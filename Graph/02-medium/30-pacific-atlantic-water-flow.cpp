/*
 * Leetcode - 417
 * Pacific Atlantic Water Flow
 * 
 * There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
 * The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's
 * right and bottom edges.
 * 
 * The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights 
 * where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
 * 
 * The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east,
 * and west if the neighboring cell's height is less than or equal to the current cell's height. 
 * Water can flow from any cell adjacent to an ocean into the ocean.
 * 
 * Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from 
 * cell (ri, ci) to both the Pacific and Atlantic oceans.
 * 
 * Example 1:
 * Input     : heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * Output    : [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 * 
 * Example 1:
 * Input     : heights = [[1]]
 * Output    : [[0,0]]

 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
*/

// ! Amazon

#include <vector>
#include <climits>
#include <iostream>

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

const std::vector<std::vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(
    int r, int c,
    int prev_val,
    bool &atlantic, bool &pacific,
    std::vector<std::vector<int>> &heights)
{

  int m = heights.size(), n = heights[0].size();

  if (r < 0 || c < 0) { // * Reached Pacific ocean
    pacific = true;
    return;
  }

  if (r >= m || c >= n) { // * Reached Atlantic ocean
    atlantic = true;
    return;
  }

  if (heights[r][c] > prev_val) {
    return;
  }

  int tmp = heights[r][c];
  heights[r][c] = INT_MAX;  // * this is to mark visited
  
  // * Go to neighbouring cells
  for (auto &dir : dirs) {
    int dr = r + dir[0], dc = c + dir[1];
    dfs(dr, dc, tmp, atlantic, pacific, heights);
    if (atlantic && pacific)
      break;
  }

  heights[r][c] = tmp;
}

void dfs(
    int r, int c,
    std::vector<std::vector<bool>> &ocean,
    std::vector<std::vector<int>> &heights)
{
  ocean[r][c] = true;
  int m = heights.size(), n = heights[0].size();

  // * Out of bound check
  const auto is_safe = [&](const int &row, const int &col) {
    return row >= 0 && row < m && col >= 0 && col < n;
  };

  // * Go to neighbours
  for (auto dir : dirs) {
    int nr = r + dir[0], nc = c + dir[1];
    if (is_safe(nr, nc) && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
      dfs(nr, nc, ocean, heights);
    }
  }
}

// * ------------------------- APPROACH 1: BRUTE FORCE Approach -------------------------`
// * Traverse all the cell in grid & check if it can reach both oceans.
// * Backtracking
// * TIME COMPLEXITY O((m x n) x 4^(m x n))
// * SPACE COMPLEXITY O(m x n)
std::vector<std::vector<int>> bruteForce(std::vector<std::vector<int>> &heights) {
  int m = heights.size(), n = heights[0].size();
  std::vector<std::vector<int>> ans;

  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      bool atlantic = false, pacific = false;
      dfs(r, c, INT_MAX, atlantic, pacific, heights);
      if (atlantic && pacific) {
        ans.push_back({r, c});
      }
    }
  }

  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * DFS
// * TIME COMPLEXITY O(m x n)
// * SPACE COMPLEXITY O(m x n)
std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &heights) {
  int m = heights.size(), n = heights[0].size();
  std::vector<std::vector<bool>> pac(m, std::vector<bool>(n, false));
  std::vector<std::vector<bool>> atl(m, std::vector<bool>(n, false));

  for (int c = 0; c < n; ++c) {
    dfs(0, c, pac, heights);         // * top pacific
    dfs(m - 1, c, atl, heights);     // * bottom atlantic
  }

  for (int r = 0; r < m; ++r) {
    dfs(r, 0, pac, heights);        // * left pacific
    dfs(r, n - 1, atl, heights);    // * right atlantic
  }

  std::vector<std::vector<int>> ans;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (pac[r][c] && atl[r][c]) {
        ans.push_back({r, c});
      }
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};

  // * testcase 2
  // std::vector<std::vector<int>> heights = {{1}};

  std::cout << "-------- heights -------- " << std::endl;
  for (auto &vec : heights)
  printArr(vec);
  
  std::cout << "-------- Pacific Atlantic Water Flow -------- " << std::endl;
  // std::vector<std::vector<int>> ans = bruteForce(heights);
  std::vector<std::vector<int>> ans = pacificAtlantic(heights);
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 30-pacific-atlantic-water-flow.cpp -o output && ./output

 