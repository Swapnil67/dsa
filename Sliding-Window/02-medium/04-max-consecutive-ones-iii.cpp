/*
 * Leetcode - 1004
 * Max Consecutive Ones III
 * 
 * Given a binary array nums and an integer k, return the maximum number of consecutive 1's
 * in the array if you can flip at most k 0's.
 * 
 * Example 1
 * Input  : nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * Output : 6
 * Explanation: [1,1,1,0,0,'1',1,1,1,1,'1']
 *                          ______________
 * Quoted numbers were flipped from 0 to 1. The longest subarray is underlined.
 * 
 * Example 2
 * Input  : nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 * Output : 10
 * Explanation: [0,0,1,1,'1','1',1,1,1,'1',1,1,0,0,0,1,1,1,1]
 *                   _________________________
 * Quoted numbers were flipped from 0 to 1. The longest subarray is underlined.
 * 
 * https://leetcode.com/problems/max-consecutive-ones-iii/description/
*/

// ! Amazon, Google, Meta, Microsoft, IBM, Adobe, Apple, Oracle

#include <vector>
#include <iostream>

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
// * Check all k size windows with k zeros
// * TIME COMPLEXITY O(N * 3)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> arr, int k) {
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
    max_ones = max(max_ones, j - i);
  }
  return max_ones;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * Classic Sliding Window
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int longestOnes(vector<int> arr, int k) {
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

    ans = max(ans, (j - i + 1));
    j++;
  }
  return ans;
}

int main() {
  // * testcase 1
  int k = 2;
  vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};

  // * testcase 2
  // int k = 3;
  // vector<int> arr = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};

  cout << "Input Array: " << endl;
  printArr(arr);
  
  // int ans = bruteForce(arr, k);
  int ans = longestOnes(arr, k);
  cout << " Max Consecutive Ones: " << ans << endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++17 04-max-consecutive-ones-iii.cpp -o output && ./output