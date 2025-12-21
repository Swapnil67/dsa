/*
 * Leetcode - 2812
 * Find the Safest Path in a Grid
 *
 * You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:
 * 
 * grid[r][c] = 1 (Thief Cell)
 * grid[r][c] = 0 (Empty Cell)
 * 
 * You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, 
 * including cells containing thieves.
 * 
 * The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the
 * path to any thief in the grid.
 * 
 * Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).
 * 
 * An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) 
 * if it exists.
 * 
 * The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, 
 * where |val| denotes the absolute value of val.

 * * Example 1  :
 * * Input      : grid = [[1,0,0],[0,0,0],[0,0,1]]
 * * Output     : 6

 * * Example 2  :
 * * Input      : grid = [[0,0,1],[0,0,0],[0,0,0]]
 * * Output     : 0

 * * Example 3  :
 * * Input      : grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
 * * Output     : 0
 * 
 * * https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/
*/

// ! Meta, Microsoft, Google, Apple, Amazon, Uber

#include <queue>
#include <vector>
#include <climits>
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

typedef std::pair<int, int> pii;

const std::vector<std::vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

// * check out of bound
bool check_not_oob(const int &row, const int &col, std::vector<std::vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  return row >= 0 && row < m && col >= 0 && col < n;
}

// * Multi Source BFS
// * We need to go to the cells where distance from thief is greater than on equal to min_dist (Safeness factor)
bool bfs(int &min_dist, std::vector<std::vector<int>> &dist) {
  int m = dist.size(), n = dist[0].size();
  if (dist[0][0] < min_dist) { // * Starting cell is not within the safeness factor
    return 0;
  }

  // * Classic BFS
  std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
  visited[0][0] = true;

  std::queue<std::pair<int, int>> q;
  q.push(std::make_pair(0, 0));

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    if (r == m - 1 && c == n - 1)
      return true;

    for (auto &dir: dirs) {
      int dr = r + dir[0], dc = c + dir[1];
      if (check_not_oob(dr, dc, dist) && !visited[dr][dc] && dist[dr][dc] >= min_dist) {
        visited[dr][dc] = true;
        q.push(std::make_pair(dr, dc));
      }
    }
  }

  return false;
}

// * We need to go to the cell where distance from thief is greater than on equal to min_dist (Safeness factor)
std::vector<std::vector<int>> distanceGrid(std::vector<std::vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();

  std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX));
  std::queue<pii> q;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == 1) { // * Found thief
        dist[r][c] = 0;
        q.push(std::make_pair(r, c));
      }
    }
  }

  while (!q.empty()) {
    int N = q.size();
    while (N--) {
      auto [r, c] = q.front();
      q.pop();

      for (auto &dir: dirs) {
        int dr = r + dir[0], dc = c + dir[1];
        if (check_not_oob(dr, dc, grid) && dist[dr][dc] == INT_MAX) {
          dist[dr][dc] = dist[r][c] + 1;
          q.push(std::make_pair(dr, dc));
        }
      }
    }
  }

  return dist;
}

// * ------------------------- Approach 1: Optimal -------------------------
// * Binary Search + Multi Source BFS
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n) + O(m + n)
int maximumSafenessFactor(std::vector<std::vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();

  // * Cannot reach destination
  if (grid[m - 1][n - 1] != 0) 
    return 0;

  // * 1. Precompute a distance grid
  std::vector<std::vector<int>> dist = distanceGrid(grid); // * (m x n)
  std::cout << "Distance: " << std::endl;
  for (auto &vec : dist)
    printArr(vec);

  // * 2. Binary Search on Answers
  int max_safe_factor = 0;
  int l = 1, r = 400; // * Upper bound is already defined
  while (l <= r) {
    int m = l + (r - l) / 2; // * current safeness factor
    bool ans = bfs(m, dist);
    // std::cout << m << "  " << ans << std::endl;
    if (ans) {
      l = m + 1;
      max_safe_factor = m;
    } else {
      r = m - 1;
    }
  }
  return max_safe_factor;
}

// * ------------------------- Approach 2: Optimal -------------------------
// * Multi Source BFS + Dijkstra's Algorithm
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n) + O(m + n)
int maximumSafenessFactorDij(std::vector<std::vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();

  // * Cannot reach destination
  if (grid[m - 1][n - 1] != 0) 
    return 0;

  // * 1. Precompute a distance grid (Multi Source BFS)
  std::vector<std::vector<int>> dist = distanceGrid(grid); // * (m x n)
  std::cout << "Distance: " << std::endl;
  for (auto &vec : dist)
    printArr(vec);

  // * 2. Dijkstra Algorithm
  std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
  visited[0][0] = true;

  std::priority_queue<std::vector<int>> max_heap;
  max_heap.push({dist[0][0], 0, 0});

  while (!max_heap.empty()) {
    std::vector<int> data = max_heap.top();
    max_heap.pop();
    int d = data[0], r = data[1], c = data[2];

    // * Reached destination
    if (r == m - 1 && c == n - 1)
      return d;

    for (auto &dir: dirs) { // * Go to neighbours
      int dr = r + dir[0], dc = c + dir[1];
      if (check_not_oob(dr, dc, grid) && !visited[dr][dc]) { 
        visited[dr][dc] = true;
        int min_dist = std::min(d, dist[dr][dc]);
        std::cout << "(" << dr << " " << dc << ") = " << min_dist << std::endl;
        max_heap.push({min_dist, dr, dc});
      }
    }
  }

  return 0;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};

  // * testcase 2
  std::vector<std::vector<int>> grid = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};

  // * testcase 3
  // std::vector<std::vector<int>> grid = {{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}};

  // * testcase 4
  // std::vector<std::vector<int>> grid = {{0, 1, 1}, {0, 1, 1}, {1, 1, 0}};

  std::cout << "grid: " << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  // int ans = maximumSafenessFactor(grid);
  int ans = maximumSafenessFactorDij(grid);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 05-find-the-safest-path-in-a-grid.cpp -o output && ./output