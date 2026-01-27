/*
* Longest Subarray with Sum K
*
* Given an array arr[] containing integers and an integer k, your task is to find the length of the 
* longest subarray where the sum of its elements is equal to the given value k. 
*
* If there is no subarray with sum equal to k, return 0.
*
* Example 1 
* Input       : nums = [1, 2, 3, 1, 1, 1, 1, 4, 2, 3], k = 3
* Output      : 3
* Explanation : Subarrays with sum = 3 are [1, 2], [3] and [1,1,1]. 
*               The length of the longest subarray with a sum of 3 is 3.
*
* Example 1 
* Input       : nums = [10, 5, 2, 7, 1, -10], k = 15
* Output      : 6
* Explanation : Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. 
*               The length of the longest subarray with a sum of 15 is 6.
*
* Example 2 
* Input       : nums =  [-5, 8, -14, 2, 4, 12], k = -5
* Output      : 5
* Explanation : Only subarray with sum = -5 is [-5, 8, -14, 2, 4] of length 5.
*
* Example 3
* Input       : nums =  [10, -10, 20, 30], k = 5
* Output      : 0
* Explanation : No subarray with sum = 5 is present in nums


* https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/description/
* https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
* https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_10870953
* https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399
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


// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^3)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> &nums, int k) {
  int n = nums.size();
  int max_len = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int cur_sum = 0;
      for (int k = i; k <= j; ++k) {
        cur_sum += nums[k];
      }
      // std::cout << cur_sum << " ";
      if (cur_sum == k) {
        max_len = std::max(max_len, (j - i + 1));
      }
    }
    // std::cout << std::endl;
  }
  return max_len;
}

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// ! This is optimal for +ve & -ve
// * Prefix Sum HashMap
// * TIME COMPLEXITY 
// *   Ordered Map    - O(nlogn) - (No Collisions)
// *   UnOrdered Map  - O(n^2)   - (Collisions)
// * SPACE COMPLEXITY O(n)
int betterApproach(std::vector<int> &nums, int &k) {
  int n = nums.size();
  
  // * {sum, index} Map
  std::unordered_map<long long, int> prefix_mp;
  
  int max_len = 0;
  long long cur_sum = 0;
  for (int j = 0; j < n; ++j) {
    cur_sum += (nums[j] * 1ll);

    if (cur_sum == k) {
      max_len = std::max(max_len, j + 1);
    }

    // * check if (x - k) exists in map
    int rem_sum = cur_sum - k;
    if (prefix_mp.count(rem_sum)) {
      max_len = std::max(max_len, j - prefix_mp[rem_sum]);
    }

    // * Only update sub array if it does not exists previously 
    // * becoz we need left most possible index for longest subarray
    if (!prefix_mp.count(cur_sum))
      prefix_mp[cur_sum] = j;
  }

  return max_len;
}

// * ------------------------- APPROACH 3: Optimal Approach -------------------------`
// ! This is optimal for +ve & 0s
// * Two Pointer + Sliding Window
// * TIME COMPLEXITY  O(n)
// * SPACE COMPLEXITY O(1)
int longestSubarray(std::vector<int> &nums, int &k) {
  int n = nums.size();
  int max_len = 0;
  long long sum = 0;
  int i = 0, j = 0;

  while (j < n) {
    sum += nums[j];
    while (i <= j && sum > k) {
      sum -= nums[i];
      i++;
    }
    // std::cout << sum << std::endl;
    
    if (sum == k) {
      max_len = std::max(max_len, (j - i + 1));
    }

    j++;
  }

  return max_len;
}


int main(void) {

  // * testcase 1
  // int k = 3;
  // std::vector<int> nums = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};

  // * testcase 2 // * (Will work in betterApproach)
  // int k = 15;
  // std::vector<int> nums = {10, 5, 2, 7, 1, -10};

  // * testcase 3 // * (Will work in betterApproach)
  int k = -5;
  std::vector<int> nums = {-5, 8, -14, 2, 4, 12};

  std::cout << "Nums: ";
  printArr(nums);
  
  // int ans = bruteForce(nums, k);
  int ans = betterApproach(nums, k);
  // int ans = longestSubarray(nums, k);
  std::cout << "Ans: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 34-max-size-subarray-sum-equals-k.cpp -o output && ./output
