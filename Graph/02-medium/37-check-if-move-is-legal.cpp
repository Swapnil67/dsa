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

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << "'" << arr[i] << "' ";
    if (i != n - 1)
      cout << "  ";
  }
  cout << "]" << endl;
}

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

bool check_legal(
    int r, int c,
    char &color,
    vector<int> &dir,
    vector<vector<char>> &board)
{
  int m = board.size(), n = board[0].size();
  int dr = dir[0], dc = dir[1];
  r += dr;
  c += dc;

  // cout << "dr: " << dr << ", dc: " << dc << endl;
  int length = 1;

  // * out of bound check
  while (r >= 0 && r < m && c >= 0 && c < n)
  {
    // cout << r << " " << c << " -> " << board[r][c] << endl;
    length++;
    if (board[r][c] == '.')
      return false;

    // * We should get the same color only if we get the same color after 3 or more cells
    if (board[r][c] == color) // * same color found on line
      return length >= 3;     // * is good line

    // * go forward in current direction
    r += dr, c += dc;
  }
  return false;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * TIME COMPLEXITY O(1)
// * SPACE COMPLEXITY O(1)
bool checkMove(int r, int c, char color,
               vector<vector<char>> &board)
{
  board[r][c] = color;
  for (auto &dir: dirs) { // * go to all 8 directions
    if (check_legal(r, c, color, dir, board))
      return true;
  }
  return false;
}

int main(void) {
  // * testcase 1
  // int rMove = 4, cMove = 3;
  // char color = 'W';
  // vector<vector<char>> board = {{'.', '.', '.', 'B', '.', '.', '.', '.'},
  //                               {'.', '.', '.', 'W', '.', '.', '.', '.'},
  //                               {'.', '.', '.', 'W', '.', '.', '.', '.'},
  //                               {'.', '.', '.', 'W', '.', '.', '.', '.'},
  //                               {'W', 'B', 'B', '.', 'W', 'W', 'W', 'B'},
  //                               {'.', '.', '.', 'B', '.', '.', '.', '.'},
  //                               {'.', '.', '.', 'B', '.', '.', '.', '.'},
  //                               {'.', '.', '.', 'W', '.', '.', '.', '.'}};

  // * testcase 2
  int rMove = 4, cMove = 4;
  char color = 'W';
  vector<vector<char>> board = {{'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', 'B', '.', '.', 'W', '.', '.', '.'},
                                {'.', '.', 'W', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', 'W', 'B', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', 'B', 'W', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', 'W', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', 'B'}};

  cout << "color: " << color << ", rMove: " << rMove << ", cMove: " << cMove << endl;
  cout << "---------------- board ---------------- " << endl;
  for (auto &vec : board)
    printArr(vec);

  bool ans = checkMove(rMove, cMove, color, board);
  cout << "Is Move Legal: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 37-check-if-move-is-legal.cpp -o output && ./output

 