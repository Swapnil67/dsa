/*
 * Leetcode = 977
 * Squares of a Sorted Array
 * 
 * Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number 
 * sorted in non-decreasing order.
 * 
 * 
 * Example: 1
 * Input: nums = [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * 
 * Example: 2
 * Input: nums = [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 * 
 * https://leetcode.com/problems/squares-of-a-sorted-array/description/
 */

#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
std::vector<int> sortedSquares(std::vector<int>& nums) {
  int n = nums.size();
  int i = 0, j = n - 1;
  int k = n - 1;
  std::vector<int> ans(n);
  while (i <= j) {
    int sqr1 = nums[i] * nums[i];
    int sqr2 = nums[j] * nums[j];
    if (sqr1 > sqr2) {
      ans[k] = sqr1;
      i++;
    } else {
      ans[k] = sqr2;
      j--;
    }
    k--;
  }

  return ans;
}

int main(void) {
  // std::vector<int> nums = {-4, -1, 0, 3, 10};
  std::vector<int> nums = {-7, -3, 2, 3, 11};
  printArr(nums);
  
  std::vector<int> ans = sortedSquares(nums);
  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++20 15-sqr-of-sorted-arr.cpp -o output && ./output

