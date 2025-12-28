/*
 * Leetcode - 198
 * House Robber
 * 
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
 * the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected
 * and it will automatically contact the police if two adjacent houses were broken into on the same night.

 * Given an integer array nums representing the amount of money of each house, return the maximum amount of money 
 * you can rob tonight without alerting the police.
 
 * Example 1
 * input            : nums = [1,2,3,1]
 * output           : 4

 * Example 2
 * input            : nums = [2,7,9,3,1]
 * output           : 12

 * https://leetcode.com/problems/house-robber/description/
 * https://www.naukri.com/code360/problems/loot-houses_630510
 * https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1
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

int dfs(int i, std::vector<int> &nums, std::vector<int> &cache) {
  int n = nums.size();
  if (i >= n)
    return 0;

  if (cache[i] != -1)
    return cache[i];

  int steal = nums[i] + dfs(i + 2, nums, cache);
  int skip = dfs(i + 1, nums, cache);
  return cache[i] = std::max(steal, skip);
}

// * ------------------------- Approach: Brute Force Approach -------------------------`
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(2^n) 
int bruteForce(std::vector<int> nums) {
  return dfs_brute(0, nums);
}

// * ------------------------- Approach: Better Approach -------------------------`
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) 
int betterApproach(std::vector<int> nums) {
  std::vector<int> cache(101, -1);
  return dfs(0, nums, cache);
}

// * ------------------------- Approach: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) 
int rob(std::vector<int> nums) {
  int n = nums.size();
  if (n == 1)
    return nums[0];

  std::vector<int> dp(n + 1, 0);
  dp[0] = 0;       // * 0 house
  dp[1] = nums[0]; // * 1 house
  for (int i = 2; i <= n; ++i) {
    int steal = nums[i - 1] + dp[i - 2];
    int skip = dp[i - 1];
    dp[i] = std::max(skip, steal);
  }
  // printArr(dp); // * For debugging

  return dp[n];
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