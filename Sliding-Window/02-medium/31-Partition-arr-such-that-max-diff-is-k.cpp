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

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * Classic Sliding Window
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1)
int partitionArray(std::vector<int> &nums, int k) {
  int n = nums.size();

  // * sort the input array
  std::sort(nums.begin(), nums.end());

  int j = 0, ans = 1;
  int cur_min = nums[0]; // * start the current subseq with first ele
  while (j < n) {

    // * start new subseq here since the diff b/w largest - smallest > k 
    if (nums[j] - cur_min > k) {
      ans++;
      cur_min = nums[j];
    }

    j++;
  }
  return ans;
}

int main(void) {
  // * testcase 1 (ans = 2)
  // int k = 2;
  // std::vector<int> nums = {3, 6, 1, 2, 5};

  // * testcase 2 (ans = 2)
  // int k = 1;
  // std::vector<int> nums = {1,2,3};

  // * testcase 3 (ans = 3)
  int k = 0;
  std::vector<int> nums = {2, 2, 4, 5};

  std::cout << "k = " << k << std::endl;
  std::cout << "Input Array" << std::endl;
  printArr(nums);
  
  int ans = partitionArray(nums, k);
  std::cout << "Count: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 31-Partition-arr-such-that-max-diff-is-k.cpp -o output && ./output 