/*
 * Leetcode - 2044
 * Count Number of Maximum Bitwise-OR Subsets
 * 
 * Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of 
 * different non-empty subsets with the maximum bitwise OR.
 * 
 * An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. 
 * Two subsets are considered different if the indices of the elements chosen are different.
 * 
 * The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).

 * Example 1
 * input            : nums = [3,1]
 * output           : 2
 * Explanation      : The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
 *                    - [3]
 *                    - [3,1]
 
 * Example 2
 * input            : nums = [3,2,1,5]
 * output           : 6
 * Explanation      : The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
 *                    - [3,5]
 *                    - [3,1,5]
 *                    - [3,2,5]
 *                    - [3,2,1,5]
 *                    - [2,5]
 *                    - [2,1,5]

 * https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/
*/

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

int max_or;
void solveBrute(int cur_or, vector<int> &nums, int i, int &ans) {
  if (i >= nums.size()) {
    ans += (cur_or == max_or);
    return;
  }

  solveBrute(cur_or | nums[i], nums, i + 1, ans);
  solveBrute(cur_or, nums, i + 1, ans);
}

int solve(int i, int cur_or, vector<int> &nums, vector<vector<int>> dp) {
  if (i >= nums.size())
    return cur_or == max_or;

  // * Returned memoized result
  if (dp[i][cur_or] != -1)
    return dp[i][cur_or];

  int take_count = solve(i + 1 ,cur_or | nums[i], nums, dp);
  int not_take_count = solve(i + 1, cur_or, nums, dp);

  return dp[i][cur_or] = take_count + not_take_count;
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * without Memoization
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n) (Recursion Stack)
int bruteForce(vector<int> nums) {
  max_or = 0;
  for (auto &x: nums) {
    max_or |= x;
  }
  // cout << max_or << endl;

  int ans = 0;
  solveBrute(0, nums, 0, ans);

  return ans;
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Memoizing to store subproblems result
// * TIME COMPLEXITY O(n * max_or)
// * SPACE COMPLEXITY O(n) (Recursion Stack)
int countMaxOrSubsets(vector<int> nums) {
  max_or = 0;
  for (auto &x : nums) {
    max_or |= x;
  }
  // cout << max_or << endl;

  int n = nums.size();
  vector<vector<int>> dp(n + 1, vector<int>(max_or + 1, -1));
  return solve(0, 0, nums, dp);
}

int main(void) {
  // * testcase 1
  // vector<int> nums = {3, 1};

  // * testcase 2
  // vector<int> nums = {2, 2, 2};

  // * testcase 3
  vector<int> nums = {3, 2, 1, 5};

  cout << "Input nums: ";
  printArr(nums);

  // int ans = bruteForce(nums);
  int ans = countMaxOrSubsets(nums);
  cout << "Number of Maximum Bitwise-OR Subsets: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 24-count-no-of-max-bitwise-or-subsets.cpp -o output && ./output 