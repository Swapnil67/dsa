/*
 * Leetcode - 213
 * House Robber II
 * 
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
 * All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
 * Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if 
 * two adjacent houses were broken into on the same night.

 * Given an integer array nums representing the amount of money of each house, return the maximum amount of money 
 * you can rob tonight without alerting the police.
 
 * Example 1
 * input            : nums = [1,2,3,1]
 * output           : 4

 * Example 2
 * input            : nums = [2,7,9,3,1]
 * output           : 12

 * https://leetcode.com/problems/house-robber-ii/description/
*/

// * Amazon, Paytm, Walmart, Google, Flipkart, LinkedIn, Airbnb

#include <vector>
#include <iostream>

template <typename T>
void printArr(std::vector<T> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

int dfs_brute(int i, std::vector<int> &nums) {
  int n = nums.size();
  if (i >= n)
    return 0;
  int steal = nums[i] + dfs_brute(i + 2, nums);
  int skip = dfs_brute(i + 1, nums);
  return std::max(steal, skip);
}

int dfs(int i, int n, std::vector<int> &nums, std::vector<int> &cache) {
  if (i > n)
    return 0;

  if (cache[i] != -1)
    return cache[i];

  int steal = nums[i] + dfs(i + 2, n, nums, cache);
  int skip = dfs(i + 1, n, nums, cache);
  return cache[i] = std::max(steal, skip);
}

// * ------------------------- Approach: Brute Force Approach -------------------------`
// * Plain Recursion
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(2^n) 
int bruteForce(std::vector<int> nums) {
  return dfs_brute(0, nums);
}

// * ------------------------- Approach: Better Approach -------------------------`
// * Top Down Approach
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) 
int betterApproach(std::vector<int> nums) {
  int n = nums.size();
  if (n == 1)
    return nums[0];
  if (n == 2)
    return std::max(nums[0], nums[1]);

  // * case 1: Start from 0th house
  std::vector<int> cache(101, -1);
  int first = dfs(0, n - 2, nums, cache);

  // * case 2: Start from 1st house
  cache.clear();
  int second = dfs(1, n - 1, nums, cache);
  return std::max(first, second);
}

// * ------------------------- Approach: Optimal Approach -------------------------`
// * Bottom Up Approach
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) 
int rob(std::vector<int> nums) {
  int n = nums.size();
  if (n == 1)
    return nums[0];
  if (n == 2)
    return std::max(nums[0], nums[1]);

  // * case 1: Start from 1st house & skip the last house
  std::vector<int> dp(n + 1, 0);
  dp[0] = 0;
  for (int i = 1; i <= n - 1; ++i) {
    int skip = dp[i - 1];
    int steal = nums[i - 1] + ((i - 2 >= 0) ? dp[i - 2] : 0);
    dp[i] = std::max(steal, skip);
  }
  int res1 = dp[n - 1];

  // * case 2: Start from 2nd house & take the last house
  dp.clear();
  dp[0] = 0;
  dp[1] = 0;
  for (int i = 2; i <= n; ++i) {
    int skip = dp[i - 1];
    int steal = nums[i - 1] + ((i - 2 >= 0) ? dp[i - 2] : 0);
    dp[i] = std::max(steal, skip);
  }
  int res2 = dp[n];

  return std::max(res1, res2);
}

int main(void) {
  // * testcase 1
  // std::vector<int> nums = {1, 2, 3, 1};

  // * testcase 2
  // std::vector<int> nums = {2, 7, 9, 3, 1};

  // * testcase 3
  // std::vector<int> nums = {2};

  // * testcase 4
  // std::vector<int> nums = {2, 5};

  // * testcase 5
  std::vector<int> nums = {2, 1, 1, 2};

  std::cout << "Input nums: ";
  printArr(nums);

  // int ans = bruteForce(nums);
  // int ans = betterApproach(nums);
  int ans = rob(nums);
  std::cout << "found: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-house-robber.cpp -o output && ./output 