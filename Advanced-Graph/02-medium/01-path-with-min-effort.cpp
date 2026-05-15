/*
 * Leetcode - 1631
 * Path With Minimum Effort
 * 
 * You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, 
 * where heights[row][col] repdistents the height of cell (row, col). You are situated in the top-left cell, (0, 0), 
 * and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). 
 * You can move up, down, left, or right, and you wish to find a route that requidist the minimum effort.
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

 * https://neetcode.io/problems/path-with-minimum-effort/
 * https://leetcode.com/problems/path-with-minimum-effort/description/
 * https://www.naukri.com/code360/problems/path-with-minimum-effort_1380958
 * https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1
 * 
*/

// ! Dijkstra Algorithm

// ! Amazon, Google, Meta, Microsoft, Bloomberg, Tiktok

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
    if (i != n - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * Using Dijkstra Algorithm
// * m = no of rows
// * n = no of cols
// * TIME COMPLEXITY O(m * n * log(m * n))
// * SPACE COMPLEXITY O(m * n)
int minimumEffortPath(vector<vector<int>>& heights) {
  int m = heights.size(), n = heights[0].size();

  vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
  dist[0][0] = 0;

  // * pair = {distance, {x, y}}
  typedef pair<int, pair<int, int>> P;
  priority_queue<P, vector<P>, greater<>> pq;
  pq.push({0, {0, 0}});

  // * out of bound check lamda
  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  while (!pq.empty()) {
    int d = pq.top().first;
    auto [r, c] = pq.top().second;
    pq.pop();

    for (auto &dir : dirs) {
      int dr = r + dir[0], dc = c + dir[1];
      if (is_safe(dr, dc)) {
        // * abs diff b/w two heights
        int w = abs(heights[dr][dc] - heights[r][c]);
        int max_diff = max(w, d); // * we need the max diff
        if (dist[dr][dc] > max_diff) {
          dist[dr][dc] = max_diff;       // * update distance vector
          pq.push({max_diff, {dr, dc}}); // * add to pq
        }
      }
    }
  }
 
  // * For debugging
  // cout << "Distance Matrix" << endl;
  // for (auto &vec : dist)
  //   printArr(vec); 

  if (dist[m - 1][n - 1] == INT_MAX)
    return -1;
  return dist[m - 1][n - 1];
}

int main(void) {
  // * testcase 1
  // vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

  // * testcase 2
  // vector<vector<int>> heights = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};

  // * testcase 3
  // vector<vector<int>> heights = {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};

  // * testcase 4
  // vector<vector<int>> heights = {{1, 10, 6, 7, 9, 10, 4, 9}};

  // * testcase 5
  vector<vector<int>> heights = {{1, 8, 8}, {3, 8, 9}, {5, 3, 5}};

  cout << "heights" << endl;
  for (auto &vec : heights)
    printArr(vec);

  int ans = minimumEffortPath(heights);
  cout << "Answer: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-path-with-min-effort.cpp -o output && ./output
