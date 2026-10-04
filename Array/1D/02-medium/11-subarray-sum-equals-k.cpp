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

// ! Amazon, Google, Meta, Microsoft, Apple, Oracle, Tiktok, IBM, Paypal

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> &nums, int k) {
  int n = nums.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cur_sum = 0;
    for (int j = i; j < n; ++j) {
      cur_sum += nums[j];
      if (cur_sum == k)
        ans += 1;
    }
  }
  return ans;
}

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * Using Prefix Sum Map
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int subarraySum(vector<int> &nums, int k) {
  int n = nums.size();
  int sum = 0, cnt = 0;

  unordered_map<int, int> prefix_sum_map;
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
  int k = 2;
  vector<int> nums = {1, 1, 1};

  // * testcase 2
  // int k = 3;
  // vector<int> nums = {1, 2, 3};

  // * testcase 3
  // int k = 0;
  // vector<int> nums = {1};

  // * testcase  4
  // int k = 0;
  // vector<int> nums = {-1, -1, 1};

  cout << "K: " << k << endl;
  cout << "Nums: ";
  printArr(nums);

  int ans = bruteForce(nums, k);
  // int ans = subarraySum(nums, k);
  cout << "Total number of subarrays whose sum equals to k: " << ans << endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 11-subarray-sum-equals-k.cpp -o output && ./output
