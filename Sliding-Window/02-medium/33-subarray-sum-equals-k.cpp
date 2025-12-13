/*
* Leetcode - 560
* Subarray Sum Equals K

* Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

* A subarray is a contiguous non-empty sequence of elements within an array.

* Example 1 
* Input   : nums = [1,1,1], k = 2
* Output  : 2

* Example 2
* Input   : nums = [1,2,3], k = 3
* Output  : 2

* https://leetcode.com/problems/subarray-sum-equals-k/description/
* https://www.naukri.com/code360/problems/subarray-sums-i_1467103
*/

#include <vector>
#include <iostream>
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

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * Using Prefix Sum Map
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int subarraySum(std::vector<int> &nums, int k) {
  int n = nums.size();
  int sum = 0, cnt = 0;

  std::unordered_map<int, int> prefix_sum_map;
  prefix_sum_map[0] = 1;

  for (int i = 0; i < n; ++i) {
    sum += nums[i];
    int rem = sum - k;
    cnt += prefix_sum_map[rem];
    prefix_sum_map[sum]++;
  }

  return cnt;
}

int main(void) {

  // * testcase 1
  // int k = 2;
  // std::vector<int> nums = {1, 1, 1};

  // * testcase 2
  // int k = 3;
  // std::vector<int> nums = {1, 2, 3};

  // * testcase 3
  // int k = 0;
  // std::vector<int> nums = {1};

  // * testcase  4
  int k = 0;
  std::vector<int> nums = {-1, -1, 1};


  std::cout << "K: " << k << std::endl;
  std::cout << "Nums: ";
  printArr(nums);

  int ans = subarraySum(nums, k);
  std::cout << "Total number of subarrays whose sum equals to k: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 33-subarray-sum-equals-k.cpp -o output && ./output
