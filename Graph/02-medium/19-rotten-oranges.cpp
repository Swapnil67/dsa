/**
 * * Leetcode - 994
 * * Rotting Oranges
 *
 * * You are given an m x n grid where each cell can have one of three values:
 * * - 0 representing an empty cell,
 * * - 1 representing a fresh orange, or
 * * - 2 representing a rotten orange.
 *
 * * Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

 * * Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 * * Example 1  :
 * * Input      : grid = [[2,1,1],[1,1,0],[0,1,1]]
 * * Output     : 4
 * 
 * * Example 2  :
 * * Input      : grid = [[2,1,1],[0,1,1],[1,0,1]]
 * * Output     : -1

 * * Example 2  :
 * * Input      : grid = [[0,2]]
 * * Output     : 0
 * 
 * * https://leetcode.com/problems/rotting-oranges/description/
*/

#include <queue>
#include <vector>
#include <iostream>

typedef std::vector<char> vc;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

// * Print adjacency list
template <typename T>
void printAdjList(std::vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    std::cout << i << " -> ";
    printArr(adj[i]);
  }
}
const std::vector<std::vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool dfs(int x, int y, std::vector<std::vector<int>> &grid) {
  int m = grid.size(); 
  int n = grid[0].size(); 

  // * Edge cases
  if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 2) {
    return false;
  }

  if (grid[x][y] == 2)
    return true;

  for (auto &dir : dirs) {
    int new_x = x + dir[0]; 
    int new_y = y + dir[1];
    if (dfs(new_x, new_y, grid))
      return true;
  }

  return false;
}

// * ------------------------- Approach 1: Optimal -------------------------
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n) + O(m + n)
int orangesRotting(std::vector<std::vector<int>>& grid) {
  int m = grid.size(); 
  int n = grid[0].size(); 
  int minutes = 0;


  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1) {
        if (dfs(i, j, grid))
          minutes++;
      }
    }
  }

  return minutes;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

  // * testcase 2
  // std::vector<std::vector<int>> grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};

  std::cout << "grid: " << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  int ans = orangesRotting(grid);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 09-rotten-oranges.cpp -o output && ./output