/*
 * Leetcode - 79
 * Word Search
 * 
 * Given an m x n grid of characters board and a string word, return true if word exists in the grid.

 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. 
 * The same letter cell may not be used more than once.

 * Example 1
 * input  : word = "ABCCED"
 *          board = {{ "A","B","C","E" },
 *                   { "S","F","C","S" },
 *                   { "A","D","E","E" }}
 * output : true
 * 
 * 

 * Example 2
 * input  : word = "ABCB"
 *          board = {{ "A","B","C","E" },
 *                   { "S","F","C","S" },
 *                   { "A","D","E","E" }}
 * output : false
 * 
 * 
 * https://leetcode.com/problems/word-search/description/
*/

#include <vector>
#include <iostream>
#include <unordered_set>

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "{ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "}" << std::endl;
}

std::vector<std::vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool find(std::vector<std::vector<char>> &board,
          std::string &word,
          int i, int j, int idx)
{
  int m = board.size();
  int n = board[0].size();

  if (idx == word.length())
    return true;

  if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[idx])
    return false;

  if (board[i][j] != word[idx])
    return false;

  char temp = board[i][j];
  board[i][j] = '$'; // * visited

  for (auto &dir : directions) {
    int new_i = i + dir[0];
    int new_j = j + dir[1];
    if (find(board, word, new_i, new_j, idx + 1)) {
      return true;
    }
  }

  board[i][j] = temp;
  return false;
}

// * ------------------------- Optimal Approach -------------------------`
// * Go in all 4 direction on each co-ordinate
// * L = length of word
// * TIME COMPLEXITY O(m * n * 4^L)
// * SPACE COMPLEXITY O(L)
bool exist(std::vector<std::vector<char>> &board, std::string &word) {
  int m = board.size();
  int n = board[0].size();
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (board[i][j] == word[0] && find(board, word, i, j, 0)) {
        return true;
      }
    }
  }

  return false;
}

int main(void) {
  // std::string word = "ABCCED";
  // std::string word = "SEE";
  std::string word = "ABCB";
  std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  std::cout << "Word: " << word << std::endl;
  for (auto &vec : board)
    printArr(vec);

  bool ans = exist(board, word);
  std::cout << "Found: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 07-word-search.cpp -o output && ./output
