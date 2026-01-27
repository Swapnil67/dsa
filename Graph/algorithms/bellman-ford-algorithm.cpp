/*
 * Bellman-Ford
 *
 * Example 1
 * Input  : V = 5, edges[][] = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]], src = 0
 * Output : [0, 5, 6, 6, 7]
 *
 * Example 2
 * Input  : V = 4, edges[][] = [[0, 1, 4], [1, 2, -6], [2, 3, 5], [3, 1, -2]], src = 0
 * Output : [-1]
 * 
 * https://www.naukri.com/code360/problems/bellmon-ford_2041977
 * https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
*/

// ! Amazon, Microsoft

#include <vector>
#include <climits>
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

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * v = no of vertices
// * e = no of edges
// * TIME COMPLEXITY O(E * V)
// * SPACE COMPLEXITY O(V)
std::vector<int> bellmanFord(int V, int src, std::vector<std::vector<int>> &edges) {
  std::vector<int> dist(V, INT_MAX);
  dist[src] = 0;

  // * Step1:  V - 1 relaxation
  for (int count = 1; count <= V - 1; ++count) {
    for (auto &edge: edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
      }
    }
  }
  
  // * Step2: Now detect -ve cycle 
  // * By doing 1 extra relaxation 
  for (auto &edge: edges) {
    int u = edge[0], v = edge[1], w = edge[2];
    if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
      return {-1};
    }
  }

  return dist;
}

int main(void) {

  // * testcase 1
  int V = 5, src = 0;
  std::vector<std::vector<int>> edges = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};

  // * testcase 2
  // int V = 4, src = 0;
  // std::vector<std::vector<int>> edges = {{0, 1, 4}, {1, 2, -6}, {2, 3, 5}, {3, 1, -2}};

  std::cout << "V: " << V << ", src: " << src << std::endl;
  std::cout << "Edges" << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  std::vector<int> ans = bellmanFord(V, src, edges);
  std::cout << "Answer" << std::endl;
  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++20 bellman-ford-algorithm.cpp -o output && ./output

