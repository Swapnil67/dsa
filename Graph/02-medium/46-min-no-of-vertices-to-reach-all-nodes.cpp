/*
 * Leetcode - 1557
 * Minimum Number of Vertices to Reach All Nodes
 * 
 * Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges
 * where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.
 * 
 * Find the smallest set of vertices from which all nodes in the graph are reachable. 
 * It's guaranteed that a unique solution exists.
 * 
 * Notice that you can return the vertices in any order.

 * Example 1  :
 * Input      : n = 6, grid = [[0,1],[0,2],[2,5],[3,4],[4,2]]
 * Output     : [0,3]

 * Example 2  :
 * Input      : n = 5, grid = [[0,1],[2,1],[3,1],[1,4],[2,4]]
 * Output     : [0,2,3]
 
 * https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
 * https://www.naukri.com/code360/problems/minimum-number-of-vertices-to-reach-all-nodes_1377922
*/

// ! Meta, Google

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

// * check out of bound
bool check_not_oob(const int &row, const int &col, std::vector<std::vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  return row >= 0 && row < m && col >= 0 && col < n;
}

std::unordered_map<int, std::vector<int>> constructadj(
    std::vector<int> &indegree,
    std::vector<std::vector<int>> &edges)
{
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it : edges)
  {
    indegree[it[1]]++;
    adj[it[0]].push_back(it[1]);
  }
  return adj;
}

// * ------------------------- APPROACH: Brute Force -------------------------`
// * Do Kahn's Algo
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
std::vector<int> bruteForce(int n, std::vector<std::vector<int>> edges) {
  // * 1. Create a Adj List
  std::vector<int> indegree(n, 0);
  std::unordered_map<int, std::vector<int>> adj = constructadj(indegree, edges);

  std::vector<int> ans;
  std::queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (indegree[i] == 0) {
      ans.push_back(i);
      q.push(i);
    }
  }

  int count = 0;
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    count++;
    for (auto &v : adj[u]) {
      indegree[v]--;
      if (indegree[v] == 0) {
        q.push(v);
      }
    }
  }

  if (count == n) // * We managed to reach all nodes
    return ans;

  return {};
}


// * ------------------------- APPROACH: Brute Force -------------------------`
// * Do Kahn's Algo
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
std::vector<int> findSmallestSetOfVertices(int n, std::vector<std::vector<int>> edges) {
  // * 1. mark all the nodes to true which have indegree 
  std::vector<int> indegree(n, 0);
  for (auto &it : edges) {
    int from = it[0], to = it[1];
    indegree[to] = 1;
  }

  // * 2. Return the nodes which do not have any degree
  std::vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (indegree[i] == 0)
      ans.push_back(i);
  }

  return ans;
} 


int main(void) {
  // * testcase 1
  int n = 6;
  std::vector<std::vector<int>> grid = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
  
  // * testcase 2
  // int n = 5;
  // std::vector<std::vector<int>> grid = {{0, 1}, {2, 1}, {3, 1}, {1, 4}, {2, 4}};

  std::cout << "-------- Grid -------- " << std::endl;
  for (auto &vec : grid)
  printArr(vec);
  
  std::cout << "-------- Answer -------- " << std::endl;
  // std::vector<int> ans = bruteForce(n, grid);
  std::vector<int> ans = findSmallestSetOfVertices(n, grid);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 46-min-no-of-vertices-to-reach-all-nodes.cpp -o output && ./output
