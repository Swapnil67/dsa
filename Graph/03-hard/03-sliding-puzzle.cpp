/*
 * Leetcode - 2872
 * Maximum Number of K-Divisible Components
 *
 * There is an undirected tree with n nodes labeled from 0 to n - 1. 
 * You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] 
 * indicates that there is an edge between nodes ai and bi in the tree.
 * 
 * You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with
 * the ith node, and an integer k.
 * 
 * A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the 
 * resulting components all have values that are divisible by k, where the value of a connected component is the sum 
 * of the values of its nodes.
 * 
 * Return the maximum number of components in any valid split.

 * * Example 1  :
 * * Input      : board = [[1,2,3],[4,0,5]]
 * * Output     : 2
 * 
 * * Example 2  :
 * * Input      : board = [[1,2,3],[5,4,0]]
 * * Output     : 3
 * 
 * https://leetcode.com/problems/maximum-number-of-k-divisible-components/
 * 
 */

// ! Airbnb

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

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

// * ------------------------- APPROACH: Optimal  -------------------------`
// * TIME COMPLEXITY  O(6!)
// * The puzzle has 6 ! = 720 possible permutations of the board, as there are 6 tiles, 
// * including the blank tile (0). In the worst case, BFS explores all permutations.
// * SPACE COMPLEXITY O(6!)
int slidingPuzzle(std::vector<std::vector<int>> &board) {
  int m = 2, n = 3;

  // * Create the string out of given matrix
  std::string start = "";
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      start += std::to_string(board[r][c]);
    }
  }

  std::queue<std::string> q;
  q.push(start);
  
  std::string target = "123450";
  // * Save all the possible cell zero can be swapped with into a map
  std::unordered_map<int, std::vector<int>> mp = {
      {0, {1, 3}},
      {1, {0, 2, 4}},
      {2, {1, 5}},
      {3, {0, 4}},
      {4, {1, 3, 5}},
      {5, {2, 4}}};

  std::unordered_set<std::string> visited;
  visited.insert(start);

  int level = 0;
  while (!q.empty()) {
    int N = q.size();
    while (N--) {
      std::string cur = q.front();
      q.pop();

      if (cur == target) // * Found ans
        return level;

      int idx_of_zero = cur.find('0');
      for (auto swap_idx: mp[idx_of_zero]) { // * Swap cur zero with all possible positions
        std::string temp = cur;
        std::swap(temp[swap_idx], temp[idx_of_zero]);
        if (!visited.count(temp)) {
          visited.insert(temp);
          q.push(temp);
        }
      }
    }
    level += 1;
  }

  return -1;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> board = {{1, 2, 3}, {4, 0, 5}};

  // * testcase 2
  // std::vector<std::vector<int>> board = {{1, 2, 3}, {5, 4, 0}};

  // * testcase 2
  std::vector<std::vector<int>> board = {{4, 1, 2}, {5, 0, 3}};

  std::cout << "-------- board -------- " << std::endl;
  for (auto &vec : board)
    printArr(vec);

  int ans = slidingPuzzle(board);
  std::cout << "Least Moves: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-sliding-puzzle.cpp -o output && ./output
