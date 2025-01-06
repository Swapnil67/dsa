/**
 * * Maximum Sum of Distinct Subarrays With Length K
 * * You are given an integer array nums and an integer k. Find the maximum subarray sum of all the 
 * * subarrays of nums that meet the following conditions:
 *  * The length of the subarray is k, and
 *  * All the elements of the subarray are distinct.
 * 
 * * Return the maximum subarray sum of all the subarrays that meet the conditions. 
 * * If no subarray meets the conditions, return 0.
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
*/

#include<set>
#include<vector>
#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int subarraySumBrute(std::vector<int> arr, int window_size) {
  int n = arr.size();
  long long max_sum = 0;
  for (int i = 0; i < n; ++i) {
    long long sum = 0, c = 0;
    std::set<int> st;
    for (int j = i; (i + window_size - 1 < n) && j < (i + window_size); ++j) {
      if(st.count(arr[j])) {
        break;
      }
      c++;
      sum += arr[j];
      st.insert(arr[j]);
      // std::cout << arr[j] << " ";
    }
    // std::cout << std::endl;
    if (c == window_size)
      max_sum = std::max(max_sum, sum);
  }
  return max_sum;
}

int subarraySum(std::vector<int> arr, int window_size) {
  int n = arr.size();
  int i = 0, j = 0;
  long long max_sum = 0, cur_sum = 0;
  std::set<int> st;
  while(j < n) {

    // * check if duplicate element
    while (i < j && (st.count(arr[j]) || st.size() == window_size)) {
      cur_sum -= arr[i];
      st.erase(arr[i]);
      i++;
    }

    cur_sum += arr[j];
    st.insert(arr[j]);
    j++;

    if (st.size() == window_size)
      max_sum = std::max(max_sum, cur_sum);
  }

  return max_sum;
}

int main() {
  int window_size = 3;
  std::vector<int> arr = {1, 5, 4, 2, 9, 9, 9};
  // int window_size = 3;
  // std::vector<int> arr = {4, 4, 4};
  // int window_size = 3;
  // std::vector<int> arr = {1, 1, 1, 7, 8, 9};
  printArr(arr);

  int ans= subarraySum(arr, window_size);
  std::cout << "Subarray Sum Equals K: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 02-max-sum-of-size-k.cpp -o output && ./output
