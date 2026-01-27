/*
 * Leetcode - 2577
 * Minimum Time to Visit a Cell In a Grid
 *
 * You are given a m x n matrix grid consisting of non-negative integers where grid[row][col] represents
 * the minimum time required to be able to visit the cell (row, col), which means you can visit the cell (row, col)
 * only when the time you visit it is greater than or equal to grid[row][col].
 * 
 * You are standing in the top-left cell of the matrix in the 0th second, and you must move to any adjacent cell
 * in the four directions: up, down, left, and right. Each move you make takes 1 second.
 * 
 * Return the minimum time required in which you can visit the bottom-right cell of the matrix. 
 * If you cannot visit the bottom-right cell, then return -1.

 * Example 1  :
 * Input      : grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
 * Output     : 7

 * Example 2  :
 * Input      : grid = [[0,2,4],[3,2,1],[1,0,4]]
 * Output     : -1
 * 
 * https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/
*/

// ! Microsoft, Google

#include <queue>
#include <vector>
#include <climits>
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
typedef std::pair<int, std::pair<int, int>> P;

// * ------------------------- Approach 1: Optimal -------------------------
// * Dijkstra's Algorithm
// * TIME COMPLEXITY O(m * n log(m * n))
// * SPACE COMPLEXITY O(m * n)
int minimumTime(std::vector<std::vector<int>> &grid)
{
  int m = grid.size(), n = grid[0].size();
  if (grid[0][1] > grid[0][0] + 1 && grid[1][0] > grid[0][0] + 1)
    return -1;

  std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
  std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX));
  dist[0][0] = 0;

  // * Min heap = {time, {r, c}}
  std::priority_queue<P, std::vector<P>, std::greater<>> min_heap;
  min_heap.push({grid[0][0], {0, 0}});

  // * Out of bound check
  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  while (!min_heap.empty()) {
    auto [t, p] = min_heap.top();
    min_heap.pop();

    auto [r, c] = p;
    if (r == m - 1 && c == n - 1)
      return dist[m - 1][n - 1];

    if (visited[r][c])
      continue;
    visited[r][c] = true;

    for (auto &dir : dirs) {
      int dr = r + dir[0], dc = c + dir[1];
      if (is_safe(dr, dc) && !visited[dr][dc]) {
        int new_time;
        if (t + 1 >= grid[dr][dc]) {
          new_time = t + 1;
        }
        else {
          int extra_time = grid[dr][dc] - t;
          new_time = grid[dr][dc];
          if (extra_time % 2 == 0) {
            new_time = grid[dr][dc] + 1;
          }
        }
        dist[dr][dc] = new_time;
        min_heap.push({new_time, {dr, dc}});
      }
    }
  }

  return -1;
}

// * ------------------------- Approach 1: Optimal -------------------------
// * Dijkstra's Algorithm (without dist matrix)
// * TIME COMPLEXITY O(m * n log(m * n))
// * SPACE COMPLEXITY O(m * n)
int minimumTime2(std::vector<std::vector<int>> &grid)
{
  int m = grid.size(), n = grid[0].size();
  if (grid[0][1] > grid[0][0] + 1 && grid[1][0] > grid[0][0] + 1)
    return -1;

  std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

  // * Min heap = {time, {r, c}}
  std::priority_queue<P, std::vector<P>, std::greater<>> min_heap;
  min_heap.push({grid[0][0], {0, 0}});

  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  while (!min_heap.empty())
  {
    auto [t, p] = min_heap.top();
    min_heap.pop();

    auto [r, c] = p;
    if (r == m - 1 && c == n - 1)
      return t;

    if (visited[r][c])
      continue;
    visited[r][c] = true;

    for (auto &dir : dirs) {
      int dr = r + dir[0], dc = c + dir[1];
      if (is_safe(dr, dc) && !visited[dr][dc]) {
        int new_time;
        if (t + 1 >= grid[dr][dc]) {
          new_time = t + 1;
        }
        else {
          int extra_time = grid[dr][dc] - t;
          new_time = grid[dr][dc];
          if (extra_time % 2 == 0) {
            new_time = grid[dr][dc] + 1;
          }
        }
        min_heap.push({new_time, {dr, dc}});
      }
    }
  }

  return -1;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> grid = {{0, 1, 3, 2}, {5, 1, 2, 5}, {4, 3, 8, 6}};

  // * testcase 2
  // std::vector<std::vector<int>> grid = {{0, 2, 4}, {3, 2, 1}, {1, 0, 4}};

  std::cout << "grid: " << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  int ans = minimumTime(grid);
  // int ans = minimumTime2(grid);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 05-min-time-to-visit-a-cell-in-a-grid.cpp -o output && ./output