/*
* DFS on Graph
*
* Do traverse in the same order as they are in the given adjacency list.
*
* Input  : adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
* Output : [0, 2, 4, 3, 1]
*
* https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
* https://www.naukri.com/code360/problems/dfs-traversal_630462
*/

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

void solve(vector<vector<int>> &adj,
                       int u,
                       vector<bool> &visited,
                       vector<int> &result)
{
  if (visited[u])
    return;

  visited[u] = true;
  result.push_back(u);

  for (auto &v: adj[u]) {
    if (!visited[v]) {
      solve(adj, v, visited, result);
    }
  }
}

vector<int> dfs(vector<vector<int>> &adj) {
  int u = adj.size();
  vector<int> result;
  vector<bool> visited(u, false);
  solve(adj, 0, visited, result);
  return result;
}

int main(void) {
  // * testcase 1
  // vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

  // * testcase 2
  vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};

  for (auto &vec : adj)
    printArr(vec);

  vector<int> ans = dfs(adj);
  cout << "DFS on Graph" << endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-dfs-of-graph.cpp -o output && ./output