/*
 * Leetcode - 2401
 * Longest Nice Subarray
 * 
 * You are given an array nums consisting of positive integers.
 * 
 * We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in 
 * the subarray is equal to 0.
 * 
 * Return the length of the longest nice subarray.
 * 
 * A subarray is a contiguous part of an array.
 * 
 * Note that subarrays of length 1 are always considered nice.
 * 
 * Example 1    :
 * Input        : nums = [1,3,8,48,10]
 * Output       : 3
 * Explanation  : The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
 *                 - 3 AND 8 = 0.
 *                 - 3 AND 48 = 0.
 *                 - 8 AND 48 = 0.
 * 
 * Example 2    :
 * Input        : nums = [3,1,5,11,13]
 * Output       : 1
 * Explanation  : The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.
 * 
 * https://leetcode.com/problems/longest-nice-subarray/
*/

#include <vector>
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

// * ------------------------- APPROACH 1: Brute Force -------------------------
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int>& nums) {
  int n = nums.size();
  int max_len = 0;
  for (int i = 0; i < n; ++i) {
    int mask = 0;
    for (int j = i; j < n; ++j) {
      if ((mask & nums[j]) != 0) // * early exit
        break;

      max_len = max(max_len, (j - i + 1));
      mask |= nums[j]; // * only take '1' bits
    }
  }
  return max_len;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int longestNiceSubarray(vector<int>& nums) {
  int n = nums.size();
  int max_len = 0;
  int i = 0, j = 0, mask = 0;
  while (j < n) {
    while ((mask & nums[j]) != 0) {
      mask ^= nums[i]; // * removing '1' bits from mask
      i++;
    }
    mask |= nums[j]; // * only take '1' bits
    max_len = max(max_len, (j - i + 1));
    j++;
  }
  return max_len;
}

int main(void) {
  // * testcase 1
  vector<int> nums = {1, 3, 8, 48, 10};

  // * testcase 2
  // vector<int> nums = {3, 1, 5, 11, 13};

  std::cout << "Input Nums: ";
  printArr(nums);

  int len = bruteForce(nums);
  std::cout << "Longest Nice Subarray: " << len << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 33-longest-nice-subarray.cpp -o output && ./output
