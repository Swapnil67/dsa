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
int sum;
int dfs(int i, int cur, int &target, vector<int> &nums,
        vector<vector<int>> &dp) {
  if (i >= nums.size())
    return target == cur;

  // * Add sum to cur to prevent indexing -ve element (i.e. cur can be -ve)
  if (dp[i][cur + sum] != INT_MIN)
    return dp[i][cur + sum];

  return dp[i][cur + sum] = dfs(i + 1, cur + nums[i], target, nums, dp) +
                            dfs(i + 1, cur - nums[i], target, nums, dp);
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
int bruteForce(vector<int> &nums, int target) {
  int sum = accumulate(begin(nums), end(nums), 0);
  int k = (sum - target) / 2;
  return dfs(0, k, nums);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Solved in a little different way
// * Top Down + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
int betterApproach(vector<int> &nums, int target) {
  int n = nums.size();
  sum = accumulate(begin(nums), end(nums), 0);
  vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, INT_MIN));
  return dfs(0, 0, target, nums, dp);
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
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
  dp[0][0] = (nums[0] == 0) ? 2 : 1;
  if (nums[0] != 0 && k >= nums[0]) {
    dp[0][nums[0]] = 1;
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      int not_take = dp[i - 1][j];
      int take = 0;
      if (j >= nums[i - 1]) {
        take = dp[i - 1][j - nums[i - 1]];
      }
      dp[i][j] = (not_take + take);
    }
  }

  // * For Debugging
  for (auto &vec : dp)
    printArr(vec);

  return dp[n - 1][k];
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
int findTargetSumWaysDP2(vector<int> &nums, int target) {
  int sum = accumulate(begin(nums), end(nums), 0);
  if (sum - target < 0 || (sum - target) % 2 != 0)
    return 0;

  int n = nums.size();
  int k = (sum - target) / 2;
  // cout << "k: " << k << endl;

  vector<int> dp(k + 1, 0);
  dp[0] = nums[0] == 0 ? 2 : 1; // * Base Case
  if (nums[0] != 0 && k >= nums[0]) // * Base Case
    dp[nums[0]] = 1;
  // printArr(dp);

  vector<int> next_dp(k + 1, 0);

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      int not_take = dp[j];
      int take = 0;
      if (j >= nums[i]) {
        take = dp[j - nums[i]];
      }
      next_dp[j] = (not_take + take);
    }
    dp = next_dp;
    // printArr(dp);
  }

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