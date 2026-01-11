/*
 * Leetcode - 922
 * Sort Array By Parity II
 * 
 * Given an array of integers nums, half of the integers in nums are odd, and the other half are even.
 * Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.
 * Return any answer array that satisfies this condition.

 * Example 1
 * Input        : nums = [4,2,5,7]
 * Output       : [4,5,2,7]
 * Explanation  : [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

 * Example 1
 * Input        : nums = [2,3]
 * Output       : [2,3]

 * https://leetcode.com/problems/sort-array-by-parity-ii/description/
*/

// ! Amazon, Meta, Google, MIcrosoft, Apple

#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
void printArr(std::vector<T> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void swap(int &a, int &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

// * ------------------------- APPROACH 1: Brute Force Approach -------------------------`
// * TIME COMPLEXITY (N)
// * SPACE COMPLEXITY O(N)
std::vector<int> bruteForce(std::vector<int> &arr) {
  int n = arr.size();
  int l = 0, r = n - 1;
  std::vector<int> ans(n);
  for(int i = 0; i < n; ++i) {
    if (arr[i] % 2 == 0) {
      ans[l] = arr[i];
      l++;
    } else {
      ans[r] = arr[i];
      r--;
    }
  }

  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * TIME COMPLEXITY (N)
// * SPACE COMPLEXITY O(N)
std::vector<int> sortArrayByParity(std::vector<int> nums) {
  int even_idx = 0, odd_idx = 1;
  int n = nums.size();
  std::vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if (nums[i] % 2 == 0) {
      ans[even_idx] = nums[i];
      even_idx += 2;
    }
    else {
      ans[odd_idx] = nums[i];
      odd_idx += 2;
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * TIME COMPLEXITY (N)
// * SPACE COMPLEXITY O(1)
std::vector<int> sortArrayByParityII(std::vector<int> &nums) {
  int n = nums.size();
  int even = 0, odd = 1;
  while (even < n && odd < n) {
    while (even < n && nums[even] % 2 == 0) {
      even += 2;
    }
    while (odd < n && nums[odd] % 2 == 1) {
      odd += 2;
    }
    if (even < n && odd < n)
      std::swap(nums[even], nums[odd]);
  }
  return nums;
}

int main() {
  // * testcase 1
  // std::vector<int> arr = {3, 1, 2, 4};

  // * testcase 2
  // std::vector<int> arr = {4, 2, 5, 7};

  // * testcase 3
  std::vector<int> arr = {4, 2, 5, 7};

  std::cout << "Before Sorting" << std::endl;
  printArr(arr);
  
  // std::vector<int> ans = bruteForce(arr);
  std::vector<int> ans = sortArrayByParityII(arr);

  std::cout << "After Sorting" << std::endl;
  printArr(ans);
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 17-sort-by-parity-II.cpp -o output && ./output