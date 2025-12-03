/*
 * Leetcode - 1462
 * Check if Move is Legal
 * 
 * You are given a 0-indexed 8 x 8 grid board, where board[r][c] represents the cell (r, c) on a game board.
 * On the board, free cells are represented by '.', white cells are represented by 'W', and black cells '
 * are represented by 'B'.
 * 
 * Each move in this game consists of choosing a free cell and changing it to the color you are playing as 
 * (either white or black). However, a move is only legal if, after changing it, the cell becomes the endpoint
 * of a good line (horizontal, vertical, or diagonal).
 * 
 * A good line is a line of three or more cells (including the endpoints) where the endpoints of the line are 
 * one color, and the remaining cells in the middle are the opposite color (no cells in the line are free). 
 * You can find examples for good lines in the figure below:

 * Given two integers rMove and cMove and a character color representing the color you are playing as 
 * (white or black), return true if changing cell (rMove, cMove) to color color is a legal move, or false 
 * if it is not legal.

 * Example 1:
 * Input     : color: W, rMove: 4, cMove: 3,
 *             edges =  [ '.'   '.'   '.'   'B'   '.'   '.'   '.'   '.' ]
 *                      [ '.'   '.'   '.'   'W'   '.'   '.'   '.'   '.' ]
 *                      [ '.'   '.'   '.'   'W'   '.'   '.'   '.'   '.' ]
 *                      [ '.'   '.'   '.'   'W'   '.'   '.'   '.'   '.' ]
 *                      [ 'W'   'B'   'B'   '.'   'W'   'W'   'W'   'B' ]
 *                      [ '.'   '.'   '.'   'B'   '.'   '.'   '.'   '.' ]
 *                      [ '.'   '.'   '.'   'B'   '.'   '.'   '.'   '.' ]
 *                      [ '.'   '.'   '.'   'W'   '.'   '.'   '.'   '.' ]
 * Output    : true

 * Example 2:
 * Input     : color: W, rMove: 4, cMove: 4,
 *             edges =  [ '.'   '.'   '.'   '.'   '.'   '.'   '.'   '.' ]
 *                      [ '.'   'B'   '.'   '.'   'W'   '.'   '.'   '.' ]
 *                      [ '.'   '.'   'W'   '.'   '.'   '.'   '.'   '.' ]
 *                      [ '.'   '.'   '.'   'W'   'B'   '.'   '.'   '.' ]
 *                      [ '.'   '.'   '.'   '.'   '.'   '.'   '.'   '.' ]
 *                      [ '.'   '.'   '.'   '.'   'B'   'W'   '.'   '.' ]
 *                      [ '.'   '.'   '.'   '.'   '.'   '.'   'W'   '.' ]
 *                      [ '.'   '.'   '.'   '.'   '.'   '.'   '.'   'B' ]
 * Output    : false

 * https://leetcode.com/problems/check-if-move-is-legal/description/
*/

// ! Google, Meta, Amazon

#include <vector>
#include <iostream>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << "'" << arr[i] << "' ";
    if (i != n - 1)
      std::cout << "  ";
  }
  std::cout << "]" << std::endl;
}

std::vector<std::vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

bool check_legal(
    int r, int c,
    char &color,
    std::vector<int> &dir,
    std::vector<std::vector<char>> &board)
{ 
  int m = board.size(), n = board[0].size();
  int dr = dir[0], dc = dir[1];
  r += dr;
  c += dc;

  // std::cout << "dr: " << dr << ", dc: " << dc << std::endl;
  int length = 1;
  
  // * out of bound check
  while (r >= 0 && r < m && c >= 0 && c < n) {
    // std::cout << r << " " << c << " -> " << board[r][c] << std::endl;
    length++;
    if (board[r][c] == '.') {
      return false;
    }

    // * We should get the same color only if we get the same color after 3 or more cells
    if (board[r][c] == color) // * same color found on line
      return length >= 3;     // * is good line

    // * go forward in current direction
    r += dr, c += dc;
  }
  return false;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(1)
// * SPACE COMPLEXITY O(1)
bool checkMove(
    int rMove, int cMove, char color,
    std::vector<std::vector<char>> &board)
{
  int r = board.size(), c = board[0].size();
  board[rMove][cMove] = color;

  for (auto &dir: dirs) { // * go to all 8 directions
    if (check_legal(rMove, cMove, color, dir, board))
      return true;
  }
  return false;
}

int main(void) {
  // * testcase 1
  // int rMove = 4, cMove = 3;
  // char color = 'W';
  // std::vector<std::vector<char>> board = {{'.', '.', '.', 'B', '.', '.', '.', '.'},
  //                                         {'.', '.', '.', 'W', '.', '.', '.', '.'},
  //                                         {'.', '.', '.', 'W', '.', '.', '.', '.'},
  //                                         {'.', '.', '.', 'W', '.', '.', '.', '.'},
  //                                         {'W', 'B', 'B', '.', 'W', 'W', 'W', 'B'},
  //                                         {'.', '.', '.', 'B', '.', '.', '.', '.'},
  //                                         {'.', '.', '.', 'B', '.', '.', '.', '.'},
  //                                         {'.', '.', '.', 'W', '.', '.', '.', '.'}};

  // * testcase 2
  int rMove = 4, cMove = 4;
  char color = 'W';
  std::vector<std::vector<char>> board = {{'.', '.', '.', '.', '.', '.', '.', '.'},
                                          {'.', 'B', '.', '.', 'W', '.', '.', '.'},
                                          {'.', '.', 'W', '.', '.', '.', '.', '.'},
                                          {'.', '.', '.', 'W', 'B', '.', '.', '.'},
                                          {'.', '.', '.', '.', '.', '.', '.', '.'},
                                          {'.', '.', '.', '.', 'B', 'W', '.', '.'},
                                          {'.', '.', '.', '.', '.', '.', 'W', '.'},
                                          {'.', '.', '.', '.', '.', '.', '.', 'B'}};

  std::cout << "color: " << color << ", rMove: " << rMove << ", cMove: " << cMove << std::endl;
  std::cout << "---------------- board ---------------- " << std::endl;
  for (auto &vec : board)
  printArr(vec);

  bool ans = checkMove(rMove, cMove, color, board);
  std::cout << "Is Move Legal: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 37-check-if-move-is-legal.cpp -o output && ./output

 