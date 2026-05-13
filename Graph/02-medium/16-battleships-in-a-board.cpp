/*
* Leetcode -  419
* Battleships in a Board
* 
* Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

* Battleships can only be placed horizontally or vertically on board. 
* In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column),
* where k can be of any size. At least one horizontal or vertical cell separates between two battleships 
* (i.e., there are no adjacent battleships).

* Example 1  :
* Input      : board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
* Output     : 2

* Example 2  :
* Input      : board = [["."]]
* Output     : 0

* https://leetcode.com/problems/battleships-in-a-board/description/
* 
*/

// ! Microsoft, Amazon, Adobe, Google

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
    if (i != n - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// * ------------------------- APPROACH 1: Brute Force Approach -------------------------
// * BFS
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n)
int bruteForce(vector<vector<char>>& board) {
  int m = board.size(), n = board[0].size();
  if (m == 0 || n == 0)
    return 0;

  queue<pair<int, int>> q;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (board[r][c] == 'X') {
        q.push(make_pair(r, c));
      }
    }
  }
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  
  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  int total_battleships = 0;
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    if (!visited[r][c]) {
      total_battleships++;
    } else {
      visited[r][c] = true;
    }

    for (auto &dir: dirs) {
      int dr = r + dir[0], dc = c + dir[1];
      if (is_safe(dr, dc) && !visited[dr][dc] && board[dr][dc] == 'X') {
        visited[dr][dc] = true;
        q.push(make_pair(dr, dc));
      }
    }
  }

  return total_battleships;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Only count new battleship if it has '.' in its top or left cell
// * TIME COMPLEXITY O(m x n)
// * SPACE COMPLEXITY O(m x n)
int countBattleships(vector<vector<char>>& board) {
int m = board.size(), n = board[0].size();
  if (m == 0 || n == 0)
    return 0;

  int total_battle_ships = 0;
  for (int r = 0; r < m; ++r) {
    int top = r - 1;
    for (int c = 0; c < n; ++c) {
      int left = c - 1;
      if (board[r][c] == 'X' &&
          ((left < 0 || board[r][left] == '.') &&
           (top < 0 || board[top][c] == '.')))
      {
        // * new battleship
        total_battle_ships += 1;
      }
    }
  }

  return total_battle_ships;
}

int main(void) {
  // * testcase 1
  vector<vector<char>> board = {{'X', '.', '.', 'X'},
                                          {'.', '.', '.', 'X'},
                                          {'.', '.', '.', 'X'}};

  // * testcase 2
  // vector<vector<char>> board = {{'X', 'X', 'X'}};

  cout << "Board" << endl;
  for (auto &vec : board)
    printArr(vec);

  // int ans = bruteForce(board);
  int ans = countBattleships(board);
  cout << "Answer: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 16-battleships-in-a-board.cpp -o output && ./output
