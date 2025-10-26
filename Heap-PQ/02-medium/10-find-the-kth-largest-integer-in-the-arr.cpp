/*
 * Leetcode - 1985
 * Find the Kth Largest Integer in the Array
 * 
 * You are given an array of strings nums and an integer k. 
 * Each string in nums represents an integer without leading zeros.
 
 * Return the string that represents the kth largest integer in nums.

 * Example 1
 * input  : nums = ["3","6","7","10"], k = 4
 * output : "3"

 * Example 2
 * input  : nums = ["2","21","12","1"], k = 3
 * output : "2"
 * 
 * https://leetcode.com/problems/process-tasks-using-servers/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

std::string kthLargestNumber(std::vector<std::string>& nums, int k) {
  int n = nums.size();
  std::sort(begin(nums), end(nums), [](const auto &a, const auto &b)
            { 
    if(a.length() == b.length()) {
      return a < b;
    }
    return a.length() < b.length(); });

  // printArr(nums);
  return nums[n - k];
}

int main(void) {
  // * testcase 1
  int k = 4;
  std::vector<std::string> nums = {"3", "6", "7", "10"};

  // * testcase 2
  // int k = 3;
  // std::vector<std::string> nums = {"2", "21", "12", "1"};

  std::cout << "K: " << k << std::endl;
  std::cout << "nums: ";
  printArr(nums);
  
  std::string ans = kthLargestNumber(nums, k);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 10-find-the-kth-largest-integer-in-the-arr.cpp -o output && ./output