/*
 * Leetcode - 5
 * Longest Palindromic Substring 
 * 
 * Given a string s, return the longest palindromic substring in s.
 * 
 * https://neetcode.io/problems/longest-palindromic-substring/question
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 * https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string1956/1
 * https://www.naukri.com/code360/problems/longest-palindromic-substring_758900
*/

// ! Amazon, Google, Meta, Microsoft, Oracle, Adobe

#include <vector>
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


bool is_palindrome(string s) {
  int n = s.size();
  int i = 0, j = n - 1;
  while (i <= j) {
    if (s[i++] != s[j--])
      return false;
  }
  return true;
}

bool is_palindrome2(string &s, int l, int r, vector<vector<int>> &dp) {
  if (l >= r)
    return true;

  if (dp[l][r] != -1)
    return dp[l][r];

  if (s[l] == s[r])
    return dp[l][r] = is_palindrome2(s, l + 1, r - 1, dp);

  return dp[l][r] = false;
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(n^3)
// * SPACE COMPLEXITY O(n) 
string bruteForce(string s) {
  int n = s.size();
  int max_len = 0;
  string ans = "";
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      string str = s.substr(i, j);
      if (is_palindrome(str)) {
        // std::cout << str << std::endl;
        if ((j - i + 1) > max_len) {
          max_len = (j - i);
          ans = str;
        }
      }
    }
  }

  return ans;
}


// * ------------------------- Approach 2: Better Approach -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(n^3)
// * SPACE COMPLEXITY O(n) 
string betterApproach(string s) {
  int n = s.size();
  int max_len = 0;
  string ans = "";
  for (int i = 0; i < n; ++i) {
    for (int j = n - 1; j >= i; --j) {
      string str = s.substr(i, j);
      if (is_palindrome(str)) {
        std::cout << str << std::endl;
        if ((j - i + 1) > max_len) {
          max_len = (j - i);
          ans = str;
        }
        break;
      }
    }
  }

  return ans;
}

// * ------------------------- Approach 2: Better Approach -------------------------
// * Recursion + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2) 
string longestPalindrome(string s) {
  int n = s.size();
  int max_len = 0, start_idx = 0;
  string ans = "";
  vector<vector<int>> dp(n, vector<int>(n, -1));
  
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (is_palindrome2(s, i, j, dp)) {
        if ((j - i + 1) > max_len) {
          start_idx = i;
          max_len = (j - i + 1);
        }
      }
    }
  }

  return s.substr(start_idx, max_len);
}

int main(void) {
  // * testcase 1
  string s = "babad";
  
  // * testcase 2
  // string s = "cbbd";

  std::cout << "Input String: " << s << std::endl;

  string ans = bruteForce(s);
  // string ans = betterApproach(s);
  // int ans = longestPalindrome(s);
  std::cout << "Longest Palindromic Substring: " << ans << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 04-longest-palindromic-substring.cpp -o output && ./output
