/*
 * Leetcode - ?
 * Number of Distinct Islands
 * 
 * You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally 
 * (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
 * 
 * An island is considered to be the same as another if and only if one island can be translated 
 * (and not rotated or reflected) to equal the other.
 * 
 * Return the number of distinct islands.
 * 
 * Example 1    :
 * Input        : grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
 * Output       : 1
 * 
 * Example 2    :
 * Input        : grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
 * Output       : 3
 * 
 * https://neetcode.io/problems/number-of-distinct-islands/question
 * https://www.naukri.com/code360/problems/distinct-islands_630460
 * https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
*/

// ! Microsoft, Expedia, Google, Amazon, Meta, Tiktok 

#include <set>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

typedef pair<int, int> P;
const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int r, int c, int r_base, int c_base, vector<P> &coordinates,
         std::vector<std::vector<bool>> &visited,
         vector<vector<int>> &grid)
{
  visited[r][c] = true;
  coordinates.push_back({r - r_base, c - c_base});

  int m = grid.size(), n = grid[0].size();
  const auto is_safe = [&](const int &row, const int &col) {
    return row >= 0 && row < m && col >= 0 && col < n;
  };

  // * Go to neighbours
  for (auto &dir : dirs) {
    int dr = r + dir[0], dc = c + dir[1];
    if (is_safe(dr, dc) && !visited[dr][dc] && grid[dr][dc] == 1) {
      dfs(dr, dc, r_base, c_base, coordinates, visited, grid);
    }
  }
}

// * TIME COMPLEXITY O(M * N * log(M * N))
// * SPACE COMPLEXITY O(M * N)
int numDistinctIslands(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  set<vector<P>> st;
  std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (!visited[r][c] && grid[r][c] == 1) {
        vector<P> coordinates;
        dfs(r, c, r, c, coordinates, visited, grid);
        st.insert(coordinates);
      }
    }
  }

  return st.size();
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> grid = {{1, 1, 0, 0, 0},
                                        {1, 1, 0, 0, 0},
                                        {0, 0, 0, 1, 1},
                                        {0, 0, 0, 1, 1}};

  // * testcase 2
  // std::vector<std::vector<int>> grid = {{1, 1, 0, 1, 1},
  //                                       {1, 0, 0, 0, 0},
  //                                       {0, 0, 0, 0, 1},
  //                                       {1, 1, 0, 1, 1}};

  std::cout << "Grid" << std::endl;
  for (auto &vec: grid) {
    printArr(vec);
  }

  int ans = numDistinctIslands(grid);
  std::cout << "Number of Distinct Islands: " << ans << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 65-number-of-distinct-islands.cpp -o output && ./output
