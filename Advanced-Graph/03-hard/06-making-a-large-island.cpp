/*
 * Leetcode - 827
 * Making A Large Island
 * 
 * You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
 * Return the size of the largest island in grid after applying this operation.
 * 
 * An island is a 4-directionally connected group of 1s.
 * 
 * Example 1    :
 * Input        : grid = [[1,0],[0,1]]
 * Output       : 3
 * Explanation  : Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
 * 
 * Example 2    :
 * Input        : grid = [[1,1],[1,0]]
 * Output       : 4
 * Explanation  : Change the 0 to 1 and make the island bigger, only one island with area = 4.
 * 
 * Example 3    :
 * Input        : grid = [[1,1],[1,1]]
 * Output       : 4
 * Explanation  : Can't change any 0 to 1, only one island with area = 4.
 * 
 * https://leetcode.com/problems/making-a-large-island/description/
 * https://www.geeksforgeeks.org/problems/making-a-large-island/1
 * https://www.naukri.com/code360/problems/making-the-largest-island_1381282
*/

// ! Google, Amazon, Microsoft

#include <vector>
#include <numeric>
#include <iostream>
#include <unordered_set>

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

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)

std::vector<std::vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int find(int x, vector<int> &parent) {
  if (x == parent[x])
    return x;
  return parent[x] = find(parent[x], parent);
}

void Union(int x, int y, vector<int> &size, vector<int> &parent) {
  int xp = find(x, parent);
  int yp = find(y, parent);
  if (xp == yp)
    return;

  if (size[xp] > size[yp]) {
    parent[yp] = xp;
    size[xp] += size[yp];
  } else {
    parent[xp] = yp;
    size[yp] += size[xp];
  }
}

int largestIsland(vector<vector<int>> &grid)
{
  int m = grid.size(), n = grid[0].size();
  vector<int> size(m * n, 1);
  vector<int> parent(m * n);
  iota(begin(parent), end(parent), 0);

  const auto is_safe = [&](const int &r, const int &c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  };

  // * connect components
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == 0)
        continue;

      for (auto &dir : dirs) {
        int dr = r + dir[0], dc = c + dir[1];
        if (is_safe(dr, dc) && grid[dr][dc] == 1) {
          int node = r * n + c;
          int ngbr = dr * n + dc;
          Union(node, ngbr, size, parent);
        }
      }
    }
  }

  int max_size = 0;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == 1)
        continue;

      unordered_set<int> components;
      for (auto &dir : dirs) {
        int dr = r + dir[0], dc = c + dir[1];
        if (is_safe(dr, dc) && grid[dr][dc] == 1) {
          int node = dr * n + dc;
          components.insert(find(node, parent));
        }
      }

      int cur_size = 0;
      for (auto &node : components) {
        cur_size += size[node];
      }
      max_size = max(max_size, cur_size + 1);
    }
  }

  // * Edge case where every node is a '1'
  for (int cell = 0; cell < m * n; ++cell) {
    max_size = max(max_size, size[find(cell, parent)]);
  }

  return max_size;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> grid = {{1, 0}, {0, 1}};
  
  // * testcase 2
  // std::vector<std::vector<int>> grid = {{1, 1}, {0, 1}};
  
  // * testcase 3
  // std::vector<std::vector<int>> grid = {{1, 1}, {1, 1}};

  std::cout << "Input Grid: " << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  int ans = largestIsland(grid);
  std::cout << "Largest Island: " << ans << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 06-making-a-large-island.cpp -o output && ./output

