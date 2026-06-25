/*
 * Leetcode - 416
 * Partition Equal Subset Sum
 *
 * Given an integer array nums, return true if you can partition the array into two subsets such that
 * the sum of the elements in both subsets is equal or false otherwise.
 *
 * Example 1
 * input            : nums = [1,5,11,5]
 * output           : true
 * Explanation      : The array can be partitioned as [1, 5, 5] and [11].
 *
 * Example 2
 * input            : nums = [1,2,3,5]
 * output           : false
 * Explanation      : no subset sum equals 'k'The array cannot be partitioned into equal sum subsets.
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/
*/

// ! Amazon, Meta, Paypal, Microsoft, Flipkart, Tiktok, Visa

// ! DP on subsequences

#include <vector>
#include <numeric>
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
bool dfs(int i, int target, vector<int> &nums) {
  if (i == nums.size())
    return target == 0;

  if (target < 0)
    return false;

  return dfs(i + 1, target, nums) || dfs(i + 1, target - nums[i], nums);
}

// * With Memoization
bool dfs(int i, int target, vector<int> &nums, vector<vector<int>> &dp) {
  if (i == nums.size())
    return target == 0;

  if (target < 0)
    return false;

  if (dp[i][target] != -1)
    return dp[i][target];

  dp[i][target] = dfs(i + 1, target, nums, dp) ||
                  dfs(i + 1, target - nums[i], nums, dp);

  return dp[i][target];
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^N)
// * SPACE COMPLEXITY O(N)
bool bruteForce(vector<int> &nums) {
  int sum = accumulate(begin(nums), end(nums), 0);
  if (sum % 2 == 1)
    return false;

  int target = sum / 2;
  return dfs(0, target, nums);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(N * target)
// * SPACE COMPLEXITY O(N * target)
bool canPartition(vector<int> &nums) {
  int sum = accumulate(begin(nums), end(nums), 0);
  if (sum % 2 == 1)
    return false;

  int target = sum / 2;
  vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
  return dfs(0, target, nums, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(N * target)
// * SPACE COMPLEXITY O(N * target)
bool canPartition2(vector<int> &nums) {
  int n = nums.size();

  int sum = accumulate(begin(nums), end(nums), 0);
  if (sum % 2 == 1)
    return false;

  int target = sum / 2;
  vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

  for (int i = 0; i <= n; ++i) {
    dp[i][0] = true;
  }

  // * The i = 0 row is the base case — it represents using zero elements from the array.
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= target; ++j) {
      if (j >= nums[i - 1]) {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
      }
      else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  return dp[n][target];
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * dp = represents all possible sums we can make after processing elements up to index i-1
// * next_dp = represents all possible sums we can make after processing elements up to index i
// * Bottom Up + Space Optimization (Rolling DP)
// * TIME COMPLEXITY O(N * target)
// * SPACE COMPLEXITY O(N * target)
bool canPartition3(vector<int>& nums) {
  int n = nums.size();

  int sum = accumulate(begin(nums), end(nums), 0);
  if (sum % 2 == 1) return false;

  int target = sum / 2;
  vector<int> dp(target + 1, false);
  vector<int> next_dp(target + 1, false);
  dp[0] = true;

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= target; ++j) {
      next_dp[j] = dp[j];
      if (j >= nums[i]) {
        // * dp[j - nums[i]] asks: "Could we make sum j - nums[i] before? If yes, then by adding the current element, we can now make sum j!"
        next_dp[j] = dp[j] || dp[j - nums[i]];
      }
    }
    dp = next_dp;
  }
  
  return dp[target];
}

int main(void) {
  vector<int> nums = {1, 5, 11, 5};
  cout << "Nums: ";
  printArr(nums);

  // bool ans = bruteForce(nums);
  // bool ans = canPartition(nums);
  // bool ans = canPartition2(nums);
  bool ans = canPartition3(nums);

  cout << "Can partition: " << ans << endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 28-partition-equal-subset-sum.cpp -o output && ./output

