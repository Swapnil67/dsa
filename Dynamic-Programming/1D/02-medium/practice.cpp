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

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output