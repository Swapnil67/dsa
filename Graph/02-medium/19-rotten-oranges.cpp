/**
 * * Leetcode - 994
 * * Rotting Oranges
 *
 * * You are given an m x n grid where each cell can have one of three values:
 * * - 0 representing an empty cell,
 * * - 1 representing a fresh_oranges orange, or
 * * - 2 representing a rotten orange.
 *
 * * Every minute, any fresh_oranges orange that is 4-directionally adjacent to a rotten orange becomes rotten.

 * * Return the minimum number of minutes that must elapse until no cell has a fresh_oranges orange. If this is impossible, return -1.

 * * Example 1  :
 * * Input      : grid = [[2,1,1],[1,1,0],[0,1,1]]
 * * Output     : 4
 * 
 * * Example 2  :
 * * Input      : grid = [[2,1,1],[0,1,1],[1,0,1]]
 * * Output     : -1

 * * Example 2  :
 * * Input      : grid = [[0,2]]
 * * Output     : 0
 * 
 * * https://leetcode.com/problems/rotting-oranges/description/
 * * https://www.geeksforgeeks.org/problems/rotten-oranges2536/1
 * * https://www.naukri.com/code360/problems/rotting-oranges_701655
*/


// ! BFS - (Multi Source)

// ! Apple, Amazon, Microsoft

#include <queue>
#include <vector>
#include <iostream>

typedef std::vector<char> vc;

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

// * Print adjacency list
template <typename T>
void printAdjList(std::vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    std::cout << i << " -> ";
    printArr(adj[i]);
  }
}
const std::vector<std::vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

// * ------------------------- Approach 1: Optimal -------------------------
// * Multi Source BFS
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n) + O(m + n)
int orangesRotting(std::vector<std::vector<int>> &grid)
{
  int m = grid.size(), n = grid[0].size();
  std::queue<std::pair<int, int>> q;
  
  // * Add all the rotten oranges to queue
  int fresh_oranges = 0;
  for (int r = 0; r < grid.size(); r++) {
    for (int c = 0; c < grid[0].size(); c++) {
      if (grid[r][c] == 1) {
        fresh_oranges++;
      } else if (grid[r][c] == 2) {
        q.push({r, c});
      }
    }
  }

  // * There are no fresh oranges
  if (fresh_oranges == 0)
    return 0;

  // * Out of bound check
  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  int minutes = 0;
  while (fresh_oranges > 0 && !q.empty()) {
    int N = q.size();
    while (N--) {
      auto [r, c] = q.front();
      q.pop();

      for (auto &dir : dirs) {
        int nr = r + dir[0];
        int nc = c + dir[1];
        // * Make all the fresh_oranges oranges in neighbour rotten
        if (is_safe(nr, nc) && grid[nr][nc] == 1) {
          grid[nr][nc] = 2;
          q.push({nr, nc});
          fresh_oranges--;
        }
      }
    }
    minutes++;
  }

  return fresh_oranges == 0 ? minutes : -1;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

  // * testcase 2
  // std::vector<std::vector<int>> grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};

  std::cout << "grid: " << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  int ans = orangesRotting(grid);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 09-rotten-oranges.cpp -o output && ./output