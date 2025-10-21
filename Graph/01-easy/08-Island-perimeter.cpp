/**
 * * Island Perimeter
 * 
 * * You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 
 * * represents water.
 * 
 * * Grid cells are connected horizontally/vertically (not diagonally). 
 * * The grid is completely surrounded by water, and there is exactly one island 
 * * (i.e., one or more connected land cells).
 * 
 * * The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. 
 * * One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
 * * Determine the perimeter of the island.
 * 
 * * Example 1  :
 * * Input      : grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
 * * Output     : 16
 * 
 * * Example 2  :
 * * Input      : grid = [[1]]
 * * Output     : 4
 * 
 * * Example 3  :
 * * Input      : grid = [[1,0]]
 * * Output     : 4
 * 
 * * https://leetcode.com/problems/island-perimeter/description/
 * 
 */

#include <queue>
#include <vector>
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

// * Print adjacency list
template <typename T>
void printAdjList(std::vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    std::cout << i << " -> ";
    printArr(adj[i]);
  }
}

const std::vector<std::vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y, int &p, std::vector<std::vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();

  // * Edge cases
  if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
    p++;
    return;
  }

  // * Already Visited
  if (grid[x][y] == -1)  
    return;

  grid[x][y] = -1; // * mark visited

  // * Move to all 4 directions
  for (auto &dir : dirs) {
    int new_x = x + dir[0];
    int new_y = y + dir[1];
    dfs(new_x, new_y, p, grid);
  }
}

int bfs(int x, int y, std::vector<std::vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();

  int peri = 0;

  std::queue<std::pair<int, int>> q;
  q.push({x, y});
  grid[x][y] = -1;

  while (!q.empty()) {
    std::pair<int, int> p = q.front();
    q.pop();

    for (auto &dir : dirs) {
      int new_x = p.first + dir[0];
      int new_y = p.second + dir[1];

      // * Edge cases
      if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || grid[new_x][new_y] == 0) {
        peri++;
        continue;
      }
      else if (grid[new_x][new_y] == -1) {
        continue;
      }
      else {
        q.push({new_x, new_y});
        grid[new_x][new_y] = -1;
      }
    }
  }

  return peri;
}


// * ------------------------- Approach 1: Optimal -------------------------
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(1)
int islandPerimeterDFS(std::vector<std::vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();
  int perimeter = 0;

  for (int i = 0; i < m ; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1) {
        dfs(j, i, perimeter, grid);
      }
    }
  }

  return perimeter;
}

// * ------------------------- Approach 2: Optimal -------------------------
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(1)
int islandPerimeterBFS(std::vector<std::vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();
  int perimeter = 0;

  for (int i = 0; i < m ; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1) {
        dfs(j, i, perimeter, grid);
      }
    }
  }

  return perimeter;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};

  // * testcase 2
  // std::vector<std::vector<int>> grid = {{1}};

  // * testcase 3
  // std::vector<std::vector<int>> grid = {{1, 0}};

  int V = grid.size();
  std::cout << "Grid: " << V << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  // int perimeter = islandPerimeterDFS(grid);
  int perimeter = islandPerimeterBFS(grid);
  std::cout << "Perimeter: " << perimeter << std::endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 08-Island-perimeter.cpp -o output && ./output