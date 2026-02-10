/*
 * Leetcode - ?
 * Missing Element in Sorted Array
 * 
 * Given an integer array nums which is sorted in ascending order and all of its elements are unique and given also an
 * integer k, return the kᵗʰ missing number starting from the leftmost number of the array.
 * 
 * Example 1    :
 * Input        : nums = [4,7,9,10], k = 1
 * Output       : 5
 * Explanation  : The first missing number is 5.
 * 
 * Example 2    :
 * Input        : nums = [4,7,9,10], k = 3
 * Output       : 8
 * Explanation  : The missing numbers are [5,6,8,...], hence the third missing number is 8.
 * 
 * Example 3    :
 * Input        : nums = [1,2,4], k = 3
 * Output       : 6
 * Explanation  : The missing numbers are [3,5,6,7,...], hence the third missing number is 6.
 * 
 * https://neetcode.io/problems/missing-element-in-sorted-array/question
*/

// ! Amazon, Meta, Google

#include <vector>
#include <iostream>

using namespace std;

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
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> &nums, int k) {
  int n = nums.size();
  for (int i = 1; i < n; ++i) {
    int gap = (nums[i] - nums[i - 1]) - 1;
    if (gap >= k) {
      return nums[i - 1] + k;
    }
    k -= gap;
  }
  return nums[n - 1] + k;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(log(n))
// * SPACE COMPLEXITY O(1)
int missingElement(vector<int> &nums, int k) {
  int n = nums.size();
  int l = 0, r = n - 1;
  int idx = 0;
  while (l <= r) {
    int m = l + (r - l) / 2;
    // cout << m << endl;
    // * Compute the number of missing elements up to index 'm'
    if ((nums[m] - nums[0] - m) < k) {
      idx = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return nums[0] + k + idx;
}

int main(void) {
  // * testcase 1
  // int k = 1;
  // std::vector<int> nums = {4, 7, 9, 10};

  // * testcase 2
  // int k = 3;
  // std::vector<int> nums = {4, 7, 9, 10};

  // * testcase 3
  int k = 3;
  std::vector<int> nums = {1, 2, 4};

  int missing = bruteForce(nums, k);
  std::cout << "Missing Element: " << missing << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 32-missing-element-in-sorted-array.cpp -o output && ./output
