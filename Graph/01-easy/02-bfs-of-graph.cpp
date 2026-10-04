/*
* BFS on Graph
*
* Do traverse in the same order as they are in the given adjacency list.
*
* Input  : adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
* Output : [0, 2, 3, 1, 4]
*
* https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
* https://www.naukri.com/code360/problems/bfs-in-graph_973002
*/

// ! BFS - Always used to find Shortest Path

#include <queue>
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

vector<int> bfs(vector<vector<int>> &adj) {
  int V = adj.size();
  vector<int> result;

  // * visited bool vector
  vector<bool> visited(V + 1, false);
  visited[0] = true;

  // * push the first node to queue
  queue<int> q;
  q.push(0);
  
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    result.push_back(node);
    
    for (auto &v: adj[node]) {
      if(!visited[v]) {
        q.push(v);
        visited[v] = true;
      }
    }
  }

  return result;
}

int main(void) {
  // * testcase 1
  vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

  // * testcase 2
  // vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};

  for (auto &vec : adj)
    printArr(vec);

  vector<int> ans = bfs(adj);
  cout << "BFS on Graph" << endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-bfs-of-graph.cpp -o output && ./output