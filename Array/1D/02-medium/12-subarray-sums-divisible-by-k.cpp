/*
* Leetcode - 974
* Subarray Sums Divisible by K

* Given an integer array nums and an integer k, return the number of non-empty subarrays that 
* have a sum divisible by k.

* A subarray is a contiguous part of an array.

* Example 1 
* Input        : nums = [4,5,0,-2,-3,1], k = 5
* Output       : 7
* Explanation  : There are 7 subarrays with a sum divisible by k = 5:
*                [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]


* Example 2
* Input   : nums = [1,2,3], k = 3
* Output  : 2

* https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
* https://www.naukri.com/code360/problems/count-all-sub-arrays-having-sum-divisible-by-k_973254
* https://www.geeksforgeeks.org/problems/sub-array-sum-divisible-by-k2617/1
*/

// ! Microsoft, Paytm, Amazon, Adobe, Flipkart

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

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> &nums, int k) {
  int n = nums.size();
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    long long cur_sum = 0;
    for (int j = i; j < n; ++j) {
      cur_sum += (nums[j] * 1ll);
      if (cur_sum % k == 0)
        cnt++;
    }
  }

  return cnt;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using Prefix Sum + Hash Map
// * Suppose s1 % k = 0 & s2 % k = 0
// * therefore we can say following
// * s1 % k == s2 % k
// * (s1 - s2) % k = 0
// * ((s1 % k) - (s2 % k)) % k = 0
// * ((s1 % k) - (s1 % k)) % k = 0
// * 0 % k = 0
// * (s1 - s2) % k = 0 (Hence Proved)
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(k)
int subarraysDivByK(std::vector<int> &nums, int k) {
  int n = nums.size();
  
  // * {remainder, count} Map
  std::unordered_map<int, int> prefix_sum_map;
  prefix_sum_map[0] = 1;
  
  int sum = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    sum += nums[i];

    // * Get the remainder of sum
    int rem = sum % k;
    if (rem < 0)
      rem += k;

    cnt += prefix_sum_map[rem];
    prefix_sum_map[rem]++;  // * Add the remainder to map
  }

  return cnt;
}

int main(void) {
  // * testcase 1
  // int k = 5;
  // std::vector<int> nums = {4, 5, 0, -2, -3, 1};

  // * testcase 2
  // int k = 9;
  // std::vector<int> nums = {5};

  // * testcase 3
  int k = 7;
  std::vector<int> nums = {2, -6, 3, 1, 2, 8, 2, 1};

  // * testcase  4
  // int k = 0;
  // std::vector<int> nums = {-1, -1, 1};

  std::cout << (-5 % 6) << std::endl;

  std::cout << "K: " << k << std::endl;
  std::cout << "Nums: ";
  printArr(nums);

  // int ans = bruteForce(nums, k);
  int ans = subarraysDivByK(nums, k);
  std::cout << "Total number of subarrays whose sum divisible by k: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 12-subarray-sums-divisible-by-k.cpp -o output && ./output
