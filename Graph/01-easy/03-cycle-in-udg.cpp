/**
 * * UnDirected Graph Cycle
 * 
 * * Example 1  :
 * * Input      : V = 4, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 3]]
 * * Output     : true
 * 
 * * Example 2  :
 * * Input      : V = 3, edges[][] = [[0, 1], [1, 2]]
 * * Output     : false
 * 
 * * https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
 * * https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626
 * 
 */

#include <queue>
#include <vector>
#include <iostream>

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

std::vector<std::vector<int>> constructadj(int V, std::vector<std::vector<int>> &edges) {
  std::cout << "V: " << V << std::endl;
  std::vector<std::vector<int>> adj(V + 1);
  // for (int i = 0; i <= V; ++i) {
  for (auto &it : edges) {
    // printArr(it);
    // std::cout << it[0] << " -- " << it[1] << std::endl;
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
    // std::cout << "-----------" << std::endl;
  }
  return adj;
}

bool dfs(std::vector<std::vector<int>> &edges,
         std::vector<bool> &visited,
         int u, int parent)
{
  visited[u] = true;
  
  for (auto &v: edges[u]) {
    if (v == parent)
      continue;

    if (visited[v] == true)
      return true;
    
    if (!visited[v]) {
      if (dfs(edges, visited, v, u) == true)
        return true;
    }
  }

  return false;
}

// * DFS
bool cycleDetectionDFS(std::vector<std::vector<int>> &edges) {
  int V = edges.size();
  std::vector<bool> visited(V + 1, false);
  // return dfs(edges, visited, 0, -1);
  for (int i = 0; i < V; ++i) {
    if (!visited[i] && dfs(edges, visited, i, -1))
      return true;
  }
  return false;
}

bool bfs(std::vector<std::vector<int>> &adj,
         std::vector<bool> &visited, int u)
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

  std::vector<std::vector<int>> adj = constructadj(V + 1, edges);

  // * For Debugging
  std::cout << "Adjacency List" << std::endl;
  printAdjList(adj);

  for (int i = 0; i < V; ++i) {
    if (!visited[i] && bfs(adj, visited, i)) {
      std::cout << i << std::endl;
      return true;
    }
  }

  return false;
}


int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};

  // * testcase 2
  // std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}};

  // * testcase 3
  // std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};

  for (auto &vec : edges)
    printArr(vec);

  // bool cycle = cycleDetectionDFS(edges);
  bool cycle = cycleDetectionBFS(edges);
  std::cout << "Cycle Detection In Undirected Graph: " << cycle << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 03-cycle-in-udg.cpp -o output && ./output