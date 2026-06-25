/*
 * Leetcode - 45
 * Jump Game II
 * 
 * You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.
 * 
 * Each element nums[i] represents the maximum length of a forward jump from index i. 
 * In other words, if you are at index i, you can jump to any index (i + j) where:
 * 
 * - 0 <= j <= nums[i] and
 * - i + j < n
 * 
 * Return the minimum number of jumps to reach index n - 1. 
 * The test cases are generated such that you can reach index n - 1.
 * 
 * https://neetcode.io/problems/jump-game-ii/question
 * https://leetcode.com/problems/jump-game-ii/description/
*/

// ! Amazon, Microsoft, Google, Meta, Bloomberg, Adobe, ByteDance, PhonePe

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
int dfs(int idx, vector<int> &nums) {
  if (idx >= nums.size() - 1)
    return 0;

    int mini = 10001;
  for (int i = 1; i <= nums[idx]; ++i) {
    mini = min(mini, 1 + dfs(i + idx, nums));
  }
  return mini;
}

// * With Memoization
int dfs(int idx, vector<int> &nums, vector<int> &dp) {
  if (dp[idx] != -1)
    return dp[idx];

  if (idx >= nums.size() - 1)
    return 0;

  int mini = 10001;
  for (int i = 1; i <= nums[idx]; ++i) {
    mini = min(mini, 1 + dfs(i + idx, nums, dp));
  }
  return dp[idx] = mini;
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
int jump(vector<int> &nums) {
  vector<int> dp(100001, -1);
  return dfs(0, nums, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
int jump(vector<int>& nums) {
    int jumps = 0, l = 0, r = 0;
    int n = nums.size();
    while (r < n - 1) {
        int farthest = 0;
        for (int i = l; i <= r; ++i) {
          farthest = max(farthest, i + nums[i]);
        }
        l = r + 1;
        r = farthest;
        jumps++;
    }
    return jumps;
}

int main(void) {
  // * testcase 1
  vector<int> nums = {2, 3, 1, 1, 4};

  // * testcase 2
  // vector<int> nums = {2, 3, 0, 1, 4};

  cout << "Input nums: ";
  printArr(nums);

  int ans = jump(nums);
  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 04-jump-game-ii.cpp -o output && ./output
