/*
 * Leetcode - 1466
 * Reorder Routes to Make All Paths Lead to the City Zero
 * 
 * There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel 
 * between two different cities (this network form a tree). Last year, The ministry of transport decided 
 * to orient the roads in one direction because they are too narrow.

 * Roads are represented by connections where connections[i] = [ai, bi] represents a road from 
 * city a to city b.
 * 
 * This year, there will be a big event in the capital (city 0), and many people want to travel to this city.
 * 
 * Your task consists of reorienting some roads such that each city can visit the city 0. 
 * Return the minimum number of edges changed.
 * 
 * It's guaranteed that each city can reach city 0 after reorder.

 * Example 1:
 * Input     : n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
 * Output    : 3
 * 
 * Example 1:
 * Input     : n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
 * Output    : 2

 * https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero
*/

// ! Meta, Microsoft

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
typedef std::pair<int, int> pii;

void printAdjList(std::unordered_map<int, std::vector<pii>> &adj) {
  for (auto &[key, pairs] : adj) {
    std::cout << key << " -> ";
    for (auto &it: pairs) {
      std::cout << "(" << it.first << ", " << it.second << ") ";
    }
    std::cout << std::endl;
  }
}

std::unordered_map<int, std::vector<pii>> constructadj(std::vector<std::vector<int>> &edges) {
  std::unordered_map<int, std::vector<pii>> adj;
  for (auto &it: edges) {
    int u = it[0], v = it[1]; // * u -> v (default)
    // * {node, is_real_path} 
    adj[u].push_back({v, 1});  // * real path (1)
    adj[v].push_back({u, 0});  // * fake path (0)
  }
  return adj;
}

void dfs(int u, int parent, int &reorder,
         std::unordered_map<int, std::vector<pii>> &adj)
{
  for (auto &[v, path]: adj[u]) {
    if (v == parent) // * don't go to parent again
      continue;

    if (path == 1) { // * Moved away from 'u' using real path so we need to flip
      reorder += 1;
    } 

    dfs(v, u, reorder, adj);
  }
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Create the two way path b/w all nodes to traverse the complete graph and then find the 
// * edges which we need to flip.
// * TIME COMPLEXITY O(m x n)
// * SPACE COMPLEXITY O(m x n)
int minReorder(int n, std::vector<std::vector<int>>& connections) {
  // * 1. Create an Adj with Real & fake paths
  std::unordered_map<int, std::vector<pii>> adj = constructadj(connections);
  // std::cout << "Adjacency List" << std::endl;
  // printAdjList(adj); // * For Debugging

  int reorder = 0;
  dfs(0, -1, reorder, adj);
  return reorder;
}

int main(void) {
  // * testcase 1
  // int n = 6;
  // std::vector<std::vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
  
  // * testcase 2
  // int n = 5;
  // std::vector<std::vector<int>> connections = {{1, 0}, {1, 2}, {3, 2}, {3, 4}};
  
  // * testcase 3
  int n = 3;
  std::vector<std::vector<int>> connections = {{1, 0}, {2, 0}};

  std::cout << "-------- Connections -------- " << std::endl;
  for (auto &vec : connections)
    printArr(vec);

  int reorder = minReorder(n, connections);
  std::cout << "Min reorder: " << reorder << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 29-reorder-routes-to-city.cpp -o output && ./output

 