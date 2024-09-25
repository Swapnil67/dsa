/*
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

#include<iostream>

template <typename T>
void printArr(std::vector<T> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

// * TIME COMPLEXITY (N)
// * SPACE COMPLEXITY O(1)
std::vector<int> sortArrayByParity(std::vector<int> nums) {
  int n = nums.size();
  std::vector<int> ans(nums.begin(), nums.end());
  int i = 0, j = 0;

  if (n == 1)
    return ans;

  while (j < n) {
    if (nums[j] % 2 == 0) {
      swap(ans[i], ans[j]);
      i++;
    }
    j++;
  }
  return ans;
}

int main() {
  // std::vector<int> arr = {3, 1, 2, 4};
  std::vector<int> arr = {0, 1, 2};
  printArr(arr);
  std::vector<int> ans = sortArrayByParity(arr);
  printArr(ans);
}

// * Run the code
// * g++ --std=c++17 06-sort-by-parity.cpp -o output && ./output