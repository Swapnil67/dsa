/*
* DFS on Graph
*
* Do traverse in the same order as they are in the given adjacency list.
*
* Input  : adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
* Output : [0, 2, 4, 3, 1]
*
* https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
*/

#include <vector>
#include <iostream>

template <typename T>
void printArr(std::vector<T> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

void solve(std::vector<std::vector<int>> &adj,
                       int u,
                       std::vector<bool> &visited,
                       std::vector<int> &result)
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

std::vector<int> dfs(std::vector<std::vector<int>> &adj) {
  int u = adj.size();
  std::vector<int> result;
  std::vector<bool> visited(u, false);
  solve(adj, 0, visited, result);
  return result;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

  // * testcase 2
  std::vector<std::vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};

  for (auto &vec : adj)
    printArr(vec);

  std::vector<int> ans = dfs(adj);
  std::cout << "DFS on Graph" << std::endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-dfs-of-graph.cpp -o output && ./output