/*
 * Continuous Subarray Sum
 * Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

 * A good subarray is a subarray where:
 * - its length is at least two, and
 * - the sum of the elements of the subarray is a multiple of k.
 * 
 * Example 1:
 * Input: nums = [23,2,4,6,7], k = 6
 * Output: true
 * Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
 * 
 * Example 2:
 * Input: nums = [23,2,6,4,7], k = 6
 * Output: true
 * Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
 *              42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
 * 
 * Example 3:
 * Input: [23,2,6,4,7], k = 13
 * Output: false

 * https://leetcode.com/problems/continuous-subarray-sum/description/
*/

#include<map>
#include<iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}


// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Nested Loop [Find all subarray]
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
bool bruteForce(std::vector<int> nums, int k) {
  int n = nums.size();
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = i; j < n; ++j) {
      sum += nums[j];
      if (sum % k == 0 && j - i > 1) {
        // std::cout << sum << std::endl;
        // std::cout << i << " " << j << std::endl;
        return true;
      }
    }
  }
  return false;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Hashmap of remainder
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
bool checkSubarraySum(std::vector<int>& nums, int k) {
  int n = nums.size();
  std::map<int, int> remainderMap;
  remainderMap[0] = -1;
  int prefixSum = 0;
  for (int i = 0; i < n; ++i) {
    prefixSum += nums[i];
    int rem = prefixSum % k;
    // std::cout << prefixSum << " " << rem << std::endl;
    // * don't overwrite if already exists 
    if(!remainderMap.count(rem)) {
      remainderMap[rem] = i;
    }
    else if (i - remainderMap[rem] > 1) {
      // * possible subarray  
      return true;
    }
  }
  return false;
}


int main() {
  // * testcase 1
  // std::vector<int> nums = {23, 2, 6, 4, 7};
  // int k = 13;

  // * testcase 2
  std::vector<int> nums = {5, 0, 0, 0};
  int k = 3;
  
  printArr(nums);
  // bool ans = bruteForce(nums, k);
  bool ans = checkSubarraySum(nums, k);
  std::cout << "good subarray " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 18-continuous-subarray-sum.cpp -o output && ./output