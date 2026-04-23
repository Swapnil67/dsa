/*
 * Leetcode - 1984
 * Minimum Difference Between Highest and Lowest of K Scores
 * 
 * You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. 
 * You are also given an integer k.
 * 
 * Pick the scores of any k students from the array so that the difference between the highest and the lowest of
 * the k scores is minimized.
 * Return the minimum possible difference.
 * 
 * Example 1
 * Input  : nums = [90], k = 1
 * Output : 0
 * 
 * Example 2
 * Input  : nums = [9, 4, 1, 7], k = 2
 * Output : 2

 * https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/
*/

#include <vector>
#include <climits>
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

// * Sliding Window Approach
// * Time Complexity = nlogn + O(N)
// * Space Complexity = O(1)
int minimumDifference(vector<int> arr, int k) {
  int n = arr.size();
  // * Step 1. Sort the given array
  sort(arr.begin(), arr.end());

  // * Step 2. Loop over the window
  int i = 0, j = k - 1;
  int res = INT_MAX;
  while(j < n) {
    res = min(res, arr[j] - arr[i]);
    i += 1;
    j += 1;
  }
  return res;
}


int main() {
  int k = 3;
  // int k = 2;
  vector<int> nums = {9, 4, 1, 7};
  printArr(nums);
  int ans = minimumDifference(nums, k);
  cout << "Minimum Difference Between Highest and Lowest of K Scores: " << ans << endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 01-min-dff-bw-high-and-low-k.cpp -o output && ./output