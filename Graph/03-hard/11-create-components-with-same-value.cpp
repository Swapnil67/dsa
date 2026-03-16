/*
 * Leetcode - 2440
 * Create Components With Same Value
 * 
 * There is an undirected tree with n nodes labeled from 0 to n - 1.
 * 
 * You are given a 0-indexed integer array nums of length n where nums[i] represents the value of the ith node. 
 * You are also given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there
 * is an edge between nodes ai and bi in the tree.
 * 
 * You are allowed to delete some edges, splitting the tree into multiple connected components. 
 * Let the value of a component be the sum of all nums[i] for which node i is in the component.
 * 
 * Return the maximum number of edges you can delete, such that every connected component in the tree has the same value.
 * 
 * Example 1    :
 * Input        : nums = [6,2,2,2,6], edges = [[0,1],[1,2],[1,3],[3,4]] 
 * Output       : 2
 * 
 * Example 2    :
 * Input        : nums = [2], edges = []
 * Output       : 0
 * 
 * https://leetcode.com/problems/create-components-with-same-value
*/

#include <vector>
#include <numeric>
#include <iostream>
#include <unordered_map>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)

int dfs(int u, int &target, vector<int> &temp, vector<int> &nums,
        unordered_map<int, vector<int>> &adj)
{
  temp[u] = nums[u];
  for (auto &v : adj[u]) {
    if (temp[v])
      continue;

    temp[u] += dfs(v, target, temp, nums, adj);

    if (temp[u] > target) // * Early exit
      return 1e7;
  }
  // * this condition represents that the substree rooted at 'u' can be
  // * deleted from the tree. So, the sum of value can not add up to the
  // * parent of curent node.
  return (temp[u] == target) ? 0 : temp[u];
}

int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
  unordered_map<int, vector<int>> adj;
  for (auto& it : edges) {
      int u = it[0], v = it[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
  }

  int n = nums.size();
  int sum = accumulate(begin(nums), end(nums), 0);
  for (int i = n; i > 1; --i) {
    // * there is no probability that split the tree into i part.
    if (sum % i)
      continue;

    vector<int> temp(n);
    int target = sum / i;
    // cout << i << " -> " << target << endl;
    if (dfs(0, target, temp, nums, adj) == 0)
      return i - 1;
  }
  return 0;
}


int main(void) {
  // * testcase 1
  vector<int> nums = {6, 2, 2, 2, 6};
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};
  
  // * testcase 2
  // vector<int> nums = {2};
  // vector<vector<int>> edges = {};

  std::cout << "nums: ";
  printArr(nums);

  std::cout << "Edges" << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  int ans = componentValue(nums, edges);
  cout << "Components: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 11-create-components-with-same-value.cpp -o output && ./output
