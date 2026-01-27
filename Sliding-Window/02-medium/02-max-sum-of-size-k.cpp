/*
 * leetcode - 2461
 * Maximum Sum of Distinct Subarrays With Length K
 * 
 * You are given an integer array nums and an integer k. Find the maximum subarray sum of all the 
 * subarrays of nums that meet the following conditions:
 *  - The length of the subarray is k, and
 *  - All the elements of the subarray are distinct.
 * 
 * Return the maximum subarray sum of all the subarrays that meet the conditions. 
 * If no subarray meets the conditions, return 0.
 * 
 * * Example 1
 * * Input  : nums = [1,5,4,2,9,9,9], k = 3
 * * Output : 15
 * * Explanation: The subarrays of nums with length 3 are:
 * * - [1,5,4] which meets the requirements and has a sum of 10.
 * * - [5,4,2] which meets the requirements and has a sum of 11.
 * * - [4,2,9] which meets the requirements and has a sum of 15.
 * * - [2,9,9] which does not meet the requirements because the element 9 is repeated.
 * * - [9,9,9] which does not meet the requirements because the element 9 is repeated.
 * * We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions

 * * Example 2
 * * Input  : nums = [4,4,4], k = 3
 * * Output : 0
 * * Explanation: The subarrays of nums with length 3 are:
 * * - [4,4,4] which does not meet the requirements because the element 4 is repeated.
 * * We return 0 because no subarrays meet the conditions.

 * * https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
 * https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
*/

// ! IBM, Nvidia, Meta, Google, Microsoft

#include<vector>
#include<iostream>
#include<unordered_set>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1A: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr, int k) {
  int n = arr.size();
  int ans = 0;
  for (int i = 0; i <= n - k; ++i) {
    int cur_sum = 0;
    std::unordered_set<int> st;
    for (int j = i; j < i + k; ++j) {
      if(st.count(arr[j])) {
        // * found duplicate
        cur_sum = 0;
        break;
      }
      cur_sum += arr[j];
      st.insert(arr[j]);
    }
    if(st.size() == k) {
      ans = std::max(ans, cur_sum);
    }
  }
  return ans;
}

// * 0, 1, 2, 3, 4, 5, 6
// * 1, 5, 4, 2, 9, 9, 9 
// * n - k = 7 - 3 = 4

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Classic Sliding Window with set
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int subarraySum(std::vector<int> nums, int window_size) {
  int n = nums.size();
  int i = 0, j = 0;
  long long max_sum = 0, cur_sum = 0;
  std::unordered_set<int> st;
  while (j < n) {
    // * Shrink window 
    // * on duplicate element or on set size >= window_size
    while (i < j && (st.count(nums[j]) || st.size() >= window_size)) {
      cur_sum -= nums[i];
      st.erase(nums[i]);
      i++;
    }

    // * Update cur_sum & set
    cur_sum += nums[j];
    st.insert(nums[j]);

    if (st.size() == window_size)
      max_sum = std::max(max_sum, cur_sum);
    
    j++;
  }

  return max_sum;
}

int main(void) {
  // * testcase 1
  int window_size = 3;
  std::vector<int> arr = {1, 5, 4, 2, 9, 9, 9};
  
  // * testcase 2
  // int window_size = 3;
  // std::vector<int> arr = {4, 4, 4};

  // * testcase 3
  // int window_size = 3;
  // std::vector<int> arr = {1, 1, 1, 7, 8, 9};
  std::cout << "Distinct Elements = " << window_size << std::endl;
  printArr(arr);

  // int ans= bruteForce(arr, window_size);
  int ans= subarraySum(arr, window_size);
  std::cout << "Maximum Sum of Distinct Subarrays With Length K: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 02-max-sum-of-size-k.cpp -o output && ./output
