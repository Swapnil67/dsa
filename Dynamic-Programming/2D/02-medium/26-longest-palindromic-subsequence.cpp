/*
 * Leetcode - 516
 * Longest Palindromic Subsequence
 * 
 * Given a string s, find the longest palindromic subsequence's length in s.
 * 
 * A subsequence is a sequence that can be derived from another sequence by deleting some or no elements 
 * without changing the order of the remaining elements.
 * 
 * https://leetcode.com/problems/longest-palindromic-subsequence/
 * https://www.naukri.com/code360/problems/longest-palindromic-subsequence_842787
*/

// ! Amazon, Google, Meta, Uber, LinkedIn, Paypal, MasterCard, IBM

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



int dfs(int m, int n, string &s, string &t) {
  // * Base case: if either string is empty
  if (m == 0 || n == 0)
    return 0;

  // * If characters match
  if (s[m - 1] == t[n - 1])
    return 1 + dfs(m - 1, n - 1, s, t);

  // * If characters do not match
  return max(dfs(m - 1, n, s, t), dfs(m, n - 1, s, t));
}

int dfs(int m, int n, string &s, string &t, vector<vector<int>> &dp) {
  // * Base case: if either string is empty
  if (m == 0 || n == 0)
    return 0;

  // * If we already calculated this answer, return it
  if (dp[m][n] != -1)
    return dp[m][n];

  // * If characters match
  if (s[m - 1] == t[n - 1])
    return dp[m][n] = 1 + dfs(m - 1, n - 1, s, t, dp);

  // * If characters do not match
  return dp[m][n] = max(dfs(m - 1, n, s, t, dp), dfs(m, n - 1, s, t, dp));
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * Recursion
// * TIME COMPLEXITY  O(2^(m+n))
// * SPACE COMPLEXITY O(2^n * 2^m)
int bruteForce(string s) {
  int m = s.length();
  string t = s;
  reverse(begin(t), end(t));
  return dfs(m, m, s, t);
}

// * ------------------------- Approach 2: Optimal Approach -------------------------
// * Recursion + Memoization (Top Down)
// * TIME COMPLEXITY  O(m^2)
// * SPACE COMPLEXITY O(m^2) + O(m + n) (Auxillary Stack Space)
int betterApproach(string s) {
  int m = s.length();
  string t = s;
  reverse(begin(t), end(t));
  vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
  return dfs(m, m, s, t, dp);
}

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * Bottom Up Approach
// * TIME COMPLEXITY  O(m * m^2)
// * SPACE COMPLEXITY O(m^2) (No Auxillary Stack Space)
int longestPalindromeSubseq(string s) {
  int m = s.length();

  // * 1. Create a reversed copy of the string
  string t = s;
  reverse(begin(t), end(t)); // * O(m)

  // * 2. Create a grid to store solutions to smaller problems.
  // * Size is (m + 1) x (m + 1) initialized to 0.
  // * The extra row and column handle the boundary/empty string cases.
  vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

  // * 3. Build the solution bottom-up from the end of the strings
  for (int i = m - 1; i >= 0; --i) { // * O(m^2)
    for (int j = m - 1; j >= 0; --j) {
      if (s[i] == t[j]) {
        // * If letters match, add 1 to the result of the remaining strings
        dp[i][j] = 1 + dp[i + 1][j + 1];
      }
      else {
        // * If they don't match, take the best result from skipping
        // * a letter in either string s or string t
        dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }

  // * 4. The top-left cell holds the answer for the full-length strings
  return dp[0][0];
}


// * ------------------------- Approach 3: Optimal Approach -------------------------
// * Bottom Up Approach
// * TIME COMPLEXITY  O(m^2)
// * SPACE COMPLEXITY O(m) (No Auxillary Stack Space)
int longestPalindromeSubseq2(string s) {
  int m = s.length();
  
  // * 1. Create a reversed copy of the string
  string t = s;
  reverse(begin(t), end(t));
  
  // * 2. Space Optimization: Instead of a full grid, we only keep two rows.
  // * 'prev' represents the row below (i + 1)
  // * 'cur' represents the current row we are filling right now (i)
  vector<int> prev(m + 1, 0);
  vector<int> cur(m + 1, 0);
  
  // * 3. Loop backwards through both strings
  for (int i = m - 1; i >= 0; --i) {
      for (int j = m - 1; j >= 0; --j) {

        if (s[i] == t[j]) {
          // * If letters match, look diagonally down-right:
          // * This means look at the next character in 'prev' (row i + 1, col j + 1)
          cur[j] = 1 + prev[j + 1];
        }
        else {
          // * If they don't match, take the max of:
          // * Skipping s[i] -> look down at prev[j] (row i + 1, col j)
          // * Skipping t[j] -> look right at cur[j + 1] (row i, col j + 1)
          cur[j] = max(prev[j], cur[j + 1]);
        }
      }
      // * 4. Important: The current row is finished. It now becomes 
      // * the 'previous' row for the next iteration of the outer loop.
      prev = cur;
  }
  
  // * 5. The final answer sits at the start of our last computed row
  return prev[0];
}


int main(void) {
  // * testcase 1
  string s = "bbbab";

  // * testcase 2
  // string s = "cbbd";

  cout << "s: " << s << endl;

  // int ans = bruteForce(s);
  // int ans = betterApproach(s);
  // int ans = longestPalindromeSubseq(s);
  int ans = longestPalindromeSubseq2(s);

  cout << "Longest Palindromic Subsequence: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 26-longest-palindromic-subsequence.cpp -o output && ./output
