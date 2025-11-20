/*
 * Leetcode - 934
 * Shortest Bridge
 * 
 * You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
 * An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
 *
 * You may change 0's to 1's to connect the two islands to form one island.
 * Return the smallest number of 0's you must flip to connect the two islands.

 * Example 1:
 * Input     : grid = [[0,1],[1,0]]
 * Output    : 1
 * 
 * Example 2:
 * Input     : grid = [[0,1,0],[0,0,0],[0,0,1]]
 * Output    : 2
 * 
 * Example 3:
 * Input     : grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * Output    : 1

 * https://leetcode.com/problems/shortest-bridge/description/
 * https://www.naukri.com/code360/problems/shortest-bridge_1105571
*/

#include <queue>
#include <vector>
#include <iostream>

// ! DFS + BFS 
// ! Microsoft, Meta, Uber, Google

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

// * check out of bound
bool check_oob(int n, const int &row, const int &col) {
  return row >= 0 && row < n && col >= 0 && col < n;
};

void dfs(int r, int c,
         std::queue<std::pair<int, int>> &q,
         std::vector<std::vector<bool>> &visited,
         std::vector<std::vector<int>> &grid)
{
  int n = grid.size(); // * rows == cols
  visited[r][c] = true; // * mark visited
  q.push({r, c});

  // * go in all 4 directions
  for (auto &dir : dirs) {
    int dr = r + dir[0], dc = c + dir[1];
    if (check_oob(n, dr, dc) && !visited[dr][dc] && grid[dr][dc] == 1) {
      dfs(dr, dc, q, visited, grid);
    }
  }
}

// * ------------------------- APPROACH : Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n x n)
// * SPACE COMPLEXITY O(n x n)
int shortestBridge(std::vector<std::vector<int>>& grid) {
  int n = grid.size(); // * rows == cols
  std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

  std::queue<std::pair<int, int>> q;

  // * Do DFS on 1st Island
  bool found = false;
  for (int r = 0; r < n; ++r) {
    if (found)
      break;
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == 1) {
        dfs(r, c, q, visited, grid);
        found = true;
        break;
      }
    }
  }

  // * For Debugging
  // while (!q.empty()) {
  //   auto p = q.front();
  //   std::cout << "(" << p.first << " " << p.second << ")" << std::endl;
  //   q.pop();
  // }

  // * From all the nodes of 1st island do BSF to 2nd Island
  int min_dist = 0;
  while (!q.empty()) {
    int N = q.size();
    while (N--) {
      auto [r, c] = q.front();
      q.pop();

      for (auto &dir: dirs) {
        int dr = r + dir[0], dc = c + dir[1];
        if (check_oob(n, dr, dc) && !visited[dr][dc]) {
          if (grid[dr][dc] == 1) {
            return min_dist;
          }
          q.push({dr, dc});
          visited[dr][dc] = true;
        }
      }
    }
    min_dist++;
  }

  // std::cout << std::endl;
  // for (auto &vec : visited)
  //   printArr(vec);

  return min_dist;
}

int main(void) {
  // * testcase 1 // * Ans = 1
  // std::vector<std::vector<int>> grid = {{0, 1}, {1, 0}};

  // * testcase 2 // * Ans = 2
  // std::vector<std::vector<int>> grid = {{0, 1, 0},
  //                                       {0, 0, 0},
  //                                       {0, 0, 1}};

  // * testcase 3 // * Ans = 1
  // std::vector<std::vector<int>> grid = {{1, 1, 1, 1, 1},
  //                                       {1, 0, 0, 0, 1},
  //                                       {1, 0, 1, 0, 1},
  //                                       {1, 0, 0, 0, 1},
  //                                       {1, 1, 1, 1, 1}};

  // * testcase 3 // * Ans = 1
  std::vector<std::vector<int>> grid = {{0, 0, 1, 0, 1},
                                        {0, 1, 1, 0, 1},
                                        {0, 1, 0, 0, 1},
                                        {0, 0, 0, 0, 0},
                                        {0, 0, 0, 0, 0}};

  std::cout << "-------- Board -------- " << std::endl;
  for (auto &vec : grid)
    printArr(vec);
  
  int steps = shortestBridge(grid);
  std::cout << "Steps: " << steps << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 38-shortest-bridge.cpp -o output && ./output

 