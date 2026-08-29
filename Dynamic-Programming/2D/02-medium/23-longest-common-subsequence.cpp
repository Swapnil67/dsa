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
 * https://leetcode.com/problems/longest-common-subsequence/
 * https://neetcode.io/problems/longest-common-subsequence/question
 * https://www.naukri.com/code360/problems/longest-common-subsequence_624879
 * https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
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

// * Without Memoization
int dfs(int i, int j, string &t1, string &t2) {
  if (i == 0 || j == 0)
    return 0;

  if (t1[i - 1] == t2[j - 1])
    return 1 + dfs(i - 1, j - 1, t1, t2);

  return max(dfs(i - 1, j, t1, t2), dfs(i, j - 1, t1, t2));
}

// * With Memoization
int dfs(int i, int j, string &t1, string &t2, vector<vector<int>> &dp) {
  if (i == 0 || j == 0)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  if (t1[i - 1] == t2[j - 1])
    return 1 + dfs(i - 1, j - 1, t1, t2, dp);

  return dp[i][j] =
             max(dfs(i - 1, j, t1, t2, dp), dfs(i, j - 1, t1, t2, dp));
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * n - size of s, m - size of t
// * Recursion
// * TIME COMPLEXITY  O(2^(m+n))
// * SPACE COMPLEXITY O(2^n * 2^m)
int bruteForce(string s, string t) {
  int m = s.size(), n = t.size();
  return dfs(m, n, s, t);
}

// * ------------------------- Approach 2: Optimal Approach -------------------------
// * m - size of s, n - size of t
// * Recursion + Memoization (Top Down)
// * TIME COMPLEXITY  O(m * n)
// * SPACE COMPLEXITY O(m * n) + O(m + n) (Auxillary Stack Space)
int betterApproach(string s, string t) {
  int m = s.size(), n = t.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
  return dfs(m, n, s, t, dp);
}

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * m - size of s, n - size of t
// * Bottom Up Approach
// * TIME COMPLEXITY  O(m * n)
// * SPACE COMPLEXITY O(m * n) (No Auxillary Stack Space)
int longestCommonSubsequence(string s, string t) { // * Using Backward Loop
  int m = s.size(), n = t.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  for (int i = m - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (s[i] == t[j]) 
        dp[i][j] = 1 + dp[i + 1][j + 1];
      else 
        dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
    }
  }

  // * For Debugging
  // for (auto &vec : dp)
  //   printArr(vec);

  return dp[0][0];
}

// * Using Forward Loop (Same as above)
int longestCommonSubsequence2(string s, string t) {
  int m = s.size(), n = t.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      // * Shift string indices back by 1 to match 0-based indexing
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // * For Debugging
  // for (auto &vec : dp)
  //   printArr(vec);

  return dp[m][n];
}

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * m - size of s, n - size of t
// * Bottom Up Approach + Space Optimized
// * TIME COMPLEXITY  O(m * n)
// * SPACE COMPLEXITY O(min(m,n)) (No Auxillary Stack Space)
int longestCommonSubsequence3(string s, string t) {
  if (s.size() < t.size()) {
    swap(s, t);
  }

  int m = s.size(), n = t.size();
  vector<int> prev(n + 1, 0);
  vector<int> cur(n + 1, 0);

  for (int i = m - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (s[i] == t[j]) {
        cur[j] = 1 + prev[j + 1];
      } else {
        // * cur[j + 1] : This represents skipping the current char of string (t) (t[j]) and moving to the next char. 
        // * prev[j]    : This represents skipping the current char of string (s) (s[i]) and moving to the next char 
        // *              (which belongs to the previous outer loop iteration, prev). 
        cur[j] = max(cur[j + 1], prev[j]);
        // * dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
    prev = cur;
  }

  return prev[0];
}

int main(void) {
  // * testcase 1
  // string s = "abcde", t = "ace";

  // * testcase 2
  // string s = "abc", t = "abc";

  // * testcase 3
  // string s = "abc", t = "def";

  // * testcase 4
  string s = "acd", t = "ced";

  cout << "s: " << s << ", t: " << t << endl;
  // int ans = bruteForce(s, t);
  // int ans = betterApproach(s, t);
  int ans = longestCommonSubsequence(s, t);
  // int ans = longestCommonSubsequence3(s, t);

  cout << "Longest Common Subsequence: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 01-longest-common-subsequence.cpp -o output && ./output
