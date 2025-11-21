/*
 * Leetcode - 959
 * Regions Cut By Slashes
 * 
 * An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. 
 * These characters divide the square into contiguous regions.
 * 
 * Given the grid grid represented as a string array, return the number of regions.
 * 
 * Note that backslash characters are escaped, so a '\' is represented as '\\'.

 * Example 1  :
 * Input      : grid = [" /","/ "]
 * Output     : 2

 * Example 2  :
 * Input      : grid = [" /","  "]
 * Output     : 1
 
 * https://leetcode.com/problems/regions-cut-by-slashes/description/
*/

// ! Google

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

void dfs(int r, int c, std::vector<std::vector<int>> &grid) {
  grid[r][c] = 1;
  for (auto &dir: dirs) {
    int dr = r + dir[0];
    int dc = c + dir[1];
    if (check_not_oob(dr, dc, grid) && grid[dr][dc] == 0) {
      dfs(dr, dc, grid);
    }
  }
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(m x n)
// * SPACE COMPLEXITY O(m x n)
int regionsBySlashes(std::vector<std::string> &grid) {
  int n = grid.size();
  std::vector<std::vector<int>> matrix(n * 3, std::vector<int>(n * 3, 0));

  // * Create the matrix out of given string
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == '/') {
        matrix[r * 3][c * 3 + 2] = 1;
        matrix[r * 3 + 1][c * 3 + 1] = 1;
        matrix[r * 3 + 2][c * 3] = 1;
      }
      if (grid[r][c] == '\\') {
        matrix[r * 3][c * 3] = 1;
        matrix[r * 3 + 1][c * 3 + 1] = 1;
        matrix[r * 3 + 2][c * 3 + 2] = 1;
      }
    }
  }

  // * For Debugging
  for (auto &vec : matrix)
    printArr(vec);

  // * Same as no of islands
  int ans = 0;
  for (int r = 0; r < matrix.size(); ++r) {
    for (int c = 0; c < matrix[0].size(); ++c) {
      if (matrix[r][c] == 0) {
        dfs(r, c, matrix);
        ans++;
      }
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // std::vector<std::string> grid = {" /", "/ "};
  
  // * testcase 2
  // std::vector<std::string> grid = {" /", "  "};
  
  // * testcase 3
  std::vector<std::string> grid = {"/\\", "\\/"};

  std::cout << "grid ";
  printArr(grid);

  int ans = regionsBySlashes(grid);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 45-regions-cut-by-slashes.cpp -o output && ./output

 
/*
* Convert all the characters to respective matrix

* Space
* " " -> [
*           0 0 0
*           0 0 0
*           0 0 0
*        ]

* Forward Slash
* "/" -> [
*           0 0 1
*           0 1 0
*           1 0 0
*        ]

* Backward Slash
* "\\" -> [
*           1 0 0
*           0 1 0
*           0 0 1
*        ]

*/