/**
 * * Max Consecutive Ones III
 * * Given a binary array nums and an integer k, return the maximum number of consecutive 1's
 * * in the array if you can flip at most k 0's.
 * 
 * * Example 1
 * * Input  : nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * * Output : 6
 * * Explanation: [1,1,1,0,0,'1',1,1,1,1,'1']
 * * Quoted numbers were flipped from 0 to 1. The longest subarray is underlined.
 * 
 * * Example 2
 * * Input  : nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 * * Output : 10
 * * Explanation: [0,0,1,1,'1','1',1,1,1,'1',1,1,0,0,0,1,1,1,1]
 * * Quoted numbers were flipped from 0 to 1. The longest subarray is underlined.
 * 
 * * https://leetcode.com/problems/max-consecutive-ones-iii/description/
*/

#include<iostream>

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
  int max_cnt = 0;
  for (int i = 0; i < n; ++i) {
    int cur_cnt = 0, zero_cnt = 0;
    for (int j = i; j < n; ++j) {
      if(arr[j] == 1) {
        cur_cnt++;
      }
      else if(zero_cnt < k) {
        cur_cnt++;
        zero_cnt++;
      }
      else {
        break;
      }
    }
    max_cnt = std::max(max_cnt, cur_cnt);
  }
  return max_cnt;
}

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * keep zero counter and keep the window of k zeros
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int betterApproach(std::vector<int> arr, int k) {
  int n = arr.size();
  int i = 0, j = 0, zeros = 0;
  int max_len = 0;

  while(j < n) {
    if(arr[j] == 0) 
      zeros++;
    
    // * Increase the window from left till it has k zeros
    while(zeros > k) {
      if(arr[i] == 0) {
        zeros--;
      }
      i++;
    }

    if (zeros <= k) {
      max_len = std::max(max_len, j - i + 1);
    }
    j++;
  }
  return max_len;
}

// * ------------------------- APPROACH 3: Optimal Approach -------------------------`
// * keep zeros counter
// * Only calculate one count if zeros counter is under k
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int longestOnes(std::vector<int> arr, int k) {
  int n = arr.size();
  int i = 0, j = 0, max_cnt = 0, zeros = 0;
  while (j < n) {
    if (arr[j] == 0)
      zeros++;

    // * We have zeros under k
    if(zeros <= k) {
      max_cnt = std::max(max_cnt, j - i + 1);
    }
    else {
      // * We have more zeros than k
      if (arr[i] == 0)
        zeros--;
      i++;
    }

    j++;
  }
  return max_cnt;
}


int main() {

  // * testcase 1
  int k = 2;
  std::vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
  
  // * testcase 2
  // int k = 3;
  // std::vector<int> arr = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};

  printArr(arr);
  
  // int ans = bruteForce(arr, k);
  // int ans = betterApproach(arr, k);
  int ans = longestOnes(arr, k);
  std::cout << " Max Consecutive Ones: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 04-max-consecutive-ones-iii.cpp -o output && ./output