/*
 * Leetcode - 2685
 * Count the Number of Complete Components
 * 
 * You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. 
 * You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an 
 * undirected edge connecting vertices ai and bi.
 * 
 * Return the number of complete connected components of the graph.

 * A connected component is a subgraph of a graph in which there exists a path between any two vertices,
 * and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

 * A connected component is said to be complete if there exists an edge between every pair of its vertices.

 * Example 1  :
 * Input      : n = 6, edges = {{0,1},{0,2},{1,2},{3,4}}
 * Output     : 3

 * Example 2  :
 * Input      : n = 6, edges = {{0,1},{0,2},{1,2},{3,4},{3,5}}
 * Output     : 1
 
 * https://leetcode.com/problems/count-the-number-of-complete-components/description/
 * https://www.geeksforgeeks.org/problems/number-of-good-components--170647/1
*/

// ! Microsoft, Google, Amazon

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

void printAdjList(std::unordered_map<int, std::vector<int>> &adj) {
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    printArr(vec);
  }
}

std::unordered_map<int, std::vector<int>> constructadj(std::vector<std::vector<int>> &edges) {
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it: edges) {
    int u = it[0], v = it[1];
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  return adj;
}

void dfs(int u, int &edges, int &vertices,
         std::vector<bool> &visited,
         std::unordered_map<int, std::vector<int>> adj)
{
  visited[u] = true;
  vertices += 1;
  edges += adj[u].size();

  for (auto &ngbr: adj[u]) {
    if (!visited[ngbr]) {
      dfs(ngbr, edges, vertices, visited, adj);
    }
  }
}

void bfs(int node, int &edges, int &vertices,
         std::vector<bool> &visited,
         std::unordered_map<int, std::vector<int>> adj)
{
  std::queue<int> q;
  q.push(node);
  visited[node] = true;

  while (!q.empty()) {
    auto u = q.front();
    q.pop();

    vertices += 1;
    edges += adj[u].size();

    for (auto &v: adj[u]) {
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
  }
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Calculate count of vertices & edges for each subgraph and check if the following formula is valid
// * TIME COMPLEXITY O(V + E)
// * SPACE COMPLEXITY O(V + E)
int countCompleteComponentsDFS(int n, std::vector<std::vector<int>>& edges) {
  // * 1. Construct adj matrix
  std::unordered_map<int, std::vector<int>> adj = constructadj(edges);
  // printAdjList(adj); // * For Debugging
  
  // * 2. Classic DFS
  std::vector<bool> visited(n, false);

  int ans = 0;
  for (int u = 0; u < n; ++u) {
    if (!visited[u]) {
      int e = 0, v = 0;
      dfs(u, e, v,visited, adj);
      int edges = (v * (v - 1)) / 2;
      // std::cout << "u: " << u << ", e: " << e << ", v: " << v << std::endl;
      if (edges == e / 2)
        ans++;
    }
  }

  return ans;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(V + E)
// * SPACE COMPLEXITY O(V + E)
int countCompleteComponentsBFS(int n, std::vector<std::vector<int>>& edges) {
  // * 1. Construct adj matrix
  std::unordered_map<int, std::vector<int>> adj = constructadj(edges);
  // printAdjList(adj); // * For Debugging
  
  // * 2. Classic BFS
  std::vector<bool> visited(n, false);
  int ans = 0;
  for (int u = 0; u < n; ++u) {
    if (!visited[u]) {
      int e = 0, v = 0;
      bfs(u, e, v,visited, adj);
      // std::cout << "u: " << u << ", e: " << e << ", v: " << v << std::endl;
      if ((v * (v - 1)) == e)
        ans++;
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // int n = 6;
  // std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
  
  // * testcase 2
  // int n = 6;
  // std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};
  
  // * testcase 3
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 2}, {0, 1}, {1, 2}};

  std::cout << "edges" << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  // int ans = countCompleteComponentsDFS(n, edges);
  int ans = countCompleteComponentsBFS(n, edges);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 47-count-the-no-of-complete-components.cpp -o output && ./output

 