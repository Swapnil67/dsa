/*
 * Leetcode - 377
 * Combination Sum IV
 *
 * Given an array of distinct integers nums and a target integer target, return the number of possible 
 * combinations that add up to target.
 * 
 * The test cases are generated so that the answer can fit in a 32-bit integer.
 *
 * Example 1
 * input            : nums = [1,2,3], target = 4
 * output           : 7
 * Explanation      : 
 *
 * Example 2
 * input            : nums = [9], target = 3
 * output           : 0
 * Explanation      :
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 * https://neetcode.io/problems/combination-sum-iv/question
 */

// ! Meta, Snapchat

#include <vector>
#include <iostream>
#include <algorithm>

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

// * without Memoization
int dfs(vector<int> &nums, int k) {
  if (k == 0)
    return 1;

  int res = 0;
  for (int num : nums) {
    if (k < num) // * early exit
      break;
    res += dfs(nums, k - num);
  }

  return res;
}

// * with Memoization
int dfs(vector<int> &nums, int k, unordered_map<int, int> &memo) {
  if (memo.count(k))
    return memo[k];

  int ways = 0;
  for (auto &num : nums) {
    if (k < num)
      break;
    ways += dfs(nums, k - num, memo);
  }

  return memo[k] = ways;
}


// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^t)
// * SPACE COMPLEXITY O(t)
int bruteForce(vector<int>& nums, int target) {
  sort(begin(nums), end(nums));
  return dfs(nums, target);
}


// * ------------------------- Approach: Better Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(N * t)
// * SPACE COMPLEXITY O(t)
int combinationSum4(vector<int>& nums, int target) {
 sort(begin(nums), end(nums));
 // * memo[t] = number of ways to sum to value t
 unordered_map<int, int> memo;
 memo[0] = 1;
 return dfs(nums, target, memo);
}


// * ------------------------- Approach: Optimal Approach -------------------------
// * BOTTOM UP 
// * TIME COMPLEXITY O(N * target)
// * SPACE COMPLEXITY O(N * target)
// int combinationSum4(vector<int>& nums, int target) {
// TODO
// }

int main(void) {
  // * testcase 1
  int target = 4;
  vector<int> nums = {1, 2, 3};

  cout << "target: " << target << endl;
  cout << "Nums: ";
  printArr(nums);

  int ans = bruteForce(nums, target);
  // bool ans = combinationSum4(nums);

  cout << "possible combinations: " << ans << endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++17 29-combination-sum-iv.cpp -o output && ./output

