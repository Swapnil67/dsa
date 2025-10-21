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

// * Print adjacency list
template <typename T>
void printAdjList(std::vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    std::cout << i << " -> ";
    printArr(adj[i]);
  }
}

// * Function to construct an adjacency list from edge list
std::vector<std::vector<int>> constructadj(
    int V,
    std::vector<std::vector<int>> &edges,
    std::vector<int> &indegree)
{
  std::vector<std::vector<int>> adj(V);
  for (auto &it: edges) {
    indegree[it[1]]++;
    adj[it[0]].push_back(it[1]);
  }
  return adj;
}

// * 01 - DFS on Graph
// std::vector<int> dfs(std::vector<std::vector<int>> &adj) {
// TODO
// }

// * 02 - BFS on Graph
// std::vector<int> bfs(std::vector<std::vector<int>> &adj) {
// TODO
// }

// * 03A - Undirected Graph Cycle
// bool cycleDetectionDFS(std::vector<std::vector<int>> &edges) {
// TODO
// }

// * 03B - Undirected Graph Cycle
// bool cycleDetectionBFS(std::vector<std::vector<int>> &edges) {
// TODO
// }

// * 04A - directed Graph Cycle
// bool cycleDetectionDFS(int V, std::vector<std::vector<int>> &edges) {
// TODO
// }

// * 04B - directed Graph Cycle (Kahn's Algo)
// bool cycleDetectionBFS(int V, std::vector<std::vector<int>> &edges) {
// TODO
// }

// * 05 - Topological sort
// std::vector<int> topologicalSort(int V, std::vector<std::vector<int>> &edges) {
// TODO
// }

// * 06 - Kahn's Algorithm
// std::vector<int> topologicalSort(int V, std::vector<std::vector<int>> &edges) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

