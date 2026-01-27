/*
 * Leetcode - 2294
 * Partition Array Such That Maximum Difference Is K
 * 
 * You are given an integer array nums and an integer k. You may partition nums into one or more subsequences such that 
 * each element in nums appears in exactly one of the subsequences.
 * 
 * Return the minimum number of subsequences needed such that the difference between the maximum and minimum values
 * in each subsequence is at most k.
 * 
 * Example 1
 * * Input  : nums = [3,6,1,2,5], k = 2
 * * Output : 2

 * Example 2
 * * Input  : nums = [1,2,3], k = 1
 * * Output : 2
 * 

 * Example 2
 * * Input  : [2,2,4,5], k = 0
 * * Output : 3
 * 
 * https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/
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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
long long bruteForce(std::vector<int> &nums, int minK, int maxK) {
  int n = nums.size();
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int cur_min = nums[i], cur_max = nums[i];
    for (int j = i; j < n; ++j) {
      cur_min = std::min(cur_min, nums[j]);
      cur_max = std::max(cur_max, nums[j]);
      // std::cout << cur_min << " " << cur_max << " " << std::endl;
      if (cur_min == minK && cur_max == maxK)
        ans++;
    }
  }

  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Find Index of minK & maxK & culprit_idx
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
long long countSubarrays(std::vector<int> &nums, int minK, int maxK) {
  int n = nums.size();

  long long ans = 0;
  int min_k_pos = -1, max_k_pos = -1, culprit_pos = -1;

  for (int i = 0; i < n; ++i) {
    if (nums[i] < minK || nums[i] > maxK) {
      culprit_pos = i;
    }

    if (nums[i] == minK) {
      min_k_pos = i;
    }

    if (nums[i] == maxK) {
      max_k_pos = i;
    }

    long long smaller = std::min(min_k_pos, max_k_pos);
    // std::cout << smaller << std::endl;
    long long temp = smaller - culprit_pos;
    ans += (temp <= 0 ? 0 : temp);
  }

  return ans;
}

int main(void) {
  // * testcase 1 (ans = 2)
  int minK = 1, maxK = 5;
  std::vector<int> nums = {1, 3, 5, 2, 7, 5};

  // * testcase 1 (ans = 2)
  // int minK = 1, maxK = 1;
  // std::vector<int> nums = {1, 1, 1, 1};

  std::cout << "minK = " << minK << ", maxK = " << maxK << std::endl;
  std::cout << "Input Array: ";
  printArr(nums);

  // long long ans = bruteForce(nums, minK, maxK);
  long long ans = countSubarrays(nums, minK, maxK);
  std::cout << "Count: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 07-cnt-subarr-with-fixed-bounds.cpp -o output && ./output 