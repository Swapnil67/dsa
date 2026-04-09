/*
 * Leetcode - 934
 * Shortest Bridge
 * 
 * You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
 * An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
 *
 * You may change 0's to 1's to connect the two islands to form one island.
 * Return the smallest number of 0's you must flip to connect the two islands.

 * Example 1:
 * Input     : grid = [[0,1],[1,0]]
 * Output    : 1
 * 
 * Example 2:
 * Input     : grid = [[0,1,0],[0,0,0],[0,0,1]]
 * Output    : 2
 * 
 * Example 3:
 * Input     : grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * Output    : 1

 * https://leetcode.com/problems/shortest-bridge/description/
 * https://www.naukri.com/code360/problems/shortest-bridge_1105571
*/

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

// ! DFS + BFS 
// ! Microsoft, Meta, Uber, Google

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

// * check out of bound
bool check_oob(int n, const int &row, const int &col) {
  return row >= 0 && row < n && col >= 0 && col < n;
};

void dfs(int r, int c,
         queue<pair<int, int>> &q,
         vector<vector<bool>> &visited,
         vector<vector<int>> &grid)
{
  int n = grid.size(); // * rows == cols
  visited[r][c] = true; // * mark visited
  q.push({r, c});

  // * go in all 4 directions
  for (auto &dir : dirs) {
    int dr = r + dir[0], dc = c + dir[1];
    if (check_oob(n, dr, dc) && !visited[dr][dc] && grid[dr][dc] == 1) {
      dfs(dr, dc, q, visited, grid);
    }
  }
}

// * ------------------------- APPROACH : Optimal Approach -------------------------
// * TIME COMPLEXITY O(n x n)
// * SPACE COMPLEXITY O(n x n)
int shortestBridge(vector<vector<int>>& grid) {
  int n = grid.size(); // * rows == cols
  vector<vector<bool>> visited(n, vector<bool>(n, false));

  queue<pair<int, int>> q;

  // * Do DFS on 1st Island and save all the land nodes to queue
  bool found = false;
  for (int r = 0; r < n; ++r) {
    if (found)
      break;
      
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == 1) {
        dfs(r, c, q, visited, grid);
        found = true;
        break;
      }
    }
  }

  // * For Debugging
  // while (!q.empty()) {
  //   auto p = q.front();
  //   cout << "(" << p.first << " " << p.second << ")" << endl;
  //   q.pop();
  // }

  // * From all the land nodes of 1st island do BSF to 2nd Island
  // * i.e., find the shortest from 1st -> 2nd island
  int min_dist = 0;
  while (!q.empty()) {
    int N = q.size();
    while (N--) {
      auto [r, c] = q.front();
      q.pop();

      for (auto &dir: dirs) {
        int dr = r + dir[0], dc = c + dir[1];
        if (check_oob(n, dr, dc) && !visited[dr][dc]) {
          if (grid[dr][dc] == 1) {
            return min_dist;
          }
          q.push({dr, dc});
          visited[dr][dc] = true;
        }
      }
    }
    min_dist++;
  }

  // cout << endl;
  // for (auto &vec : visited)
  //   printArr(vec);

  return min_dist;
}

int main(void) {
  // * testcase 1 // * Ans = 1
  // vector<vector<int>> grid = {{0, 1}, {1, 0}};

  // * testcase 2 // * Ans = 2
  // vector<vector<int>> grid = {{0, 1, 0},
  //                             {0, 0, 0},
  //                             {0, 0, 1}};

  // * testcase 3 // * Ans = 1
  // vector<vector<int>> grid = {{1, 1, 1, 1, 1},
  //                             {1, 0, 0, 0, 1},
  //                             {1, 0, 1, 0, 1},
  //                             {1, 0, 0, 0, 1},
  //                             {1, 1, 1, 1, 1}};

  // * testcase 3 // * Ans = 1
  vector<vector<int>> grid = {{0, 0, 1, 0, 1},
                              {0, 1, 1, 0, 1},
                              {0, 1, 0, 0, 1},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}};

  cout << "-------- Board -------- " << endl;
  for (auto &vec : grid)
    printArr(vec);
  
  int steps = shortestBridge(grid);
  cout << "Steps: " << steps << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 38-shortest-bridge.cpp -o output && ./output

 