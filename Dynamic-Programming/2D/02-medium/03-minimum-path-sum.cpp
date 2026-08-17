/*
 * Leetcode - 64
 * Minimum Path Sum
 * 
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
 * which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example 1    :
 * Input        : grid = [[1,3,1],[1,5,1],[4,2,1]]
 * Output       : 7
 * Explanation  : Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
 * 
 * Example 2    :
 * Input        : grid = [[1,2,3],[4,5,6]]
 * Output       : 12
 *
 * https://leetcode.com/problems/minimum-path-sum
*/

#include <vector>
#include <climits>
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

int m, n;

// * Without Memoization
int dfs(int r, int c, vector<vector<int>> &grid) {
  if (r >= m || c >= n)
    return INT_MAX;

  if (r == m - 1 && c == n - 1)
    return grid[r][c];

  return grid[r][c] + min(dfs(r + 1, c, grid), dfs(r, c + 1, grid));
}

// * With Memoization
int dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp) {
  if (r >= m || c >= n)
    return INT_MAX;

  if (r == m - 1 && c == n - 1)
    return grid[r][c];

  if (dp[r][c] != -1)
    return dp[r][c];

  int ans =
      grid[r][c] + min(dfs(r + 1, c, grid, dp), dfs(r, c + 1, grid, dp));
  dp[r][c] = ans;
  return ans;
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^(m * n))
// * SPACE COMPLEXITY O(m + n)
int bruteForce(vector<vector<int>> &grid) {
  m = grid.size(), n = grid[0].size();
  return dfs(0, 0, grid);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n)
int betterApproach(vector<vector<int>> &grid) {
  m = grid.size(), n = grid[0].size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
  return dfs(0, 0, grid, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n)
int minPathSum(vector<vector<int>> &grid) {
  m = grid.size(), n = grid[0].size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
  dp[m - 1][n] = 0;

  for (int r = n - 1; r >= 0; --r) {
    for (int c = m - 1; c >= 0; --c) {
      dp[r][c] = grid[r][c] + min(dp[r + 1][c], dp[r][c + 1]);
      // cout << "dp[" << c << "] = grid[" << r << "][" << c
      //      << "] + min(dp[" << c << "], dp[" << c + 1 << "])" << endl;
    }
    // cout << endl;
    // printArr(dp);
  }

  return dp[0][0];
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(n)
int minPathSum2(vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  vector<int> dp(n + 1, INT_MAX);
  dp[n - 1] = 0;
  for (int r = m - 1; r >= 0; --r) {
    for (int c = n - 1; c >= 0; --c) {
      dp[c] = grid[r][c] + min(dp[c], dp[c + 1]);
    }
  }
  return dp[0];
}


int main(void) {
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  // vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};

  cout << "Input Grid" << endl;
  for (auto &vec : grid)
    printArr(vec);

  // int ans = bruteForce(grid);
  // int ans = betterApproach(grid);
  // int ans = minPathSum(grid);
  int ans = minPathSum2(grid);

  cout << "Minimum Path Sum: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 06-minimum-path-sum.cpp -o output && ./output

/*
* r = 2, c = 2
*   - dp[2] = grid[2][2] + min(dp[2], dp[3])
* r = 2, c = 1
*   - dp[1] = grid[2][1] + min(dp[1], dp[2])
* r = 2, c = 0
*   - dp[0] = grid[2][0] + min(dp[0], dp[1])
* dp => [ 7, 3, 1, 2147483647 ]

* r = 1, c = 2
*   - dp[2] = grid[1][2] + min(dp[2], dp[3])
* r = 1, c = 1
* - dp[1] = grid[1][1] + min(dp[1], dp[2])
* r = 1, c = 0
* - dp[0] = grid[1][0] + min(dp[0], dp[1])
* dp => [ 8, 7, 2, 2147483647 ]

* r = 0, c = 2
*   - dp[2] = grid[0][2] + min(dp[2], dp[3])
* r = 0, c = 1
*   - dp[1] = grid[0][1] + min(dp[1], dp[2])
* r = 0, c = 2
*   - dp[0] = grid[0][0] + min(dp[0], dp[1])
* dp => [ 7, 6, 3, 2147483647 ]
*/

