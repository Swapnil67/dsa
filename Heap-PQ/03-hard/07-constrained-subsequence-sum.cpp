/*
 * Leetcode - 1425
 * Constrained Subsequence Sum
 * 
 * Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that
 * for every two consecutive integers in the subsequence, nums[i] and nums[j], 
 * where i < j, the condition j - i <= k is satisfied.

 * A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, 
 * leaving the remaining elements in their original order.

 * Example 1
 * input       : nums = [10,2,-10,5,20], k = 2
 * output      : 37
 * Explanation: The subsequence is [10, 2, 5, 20].

 * Example 2
 * input       : nums = [-1,-2,-3], k = 1
 * output      : -1
 * Explanation: The subsequence must be non-empty, so we choose the largest number.

 * Example 3
 * input       : nums = [10,-2,-10,-5,20], k = 2
 * output      : 23
 * Explanation: The subsequence is [10, -2, -5, 20].

 * https://leetcode.com/problems/constrained-subsequence-sum/description/
*/

// ! Google

#include <queue>
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

// * DP
// int bruteForce(std::vector<int>& nums, int k) {
// TODO
// }

// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * Max Heap
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(n)
int constrainedSubsetSum(std::vector<int>& nums, int k) {
  int res = nums[0];
  std::priority_queue<std::pair<int, int>> max_heap;
  max_heap.emplace(nums[0], 0);

  for (int i = 1; i < nums.size(); ++i) {
    // * If diff b/w index is greater than k then pop the element
    while (!max_heap.empty() && i - max_heap.top().second > k) {
      max_heap.pop();
    }

    int cur_max = std::max(nums[i], nums[i] + max_heap.top().first);
    std::cout << cur_max << std::endl;
    max_heap.emplace(cur_max, i);
    res = std::max(res, cur_max);
  }

  return res;
}

int main(void) {
  // * testcase 1
  // int k = 2;
  // std::vector<int> nums = {10, 2, -10, 5, 20};

  // * testcase 2
  int k = 1;
  std::vector<int> nums = {-1, -2, -3};

  // * testcase 3
  // int k = 2;
  // std::vector<int> nums = {10, -2, -10, -5, 20};

  std::cout << "k: " << k << std::endl;
  std::cout << "Nums: ";
  printArr(nums);

  // int ans = bruteForce(nums, k);
  int ans = constrainedSubsetSum(nums, k);
  std::cout << "Constrained Subsequence Sum " << ans << std::endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 07-constrained-subsequence-sum.cpp -o output && ./output