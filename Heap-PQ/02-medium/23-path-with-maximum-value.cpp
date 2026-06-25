/*
* Leetcode - PAID
* Path With Maximum Minimum Value
*
* Given an m x n integer matrix grid, return the maximum score of a path starting at (0, 0) and 
* ending at (m - 1, n - 1) moving in the 4 cardinal directions.
*
* The score of a path is the minimum value in that path.
*
* Example 1:
* Input     : grid = {{5,4,5},{1,2,6},{7,4,6}}
* Output    : 4
*
* Example 2:
* Input     : grid = {{2,2,1,2,2,2},{1,2,2,2,1,2}}
* Output    : 2
*
* Example 3:
* Input     : grid = {{3,4,6,3,4},{0,2,1,1,7},{8,8,3,2,7},{3,2,4,9,8},{4,1,2,0,0},{4,6,5,4,3}}
* Output    : 3
* 
* https://neetcode.io/problems/path-with-maximum-minimum-value/
*/

// ! Amazon, Google

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int maximumMinimumPath(vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();

  // * max heap
  priority_queue<pair<int, pair<int, int>>> pq;
  pq.push({grid[0][0], {0, 0}});

  // * Create a visited grid
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  visited[0][0] = true;
  
  const auto is_safe = [&](const auto &r, const auto &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };
  
  int ans = grid[0][0];
  while (!pq.empty()) {
    auto [d, p] = pq.top();
    pq.pop();
    ans = min(d, ans);
    auto [r, c] = p;

    if (r == m - 1 && c == n - 1)
      return ans;

    // * Go to neighbours
    for (auto &dir : dirs) {
      int dr = r + dir[0], dc = c + dir[1];
      if (is_safe(dr, dc) && !visited[dr][dc])
      {
        visited[dr][dc] = true;
        pq.push({grid[dr][dc], {dr, dc}});
      }
    }
  }

  return ans;
}


int main(void) {
  // * testcase 1
  // vector<vector<int>> grid = {{5, 4, 5}, {1, 2, 6}, {7, 4, 6}};
  
  // * testcase 2
  // vector<vector<int>> grid = {{3, 4, 6, 3, 4},
  //                             {0, 2, 1, 1, 7},
  //                             {8, 8, 3, 2, 7},
  //                             {3, 2, 4, 9, 8},
  //                             {4, 1, 2, 0, 0},
  //                             {4, 6, 5, 4, 3}};

  // * testcase 3
  vector<vector<int>> grid = {{2, 2, 1, 2, 2, 2}, {1, 2, 2, 2, 1, 2}};

  cout << "-------- Grid -------- " << endl;
  for (auto &vec : grid)
    printArr(vec);

  int ans = maximumMinimumPath(grid);
  cout << "Path With Maximum Minimum Value: " << ans << endl;

}