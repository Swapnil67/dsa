/**
 * * Leetcode - 2316
 * * Number of Islands
 *
 * * Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
 * * return the number of islands.
 *
 * * Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
 * * return the number of islands.
 *
 * * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
 * * You may assume all four edges of the grid are all surrounded by water.
 * 
 * * Example 1  :
 * * Input      : grid = [
 * *                      ["1","1","1","1","0"],
 * *                      ["1","1","0","1","0"],
 * *                      ["1","1","0","0","0"],
 * *                      ["0","0","0","0","0"]]
 * * Output     : 1

 * * Example 2  :
 * * Input      : grid = [
 * *                      ["1","1","0","0","0"],
 * *                      ["1","1","0","0","0"],
 * *                      ["0","0","1","0","0"],
 * *                      ["0","0","0","1","1"]]
 * * Output     : 0
 * 
 * * https://leetcode.com/problems/number-of-islands/description/
*/

#include <queue>
#include <vector>
#include <iostream>

typedef std::vector<char> vc;

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

void dfs(int x, int y, std::vector<std::vector<int>> &visited, std::vector<vc>& grid) {
  int m = grid.size(); 
  int n = grid[0].size(); 

  // * Edge cases
  if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0' || visited[x][y]) {
    return;
  }

  visited[x][y] = 1;

  for (auto &dir : dirs) {
    int new_x = x + dir[0]; 
    int new_y = y + dir[1];
    dfs(new_x, new_y, visited, grid);
  }
}

// * ------------------------- Approach 1: Optimal -------------------------
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n) + O(m + n)
int numIslandsDFS(std::vector<vc>& grid) {
  int m = grid.size(); 
  int n = grid[0].size(); 
  int islands = 0;

  std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '1' && !visited[i][j]) {
        dfs(i, j, visited, grid);
        islands++;
      }
    }
  }

  return islands;
}

void bfs(int x, int y, std::vector<std::vector<int>> &visited, std::vector<vc> &grid) {
  int m = grid.size(); 
  int n = grid[0].size(); 
  visited[x][y] = 1;
  std::queue<std::pair<int, int>> q;
  q.push({x, y});

  while (!q.empty()) {
    auto p = q.front();
    q.pop();

    int row = p.first, col = p.second;

    // * Traverse in neighbours and mark them it it's a land
    for (auto &dir : dirs) {
      int new_x = row + dir[0];
      int new_y = col + dir[1];

      if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || grid[new_x][new_y] == '0') {
        continue;
      }

      if (!visited[new_x][new_y]) {
        visited[new_x][new_y] = 1;
        q.push({new_x, new_y});
      }
    }
  }
}

// * ------------------------- Approach 2: Optimal -------------------------
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n) + O(m + n)
int numIslandsBFS(std::vector<vc>& grid) {
  int m = grid.size(); 
  int n = grid[0].size(); 
  int islands = 0;

  std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '1' && !visited[i][j]) {
        bfs(i, j, visited, grid);
        islands++;
      }
    }
  }

  return islands;
}

int main(void) {
  // * testcase 1
  // std::vector<vc> grid = {
  //     {'1', '1', '1', '1', '0'},
  //     {'1', '1', '0', '1', '0'},
  //     {'1', '1', '0', '0', '0'},
  //     {'0', '0', '0', '0', '0'}};

  // * testcase 2
  std::vector<vc> grid = {
      {'1', '1', '0', '0', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '1', '0', '0'},
      {'0', '0', '0', '1', '1'}};

  std::cout << "grid: " << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  int ans = numIslandsDFS(grid);
  // int ans = numIslandsBFS(grid);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 08-no-of-Islands.cpp -o output && ./output