/**
 * * Leetcode - 695
 * * Max Area of Island
 *
 * * You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

 * * The area of an island is the number of cells with a value 1 in the island.
 * * Return the maximum area of an island in grid. If there is no island, return 0.

 * * Example 1  :
 * * Input      : grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * *                      [0,0,0,0,0,0,0,1,1,1,0,0,0], [0,1,1,0,1,0,0,0,0,0,0,0,0],
 * *                      [0,1,0,0,1,1,0,0,1,0,1,0,0], [0,1,0,0,1,1,0,0,1,1,1,0,0],
 *  *                     [0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * * Output     : 6

 * * Example 2  :
 * * Input      : grid = [[0,0,0,0,0,0,0,0]]
 * * Output     : 0
 * 
 * * https://leetcode.com/problems/max-area-of-island/description/
 * * https://www.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1
*/

// ! Meta, Microsoft, Google, Apple, Amazon, Uber

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
void dfs(int r, int c, int &area,
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

  if (grid[r][c] == 1) // * add to current area
      area += 1;

  for (auto &dir : dirs) { // * go to neighbours
    int n_r = r + dir[0];
    int n_c = c + dir[1];
    dfs(n_r, n_c, area, visited, grid);
  }
}

// * Using grid as matrix
void dfs2(int r, int c, int &area,
         std::vector<std::vector<int>> &visited,
         std::vector<std::vector<int>> &grid)
{
  int m = grid.size(), n = grid[0].size();

  // * Edge case
  if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
      return;
  }

  grid[r][c] = 0; // * mark visited

  if (grid[r][c] == 1) // * add to current area
      area += 1;

  for (auto &dir : dirs) { // * go to neighbours
    int n_r = r + dir[0];
    int n_c = c + dir[1];
    dfs2(n_r, n_c, area, visited, grid);
  }
}

// * ------------------------- Approach 1: Optimal -------------------------
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n) + O(m + n)
int maxAreaOfIslandDFS(std::vector<std::vector<int>>& grid) {
  int m = grid.size(); 
  int n = grid[0].size(); 
  int max_area = 0;

  std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1 && !visited[i][j]) {
        int cur_area = 0;
        dfs(i, j, cur_area, visited, grid);
        max_area = std::max(max_area, cur_area);
      }
    }
  }

  return max_area;
}

int bfs(int x, int y, std::vector<std::vector<int>> &visited, std::vector<std::vector<int>> &grid)
{
  int m = grid.size(), n = grid[0].size();

  std::queue<std::pair<int, int>> q;
  q.push({x, y});
  int area = 0;

  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    area++;
    visited[r][c] = 1;

    // * Traverse in neighbours and mark them it it's a land
    for (auto &dir : dirs) {
      int nx = r + dir[0], ny = c + dir[1];
      if (is_safe(nx, ny) && grid[nx][ny] == 1 && !visited[nx][ny]) {
        q.push({nx, ny});
      }
    }
  }

  return area;
}

// * ------------------------- Approach 2: Optimal -------------------------
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n) + O(m + n)
int maxAreaOfIslandBFS(std::vector<std::vector<int>> &grid) {
  int m = grid.size(); 
  int n = grid[0].size(); 
  int max_area = 0;

  std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));

  // * Loop over grid and do BFS on islands
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == 1 && !visited[r][c]) {
        int cur_area = bfs(r, c, visited, grid);
        max_area = std::max(max_area, cur_area);
      }
    }
  }

  return max_area;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

  // * testcase 2
  // std::vector<std::vector<int>> grid = {{0, 0, 0, 0, 0, 0, 0, 0}};

  // * testcase 3
  // std::vector<std::vector<int>> grid = {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};

  std::cout << "grid: " << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  // int ans = maxAreaOfIslandDFS(grid);
  int ans = maxAreaOfIslandBFS(grid);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 09-max-area-of-Island.cpp -o output && ./output