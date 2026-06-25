/*
 * Leetcode - 44
 * Wildcard Matching
 * 
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with 
 * support for '?' and '*' where:
 * 
 * - '?' Matches any single character.
 * - '*' Matches any sequence of characters (including the empty sequence).
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Example 1
 * input            : s = "aa", p = "a"
 * output           : false
 * 
 * Example 2
 * input            : s = "aa", p = "*"
 * output           : true
 * 
 * Example 2
 * input            : s = "ab", p = "?*"
 * output           : true
 * 
 * https://leetcode.com/problems/wildcard-matching/description/
*/

// ! Amazon, Meta, Google, Oracle, Walmart, Bloomberg, JP Morgan, Microsoft, Swiggy

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

int m, n;

// * Without Memoization
bool dfs(int i, int j, string &s, string &p) {
  if (i < 0 && j < 0)
    return true;
  if (j < 0 && i >= 0)
    return false;

  if (i < 0 && j >= 0) {
    // * Pattern must only contain '*' for this (testcase - 3)
    for (int ii = 0; ii < j; ++ii) {
      if (p[ii] != '*')
        return false;
    }
    return true;
  }

  if (s[i] == p[j] || p[j] == '?') {
    return dfs(i - 1, j - 1, s, p);
  }
  if (p[j] == '*') {
    return (dfs(i - 1, j, s, p) || dfs(i, j - 1, s, p));
  }
  return false;
}

// * With Memoization
bool dfs(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
  if (i == 0 && j == 0)
    return true;

  if (j == 0 && i > 0)
    return false;

  if (i == 0 && j > 0) {
    for (int ii = 1; ii <= j; ++ii) {
      if (p[ii - 1] != '*')
        return false;
    }
    return true;
  }

  if (dp[i][j] != -1)
    return dp[i][j];

  if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
    return dp[i][j] = dfs(i - 1, j - 1, s, p, dp);
  }
  if (p[j - 1] == '*') {
    return dp[i][j] =
               (dfs(i - 1, j, s, p, dp) || dfs(i, j - 1, s, p, dp));
  }
  return dp[i][j] = false;
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * 'm' is the length of the string 's'
// * Top Down
// * TIME COMPLEXITY O(2^(m + n))
// * SPACE COMPLEXITY O(m + n)
int bruteForce(string &s, string &p) {
  m = s.length(), n = p.length();
  return dfs(0, 0, s, p);
}

// * ------------------------- Approach: Better Approach -------------------------
// * 'm' is the length of the string 's'
// * 'n' is the length of the string 't'
// * Top Down + Memoization
// * TIME COMPLEXITY O(m * n) (With Recursion Auxillary Space O(n))
// * SPACE COMPLEXITY O(m * n)
int betterApproach(string &s, string &p) {
  m = s.length(), n = p.length();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
  return dfs(m, n, s, p, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * t[i][j] = min operations for making word1 of length 'i' and word2 of length 'j' equal
// * Bottom Up
// * TIME COMPLEXITY O(m * n) (No Recursion Auxillary Space O(n))
// * SPACE COMPLEXITY O(m * n)
bool isMatch(string s, string p) {
   int m = s.length(), n = p.length();
  vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
  dp[0][0] = true;
  for (int j = 1; j <= n; ++j) {
    bool flag = true;
    for (int ii = 1; ii <= j; ++ii) {
      if (p[ii - 1] != '*') {
        flag = false;
        break;
      }
    }
    dp[0][j] = flag;
  }

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        } else {
          dp[i][j] = false;
        }
    }
  }

  return dp[m][n];
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimized
// * TIME COMPLEXITY O(m * n) (No Recursion Auxillary Space O(n))
// * SPACE COMPLEXITY O(n)
int isMatch2(string &s, string &p) {
  int m = s.length(), n = p.length();

  // * Base Case
  vector<bool> prev(n + 1, false);
  prev[n] = true;
  // printArr(prev);

  for (int i = m; i >= 0; --i) {
    vector<bool> cur(n + 1, false);
    cur[n] = (i == m);

    for (int j = n - 1; j >= 0; j--) {
      bool match = i < m && (s[i] == p[j] || p[j] == '.');
      if ((j + 1 < n && p[j + 1] == '*')) {
        cur[j] = cur[j + 2];
        if (match) {
          cur[j] = prev[j] || cur[j];
        }
      }
      else if (match) {
        cur[j] = prev[j + 1];
      }
    }
    prev = cur;
    printArr(prev);
  }

  return prev[0];
}

int main(void) {
  // * testcase 1
  // string s = "aa", p = "a";

  // * testcase 2
  // string s = "aa", p = "a*";

  // * testcase 2
  // string s = "ab", p = ".*";

  // * testcase 4
  // string s = " ", p = "***";
  
  // * testcase 5
  string s = "aab", p = "c*a*b";

  cout << "s: " << s << endl;
  cout << "p: " << p << endl;

  // bool ans = bruteForce(s, p);
  bool ans = betterApproach(s, p);
  // bool ans = isMatch(s, p);
  // bool ans = isMatch2(s, p);

  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 04-regular-expression-matching.cpp -o output && ./output
