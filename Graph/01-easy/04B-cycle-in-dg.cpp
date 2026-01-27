/**
 * * Directed Graph Cycle
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
#include <unordered_map>

// ! In cycle detection the `in_recursion` array will contain following values
// ! True Vertices = They have cycle
// ! False Vertices = They don't have cycle

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
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    printArr(vec);
  }
}

// * Function to construct an adjacency list from edge list
std::unordered_map<int, std::vector<int>> constructadj(std::vector<std::vector<int>> &edges)
{
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it: edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
  }
  return adj;
}

// * Function to construct an adjacency list from edge list
std::unordered_map<int, std::vector<int>> constructadj(
    std::vector<int> &indegree,
    std::vector<std::vector<int>> &edges)
{
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it: edges) {
    int u = it[0], v = it[1];
    indegree[v]++;
    adj[u].push_back(v);
  }
  return adj;
}

bool bfs(int N,
         std::vector<int> &indegree,
         std::unordered_map<int, std::vector<int>> adj)
{
  int count = 0;
  
  // * Push all the vertices with indegree = 0
  std::queue<int> q;
  for (int i = 0; i < indegree.size(); ++i) {
    if (indegree[i] == 0) {
      q.push(i);
      count++;
    }
  }

  // * Simple BFS
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto &v: adj[u]) {
      indegree[v]--;
      
      if (indegree[v] == 0) {
        count++;
        q.push(v);
      }
    }
  }

  // std::cout << "N: " << N << ", Count: " << count << std::endl;
  return count != N;
}

bool cycleDetectionBFS(int V, std::vector<std::vector<int>> &edges) {
  int N = V * 2;
  // * construct the adjacency list
  std::vector<int> indegree(N, 0);

  std::unordered_map<int, std::vector<int>> adj = constructadj(indegree, edges);
  // * For Debugging
  std::cout << "Adjacency List" << std::endl;
  printAdjList(adj);
  std::cout << "Indegree" << std::endl;
  printArr(indegree);

  return bfs(N, indegree, adj);
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> edges = {{0, 1}, {2, 1}}; // * false

  // * testcase 2
  // std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 3}}; // * true
  
  // * testcase 3
  std::vector<std::vector<int>> edges = {{0, 3}, {0, 1}, {1, 3}}; // * false

  int V = edges.size();
  std::cout << "Edges: " << V << std::endl;

  for (auto &vec : edges)
    printArr(vec);

  bool cycle = cycleDetectionBFS(V, edges);
  std::cout << "Cycle Detection In directed Graph: " << cycle << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 04B-cycle-in-dg.cpp -o output && ./output