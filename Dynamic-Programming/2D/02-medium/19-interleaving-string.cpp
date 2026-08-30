/*
 * Leetcode - 97
 * Interleaving String
 * 
 * Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
 * 
 * An interleaving of two strings s and t is a configuration where s and t are divided 
 * into n and m substrings respectively, such that:
 * 
 * - s = s1 + s2 + ... + sn
 * - t = t1 + t2 + ... + tm
 * - |n - m| <= 1
 * - The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
 * 
 * Note: a + b is the concatenation of strings a and b.
 * 
 * 
 * Example 1
 * input            : s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * output           : true
 * 
 * Example 2
 * input            : s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * output           : false
 * 
 * https://leetcode.com/problems/interleaving-string
 * https://neetcode.io/problems/interleaving-string
 * https://www.naukri.com/code360/problems/interleaving-two-strings_1062567
 * https://www.geeksforgeeks.org/problems/interleaved-strings/1
 * https://www.youtube.com/watch?v=CfzP4oXxZTI
*/

// ! Amazon, Google, Meta, Uber, Microsoft, Apple

#include <vector>
#include <cstring>
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

int m, n, N;

// * with Memoization
bool dfs(int i, int j, int k, string &s1, string &s2, string &s3,
         int (&t)[][101][201]) {
  if (i == m && j == n && k == N)
    return true;

  if (t[i][j][k] != -1)
    return t[i][j][k];

  // * Choice 1: If the current char of s1 matches s3[k], try moving forward in s1
  bool res = false;
  if (s1[i] == s3[k])
    res = dfs(i + 1, j, k + 1, s1, s2, s3, t);

  if (res == true) // * Early Exit
    return res;

  // * Choice 2: If the current char of s2 matches s3[k], try moving forward in s2
  if (s2[j] == s3[k])
    res = dfs(i, j + 1, k + 1, s1, s2, s3, t);

  return t[i][j][k] = res;
}

bool dfs(int i, int j, string &s1, string &s2, string &s3,
         int (&t)[101][101]) {
  if (i == m && j == n)
    return true;

  if (t[i][j] != -1)
    return t[i][j];

  // * Choice 1: If the current char of s1 matches s3[k], try moving forward in s1
  bool res = false;
  if (s1[i] == s3[i + j]) // * k = i + j
    res = dfs(i + 1, j, s1, s2, s3, t);

  if (res == true)
    return res;

  // * Choice 2: If the current char of s2 matches s3[k], try moving forward in s2
  if (s2[j] == s3[i + j]) // * k = i + j
    res = dfs(i, j + 1, s1, s2, s3, t);

  return t[i][j] = res;
}

// * ------------------------- Approach: Better Approach -------------------------
// * Use only 'i' and 'j' and let 'k' with t[][][]
// * Top Down + Memoization
// * TIME COMPLEXITY O(m * n * N)
// * SPACE COMPLEXITY O(m * n * N)
int betterApproach(string s1, string s2, string s3) {
  m = s1.length(), n = s2.length(), N = s3.length();
  if (N != m + n)
    return false;

  int t[101][101][201];
  memset(t, -1, sizeof(t));
  return dfs(0, 0, 0, s1, s2, s3, t);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Use only 'i' and 'j' and let 'k' = 'i + j'
// * Top Down + Memoization
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n)
int isInterleave(string s1, string s2, string s3) {
  m = s1.length(), n = s2.length(), N = s3.length();
  if (N != m + n)
    return false;

  int t[101][101];
  memset(t, -1, sizeof(t));
  return dfs(0, 0, s1, s2, s3, t);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up 
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n)
int isInterleaveBottomUp(string s1, string s2, string s3) {
  m = s1.length(), n = s2.length(), N = s3.length();
  if (N != m + n)
    return false;

  vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

  // * --- Base Case ---
  // * Two empty strings can always form an empty s3
  dp[0][0] = true;

  // * --- Base Case: First Column ---
  // * Matching s3 using ONLY characters from s1 (s2 is empty)
  for (int i = 1; i <= m; ++i) {
    // * Can only be true if the previous prefix matched AND the current character matches s3
    dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
  }

  // * --- Base Case: First Row ---
  // * Matching s3 using ONLY characters from s2 (s1 is empty)
  for (int j = 1; j <= n; ++j) {
    // * Can only be true if the previous prefix matched AND the current character matches s3
    dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
  }

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      int k = i + j - 1;
      // * Choice 1: Take the current character from s1
      bool take_s1 = dp[i - 1][j] && (s1[i - 1] == s3[k]);
      // * Choice 2: Take the current character from s2
      bool take_s2 = dp[i][j - 1] && (s2[j - 1] == s3[k]);
      dp[i][j] = take_s1 || take_s2;
    }
  }

  // for (auto &vec: dp)
  //   printArr(vec);

  return dp[m][n];
}


// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(n)
bool isInterleaveBottomUp2(string s1, string s2, string s3) {
  int m = s1.length(), n = s2.length();

  // * Structural Guarantee: Total length must match perfectly
  if (m + n != s3.length())
    return false;

  // * dp[j] will store whether the current prefix of s1 and s2[0...j-1]
  // * can successfully interleave to form the corresponding prefix of s3.
  // * Space Complexity: O(n) instead of O(m * n)
  vector<bool> dp(n + 1, false);

  // * --- Base Case ---
  // * Empty s1 prefix and empty s2 prefix can form an empty s3 prefix
  dp[0] = true;

  // * --- Initialize the 1D Array (Row 0 Base Case) ---
  // * This simulates matching s3 using ONLY characters from s2 (s1 is empty)
  for (int j = 1; j <= n; ++j) {
    dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
  }

  // * --- Process row by row ---
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j <= n; ++j) {
      // * The current character index we need to match in s3
      int k = i + j - 1;

      if (j == 0) {
        // * Column 0: We are using ONLY characters from s1.
        // * dp[0] currently holds the value from the row above (dp[i-1][0]).
        dp[0] = dp[0] && (s1[i - 1] == s3[k]);
      }
      else {
        // * Choice 1: Take from s1.
        // * dp[j] still contains the value from the row above (equivalent to 2D's dp[i-1][j]).
        bool take_s1 = dp[j] && (s1[i - 1] == s3[k]);

        // * Choice 2: Take from s2.
        // * dp[j-1] has already been updated in this row loop iteration (equivalent to 2D's dp[i][j-1]).
        bool take_s2 = dp[j - 1] && (s2[j - 1] == s3[k]);

        // * Update the state for the current element
        dp[j] = take_s1 || take_s2;
      }
    }
  }

  return dp[n];
}

int main(void) {
  // * testcase 1
  string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";

  // * testcase 2
  // string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";

  // * testcase 3
  // string s1 = "", s2 = "", s3 = "";

  cout << "s1: " << s1 << ", s2: " << s2 << ", s3: " << s3 << endl;

  // int ans = betterApproach(s1, s2, s3);
  // int ans = isInterleave(s1, s2, s3);
  int ans = isInterleaveBottomUp(s1, s2, s3);

  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 19-interleaving-string.cpp -o output && ./output
