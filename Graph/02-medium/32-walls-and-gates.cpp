/*
 * Leetcode - 286
 * Walls And Gates
 * 
 * You are given a m×n 2D grid initialized with these three possible values:
 * -> -1 - A water cell that can not be traversed.
 * -> 0 - A treasure chest.
 * -> INF - A land cell that can be traversed. We use the integer 2^31 - 1 = 2147483647 to represent INF.

 * Fill each land cell with the distance to its nearest treasure chest.
 * If a land cell cannot reach a treasure chest then the value should remain INF.
 * 
 * Assume the grid can only be traversed up, down, left, or right.
 * Modify the grid in-place.

 * Example 1:
 * Input     : board = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
 * Output    : [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
 * 
 * Example 2:
 * Input     : board = [[0,-1],[2147483647,2147483647]]
 * Output    : [[0,-1],[1,2]]

 * https://leetcode.com/problems/walls-and-gates/description/
 * https://www.naukri.com/code360/problems/walls-and-gates_1092887
*/

#include <queue>
#include <vector>
#include <iostream>

// ! Multi Source BFS

// ! Uber, Meta, Amazon

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


// * ------------------------- APPROACH : Optimal Approach -------------------------`
// * Multi Source BFS
// * TIME COMPLEXITY O(m x n)
// * SPACE COMPLEXITY O(m x n)
void islandsAndTreasure(std::vector<std::vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  std::queue<std::pair<int, int>> q;

  // * push all the treasure into queue
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == 0) {
        q.push({r, c});
      }
    }
  }
  // std::cout << q.size() << std::endl;

  // * Out of bound check
  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  while (!q.empty()) {
    int N = q.size();
    while (N--) {
      auto [r, c] = q.front();
      q.pop();

      for (auto &dir: dirs)  {
        int dr = r + dir[0], dc = c + dir[1];
        if (is_safe(dr, dc) && grid[dr][dc] == 2147483647) {
          grid[dr][dc] = grid[r][c] + 1;
          q.push({dr, dc});
        }
      }
    }
  }
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> grid = {
      {2147483647, -1, 0, 2147483647},
      {2147483647, 2147483647, 2147483647, -1},
      {2147483647, -1, 2147483647, -1},
      {0, -1, 2147483647, 2147483647}};

  std::cout << "-------- Grid Before -------- " << std::endl;
  for (auto &vec : grid)
  printArr(vec);
  
  std::cout << "-------- Grid After -------- " << std::endl;
  islandsAndTreasure(grid);
  for (auto &vec : grid)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 32-walls-and-gates.cpp -o output && ./output

 