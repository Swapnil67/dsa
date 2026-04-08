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

// ! Amazon, Google, Meta, Microsoft, Adobe, Apple, Uber

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> arr) {
  cout << "{ ";
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr[i] << " ";
  }
  cout << "}" << endl;
}

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool dfs(int r, int c, int idx, string &word,
         vector<vector<char>> &board)
{
  int m = board.size(), n = board[0].size();

  if (idx == word.length())
    return true;

  if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] != word[idx])
    return false;

  char temp = board[r][c];
  board[r][c] = '$'; // * visited

  for (auto &dir : dirs) {
    int dr = r + dir[0], dc = c + dir[1];
    if (dfs(dr, dc, idx + 1, word, board)) {
      return true;
    }
  }

  board[r][c] = temp;
  return false;
}

// * ------------------------- Optimal Approach -------------------------
// * Go in all 4 direction on each co-ordinate
// * L = length of word
// * TIME COMPLEXITY O(m * n * 4^L)
// * SPACE COMPLEXITY O(L)
bool exist(vector<vector<char>> &board, string &word) {
  int m = board.size(), n = board[0].size();
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (board[i][j] == word[0] && dfs(i, j, 0, word, board)) {
        return true;
      }
    }
  }

  return false;
}

int main(void) {
  // * testcase 1
  // string word = "ABCCED";

  // * testcase 2
  // string word = "SEE";

  // * testcase 3
  // string word = "ABCB";

  // * testcase 4
  string word = "a";

  cout << "Search Word: " << word << endl;

  // vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

  vector<vector<char>> board = {{'a'}};
  for (auto &vec : board)
    printArr(vec);

  bool ans = exist(board, word);
  cout << "Found: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 07-word-search.cpp -o output && ./output
