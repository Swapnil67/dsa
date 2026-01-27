/*
 * Leetcode - 2658
 * Maximum Number of Fish in a Grid
 *
 * You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:
 * - A land cell if grid[r][c] = 0, or
 * - A water cell containing grid[r][c] fish, if grid[r][c] > 0.
 * 
 * A fisher can start at any water cell (r, c) and can do the following operations any number of times:
 * - Catch all the fish at cell (r, c), or
 * - Move to any adjacent water cell.
 * 
 * Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.
 * 
 * An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

 * * Example 1  :
 * * Input      : grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
 * * Output     : 7

 * * Example 2  :
 * * Input      : grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
 * * Output     : 1
 * 
 * https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/
*/

// ! Same as `Max Area of Island`

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

const std::vector<std::vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

// * Using visited matrix
void dfs(int r, int c, int &fishes,
         std::vector<std::vector<int>> &visited,
         std::vector<std::vector<int>> &grid)
{
  int m = grid.size(), n = grid[0].size();

  // * Edge case
  if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] ||
      grid[r][c] == 0) {
      return;
  }

  visited[r][c] = 1; // * mark visited

  fishes += grid[r][c]; // * add fishes

  for (auto &dir : dirs) { // * go to neighbours
    int n_r = r + dir[0];
    int n_c = c + dir[1];
    dfs(n_r, n_c, fishes, visited, grid);
  }
}

// * Using visited matrix
void dfs2(int r, int c, int &fishes,
          std::vector<std::vector<int>> &grid)
{
  int m = grid.size(), n = grid[0].size();

  // * Edge case
  const auto is_safe = [&](const int &row, const int &col) {
    return row >= 0 && row < m && col >= 0 && col < n;
  };

  fishes += grid[r][c]; // * add fishes

  grid[r][c] = 0; // * mark visited

  for (auto &dir : dirs) { // * go to neighbours
    int dr = r + dir[0], dc = c + dir[1];
    if (is_safe(dr, dc) && grid[dr][dc] > 0) {
      dfs2(dr, dc, fishes, grid);
    }
  }
}

// * ------------------------- Approach 1: Optimal -------------------------
// * Using visited vector
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n) + O(m + n)
int maxAreaOfIslandDFS(std::vector<std::vector<int>>& grid) {
  int m = grid.size(); 
  int n = grid[0].size(); 
  int max_area = 0;

  std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] != 0 && !visited[i][j]) {
        int cur_area = 0;
        dfs(i, j, cur_area, visited, grid);
        max_area = std::max(max_area, cur_area);
      }
    }
  }

  return max_area;
}

// * ------------------------- Approach 2: Optimal -------------------------
// * Using Grid as visited vector
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(1)
int maxAreaOfIslandDFS2(std::vector<std::vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  int max_area = 0;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] != 0) {
        int cur_area = 0;
        dfs2(i, j, cur_area, grid);
        max_area = std::max(max_area, cur_area);
      }
    }
  }

  return max_area;
}


int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> grid = {{0, 2, 1, 0}, {4, 0, 0, 3}, {1, 0, 0, 4}, {0, 3, 2, 0}};

  // * testcase 2
  std::vector<std::vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}};

  std::cout << "grid: " << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  // int ans = maxAreaOfIslandDFS(grid);
  int ans = maxAreaOfIslandDFS2(grid);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 23-max-no-of-fish-in-a-grid.cpp -o output && ./output