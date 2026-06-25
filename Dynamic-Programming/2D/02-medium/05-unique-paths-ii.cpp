/*
 * 
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
int dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>>& dp) {
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
  vector<vector<int>> dp(m, vector<int>(n, -1));
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

  vector<vector<uint>> dp(m + 1, vector<uint>(n + 1, 0));
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

  vector<uint> dp(n + 1, 0);
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

  return 0;
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
