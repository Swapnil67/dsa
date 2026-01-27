/*
 * Leetcode - 2290
 * Minimum Obstacle Removal to Reach Corner
 *
 * You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:
 * - 0 represents an empty cell,
 * - 1 represents an obstacle that may be removed.
 * 
 * You can move up, down, left, or right from and to an empty cell.
 *
 * Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) 
 * to the lower right corner (m - 1, n - 1).
 * 
 * Example 1  :
 * Input      : grid = [[0,1,1],[1,1,0],[1,1,0]]
 * Output     : 2

 * Example 2  :
 * Input      : grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
 * Output     : 0
 * 
 * https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/
*/

// ! Meta, Google

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
int minimumObstaclesDij(std::vector<std::vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();

  // * Distance vector
  std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX));
  dist[0][0] = 0;

  // * Min heap = {weight, {r, c}}
  std::priority_queue<P, std::vector<P>, std::greater<>> min_heap;
  min_heap.push({grid[0][0], {0, 0}});

  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  while (!min_heap.empty()) {
    auto [d, p] = min_heap.top();
    min_heap.pop();

    auto [r, c] = p;
    for (auto &dir: dirs) {
      int dr = r + dir[0], dc = c + dir[1];

      if (is_safe(dr, dc)) {
        int wt = grid[dr][dc] == 1 ? 1 : 0;
        if (dist[dr][dc] > d + wt) {
          dist[dr][dc] = d + wt;
          min_heap.push({d + wt, {dr, dc}});
        }
      }
    }
  }

  return dist[m - 1][n - 1];
}

// * ------------------------- Approach 2: Optimal -------------------------
// * BFS
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n) 
int minimumObstaclesBFS(std::vector<std::vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();

  // * Distance vector
  std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX));
  dist[0][0] = 0;

  // * Min heap = { , {r, c}}
  std::queue<std::pair<int, int>> q;
  q.push({0, 0});

  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    for (auto &dir: dirs) {
      int dr = r + dir[0], dc = c + dir[1];
      
      if (is_safe(dr, dc)) {
        int wt = grid[dr][dc] == 1 ? 1 : 0;
        int new_wt = dist[r][c] + wt;
        // std::cout << "(" << dr << "," << dc << ")" << ": " << new_wt << std::endl;
        if (dist[dr][dc] > new_wt) {
          dist[dr][dc] = new_wt;
          q.push({dr, dc});
        }
      }
    }
    // std::cout << std::endl;
  }

  std::cout << "Distance: " << std::endl;
  for (auto &vec : dist)
    printArr(vec);

  return dist[m - 1][n - 1];
}


int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> grid = {{0, 1, 1}, {1, 1, 0}, {1, 1, 0}};

  // * testcase 2
  // std::vector<std::vector<int>> grid = {{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}};

  std::cout << "grid: " << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  // int ans = minimumObstaclesDij(grid);
  int ans = minimumObstaclesBFS(grid);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 04-min-obstacle-removal-to-reach-corner.cpp -o output && ./output