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
 * 
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
  std::cout << "V: " << V << std::endl;
  std::vector<std::vector<int>> adj(V + 1);
  for (auto &it : edges) {
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
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
bool cycleDetectionDSU(std::vector<std::vector<int>> &edges) {
  int V = edges.size();

  // * Initialize rank and parent vectors
  std::vector<int> rank(V);
  std::vector<int> parent(V);
  for (int i = 0; i < V; ++i) {
    rank[i] = 1;
    parent[i] = i;
  }

  std::vector<std::vector<int>> adj = constructadj(V + 1, edges);
  // * For Debugging
  std::cout << "Adjacency List" << std::endl;
  printAdjList(adj);

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
  // std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};

  // * testcase 2
  std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}};

  // * testcase 3
  // std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};

  // * testcase 4
  // std::vector<std::vector<int>> edges = {{0, 2}, {0, 3}, {0, 4}, {1, 3}, {2, 4}};

  for (auto &vec : edges)
    printArr(vec);

  bool cycle = cycleDetectionDSU(edges);
  std::cout << "Cycle Detection In Undirected Graph: " << cycle << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 08-cycle-in-udg-dsu.cpp -o output && ./output