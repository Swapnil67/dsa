/*
 * Leetcode - 130
 * Surrounded Regions
 * 
 * You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
 * - Connect: A cell is connected to adjacent cells horizontally or vertically.
 * - Region: To form a region connect every 'O' cell.
 * - Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and 
 *   none of the region cells are on the edge of the board.
 * 
 * To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. 
 * You do not need to return anything.
 * 
 * Example 1:
 * Input     : board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * Output    : [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * 
 * Example 2:
 * Input     : board = [["X"]]
 * Output    : [["X"]]

 * https://leetcode.com/problems/surrounded-regions/description/
 * https://www.naukri.com/code360/problems/capture-region_1092608
 * https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1
*/

// ! Microsoft, HSBC, Google

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

const std::vector<std::vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void mark_visited(int x, int y, std::vector<std::vector<char>> &board) {
  board[x][y] = 'T';
  int m = board.size(), n = board[0].size();
  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  for (auto &dir : dirs) {
    int dx = x + dir[0], dy = y + dir[1];
    if (is_safe(dx, dy) && board[dx][dy] == 'O') {
      mark_visited(dx, dy, board);
    }
  }
}

// * ------------------------- APPROACH : Optimal Approach -------------------------`
// * DFS
// * TIME COMPLEXITY O(m x n)
// * SPACE COMPLEXITY O(m x n)
void solve(std::vector<std::vector<char>> &board) {
  int m = board.size(), n = board[0].size();

  // * Mark Top & bottom border of board
  for (int r = 0; r < m; ++r) {
    if (board[r][0] == 'O') {       // * first column
      mark_visited(r, 0, board);
    }
    if (board[r][n - 1] == 'O') {   // * last column
      mark_visited(r, n - 1, board);
    }
  }
  
  // * Mark left & right border of board
  for (int c = 0; c < n; ++c) {
    if (board[0][c] == 'O') {      // * First row
      mark_visited(0, c, board);
    }
    if (board[m - 1][c] == 'O') {  // * Last row
      mark_visited(m - 1, c, board);
    }
  }

  // * for debugging
  // for (auto &vec : visited)
  //   printArr(vec);

  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (board[r][c] == 'O') {
        board[r][c] = 'X';
      }
      else if (board[r][c] == 'T') {
        board[r][c] = 'O';
      }
    }
  }
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<char>> board = {{'X', 'X', 'X', 'X'},
  //                                         {'X', 'O', 'O', 'X'},
  //                                         {'X', 'X', 'O', 'X'},
  //                                         {'X', 'O', 'X', 'X'}};

  // * testcase 2
  // std::vector<std::vector<char>> board= {{1}};

  // * testcase 3
  // std::vector<std::vector<char>> board = {{'X', 'X', 'X'}, {'X', 'O', 'X'}, {'X', 'X', 'X'}};

  // * testcase 4
  // std::vector<std::vector<char>> board = {{'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}};

  // * testcase 4
  std::vector<std::vector<char>> board = {{'O', 'X', 'O'},
                                          {'O', 'X', 'O'},
                                          {'X', 'O', 'X'},
                                          {'O', 'O', 'X'},
                                          {'X', 'X', 'O'},
                                          {'O', 'X', 'X'},
                                          {'O', 'O', 'O'},
                                          {'X', 'O', 'X'}};

  std::cout << "-------- board -------- " << std::endl;
  for (auto &vec : board)
    printArr(vec);
  
  std::cout << "-------- Surrounded Regions -------- " << std::endl;
  solve(board);
  for (auto &vec : board)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 31-surrounded-regions.cpp -o output && ./output

 