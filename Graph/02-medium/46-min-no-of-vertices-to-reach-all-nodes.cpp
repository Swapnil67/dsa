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

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
    if (i != n - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

// * check out of bound
bool check_not_oob(const int &row, const int &col, vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  return row >= 0 && row < m && col >= 0 && col < n;
}

unordered_map<int, vector<int>> constructadj(
    vector<int> &indegree,
    vector<vector<int>> &edges)
{
  unordered_map<int, vector<int>> adj;
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
vector<int> bruteForce(int n, vector<vector<int>> edges) {
  // * 1. Create a Adj List
  vector<int> indegree(n, 0);
  unordered_map<int, vector<int>> adj = constructadj(indegree, edges);

  vector<int> ans;
  queue<int> q;
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
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> edges) {
  // * 1. mark all the nodes to true which have indegree 
  vector<int> indegree(n, 0);
  for (auto &it : edges) {
    int from = it[0], to = it[1];
    indegree[to] = 1;
  }

  // * 2. Return the nodes which do not have any degree
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (indegree[i] == 0)
      ans.push_back(i);
  }
  return ans;
} 


int main(void) {
  // * testcase 1
  int n = 6;
  vector<vector<int>> grid = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
  
  // * testcase 2
  // int n = 5;
  // vector<vector<int>> grid = {{0, 1}, {2, 1}, {3, 1}, {1, 4}, {2, 4}};

  cout << "-------- Grid -------- " << endl;
  for (auto &vec : grid)
  printArr(vec);
  
  cout << "-------- Answer -------- " << endl;
  // vector<int> ans = bruteForce(n, grid);
  vector<int> ans = findSmallestSetOfVertices(n, grid);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 46-min-no-of-vertices-to-reach-all-nodes.cpp -o output && ./output
