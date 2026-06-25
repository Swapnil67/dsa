/*
 * Subset Sum Equal To K
 * 
 * You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. 
 * Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
 
 * Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

 * Example 1
 * input            : k = 5, nums = {4, 3, 9, 2};
 * output           : true
 * Explanation      : subset sum {3,2} equals 5

 * Example 2
 * input            : k = 1, nums = {4, 3, 9, 2};
 * output           : false
 * Explanation      : no subset sum equals 'k'

 * https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954
*/

// ! Amazon, Meta, Paypal, Microsoft

// ! DP on subsequences

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
bool solve(int& k, vector<int>& nums, int cur_sum, int i) {
  if (cur_sum == k)
    return true;

  if (i >= nums.size())
    return false;

  bool not_take = solve(k, nums, cur_sum, i + 1); 
  bool take = false;
  if (k >= cur_sum + nums[i])
    take = solve(k, nums, cur_sum + nums[i], i + 1);

  return take || not_take;
}

// * With Memoization
bool dfs(int i, int k, vector<int>& nums, vector<vector<int>> &dp) {
  if (0 == k)
    return true;

  if (i >= nums.size())
    return false;

  if (dp[i][k] != -1)
    return dp[i][k];

  bool not_take = dfs(i + 1, k, nums, dp);
  bool take = false;
  if (k >= nums[i])
    take = dfs(i + 1, k - nums[i], nums, dp);

  return dp[i][k] = (take || not_take);
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
bool bruteForce(vector<int> nums, int k) {
  return solve(k, nums, 0, 0);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(n * k)
// * SPACE COMPLEXITY O(n * k) * O(n)
bool betterApproach(vector<int> nums, int k) {
  vector<vector<int>> dp(nums.size() + 1, vector<int>(k + 1, -1));
  return dfs(0, k, nums, dp);
}


// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
int subsetSumEqualsK(vector<int> &nums, int &k) {
  int n = nums.size();
  vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
  for (int i = 0; i < n; ++i)
    dp[i][0] = true;

  for (int i = 1; i < n; ++i) {
    for (int t = 1; t <= k; ++t) {
      bool not_take = dp[i - 1][t];
      bool take = false;
      if (t >= nums[i - 1]) {
        take = dp[i - 1][t - nums[i - 1]];
      }
      dp[i][t] = (not_take | take);
    }
  }

  // * For Debugging
  for (auto &vec : dp)
    printArr(vec);

  return 0;
}


// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(n * k)
// * SPACE COMPLEXITY O(n)
int subsetSumEqualsKDP2(vector<int> &nums, int k) {
  int n = nums.size();

  vector<bool> dp(k + 1, false);
  dp[0] = true;

  vector<bool> next_dp(k + 1, false);
  next_dp[0] = true;

  for (int i = 0; i < n; ++i) {
    for (int t = 1; t <= k; ++t) {
      bool not_take = dp[t];
      bool take = false;
      if (t >= nums[i]) {
        take = dp[t - nums[i]];
      }
      next_dp[t] = (not_take | take);
    }
    dp = next_dp;
    printArr(dp);
  }

  return dp[k];
}

int main(void) {
  // * testcase 1
  // int k = 5;
  // vector<int> nums = {4, 3, 9, 2};

  // * testcase 2
  int k = 1;
  vector<int> nums = {4, 3, 9, 2};

  cout << "k: " << k << endl;
  cout << "Input nums: ";
  printArr(nums);

  // bool ans = bruteForce(nums, k);
  // bool ans = betterApproach(nums, k);
  // bool ans = subsetSumEqualsK(nums, k);
  bool ans = subsetSumEqualsKDP2(nums, k);
  
  cout << "found: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 11-subset-sum-equal-to-k.cpp -o output && ./output