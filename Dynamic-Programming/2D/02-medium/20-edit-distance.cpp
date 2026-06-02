/*
 * Leetcode - 72
 * Edit Distance
 * 
 * Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
 * 
 * You have the following three operations permitted on a word:
 * 
 * - Insert a character
 * - Delete a character
 * - Replace a character
 * 
 * Example 1
 * input            : word1 = "horse", word2 = "ros"
 * output           : 3
 * 
 * Example 2
 * input            : word1 = "intention", word2 = "execution"
 * output           : 5
 * 
 * https://leetcode.com/problems/edit-distance/
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

int dfs(int m, int n, string word1, string word2) {
  // * word2 got completed first
  if (n == 0)
    return m; // * delete extra chars from word1

  // * word1 got completed first
  if (m == 0) 
    return n; // * Insert extra chars from word2

  // * Both char same at 'm' and 'n'
  if (word1[m - 1] == word2[n - 1])
    return dfs(m - 1, n - 1, word1, word2);

  // * Insert a char at 'm'
  int insert_res = 1 + dfs(m, n - 1, word1, word2);

  // * Delete a char at 'm'
  int delete_res = 1 + dfs(m - 1, n, word1, word2);

  // * Replace a char at 'm'
  int replace_res = 1 + dfs(m - 1, n - 1, word1, word2);

  return min(insert_res, min(delete_res, replace_res));
}


int dfs(int m, int n, string &word1, string &word2, vector<vector<int>>& dp) {
  // * word2 got completed first
  if (n == 0)
    return m; // * delete extra chars from word1

  // * word1 got completed first
  if (m == 0) 
    return n; // * Insert extra chars from word2

  if (dp[m][n] != -1)
    return dp[m][n];

  // * Both char same at 'm' and 'n'
  if (word1[m - 1] == word2[n - 1])
    return dfs(m - 1, n - 1, word1, word2, dp);

  // * Insert a char at 'm'
  int insert_res = 1 + dfs(m, n - 1, word1, word2, dp);

  // * Delete a char at 'm'
  int delete_res = 1 + dfs(m - 1, n, word1, word2, dp);

  // * Replace a char at 'm'
  int replace_res = 1 + dfs(m - 1, n - 1, word1, word2, dp);

  return dp[m][n] = min(insert_res, min(delete_res, replace_res));
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Use 3 ways on every recursion call
// * Top Down
// * TIME COMPLEXITY O(2^(m + n))
// * SPACE COMPLEXITY O(m + n)
int bruteForce(string word1, string word2) {
  int m = word1.size(), n = word2.size();
  return dfs(m, n, word1, word2);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Use 3 ways on every recursion call + Memoization
// * Top Down + Memoization
// * TIME COMPLEXITY O(m * n) (With Recursion Auxillary Space O(n))
// * SPACE COMPLEXITY O(m * n)
int betterApproach(string word1, string word2) {
  int m = word1.size(), n = word2.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
  return dfs(m, n, word1, word2, dp);
}


// * ------------------------- Approach: Optimal Approach -------------------------
// * t[i][j] = min operations for making word1 of length 'i' and word2 of length 'j' equal
// * Bottom Up
// * TIME COMPLEXITY O(m * n) (No Recursion Auxillary Space O(n))
// * SPACE COMPLEXITY O(m * n)
int minDistance(string word1, string word2) {
  int m = word1.size(), n = word2.size();
  vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (i == 0 || j == 0) {
        t[i][j] = i + j;
      } else if (word1[i - 1] == word2[j - 1]) {
        t[i][j] = t[i - 1][j - 1];
      } else {
        int insert_res = 1 + t[i][j - 1];
        int delete_res = 1 + t[i - 1][j];
        int replace_res = 1 + t[i - 1][j - 1];
        t[i][j] = min(insert_res, min(delete_res, replace_res));
      }
    }
  }

  // * For Debugging
  for (auto &vec : t)
    printArr(vec);

  return t[m][n];
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimized
// * TIME COMPLEXITY O(m * n) (No Recursion Auxillary Space O(n))
// * SPACE COMPLEXITY O(n)
int minDistance(string word1, string word2) {
  int m = word1.size(), n = word2.size();
  vector<int> prev(n + 1, 0);

  // * Base Case
  for (int j = 0; j <= n; ++j) {
    prev[j] = j;
  }
  // printArr(prev);

  vector<int> cur(n + 1, 0);
  for (int i = 1; i <= m; ++i) {
    cur[0] = i; // * For every 0th row ans will be 'i'
    for (int j = 1; j <= n; ++j) {
      if (word1[i - 1] == word2[j - 1]) {
        cur[j] = prev[j - 1];
      }
      else {
        int insert_res = 1 + cur[j - 1];
        int delete_res = 1 + prev[j];
        int replace_res = 1 + prev[j - 1];
        cur[j] = min(insert_res, min(delete_res, replace_res));
      }
    }
    prev = cur;
    // printArr(prev);
  }

  return prev[n];
}

int main(void) {
  // * testcase 1
  string word1 = "horse", word2 = "ros";

  // * testcase 2
  // string word1 = "intention", word2 = "execution";

  cout << "word1: " << word1 << endl;
  cout << "word2: " << word2 << endl;

  // int ans = bruteForce(word1, word2);
  // int ans = betterApproach(word1, word2);
  int ans = minDistance(word1, word2);
  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 20-edit-distance.cpp -o output && ./output
