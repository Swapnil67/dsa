/*
 * Leetcode - ?
 * The Maze
 * 
 * There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). 
 * The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. 
 * When the ball stops, it could choose the next direction.
 * 
 * Given the m x n maze, the ball's start position and the destination, where start = [start_row, start_col] and 
 * destination = [destination_row, destination_col], return true if the ball can stop at the destination, otherwise return false.
 * 
 * You may assume that the borders of the maze are all walls (see examples).
 * 
 * Example 1    :
 * Input        : maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
 * Output       : true
 * 
 * Example 2    :
 * Input        : maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
 * Output       : false
 * 
 * Example 3    :
 * Input        : maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
 * Output       : false
 * 
 * https://neetcode.io/problems/the-maze/question
*/

// ! Amazon, Google, Meta, Uber, Bloomberg

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

const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// * (m + n) because it's rolling the full row or column in worst case
// * TIME COMPLEXITY O(m * n * (m + n))
// * SPACE COMPLEXITY O(m * n)
bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
  int m = maze.size(), n = maze[0].size();
  queue<pair<int, int>> q;
  q.push({start[0], start[1]});

  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  vector<vector<bool>> visit(m, vector<bool>(n, false));
  visit[start[0]][start[1]] = true;

  while (!q.empty())
  {
    int N = q.size();
    while (N--) {
      auto [r, c] = q.front();
      q.pop();

      // * Reached Destination
      if (r == destination[0] && c == destination[1])
        return true;

      for (auto &dir : dirs) {
        int dr = r + dir[0], dc = c + dir[1];
        // * Move the ball in the chosen direction until it can.
        while (is_safe(dr, dc) && maze[dr][dc] == 0)  {
          dr = dr + dir[0], dc = dc + dir[1];
        }
        // * Revert the last move to get the cell to which the ball rolls.
        dr -= dir[0], dc -= dir[1];

        if (!visit[dr][dc]) {
          q.push({dr, dc});
          visit[dr][dc] = true;
        }
      }
    }
  }

  return false;
}

int main(void) {
  // * testcase 1
  // vector<vector<int>> maze = {{0, 0, 1, 0, 0},
  //                             {0, 0, 0, 0, 0},
  //                             {0, 0, 0, 1, 0},
  //                             {1, 1, 0, 1, 1},
  //                             {0, 0, 0, 0, 0}};
  // vector<int> start = {0, 4}, destination = {4, 4};

  // * testcase 2
  // vector<vector<int>> maze = {{0, 0, 1, 0, 0},
  //                             {0, 0, 0, 0, 0},
  //                             {0, 0, 0, 1, 0},
  //                             {1, 1, 0, 1, 1},
  //                             {0, 0, 0, 0, 0}};
  // vector<int> start = {0, 4}, destination = {3, 2};

  // * testcase 3
  vector<vector<int>> maze = {{0, 0, 0, 0, 0},
                              {1, 1, 0, 0, 1},
                              {0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 1},
                              {0, 1, 0, 0, 0}};
  vector<int> start = {4, 3}, destination = {0, 1};

  cout << "Maze" << endl;
  for (auto &vec : maze)
    printArr(vec);
  cout << "start: ";
  printArr(start);
  cout << "destination: ";
  printArr(destination);

  bool ans = hasPath(maze, start, destination);
  cout << "Has Path: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 60-the-maze.cpp -o output && ./output
