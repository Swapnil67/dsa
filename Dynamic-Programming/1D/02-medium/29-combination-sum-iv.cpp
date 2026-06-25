/*
 * Leetcode - 377
 * Combination Sum IV
 *
 * Given an array of distinct integers nums and a target integer target, return the number of possible 
 * combinations that add up to target.
 * 
 * The test cases are generated so that the answer can fit in a 32-bit integer.
 *
 * Example 1
 * input            : nums = [1,2,3], target = 4
 * output           : 7
 * Explanation      : 
 *
 * Example 2
 * input            : nums = [9], target = 3
 * output           : 0
 * Explanation      :
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 */

#include <vector>
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

int dfs(vector<int> &nums, int target) {
  if (target == 0)
    return 1;

  int res = 0;
  for (int num : nums) {
    if (target < num)
      break;
    res += dfs(nums, target - num);
  }

  return res;
}


int dfs(vector<int> &nums, int target, vector<int> &dp) {
  if (target == 0)
    return dp[target];

  if (dp[target] != -1)
   return dp[target];

  int res = 0;
  for (int num : nums) {
    if (target < num)
      break;
    res += dfs(nums, target - num);
  }

  return dp[target] = res;
}


// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^t)
// * SPACE COMPLEXITY O(t)
int bruteForce(vector<int>& nums, int target) {
  sort(begin(nums), end(nums));
  return dfs(nums, target);
}


// * ------------------------- Approach: Better Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(N * t)
// * SPACE COMPLEXITY O(t)
int combinationSum4(vector<int>& nums, int target) {
 sort(begin(nums), end(nums));
  // * dp[t] = number of ways to sum to value t

 vector<int> dp(target + 1, -1);
 dp[0] = 1;
 return dfs(nums, target, dp);
}


// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(N * target)
// * SPACE COMPLEXITY O(N * target)
int combinationSum4(vector<int>& nums, int target) {
 sort(begin(nums), end(nums));
 vector<int> dp(target + 1, -1);
 dp[0] = 1;
 return dfs(nums, target, dp);
}

int main(void) {
  // * testcase 1
  int target = 4;
  vector<int> nums = {1, 2, 3};

  cout << "target: " << target << endl;
  cout << "Nums: ";
  printArr(nums);

  int ans = bruteForce(nums, target);
  // bool ans = canPartition(nums);
  // bool ans = canPartition2(nums);
  // bool ans = canPartition3(nums);

  cout << "possible combinations: " << ans << endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++17 29-combination-sum-iv.cpp -o output && ./output

