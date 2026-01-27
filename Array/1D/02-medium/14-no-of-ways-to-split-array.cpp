/*
 * Leetcode - 2270
 * Number of Ways to Split Array
 * 
 * You are given a 0-indexed integer array nums of length n.
 * 
 * nums contains a valid split at index 'i' if the following are true:
 * - The sum of the first 'i + 1' elements is greater than or equal to the sum of the last n - i - 1 elements.
 * - There is at least one element to the right of i. That is, 0 <= i < n - 1.
 * 
 * Return the number of valid splits in nums.
 *
 * Example 1:
 * Input: nums = [10,4,-8,7]
 * Output: 2
 * 
 * Example 2:
 * Input: nums = [2,3,1,0]
 * Output: 2
 *
 * https://www.naukri.com/code360/problems/subarray-with-maximum-product_6890008
 * https://leetcode.com/problems/maximum-product-subarray/description/
*/

// ! Google, Amazon

#include <vector>
#include <iostream>

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

// * ------------------------- APPROACH 1: Brute Force -------------------------
// * Prefix Sum Array
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
int bruteForce(std::vector<int> &nums) {
  int n = nums.size();

  // * Calculate the prefix sum array
  std::vector<long long> prefix(n, 0);
  prefix[0] = nums[0];
  for (int i = 1; i < n; ++i) {
    prefix[i] = prefix[i - 1] + nums[i];
  }

  // * Find valid splits
  int valid_splits = 0;
  for (int i = 0; i < n - 1; ++i) {
    long long left_subarray_sum = prefix[i];
    long long right_subarray_sum = prefix[n - 1] - prefix[i];
    // std::cout << "left: " << left_subarray_sum << ", right: " << right_subarray_sum << std::endl;
    if (left_subarray_sum >= right_subarray_sum) {
      valid_splits += 1;
    }
  }

  return valid_splits;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * Prefix Sum Variable
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int waysToSplitArray(std::vector<int> &nums) {
  int n = nums.size();
  // * Find the total sum
  long long total_sum = 0;
  for (int &num : nums) {
    total_sum += num;
  }

  int valid_splits = 0;
  long long left_sum = 0;
  long long right_sum = 0;

  for (int i = 0; i < n - 1; ++i) {
    left_sum += nums[i];
    right_sum = total_sum - left_sum;
    if (left_sum >= right_sum)
      valid_splits += 1;
  }

  return valid_splits;
}

int main() {
  // * testcase 1
  std::vector<int> arr = {10, 4, -8, 7};

  // * testcase 2
  // std::vector<int> arr = {2, 3, 1, 0};

  std::cout << "Input Array: ";
  printArr(arr);
  
  // int maxProduct = bruteForce(arr);
  int ans = waysToSplitArray(arr);
  std::cout << "Number of Ways to Split Array: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 14-no-of-ways-to-split-array.cpp -o output && ./output
