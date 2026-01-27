/*
 * Leetcode - 1143
 * Longest Common Subsequence
 * 
 * Given two strings text1 and text2, return the length of their longest common subsequence. 
 * If there is no common subsequence, return 0.
 * 
 * A subsequence of a string is a new string generated from the original string with some characters
 * (can be none) deleted without changing the relative order of the remaining characters.
 * 
 * For example, "ace" is a subsequence of "abcde".
 * 
 * A common subsequence of two strings is a subsequence that is common to both strings.
 * 
 * https://leetcode.com/problems/longest-common-subsequence/description/
*/

// ! Amazon, Microsoft, Google, Meta, Uber, Adobe, ByteDance, Oracle

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

int solve(string s1, string s2, int i, int j) {
  if (i >= s1.size() || j >= s2.size())
    return 0;

  int a = 0, b = 0;
  if (s1[i] == s2[j]) {
    return 1 + solve(s1, s2, i + 1, j + 1);
  }
  return max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
}

int solve_dp(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
  if (i >= s1.size() || j >= s2.size())
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  int a = 0, b = 0;
  if (s1[i] == s2[j]) {
    return dp[i][j] = (1 + solve(s1, s2, i + 1, j + 1));
  }
  return dp[i][j] = max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * n - size of s1, m - size of s2
// * Recursion
// * TIME COMPLEXITY  O(2^n * 2^m)
// * SPACE COMPLEXITY O(2^n * 2^m)
int bruteForce(string s1, string s2) {
  return solve(s1, s2, 0, 0);
}

// * ------------------------- Approach 2: Optimal Approach -------------------------
// * m - size of s1, n - size of s2
// * Recursion + Memoization (Top Down)
// * TIME COMPLEXITY  O(m * n)
// * SPACE COMPLEXITY O(m * n) + O(m + n) (Auxillary Stack Space)
int longestCommonSubsequence(string s1, string s2) {
  vector<vector<int>> dp(1001, vector<int>(1001, -1));
  return solve_dp(s1, s2, 0, 0, dp);
}

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * m - size of s1, n - size of s2
// * Bottom Up Approach
// * TIME COMPLEXITY  O(m * n)
// * SPACE COMPLEXITY O(m * n) 
int longestCommonSubsequence2(string s1, string s2) {
  int m = s1.size(), n = s2.size();

  vector<vector<int>> t(m + 1, vector<int>(n + 1)); // * states
  for (int i = 0; i < m + 1; ++i) {
    for (int j = 0; j < n + 1; ++j) {
      if (i == 0 || j == 0)  { // * either length of s1 or s2 is zero
        t[i][j] = 0;
      }
      else if (s1[i - 1] == s2[j - 1]) {
        t[i][j] = 1 + t[i - 1][j - 1];
      }
      else {
        t[i][j] = max(t[i - 1][j], t[i][j - 1]);
      }
    }
  }

  for (auto &vec : t)
    printArr(vec);

  return t[m][n];
}

int main(void) {
  // * testcase 1
  string s1 = "abcde", s2 = "ace";

  // * testcase 2
  // string s1 = "abc", s2 = "abc";

  // * testcase 3
  // string s1 = "abc", s2 = "def";

  cout << "s1: " << s1 << ", s2: " << s2 << endl;
  // int ans = bruteForce(s1, s2);
  // int ans = longestCommonSubsequence(s1, s2);
  int ans = longestCommonSubsequence2(s1, s2);
  cout << "Longest Common Subsequence: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 01-longest-common-subsequence.cpp -o output && ./output
