/**
 * * Leetcode - 547
 * * Number of Provinces
 *
 * * There are n cities. Some of them are connected, while some are not. 
 * * If city a is connected directly with city b, and city b is connected directly with city c,
 * * then city a is connected indirectly with city c.
 * 
 * * A province is a group of directly or indirectly connected cities and no other cities outside of the group.
 
 * * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city 
 * * are directly connected, and isConnected[i][j] = 0 otherwise.
 
 * * Example 1  :
 * * Input      : isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * * Output     : 2
 * 
 * * Example 2  :
 * * Input      : isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * * Output     : 3
 * 
 * * https://leetcode.com/problems/number-of-provinces/description/
 * * https://www.naukri.com/code360/problems/find-the-number-of-states_1377943
 * * https://www.geeksforgeeks.org/problems/number-of-provinces/1
 * 
 */

// ! Google, Amazon, Microsoft, uber

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
template <typename T>
void printAdjList(std::vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    std::cout << i << " -> ";
    printArr(adj[i]);
  }
}

void dfsBrute(
    int u,
    std::vector<bool> &visited,
    std::unordered_map<int, std::vector<int>> &adj)
{
  visited[u] = true;

  // * Visit neighbours
  for (int &v: adj[u]) {
    if (!visited[v])
      dfsBrute(v, visited, adj);
  }
}

// * ------------------------- Brute Force Approach -------------------------`
// * TIME COMPLEXITY O(v + e)
// * SPACE COMPLEXITY O(v)
int findCircleNumDfsBrute(std::vector<std::vector<int>> &isConnected) {
  int n = isConnected.size();

  // * make graph
  std::unordered_map<int, std::vector<int>> adj;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (isConnected[i][j] == 1) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  // * Classic DFS
  int ans = 0;
  std::vector<bool> visited(n, false);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfsBrute(i, visited, adj);
      ans++;
    }
  }

  return ans;
}

void dfs(
    int u,
    std::vector<bool> &visited,
    std::vector<std::vector<int>> &isConnected)
{
  int n = isConnected.size();
  visited[u] = true;

  // * Visit neighbours
  for (int v = 0; v < n; ++v) {
    if (!visited[v] && isConnected[u][v] == 1)
      dfs(v, visited, isConnected);
  }
}

// * ------------------------- Optimal Approach -------------------------`
// * Using DFS
// * TIME COMPLEXITY O(v + e)
// * SPACE COMPLEXITY O(1)
int findCircleNumDfs(std::vector<std::vector<int>> &isConnected) {
  int n = isConnected.size();
  std::vector<bool> visited(n, false);

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i, visited, isConnected);
      ans++;
    }
  }

  return ans;
}

void bfs(std::unordered_map<int, std::vector<int>> &adj,
         int u,
         std::vector<bool> &visited)
{
  std::queue<int> q;

  q.push(u);
  visited[u] = true;

  // * Visit neighbours
  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (auto &v: adj[node] ) {
      if (!visited[v]) {
        q.push(v);
        visited[v] = true;
      }
    }
  }
}

// * ------------------------- Optimal Approach -------------------------`
// * Using BFS
// * TIME COMPLEXITY O(v + e)
// * SPACE COMPLEXITY O(1)
int findCircleNumBfs(std::vector<std::vector<int>> &isConnected) {
  int n = isConnected.size();

  // * 1. make graph
  std::unordered_map<int, std::vector<int>> adj;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (isConnected[i][j] == 1) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  // * 2. Classic BFS
  std::vector<bool> visited(n, false);
  int ans = 0;
  for (int u = 0; u < n; ++u) {
    if (!visited[u]) {
      bfs(adj, u, visited);
      ans++;
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  
  // * testcase 2
  // std::vector<std::vector<int>> isConnected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

  std::cout << "isConnected Cities: " << std::endl;
  for (auto &vec : isConnected)
    printArr(vec);

  int ans = findCircleNumDfsBrute(isConnected);
  // int ans = findCircleNumDfs(isConnected);
  // int ans = findCircleNumBfs(isConnected);
  std::cout << "Number of Provinces: " << ans << std::endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 01-no-of-provinces.cpp -o output && ./output