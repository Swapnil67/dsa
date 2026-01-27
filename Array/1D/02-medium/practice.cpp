#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>

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

// * 14 - Maximum Product Subarray
// int subarraysDivByK(std::vector<int> &nums, int k) {
// TODO
// }

// * ------------------------------------------------------------------------------------------

// * 01 - Average Waiting Time
// double averageWaitingTime(std::vector<std::vector<int>> &customers) {
// TODO
// }

// * 02 - Sort An Array of 0s, 1s and 2s
// void sortColors(std::vector<int> &nums) {
// TODO
// }

// * 03 - Maximum Subarray
// int maxSubArray(std::vector<int>& nums) {
// TODO
// }

// * 04 - Maximum Distance in Arrays
// int maxDistance(std::vector<std::vector<int>> &arr) {
// TODO
// }

// * 05 - Maximum Sum Circular Subarray
// int maxSubarraySumCircular(std::vector<int> &nums) {
// TODO
// }

// * 06 - Majority Element (N/3)
// std::vector<int> rearrangeArray(std::vector<int> &nums) {
// TODO 
// }

// * 07 - Rearrange Array Elements by Sign
// std::vector<int> rearrangeArray(std::vector<int> &nums) {
// TODO 
// }

// * 08 - Two Sum II - Input Array Is Sorted
// std::vector<int> twoSum(std::vector<int> nums, int target) {
// TODO 
// }

// * 09 - Minimum Index of a Valid Split
// int minimumIndex(std::vector<int> &nums) {
// TODO 
// }

// * 10 - Longest Successive Elements
// int findlongestConsecutive(std::vector<int> &arr) {
// TODO 
// }

// * 11 - Subarray Sum Equals K
// int subarraySum(std::vector<int> &nums, int k) {
// TODO
// }

// * 12 - Subarray Sums Divisible by K
// int subarraysDivByK(std::vector<int> &nums, int k) {
// TODO
// }

// * 13 - Make Sum Divisible by P
// int subarraysDivByK(std::vector<int> &nums, int k) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
