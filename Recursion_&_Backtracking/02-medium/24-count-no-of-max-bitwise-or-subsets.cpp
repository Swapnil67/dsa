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

template <typename T>
void printArr(std::vector<T> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

void solveBrute(int &target, int cur_or, std::vector<int> &nums, int i, int &ans) {
  // std::cout << cur_or << std::endl;
  
  if (i >= nums.size()) {
    if (cur_or == target)
      ans++;
    return;
  }

  solveBrute(target, cur_or | nums[i], nums, i + 1, ans);
  solveBrute(target, cur_or, nums, i + 1, ans);
}

int solve(int &max_or, int cur_or, std::vector<int> &nums,
          std::vector<std::vector<int>> t,
          int i)
{
  if (i >= nums.size()) {
    if (cur_or == max_or)
      return 1;
    return 0;
  }

  // * Returned memoized result
  if (t[i][cur_or] != -1)
    return t[i][cur_or];

  int take_count = solve(max_or, cur_or | nums[i], nums, t, i + 1);
  int not_take_count = solve(max_or, cur_or, nums, t, i + 1);

  t[i][cur_or] = take_count + not_take_count;
  return t[i][cur_or];
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------`
// * without Memoization
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n) (Recursion Stack)
int bruteForce(std::vector<int> nums) {
  int max_or = 0;
  for (auto &x: nums) {
    max_or |= x;
  }
  // std::cout << max_or << std::endl;

  int ans = 0;
  solveBrute(max_or, 0, nums, 0, ans);

  return ans;
}

// * ------------------------- Approach: Optimal Approach -------------------------`
// * Memoizing to store subproblems result
// * TIME COMPLEXITY O(n * max_or)
// * SPACE COMPLEXITY O(n) (Recursion Stack)
int countMaxOrSubsets(std::vector<int> nums) {
  int max_or = 0;
  for (auto &x : nums) {
    max_or |= x;
  }
  // std::cout << max_or << std::endl;

  int n = nums.size();
  std::vector<std::vector<int>> t(n + 1, std::vector<int>(max_or + 1, -1));
  return solve(max_or, 0, nums, t, 0);
}

int main(void) {
  // * testcase 1
  // std::vector<int> nums = {3, 1};

  // * testcase 2
  // std::vector<int> nums = {2, 2, 2};

  // * testcase 3
  std::vector<int> nums = {3, 2, 1, 5};

  std::cout << "Input nums: ";
  printArr(nums);

  // int ans = bruteForce(nums);
  int ans = countMaxOrSubsets(nums);
  std::cout << "Number of Maximum Bitwise-OR Subsets: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 24-count-no-of-max-bitwise-or-subsets.cpp -o output && ./output 