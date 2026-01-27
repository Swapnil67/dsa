/*
 * Minimum Difference Between Highest and Lowest of K Scores
 * You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. 
 * You are also given an integer k.
 * 
 * Pick the scores of any k students from the array so that the difference between the highest and the lowest of
 * the k scores is minimized.
 * Return the minimum possible difference.
 * 
 * Example 1
 * Input  : nums = [90], k = 1
 * Output : 0
 * 
 * Example 2
 * Input  : nums = [9,4,1,7], k = 2
 * Output : 2

 * https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/
*/

#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int minimumDifference(std::vector<int> arr, int k) {
  int n = arr.size();
  std::sort(arr.begin(), arr.end());

  int l = 0, r = k - 1;
  int res = INT_MAX;
  while (r < n) {
    res = std::min(res, arr[r] - arr[l]);
    l += 1;
    r += 1;
  }

  return res;
}


int main() {
  int k = 3;
  // int k = 2;
  std::vector<int> nums = {9, 4, 1, 7};
  printArr(nums);
  int ans = minimumDifference(nums, k);
  std::cout << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 29-min-dff-bw-high-and-low-k.cpp -o output && ./output