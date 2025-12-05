/*
 * Leetcode - 1020
 * Number of Enclaves
 * 
 * You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
 *
 * A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking 
 * off the boundary of the grid.
 * 
 * Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 * Example 1  :
 * Input      : heights = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * Output     : [[0,0,0],[0,1,0],[0,0,0]]

 * Example 2  :
 * Input      : heights = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * Output     : [[0,0,0],[0,1,0],[1,2,1]]
 
 * https://leetcode.com/problems/number-of-enclaves/description/
*/

// ! Multi Source BFS

// ! Microsoft, Google, Amazon

#include <queue>
#include <vector>
#include <iostream>

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

// * check out of bound
bool check_not_oob(const int &row, const int &col, std::vector<std::vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  return row >= 0 && row < m && col >= 0 && col < n;
}

const std::vector<std::vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void mark_visited(
  int r, int c,
  std::vector<std::vector<bool>> &visited,
  std::vector<std::vector<int>> &grid)
{
  visited[r][c] = true;

  for (auto &dir : dirs) {
    int dr = r + dir[0], dc = c + dir[1];
    if (check_not_oob(dr, dc, grid) && !visited[dr][dc] && grid[dr][dc] == 1) {
      mark_visited(dr, dc, visited, grid);
    }
  }
}

void mark_visited(int r, int c, std::vector<std::vector<int>> &grid)
{
  grid[r][c] = 0;

  for (auto &dir : dirs) {
    int dr = r + dir[0], dc = c + dir[1];
    if (check_not_oob(dr, dc, grid) && grid[dr][dc] == 1) {
      mark_visited(dr, dc, grid);
    }
  }
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Mark All the islands from boundary as visited then count the remaining land area
// * use a visited matrix
// * TIME COMPLEXITY O(m x n)
// * SPACE COMPLEXITY O(m x n)
int numEnclaves(std::vector<std::vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

  for (int r = 0; r < m; ++r) {
    // * first column
    if (grid[r][0] == 1)
      mark_visited(r, 0, visited, grid);

    // * last column
    if (grid[r][n - 1] == 1)
      mark_visited(r, n - 1, visited, grid);
  }

  for (int c = 0; c < n; ++c) {
    // * first row
    if (grid[0][c] == 1)
      mark_visited(0, c, visited, grid);

    // * last row
    if (grid[m - 1][c] == 1)
      mark_visited(m - 1, c, visited, grid);
  }

  int ans = 0;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == 1 && !visited[r][c]) {
        ans++;
      }
    }
  }

  return ans;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Mark All the islands from boundary as visited then count the remaining land area
// * use a input matrix as visited
// * TIME COMPLEXITY O(m x n)
// * SPACE COMPLEXITY O(m x n)
int numEnclaves2(std::vector<std::vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  for (int r = 0; r < m; ++r) {
    // * first column
    if (grid[r][0] == 1)
      mark_visited(r, 0, grid);

    // * last column
    if (grid[r][n - 1] == 1)
      mark_visited(r, n - 1, grid);
  }

  for (int c = 0; c < n; ++c) {
    // * first row
    if (grid[0][c] == 1)
      mark_visited(0, c, grid);

    // * last row
    if (grid[m - 1][c] == 1)
      mark_visited(m - 1, c, grid);
  }

  int ans = 0;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == 1) {
        ans++;
      }
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};

  // * testcase 2
  // std::vector<std::vector<int>> grid = {{0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};

  // * testcase 3
  // std::vector<std::vector<int>> grid = {{0, 1, 1, 0, 0}};

  std::cout << "grid" << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  int ans = numEnclaves(grid);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 44-no-of-enclaves.cpp -o output && ./output

 