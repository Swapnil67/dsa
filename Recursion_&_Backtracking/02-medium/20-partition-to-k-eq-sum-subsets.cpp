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
 * https://neetcode.io/problems/partition-to-k-equal-sum-subsets
*/

// ! Amazon, Google, Meta, Microsoft, LinkedIn

#include <vector>
#include <numeric>
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

vector<bool> used;
int target;
bool dfs(int start, int k, int cur_sum, vector<int>& nums) {
  if (k == 0)
      return true;

  if (cur_sum == target)
      return dfs(0, k - 1, 0, nums);

  for (int i = start; i < nums.size(); ++i) {
      if (used[i] || cur_sum + nums[i] > target)
          continue;

      used[i] = true;

      if (dfs(i + 1, k, cur_sum + nums[i], nums))
          return true;

      used[i] = false;

      if (cur_sum == 0) 
          return false;
  }

  return false;
}


// * ------------------------- Approach: Optimal Approach -------------------------
// * - 'k' is number of subsets
// * TIME COMPLEXITY O(2^n * k)
// * SPACE COMPLEXITY O(n)
bool canPartitionKSubsets(vector<int>& nums, int k) {
  int sum = accumulate(begin(nums), end(nums), 0);
  if (sum % k != 0)
    return false;

  used.assign(nums.size(), false);

  target = sum / k;
  cout << "target: " << target << endl;

  return dfs(0, k, 0, nums);
}

int main(void) {
  // * testcase 1
  int k = 4;
  vector<int> nums = {4, 3, 2, 3, 5, 2, 1};

  // * testcase 2
  // int k = 3;
  // vector<int> nums = {1, 2, 3, 4};

  // * testcase 3
  // int k = 3;
  // vector<int> nums = {1, 1, 2, 2, 2};

  // * testcase 4
  // int k = 4;
  // vector<int> nums = {2, 2, 2, 2, 3, 4, 5};

  cout << "Input nums: ";
  printArr(nums);

  bool ans = canPartitionKSubsets(nums, k);
  cout << "Can partition: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 20-partition-to-k-eq-sum-subsets.cpp -o output && ./output