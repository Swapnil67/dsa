/*
 * Leetcode - 1631
 * Path With Minimum Effort
 * 
 * You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, 
 * where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), 
 * and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). 
 * You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
 * 
 * A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
 * 
 * Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 * Example 1  :
 * Input      : heights = [[1,2,2],[3,8,2],[5,3,5]]
 * Output     : 2

 * Example 2  :
 * Input      : heights = [[1,2,3],[3,8,4],[5,3,5]]
 * Output     : 1

 * Example 3  :
 * Input      : heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
 * Output     : 0

 * https://leetcode.com/problems/path-with-minimum-effort/description/
 * https://www.naukri.com/code360/problems/path-with-minimum-effort_1380958
 * https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1
*/

// ! Dijkstra Algorithm

// ! Meta, Visa

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

int minimumEffortPath(std::vector<std::vector<int>>& heights) {
  int m = heights.size();
  int n = heights[0].size();

  std::vector<std::vector<int>> res(m, std::vector<int>(n, INT_MAX));
  res[0][0] = 0;

  typedef std::pair<int, std::pair<int, int>> P;
  std::priority_queue<P, std::vector<P>, std::greater<>> min_heap;
  min_heap.push({0, {0, 0}});

  auto is_safe = [&](const int&x, const int&y) {
    return x >= 0 && x < m && y >= 0 && y < n;
  };

  while (!min_heap.empty()) {
    int d = min_heap.top().first;
    std::pair<int, int> node = min_heap.top().second;
    min_heap.pop();

    int x = node.first, y = node.second;
    for (auto &dir : dirs) {
      int dx = x + dir[0], dy = y + dir[1];
      if (is_safe(dx, dy)) {
        // * abs diff b/w two heights
        int w = std::abs(heights[dx][dy] - heights[x][y]);
        int max_diff = std::max(w, d);

        if (res[dx][dy] > max_diff) {
          res[dx][dy] = max_diff;
          min_heap.push({max_diff, {dx, dy}});
        }
      }
    }
  }
 
  // std::cout << "Distance Matrix" << std::endl;
  // for (auto &vec : res)
  //   printArr(vec); 

  if (res[m - 1][n - 1] == INT_MAX)
    return -1;
  return res[m - 1][n - 1];

  return 0;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

  // * testcase 2
  std::vector<std::vector<int>> heights = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};

  // * testcase 3
  // std::vector<std::vector<int>> heights = {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};

  std::cout << "heights" << std::endl;
  for (auto &vec : heights)
    printArr(vec);

  int ans = minimumEffortPath(heights);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 16-path-with-min-effort.cpp -o output && ./output

 