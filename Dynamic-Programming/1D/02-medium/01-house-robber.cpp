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

// ! Amazon, Paytm, Walmart, Google, Flipkart, LinkedIn, Airbnb

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

int dfs_brute(int i, vector<int> &nums) {
  int n = nums.size();
  if (i >= n)
    return 0;
  int steal = nums[i] + dfs_brute(i + 2, nums);
  int skip = dfs_brute(i + 1, nums);
  return max(steal, skip);
}

int dfs(int i, vector<int> &nums, vector<int> &dp) {
  int n = nums.size();
  if (i >= n)
    return 0;

  if (dp[i] != -1)
    return dp[i];

  int steal = nums[i] + dfs(i + 2, nums, dp);
  int skip = dfs(i + 1, nums, dp);
  return dp[i] = max(steal, skip);
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(2^n) 
int bruteForce(vector<int> nums) {
  return dfs_brute(0, nums);
}

// * ------------------------- Approach: Better Approach -------------------------
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) 
int betterApproach(vector<int> nums) {
  vector<int> cache(101, -1);
  return dfs(0, nums, cache);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) 
int rob(vector<int> nums) {
  int n = nums.size();
  if (n == 1)
    return nums[0];
  if (n == 2)
    return max(nums[0], nums[1]);

  vector<int> dp(n + 1, 0);
  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);
  for (int i = 2; i < n; ++i) {
    int skip = dp[i - 1];
    int steal = nums[i] + dp[i - 2];
    dp[i] = max(skip, steal);
  }
  return dp[n - 1];
}

int main(void) {
  // * testcase 1
  // vector<int> nums = {1, 2, 3, 1};

  // * testcase 2
  // vector<int> nums = {2, 7, 9, 3, 1};

  // * testcase 3
  // vector<int> nums = {2, 5};
  
  // * testcase 4
  // vector<int> nums = {2};

  // * testcase 5
  vector<int> nums = {2, 1, 1, 2};

  cout << "Input nums: ";
  printArr(nums);

  // int ans = bruteForce(nums);
  // int ans = betterApproach(nums);
  int ans = rob(nums);
  cout << "found: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-house-robber.cpp -o output && ./output 