/*
 * Leetcode - 1462
 * Graph Valid Tree
 * 
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
 * write a function to check whether these edges make up a valid tree.

 * Example 1:
 * Input     : n = 5, edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
 * Output    : true
 * 
 * Example 2:
 * Input     : n = 5, edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
 * Output    : false

 * https://neetcode.io/problems/valid-tree/question
 * https://leetcode.com/problems/graph-valid-tree/description/
 * https://www.naukri.com/code360/problems/graph-valid-tree_1376618
 * https://www.geeksforgeeks.org/problems/is-it-a-tree/1
*/

// ! Cycle Detection

// ! LinkedIn, Google, Meta, Microsoft

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

void printAdjList(unordered_map<int, vector<int>> &adj) {
  for (auto &[key, vec] : adj) {
    cout << key << " -> ";
    printArr(vec);
  }
}

// * TC = O(E)
unordered_map<int, vector<int>> constructadj(vector<vector<int>> &edges)  {
  unordered_map<int, vector<int>> adj;
  for (auto &it : edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return adj;
}

bool dfs(
    int u, int parent,
    vector<bool> &visited,
    unordered_map<int, vector<int>> adj)
{
  visited[u] = true;
  for (auto &v : adj[u]) {
    if (v == parent) // * don't go parent again
      continue;

    if (visited[v])
      return true;

    if (!visited[v] && dfs(v, u, visited, adj)) {
      return true;
    }
  }

  return false;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Cycle Detection
// * TIME COMPLEXITY O(V + E)
// * SPACE COMPLEXITY O(V + E)
bool validTree(
    int n,
    vector<vector<int>> &edges)
{
  // * 1. Create a adjaency list
  unordered_map<int, vector<int>> adj = constructadj(edges); 
  // printAdjList(adj); // * For debugging
  
  vector<bool> visited(n + 1, false);

  // * 2. Check if there is any cycle in graph
  if (dfs(0, -1, visited, adj)) {
    return false;
  }

  // * 3. check if any node is not visited that means its not a valid tree
  for (int i = 0; i < n; i++) {
    if (!visited[i])
      return false;
  }
  
  return true;
}

int main(void) {
  // * testcase 1
  // int n = 2;
  // vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};

  // * testcase 2
  int n = 2;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};

  cout << "-------- edges -------- " << endl;
  for (auto &vec : edges)
  printArr(vec);
  
  bool ans = validTree(n, edges);
  cout << "Is Graph Valid Tree: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 36-graph-valid-tree.cpp -o output && ./output

 