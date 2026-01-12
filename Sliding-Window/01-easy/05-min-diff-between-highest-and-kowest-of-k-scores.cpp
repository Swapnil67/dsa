/*
 * Leetcode - 1984
 * Minimum Difference Between Highest and Lowest of K Scores
 * 
 * You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student.
 * You are also given an integer k.
 * 
 * Pick the scores of any k students from the array so that the difference between the highest and the 
 * lowest of the k scores is minimized.

 * Return the minimum possible difference.

 * Example 1:
 * Input: nums = [90], k = 1
 * Output: 0

 * 
 * Example 2:
 * Input: nums = [9,4,1,7], k = 2
 * Output: 2
 * Explanation: 
 *              -> 9 - 4 = 5
 *              -> 9 - 1 = 8
 *              -> 9 - 7 = 2
 *              -> 4 - 1 = 3
 *              -> 4 - 7 = 3
 *              -> 1 - 7 = 6

 * https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/
*/

// ! Amazon, Google, Bloomberg

#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int minimumDifference(std::vector<int> &nums, int k) {
  std::sort(nums.begin(), nums.end());
  int res = INT_MAX;
  int n = nums.size();
  int l = 0, r = k - 1;

  while (r < n) {
    res = std::min(res, (nums[r] - nums[l]));
    l += 1;
    r += 1;
  }

  return res;
}

int main(void) {
  // * testcase 1
  int k = 2;
  std::vector<int> nums = {9, 4, 1, 7};

  // * testcase 2
  // std::vector<int> nums = {7, 6, 4, 3, 1};

  std::cout << "Input nums" << std::endl;
  printArr(nums);

  int ans = minimumDifference(nums, k);
  std::cout << "ans: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 06-min-diff-between-highest-and-kowest-of-k-scores.cpp -o output && ./output