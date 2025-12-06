/*
 * Leetcode - 1091
 * Shortest Path in Binary Matrix
 *
 * Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix.
 * If there is no clear path, return -1.
 *
 * A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell
 * (i.e., (n - 1, n - 1)) such that:
 *
 * - All the visited cells of the path are 0.
 * - All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
 *
 * The length of a clear path is the number of visited cells of this path.

 * Example 1  :
 * Input      : grid = [[0,1],[1,0]]
 * Output     : 2

 * Example 2  :
 * Input      : grid = [[0,0,0],[1,1,0],[1,1,0]]
 * Output     : 4

 * Example 3  :
 * Input      : grid = [[1,0,0],[1,1,0],[1,1,0]]
 * Output     : -1

 * https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
 * https://www.naukri.com/code360/problems/shortest-path-in-a-binary-matrix_699835
*/

// ! BFS

// ! Amazon

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>

template <typename T>
void printArr(std::vector<T> &arr)
{
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i)
  {
    std::cout << arr[i] << " ";
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}
const std::vector<std::vector<int>> dirs = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// ! use this more optimal & easy
// * Using BFS
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int shortestPathBinaryMatrixBFS(std::vector<std::vector<int>> &grid)
{
  int m = grid.size(), n = grid[0].size();
  if (m == 0 || n == 0 || grid[0][0] != 0) // * Edge cases
    return -1;

  std::queue<std::pair<int, int>> q;
  q.push({0, 0}); // * starting position
  grid[0][0] = 1; // * we'll use inupt matrix as visited matrix

  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  int level = 1;
  // * Classic BFS
  while (!q.empty()) {
    int N = q.size();

    // * Loop over current level
    while (N--) {
      auto [r, c] = q.front();
      q.pop();

      // * reached grid[m-1][n-1]
      if (r == m - 1 && c == n - 1)
        return level;

      // * Push all directions into queue
      for (auto &dir : dirs) {
        int dr = r + dir[0], dc = c + dir[1];
        if (is_safe(dr, dc) && grid[dr][dc] == 0) {
          grid[dr][dc] = 1;
          q.push({dr, dc});
        }
      }
    }
    level++;
  }

  return -1;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using Dijkstra's Algorithm
// * v = no of vertices
// * e = no of edges
// * TIME COMPLEXITY O(E * Log(V))
// * SPACE COMPLEXITY O(E + V)
int shortestPathBinaryMatrixDij(std::vector<std::vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();
  if (m == 0 || n == 0 || grid[0][0] != 0)
    return -1;

  auto is_safe = [&](const int &r, const int &c)
  {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  grid[0][0] = 1; // * mark visited

  // * distance matrix
  std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX));
  dist[0][0] = 0; // * Initial distance

  // * min heap = {distance, {x, y}}
  typedef std::pair<int, std::pair<int, int>> P;
  std::priority_queue<P, std::vector<P>, std::greater<>> min_heap;
  min_heap.push({0, {0, 0}}); // * initial source

  while (!min_heap.empty())
  {
    auto p = min_heap.top();
    int d = p.first;        // * distance
    auto [r, c] = p.second; // * (x, y) co-ordinate
    min_heap.pop();

    int w = d + 1;
    for (auto &dir : dirs)
    {
      int dr = r + dir[0], dc = c + dir[1];
      // std::cout << d << " -> " << dr << " " << dc << std::endl;
      if (is_safe(dr, dc) && grid[dr][dc] == 0 && dist[dr][dc] > w)
      {
        dist[dr][dc] = w;
        min_heap.push({w, {dr, dc}});
      }
    }
  }

  if (dist[m - 1][n - 1] == INT_MAX)
    return -1;

  return dist[m - 1][n - 1] + 1;
}

int main(void)
{
  // * testcase 1
  // std::vector<std::vector<int>> grid = {{0, 1}, {1, 0}};

  // * testcase 2
  std::vector<std::vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};

  // * testcase 3
  // std::vector<std::vector<int>> grid = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};

  std::cout << "Grid" << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  // int ans = shortestPathBinaryMatrixBFS(grid);
  int ans = shortestPathBinaryMatrixDij(grid);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 15-shortest-path-in-binary-matrix.cpp -o output && ./output
