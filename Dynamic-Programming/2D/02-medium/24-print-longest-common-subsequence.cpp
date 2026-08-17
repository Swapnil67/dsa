/*
 * Print Longest Common Subsequence
 *
 * Example 1    :
 * Input        : ‘s’  = “abcab”, ‘t’ = “cbab”
 * Output       : "bab"
 * 
 * Example 2    :
 * Input        : ‘s’  = “abc”, ‘t’ = “xyx”
 * Output       : ""
 *
 * https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383
*/

#include <vector>
#include <iostream>
#include <algorithm>

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

// * ------------------------- Approach 1: Optimal Approach -------------------------
// * m - size of s1, n - size of s2
// * Bottom Up Approach
// * TIME COMPLEXITY  O(m * n)
// * SPACE COMPLEXITY O(m * n) (No Auxillary Stack Space)
string findLCS(string &s, string &t) {
  if (s.size() < t.size())
    swap(s, t);

  int m = s.size(), n = t.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  for (int i = m - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (s[i] == t[j]) {
        dp[i][j] = 1 + dp[i + 1][j + 1];
      } else {
        dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }

  // * For Debugging
  for (auto &vec : dp)
    printArr(vec);

  // * Reconstruct the string by walking forward
  string ans = "";
  int i = 0, j = 0;
  while (i < m && j < n) {
    if (s[i] == t[j]) {
      ans += s[i]; // * Collect the matching character
      i++, j++;    // * Move diagonally
    } else if (dp[i][j + 1] >= dp[i + 1][j]) {
      j++; // * Move right because it has the better/equal optimal path
    } else {
      i++; // * Move Down
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  string s1 = "abcde", s2 = "ace";

  // * testcase 2
  // string s1 = "abc", s2 = "abc";

  // * testcase 3
  // string s1 = "abc", s2 = "def";

  cout << "s1: " << s1 << ", s2: " << s2 << endl;
  string ans = findLCS(s1, s2);
  cout << "Longest Common Subsequence: " << ans << endl;
}

// * Run the code
// * g++ --std=c++20 02-print-longest-common-subsequence.cpp -o output && ./output

