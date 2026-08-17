/*
 * Leetcode - 63
 * Unique Paths II
 * 
 * You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
 * The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
 * The robot can only move either down or right at any point in time.
 * 
 * An obstacle and space are marked as 1 or 0 respectively in grid. 
 * A path that the robot takes cannot include any square that is an obstacle.
 * 
 * Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
 * 
 * The testcases are generated so that the answer will be less than or equal to 2 * 109.
 * 
 * Example 1    :
 * Input        : obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * Output       : 2
 * 
 * Example 2    :
 * Input        : obstacleGrid = [[0,1],[0,0]]
 * Output       : 1
 * 
 * https://leetcode.com/problems/unique-paths-ii/
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

int m, n;

// * Without Memoization
int dfs(int r, int c, vector<vector<int>> &grid) {
  if (r >= m || c >= n || grid[r][c] == 1)
    return 0;

  if (r == m - 1 && c == n - 1)
    return 1;

  return dfs(r + 1, c, grid) + dfs(r, c + 1, grid);
}

// * With Memoization
int dfs(int r, int c, vector<vector<int>> &grid, vector<vector<unsigned int>>& dp) {
  if (r >= m || c >= n || grid[r][c] == 1)
    return 0;

  if (r == m - 1 && c == n - 1)
    return 1;

  if (dp[r][c] != -1)
    return dp[r][c];

  return dp[r][c] = dfs(r + 1, c, grid, dp) + dfs(r, c + 1, grid, dp);
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^(m * n))
// * SPACE COMPLEXITY O(n)
int bruteForce(vector<vector<int>> &grid) {
  m = grid.size(), n = grid[0].size();
  if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
    return 0;
  return dfs(0, 0, grid);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n)
int betterApproach(vector<vector<int>> &grid) {
  m = grid.size(), n = grid[0].size();
  if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
    return 0;
  vector<vector<unsigned int>> dp(m, vector<unsigned int>(n, -1));
  return dfs(0, 0, grid, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up 
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n) (No Auxillary Space)
int uniquePathsWithObstacles(vector<vector<int>> &grid) {
  m = grid.size(), n = grid[0].size();
  if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
    return 0;

  vector<vector<unsigned int>> dp(m + 1, vector<unsigned int>(n + 1, 0));
  dp[m - 1][n - 1] = 1;

  for (int r = m - 1; r >= 0; --r) {
    for (int c = n - 1; c >= 0; --c) {
      if (grid[r][c] == 1) {
        dp[r][c] = 0;
      } else {
        dp[r][c] += dp[r + 1][c] + dp[r][c + 1];
      }
    }
  }

  return dp[0][0];
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(n) (No Auxillary Space)
int uniquePaths(vector<vector<int>> &grid) {
  m = grid.size(), n = grid[0].size();
  if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
    return 0;

  vector<unsigned int> dp(n + 1, 0);
  dp[n - 1] = 1;
  for (int r = m - 1; r >= 0; --r) {
    for (int c = n - 1; c >= 0; --c) {
      if (grid[r][c] == 1) {
        dp[c] = 0;
      } else {
        dp[c] += dp[c + 1];
      }
    }
  }

  return dp[0];
}

int main(void) {
  // vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  // vector<vector<int>> grid = {{0, 1}, {0, 0}};
  // vector<vector<int>> grid = {{0, 0}, {0, 1}};
  vector<vector<int>> grid = {{0, 1, 0, 0}};
  
  cout << "Input Grid" << endl;
  for (auto &vec : grid)
    printArr(vec);

  int ans = bruteForce(grid);
  // int ans = betterApproach(grid);
  // int ans = uniquePaths(grid);

  cout << "Unique Paths: " << ans << endl; 

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 05-unique-paths-ii.cpp -o output && ./output

/*
* Initial Setup:
* grid = [0, 0, 0]
*        [0, 1, 0]
*        [0, 0, 0]
* 
* dp size = 4 (n + 1)
* Initial dp state: [0, 0, 1, 0]
* 
* ==================================================
* 
* Row r = 2 (Bottom Row)
* --------------------------------------------------
* c = 2 | grid[2][2] = 0 | dp[2] += dp[3] -> 1 + 0 = 1
* dp state: [0, 0, 1, 0]
* 
* c = 1 | grid[2][1] = 0 | dp[1] += dp[2] -> 0 + 1 = 1
* dp state: [0, 1, 1, 0]
* 
* c = 0 | grid[2][0] = 0 | dp[0] += dp[1] -> 0 + 1 = 1
* dp state: [1, 1, 1, 0]
* 
* End of Row 2 dp state: [1, 1, 1, 0]
* 
* ==================================================
* 
* Row r = 1 (Middle Row)
* --------------------------------------------------
* c = 2 | grid[1][2] = 0 | dp[2] += dp[3] -> 1 + 0 = 1
* dp state: [1, 1, 1, 0]
* 
* c = 1 | grid[1][1] = 1 | Obstacle! dp[1] = 0
* dp state: [1, 0, 1, 0]
* 
* c = 0 | grid[1][0] = 0 | dp[0] += dp[1] -> 1 + 0 = 1
* dp state: [1, 0, 1, 0]
* 
* End of Row 1 dp state: [1, 0, 1, 0]
* 
* ==================================================
* 
* Row r = 0 (Top Row)
* --------------------------------------------------
* c = 2 | grid[0][2] = 0 | dp[2] += dp[3] -> 1 + 0 = 1
* dp state: [1, 0, 1, 0]
* 
* c = 1 | grid[0][1] = 0 | dp[1] += dp[2] -> 0 + 1 = 1
* dp state: [1, 1, 1, 0]
* 
* c = 0 | grid[0][0] = 0 | dp[0] += dp[1] -> 1 + 1 = 2
* dp state: [2, 1, 1, 0]
* 
* End of Row 0 dp state: [2, 1, 1, 0]
* 
* ==================================================
* 
* Final Result (dp[0]): 2
*/