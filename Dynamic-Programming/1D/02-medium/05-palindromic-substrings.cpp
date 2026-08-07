/*
 * Leetcode - 647
 * Palindromic Substrings
 * 
 * Given a string s, return the number of palindromic substrings in it.
 * A string is a palindrome when it reads the same backward as forward.
 * A substring is a contiguous sequence of characters within the string.
 * 
 * 
 * https://leetcode.com/problems/palindromic-substrings/description/
*/

// ! Amazon, Google, Meta, Microsoft, Oracle, Apple, Paypal, Bloomberg

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

bool is_palindrome(string &s, int l, int r) {
  if (l >= r)
    return true;

  if (s[l] == s[r])
    return is_palindrome(s, l + 1, r - 1);

  return false;
}

bool is_palindrome_dp(string &s, int l, int r, vector<vector<int>> &dp) {
  if (l >= r)
    return true;

  if (dp[l][r] != -1)
    return dp[l][r];

  if (s[l] == s[r])
    return dp[l][r] = is_palindrome_dp(s, l + 1, r - 1, dp);

  return dp[l][r] = 0;
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * Nested Loop + Recursion
// * TIME COMPLEXITY O(n^3)
// * SPACE COMPLEXITY O(1) 
int bruteForce(string s) {
  int n = s.size();
  int ans = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (is_palindrome(s, i, j)) {
        ans += 1;
      }
    }
  }

  return ans;
}

// * ------------------------- Approach 2: Better Approach -------------------------
// * Recursion + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2) 
int betterApproach(string s) {
  int n = s.size();
  int ans = 0;

  vector<vector<int>> dp(n, vector<int>(n, -1));

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (is_palindrome_dp(s, i, j, dp)) {
        ans += 1;
      }
    }
  }

  return ans;
}

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * Classic Pattern
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
int countSubstrings(string s) {
  int n = s.size();
  int ans = 0;
  vector<vector<bool>> t(n, vector<bool>(n, false));

  for (int L = 1; L <= n; ++L) {
    for (int i = 0; i + L - 1 < n; ++i) {
      int j = i + L - 1;
      if (i == j) {
        t[i][i] = true; // * Single characters are palindrome
      }
      else if (i + 1 == j) {
        t[i][j] = s[i] == s[j]; // * Strings of 2 Length
      }
      else { // * Strings of length > 2
        t[i][j] = (s[i] == s[j] && t[i + 1][j - 1]);
      }

      ans += t[i][j];
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // string s = "abc";

  // * testcase 2
  string s = "aaa";

  cout << "Input String: " << s << endl;

  // int ans = bruteForce(s);
  // int ans = betterApproach(s);
  int ans = countSubstrings(s);
  cout << "Palindromic Substrings: " << ans << endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 05-palindromic-substrings.cpp -o output && ./output

/*
* str = abacaba
*
*        0(a)  1(b)  2(a)  3(c)  4(a)  5(b)  6(a)
* 0(a)     1     0     1     0     0     0     1
* 1(b)     -     1     0     0     0     1     0
* 2(a)     -     -     1     0     1     0     0
* 3(c)     -     -     -     1     0     0     0
* 4(a)     -     -     -     -     1     0     1
* 5(b)     -     -     -     -     -     1     0
* 6(a)     -     -     -     -     -     -     1
* 
*/