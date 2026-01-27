/*
 * Leetcode - 1730
 * Shortest Path to Get Food
 *
 * You are starving :( and you want to eat food as quickly as possible.
 * You want to find shortest path to arrive at any food cell
 * 
 * You are given a mxn character matrix, grid of these different types of cells:
 * - '*' is your location. There is exactly one '*' cell.
 * - '#' is a food cell. There may be multiple food cell.
 * - 'o' is a free space. You can travel through these cells.
 * - 'x' is an obstacle. You cannot travel through these cells.
 * 
 * You can travel to cell in one of the 4 cardinal directions (north, east, west, south) if there is no obstacle.
 * 
 * Return the length of shortest path for you to reach any food cell.
 * If there is no path return -1
 *
 * Example 1:
 * Input       : grid = [["X","X","X","X","X","X"],
 *                       ["X","*","O","O","O","X"],
 *                       ["X","O","O","#","O","X"],
 *                       ["X","X","X","X","X","X"]]
 * Output      : 3
 * Explanation : It takes 3 steps to reach the food.
 * 
 * https://leetcode.com/problems/shortest-path-to-get-food/description/
*/

// ! Amazon, Google, Adobe

#include <queue>
#include <vector>
#include <iostream>

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

const std::vector<std::vector<int>> dirs = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int getFood(std::vector<std::vector<char>> &grid) {
  int m = grid.size(), n = grid[0].size();

  // * Step 1: Find the starting cell
  std::queue<std::pair<int, int>> q;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == '*') {
        q.push(std::make_pair(r, c));
        break;
      }
    }
  }

  // * There is no starting position
  if (q.empty())
    return -1;

  // * out of bound check
  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  // * Step 2: Simple BFS
  int steps = 0;
  while (!q.empty()) {
    int N = q.size();
    steps += 1;
    while (N--) {
      auto [r, c] = q.front();
      q.pop();

      if (grid[r][c] == '#')
        return steps;

      // * Go to neighbours
      for (auto &dir : dirs) {
        int dr = r + dir[0], dc = c + dir[1];
        if (is_safe(dr, dc)) {
          if (grid[dr][dc] == '#')
            return steps;
          else if (grid[dr][dc] == 'O') {
            grid[dr][dc] = 'X';
            q.push(std::make_pair(dr, dc));
          }
        }
      }
    }
  }

  return -1;
}


int main(void) {
  // * testcase 1
  //  std::vector<std::vector<char>> grid = {
  //      {'X', 'X', 'X', 'X', 'X', 'X'},
  //      {'X', '*', 'O', 'O', 'O', 'X'},
  //      {'X', 'O', 'O', '#', 'O', 'X'},
  //      {'X', 'X', 'X', 'X', 'X', 'X'},
  //  };

  // * testcase 2
   std::vector<std::vector<char>> grid = {
       {'X', 'X', 'X', 'X', 'X', 'X'},
       {'X', '*', 'X', 'O', 'X', 'X'},
       {'X', 'O', 'X', '#', 'X', 'X'},
       {'X', 'X', 'X', 'X', 'X', 'X'},
   };

  // * testcase 3
  // std::vector<std::vector<char>> grid = {
  //     {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
  //     {'X', '*', 'O', 'X', 'O', '#', 'O', 'X'},
  //     {'X', 'O', 'O', 'X', 'O', 'O', 'X', 'X'},
  //     {'X', 'O', 'O', 'O', 'O', '#', 'O', 'X'},
  //     {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
  // };

  std::cout << "Input Grid: " << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  int ans = getFood(grid);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 56-shortest-path-to-get-food.cpp -o output && ./output