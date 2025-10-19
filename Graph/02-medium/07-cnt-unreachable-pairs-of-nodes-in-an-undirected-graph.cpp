/**
 * * Leetcode - 2316
 * * Count Unreachable Pairs of Nodes in an Undirected Graph
 *
 * * You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1.
 * *  You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an 
 * * undirected edge connecting nodes ai and bi.

 * * Return the number of pairs of different nodes that are unreachable from each other.

 * * Example 1  :
 * * Input      : n = 3, edges = [[0,1],[0,2],[1,2]]
 * * Output     : 0
 * 
 * * Example 2  :
 * * Input       : n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
 * * Output      : 14
 * * Explanation : There are 14 pairs of nodes that are unreachable from each other:
 * *               [[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
 * 
 * * https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
*/

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

// * Print adjacency list
template <typename T>
void printAdjList(std::vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    std::cout << i << " -> ";
    printArr(adj[i]);
  }
}

std::vector<std::vector<int>> constructadj(int n, std::vector<std::vector<int>> &edges) {
  std::vector<std::vector<int>> adj(n);
  for (auto &it : edges) {
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
  }
  return adj;
}

void dfs(long long &size, int u, std::vector<bool> &visited, std::vector<std::vector<int>> &adj) {
  visited[u] = true;
  size += 1;
  
  for (auto &v : adj[u]) {
    if (!visited[v]) {
      dfs(size, v, visited, adj);
    }
  }
}

long long countPairsDFS(int n, std::vector<std::vector<int>> &edges) {
  int e = edges.size(); // * Edges

  std::vector<bool> visited(n, false);
  
  std::vector<std::vector<int>> adj = constructadj(n, edges);
  // * For Debugging
  std::cout << "Adjacency List" << std::endl;
  printAdjList(adj);

  long long cur_remaining = n;
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      long long grp_size = 0;
      dfs(grp_size, i, visited, adj);
      res += grp_size * (cur_remaining - grp_size);
      std::cout << "grp_size  " << grp_size << std::endl;
      std::cout << "pairs  " << res << std::endl;
      cur_remaining -= grp_size;
    }
  }

  return res;
}

int main(void) {
  // * testcase 1
  // int n = 3;
  // std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};
  
  // * testcase 2
  int n = 7;
  std::vector<std::vector<int>> edges = {{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};
  
  // * testcase 3
  // int n = 6;
  // std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
  
  std::cout << "n: " << n << std::endl;
  std::cout << "edges: " << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  long long ans = countPairsDFS(n, edges);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 07-cnt-unreachable-pairs-of-nodes-in-an-undirected-graph.cpp -o output && ./output