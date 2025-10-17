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
std::vector<std::vector<int>> constructadj(int V, std::vector<std::vector<int>> &edges) {
  std::vector<std::vector<int>> adj(V);
  for (auto &it : edges) {
    // printArr(it);
    // std::cout << it[0] << " -> " << it[1] << std::endl;
    adj[it[0]].push_back(it[1]); // Directed edge from it[0] to it[1]
  }
  return adj;
}

bool dfs(std::vector<std::vector<int>> &adj,
         std::vector<bool> &visited,
         std::vector<bool> in_recursion,
         int u)
{
  visited[u] = true;
  in_recursion[u] = true;
  // std::cout << "u: " << u << " & parent: " << parent << std::endl;
  
  for (auto &v: adj[u]) {
    if (visited[v] && in_recursion[v]) {
      // std::cout << "\tv: " << v << std::endl;
      return true;
    }

    if (dfs(adj, visited, in_recursion, v))
      return true;
  }

  in_recursion[u] = false;
  return false;
}

bool cycleDetectionDfs(int V, std::vector<std::vector<int>> &edges) {
  // * construct the adjacency list
  std::vector<std::vector<int>> adj = constructadj(V + 1, edges);

  // * For Debugging
  std::cout << "Adjacency List" << std::endl;
  printAdjList(adj);

  std::vector<bool> visited(V, false);
  std::vector<bool> in_recursion(V, false);
  for (int i = 0; i < V; ++i) {
    if (!visited[i] && dfs(adj, visited, in_recursion, i))
      return true;
  }

  return false;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> edges = {{0, 1}, {2, 1}}; // * false

  // * testcase 2
  // std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 3}}; // * true
  
  // * testcase 3
  // std::vector<std::vector<int>> edges = {{0, 3}, {0, 1}, {1, 3}}; // * false

  int V = edges.size();
  std::cout << "Edges: " << V << std::endl;

  for (auto &vec : edges)
    printArr(vec);

  bool cycle = cycleDetectionDfs(V, edges);
  std::cout << "Cycle Detection In Undirected Graph: " << cycle << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 04-cycle-in-dg.cpp -o output && ./output