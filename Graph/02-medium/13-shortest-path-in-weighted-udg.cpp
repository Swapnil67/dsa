/*
 * Shortest Path in Weighted undirected graph
 *
 * https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
*/

// ! Dijkstra Algorithm

// ! Google, Microsoft, Paypal, Myntra

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
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

void printAdjList(std::unordered_map<int, std::vector<std::pair<int, int>>> &adj) {
  for (auto &[u, vec] : adj) {
    std::cout << u << " -> "; 
    for (auto &p: vec) {
      std::cout << "(" << p.first << " " << p.second << ") ";
    }
    std::cout << std::endl;
  }
}

typedef std::pair<int, int> pii;

std::unordered_map<int, std::vector<pii>> constructadj(std::vector<std::vector<int>> &edges) {
  std::unordered_map<int, std::vector<pii>> adj;
  if (edges.size() == 0)
    return adj;

  for (auto &vec: edges) {
    if (vec.size() == 0)
      continue;
    int u = vec[0], v = vec[1], w = vec[2];
    adj[u].push_back(std::make_pair(v, w));
    adj[v].push_back(std::make_pair(u, w));
  }
  return adj;
}

std::vector<int> shortestPath(int m, int n, std::vector<std::vector<int>> &edges) {
  // * 1. Create a Adjacency List
  std::unordered_map<int, std::vector<pii>> adj = constructadj(edges);

  // * For debugging
  std::cout << "Adjacency List" << std::endl;
  printAdjList(adj);

  std::vector<int> parent_vec(n + 1);
  std::vector<int> distance(n + 1, INT_MAX);
  distance[1] = 0;

  std::priority_queue<pii, std::vector<pii>, std::greater<>> min_heap;
  min_heap.push({0, 1});

  while (!min_heap.empty()) {
    int w1 = min_heap.top().first;
    int parent = min_heap.top().second;
    min_heap.pop();

    for (auto &p: adj[parent]) {
      int v = p.first, w2 = p.second;
      if (distance[v] > w1 + w2) { 
        distance[v] = w1 + w2;
        min_heap.push({w1 + w2, v});
        parent_vec[v] = parent;
      }
    }
  }

  // printArr(parent_vec);

  // * Did not reach the node
  if (distance[n] == INT_MAX)
    return {-1};

  std::vector<int> path;
  int i = n;
  while (parent_vec[i] != i) {
    path.push_back(i);
    i = parent_vec[i];
  }
  std::reverse(begin(path), end(path));
  return path;
}

int main(void) {
  // * testcase 1
  int m = 6, n = 5;
  std::vector<std::vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
  
  // * testcase 2
  // int m = 1, n = 2;
  // std::vector<std::vector<int>> edges = {{1, 2, 2}};
  
  // * testcase 3
  // int m = 0, n = 2;
  // std::vector<std::vector<int>> edges = {{}};

  std::cout << "m: " << m << ", n: " << n << std::endl;
  std::cout << "Edges" << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  std::vector<int> ans = shortestPath(m, n, edges);
  std::cout << "Answer" << std::endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 13-shortest-path-in-weighted-udg.cpp -o output && ./output

 