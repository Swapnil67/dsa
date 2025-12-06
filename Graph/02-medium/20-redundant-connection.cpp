/**
* * Leetcode - 684
 * * Redundant Connection
 *
 * * In this problem, a tree is an undirected graph that is connected and has no cycles.

 * * You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. 
 * * The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. 
 * * The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge
 * * between nodes ai and bi in the graph.

 * * Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers,
 * * return the answer that occurs last in the input.
 * 
 * * Example 1  :
 * * Input      : edges = [[1,2],[1,3],[2,3]]
 * * Output     : [2,3]
 * 
 * * Example 2  :
 * * Input      : edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
 * * Output     : [1,4]
 * 
 * * https://leetcode.com/problems/redundant-connection/description/
 * * https://www.naukri.com/code360/problems/redundant-connection-i_1281198
 */

// ! DSU

// ! Google

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
template <typename T>
void printAdjList(std::vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    std::cout << i << " -> ";
    printArr(adj[i]);
  }
}

int find(int x, std::vector<int> &parent) {
  if (x == parent[x])
    return x;

  return parent[x] = find(parent[x], parent);
}

void Union(int x, int y, std::vector<int> &parent, std::vector<int> &rank) {
  int x_parent = find(x, parent);
  int y_parent = find(y, parent);
  if (x_parent == y_parent)
    return;

  if (rank[x_parent] > rank[y_parent]) {
    parent[y_parent] = x_parent;
  }
  else if (rank[x_parent] < rank[y_parent]) {
    parent[x_parent] = y_parent;
  }
  else {
    parent[x_parent] = y_parent;
    rank[y_parent]++;
  }
}

bool dfs(
    int u, int v,
    std::vector<bool> visited,
    std::unordered_map<int, std::vector<int>> &adj)
{
  visited[u] = true;
  if (u == v)
    return true;

  // * Go to neighbours
  for (auto &ngbr : adj[u]) {
    if (!visited[ngbr]) {
      if(dfs(ngbr, v, visited, adj)) {
        return true;
      }
    }
  }

  return false;
}

bool bfs(
    int u, int v,
    std::vector<bool> visited,
    std::unordered_map<int, std::vector<int>> &adj)
{

  std::queue<int> q;
  q.push(u);
  visited[u] = true;

  while(!q.empty()) {
    int node = q.front();
    q.pop();

    if (node == v)
      return true;

    // * Go to neighbours
    for (auto &ngbr: adj[node]) {
      if (!visited[ngbr]) {
        visited[ngbr] = true;
        q.push(ngbr);
      }
    }
  }

  return false;
}


// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Using DFS
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
std::vector<int> findRedundantConnectionDFS(std::vector<std::vector<int>> &edges) {
  int n = edges.size();
  std::unordered_map<int, std::vector<int>> adj;

  std::vector<bool> visited(n, false);

  for (auto &edge: edges) { // * O(N)
    int u = edge[0], v = edge[1];

    // * If we are able to connect from u -> v in our current adj then it 
    // * means that current 'edge' is a redudant connection.
    if (adj.find(u) != adj.end() &&
        adj.find(v) != adj.end() &&
        dfs(u, v, visited, adj)) { // * O(N)
      return edge;
    }

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  return {};
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Using BFS
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
std::vector<int> findRedundantConnectionBFS(std::vector<std::vector<int>> &edges) {
  int n = edges.size();
  std::unordered_map<int, std::vector<int>> adj;

  std::vector<bool> visited(n, false);

  for (auto &edge: edges) { // * O(N)
    int u = edge[0], v = edge[1];

    // * If we are able to connect from u -> v in our current adj then it means current 'it' is a redudant connection
    if (adj.find(u) != adj.end() &&
        adj.find(v) != adj.end() &&
        bfs(u, v, visited, adj))
    { // * O(N)
      return edge;
    }

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  return {};
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Using DSU [Most Optimal]
// * TIME COMPLEXITY O(N * alpha(n))
// * SPACE COMPLEXITY O(N)
std::vector<int> findRedundantConnectionDSU(std::vector<std::vector<int>> &edges) {
  int n = edges.size();

  // * 1. Initialize rank and parent vectors
  std::vector<int> rank(n + 1, 1);
  std::vector<int> parent(n + 1);
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
  
  for (auto &edge: edges) { // * O(N)
    int u = edge[0], v = edge[1];
    int u_parent = find(u, parent);
    int v_parent = find(v, parent);

    // * Both are already present in graph
    if (u_parent == v_parent)
      return edge;

    Union(u, v, parent, rank);
  }

  return {};
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
  
  // * testcase 2
  // std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1,5}};

  std::cout << "Edges: " << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  // std::vector<int> ans = findRedundantConnectionDFS(edges);
  // std::vector<int> ans = findRedundantConnectionBFS(edges);
  std::vector<int> ans = findRedundantConnectionDSU(edges);
  std::cout << "Redundant Connection: " << std::endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 20-redundant-connection.cpp -o output && ./output