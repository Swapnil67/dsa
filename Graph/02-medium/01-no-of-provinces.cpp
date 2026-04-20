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

// ! Google, Apple, Amazon, Microsoft, uber, Walmart

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
    if (i != n - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

unordered_map<int, vector<int>> constructadj(vector<vector<int>> &isConnected) {
  unordered_map<int, vector<int>> adj;
  int n = isConnected.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (isConnected[i][j] == 1) {
        adj[i].push_back(j);
        adj[i].push_back(i);
      }
    }
  }

  return adj;
}

void dfsBrute(
    int u,
    vector<bool> &visited,
    unordered_map<int, vector<int>> &adj)
{
  visited[u] = true;

  // * Visit neighbours
  for (int &v: adj[u]) {
    if (!visited[v])
      dfsBrute(v, visited, adj);
  }
}

void dfs(
    int u,
    vector<bool> &visited,
    vector<vector<int>> &isConnected)
{
  int n = isConnected.size();
  visited[u] = true;

  // * Visit neighbours
  for (int v = 0; v < n; ++v) {
    if (!visited[v] && isConnected[u][v] == 1)
      dfs(v, visited, isConnected);
  }
}

void bfs(
    int u,
    vector<bool> &visited,
    unordered_map<int, vector<int>> &adj)
{
  queue<int> q;
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

// * ------------------------- Brute Force Approach -------------------------
// * TIME COMPLEXITY  O(N) + O(V + 2E) ~ O(N)
// * SPACE COMPLEXITY O(v)
int findCircleNumDfsBrute(vector<vector<int>> &isConnected) {
  int n = isConnected.size();

  // * make Adjacency graph
  unordered_map<int, vector<int>> adj = constructadj(isConnected);

  // * Classic DFS
  int ans = 0;
  vector<bool> visited(n, false);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfsBrute(i, visited, adj);
      ans++;
    }
  }

  return ans;
}

// * ------------------------- Optimal Approach -------------------------
// * Using DFS
// * TIME COMPLEXITY O(N) + O(V + 2E) ~ O(N)
// * SPACE COMPLEXITY O(1)
int findCircleNumDfs(vector<vector<int>> &isConnected) {
  int n = isConnected.size();
  vector<bool> visited(n, false);

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i, visited, isConnected);
      ans++;
    }
  }

  return ans;
}

// * ------------------------- Optimal Approach -------------------------
// * Using BFS
// * TIME COMPLEXITY O(v + e)
// * SPACE COMPLEXITY O(1)
int findCircleNumBfs(vector<vector<int>> &isConnected) {
  int n = isConnected.size();

  // * 1. make graph
  unordered_map<int, vector<int>> adj = constructadj(isConnected);

  // * 2. Classic BFS
  vector<bool> visited(n, false);
  int ans = 0;
  for (int u = 0; u < n; ++u) {
    if (!visited[u]) {
      bfs(u, visited, adj);
      ans++;
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  
  // * testcase 2
  // vector<vector<int>> isConnected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

  cout << "isConnected Cities: " << endl;
  for (auto &vec : isConnected)
    printArr(vec);

  int ans = findCircleNumDfsBrute(isConnected);
  // int ans = findCircleNumDfs(isConnected);
  // int ans = findCircleNumBfs(isConnected);
  cout << "Number of Provinces: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-no-of-provinces.cpp -o output && ./output
