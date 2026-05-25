/*
 * Leetcode - 62
 * Unique Paths
 * 
 * There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
 * The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
 * The robot can only move either down or right at any point in time.
 * 
 * Given the two integers m and n, return the number of possible unique paths that the robot can take to 
 * reach the bottom-right corner.
 * 
 * The test cases are generated so that the answer will be less than or equal to 2 * 109.
 * 
 * https://leetcode.com/problems/unique-paths
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

// * Without Memoization
int dfs(int r, int c, int m, int n) {
  if (r >= m || c >= n)
    return 0;

  if (r == m - 1 || c == n - 1)
    return 1;

  return dfs(r + 1, c, m, n) + dfs(r, c + 1, m, n);
}

// * With Memoization
int dfs(int r, int c, int m, int n, vector<vector<int>>& dp) {
  if (r >= m || c >= n)
    return 0;

  if (dp[r][c] > 0)
    return dp[r][c];

  if (r == m - 1 || c == n - 1)
    return 1;

  return dp[r][c] = dfs(r + 1, c, m, n, dp) + dfs(r, c + 1, m, n, dp);
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^(m * n))
// * SPACE COMPLEXITY O(n)
int bruteForce(int m, int n) {
  return dfs(0, 0, m, n);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n)
int betterApproach(int m, int n) {
  vector<vector<int>> dp(m, vector<int>(n, -1));
  return dfs(0, 0, m, n, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(n)
int uniquePaths(int m, int n) {
  vector<int> prev_dp(n, 0);

  for (int r = m - 1; r >= 0; --r) {
    vector<int> cur_dp(n, 0);
    cur_dp[n - 1] = 1;
    for (int c = n - 2; c >= 0; --c) {
      cur_dp[c] = cur_dp[c + 1] + prev_dp[c];
    }
    prev_dp = cur_dp;
  }

  return prev_dp[0];
}

int main(void) {
  // int m = 3, n = 7;
  int m = 3, n = 2;
  cout << "m: " << m << ", n: " << n << endl;

  // int ans = bruteForce(m, n);
  // int ans = betterApproach(m, n);
  int ans = uniquePaths(m, n);

  cout << "Unique Paths: " << ans << endl; 

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 04-unique-paths.cpp -o output && ./output
