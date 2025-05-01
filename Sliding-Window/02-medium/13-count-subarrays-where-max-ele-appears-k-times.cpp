
/**
 * * Leetcode - 2962
 * * Count Subarrays Where Max Element Appears at Least K Times
 * * You are given an integer array nums and a positive integer k.
 * * Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
 * 
 * * Example 1
 * * Input  : nums = [1,3,2,3,3], k = 2
 * * Output : 6
 * * Explanation: The subarrays that contain the element 3 at least 2 times are: 
 * * [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

 * * Example 2
 * * Input  : nums = [1,4,2,1], k = 3
 * * Output : 0
 * * Explanation: No subarray contains the element 4 at least 3 times.
 * 
 * * https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/
*/
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <bits/algorithmfwd.h>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int bruteForce(std::vector<int> &arr, int k) {
  int n = arr.size();
  int ans = 0;

  // * get the max_element from array
  int max_ele = *max_element(arr.begin(), arr.end());

  for(int i = 0; i < n; ++i) {
    std::unordered_map<int, int> freq_map;
    for(int j = i; j < n; ++j) {
      int cur = arr[j];
      freq_map[cur]++;
      if(cur == max_ele && freq_map[cur] >= k) {
        ans++;
      }
    }
  }

  return ans;
}

// * ------------------------- APPROACH 2A: Optimal Approach -------------------------`
// * Classic Sliding Window
// * Note: subarrays ending at 'j' => (n - j)
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
int countSubarrays(std::vector<int> &arr, int k) {
  int n = arr.size();
  int i = 0, j = 0, ans = 0;

  // * get the max_element from array
  int max_ele = *max_element(arr.begin(), arr.end());

  // * sliding window
  int count = 0;    // * freq of max_ele
  while(j < n) {
    if(arr[j] == max_ele) {
      count++;
    }

    while (count >= k) {
      ans += (n - j);
      if (arr[i] == max_ele) {
        count--;
      }
      i++;
    }

    j++;
  }

  return ans;
}

// * ------------------------- APPROACH 2B: Optimal Approach -------------------------`
// * Keep max_ele index vector 
// * find the first_idx where count >= k
// * ans += first_idx + 1 if count >= k
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int countSubarrays2(std::vector<int> &arr, int k) {
  int n = arr.size();
  int ans = 0, count = 0;
  int max_ele = *max_element(arr.begin(), arr.end());

  std::vector<int> max_ele_idx_arr;
  for(int i = 0; i < n; ++i) {
    // * check if cur ele is max_ele
    if (arr[i] == max_ele) {
      count++;
      max_ele_idx_arr.push_back(i); // * Add the index to arr
    }

    // * if count >= k then check the first_idx 
    // * where first_idx to i has count >= k
    if (count >= k) {
      int first_idx = max_ele_idx_arr[max_ele_idx_arr.size() - k];
      ans += first_idx + 1;
    }
  }
  return ans;
}

int main() {
  // * testcase 1
  int k = 2;
  std::vector<int> arr = {1, 3, 2, 3, 3};

  // * testcase 1
  // int k = 2;
  // std::vector<int> arr = {1, 3, 2, 5, 1, 5};

  // * testcase 2
  // int k = 3;
  // std::vector<int> arr = {1, 4, 2, 1};

  // * testcase 3
  // int k = 4;
  // std::vector<int> arr = {5, 5, 5, 5, 5, 5, 5};

  printf("Appear at least: %d\n", k);
  printf("Input Array\n");
  printArr(arr);  

  // int ans = bruteForce(arr, k);
  // int ans = countSubarrays(arr, k);
  int ans = countSubarrays2(arr, k);
  printf("Length of Longest Subarray With at Most %d Frequency is %d\n", k, ans);

  return 0;
}

// * Run the code
// * $CXX --std=c++20 13-count-subarrays-where-max-ele-appears-k-times.cpp -o output && ./output