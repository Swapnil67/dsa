/*
 * Leetcode - 2016
 * Maximum Difference Between Increasing Elements
 * 
 * Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (
 * i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].
 *
 * Return the maximum difference. If no such i and j exists, return -1.
 *
 * Example 1:
 * Input: prices = [1,5,2,10]
 * Output: 9
 * Explanation: 10 - 1 = 9
 * 
 * Example 2:
 * Input: prices = [9,4,3,2]
 * Output: -1
 * Explanation: It's in decreasing order
 * 
 * Example 3:
 * Input: prices = [87,68,91,86,58,63,43,98,6,40]
 * Output: 55
 * Explanation: 98 - 43 = 55
 * 
 * https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/
*/

// ! Google, Adobe, Bloomberg

#include <vector>
#include <climits>
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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> &nums) {
  int n = nums.size();
  int max_diff = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (nums[i] < nums[j]) {
        max_diff = max(max_diff, nums[j] - nums[i]);
      }
    }
  }
  return max_diff;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Sliding Window
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maximumDifference(vector<int> &nums) {
  int n = nums.size();
  int max_diff = -1;
  int i = 0, j = 1;
  while (j < n) {
    if (i <= j && nums[i] >= nums[j]) // * As per constraints
      i = j;
    else
      max_diff = max(max_diff, nums[j] - nums[i]);
    j++;
  }
  return max_diff;
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * Dynamic Programming
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maximumDifferenceDP(vector<int> &nums) {
  int n = nums.size();
  int max_diff = -1;
  int cur_min = nums[0], j = 1;

  while (j < n) {
    if (cur_min < nums[j]) {
      max_diff = max(max_diff, nums[j] - cur_min);
    }
    cur_min = min(cur_min, nums[j]);
    j++;
  }
  return max_diff;
}


int main(void) {
  // * testcase 1
  std::vector<int> nums = {1, 5, 2, 10};

  // * testcase 2
  // std::vector<int> nums = {9, 4, 3, 2};

  // * testcase 3
  // std::vector<int> nums = {87, 68, 91, 86, 58, 63, 43, 98, 6, 40};

  std::cout << "Stock Prices" << std::endl;
  printArr(nums);

  // int p = bruteForce(nums);
  int p = maximumDifference(nums);
  // int p = maximumDifferenceDP(nums);
  std::cout << "Maximum Difference: " << p << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 05-max-diff-between-increasing-elements.cpp -o output && ./output