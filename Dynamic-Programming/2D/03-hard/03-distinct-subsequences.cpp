/*
 * Leetcode - 115
 * Distinct Subsequences
 * 
 * Given two strings s and t, return the number of distinct subsequences of s which equals t.
 * 
 * The test cases are generated so that the answer fits on a 32-bit signed integer.
 * 
 * Example 1
 * input            : s = "rabbbit", t = "rabbit"
 * output           : 3
 * 
 * Example 2
 * input            : s = "babgbag", t = "bag"
 * output           : 5
 * 
 * https://neetcode.io/problems/count-subsequences
 * https://leetcode.com/problems/distinct-subsequences
 * https://www.naukri.com/code360/problems/subsequence-counting_3755256
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
int dfs(int i, int j, string &s, string &t) {
  if (j < 0 || i < 0)
    return (j < 0);

  if (s[i] == t[j]) {
    // * (i - 1, j - 1) find the next possible char
    // * (i - 1, j) find another occurence of same char
    return dfs(i - 1, j - 1, s, t) + dfs(i - 1, j, s, t);
  } else {
    return dfs(i - 1, j, s, t);
  }
}

// * With Memoization
int dfs(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
  if (j == 0 || i == 0)
    return (j == 0);

  if (dp[i][j] != -1)
    return dp[i][j];

  if (s[i - 1] == t[j - 1]) {
    return dp[i][j] =
               dfs(i - 1, j - 1, s, t, dp) + dfs(i - 1, j, s, t, dp);
  }
  return dp[i][j] = dfs(i - 1, j, s, t, dp);
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * 'm' is the length of the string 's'
// * Top Down
// * TIME COMPLEXITY O(2^m)
// * SPACE COMPLEXITY O(m)
int bruteForce(string s, string t) {
  m = s.length(), n = t.length();
  return dfs(m - 1, n - 1, s, t);
}

// * ------------------------- Approach: Better Approach -------------------------
// * 'm' is the length of the string 's'
// * 'n' is the length of the string 't'
// * Top Down + Memoization
// * TIME COMPLEXITY O(m * n) (With Recursion Auxillary Space O(n))
// * SPACE COMPLEXITY O(m * n)
int betterApproach(string s, string t) {
  m = s.length(), n = t.length();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
  return dfs(m, n, s, t, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * t[i][j] = min operations for making word1 of length 'i' and word2 of length 'j' equal
// * Bottom Up
// * TIME COMPLEXITY O(m * n) (No Recursion Auxillary Space O(n))
// * SPACE COMPLEXITY O(m * n)
int numDistinct(string s, string t) {
  int m = s.length(), n = t.length();
  vector<vector<uint>> dp(m + 1, vector<uint>(n + 1, 0));

  // * Base cases (For every 'i' if 'j' becomes 0 we found one subsequence)
  for (int i = 0; i < m; ++i)
    dp[i][0] = 1;

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // * For Debugging
  // for (auto& vec : dp)
  //     printArr(vec);

  return dp[m][n];
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimized
// * TIME COMPLEXITY O(m * n) (No Recursion Auxillary Space O(n))
// * SPACE COMPLEXITY O(n)
int numDistinct2(string s, string t) {
  int m = s.size(), n = t.size();

  // * Base Case
  vector<int> prev(n + 1, 0);
  prev[0] = 1;

  vector<int> cur(n + 1, 0);
  cur[0] = 1;

  printArr(prev);

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (s[i - 1] == t[j - 1]) {
        cur[j] = prev[j - 1] + prev[j];
      } else {
        cur[j] = prev[j];
      }
    }
    prev = cur;
    printArr(prev);
  }

  return prev[n];
}

int main(void) {
  // * testcase 1
  // string s = "rabbbit", t = "rabbit";

  // * testcase 2
  string s = "babgbag", t = "bag";

  cout << "s: " << s << endl;
  cout << "t: " << t << endl;

  // int ans = bruteForce(s, t);
  // int ans = betterApproach(s, t);
  // int ans = numDistinct(s, t);
  int ans = numDistinct2(s, t);

  cout << "Distinct Subsequences: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 03-distinct-subsequences.cpp -o output && ./output
