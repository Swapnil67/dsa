/*
 * Valid Sudoku

 * https://www.naukri.com/code360/problems/sudoku_758961
 * https://leetcode.com/problems/valid-sudoku/description/
*/

#include<map>
#include<set>
#include<iostream>

void printBoard(std::vector<std::vector<char>> board) {
  int r = board.size(), c = board[0].size();
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cout << board[i][j] << " ";
    }
    std::cout<<std::endl;
  }
  std::cout << std::endl;
}

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
bool isValidBoard(std::vector<std::vector<char>> board) {
  std::map<int, std::set<int>> rowMap; // * duplicate in row
  std::map<int, std::set<int>> colMap; // * duplicate in columns
  std::map<std::pair<int, int>, std::set<int>> squareMap; // * duplicate in 3x3 matrix

  int r = board.size(), c = board[0].size();
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if(board[i][j] == '.')
        continue;
      // * location of smaller matrix within board
      std::pair<int, int> square({i / 3, j / 3});
      if (
          (rowMap.find(i) != rowMap.end()) && (rowMap[i].find(board[i][j]) != rowMap[i].end()) ||
          (colMap.find(j) != colMap.end()) && (colMap[j].find(board[i][j]) != colMap[j].end()) ||
          (squareMap.find(square) != squareMap.end()) &&
              (squareMap[square].find(board[i][j]) != squareMap[square].end()))
      {
        return false;
      }
      rowMap[i].insert(board[i][j]);
      colMap[j].insert(board[i][j]);
      squareMap[square].insert(board[i][j]);
    }
  }
  return true;
}

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    const int cnt = 9;
    bool row[cnt][cnt] = {false};
    bool col[cnt][cnt] = {false};
    bool sub[cnt][cnt] = {false};

    for (int r = 0; r < cnt; ++r) {
      for (int c = 0; c < cnt; ++c) {
        if (board[r][c] == '.')
          continue; // if not number pass

        int idx = board[r][c] - '0' - 1; // char to num idx
        // std::cout << idx << std::endl;
        int area = (r / 3) * 3 + (c / 3);

        // if number already exists
        if (row[r][idx] || col[c][idx] || sub[area][idx])
        {
          return false;
        }

        row[r][idx] = true;
        col[c][idx] = true;
        sub[area][idx] = true;
      }
    }
    return true;
}

int main() {

  // std::vector<std::vector<char>> board = {
  //     {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
  //     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
  //     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
  //     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
  //     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
  //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
  //     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
  //     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
  //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  // std::vector<std::vector<char>> board =
  //     {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
  //      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
  //      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
  //      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
  //      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
  //      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
  //      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
  //      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
  //      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  std::vector<std::vector<char>> board =
      {{'1', '5', '9', '.', '.', '6', '.', '3', '2'},
       {'2', '7', '4', '.', '.', '.', '.', '.', '.'},
       {'3', '8', '6', '2', '.', '.', '.', '.', '5'},
       {'4', '9', '2', '5', '.', '1', '.', '8', '.'},
       {'6', '3', '7', '.', '4', '.', '.', '.', '.'},
       {'5', '1', '.', '8', '2', '.', '.', '.', '.'},
       {'8', '2', '1', '.', '.', '.', '.', '.', '.'},
       {'7', '6', '.', '1', '.', '.', '4', '2', '.'},
       {'9', '4', '3', '.', '7', '.', '.', '6', '1'}};

  std::cout << "Soduku Board" << std::endl;
  printBoard(board);
  // bool isValid = isValidBoard(board);
  bool isValid = isValidSudoku(board);
  std::cout << "Is Valid " << isValid << std::endl;
  std::cout << "test " << '3' - '0' - 1 << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 16-valid-sudoku.cpp -o output && ./output