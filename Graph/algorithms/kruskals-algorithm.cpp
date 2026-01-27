/*
 * Kruskal's Algorithm
 *
 * https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1
*/

// ! Flipkart, Microsoft, Amazon, Samsung, Cisco

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

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
int find(int x, std::vector<int> &parent) {
  if (x == parent[x]) return x;
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
  }
  else {
    parent[x_parent] = y_parent;
    rank[y_parent]++;
  }
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Using DSU
// * V = no of vertices
// * E = no of edges
// * TIME COMPLEXITY O(E * log(E))
// * SPACE COMPLEXITY O(V + E)
int kruskalsMST(int V, int src, std::vector<std::vector<int>> &edges) {
  const auto comparator = [&](const std::vector<int> &v1, const std::vector<int> &v2) {
      return v1[2] < v2[2];
  };
  sort(begin(edges), end(edges), comparator);
  
  std::vector<int> rank(V, 1);
  std::vector<int> parent(V);
  for (int i = 0; i < V; ++i) {
      parent[i] = i;
  }
  
  int sum = 0;
  for (auto &temp : edges) {
    int u = temp[0], v = temp[1], w = temp[2];
    
    int u_parent = find(u, parent);
    int v_parent = find(v, parent);

    if (u_parent != v_parent) {
      Union(u, v, rank, parent);
      sum += w;
    }
  }
  
  return sum;
}

int main(void) {
  // * testcase 1
  int V = 3, E = 3;
  std::vector<std::vector<int>> edges = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};
  
  std::cout << "V: " << V << ", E: " << E << std::endl;
  std::cout << "Edges" << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  int ans = kruskalsMST(V, E, edges);
  std::cout << "Sum: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 kruskals-algorithm.cpp -o output && ./output

