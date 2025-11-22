/*
 * Leetcode - 2872
 * Maximum Number of K-Divisible Components
 *
 * There is an undirected tree with n nodes labeled from 0 to n - 1. 
 * You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] 
 * indicates that there is an edge between nodes ai and bi in the tree.
 * 
 * You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with
 * the ith node, and an integer k.
 * 
 * A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the 
 * resulting components all have values that are divisible by k, where the value of a connected component is the sum 
 * of the values of its nodes.
 * 
 * Return the maximum number of components in any valid split.

 * * Example 1  :
 * * Input      : n = 5, edges = [[0,2],[1,2],[1,3],[2,4]], values = [1,8,1,4,4], k = 6
 * * Output     : 2
 * 
 * * Example 2  :
 * * Input      : n = 7, edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [3,0,6,1,5,2,1], k = 3
 * * Output     : 3
 * 
 * https://leetcode.com/problems/maximum-number-of-k-divisible-components/
 * 
 */

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

void printAdjList(std::unordered_map<int, std::vector<int>> &adj) {
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    printArr(vec);
  }
}

std::unordered_map<int, std::vector<int>> constructadj(
    std::vector<std::vector<int>> &edges)
{
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it : edges) {
    int a = it[0], b = it[1];
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  return adj;
}

long long dfs(int u, int parent,
        int k, int &res,
        std::vector<int> &values,
        std::unordered_map<int, std::vector<int>> &adj)
{
  long long total = values[u] * 1ll;
  for (auto &v: adj[u]) {
    if (v == parent) // * prevents going to parent node
      continue;

    total += dfs(v, u, k, res, values, adj);
  }
  // std::cout << total << std::endl;

  if (total % k == 0) // * subtree which is divisible by 'k'
    res++;

  return total;
}

// * ------------------------- APPROACH: Optimal  -------------------------`
// * Proof Contradiction
// * Count the subtrees which are divisible by 'k' (Bottom up approach)
// * TIME COMPLEXITY  O(N)
// * SPACE COMPLEXITY O(N)
int maxKDivisibleComponents(int n, int k, std::vector<int> &values, std::vector<std::vector<int>> &edges) {
  // * Base case: if there are less than 2 nodes, return 1
  if (n < 2)
    return 1;
   
  // * 1. Construct Adj
  std::unordered_map<int, std::vector<int>> adj = constructadj(edges);
  // printAdjList(adj); // * For Debugging

  // * 2. DFS
  int ans = 0;
  dfs(0, -1, k, ans, values, adj);
  return ans;
}

int main(void) {
  // * testcase 1
  int n = 5, k = 6;
  std::vector<int> values = {1, 8, 1, 4, 4};
  std::vector<std::vector<int>> edges = {{0, 2}, {1, 2}, {1, 3}, {2, 4}};

  // * testcase 2
  // int n = 7, k = 3;
  // std::vector<int> values = {3};
  // std::vector<std::vector<int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};

  std::cout << "Values: ";
  printArr(values);
  std::cout << "-------- edges -------- " << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  int ans = maxKDivisibleComponents(n, k, values, edges);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-max-no-of-k-divisible-components.cpp -o output && ./output

/*
* -------------------------------- Recursion Tree ---------------------------------
*
*                                   dfs(0, -1) (total = 17 + 1 18)
*                                       |
*                   (return total = 17) |
*                                       |
*                                   dfs(2, 0)  (total = 12 + 4 + 1 = 17)
*                                       |
*                                       |
*      (return total = 12)     /                  \ (return total = 4)
*                             /                    \ 
*     (total = 8 + 4 = 12) dfs(1, 2)         dfs(4, 2) (total = 4)
*                              |
*        (return total = 4)    |
*                              |
*                           dfs(3, 1)
*/