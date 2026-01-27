/**
 * * Undirected Graph Cycle
 * 
 * * Example 1  :
 * * Input      : V = 4, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 3]]
 * * Output     : true
 * 
 * * Example 2  :
 * * Input      : V = 3, edges[][] = [[0, 1], [1, 2]]
 * * Output     : false
 * 
 * * https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
 * * https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670
 * 
 */

 // ! Amazon, Flipkart

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
  for (auto &[u, vec] : adj) {
    std::cout << u << " -> ";
    printArr(vec);
  }
}

std::unordered_map<int, std::vector<int>> constructadj(std::vector<std::vector<int>> &edges) {
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it : edges) {
    // * u = it[0], v = it[1]
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
  }
  return adj;
}

bool dfs(
    int u, int parent,
    std::vector<bool> &visited,
    std::unordered_map<int, std::vector<int>> adj)
{
  visited[u] = true;
  
  for (auto &v: adj[u]) {
    if (v == parent) // * don't go parent again
      continue;

    // * loop found
    if (visited[v])
      return true;
    
    if (!visited[v] && dfs(v, u, visited, adj)) {
        return true;
    }
  }

  return false;
}

// * DFS
// * Use a parent pointer
bool cycleDetectionDFS(std::vector<std::vector<int>> &edges) {
  std::unordered_map<int, std::vector<int>> adj = constructadj(edges);
  // printAdjList(adj); // * For debugging

  int V = edges.size();
  std::vector<bool> visited(V + 1, false);
  for (int u = 0; u < V; ++u) {
    if (!visited[u] && dfs(u, -1, visited, adj))
      return true;
  }
  return false;
}

bool bfs(
    int u,
    std::vector<bool> &visited,
    std::unordered_map<int, std::vector<int>> adj)
{
  std::queue<std::pair<int, int>> q;
  q.push({u, -1}); // * initial pair
  visited[u] = true;

  while (!q.empty()) {
    std::pair<int, int> p = q.front();
    q.pop();

    int source = p.first;
    int parent = p.second;

    for (int &v : adj[source]) {
      // std::cout << "v: " << v << std::endl;
      if (!visited[v]) {
        visited[v] = true;
        q.push({v, source});
      } 
      else if (v != parent) {
        // * already visited and not parent
        return true;
      }
    }
  }

  return false;
}

// * BFS
bool cycleDetectionBFS(std::vector<std::vector<int>> &edges) {
  int V = edges.size();
  std::vector<bool> visited(V + 1, false);

  std::unordered_map<int, std::vector<int>> adj = constructadj(edges);
  std::cout << "Adjacency List" << std::endl;
  printAdjList(adj); // * For Debugging

  for (int i = 0; i < V; ++i) {
    if (!visited[i] && bfs(i, visited, adj)) {
      return true;
    }
  }

  return false;
}


int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}}; // * true

  // * testcase 2
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}}; // * false

  for (auto &vec : edges)
    printArr(vec);

  // bool cycle = cycleDetectionDFS(edges);
  bool cycle = cycleDetectionBFS(edges);
  std::cout << "Cycle Detection In Undirected Graph: " << cycle << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-cycle-in-udg.cpp -o output && ./output