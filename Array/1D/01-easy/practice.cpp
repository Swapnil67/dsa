#include <map>
#include <stack>
#include <vector>
#include <climits>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

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

// * 01 - Check if Array Is Sorted and Rotated
// bool checkSortedAndRotated(std::vector<int>& nums) {
// TODO
// }

// * 02 - Merge 2 Sorted Array
// std::vector<int> mergeTwoArrays(std::vector<int> a, std::vector<int> b) {
// TODO
// }

// * 03 - Missing Number
// int missingNumber(std::vector<int> &nums) {
// TODO
// }

// * 04 - Max Consecutive Ones
// int maxConsecutiveOnes(std::vector<int> &arr) {
// TODO
// }

// * 05 - Single Number
// int singleNumber(std::vector<int> &nums) {
// TODO
// }

// * 06 - Subarray Sum Equals K
// int subarraySum(std::vector<int>& arr, int k) {
// TODO
// }

// * 07 - Two Sum
// std::vector<int> twoSum(std::vector<int> &arr, int target) {
// TODO
// }

// * 08 - Contains Duplicate
// bool containsDuplicate(std::vector<int>& nums) {
// TODO
// }

// * 09 - Can Place Flowers
// bool canPlaceFlowers(std::vector<int>& flowerbed, int newPlots) {
// TODO
// }

// * 10 - Replace Elements with Greatest Element on Right Side
// std::vector<int> replaceElements(std::vector<int> &arr) {
// TODO
// }

// * 11 - Find Pivot Index
// int pivotIndex(std::vector<int>& nums) {
// TODO
// }

// * 12 - Find All Numbers Disappeared in an Array
// std::vector<int> findDisappearedNumbers(std::vector<int> &arr) {
// TODO
// }

// * 13 - Range Sum Query - Immutable
// class NumArray {
//   public:
//     std::vector<int> prefix_vec;
//     NumArray(std::vector<int> &nums) {
      // TODO
//     }

//     int sumRange(int left, int right) {
      // TODO
//     }
// };

// * 14 - Monotonic Array 
// bool isMonotonic(std::vector<int> arr) {
// TODO
// }

// * 15 - Number of Good Pairs
// int numIdenticalPairs(std::vector<int> &arr) {
// TODO
// }

// * 16 - Maximum Product Difference Between Two Pairs
// int maxProductDifference (std::vector<int> &arr) {
// TODO  
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o output && ./output
