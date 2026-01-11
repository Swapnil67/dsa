/*
 * Leetcode - 905
 * Sort Array By Parity 
 * Given an integer array nums, move all the even integers at the beginning of the array followed 
 * by all the odd integers.
 * Return any array that satisfies this condition.

 * Example 1
 * Input  : nums = [3,1,2,4]
 * Output : [2,4,3,1]
 * 
 * Example 2
 * Input  : nums = [0]
 * Output : [0]

 * https://leetcode.com/problems/sort-array-by-parity/description/
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
// * SPACE COMPLEXITY O(1)
std::vector<int> sortArrayByParity(std::vector<int> nums) {
  int n = nums.size();
  std::vector<int> ans(nums.begin(), nums.end());
  int i = 0, j = 0;

  while (j < n) {
    if (nums[j] % 2 == 0) {
      swap(ans[i], ans[j]);
      i++;
    }
    j++;
  }
  return ans;

}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
static bool comparator(int &a, int &b) {
  return a % 2 < b % 2;
}
// * using built in sort function
// * TIME COMPLEXITY (N)
// * SPACE COMPLEXITY O(1)
std::vector<int> sortArrayByParity2(std::vector<int> nums) {
  std::sort(nums.begin(), nums.end(), comparator);
  return nums;
}

int main() {
  // * testcase 1
  std::vector<int> arr = {3, 1, 2, 4};

  // * testcase 2
  // std::vector<int> arr = {0, 1, 2};

  std::cout << "Before Sorting" << std::endl;
  printArr(arr);
  
  // std::vector<int> ans = bruteForce(arr);
  std::vector<int> ans = sortArrayByParity(arr);
  // std::vector<int> ans = sortArrayByParity2(arr);

  std::cout << "After Sorting" << std::endl;
  printArr(ans);
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 06-sort-by-parity.cpp -o output && ./output