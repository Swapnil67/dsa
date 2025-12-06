/*
 * Leetcode - 1219
 * Path with Maximum Gold
 * 
 * In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of 
 * gold in that cell, 0 if it is empty.

 * Return the maximum amount of gold you can collect under the conditions:
 * - Every time you are located in a cell you will collect all the gold in that cell.
 * - From your position, you can walk one step to the left, right, up, or down.
 * - You can't visit the same cell more than once.
 * - Never visit a cell with 0 gold.
 * - You can start and stop collecting gold from any position in the grid that has some gold.

 * Example 1  :
 * Input      : grid = [[0,6,0],[5,8,7],[0,9,0]]
 * Output     : 24

 * Example 2  :
 * Input      : grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
 * Output     : 28

 * https://leetcode.com/problems/path-with-maximum-gold/description/
*/

// ! Apple, Amazon, Google

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>

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

void printAdjList(std::unordered_map<int, std::vector<int>> &adj) {
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    printArr(vec);
  }
}

std::unordered_map<int, std::vector<int>> constructadj(std::vector<std::vector<int>> &edges) {
  std::unordered_map<int, std::vector<int>> adj;
  for (auto &it : edges) {
    int u = it[0], v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return adj;
}
const std::vector<std::vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfs(int r, int c, std::vector<std::vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  
  const auto is_safe = [&](const int &row, const int &col) {
    return row >= 0 && row < m && col >= 0 && col < n;
  };
  
  int original_value = grid[r][c];
  grid[r][c] = 0;

  int max_gold = 0;
  for (auto &dir: dirs) { // * Go to all 4 directions
    int dr = r + dir[0], dc = c + dir[1];
    if (is_safe(dr, dc) && grid[dr][dc] != 0) {
      max_gold = std::max(max_gold, dfs(dr, dc, grid));
    }
  }

  grid[r][c] = original_value;
  return original_value + max_gold;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * Go to every gold node and do DFS from there
// * TIME COMPLEXITY O(m * n) * O(4^(m * n))
// * SPACE COMPLEXITY O(4^(m * n))
int getMaximumGold(std::vector<std::vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();

  int max_gold = 0;
  // * O(m x n)
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] != 0) {
        max_gold = std::max(max_gold, dfs(r, c, grid));
        // std::cout << grid[r][c] << " -> " << max_gold << std::endl;
      }
    }
  }

  return max_gold;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> grid = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};

  // * testcase 2
  // std::vector<std::vector<int>> grid = {{1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}, {9, 0, 20}};

  std::cout << "------------ grid -------------" << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  // std::vector<int> ans = bruteForce(n, grid);
  int ans = getMaximumGold(grid);
  std::cout << "Maximum Gold: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 52-path-with-max-gold.cpp -o output && ./output

 