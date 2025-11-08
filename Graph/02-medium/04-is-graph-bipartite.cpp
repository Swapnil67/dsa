/**
 * * Leetcode - 785
 * * Is Graph Bipartite?
 *
 * * There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. 
 * * You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to.
 * * More formally, for each v in graph[u], there is an undirected edge between node u and node v. 
 * * The graph has the following properties:
 * 
 * * - There are no self-edges (graph[u] does not contain u).
 * * - There are no parallel edges (graph[u] does not contain duplicate values).
 * * - If v is in graph[u], then u is in graph[v] (the graph is undirected).
 * * - The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

 * * A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that 
 * * every edge in the graph connects a node in set A and a node in set B.
 
 * * Return true if and only if it is bipartite.

 * * Example 1  :
 * * Input      : graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
 * * Output     : false
 * 
 * * Example 2  :
 * * Input      : graph = [[1,3],[0,2],[1,3],[0,2]]
 * * Output     : true
 * 
 * * https://leetcode.com/problems/is-graph-bipartite/description/
 * * https://www.geeksforgeeks.org/problems/bipartite-graph/1
 * * https://www.naukri.com/code360/problems/check-graph-is-bipartite-or-not_920551
*/

// ! microsoft, flipkart, samsung, meta

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

bool dfs(int u,
         int cur_color,
         std::vector<int> &colors,
         std::vector<std::vector<int>> &graph)
{
  colors[u] = cur_color;

  for (int &v: graph[u]) {
    // * check if we came across same color
    if (colors[v] == colors[u]) {
      return false;
    }
    
    if (colors[v] == -1) {
      int new_color = 1 - cur_color;
      if (!dfs(v, new_color, colors, graph))
        return false;
    }
  }
  
  return true;
}

bool isBipartiteDFS(std::vector<std::vector<int>> &graph)
{
  int V = graph.size();

  // * red = 1, green = 0
  std::vector<int> color(V + 1, -1);

  for (int u = 0; u < V; ++u) {
    if (color[u] == -1) {
      if (dfs(u, 1, color, graph) == false) {
        printArr(color);
        return false;
      }
    }
  }

  return true;
}

bool bfs(int cur, int cur_color,
         std::vector<int> &color,
         std::vector<std::vector<int>> &graph)
{
  std::queue<int> q;
  q.push(cur);
  color[cur] = cur_color;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int &v: graph[u]) {
      // * check if we came across same color
      if (color[v] == color[u]) {
        return false;
      }

      if (color[v] == -1) {
        color[v] = 1 - color[u];
        q.push(v);
      }
    }

  }

  return true;
}


bool isBipartiteBFS(std::vector<std::vector<int>> &graph)
{
  int V = graph.size();
  // * red = 1, green = 0
  std::vector<int> color(V, -1);

  for (int u = 0; u < V; ++u) {
    if (color[u] == -1) {
      if (bfs(u, 1, color, graph) == false)
        return false;
    }
  }

  return true;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};

  // * testcase 2
  // std::vector<std::vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};

  // * testcase 3
  // std::vector<std::vector<int>> graph = {{}, {2, 4, 6}, {1, 4, 8, 9}, {7, 8}, {1, 2, 8, 9}, {6, 9}, {1, 5, 7, 8, 9}, {3, 6, 9}, {2, 3, 4, 6, 9}, {2, 4, 5, 6, 7, 8}};

  std::cout << "Graph: " << std::endl;
  printAdjList(graph);

  bool ans = isBipartiteDFS(graph);
  // bool ans = isBipartiteBFS(graph);
  std::cout << "Is Graph Bipartite: " << ans << std::endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 04-is-graph-bipartite.cpp -o output && ./output