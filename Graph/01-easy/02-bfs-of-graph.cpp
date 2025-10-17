/*
* BFS on Graph
*
* Do traverse in the same order as they are in the given adjacency list.
*
* Input  : adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
* Output : [0, 2, 3, 1, 4]
*
* https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
*/

// ! BFS - Always used to find Shortest Path

#include <queue>
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

std::vector<int> solve(std::vector<std::vector<int>> &adj, int u,
                       std::vector<bool> visited)
{
  std::vector<int> result;
  std::queue<int> q;

  // * push the first node to queue
  q.push(u);
  visited[u] = true;
  result.push_back(u);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    
    for (auto &v: adj[node]) {
      if(!visited[v]) {
        q.push(v);
        visited[v] = true;
        result.push_back(v);
      }
    }
  }

  return result;
}

std::vector<int> bfs(std::vector<std::vector<int>> &adj) {
  int u = adj.size();
  std::vector<bool> visited(u + 1, false);
  std::vector<int> result = solve(adj, 0, visited);
  return result;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

  // * testcase 2
  std::vector<std::vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};

  for (auto &vec : adj)
    printArr(vec);

  std::vector<int> ans = bfs(adj);
  std::cout << "BFS on Graph" << std::endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-bfs-of-graph.cpp -o output && ./output