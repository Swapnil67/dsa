/*
 * Leetcode - 1765
 * Map of Highest Peak
 * 
 * You are given an integer matrix isWater of size m x n that represents a map of land and water cells.
 * - If isWater[i][j] == 0, cell (i, j) is a land cell.
 * - If isWater[i][j] == 1, cell (i, j) is a water cell.
 * 
 * You must assign each cell a height in a way that follows these rules:
 * - The height of each cell must be non-negative.
 * - If the cell is a water cell, its height must be 0.
 * - Any two adjacent cells must have an absolute height difference of at most 1. 
 *   A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter 
 *   (i.e., their sides are touching).
 * 
 * Find an assignment of heights such that the maximum height in the matrix is maximized.
 * 
 * Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. 
 * If there are multiple solutions, return any of them.

 * Example 1  :
 * Input      : isWater = [[0,1],[0,0]]
 * Output     : [[1,0],[2,1]]

 * Example 2  :
 * Input      : isWater = [[0,0,1],[1,0,0],[0,0,0]]
 * Output     : [[1,1,0],[0,1,1],[1,2,2]]

 * https://leetcode.com/problems/map-of-highest-peak/description/
*/

// ! Multi Source BFS

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

// * ------------------------- APPROACH 1: Brute Force Approach -------------------------`
// * Go to every co-ordinate of 0 and do BFS from that position and find distance
// * Just explain this don't code

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Find the distance from 0s to 1s instead of 1s to 0s
// * TIME COMPLEXITY O(m x n)
// * SPACE COMPLEXITY O(m x n)
std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& mat) {
  int m = mat.size(), n = mat[0].size();
  std::vector<std::vector<int>> result(m, std::vector<int>(n, -1));
  std::queue<std::pair<int, int>> q;

  // * push all the co-ordinates which has element 0 to `q`
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (mat[r][c] == 1) {
        result[r][c] = 0;
        q.push({r, c});
      }
    }
  }

  // * To check out of boundary
  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  // * Classic BFS
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    // * Go to adjacent cells
    for (auto &dir: dirs) {
      int n_r = r + dir[0];
      int n_c = c + dir[1];
      if (is_safe(n_r, n_c) && result[n_r][n_c] == -1) {
          result[n_r][n_c] = result[r][c] + 1;
          q.push({n_r, n_c});
      }
    }
  }

  return result;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> isWater = {{0, 1}, {0, 0}};

  // * testcase 2
  std::vector<std::vector<int>> isWater = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};

  std::cout << "isWater" << std::endl;
  for (auto &vec : isWater)
    printArr(vec);

  std::vector<std::vector<int>> ans = highestPeak(isWater);
  std::cout << "Answer: " << std::endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 26-map-of-highest-peak.cpp -o output && ./output

 