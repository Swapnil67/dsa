/**
 * * Leetcode - 1004
 * * Max Consecutive Ones III
 * * Given a binary array nums and an integer k, return the maximum number of consecutive 1's
 * * in the array if you can flip at most k 0's.
 * 
 * * Example 1
 * * Input  : nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * * Output : 6
 * * Explanation: [1,1,1,0,0,'1',1,1,1,1,'1']
 * *                          ______________
 * * Quoted numbers were flipped from 0 to 1. The longest subarray is underlined.
 * 
 * * Example 2
 * * Input  : nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 * * Output : 10
 * * Explanation: [0,0,1,1,'1','1',1,1,1,'1',1,1,0,0,0,1,1,1,1]
 * *                   _________________________
 * * Quoted numbers were flipped from 0 to 1. The longest subarray is underlined.
 * 
 * * https://leetcode.com/problems/max-consecutive-ones-iii/description/
*/

// ! Amazon, Google, Meta, Microsoft, IBM, Adobe, Apple, Oracle

#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}


// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Check all k size windows with k zeros
// * TIME COMPLEXITY O(N * 3)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr, int k) {
  int n = arr.size();
  int max_ones = 0;
  for(int i = 0; i < n; ++i) {
    int j = i, flips = k;
    for(; j < n; ++j) {
      // * check if flips available
      if (arr[j] == 0) {
        // * All flips used
        if (flips <= 0)
          break;
        flips -= 1;
      }
    }
    max_ones = std::max(max_ones, j - i);
  }
  return max_ones;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Classic Sliding Window
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int longestOnes(std::vector<int> arr, int k) {
  int n = arr.size();
  int i = 0, j = 0;
  int ans = 0;

  while(j < n) {
    if (arr[j] == 0)
      k--;
    
    // * Increase the window from left till it has k flips
    while (k < 0) {
      if (arr[i] == 0)
        k++;
      i++;
    }

    ans = std::max(ans, (j - i + 1));
    j++;
  }
  return ans;
}

int main() {
  // * testcase 1
  int k = 2;
  std::vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};

  // * testcase 2
  // int k = 3;
  // std::vector<int> arr = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};

  std::cout << "Input Array: " << std::endl;
  printArr(arr);
  
  // int ans = bruteForce(arr, k);
  int ans = longestOnes(arr, k);
  std::cout << " Max Consecutive Ones: " << ans << std::endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++17 04-max-consecutive-ones-iii.cpp -o output && ./output