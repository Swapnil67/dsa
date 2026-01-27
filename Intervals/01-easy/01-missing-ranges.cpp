/*
 * Missing Ranges
 *
 * You are given an inclusive range [lower, upper] and a sorted unique integer array nums, where all elements are within
 * the inclusive range.
 * 
 * A number x is considered missing if x is in the range [lower, upper] and x is not in nums.
 * 
 * Return the shortest sorted list of ranges that exactly covers all the missing numbers. 
 * That is, no element of nums is included in any of the ranges, and each missing number is covered by one of the ranges.
 * 
 * Example 1:
 * Input: nums = [0,1,3,50,75], lower = 0, upper = 99
 * Output: [[2,2],[4,49],[51,74],[76,99]]
 * 
 * Example 1:
 * Input: nums = [-1], lower = -1, upper = -1
 * Output: []
 * 
 * https://neetcode.io/problems/missing-ranges/question?list=allNC
 * https://www.geeksforgeeks.org/problems/missing-ranges-of-numbers1019/1
*/

// ! Apple, Google, Meta, Tiktok

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

// * ------------------------- APPROACH : Optimal Approach -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
vector<vector<int>> findMissingRanges(vector<int> &nums, int lower, int upper) {
  int n = nums.size();
  vector<vector<int>> ans;
  if (n == 0) {
    ans.push_back(vector<int>{lower, upper});
    return ans;
  }

  // * Check for any missing numbers between the lower bound and nums[0].
  if (lower < nums[0]) {
    ans.push_back(vector<int>{lower, nums[0] - 1});
  }

  // * Check for any missing numbers between successive elements of nums.
  for (int i = 0; i < n - 1; ++i) {
    if (nums[i + 1] - nums[i] <= 1)
      continue;

    ans.push_back(vector<int>{nums[i] + 1, nums[i + 1] - 1});
  }

  // * Check for any missing numbers between the upper bound and nums[0].
  if (upper > nums[n - 1]) {
    ans.push_back(vector<int>{nums[n - 1] + 1, upper});
  }

  return ans;
}

int main(void) {
  // * testcase 1
  std::vector<int> nums = {0, 1, 3, 50, 75};
  int lower = 0, upper = 99;

  // * testcase 2
  // std::vector<int> nums = {-1};
  // int lower = -1, upper = -1;

  std::cout << "nums: ";
  printArr(nums);
  std::cout << "Lower: " << lower << ", Upper: " << upper << std::endl;

  std::vector<std::vector<int>> ans = findMissingRanges(nums, lower, upper);
  std::cout << "Missing Ranges:" << std::endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 01-missing-ranges.cpp -o output && ./output
