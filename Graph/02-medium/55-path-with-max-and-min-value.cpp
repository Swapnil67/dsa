/*
 * Leetcode - 1102
 * Path With Maximum And Minimum Value
 *
 * Given an m x n integer matrix grid, return the maximum score of a path starting at (0, 0) and ending at (m - 1, n - 1) 
 * moving in the 4 cardinal directions.
 * 
 * The score of a path is the minimum value in that path.
 * 
 * Example 1:
 * Input       : grid = {{5 4 5},
 *                       {1 2 6}, 
 *                       {7 4 6}}
 * Output      : 4
 * Explanation : so the path with maximum value will be 5 -> 4 -> 5 -> 6 -> 6 and we have to return 
 *               the minimum value in this path as the answer i.e 4.
 * 
 * https://www.naukri.com/code360/problems/path-with-maximum-and-minimum-value_1281861
 * https://leetcode.com/problems/path-with-maximum-minimum-value/description/
*/

// ! Adobe

#include <queue>
#include <vector>
#include <climits>
#include <iostream>

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

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Dijkstra Algorithm (max heap)
// * v = no of vertices
// * e = no of edges
// * TIME COMPLEXITY O(v * (logv + elogv))
// * SPACE COMPLEXITY O(E + V)
int pathWithMaxMinValue(vector<vector<int>> &arr) {
  int m = arr.size(), n = arr[0].size();

  vector<vector<bool>> visited(m, vector<bool>(n, false));

  typedef pair<int, pair<int, int>> P;
  priority_queue<P, vector<P>> max_heap;
  max_heap.push({arr[0][0], {0, 0}});

  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  int path_min = INT_MAX;
  while (!max_heap.empty()) {
    auto [d, p] = max_heap.top();
    auto [r, c] = p;
    max_heap.pop();

    path_min = min(path_min, d);

    visited[r][c] = true;

    if (r == m - 1 && c == n - 1)
      return path_min;

    for (auto &dir : dirs) {
      int dr = r + dir[0], dc = c + dir[1];
      if (is_safe(dr, dc) && !visited[dr][dc]) {
        max_heap.push({arr[dr][dc], {dr, dc}});
      }
    }
  }

  return -1;
}

int main(void) {
  // * testcase 1
  //  std::vector<std::vector<int>> grid = {{5, 4, 5}, {1, 2, 6}, {7, 4, 6}};

  // * testcase 2
  std::vector<std::vector<int>> grid = {{2, 2, 1, 2, 2, 2}, {1, 2, 2, 2, 1, 2}};

  // * testcase 3
  //  std::vector<std::vector<int>> grid = {{3, 4, 6, 3, 4},
  //                                        {0, 2, 1, 1, 7},
  //                                        {8, 8, 3, 2, 7},
  //                                        {3, 2, 4, 9, 8},
  //                                        {4, 1, 2, 0, 0},
  //                                        {4, 6, 5, 4, 3}};

  cout << "Input Matrix: " << endl;
  for (auto &vec : grid)
    printArr(vec);

  int ans = pathWithMaxMinValue(grid);
  cout << "Answer: " << ans << endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 55-path-with-max-and-min-value.cpp -o output && ./output