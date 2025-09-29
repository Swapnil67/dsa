/*
 * Leetcode - 52
 * N-Queens II
 * 
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 * Example 1
 * input  : n = 4
 * output : 2
 * 
 * https://leetcode.com/problems/n-queens-ii/description/
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

void solve(std::vector<std::string> &board, int row, int &n, int &ans) {
  // * Base case
  if (row >= n) {
    ans++;
    return;
  }

  // * check for all columns in specified row
  for (int col = 0; col < n; ++col) {
    if (is_valid(board, row, col, n)) { // * is_valid cell for queen
      board[row][col] = 'Q';
      solve(board, row + 1, n, ans);
      board[row][col] = '.';
    }
  }
}

void solveNQueens(int n, int &ans) {
  std::vector<std::string> board(n, std::string(n, '.'));
  solve(board, 0, n, ans);
}


std::unordered_set<int> used_col;
std::unordered_set<int> used_left_diagnol;
std::unordered_set<int> used_right_diagnol;
void solve2(std::vector<std::string> &board, int row, int &n, int &ans) {
  // * Base case
  if (row >= n) {
    ans++;
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
    
    solve2(board, row + 1, n, ans);
    
    board[row][col] = '.';
    used_col.erase(col);
    used_left_diagnol.erase(row - col);
    used_right_diagnol.erase(row + col);
  }
}

void solveNQueens2(int n, int &ans) {
  std::vector<std::string> board(n, std::string(n, '.'));
  solve2(board, 0, n, ans);
}

int main(void) {
  // * testcase 1
  // int n = 3;

  // * testcase 1
  int n = 4;
  
  std::cout << "Queens: " << n << std::endl;

  int ans = 0;
  // solveNQueens(n, ans);
  solveNQueens2(n, ans);
  std::cout << "Possible boards: " << ans << std::endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 02-n-queens-ii.cpp -o output && ./output