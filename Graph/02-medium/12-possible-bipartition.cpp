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

// * Print adjacency list
void printAdjList(unordered_map<int, vector<int>> &adj) {
  int n = adj.size();
  for (auto &it: adj) {
    cout << it.first << " -> ";
    printArr(it.second);
  }
}

unordered_map<int, vector<int>> constructadj(vector<vector<int>> &dislikes) {
  unordered_map<int, vector<int>> adj;
  for (auto &it : dislikes) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return adj;
}

bool dfs(int u, int color, vector<int> &colors,
         unordered_map<int, vector<int>> &adj) {
  colors[u] = color;
  for (auto &v : adj[u]) {
    if (colors[u] == colors[v])
      return false;

    if (colors[v] == -1) {
      int new_color = 1 - color;
      if (dfs(v, new_color, colors, adj) == false)
        return false;
    }
  }
  return true;
}

bool bfs(int node, vector<int> &color, unordered_map<int, vector<int>> &adj) {
  queue<int> q;
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

bool possibleBipartitionDFS(int n, vector<vector<int>> &dislikes) {
  // * 1. construct adjacency list
  unordered_map<int, vector<int>> adj = constructadj(dislikes);
  printAdjList(adj); // * For debugging 

  // * 2. Classic dfs
  vector<int> color(n + 1, -1); // * Also acts a visited vector
  for (int i = 1; i <= n; ++i) {
    if (color[i] == -1)
      if (!dfs(i, 1, color, adj))
        return false;
  }

  return true;
}

bool possibleBipartitionBFS(int n, vector<vector<int>> &dislikes) {
  // * 1. construct adjacency list
  unordered_map<int, vector<int>> adj = constructadj(dislikes);
  printAdjList(adj); // * For debugging 

  // * 2. Classic bfs
  vector<int> color(n + 1, -1); // * Also acts a visited vector
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
  // vector<vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 4}};
  
  // * testcase 2
  int n = 3;
  vector<vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 3}};

  cout << "n: " << n << endl;
  cout << "dislikes: " << endl;
  for (auto &vec : dislikes)
    printArr(vec);

  bool ans = possibleBipartitionDFS(n, dislikes);
  // bool ans = possibleBipartitionBFS(n, dislikes);
  cout << "Possible Bipartition: " << ans << endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 12-possible-bipartition.cpp -o output && ./output