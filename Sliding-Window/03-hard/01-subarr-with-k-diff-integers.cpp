
/**
 * * Leetcode - 992
 * * Subarrays with K Different Integers
 * * Given an integer array nums and an integer k, return the number of good subarrays of nums.
 * 
 * * A good array is an array where the number of different integers in that array is exactly k.
 * 
 * * Example 1
 * * Input  : nums = [1,2,1,2,3], k = 2
 * * Output : 7
 * * Explanation: Subarrays formed with exactly 2 different integers:
 * * [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

 * * Example 2
 * * Input  : nums = [1,2,1,3,4], k = 3
 * * Output : 3
 * * Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 * 
 * * https://leetcode.com/problems/subarrays-with-k-different-integers/description/
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
int bruteForce(std::vector<int> &arr, int k) {
  int n = arr.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    std::unordered_map<int, int> freq_map;
    for (int j = i; j < n; ++j) {
      freq_map[arr[j]]++;
      if(freq_map.size() == k) {
        ans++;
      }
      else if(freq_map.size() > k) {
        break;
      }
    }
  }
  return ans;
}

int helper(std::vector<int> &arr, int k) {
  int n = arr.size();
  int i = 0, j = 0, ans = 0;
  std::unordered_map<int, int> freq_map;
  while(j < n) {
    freq_map[arr[j]]++;

    // * shrink the window
    while(i < j && freq_map.size() > k) {
      freq_map[arr[i]]--;
      if(freq_map[arr[i]] == 0) {
        freq_map.erase(arr[i]);
      }
      i++;
    }

    // * count all subarrays till 'j'
    ans += (j - i + 1);
    j++;
  }
  return ans;
}

// * ------------------------- APPROACH 2A: Optimal Approach -------------------------`
// * Classic Sliding Window
// * Find subarrays with <= k elements and subtract from subarrays with <= k-1 elements
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
int subarraysWithKDistinct(std::vector<int> &arr, int k) {
  int n1 = helper(arr, k);
  int n2 = helper(arr, k - 1);
  // printf("%d = %d %d = %d\n", k, n1, k - 1, n2);
  return n1 - n2;
}

// * ------------------------- APPROACH 2B: Optimal Approach -------------------------`
// * find the smallest subarray with k elements ending at 'j'
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
int subarraysWithKDistinct2(std::vector<int> &arr, int k) {
  int n = arr.size();
  int i = 0, j = 0, ans = 0;
  int i_bada = 0;
  std::unordered_map<int, int> freq_map;
  while(j < n) {
    freq_map[arr[j]]++;

    // * Handle invalid subarray - (Shrink)
    while(freq_map.size() > k) {
      freq_map[arr[i]]--;
      if(freq_map[arr[i]] == 0) {
        freq_map.erase(arr[i]);
      }
      i++;
      i_bada = i;
    }

    // * Find smallest subarray ending at 'j'
    while(freq_map[arr[j]] > 1) {
      freq_map[arr[i]]--;
      i++;
    }

    if(freq_map.size() == k) {
      ans += (i - i_bada) + 1;
    }
    j++;
  }
  return ans;
}


int main() {
  // * testcase 1
  // int k = 2;
  // std::vector<int> arr = {1, 2, 1, 2, 3};

  // * testcase 2
  int k = 3;
  std::vector<int> arr = {1, 2, 1, 3, 4};

  printf("k different: %d\n", k);
  printf("Input Array\n");
  printArr(arr);  

  // int ans = bruteForce(arr, k);
  // int ans = subarraysWithKDistinct(arr, k);
  int ans = subarraysWithKDistinct2(arr, k);
  printf("Subarrays with %d Different Integers is %d\n", k, ans);

  return 0;
}

// * Run the code
// * $CXX --std=c++20 01-subarr-with-k-diff-integers.cpp -o output && ./output