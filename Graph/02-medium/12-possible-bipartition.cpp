/**
 * * Leetcode - 886
 * * Possible Bipartition
 *
 * * We want to split a group of n people (labeled from 1 to n) into two groups of any size. 
 * * Each person may dislike some other people, and they should not go into the same group.

 * * Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled
 * * ai does not like the person labeled bi, return true if it is possible to split everyone 
 * * into two groups in this way.

 * * Example 1  :
 * * Input      : n = 4, dislikes = [[1,2],[1,3],[2,4]]
 * * Output     : true

 * * Example 2  :
 * * Input      : n = 3, dislikes = [[1,2],[1,3],[2,3]]
 * * Output     : false
 * 
 * * https://leetcode.com/problems/possible-bipartition/description/
*/

// ! Microsoft, Flipkart, Samsung

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

// * Print adjacency list
void printAdjList(std::unordered_map<int, std::vector<int>> &adj) {
  int n = adj.size();
  for (auto &it: adj) {
    std::cout << it.first << " -> ";
    printArr(it.second);
  }
}

std::unordered_map<int, std::vector<int>> constructadj(std::vector<std::vector<int>> &dislikes) {
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it : dislikes) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return adj;
}

bool bfs(int node, std::vector<int> &color, std::unordered_map<int, std::vector<int>> &adj) {
  std::queue<int> q;
  q.push(node);
  color[node] = 1; // * red

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    // * go to neighbours
    for (int &v: adj[u]) {
      // * cannot be in same set
      if (color[v] == color[u])
        return false;
      
      if (color[v] == -1) {
        q.push(v);
        color[v] = 1 - color[u];
      }
    }
  }

  return true;
}

bool possibleBipartition(int n, std::vector<std::vector<int>> &dislikes) {
  
  // * 1. construct adjacency list
  std::unordered_map<int, std::vector<int>> adj = constructadj(dislikes);
  printAdjList(adj); // * For debugging 

  // * 2. Classic bfs
  std::vector<int> color(n + 1, -1); // * Also acts a visited vector
  for (int u = 1; u <= n; ++u) {
    if (color[u] == -1) // * not processed
      if (!bfs(u, color, adj))
        return false;
  }

  return true;
}

int main(void) {
  // * testcase 1
  // int n = 4;
  // std::vector<std::vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 4}};
  
  // * testcase 2
  int n = 3;
  std::vector<std::vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 3}};

  std::cout << "n: " << n << std::endl;
  std::cout << "dislikes: " << std::endl;
  for (auto &vec : dislikes)
    printArr(vec);

  bool ans = possibleBipartition(n, dislikes);
  std::cout << "Possible Bipartition: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 12-possible-bipartition.cpp -o output && ./output