/*
 * Leetcode - 1905
 * Count Sub Islands
 * 
 * You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's 
 * (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). 
 * Any cells outside of the grid are considered water cells.
 * 
 * An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells
 * that make up this island in grid2.
 * 
 * Return the number of islands in grid2 that are considered sub-islands.
 * 
 * Example 1:
 * Input     : grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], 
 *             grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
 * Output    : 3
 * 
 * Example 1:
 * Input     : grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]],
 *             grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
 * Output    : 2

 * https://leetcode.com/problems/count-sub-islands/description/
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

const std::vector<std::vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool dfs(
    int r, int c,
    std::vector<std::vector<int>> &grid1,
    std::vector<std::vector<int>> &grid2)
{
  int m = grid1.size(), n = grid1[0].size();;
  if (r < 0 || r >= m || c < 0 || c >= n || grid2[r][c] == 0)
    return true;

  grid2[r][c] = 0; // * mark visited by making the cell water

  bool res = (grid1[r][c] == 1);      // * grid1 cell should also be land
  res &= dfs(r, c - 1, grid1, grid2);
  res &= dfs(r, c + 1, grid1, grid2);
  res &= dfs(r - 1, c, grid1, grid2);
  res &= dfs(r + 1, c, grid1, grid2);

  return res;
}

bool bfs(
    int row, int col,
    std::vector<std::vector<int>> &grid1,
    std::vector<std::vector<int>> &grid2)
{
  int m = grid1.size(), n = grid1[0].size();

  // * check out of bound
  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  std::queue<std::pair<int, int>> q;
  q.push({row, col});
  grid2[row][col] = 0; // * mark visited by making the cell water
  
  int res = true;
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    // * We are not returning from here because we need to mark all possible land from 
    // * from this bfs as visited so that it won't come in next loop.
    if (grid1[r][c] == 0) // * grid1 cell should also be land
      res = false;

    // * Visit the ngbr
    for (auto &dir: dirs) {
      int dr = r + dir[0], dc = c + dir[1];
      if (is_safe(dr, dc) && grid2[dr][dc] == 1) { // * traverse grid2 cells
        grid2[dr][dc] = 0; // * mark visited by making the cell water
        q.push({dr, dc});
      }
    }
  }

  return res;
}

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * DFS
// * TIME COMPLEXITY O(m x n)
// * SPACE COMPLEXITY O(m x n)
int countSubIslandsDFS(std::vector<std::vector<int>> &grid1, std::vector<std::vector<int>> &grid2) {
  int m = grid2.size(), n = grid2[0].size();
  
  int sub_islands = 0;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid2[r][c] == 1) {
        sub_islands += dfs(r, c, grid1, grid2);
      }
    }
  }

  return sub_islands;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * BFS
// * TIME COMPLEXITY O(m x n)
// * SPACE COMPLEXITY O(m x n)
int countSubIslandsBFS(std::vector<std::vector<int>> &grid1, std::vector<std::vector<int>> &grid2) {
  int m = grid2.size(), n = grid2[0].size();
  
  int sub_islands = 0;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid2[r][c] == 1) {
        if (bfs(r, c, grid1, grid2))
          sub_islands++;
      }
    }
  }

  return sub_islands;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> grid1 = {{1, 1, 1, 0, 0}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 1, 1}},
  //                               grid2 = {{1, 1, 1, 0, 0}, {0, 0, 1, 1, 1}, {0, 1, 0, 0, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}};

  // * testcase 2
  std::vector<std::vector<int>> grid1 = {{1, 0, 1, 0, 1},
                                         {1, 1, 1, 1, 1},
                                         {0, 0, 0, 0, 0},
                                         {1, 1, 1, 1, 1},
                                         {1, 0, 1, 0, 1}},
                                         
                                grid2 = {{0, 0, 0, 0, 0},
                                         {1, 1, 1, 1, 1},
                                         {0, 1, 0, 1, 0},
                                         {0, 1, 0, 1, 0},
                                         {1, 0, 0, 0, 1}};

  std::cout << "-------- Grid 1 -------- " << std::endl;
  for (auto &vec : grid1)
    printArr(vec);

  std::cout << "-------- Grid 2 -------- " << std::endl;
  for (auto &vec : grid2)
    printArr(vec);

  // int sub_islands = countSubIslandsDFS(grid1, grid2);
  int sub_islands = countSubIslandsBFS(grid1, grid2);
  std::cout << "Sub Islands: " << sub_islands << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 28-count-sub-islands.cpp -o output && ./output

 