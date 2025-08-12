/*
  * Leetcode - 2616
  * Minimize the Maximum Difference of Pairs
  * You are given a 0-indexed integer array nums and an integer p.
  * Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized.
  * Also, ensure no index appears more than once amongst the p pairs.
  *
  * Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

  * Example 1:
  * Input: nums = [10,1,2,7,1,3], p = 2
  * Output: 1
  * Explanation: max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
  
  * Example 2:
  * Input: nums = [4,2,1,2], p = 1
  * Output: 0
  * Explanation: |nums[1] - nums[3]| = 0. Therefore, we return 0.
  *
  * https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * A function to check abs difference of how many pairs is '<=' pairDiff
// * return true if we found no. of pairs greater than maxPairs
bool isValid(std::vector<int> &nums, int maxPairs, int pairDiff) {
  int n = nums.size();
  int curPairs = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (curPairs >= maxPairs)
      return true;

    // * current pair difference
    int curDiff = nums[i + 1] - nums[i];
    if (curDiff <= pairDiff) {
      curPairs++;  
      i++;          // * Go to next pair
    }
  }

  // std::cout << curPairs << " " << maxPairs << std::endl;
  return curPairs >= maxPairs;
}

// * ------------------------- APPROACH : Optimal APPROACH -------------------------
// * We need to check if we can find 'p' no. of pairs with difference <= minDiff using binary search
// * TIME COMPLEXITY n * O(logm)
// * SPACE COMPLEXITY O(1)
int minimizeMax(std::vector<int> &nums, int p) {
  int n = nums.size();
  
  // * sort the nums to get min diff b/w pairs
  std::sort(nums.begin(), nums.end());
  int l = 0, r = nums[n - 1] - nums[0];

  int ans = 0;
  while (l <= r) {           // * O(logm) 'm' = nums[n - 1] - nums[0]
    int m = l + (r - l) / 2;    // * Assume this is min pair distance
    if (isValid(nums, p, m)) {   // * O(N)
      ans = m;
      r = m - 1;                // * since we want to minimize the diff
    } else {
      l = m + 1;
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  int p = 2;
  std::vector<int> nums = {10, 1, 2, 7, 1, 3};
  
  // * testcase 2
  // int p = 1;
  // std::vector<int> nums = {4, 2, 1, 2};

  printArr(nums);

  int ans = minimizeMax(nums, p);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 15-minimize-the-max-diff-of-pairs.cpp -o output && ./output

