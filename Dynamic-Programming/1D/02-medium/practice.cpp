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


// * ------------------------------------------------------------------------

// * 01 - House Robber
// int rob(vector<int> &nums) {
// TODO
// }

// * 02 - House Robber II
// int rob(vector<int> &nums) {
// TODO
// }

// * 03 - Maximum Product Subarray
// int findMaxProduct(vector<int> arr) {
// TODO
// }

// * 04 - Longest Palindromic Substring 
// string longestPalindrome(string s) {
// TODO
// }

// * 05 - Palindromic Substrings
// string countSubstrings(string s) {
// TODO
// }

// * 06 - Maximum Alternating Subsequence Sum 
// long long maxAlternatingSum(vector<int>& nums) {
// TODO
// }

// * 07 - Longest Increasing Subsequence (LIS)
// int lengthOfLIS(vector<int> &nums) {
// TODO
// }

// * 08 - Maximum Length of Pair Chain
// int findLongestChain(vector<vector<int>> &pairs) {
// TODO
// }

// * 09 - Decode Ways
// int numDecodings(string s) {
// TODO
// }

// * 10 - Maximum Length of Repeated Subarray
// int findLength(vector<int> &nums1, vector<int> &nums2) {
// TODO
// }

// * 13 - Coin Change
// int coinChange(vector<int> &coins, int amount) {
// TODO
// }

// * 14 Partition Equal Subset Sum
// bool canPartition(vector<int> &nums) {
// TODO
// }

// * 15 Subset Sum Equal To K
// bool subsetSumEqualsK(vector<int> &nums, int &k) {
// TODO
// }

// * 16 - Count Subsets Sum Equal To K
// int countSubsetSumEqualsK(vector<int> &nums, int &k) {
// TODO
// }

// * 17 - Partitions With Given Difference
// int countSubsetSumEqualsK(vector<int> &nums, int &diff) {
// TODO
// }

// * 18 - Minimum Cost For Tickets
// int mincostTickets(vector<int> &days, vector<int> &costs) {
// TODO
// }

// * 27 - Number of Longest Increasing Subsequence
// int findNumberOfLIS(vector<int> &nums) {
// TODO
// }

// * 28 - Partition Equal Subset Sum
// bool canPartition(vector<int> &nums) {
// TODO
// }

// * 29 - Combination Sum IV
// bool canPartition(vector<int> &nums) {
// TODO
// }

// * 30 - Perfect Squares
// bool canPartition(vector<int> &nums) {
// TODO
// }

// * 31 - Integer Break
// bool canPartition(vector<int> &nums) {
// TODO
// }

// * 32 - Largest Divisible Subset
// vector<int> largestDivisibleSubset(vector<int>& nums) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output