/*
 * Leetcode - 494
 * Target Sum
 * 
 * You are given an integer array nums and an integer target.
 * 
 * You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer
 * in nums and then concatenate all the integers.
 * 
 * For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them 
 * to build the expression "+2-1".
 * 
 * Return the number of different expressions that you can build, which evaluates to target.
 * 
 * https://leetcode.com/problems/target-sum/description/
 * https://neetcode.io/problems/target-sum/question
*/

// ! Amazon, Google, Meta, Uber, Pinterest, Myntra

// * Same as Partitions With Given Difference

// * Intuition
// * s1 = total_sum - s2
// * s1 - s2 = d
// * total_sum - s2 - s2 = d
// * total_sum - d = 2 * s2
// * s2 = (total_sum - d) / 2;
// * We need to find subsets whose sum is equal to s2

#include <vector>
#include <numeric>
#include <climits>
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

// * Without Memoization
int dfs(int i, int k, vector<int> &nums) {
  if (i == nums.size())
    return k == 0;

  int not_take = dfs(i + 1, k, nums);
  int take = 0;
  if (k >= nums[i]) {
    take = dfs(i + 1, k - nums[i], nums);
  }
  return (not_take + take);
}

// * With Memoization
int dfs(int i, int k, vector<int> &nums, vector<vector<int>> &dp) {
  if (i == nums.size())
    return k == 0;

  if (dp[i][k] != -1)
    return dp[i][k];

  int not_take = dfs(i + 1, k, nums, dp);
  int take = 0;
  if (k >= nums[i]) {
    take = dfs(i + 1, k - nums[i], nums, dp);
  }
  return dp[i][k] = (not_take + take);
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
int bruteForce(vector<int> &nums, int target) {
  int sum = accumulate(begin(nums), end(nums), 0);
  if (sum - target < 0 || (sum - target) % 2 != 0)
    return 0;
  int k = (sum - target) / 2;
  return dfs(0, k, nums);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
int betterApproach(vector<int> &nums, int target) {
  int n = nums.size();
  int sum = accumulate(begin(nums), end(nums), 0);
  if (sum - target < 0 || (sum - target) % 2 != 0)
    return 0;

  int k = (sum - target) / 2;
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
  return dfs(0, k, nums, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
int findTargetSumWays(vector<int> &nums, int target) {
  int sum = accumulate(begin(nums), end(nums), 0);
  if (sum - target < 0 || (sum - target) % 2 != 0)
    return 0;

  int n = nums.size();
  int k = (sum - target) / 2;
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

  // * --- Base Case: Initialize the first element (row 0) ---
  // * If the first element is 0, we can either include it or exclude it,
  // * both resulting in a subset sum of 0 (2 ways).
  if (nums[0] == 0) {
    dp[0][0] = 2;
  }
  else {
    dp[0][0] = 1; // * If it's non-zero, there's exactly 1 way to make a sum of 0 (by not taking it).

    // * If the first element fits within our target sum constraint,
    // * there is 1 way to make a sum equal to its value (by taking it).
    if (nums[0] <= k) 
      dp[0][nums[0]] = 1;
  }

  // * --- DP Transitions ---
  for (int i = 1; i < n; ++i) { // * we have already handled i = '0' case
    for (int t = 0; t <= k; ++t) {
      // * Case 1: Exclude the current element nums[i].
      // * The number of ways remains the same as the previous state.
      int not_take = dp[i - 1][t];

      // * Case 2: Include the current element nums[i].
      // * This is only possible if the current target 't' is at least nums[i].
      int take = 0;
      if (t >= nums[i]) {
        take = dp[i - 1][t - nums[i]];
      }

      // * Total ways for the current state is the sum of both choices.
      dp[i][t] = not_take + take;
    }
  }

  // * For Debugging
  for (auto &vec : dp)
    printArr(vec);

  // Return the total ways to achieve target 'k' using all 'n' elements.
  return dp[n - 1][k];
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
int findTargetSumWaysDP2(vector<int> &nums, int target) {
  int n = nums.size();

  //* Calculate the total sum of all elements in the array
  int sum = accumulate(begin(nums), end(nums), 0);

  //* --- Edge Cases / Math Guards ---
  //* 1. If the absolute target is greater than the total sum possible, it's impossible.
  //* 2. S1 - S2 = target and S1 + S2 = sum implies S2 = (sum - target) / 2.
  //*    Therefore, (sum - target) must be non-negative and perfectly divisible by 2.
  if (abs(target) > sum || (sum - target) % 2 != 0)
    return 0;

  //* k is our target subset sum for the elements assigned a negative sign
  int k = (sum - target) / 2;

  //* dp[t] stores the number of ways to achieve a subset sum of 't'
  //* Space Complexity: O(k) instead of O(n * k)
  vector<int> dp(k + 1, 0);

  //* Base Case: There is exactly 1 way to form a sum of 0 (by choosing an empty subset)
  dp[0] = 1;

  //* Process each number from the input array one by one
  for (int i = 0; i < n; ++i) {
    int cur_num = nums[i];

    //* --- Reverse Loop Optimization ---
    //* We iterate backwards from 'k' down to 'cur_num'.
    //* Why backwards? It ensures that we build dp[t] using values from the *previous*
    //* iteration (dp[t - cur_num]), preventing us from reusing the same element 'cur_num' multiple times.
    //* Why stop at cur_num? If t < cur_num, it's impossible to include cur_num,
    //* so its value remains unchanged (dp[t] = dp[t] + 0). Skipping it saves CPU cycles.
    for (int t = k; t >= cur_num; --t) {
      //* Total ways to get sum 't' = (Ways without taking cur_num) + (Ways by taking cur_num)
      dp[t] += dp[t - cur_num];
    }
  }

  //* Return the total number of ways to form the subset sum 'k'
  return dp[k];
}

int main(void) {
  // * testcase 1
  int target = 3;
  vector<int> nums = {1, 1, 1, 1, 1};
  
  // * testcase 2
  // int target = 2;
  // vector<int> nums = {2, 2, 2};

  cout << "Target: " << target << endl;
  cout << "Nums: ";
  printArr(nums);

  // int ans = bruteForce(nums, target);
  // int ans = betterApproach(nums, target);
  // int ans = findTargetSumWays(nums, target);
  int ans = findTargetSumWaysDP2(nums, target);

  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 17-target-sum.cpp -o output && ./output