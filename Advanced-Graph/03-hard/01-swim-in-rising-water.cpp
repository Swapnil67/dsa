/*
 * Leetcode - 778
 * Swim in Rising Water
 *
 * You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
 * 
 * It starts raining, and water gradually rises over time. At time t, the water level is t, 
 * meaning any cell with elevation less than equal to t is submerged or reachable.
 * 
 * You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both
 * squares individually are at most t. You can swim infinite distances in zero time. 
 * Of course, you must stay within the boundaries of the grid during your swim.
 *
 * Return the minimum time until you can reach the bottom right square (n - 1, n - 1) 
 * if you start at the top left square (0, 0).
 * 
 * Example 1  :
 * Input      : grid = [[0,2],[1,3]]
 * Output     : 3

 * Example 2  :
 * Input      : grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
 * Output     : 16
 * 
 * https://leetcode.com/problems/swim-in-rising-water/
*/

// ! Meta, Microsoft, Google, Amazon, Uber

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

bool dfs(
    int t, int r, int c,
    std::vector<std::vector<bool>> &visited,
    std::vector<std::vector<int>> &grid)
{
  int n = grid.size();
  // * out of bound check
  if (r < 0 || r >= n || c < 0 || c >= n || visited[r][c] || grid[r][c] > t) {
    return false;
  }

  // * Reached bottom right cell
  if (r == n - 1 && c == n - 1)
    return true;

  visited[r][c] = true;

  return dfs(t, r - 1, c, visited, grid) ||
         dfs(t, r + 1, c, visited, grid) ||
         dfs(t, r, c - 1, visited, grid) ||
         dfs(t, r, c + 1, visited, grid);
}


// * ------------------------- Approach 1: Optimal -------------------------
// * Dijkstra's Algorithm
// * Find the path with min cost to reach the grid[m][n] and return the largest cell in that path.
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n) + O(m + n)
int swimInWater(std::vector<std::vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();

  // * Matrix to mark a cell visited
  std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
  visited[0][0] = true;

  // * Min Heap {height, {r, c}}
  std::priority_queue<P, std::vector<P>, std::greater<>> min_heap;
  min_heap.push({grid[0][0], {0, 0}});

  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  int min_dist = INT_MIN;
  while (!min_heap.empty()) {
    auto [height, p] = min_heap.top();
    min_heap.pop();
    auto [r, c] = p;

    min_dist = std::max(min_dist, height);

    // * Reached bottom right cell
    if (r == m - 1 && c == n - 1) {
      return min_dist;
    }

    // * Go to it's neighbours
    for (auto &dir: dirs) {
      int dr = r + dir[0], dc = c + dir[1];
      if (is_safe(dr, dc) && !visited[dr][dc]) {
        visited[dr][dc] = true;
        min_heap.push({grid[dr][dc], {dr, dc}});
      }
    }
  }

  return min_dist;
}

// * ------------------------- Approach 1: Optimal -------------------------
// * Binary Search + DFS
// * Find the path with min cost to reach the grid[m][n] and return the largest cell in that path.
// * Also sounds like maximize the minimum
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n) + O(m + n)
int swimInWater2(std::vector<std::vector<int>>& grid) {
  int n = grid.size();

  // * Matrix to mark a cell visited
  std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

  int l = 0, r = (n * n) - 1;
  while (l < r) {
    int m = l + (r - l) / 2;

    // * check can we reach grid[n][n] using time = m;
    bool ans = dfs(m, 0, 0, visited, grid);
    // std::cout << "t: " << m << ", ans: " << ans << std::endl;

    if (ans) { // * if yes then we need less time
      r = m;
    } else {   // * if not then we need more time
      l = m + 1;
    }

    // * Reset the visited vec
    for (int r = 0; r < n; ++r) {
      std::fill(begin(visited[r]), end(visited[r]), false);
    }
  }

  return r;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> grid = {{0, 2}, {1, 3}};

  // * testcase 2
  // std::vector<std::vector<int>> grid = {{0, 1, 3}, {2, 4, 1}, {1, 2, 1}};

  // * testcase 3
  // std::vector<std::vector<int>> grid = {{0, 1, 2, 3, 4},
  //                                       {24, 23, 22, 21, 5},
  //                                       {12, 13, 14, 15, 16},
  //                                       {11, 17, 18, 19, 20},
  //                                       {10, 9, 8, 7, 6}};

  // * testcase 4
  std::vector<std::vector<int>> grid = {{0, 3}, {1, 2}};

  std::cout << "grid: " << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  // int ans = swimInWater(grid);
  int ans = swimInWater2(grid);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-swim-in-rising-water.cpp -o output && ./output