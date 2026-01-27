/**
 * * Leetcode - 1254
 * * Number of Closed Islands
 *
 * * Given a 2D grid consists of 0s (land) and 1s (water).  
 * * An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally 
 * * (all left, top, right, bottom) surrounded by 1s.
 * 
 * * Return the number of closed islands.

 * * Example 1  :
 * * Input      : grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 * * Output     : 2

 * * Example 2  :
 * * Input      : grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 * * Output     : 1
 * 
 * * https://leetcode.com/problems/number-of-closed-islands/description/
 * * https://www.geeksforgeeks.org/problems/find-number-of-closed-islands/1
*/

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

bool dfs(int r, int c,
         std::vector<std::vector<int>> &grid)
{
  int m = grid.size(), n = grid[0].size();

  if (r < 0 || r >= m || c < 0 || c >= n) // * out of bound
    return false; // * not closed

  if (grid[r][c] == 1) // * found water
    return true; // * closed

  grid[r][c] = 1; // * mark visited

  bool left_closed    = dfs(r, c - 1, grid);
  bool right_closed   = dfs(r, c + 1, grid);
  bool top_closed     = dfs(r - 1, c, grid);
  bool bottom_closed  = dfs(r + 1, c, grid);

  return left_closed && right_closed && top_closed && bottom_closed; 
}

// * ------------------------- Approach 1: Optimal -------------------------
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(1)
int closedIslandDFS(std::vector<std::vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();

  int closed_islands = 0;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == 0 && dfs(r, c, grid)) {
        closed_islands++;
      }
    }
  }

  return closed_islands;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> grid = {{1, 1, 1, 1, 1, 1, 1, 0},
  //                                       {1, 0, 0, 0, 0, 1, 1, 0},
  //                                       {1, 0, 1, 0, 1, 1, 1, 0},
  //                                       {1, 0, 0, 0, 0, 1, 0, 1},
  //                                       {1, 1, 1, 1, 1, 1, 1, 0}};

  // * testcase 2
  std::vector<std::vector<int>> grid = {{0, 0, 1, 0, 0},
                                        {0, 1, 0, 1, 0},
                                        {0, 1, 1, 1, 0}};

  // * testcase 3
  // std::vector<std::vector<int>> grid = {{1, 1, 1, 1, 1, 1, 1},
  //                                       {1, 0, 0, 0, 0, 0, 1},
  //                                       {1, 0, 1, 1, 1, 0, 1},
  //                                       {1, 0, 1, 0, 1, 0, 1},
  //                                       {1, 0, 1, 1, 1, 0, 1},
  //                                       {1, 0, 0, 0, 0, 0, 1},
  //                                       {1, 1, 1, 1, 1, 1, 1}};

  std::cout << "grid: " << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  int ans = closedIslandDFS(grid);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 10-no-of-Closed-Islands.cpp -o output && ./output