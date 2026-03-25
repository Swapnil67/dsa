/*
 * Leetcode - 
 * NAME
 * 
 * Example 1    :
 * Input        : grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
 * Output       : 5
 * Explanation  : 
 * 
 * Example 2    :
 * Input        : grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
 * Output       : 5
 * Explanation  : 
 * 
*/

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
