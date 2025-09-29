/*
 * Leetcode - 51
 * N-Queens II
 * 
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.'
 * both indicate a queen and an empty space, respectively.

 * Example 1
 * input  : n = 4
 * output : [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 
 * https://leetcode.com/problems/n-queens/description/
*/

#include <vector>
#include <iostream>
#include <unordered_set>

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

std::vector<std::vector<std::string>> result;

bool is_valid(std::vector<std::string> &board, int &row, int &col, int &n) {
  // * Check if queen exists in upward direction in same column.
  for (int r = row - 1; r >= 0; --r) {
    if (board[r][col] == 'Q')
      return false;
  }

  // * Check if queen exists in right diagnol upward direction.
  int c = col + 1;
  for (int r = row - 1; (r >= 0 && c < n); --r) {
    if (board[r][c] == 'Q')
      return false;
    c += 1;
  }

  // * Check if queen exists in left diagnol upward direction.
  c = col - 1;
  for (int r = row - 1; (r >= 0 && c >= 0); --r) {
    if (board[r][c] == 'Q')
      return false;
    c -= 1;
  }

  return true;
}

void solve(std::vector<std::string> &board, int row, int &n) {
  // * Base case
  if (row >= n) {
    result.push_back(board);
    return;
  }

  // * check for all columns in specified row
  for (int col = 0; col < n; ++col) {
    if (is_valid(board, row, col, n)) { // * is_valid cell for queen
      board[row][col] = 'Q';
      solve(board, row + 1, n);
      board[row][col] = '.';
    }
  }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
  std::vector<std::string> board(n, std::string(n, '.'));
  solve(board, 0, n);
  return result;
}


std::unordered_set<int> used_col;
std::unordered_set<int> used_left_diagnol;
std::unordered_set<int> used_right_diagnol;
void solve2(std::vector<std::string> &board, int row, int &n) {
  // * Base case
  if (row >= n) {
    result.push_back(board);
    return;
  }

  // * check for all columns in specified row
  for (int col = 0; col < n; ++col) {
    // * Check if queen exists in upward direction in same column.
    if (used_col.count(col))
      continue;

    // * Check if queen exists in left diagnol upward direction.
    if (used_left_diagnol.count(row - col))
      continue;
    
    // * Check if queen exists in right diagnol upward direction.
    if (used_right_diagnol.count(row + col))
      continue;

    board[row][col] = 'Q';
    used_col.insert(col);
    used_left_diagnol.insert(row - col);
    used_right_diagnol.insert(row + col);
    
    solve2(board, row + 1, n);
    
    board[row][col] = '.';
    used_col.erase(col);
    used_left_diagnol.erase(row - col);
    used_right_diagnol.erase(row + col);
  }
}

std::vector<std::vector<std::string>> solveNQueens2(int n) {
  std::vector<std::string> board(n, std::string(n, '.'));
  solve2(board, 0, n);
  return result;
}

int main(void) {
  // * testcase 1
  // int n = 3;

  // * testcase 1
  int n = 4;

  // std::vector<std::vector<std::string>> board = solveNQueens(n);
  std::vector<std::vector<std::string>> board = solveNQueens2(n);
  for (auto &row : board) {
    printArr(row);
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-n-queens.cpp -o output && ./output