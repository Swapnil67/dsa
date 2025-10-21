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

#include <stack>
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

std::vector<std::vector<int>> constructadj(int V, std::vector<std::vector<int>> &edges) {
  std::vector<std::vector<int>> adj(V);
  for (auto &it: edges) {
    adj[it[0]].push_back(it[1]);
  }
  return adj;
}

// * Classic DFS traversal in Graph
void dfs(std::vector<std::vector<int>> &adj, int u,
         std::stack<int> &st,
         std::vector<bool> &visited)
{
  visited[u] = true;

  for (auto &v : adj[u]) {
    if (!visited[v]) {
      dfs(adj, v, st, visited);
    }
  }

  st.push(u);
}

std::vector<int> topologicalSort(int V, std::vector<std::vector<int>> &edges) {

  // * Create an Adjacency list from edges 
  std::vector<std::vector<int>> adj = constructadj(V, edges);

  // * For Debugging
  std::cout << "Adjacency List" << std::endl;
  printAdjList(adj);

  std::stack<int> st;
  
  // * Classic DFS traversal in Graph
  std::vector<bool> visited(V + 1, false);
  for (int u = 0; u < V; ++u) {
    if (!visited[u])
      dfs(adj, u, st, visited);
  }

  // * Create the ans from stack
  std::vector<int> ans;
  while(!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }
  
  return ans;
}

int main(void) {

  // * testcase 1
  // std::vector<std::vector<int>> edges = {{0, 3}, {0, 1}, {1, 3}}; 

  // * testcase 2
  // std::vector<std::vector<int>> edges = {{3, 0}, {1, 0}, {2, 0}}; 

  // * testcase 3
  std::vector<std::vector<int>> edges = {{1, 3}, {2, 3}, {4, 1}, {4, 0}, {5, 0}, {5,2}};

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
// * g++ --std=c++20 05-topological-sort.cpp -o output && ./output