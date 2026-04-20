/*
 * Number of Connected Components in an Undirected Graph 

 * https://neetcode.io/problems/count-connected-components/question
 * https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
*/

// ! Meta, Amazon, Google, Apple, TikTok, X

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> adj;
void dfs(int u, vector<bool> &visited) {
  visited[u] = true;
  for (auto &v: adj[u]) {
    if (!visited[v]) {
      dfs(v, visited);
    }
  }
}

int countComponents(int n, vector<vector<int>>& edges) {
  int comp = 0;
  for (auto &it: edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> visited(n + 1, false);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i, visited);
      comp += 1;
    }
  }
  return comp;
}

int main() {
  // TODO
}
