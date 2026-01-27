/*
 * Leetcode - 286
 * Snakes and Ladders
 * 
 * You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style
 * starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.
 * 
 * A board square on row r and column c has a snake or ladder if board[r][c] != -1. 
 * The destination of that snake or ladder is board[r][c]. Squares 1 and n2 are not the starting points of any snake or ladder.
 * 
 * Note that you only take a snake or ladder at most once per dice roll. 
 * If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.
 * Return the least number of dice rolls required to reach the square n2. If it is not possible to reach the square, return -1.
 * 
 * Example 1:
 * Input     : board = [[-1,-1,-1,-1,-1,-1],
 *                      [-1,-1,-1,-1,-1,-1],
 *                      [-1,-1,-1,-1,-1,-1],
 *                      [-1,35,-1,-1,13,-1],
 *                      [-1,-1,-1,-1,-1,-1],
 *                      [-1,15,-1,-1,-1,-1]]
 * Output    : 4
 * 
 * Example 2:
 * Input     : board = [[-1,-1],[-1,3]]
 * Output    : 1

 * https://leetcode.com/problems/snakes-and-ladders/
 * https://www.naukri.com/code360/problems/snake-and-ladder_630458
*/

#include <queue>
#include <vector>
#include <iostream>

// ! BFS

// ! Meta

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

std::pair<int, int> intToPos(int square, int n) {
  int r = (square - 1) / n;
  int c = (square - 1) % n;
  if (r % 2 == 1) {
    c = n - 1 - c;
  }
  r = n - 1 - r;
  return {r, c};
}

// * ------------------------- APPROACH : Optimal Approach -------------------------`
// * Since we need a shortest path we'll use BFS approach 
// * TIME COMPLEXITY O(n x n)
// * SPACE COMPLEXITY O(n x n)
int snakesAndLadders(std::vector<std::vector<int>>& board) {
  int n = board.size(); // * rows == cols
  int dest = n * n;  // * Destination Cell

  board[n - 1][0] = 0; // * bottom-Left Cell visited
  std::queue<int> q;
  q.push(1);

  int steps = 0;
  while (!q.empty()) {
    int N = q.size();
    while (N--) {
      auto square = q.front();
      q.pop();

      for (int i = 1; i <= 6; ++i) {
        auto next_square = square + i;
        if (next_square > dest) // * out of bound
          return steps;

        auto [r, c] = intToPos(next_square, n);
        if (board[r][c] != -1) {
          next_square = board[r][c];
        }

        if (next_square == dest) 
          return steps + 1;

        // * not visited
        if (board[r][c] != 0) {
          board[r][c] = 0; // * mark visited
          q.push(next_square);
        }
      }
    }

    steps += 1;
  }

  return -1; // * could not reach dest cell
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> board = {{-1, -1, -1, -1, -1, -1},
                                        {-1, -1, -1, -1, -1, -1},
                                        {-1, -1, -1, -1, -1, -1},
                                        {-1, 35, -1, -1, 13, -1},
                                        {-1, -1, -1, -1, -1, -1},
                                        {-1, 15, -1, -1, -1, -1}};
  std::cout << "-------- Board -------- " << std::endl;
  for (auto &vec : board)
    printArr(vec);
  
  int steps = snakesAndLadders(board);
  std::cout << "Steps: " << steps << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 33-snakes-and-ladders.cpp -o output && ./output

 