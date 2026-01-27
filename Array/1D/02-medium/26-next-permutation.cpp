/*
 * Leetcode - 31
 * Next Permutation
 * 
 * 
 * https://leetcode.com/problems/next-permutation/description/
*/

// ! Google, Meta, Amazon, Microsoft, Uber, Flipkart

#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

int find_next_greater_at_right(std::vector<int> &nums, int idx) {
  int n = nums.size();
  for (int i = n - 1; i > idx + 1; --i) {
    if (nums[i] > nums[idx])
      return i;
  }
  return -1;
}

// * Generate all possible permutations
void bruteForce(std::vector<int> nums) {
}

// * C++ STL
void betterApproach(std::vector<int> nums) {
  std::next_permutation(begin(nums), end(nums));
}

void nextPermutation(std::vector<int> &nums) {
  int n = nums.size();

  int k = -1;

  // * Step 1. Find larget 'k' index such that nums[k] < nums[k - 1]
  for (int i = n - 1; i > 0; --i) {
    if (nums[i - 1] < nums[i]) {
      k = i - 1;
      break;
    }
  }

  // * Step 2. Find largest 'l' index such that nums[k] < nums[l] && k < l
  if (k != -1) {
    int l = -1;
    for (int i = n - 1; i > 0; --i) {
      if (nums[i] > nums[k]) {
        l = i;
        break;
      }
    }
    if (l != -1)
      std::swap(nums[l], nums[k]);
  }

  // * Step 3. Reverse from '(k + 1)' to 'n' index
  std::reverse(nums.begin() + k + 1, nums.end());
}

// *  0  1  2  3
// * [1, 2, 4, 3]
// * k = 1, l = 3

// * [1, 3, 4, 2]
// * [1, 3, 2, 4]


int main() {
  // * testcase 1
  // std::vector<int> nums = {1, 2, 3};
  
  // * testcase 2
  // std::vector<int> nums = {3, 2, 1};
  
  // * testcase 3
  // std::vector<int> nums = {1, 1, 5};
  
  // * testcase 4
  // std::vector<int> nums = {1, 3, 2};
  
  // * testcase 5
  std::vector<int> nums = {1, 2, 4, 3};

  std::cout<<"Input Array: ";
  printArr(nums);
  
  // std::vector<int> ans = betterApproach(nums);
  nextPermutation(nums);

  std::cout << "Next Permutation: ";
  printArr(nums);

  return 0;
}

// * Run the code
// * g++ --std=c++20 26-next-permutation.cpp -o output && ./output
