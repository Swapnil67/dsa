#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
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

void printAdjList2(std::unordered_map<int, std::vector<int>> &adj) {
  int n = adj.size();
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    printArr(vec);
  }
}

// * --------------------------------------------------------------------------------

// * 01 - DFS on Graph
// std::vector<int> dfs(std::vector<std::vector<int>> &edges) {
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

// * 07 - Detect Cycle using DSU
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

void Union(int x, int y, std::vector<int> &rank, std::vector<int> &parent) {
  int x_parent = find(x, parent);
  int y_parent = find(y, parent);

  if (x_parent == y_parent)
    return;

  if (rank[x_parent] > rank[y_parent]) {
    parent[y_parent] = x_parent;
  }
  else if (rank[x_parent] < rank[y_parent]) {
    parent[x_parent] = y_parent;
  } else {
    parent[x_parent] = y_parent;
    rank[y_parent]++;
  }
}


bool cycleDetectionDSU(std::vector<std::vector<int>> &edges) {
  std::unordered_map<int, std::vector<int>> adj = constructadj(edges);
  printAdjList2(adj);

  int V = edges.size();

  std::vector<int> rank(V, 1);
  std::vector<int> parent(V);
  for (int i = 0; i < V; ++i) {
    parent[i] = i;
  }

  for (int u = 0; u < V; ++u) {
    for (auto &v: adj[u]) {
      if (u < v) {
        int u_parent = find(u, parent);
        int v_parent = find(v, parent);

        if (u_parent == v_parent)
          return true;

        Union(u, v, rank, parent);
      }
    }
  }

  return false;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}}; // * true

  // * testcase 2
  // std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}}; // * false

  // * testcase 3
  // std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}}; // * true

  // * testcase 4
  // std::vector<std::vector<int>> edges = {{0, 2}, {0, 3}, {0, 4}, {1, 3}, {2, 4}}; // * true

  for (auto &vec : edges)
    printArr(vec);

  bool cycle = cycleDetectionDSU(edges);
  std::cout << "Cycle Detection In Undirected Graph: " << cycle << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

