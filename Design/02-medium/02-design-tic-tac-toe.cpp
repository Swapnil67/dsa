/*
 * Design Tic-Tac-Toe
 * 
 * https://www.naukri.com/code360/problems/design-tic-tac-toe_1265038 
*/

// ! Amazon, Microsoft, Uber, Adobe, Apple, Meta

#include <vector>
#include <cstring>
#include <iostream>

class Solution
{
public:
  int *r, *c, dlr, drl, s;
  Solution(int n) {
    r = new int[n];
    memset(r, 0, sizeof(*r));
    c = new int[n];
    memset(c, 0, sizeof(*c));
    dlr = drl = 0;
    s = n;
  }

  int move(int row, int col, int player)
  {
    if (player == 1) {
      r[row]++;
      c[col]++;
      if (row == col)
        dlr++;
      if (row + col == s - 1)
        drl++;
      if (r[row] == s || c[col] == s || dlr == s || drl == s) {
        return 1;
      }
      return 0;
    }
    else
    {
      r[row]--;
      c[col]--;
      if (row == col)
        dlr--;
      if (row + col == s - 1)
        drl--;
      if (r[row] == -s || c[col] == -s || dlr == -s || drl == -s) {
        return 2;
      }
    }
    return 0;
  }
};

int main(void) {
  int n = 3;
  Solution *game = new Solution(n);

  std::vector<std::vector<int>> moves = {
      {0, 0, 1},
      {1, 0, 2},
      {0, 1, 1},
      {1, 1, 2},
      {0, 2, 1},
  };

  for (auto &move: moves) {
    int row = move[0], col = move[1], player = move[2];
    std::cout << "row: " << row << ", col: " << col << ", player: " << player << std::endl;
    int player_won = game->move(row, col, player);
    if (player_won) {
      std::cout << "Player won: " << player_won << std::endl;
      break;
    }
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-design-tic-tac-toe.cpp -o output && ./output