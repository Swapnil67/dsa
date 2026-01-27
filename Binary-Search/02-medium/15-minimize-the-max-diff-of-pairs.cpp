/*
  * Leetcode - 2616
  * Minimize the Maximum Difference of Pairs
  * 
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

// ! Meta, Microsoft

// ! Binary Search on Answers

#include <vector>
#include <iostream>
#include <algorithm>

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

// * A function to check abs difference of how many pairs is '<=' max_pair_diff
// * returns `true` if we found no. of pairs greater than `required_pairs`
bool isValid(std::vector<int> &nums, int required_pairs, int max_pair_diff) {
  int n = nums.size();
  int cur_pairs = 0;

  for (int i = 0; i < n - 1; ++i) {
    if (cur_pairs >= required_pairs)
      return true;

    // * current pair difference
    int cur_diff = nums[i + 1] - nums[i];
    if (cur_diff <= max_pair_diff) {
      cur_pairs++;  
      i++;          // * Go to next pair
    }
  }

  // std::cout << cur_pairs << " " << required_pairs << std::endl;
  return cur_pairs >= required_pairs;
}

// * ------------------------- APPROACH : Optimal APPROACH -------------------------
// * We need to check if we can find 'p' no. of pairs with difference <= max_pair_diff using binary search
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
      r = m - 1;                // * since we need minimum difference
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

  std::cout << "P: " << p << std::endl;
  std::cout << "Input Nums: ";
  printArr(nums);

  int ans = minimizeMax(nums, p);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 15-minimize-the-max-diff-of-pairs.cpp -o output && ./output

