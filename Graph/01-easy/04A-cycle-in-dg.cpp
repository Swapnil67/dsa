/**
 * * Directed Graph Cycle
 * 
 * * Example 1  :
 * * Input      : V = 4, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 3]]
 * * Output     : true
 * 
 * * Example 2  :
 * * Input      : V = 3, edges[][] = [[0, 1], [1, 2]]
 * * Output     : false
 * 
 * * https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
 * * https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626
 * 
 */

#include <vector>
#include <iostream>
#include <unordered_map>

// ! In cycle detection the `in_recursion` array will contain following values
// ! True Vertices = They have cycle
// ! False Vertices = They don't have cycle

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
void printAdjList(std::unordered_map<int, std::vector<int>> &adj) {
  int n = adj.size();
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    printArr(vec);
  }
}

// * Function to construct an adjacency list from edge list
std::unordered_map<int, std::vector<int>> constructadj(std::vector<std::vector<int>> &edges)
{
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it: edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
  }
  return adj;
}

bool dfs(
    int u,
    std::vector<bool> &visited,
    std::vector<bool> &in_recursion,
    std::unordered_map<int, std::vector<int>> &adj)
{
  visited[u] = true;
  in_recursion[u] = true;
  // std::cout << "u: " << u << std::endl;
  
  for (auto &v: adj[u]) {
    // std::cout << "\tv: " << v << std::endl;
    if (visited[v] && in_recursion[v]) {
      return true;
    }

    if (dfs(v, visited, in_recursion, adj)) {
      return true;
    }
  }

  in_recursion[u] = false;
  return false;
}

bool cycleDetectionDFS(int V, std::vector<std::vector<int>> &edges) {
  // * construct the adjacency list
  std::unordered_map<int, std::vector<int>> adj = constructadj(edges);
  
  std::cout << "Adjacency List" << std::endl;
  printAdjList(adj); // * For Debugging

  std::vector<bool> visited(V, false);
  std::vector<bool> in_recursion(V, false);

  for (int i = 0; i <= V; ++i) {
    // std::cout << i << " -> " << visited[i] << std::endl;
    if (!visited[i] && dfs(i, visited, in_recursion, adj))
      return true;
  }

  return false;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> edges = {{0, 1}, {2, 1}}; // * false

  // * testcase 2
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}}; // * true
  
  // * testcase 3
  // std::vector<std::vector<int>> edges = {{0, 3}, {0, 1}, {1, 3}}; // * false

  int V = edges.size();
  std::cout << "Edges: " << V << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  bool cycle = cycleDetectionDFS(V, edges);
  std::cout << "Cycle Detection In directed Graph: " << cycle << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 04A-cycle-in-dg.cpp -o output && ./output