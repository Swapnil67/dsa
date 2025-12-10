/*
 * Kosaraju's Algorithm
 *
 * Example 1:
 * Input     : adj = [[2, 3], [0], [1], [4], []]
 * Output    :  3
 *
 * Example 2:
 * Input     : adj = [[1], [2], [0]]
 * Output    :  1
 * 
 * https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
*/

// * SCC - Strongly Connected Components

// ! Microsoft, Amazon, Visa

#include <queue>
#include <stack>
#include <vector>
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

// * Saves the Vertices of Graph in Topological Order
void dfs_topological(
    int u,
    std::stack<int> &st,
    std::vector<bool> &visited,
    std::vector<std::vector<int>> &adj)
{
  visited[u] = true;
  for (auto &v : adj[u]) {
    if (!visited[v])
      dfs_topological(v, st, visited, adj);
  }
  st.push(u);
}

// * Classic DFS
void dfs(
    int u,
    std::vector<bool> &visited,
    std::vector<std::vector<int>> &adj)
{
  visited[u] = true;
  for (auto &v : adj[u]) {
    if (!visited[v])
      dfs(v, visited, adj);
  }
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(E * log(E))
// * SPACE COMPLEXITY O(V + E)
int kosaraju(std::vector<std::vector<int>> &adj) {
  int V = adj.size();
  std::vector<bool> visited(V, false);

  // * 1. Do topological sort
  std::stack<int> st;
  for (int i = 0; i < V; ++i) {
    if (!visited[i]) {
      dfs_topological(i, st, visited, adj);
    }
  }

  // * 2. Make a reverse graph
  std::vector<std::vector<int>> reverse_adj(V);
  for (int u = 0; u < V; ++u) {
    for (auto &v: adj[u]) {
      // * v -> u
      reverse_adj[v].push_back(u); // * reverse
    }
  }
  // std::cout << "Reverse Adj" << std::endl; // * For Debugging
  // for (auto &vec : reverse_adj)
  //   printArr(vec);

  // * 3. Call DFS based on stack order 
  int scc_count = 0;
  visited.assign(V, false);
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    if (visited[u])
      continue;

    dfs(u, visited, reverse_adj);
    scc_count++;
  }

  return scc_count;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> adj = {{2, 3}, {0}, {1}, {4}, {}};
  
  // * testcase 2
  // std::vector<std::vector<int>> adj = {{1}, {2}, {0}};

  std::cout << "Adj" << std::endl;
  for (auto &vec : adj)
    printArr(vec);

  int ans = kosaraju(adj);
  std::cout << "Strongly Connected Components: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 kosaraju-algorithm.cpp -o output && ./output

