/*
 * Leetcode - 329
 * Longest Increasing Path in a Matrix
 * 
 * Given an m x n integers matrix, return the length of the longest increasing path in matrix.
 * 
 * From each cell, you can either move in four directions: left, right, up, or down. 
 * You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
 * 
 * Example 1:
 * Input     : matrix = [[9,9,4],[6,6,8],[2,1,1]]
 * Output    : 4
 * 
 * Example 1:
 * Input     : matrix = [[3,4,5],[3,2,6],[2,2,1]]
 * Output    : 4

 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
*/

// ! Amazon, Meta, Google, Microsoft

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
    if (i != n - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

int m, n;
const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// * Without Memoization
int dfs(int r, int c, int prev_val, vector<vector<int>> &matrix) {
  if (r < 0 || r >= m || c < 0 || c >= n || matrix[r][c] <= prev_val)
    return 0;

  int res = 0;
  for (auto &dir : dirs) {
    int dr = r + dir[0], dc = c + dir[1];
    res = max(res, 1 + dfs(dr, dc, matrix[r][c], matrix));
  }
  return res;
}

// * With Memoization
int dfs(int r, int c, int prev_val, vector<vector<int>> &matrix,
        vector<vector<int>> &dp) {
  if (r < 0 || r >= m || c < 0 || c >= n || matrix[r][c] <= prev_val)
    return 0;

  if (dp[r][c] != -1)
    return dp[r][c];

  int res = 0;
  for (auto &dir : dirs) {
    int dr = r + dir[0], dc = c + dir[1];
    res = max(res, 1 + dfs(dr, dc, matrix[r][c], matrix, dp));
  }
  return dp[r][c] = res;
}

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * Top Down
// * TIME COMPLEXITY O((m x n) * 4^(m x n))
// * SPACE COMPLEXITY O(m x n)
int bruteForce(vector<vector<int>> &matrix) {
  m = matrix.size(), n = matrix[0].size();
  int LIP = 0;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      LIP = max(LIP, dfs(r, c, INT_MIN, matrix));
    }
  }
  return LIP;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Top Down + Memoization
// * TIME COMPLEXITY O(m x n)
// * SPACE COMPLEXITY O(m x n)
int longestIncreasingPath(vector<vector<int>> &matrix) {
  m = matrix.size(), n = matrix[0].size();
  int LIP = 0;
  vector<vector<int>> dp(m, vector<int>(n, -1));
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      LIP = max(LIP, dfs(r, c, INT_MIN, matrix, dp));
    }
  }
  return LIP;
}

int main(void) {
  // * testcase 1
  vector<vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};

  // * testcase 2
  // vector<vector<int>> matrix = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};

  cout << "-------- Matrix -------- " << endl;
  for (auto &vec : matrix)
    printArr(vec);

  // int ans = bruteForce(matrix);
  int ans = longestIncreasingPath(matrix);

  cout << "Longest Increasing Path in a Matrix: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 02-longest-increasing-path-in-a-matrix.cpp -o output && ./output
