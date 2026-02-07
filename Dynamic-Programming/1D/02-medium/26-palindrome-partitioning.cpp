/*
 * Leetcode - 132
 * Palindrome Partitioning II
 * 
 * Given a string s, partition s such that every substring of the partition is a palindrome. 
 * Return the minimum cuts needed for a palindrome partitioning of s.

 * Example 1
 * input  : s = "aab"
 * output : 1

 * Example 2
 * input  : s = "a"
 * output : 0

 * Example 3
 * input  : s = "ab"
 * output : 1
 * 
 * https://leetcode.com/problems/palindrome-partitioning-ii/
*/

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

bool check_palindrome(string &s, int i, int j) {
  while (i <= j) {
    if (s[i++] != s[j--]) 
      return false;
  }
  return true;
}

int dfs( string s, int i, int j) {
  if ((i >= j) || check_palindrome(s, i, j))
    return 0;

  int res = INT_MAX;
  for (int k = i; k <= j - 1; ++k) {
    int cur = 1 + dfs(s, i, k) + dfs(s, k + 1, j);
    res = min(cur, res);
  }

  return res;
}

int dfs(string s, int i, int j, vector<vector<int>> &dp) {
  if ((i >= j) || check_palindrome(s, i, j))
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  int res = INT_MAX;
  for (int k = i; k <= j - 1; ++k) {
    int cur = 1 + dfs(s, i, k) + dfs(s, k + 1, j);
    res = min(cur, res);
  }

  return dp[i][j] = res;
}

// * ------------------------- Brute Force Approach -------------------------
// ! TLE
// * Recursion (Top Down)
// * TIME COMPLEXITY O(2^n * n)
// * SPACE COMPLEXITY O(2^n)
int bruteForce(string s) {
  return dfs(s, 0, s.size() - 1);
}
 
// * ------------------------- Better Approach -------------------------
// ! TLE
// * Recursion + Memoization (Top Down)
// * TIME COMPLEXITY O(n^2 * n)
// * SPACE COMPLEXITY O(n^2)
int betterApproach(string s) {
  int n = s.size();
  vector<vector<int>> dp(n, vector<int>(n, -1));
  return dfs(s, 0, n - 1, dp);
}

// * ------------------------- Optimal Approach -------------------------
// * Bottom Up
// * if t[i][j] = true  (This means s[i..j] is a palindrome)
// * if t[i][j] = false (This means s[i..j] is not a palindrome)
// * N = length of substring
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
int minCut(string s) {
  // * Blueprint
  int n = s.length();
  vector<vector<bool>> t(n, vector<bool>(n, false));
  for (int L = 1; L <= n; ++L) {
    for (int i = 0; (i + L - 1) < n; ++i) {
      int j = i + L - 1;
      if (i == j) { // * diagnol
        t[i][i] = true; // * Single characters are palindrome.
      }
      else if (i + 1 == j) {
        t[i][j] = s[i] == s[j]; // * Strings of 2 Length
      }
      else { // * Strings of length > 2
        t[i][j] = (s[i] == s[j] && t[i + 1][j - 1]);
      }
    }
  }

  // * For Debugging
  // for (auto &vec : t)
  //   printArr(vec);

  // * Min splits for every 'ith' index in string
  vector<int> dp(n, INT_MAX);
  dp[0] = 0;

  for (int i = 0; i < n; ++i) {
    if (t[0][i] == true) {
      dp[i] = 0;
    }
    else {
      for (int k = 0; k < i; ++k) {
        if (t[k + 1][i] && dp[i] > 1 + dp[k]) {
          dp[i] = 1 + dp[k];
        }
      }
    }
  }

  return dp[n - 1];
}

int main(void) {
  // * testcase 1
  string s = "aab";

  // * testcase 2
  // string s = "ab";

  // * testcase 3
  // string s = "a";

  cout << "Input string: " << s << endl;

  // int ans = bruteForce(s);
  // int ans = betterApproach(s);
  int ans = minCut(s);
  cout << "Palindrome Partitioning: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 26-palindrome-partitioning.cpp -o output && ./output