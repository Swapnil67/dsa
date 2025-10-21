/**
 * * Topological sort
 * 
 * * Example 1  :
 * * Input      : V = 4, edges[][] = [[3, 0], [1, 0], [2, 0]]
 * * Output     : [3, 2, 1, 0]
 * 
 * * Example 2  :
 * * Input      : V = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5,2]]
 * * Output     : [4, 5, 0, 1, 2, 3] or [5, 2, 4, 0, 1, 3]
 * 
 * * https://www.naukri.com/code360/problems/topological-sort_982938
 * * https://www.geeksforgeeks.org/problems/topological-sort/1
 * 
 */

#include <queue>
#include <vector>
#include <iostream>

// ! Topological sort will only take place in Directed Acyclic Graph (DAG)

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

std::vector<std::vector<int>> constructadj(
    int V,
    std::vector<std::vector<int>> &edges,
    std::vector<int> &indegree)
{
  std::vector<std::vector<int>> adj(V);
  for (auto &it: edges) {
    // * a ---> b
    adj[it[0]].push_back(it[1]);
    indegree[it[1]]++;
  }
  return adj;
}

// * Classic BFS traversal in Graph
std::vector<int> bfs(
    std::vector<std::vector<int>> &adj,
    std::vector<int> &indegree)
{
 
  // * Push all the vertices with indegree = 0
  std::queue<int> q;
  for (int i = 0; i < indegree.size(); ++i) {
    if (indegree[i] == 0)
      q.push(i);
  }

  // * Classic BFS
  std::vector<int> ans;
  while (!q.empty()) {
    int u = q.front();
    ans.push_back(u);
    q.pop();

    for (auto &v : adj[u]) {
      indegree[v]--;
      if (indegree[v] == 0)
        q.push(v);
    }
  }

  return ans;
}

std::vector<int> topologicalSort(int V, std::vector<std::vector<int>> &edges) {

  // * Create an Adjacency list from edges 
  std::vector<int> indegree(V);
  std::vector<std::vector<int>> adj = constructadj(V, edges, indegree);

  // * For Debugging
  std::cout << "Adjacency List" << std::endl;
  printAdjList(adj);

  std::cout << "Indegree" << std::endl;
  printArr(indegree);

  return bfs(adj, indegree);
}

int main(void) {

  // * testcase 1
  // std::vector<std::vector<int>> edges = {{0, 3}, {0, 1}, {1, 3}}; 

  // * testcase 2
  // std::vector<std::vector<int>> edges = {{3, 0}, {1, 0}, {2, 0}}; 

  // * testcase 3
  std::vector<std::vector<int>> edges = {{1, 3}, {2, 3}, {4, 1}, {4, 0}, {5, 0}, {5, 2}};

  int V = edges.size();
  std::cout << "Edges: " << V << std::endl;

  for (auto &vec : edges)
    printArr(vec);

  std::vector<int> ans = topologicalSort(V, edges);
  std::cout << "Topological Sort" << std::endl;
  printArr(ans);

  return 0;
}


// * Run the code
// * g++ --std=c++20 06-kahn-algorithm.cpp -o output && ./output