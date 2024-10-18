/**
 * * Number of Subsequences That Satisfy the Given Sum Condition
 * * You are given an array of integers nums and an integer target.
 * * Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element 
 * * on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

 * * Example 1
 * * Input  : nums = [3,5,6,7], target = 9
 * * Output : 4
 * 
 * * Example 2
 * * Input  : nums = [3,3,6,8], target = 10
 * * Output : 6

 * * https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/
 * * https://www.naukri.com/code360/problems/count-the-number-of-subsequences-having-product-not-more-than-p_1214647
*/

#include<iostream>


// * ------------------------- UTILITY FUNCTIONS -------------------------`

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH: Optimal APPROACH -------------------------`
// * Tow Pointer
// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(1)
int numSubseq(std::vector<int> arr, int target) {
  int n = arr.size();
  int M = 1e9 + 7; // * 10^9 + 7

  // * Sort the i/p arr
  std::sort(arr.begin(), arr.end());

  // * Create pointers
  int l = 0, r = n - 1;
  int ans = 0;

  // * Create a power vector
  std::vector<int> power(n);
  power[0] = 1;
  for (int i = 1; i < n; ++i) {
    power[i] = (power[i - 1] * 2) % M;
  }

  while (l <= r) {
    long long sum = arr[l] + arr[r];
    if(sum <= target) {
      int diff = r - l;
      ans = (ans % M + power[diff]) % M;
      l++;
    }
    else {
      r--;
    }
  }
  return ans;
}



int main() {
  // * testcase 1
  int target = 9;
  std::vector<int> arr = {3, 5, 6, 7};
  // * testcase 2
  // int target = 12;
  // std::vector<int> arr = {2, 3, 3, 4, 6, 7};
  // * testcase 3
  // int target = 22;
  // std::vector<int> arr = {14, 4, 6, 6, 20, 8, 5, 6, 8, 12, 6, 10, 14, 9, 17, 16, 9, 7, 14, 11, 14, 15, 13, 11, 10, 18, 13, 17, 17, 14, 17, 7, 9, 5, 10, 13, 8, 5, 18, 20, 7, 5, 5, 15, 19, 14};

  std::cout << "Input Array" << std::endl;
  printArr(arr);
  int ans = numSubseq(arr, target);
  std::cout << "Number of subsequences: " << ans << std::endl;
}

// * Run the code
// * g++ --std=c++17 06-subsequence-count.cpp -o output && ./output


