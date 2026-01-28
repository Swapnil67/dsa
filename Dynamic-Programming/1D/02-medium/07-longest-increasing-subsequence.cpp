/*
 * Leetcode - 300 
 * Longest Increasing Subsequence (LIS)
 * 
 * Given an integer array nums, return the length of the longest strictly increasing subsequence.
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
*/

// ! Amazon, Google, Meta, Microsoft, Oracle, Uber, Paypal, Bloomberg

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

bool is_increasing(std::vector<int> &nums) {
  int n = nums.size();
  for (int i = 1; i < n; ++i) {
    if (nums[i - 1] >= nums[i])
      return false;
  }
  return true;
}


void solve_brute(int i, int &ans, std::vector<int> cur, vector<int> &nums) {
  if (i >= nums.size()) {
    // printArr(cur);
    if (cur.size() > ans)
      ans = cur.size();
    return;
  }

  if (cur.size() > 0) {
    if (cur.back() < nums[i]) {
      cur.push_back(nums[i]);
    }
  } else {
    cur.push_back(nums[i]);
  }

  solve_brute(i + 1, ans, cur, nums);

  if (cur.size() > 0)
    cur.pop_back();
  solve_brute(i + 1, ans, cur, nums);
}


int lis(int i, int prev_idx, vector<int> &nums, std::vector<std::vector<int>> &dp) {
  if (i >= nums.size()) {
    return 0;
  }

  if (prev_idx != -1 && dp[i][prev_idx] != -1) // * Imp Check
    return dp[i][prev_idx];

  // * only take if cur number is strictly greater previous number
  int take = 0;
  if (prev_idx == -1 || nums[prev_idx] < nums[i]) { 
    take = 1 + lis(i + 1, i, nums, dp);
  }

  int skip = lis(i + 1, prev_idx, nums, dp);

  if (prev_idx != -1) // * Imp Check
    dp[i][prev_idx] = max(take, skip);

  return max(take, skip);
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * Generate All the subsequences
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(2^n) 
int bruteForce(vector<int> &nums) {
  int ans = 0;
  solve_brute(0, ans, {}, nums);
  return ans;
}

// * ------------------------- Approach 2: Better Approach -------------------------
// * Recursion + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2) 
int lengthOfLIS(vector<int> &nums) {
  int n = nums.size();
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, -1));
  return lis(0, -1, nums, dp);
}

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * Bottom Up DP
// * TIME COMPLEXITY O(n * n)
// * SPACE COMPLEXITY O(n) 
int lengthOfLIS2(vector<int> &nums) {
  int n = nums.size();
  vector<int> t(n + 1, 1);
  int max_len = 1;
  for (int i = 0; i < n; ++i) {
    int cur = nums[i];
    for (int j = 0; j < i; ++j) {
      if (cur > nums[j]) {
        t[i] = max(t[i], t[j] + 1);
        max_len = max(max_len, t[i]);
      }
    }
  }
  
  // printArr(t);
  return max_len;
}

int main(void) {
  // * testcase 1
  std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

  // * testcase 2
  // std::vector<int> nums = {0, 1, 0, 3, 2, 3};

  // * testcase 3
  // std::vector<int> nums = {7, 7, 7, 7, 7, 7, 7};

  std::cout << "Input nums: ";
  printArr(nums);

  // int ans = bruteForce(nums);
  // int ans = lengthOfLIS(nums);
  int ans = lengthOfLIS2(nums);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 07-longest-increasing-subsequence.cpp -o output && ./output
