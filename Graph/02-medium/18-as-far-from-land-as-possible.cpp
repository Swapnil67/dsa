/*
 * Leetcode - 1162
 * As Far from Land as Possible
 * 
 * Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, 
 * find a water cell such that its distance to the nearest land cell is maximized, and return the distance. 
 * If no land or water exists in the grid, return -1.
 * 
 * The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) 
 * is |x0 - x1| + |y0 - y1|.
 * 
 * Example 1  :
 * Input      : grid = [[1,0,1],[0,0,0],[1,0,1]]
 * Output     : 2

 * Example 2  :
 * Input      : grid = [[1,0,0],[0,0,0],[0,0,0]]
 * Output     : 4

 * https://leetcode.com/problems/01-matrix/description/
 * https://www.naukri.com/code360/problems/distance-of-nearest-cell-having-1-in-a-binary-matrix_1169913
 * https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
*/

// ! BFS

// ! Google, Amazon

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>

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

int maxDistance(std::vector<std::vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();

  std::queue<std::pair<int, int>> q;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == 1) {
        q.push({r, c});
      }
    }
  }

  int res = -1;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    res = grid[x][y];

    for (auto &dir : dirs) {
      int dx = x + dir[0], dy = y + dir[1];
      if (dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy] == 0) {
        grid[dx][dy] = grid[x][y] + 1;
        q.push({dx, dy});
      } 
    }
  }

  // * For debugging
  // std::cout << "Distance Grid" << std::endl;
  // for (auto &vec : grid)
  //   printArr(vec);

  return res > 1 ? res - 1 : -1;
}

int maxDistance2(std::vector<std::vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();

  std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
  std::queue<std::pair<int, int>> q;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == 1) {
        visited[r][c] = true;
        q.push({r, c});
      }
    }
  }

  const auto is_safe = [&](const int &x, const int &y) {
    return x >= 0 && x < m && y >= 0 && y < n;
  };

  int res = -1;
  while (!q.empty()) {
    int N = q.size();
    while (N--) {
      auto [x, y] = q.front();
      q.pop();
      res = grid[x][y];
    
      for (auto &dir : dirs) {
        int dx = x + dir[0], dy = y + dir[1];
        if (is_safe(dx, dy) && grid[dx][dy] == 0) {
          grid[dx][dy] = grid[x][y] + 1;
          q.push({dx, dy});
        } 
      }
    }

  }

  // * For debugging
  // std::cout << "Distance Grid" << std::endl;
  // for (auto &vec : grid)
  //   printArr(vec);

  return res > 1 ? res - 1 : -1;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> grid = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};

  // * testcase 2
  std::vector<std::vector<int>> grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  std::cout << "grid" << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  int ans = maxDistance(grid);
  std::cout << "Max Distance: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 18-as-far-from-land-as-possible.cpp -o output && ./output

 