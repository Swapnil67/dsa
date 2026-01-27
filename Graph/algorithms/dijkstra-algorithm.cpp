/*
 * Dijkstra Algorithm
 *
 * https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
 * https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469
*/

// ! Google, Microsoft, Paypal, Myntra

#include <queue>
#include <vector>
#include <climits>
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

std::unordered_map<int, std::vector<std::pair<int, int>>> constructadj(
    std::vector<std::vector<int>> &edges)
{
  std::unordered_map<int, std::vector<std::pair<int, int>>> adj;
  for (auto &e: edges) {
    int u = e[0], v = e[1], w = e[2];
    adj[u].push_back(std::make_pair(v, w));
    adj[v].push_back(std::make_pair(u, w));
  }
  return adj;
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

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using min_heap
// * v = no of vertices
// * e = no of edges
// * TIME COMPLEXITY O(v * (logv + elogv))
// * SPACE COMPLEXITY O(E + V)
std::vector<int> dijkstra(int V, int src, std::vector<std::vector<int>> &edges) {
  // * 1. Create a Adjacency List
  std::unordered_map<int, std::vector<std::pair<int, int>>> adj = constructadj(edges);

  // * For debugging
  // std::cout << "Adjacency List" << std::endl;
  // printAdjList(adj);

  // * 2. min heap for storing weights
  typedef std::pair<int, int> pii;
  std::priority_queue<pii, std::vector<pii>, std::greater<>> min_heap;
  min_heap.push({0, src});

  std::vector<int> ans(V, INT_MAX);
  ans[src] = 0;

  while (!min_heap.empty()) { // * O(V)
    int d = min_heap.top().first;
    int node = min_heap.top().second;
    min_heap.pop(); // * O(logV)
  
    for (auto &p : adj[node]) { // * O(Edges)
      int v = p.first, w = p.second;
      if (ans[v] > w + d) {
        ans[v] = w + d;
        min_heap.push({w + d, v});
      }
    }
  }

  return ans;
}

int main(void) {
  int V = 3, src = 2;
  std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 2, 3}, {0, 2, 6}};
  std::cout << "V: " << V << ", src: " << src << std::endl;
  std::cout << "Edges" << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  std::vector<int> ans = dijkstra(V, src, edges);
  std::cout << "Answer" << std::endl;
  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++20 dijkstra-algorithm.cpp -o output && ./output

