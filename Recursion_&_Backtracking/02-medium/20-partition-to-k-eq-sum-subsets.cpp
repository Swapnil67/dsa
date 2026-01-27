/*
 * Leetcode - 698
 * Partition to K Equal Sum Subsets
 * 
 * Given an integer array nums and an integer k, return true if it is possible to divide this array into 
 * k non-empty subsets whose sums are all equal.

 * Return the maximum possible length of s.
 
 * A subsequence is an array that can be derived from another array by deleting some or no elements without
 * changing the order of the remaining elements.

 * Example 1
 * input       : nums = [4,3,2,3,5,2,1], k = 4
 * output      : true

 * Example 1
 * input       : nums = [1,2,3,4], k = 3
 * output      : false

 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets
*/

#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

template <typename T>
void printArr(std::vector<T> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

std::vector<bool> used;
bool solve(std::vector<int> &nums,
           int cur_sum, int &target_sum,
           int k, int i)
{
  // std::cout << cur_sum << std::endl;

  if (k == 0)
    return true;

  if (cur_sum == target_sum) {
    return solve(nums, 0, target_sum, k - 1, 0);
  }

  for (int j = i; j < nums.size(); ++j) {
    if (used[i] || cur_sum + nums[j] > target_sum)
      continue;

    used[j] = true;
    
    if (solve(nums, cur_sum + nums[i], target_sum, k, j + 1))
      return true;

    used[j] = false;
  }

  return false;
}

// * ------------------------- Approach: Optimal Approach -------------------------`
// * - 'm' is the length of all strings in strs
// * TIME COMPLEXITY O(2^n * m)
// * SPACE COMPLEXITY O(n)
bool canPartitionKSubsets(std::vector<int>& nums, int k) {
  int sum = std::accumulate(begin(nums), end(nums), 0);
  if (sum % k != 0)
    return false;

  int n = nums.size();
  used.assign(n, false);

  int cur_sum = 0;
  int target_sum = sum / k;
  std::cout << "target_sum: " << target_sum << std::endl;
  // std::sort(nums.rbegin(), nums.rend());
  
  return solve(nums, cur_sum, target_sum, k, 0);
}

int main(void) {
  // * testcase 1
  // int k = 4;
  // std::vector<int> nums = {4, 3, 2, 3, 5, 2, 1};

  // * testcase 2
  // int k = 3;
  // std::vector<int> nums = {1, 2, 3, 4};

  // * testcase 3
  // int k = 3;
  // std::vector<int> nums = {1, 1, 2, 2, 2};

  // * testcase 4
  int k = 4;
  std::vector<int> nums = {2, 2, 2, 2, 3, 4, 5};

  std::cout << "Input nums: ";
  printArr(nums);

  bool ans = canPartitionKSubsets(nums, k);
  std::cout << "Can partition: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 20-partition-to-k-eq-sum-subsets.cpp -o output && ./output