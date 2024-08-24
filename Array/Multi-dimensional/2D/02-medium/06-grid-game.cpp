/*
 * Grid Game
 *
 * The first robot wants to minimize the number of points collected by the second robot.
 * In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally,
 * return the number of points collected by the second robot.

 * Input1: grid = [[2,5,4],[1,5,1]]
 * Output: 4

 * https://leetcode.com/problems/grid-game/description/
*/

#include<iostream>


void printMatrix(std::vector<std::vector<int>> matrix) {
  int r = matrix.size(), c = matrix[0].size();
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

// * TIME COMPLEXITY O(C)
// * SPACE COMPLEXITY O(1)
long long gridGame(std::vector<std::vector<int>> &grid) {
  int c = grid[0].size();
  std::vector<int> row1Prefix = grid[0];   
  std::vector<int> row2Prefix = grid[1];

  // * calculate prefix sum
  long long top = grid[0][0], bottom = 0;
  for (int i = 1; i < c; ++i) {
    top += grid[0][i];
  }

  long long res = LONG_MAX;
  for (int i = 0; i < c; ++i) {
    top -= grid[0][i];
    // std::cout << top << " " << bottom << std::endl;
    long long secondBot = std::max(top, bottom);
    res = std::min(res, secondBot);

    bottom += grid[1][i];
  }
  return res;
}

int main() {
  std::vector<std::vector<int>> grid = {{2, 5, 4}, {1, 5, 1}};
  printMatrix(grid);
  long long ans = gridGame(grid);
  std::cout << ans << std::endl;
  return 0;
}

// * run the code 
// * g++ --std=c++17 06-grid-game.cpp -o output && ./output