/*
 * Leetcode - 1143
 * Delete Operation for Two Strings
 * 
 * Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
 * 
 * In one step, you can delete exactly one character in either string.
 * 
 * Example 1    :
 * Input        : word1 = "sea", word2 = "eat"
 * Output       : 2
 * Explanation  : You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
 * 
 * Example 2    :
 * Input        : word1 = "leetcode", word2 = "etco"
 * Output       : 4
 * 
 * https://leetcode.com/problems/delete-operation-for-two-strings/description/
*/

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

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * m - size of s, n - size of t
// * Bottom Up Approach + Space Optimized
// * TIME COMPLEXITY  O(m * n)
// * SPACE COMPLEXITY O(min(m,n)) (No Auxillary Stack Space)
int longestCommonSubsequence(string s, string t) {
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

int minDistance(string s, string t) {
	int lcs = longestCommonSubsequence(s, t);
	return (s.length() - lcs) + (t.length() - lcs);
}

int main(void) {
  // * testcase 1
  string s = "sea", t = "eat";

  // * testcase 2
  // string s = "leetcode", t = "etco";

  // * testcase 3
  // string s = "abc", t = "def";

  cout << "s: " << s << ", t: " << t << endl;

  int ans = minDistance(s, t);

  cout << "Delete Operation for Two Strings: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 01-longest-common-subsequence.cpp -o output && ./output
