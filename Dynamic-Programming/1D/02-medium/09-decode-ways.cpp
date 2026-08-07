/*
 * Leetcode - 91
 * Decode Ways
 * 
 * You have intercepted a secret message encoded as a string of numbers. The message is decoded via
 * the following mapping:
 * 
 * "1" -> 'A'
 * "2" -> 'B'
 * ...
 * "25" -> 'Y'
 * "26" -> 'Z'
 * 
 * However, while decoding the message, you realize that there are many different ways you can decode the 
 * message because some codes are contained in other codes ("2" and "5" vs "25").
 * For example, "11106" can be decoded into:
 * - "AAJF" with the grouping (1, 1, 10, 6)
 * - "KJF" with the grouping (11, 10, 6)
 * 
 * The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
 * 
 * Note: there may be strings that are impossible to decode.
 * 
 * Given a string s containing only digits, return the number of ways to decode it. 
 * If the entire string cannot be decoded in any valid way, return 0.
 * 
 * https://leetcode.com/problems/decode-ways/description/
*/

// ! Amazon, Google, Meta, Microsoft, Apple, Adobe, Oracle

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

int dfs(int i, string& s, vector<int>& dp) {
  int n = s.length();
  
  // * Base case: If we reached the end, we found 1 valid decoding path
  if (i == n) return 1;
  
  // * Base case: Leading zero cannot be decoded
  if (s[i] == '0') return 0;
  
  // * Return already computed result to save time
  if (dp[i] != -1) return dp[i];
  
  // * Option 1: Take a single digit
  int ways = dfs(i + 1, s, dp);
  
  // * Option 2: Take two digits if they form a valid number between 10 and 26
  if (i + 1 < n) {
    if (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')) {
      ways += dfs(i + 2, s, dp);
    }
  }
  
  // * Store the result in dp before returning
  return dp[i] = ways;
}


// * ------------------------- Approach: Optimal Approach -------------------------
// * Top Down approach with memoization
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) 
int numDecodings(string s) {
  int n = s.length();
  vector<int> dp(n, -1);
  return dfs(0, s, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up approach
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) (No Auxillary Stack Space)
int numDecodings2(string s) {
  int n = s.length();
  vector<int> t(n + 1, 0);

  t[n] = 1;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '0') {
      t[i] = 0;
    } else {
      t[i] = t[i + 1];
      if (i + 1 < n) { // * Check double digit condition
        if (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')) {
          t[i] += t[i + 2];
        }
      }
    }
    // printArr(t);
  }

  return t[0];
}

int main(void) {
  // * testcase 1
  // string s = "12";

  // * testcase 2
  string s = "226";

  cout << "s: " << s << endl;

  int ans = numDecodings(s);
  // int ans = numDecodings2(s);
  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 09-decode-ways.cpp -o output && ./output
