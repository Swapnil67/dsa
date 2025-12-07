/*
 * Leetcode - 1857
 * Largest Color Value in a Directed Graph
 *
 * There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

 * You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in
 * this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there 
 * is a directed edge from node aj to node bj.

 * A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge
 * from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the 
 * most frequently occurring color along that path.

 * Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

 * * Example 1  :
 * * Input      : colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
 * * Output     : 3
 * 
 * * Example 2  :
 * * Input      : colors = "a", edges = [[0,0]]
 * * Output     : -1
 * 
 * https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/
 * 
 */

// ! Meta

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

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

// * Construct adjacency list for BFS with indegree
std::unordered_map<int, std::vector<int>> constructadj(
    std::vector<int> &indegree,
    std::vector<std::vector<int>> &edges)
{
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it: edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    indegree[v]++;
  }
  return adj;
}

// * ------------------------- APPROACH: Optimal  -------------------------`
// * Using Topological Sorting with BFS
// * Count all the a-z characters on every node and return the largest
// * TIME COMPLEXITY  O(V + E) * 26
// * SPACE COMPLEXITY O(V + E)
int largestPathValue(std::string &colors, std::vector<std::vector<int>> &edges) {
  int N = colors.size();
  std::vector<int> indegree(N, 0);
  std::unordered_map<int, std::vector<int>> adj = constructadj(indegree, edges);

  std::vector<std::vector<int>> t(N, std::vector<int>(26, 0));
  std::queue<int> q;

  // * Push nodes with indegree == 0 to queue
  for (int i = 0; i < N; ++i) {
    if (indegree[i] == 0) {
      t[i][colors[i] - 'a'] = 1;
      q.push(i);
    }
  }

  int ans = 0, count_nodes = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    count_nodes++;
    ans = std::max(ans, t[u][colors[u] - 'a']);

    for (auto &v : adj[u]) {
      int cur_color = colors[v] - 'a';
      // * Find the color values for 'v' node
      for (int c = 0; c < 26; ++c) {
        t[v][c] = std::max(t[v][c], t[u][c] + (cur_color == c));
      }
      indegree[v]--;
      if (indegree[v] == 0) {
        q.push(v);
      }
    }
  }

  // * For debugging
  // for (auto &vec: t) {
  //   printArr(vec);
  // }

  if (count_nodes < N) // * cycle in graph
    return -1;
  return ans;
}

int main(void) {
  // * testcase 1
  std::string colors = "abaca";
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {3, 4}};
  
  // * testcase 2
  // std::string colors = "a";
  // std::vector<std::vector<int>> edges = {{0,0}};

  std::cout << "-------- edges -------- " << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  int ans = largestPathValue(colors, edges);
  std::cout << "Least Moves: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 04-largest-color-value-in-a-dg.cpp -o output && ./output
