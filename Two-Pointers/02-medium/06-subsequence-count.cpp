/*
 * Leetcode - 1498
 * Number of Subsequences That Satisfy the Given Sum Condition
 * 
 * You are given an array of integers nums and an integer target.
 * Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element
 * on it is less or equal to target. Since the answer may be too large, return it modulo 10^9 + 7.
 * Leetcode - 1498

 * Example 1
 * Input  : nums = [3, 5, 6, 7], target = 9
 * Output : 4
 * [3], [3, 5], [3, 5, 6], [3, 6]
 *
 * Example 2
 * Input  : nums = [3, 3, 6, 8], target = 10
 * Output : 6
 *
 * Example 2
 * Input  : nums = [2, 3, 3, 4, 6, 7], target = 12
 * Output : 61

 * https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/
 * https://www.naukri.com/code360/problems/count-the-number-of-subsequences-having-product-not-more-than-p_1214647
*/

#include <vector>
#include <iostream>
#include <algorithm>

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


// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Generate sum of all the possible subsequences in nums (Recursion + Backtracking )
// * TIME COMPLEXITY O(2^N) 
// * SPACE COMPLEXITY O(2^N)

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Two Pointer
// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(1)
int numSubseq(vector<int> nums, int target)
{
  int n = nums.size();
  int M = 1e9 + 7; // * 10^9 + 7

  // * Sort the i/p nums
  sort(nums.begin(), nums.end());

  // * Create a power vector
  int power[n];
  power[0] = 1;
  for (int i = 1; i < n; ++i) {
    power[i] = (2 * power[i - 1]) % M;
  }

  int ans = 0;
  int l = 0, r = n - 1;

  while (l <= r) {
    int cur_sum = (nums[l] + nums[r]) % M;
    if (cur_sum <= target) {
      // * if this is valid then all combination of elements b/w i - j will be valid
      int diff = r - l;
      // cout << power[diff] << endl;
      // cout << diff << endl;
      ans = ((ans % M) + (power[diff])) % M ;
      l++;
    }
    else {
      r--;
    }
  }
  return ans;
}

int main(void) {
  // * testcase 1
  // int target = 9;
  // vector<int> arr = {3, 5, 6, 7};

  // * testcase 2
  // int target = 12;
  // vector<int> arr = {2, 3, 3, 4, 6, 7};

  // * testcase 3
  // int target = 22;
  // vector<int> arr = {14, 4, 6, 6, 20, 8, 5, 6, 8, 12, 6, 10, 14, 9, 17, 16, 9, 7, 14, 11, 14, 15, 13, 11, 10, 18, 13, 17, 17, 14, 17, 7, 9, 5, 10, 13, 8, 5, 18, 20, 7, 5, 5, 15, 19, 14};

  // * testcase 4
  int target = 10;
  vector<int> arr = {3, 3, 6, 8};

  cout << "Input Array" << endl;
  printArr(arr);
  cout << "Target " << target << endl;
  int ans = numSubseq(arr, target);
  cout << "Number of subsequences: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-subsequence-count.cpp -o output && ./output
