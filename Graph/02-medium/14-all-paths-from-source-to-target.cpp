/*
 * Leetcode - 797
 * All Paths From Source to Target
 *
 * Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, 
 * find all possible paths from node 0 to node n - 1 and return them in any order.
 * 
 * The graph is given as follows: graph[i] is a list of all nodes you can visit from
 * node i (i.e., there is a directed edge from node i to node graph[i][j]).

 * Example 1  :
 * Input      : graph = [[1,2],[3],[3],[]]
 * Output     : [[0,1,3],[0,2,3]]

 * Example 2  :
 * Input      : graph = [[4,3,1],[3,2,4],[3],[4],[]]
 * Output     : [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 * 
 * https://leetcode.com/problems/all-paths-from-source-to-target
*/

// ! Amazon, Microsoft

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

void dfs(int u, int &target, std::vector<int> &path,
         std::vector<std::vector<int>> &graph,
         std::vector<std::vector<int>> &ans)
{
  path.push_back(u);

  if (u == target - 1) {
    // printArr(path);
    ans.push_back(path);
  }

  for (auto &v : graph[u]) {
    dfs(v, target, path, graph, ans);
    path.pop_back();
  }
}
// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * Using DFS
// * V = Number of vertices
// * TIME COMPLEXITY O(2^V)
// * SPACE COMPLEXITY O(N) * O(V + E)
std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>> &graph) {
  std::vector<std::vector<int>> ans;
  int n = graph.size();
  if (n == 0)
    return ans;

  std::vector<int> path;
  dfs(0, n, path, graph, ans);
  return ans;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> graph = {{1, 2}, {3}, {3}, {}};

  // * testcase 2
  // std::vector<std::vector<int>> graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};

  std::cout << "graph: " << std::endl;
  for (auto &vec : graph)
    printArr(vec);

  std::vector<std::vector<int>> ans = allPathsSourceTarget(graph);
  std::cout << "All Paths From Source to Target: " << std::endl;
  for (auto &vec : ans)
    printArr(vec);
  return 0;
}

// * Run the code
// * g++ --std=c++20 14-all-paths-from-source-to-target.cpp -o output && ./output