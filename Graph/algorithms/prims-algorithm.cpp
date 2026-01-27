/*
 * Prim's Algorithm 
 *
 * https://www.naukri.com/code360/problems/prim-s-mst_1095633
 * https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
*/

// ! Flipkart, Microsoft, Amazon, Samsung, Cisco

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
  for (auto &e: edges) {
    int u = e[0], v = e[1], w = e[2];
    adj[u].push_back(std::make_pair(v, w));
    adj[v].push_back(std::make_pair(u, w));
  }
  return adj;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using min_heap
// * v = no of vertices
// * e = no of edges
// * TIME COMPLEXITY O(v * (logv + elogv))
// * SPACE COMPLEXITY O(E + V)
int spanningTree(int V, int src, std::vector<std::vector<int>> &edges) {
  std::unordered_map<int, std::vector<pii>> adj = constructadj(edges);
  // printAdjList(adj); // * For debugging

  // * This is a visited vector
  std::vector<bool> in_mst(V, false);

  std::priority_queue<pii, std::vector<pii>, std::greater<>> min_heap;
  min_heap.push({0, 0});

  int sum = 0;
  while (!min_heap.empty()) {
    auto [wt, u] = min_heap.top();
    min_heap.pop();

    if (in_mst[u])
      continue;

    in_mst[u] = true;
    sum += wt;

    for (auto &[v, w] : adj[u]) {
      if (!in_mst[v])
        min_heap.push({w, v});
    }
  }

  return sum;
}

int main(void) {
  int V = 3, E = 3;
  std::vector<std::vector<int>> edges = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};

  std::cout << "V: " << V << ", E: " << E << std::endl;
  std::cout << "Edges" << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  int ans = spanningTree(V, E, edges);
  std::cout << "Sum: " << ans << std::endl;
  // std::cout << "Answer" << std::endl;
  // printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++20 prims-algorithm.cpp -o output && ./output

