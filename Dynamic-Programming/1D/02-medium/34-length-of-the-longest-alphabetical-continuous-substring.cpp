/*
 * Leetcode - 2414
 * Length of the Longest Alphabetical Continuous Substring
 * 
 * An alphabetical continuous string is a string consisting of consecutive letters in the alphabet. 
 * In other words, it is any substring of the string "abcdefghijklmnopqrstuvwxyz".
 * 
 * For example, "abc" is an alphabetical continuous string, while "acb" and "za" are not.
 * 
 * Given a string s consisting of lowercase letters only, return the length of the longest alphabetical 
 * continuous substring.
 * 
 * Example 1    :
 * Input        : s = "abacaba"
 * Output       : 2
 * Explanation  : "ab" is the longest continuous substring.
 * 
 * Example 2    :
 * Input        : s = "abcde"
 * Output       : 5
 * Explanation  : "abcde" is the longest continuous substring.
 * 
 * https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/description/
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()

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

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(string s) {
  int n = s.length();
  int maxLen = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (j > i && s[j] - s[j - 1] != 1)
        break;
      maxLen = max(maxLen, (j - i + 1));
    }
  }
  return maxLen;
}

// * ------------------------- Approach 2: Optimal Approach -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int longestContinuousSubstring(string s) {
  int n = s.length();
  if (n == 1)
    return 1;

  int maxLen = 1;
  vector<int> dp(n + 1, 1);
  dp[0] = 1;
  dp[1] = (s[1] - s[0] == 1) ? 2 : 1;

  for (int i = 2; i < n; ++i) {
    if ((s[i] - s[i - 1]) == 1) {
      dp[i] = dp[i - 1] + 1;
    }
    maxLen = max(maxLen, dp[i]);
  }

  // printArr(dp); // * for debug
  return maxLen;
}

int main(void) {
  // * testcase 1
  string s = "abacaba";

  // * testcase 2
  // string s = "abcde";

  cout << "s: " << s << endl;

  // int ans = bruteForce(s);
  int ans = longestContinuousSubstring(s);

  cout << "Longest Substring: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 34-length-of-the-longest-alphabetical-continuous-substring.cpp -o output && ./output
