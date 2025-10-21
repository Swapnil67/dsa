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
*/

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

void dfs(int x, int y, int &area,
         std::vector<std::vector<int>> &visited,
         std::vector<std::vector<int>> &grid)
{
  int m = grid.size(); 
  int n = grid[0].size(); 

  // * Edge cases
  if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || visited[x][y]) {
    return;
  }

  visited[x][y] = 1;

  if (grid[x][y] == 1)
    area++;

  for (auto &dir : dirs) {
    int new_x = x + dir[0]; 
    int new_y = y + dir[1];
    dfs(new_x, new_y, area, visited, grid);
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
  int m = grid.size(); 
  int n = grid[0].size(); 

  std::queue<std::pair<int, int>> q;
  q.push({x, y});
  visited[x][y] = 1;
  int area = 1;

  while (!q.empty()) {
    auto p = q.front();
    q.pop();

    int row = p.first, col = p.second;

    // * Traverse in neighbours and mark them it it's a land
    for (auto &dir : dirs) {
      int nx = row + dir[0];
      int ny = col + dir[1];

      if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0) {
        continue;
      }

      if (!visited[nx][ny]) {
        visited[nx][ny] = 1;
        q.push({nx, ny});
        area++;
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

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1 && !visited[i][j]) {
        int cur_area = bfs(i, j, visited, grid);
        max_area = std::max(max_area, cur_area);
      }
    }
  }

  return max_area;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

  // * testcase 2
  // std::vector<std::vector<int>> grid = {{0, 0, 0, 0, 0, 0, 0, 0}};

  // * testcase 3
  std::vector<std::vector<int>> grid = {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};

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