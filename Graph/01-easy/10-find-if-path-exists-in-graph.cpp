/**
 * * Leetcode - 1971
 * * Find if Path Exists in Graph
 * 
 * * There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive).
 * * The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] 
 * * denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most 
 * * one edge, and no vertex has an edge to itself.

 * * You want to determine if there is a valid path that exists from vertex source to vertex destination.

 * * Given edges and the integers n, source, and destination, return true if there is a valid path 
 * * from source to destination, or false otherwise.

 * * Example 1  :
 * * Input      : n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
 * * Output     : true

 * * Example 2  :
 * * Input      : n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
 * * Output     : false
 * 
 * * https://leetcode.com/problems/find-if-path-exists-in-graph/
 */

#include <queue>
#include <vector>
#include <iostream>

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

std::vector<std::vector<int>> constructadj(int V, std::vector<std::vector<int>> &edges) {
  std::vector<std::vector<int>> adj(V);
  for (auto &it: edges) {
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
  }
  return adj;
}

bool dfs(int u, int &dst,
         std::vector<bool> &visited,
         std::vector<std::vector<int>> &adj)
{
  if (u == dst)
    return true;

  if (visited[u] == true)
    return false;

  visited[u] = true; // * Mark visited

  for (auto &v: adj[u]) {
    if (!visited[v]) {
      if (dfs(v, dst, visited, adj))
        return true;
    }
  }

  return false;
}

bool validPath(int V, std::vector<std::vector<int>> &edges, int source, int destination) {
  std::vector<std::vector<int>> adj = constructadj(V, edges);
  std::vector<bool> visited(V + 1, false);
  // printAdjList(adj); // * For debugging 
  return dfs(source, destination, visited, adj);
}

int main(void) {
  // * testcase 1
  // int V = 3, src = 0, dst = 2;
  // std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
  
  // * testcase 2
  // int V = 6, src = 0, dst = 5;
  // std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
  
  // * testcase 2
  // int V = 10, src = 1, dst = 0;
  // std::vector<std::vector<int>> edges = {{2, 9}, {7, 8}, {5, 9}, {7, 2}, {3, 8}, {2, 8}, {1, 6}, {3, 0}, {7, 0}, {8, 5}};
  
  // * testcase 4
  int V = 10, src = 7, dst = 5;
  std::vector<std::vector<int>> edges = {{0, 7}, {0, 8}, {6, 1}, {2, 0}, {0, 4}, {5, 8}, {4, 7}, {1, 3}, {3, 5}, {6, 5}};

  std::cout << "src: " << src << ", dst: " << dst << std::endl;
  std::cout << "edges: " << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  bool ans = validPath(V, edges, src, dst);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 10-find-if-path-exists-in-graph.cpp -o output && ./output