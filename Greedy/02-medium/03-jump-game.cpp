/*
 * Leetcode - 55
 * Jump Game
 * 
 * You are given an integer array nums. You are initially positioned at the array's first index, 
 * and each element in the array represents your maximum jump length at that position.
 * 
 * Return true if you can reach the last index, or false otherwise.
 * 
 * https://neetcode.io/problems/jump-game/
 * https://leetcode.com/problems/jump-game/description/
*/

// ! Amazon, Microsoft, Google, Meta, Uber, Adobe, ByteDance, Oracle

#include <vector>
#include <iostream>

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

// * Without Memoization
bool dfs(int i, vector<int> &nums) {
  int n = nums.size();
  if (i == n - 1)
    return true;

  int end = min((int)n - 1, i + nums[i]);
  for (int j = i + 1; j <= end; ++j) {
    if (dfs(j, nums))
      return true;
  }
  return false;
}

// * With Memoization
bool dfs(int i, vector<int> &nums, vector<int> &dp) {
  int n = nums.size();
  if (i == n - 1)
    return true;

  if (dp[i] != -1) return dp[i];

  int end = min((int)n - 1, i + nums[i]);
  for (int j = i + 1; j <= end; ++j) {
    if (dfs(j, nums, dp))
      return dp[i] = true;
  }
  return dp[i] = false;
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down (Exponential)
// * TIME COMPLEXITY O(n^n)
// * SPACE COMPLEXITY O(n)
int bruteForce(vector<int> &nums) {
  return dfs(0, nums);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n)
int betterApproach(vector<int> &nums) {
  vector<int> dp(100001, -1);
  return dfs(0, nums, dp);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Greedy
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O()
bool jumpGame(vector<int> &nums) {
  int n = nums.size();
  int max_idx = 0;

  for (int i = 0; i < n; ++i) {
    if (i > max_idx)
      return false;
    max_idx = max(max_idx, i + nums[i]);
  }

  return true;
}

int main(void) {
  // * testcase 1
  // vector<int> nums = {2, 3, 1, 1, 4};

  // * testcase 2
  vector<int> nums = {3, 2, 1, 0, 4};

  cout << "Input nums: ";
  printArr(nums);

  bool ans = jumpGame(nums);
  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 03-jump-game.cpp -o output && ./output
