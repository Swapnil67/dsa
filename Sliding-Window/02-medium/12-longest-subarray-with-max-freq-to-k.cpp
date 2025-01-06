
/**
 * * Length of Longest Subarray With at Most K Frequency
 * * You are given an integer array nums and an integer k.
 * * The frequency of an element x is the number of times it occurs in an array.
 * 
 * * An array is called good if the frequency of each element in this array is less than or equal to k.
 * * Return the length of the longest good subarray of nums.
 * 
 * * A subarray is a contiguous non-empty sequence of elements within an array.

 * * Example 1
 * * Input  : nums = [1,2,3,1,2,3,1,2], k = 2
 * * Output : 6
 * * Explanation: The longest possible good subarray is [1,2,3,1,2,3] 

 * * Example 2
 * * Input  : nums = [1,2,1,2,1,2,1,2], k = 1
 * * Output : 2
 * * Explanation: The longest possible good subarray is [1,2] or [2,1]
 * 
 * * https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/
*/
#include <vector>
#include <iostream>
#include <unordered_map>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int>& arr, int k) {
  int n = arr.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    std::unordered_map<int, int> freq_map;
    for (int j = 0; j < n; ++j) {
      freq_map[arr[j]]++;
      if(freq_map[arr[j]] > k) {
        break;
      }
      ans = std::max(ans, j - i + 1);
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2A: Optimal Approach -------------------------`
// * Classic Sliding Window
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
int maxSubarrayLength(std::vector<int>& arr, int k) {
  int n = arr.size();
  int i = 0, j = 0, ans = 0;
  std::unordered_map<int, int> freq_map;
  while (j < n) {
    freq_map[arr[j]]++;

    // * Shrink the window
    while (freq_map[arr[j]] > k) {
      freq_map[arr[i]]--;
      i++;
    }

    ans = std::max(ans, j - i + 1);
    j++;
  }
  return ans;
}

// * ------------------------- APPROACH 2B: Optimal Approach -------------------------`
// * Find culprit
// * culprit => ele which occurs more than k times
// * Classic Sliding Window
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
int maxSubarrayLength2(std::vector<int>& arr, int k) {
  int n = arr.size();
  int i = 0, j = 0, ans = 0;
  int culprit = 0;
  std::unordered_map<int, int> freq_map;
  while (j < n) {
    freq_map[arr[j]]++;

    // * Check if cur ele is culprit
    if (freq_map[arr[j]] == k + 1) {
      culprit++;
    }

    // * Shrink the window
    if (culprit > 0) {
      freq_map[arr[i]]--;
      if(arr[i] == k) {
        culprit--;
      }
      i++;
    }

    if (culprit == 0)
      ans = std::max(ans, j - i + 1);

    j++;
  }
  return ans;
}

int main() {
  // * testcase 1
  // int k = 2;
  // std::vector<int> arr = {1, 2, 3, 1, 2, 3, 1, 2};

  // * testcase 2
  // int k = 1;
  // std::vector<int> arr = {1, 2, 1, 2, 1, 2, 1, 2};

  // * testcase 3
  int k = 4;
  std::vector<int> arr = {5, 5, 5, 5, 5, 5, 5};

  printf("At most frequency: %d\n", k);
  printf("Input Array\n");
  printArr(arr);  

  // int ans = bruteForce(arr, k);
  // int ans = maxSubarrayLength(arr, k);
  int ans = maxSubarrayLength2(arr, k);
  printf("Length of Longest Subarray With at Most %d Frequency is %d\n", k, ans);

  return 0;
}

// * Run the code
// * $CXX --std=c++20 12-longest-subarray-with-max-freq-to-k.cpp -o output && ./output