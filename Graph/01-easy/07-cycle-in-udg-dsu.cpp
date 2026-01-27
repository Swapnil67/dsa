/**
 * * Detect Cycle using DSU
 * * Given an undirected graph with no self loops with V (from 0 to V-1) nodes and E edges, 
 * * the task is to check if there is any cycle in the undirected graph.

 * * Example 1  :
 * * Input      : V = 4, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 3]]
 * * Output     : true
 * 
 * * Example 2  :
 * * Input      : V = 3, edges[][] = [[0, 1], [1, 2]]
 * * Output     : false
 * 
 * * https://www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1
 */

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
void printAdjList(std::unordered_map<int, std::vector<int>> &adj) {
  int n = adj.size();
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    printArr(vec);
  }
}

std::unordered_map<int, std::vector<int>> constructadj(std::vector<std::vector<int>> &edges) {
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it: edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return adj;
}


int find(int x, std::vector<int> &parent) {
  if (x == parent[x])
    return x;

  return parent[x] = find(parent[x], parent);
}

void Union(int x, int y, std::vector<int> &parent, std::vector<int> &rank) {
  int x_parent = find(x, parent);
  int y_parent = find(y, parent);

  if (x_parent == y_parent)
    return;

  if (rank[x_parent] > rank[y_parent]) {
    parent[y_parent] = x_parent;
  }
  else if (rank[x_parent] < rank[y_parent]) {
    parent[x_parent] = y_parent;
  }
  else {
    parent[x_parent] = y_parent;
    rank[y_parent]++;
  }
}

// * DSU
// * If we get the same parents for two nodes that means there is a cycles
bool cycleDetectionDSU(std::vector<std::vector<int>> &edges) {
  int V = edges.size();

  // * Initialize rank and parent vectors
  std::vector<int> rank(V, 1);
  std::vector<int> parent(V);
  for (int i = 0; i < V; ++i) {
    parent[i] = i;
  }

  std::unordered_map<int, std::vector<int>> adj = constructadj(edges);
  std::cout << "Adjacency List" << std::endl;
  printAdjList(adj); // * For Debugging

  for (int u = 0; u < V; ++u) {
    for (auto &v: adj[u]) {
      if (u < v) { // * For undirected graph
        int u_parent = find(u, parent);
        int v_parent = find(v, parent);

        if (u_parent == v_parent)
          return true;

        Union(u, v, parent, rank);
      }
    }
  }

  return false;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}}; // * true

  // * testcase 2
  // std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}}; // * false

  // * testcase 3
  // std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}}; // * true

  // * testcase 4
  std::vector<std::vector<int>> edges = {{0, 2}, {0, 3}, {0, 4}, {1, 3}, {2, 4}}; // * true

  for (auto &vec : edges)
    printArr(vec);

  bool cycle = cycleDetectionDSU(edges);
  std::cout << "Cycle Detection In Undirected Graph: " << cycle << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 07-cycle-in-udg-dsu.cpp -o output && ./output