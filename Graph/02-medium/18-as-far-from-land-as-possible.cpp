/*
 * Leetcode - 1162
 * As Far from Land as Possible
 * 
 * Given an n x n grid containing only values 0 and 1,
 * - 0 = water 
 * - 1 = land
 * find a water cell such that its distance to the nearest land cell is maximized, and return the distance. 
 * If no land or water exists in the grid, return -1.
 * 
 * The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) 
 * is |x0 - x1| + |y0 - y1|.
 * 
 * Example 1  :
 * Input      : grid = [[1,0,1],[0,0,0],[1,0,1]]
 * Output     : 2

 * Example 2  :
 * Input      : grid = [[1,0,0],[0,0,0],[0,0,0]]
 * Output     : 4

 * https://leetcode.com/problems/as-far-from-land-as-possible/
*/

// ! BFS

// ! Google, Amazon

#include <queue>
#include <vector>
#include <iostream>
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

// * ------------------------- APPROACH 1: Optimal Approach -------------------------
// * Multi Source BFS (Overwriting Input)
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int maxDistance(vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();

  queue<pair<int, int>> q;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == 1) {
        q.push({r, c});
      }
    }
  }

  auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  int res = -1;
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    res = grid[r][c];

    for (auto &dir : dirs) {
      int dr = r + dir[0], dc = c + dir[1];
      if (is_safe(dr, dc) && grid[dr][dc] == 0) {
        grid[dr][dc] = grid[r][c] + 1; // * overwrite the distance
        q.push({dr, dc});
      }
    }
  }
  // * For debugging
  // cout << "Distance Grid" << endl;
  // for (auto &vec : grid)
  //   printArr(vec);

  return res > 1 ? res - 1 : -1;
}


// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * Multi Source BFS
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N^2)
int maxDistance2(vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();

  vector<vector<bool>> visited(m, vector<bool>(n, false));
  queue<pair<int, int>> q;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == 1) {
        visited[r][c] = true;
        q.push({r, c});
      }
    }
  }

  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  int res = -1;
  while (!q.empty()) {
    res++;
    int N = q.size();
    while (N--) {
      auto [r, c] = q.front();
      q.pop();
      for (auto &dir : dirs) {
        int nr = r + dir[0], nc = c + dir[1];
        if (is_safe(nr, nc) && !visited[nr][nc]) {
          q.push({nr, nc});
          visited[nr][nc] = true;
        } 
      }
    }

  }

  return res > 0 ? res : -1;
}

int main(void) {
  // * testcase 1
  // vector<vector<int>> grid = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};

  // * testcase 2
  vector<vector<int>> grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  cout << "grid" << endl;
  for (auto &vec : grid)
    printArr(vec);

  int ans = maxDistance(grid);
  // int ans = maxDistance2(grid);
  cout << "Max Distance: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 18-as-far-from-land-as-possible.cpp -o output && ./output

 