/*
 * Leetcode - 3419
 * Minimize the Maximum Edge Weight of Graph
 *
 * You are given two integers, n and threshold, as well as a directed weighted graph of n nodes numbered from 0 to n - 1.
 * The graph is represented by a 2D integer array edges, where edges[i] = [Ai, Bi, Wi] 
 * indicates that there is an edge going from node Ai to node Bi with weight Wi.

 * You have to remove some edges from this graph (possibly none), so that it satisfies the following conditions:

 * - Node 0 must be reachable from all other nodes.
 * - The maximum edge weight in the resulting graph is minimized.
 * - Each node has at most threshold outgoing edges.
 * 
 * Return the minimum possible value of the maximum edge weight after removing the necessary edges. 
 * If it is impossible for all conditions to be satisfied, return -1.

 * Example 1  :
 * Input      : n = 5, edges = [[1,0,1],[2,0,2],[3,0,1],[4,3,1],[2,1,1]], threshold = 2
 * Output     : 7

 * Example 2  :
 * Input      : n = 5, edges = [[0,1,1],[0,2,2],[0,3,1],[0,4,1],[1,2,1],[1,4,1]], threshold = 1
 * Output     : -1

 * Example 3  :
 * Input      : n = 5, edges = [[1,2,1],[1,3,3],[1,4,5],[2,3,2],[3,4,2],[4,0,1]], threshold = 1
 * Output     : -1
 * 
 * https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/
*/

// ! Microsoft, Google

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>

typedef std::vector<char> vc;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

// * Print adjacency list
template <typename T>
void printAdjList(std::vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    std::cout << i << " -> ";
    printArr(adj[i]);
  }
}

typedef std::pair<int, int> pii;

bool canReachToZero(
    int &n,
    int &min_weight,
    std::unordered_map<int, std::vector<pii>> &adj)
{
  std::vector<bool> visited(n, false);

  std::queue<int> q;
  q.push(0); // * Start from '0' and go to all nodes

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    visited[u] = true;
    for (auto &[v, w]: adj[u]) {
      if (!visited[v] && w <= min_weight) { // * Edge weight should not exceed min_weight
        q.push(v);
      }
    }
  }

  // * Check if we were able to visit every node or not
  for (bool v: visited) {
    if (v == false)
      return false;
  }
  return true;
}

// * ------------------------- Approach 1: Optimal -------------------------
// * Binary Search On Answers
// * Here we'll check if its possible to reach node '0' from all nodes with min edge weight 'min_weight'
// * TIME COMPLEXITY  O(log(max_edge_weight) * (V + E))
// * SPACE COMPLEXITY O(V + E)
int minMaxWeight(int n, int threshold, std::vector<std::vector<int>> &edges) {
  int max_edge_weight = 0;
  std::unordered_map<int, std::vector<pii>> adj;
  for (auto &it: edges) {
    int u = it[0], v = it[1], w = it[2];
    max_edge_weight = std::max(max_edge_weight, w);
    adj[v].push_back({u, w}); // * with reversed edge
  }

  // * Binary Search on answers
  int ans = INT_MAX;
  int l = 0, r = max_edge_weight;
  while (l <= r) {
    int m = l + (r - l) / 2;
    bool ans = canReachToZero(n, m, adj);
    // std::cout << "m: " << m << ", ans: " << ans << std::endl;
    if (ans) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  return ans == INT_MAX ? -1 : ans;
}


int main(void) {
  // * testcase 1
  // int n = 5, threshold = 2;
  // std::vector<std::vector<int>> edges = {{1, 0, 1}, {2, 0, 2}, {3, 0, 1}, {4, 3, 1}, {2, 1, 1}};

  // * testcase 2
  int n = 5, threshold = 1;
  std::vector<std::vector<int>> edges = {{0, 1, 1}, {0, 2, 2}, {0, 3, 1}, {0, 4, 1}, {1, 2, 1}, {1, 4, 1}};

  // * testcase 3
  // int n = 5, threshold = 1;
  // std::vector<std::vector<int>> edges = {{1, 2, 1}, {1, 3, 3}, {1, 4, 5}, {2, 3, 2}, {3, 4, 2}, {4, 0, 1}};

  std::cout << "n: " << n << ", threshold: " << threshold << std::endl;
  std::cout << "Edges: " << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  int ans = minMaxWeight(n, threshold, edges);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 11-minimize-the-maximum-edge-weight-of-graph.cpp -o output && ./output