/*
 * Leetcode - ?
 * The Maze II
 * 
 * There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). 
 * The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. 
 * When the ball stops, it could choose the next direction.
 * 
 * Given the m x n maze, the ball's start position and the destination, where start = [start_row, start_col] and 
 * destination = [destination_row, destination_col].
 * return the shortest distance for the ball to stop at the destination. If the ball cannot stop at destination, return -1.
 * 
 * The distance is the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).
 * 
 * 
 * You may assume that the borders of the maze are all walls (see examples).
 * 
 * Example 1    :
 * Input        : maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
 * Output       : 12
 * 
 * Example 2    :
 * Input        : maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
 * Output       : -1
 * 
 * Example 3    :
 * Input        : maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
 * Output       : -1
 * 
 * https://neetcode.io/problems/the-maze-ii/question
*/

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
// int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
// TODO
// }

int main(void) {
  // * testcase 1
  vector<vector<int>> maze = {{0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 1, 0},
                              {1, 1, 0, 1, 1},
                              {0, 0, 0, 0, 0}};
  vector<int> start = {0, 4}, destination = {4, 4};

  // * testcase 2
  // vector<vector<int>> maze = {{0, 0, 1, 0, 0},
  //                             {0, 0, 0, 0, 0},
  //                             {0, 0, 0, 1, 0},
  //                             {1, 1, 0, 1, 1},
  //                             {0, 0, 0, 0, 0}};
  // vector<int> start = {0, 4}, destination = {3, 2};

  // * testcase 3
  // vector<vector<int>> maze = {{0, 0, 0, 0, 0},
  //                             {1, 1, 0, 0, 1},
  //                             {0, 0, 0, 0, 0},
  //                             {0, 1, 0, 0, 1},
  //                             {0, 1, 0, 0, 0}};
  // vector<int> start = {4, 3}, destination = {0, 1};

  cout << "Maze" << endl;
  for (auto &vec : maze)
    printArr(vec);
  cout << "start: ";
  printArr(start);
  cout << "destination: ";
  printArr(destination);

  // int ans = shortestDistance(maze, start, destination);
  // cout << "Shortest Distance: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 61-the-maze-ii.cpp -o output && ./output
