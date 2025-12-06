/**
 * * Leetcode - 2316
 * * Count Unreachable Pairs of Nodes in an Undirected Graph
 *
 * * You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1.
 * *  You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an 
 * * undirected edge connecting nodes ai and bi.

 * * Return the number of pairs of different nodes that are unreachable from each other.

 * * Example 1  :
 * * Input      : n = 3, edges = [[0,1],[0,2],[1,2]]
 * * Output     : 0
 * 
 * * Example 2  :
 * * Input       : n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
 * * Output      : 14
 * * Explanation : There are 14 pairs of nodes that are unreachable from each other:
 * *               [[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
 * 
 * * https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
*/

// ! DSU

// ! Microsoft

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
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    printArr(vec);
  }
}

std::unordered_map<int, std::vector<int>> constructadj(std::vector<std::vector<int>> &edges) {
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it : edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return adj;
}

void dfs(
    int u,
    long long &size,
    std::vector<bool> &visited,
    std::unordered_map<int, std::vector<int>> &adj)
{
  visited[u] = true;
  size += 1;
  
  for (auto &v : adj[u]) {
    if (!visited[v]) {
      dfs(v, size, visited, adj);
    }
  }
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
  } else if (rank[y_parent] > rank[x_parent]) {
    parent[x_parent] = y_parent;
  } else {
    parent[x_parent] = y_parent;
    rank[y_parent]++;
  }
}

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * DFS (More Easy)
// * TIME COMPLEXITY O(N + E)
// * SPACE COMPLEXITY O(N + E)
long long countPairsDFS(int n, std::vector<std::vector<int>> &edges) {
  std::vector<bool> visited(n, false);
  
  // * construct the adjacency list
  std::unordered_map<int, std::vector<int>> adj = constructadj(edges);
  std::cout << "Adjacency List" << std::endl;
  printAdjList(adj); // * For Debugging

  long long res = 0;
  long long total_nodes = n;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      long long grp_size = 0;
      dfs(i, grp_size, visited, adj);
      res += grp_size * (total_nodes - grp_size);
      // std::cout << "grp_size  " << grp_size < ", pairs  " << res << std::endl;
      total_nodes -= grp_size;
    }
  }

  return res;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * DSU
// * TIME COMPLEXITY O(N + E)
// * SPACE COMPLEXITY O(N + E)
long long countPairsDSU(int n, std::vector<std::vector<int>> &edges) {
  // * 1. Initialize rank and parent vectors
  std::vector<int> rank(n, 1);
  std::vector<int> parent(n);
  for (int i = 0; i < n; ++i) {
    parent[i] = i;
  }

  // * 2. Create Disjoint sets
  for (auto &it: edges) {
    int u = it[0], v = it[1];
    Union(u, v, parent, rank);
  }

  // * 3. Save the parent frequency in map
  // * {parent, freq}
  std::unordered_map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int p = find(i, parent);
    mp[p]++;
  }
  // * For Debugging
  // for (auto &[p, freq]: mp) {
  //   std::cout << p << ": " << freq << std::endl;
  // }

  // * 4. Find result
  long long result = 0;
  long long remaining_nodes = n;
  for (auto &[p, freq]: mp) {
    result += freq * (remaining_nodes - freq);
    remaining_nodes -= freq;
  }

  return result;
}

int main(void) {
  // * testcase 1
  // int n = 3;
  // std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};
  
  // * testcase 2
  int n = 7;
  std::vector<std::vector<int>> edges = {{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};
  
  // * testcase 3
  // int n = 6;
  // std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
  
  std::cout << "n: " << n << std::endl;
  std::cout << "edges: " << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  long long ans = countPairsDFS(n, edges);
  // long long ans = countPairsDSU(n, edges);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 07-cnt-unreachable-pairs-of-nodes-in-an-undirected-graph.cpp -o output && ./output