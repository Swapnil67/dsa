/*
 * Leetcode - 802
 * Find Eventual Safe States
 * 
 * There is a directed graph of n nodes with each node labeled from 0 to n - 1. 
 * The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent 
 * to node i, meaning there is an edge from node i to each node in graph[i].
 * 
 * - A node is a "terminal node" if there are no outgoing edges. 
 * - A node is a "safe node" if every possible path starting from that node leads to a "terminal node" (or another safe node).
 * 
 * Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 * Example 1:
 * Input     : graph = [[1,2],[2,3],[5],[0],[5],[],[]]
 * Output    : [2,4,5,6]
 * 
 * Example 2:
 * Input     : graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
 * Output    : [4]

 * https://leetcode.com/problems/find-eventual-safe-states/description/
*/

// ! Microsoft

// ! Cycle Detection

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

// * Detect Cycle in DG
bool dfs(
    int u,
    std::vector<bool> &visited,
    std::vector<bool> &in_recursion,
    std::vector<std::vector<int>> &graph)
{
  visited[u] = true;
  in_recursion[u] = true;

  for (auto& v : graph[u]) {
    if (!visited[v] && dfs(v, visited, in_recursion, graph)) {
      return true; // * Found cycle return from here also to stop recursion calls.
    }
    else if (in_recursion[v]) { // * cycle detected
      return true;
    }
  }

  in_recursion[u] = false;
  return false;
}

// * ------------------------- APPROACH : Optimal Approach -------------------------`
// * Cycle detection in Directed Graph
// * 
// * TIME COMPLEXITY O(V + E)
// * SPACE COMPLEXITY O(V + E)
std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph) {
    std::vector<int> ans;
    int n = graph.size();
    if (n == 0)
        return ans;

    std::vector<bool> visited(n + 1, false);
    std::vector<bool> in_recursion(n + 1, false);

    for (int u = 0; u < n; ++u) {
      if (!visited[u]) {
        dfs(u, visited, in_recursion, graph);
      }
    }

    // * In cycle detection the `in_recursion` array will contain following values
    // * True Vertices = They have cycle 
    // * False Vertices = They don't have cycle 
    // printArr(in_recursion);
    
    for (int i = 0; i < n; ++i) {
      if (!in_recursion[i]) {
        ans.push_back(i);
      }
    }

    return ans;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
  // std::vector<std::vector<int>> graph = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};

  std::cout << "-------- graph -------- " << std::endl;
  for (auto &vec : graph)
  printArr(vec);

  std::vector<int> ans = eventualSafeNodes(graph);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 34-find-eventual-safe-states.cpp -o output && ./output

 