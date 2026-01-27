/*
 * Leetcode - 1267
 * Count Servers that Communicate
 *
 * You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell
 * there is a server and 0 means that it is no server. Two servers are said to communicate if they are on 
 * the same row or on the same column.

 * Return the number of servers that communicate with any other server.

 * Example 1  :
 * Input      : grid = [[1,0],[0,1]]
 * Output     : 0

 * Example 2  :
 * Input      : grid = [[1,0],[1,1]]
 * Output     : 3

 * Example 3  :
 * Input      : grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
 * Output     : 4
 * 
 * https://leetcode.com/problems/count-servers-that-communicate
*/

#include <vector>
#include <numeric>
#include <iostream>

// ! Google, Microsoft, Amazon, Meta, Oracle

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

int find(int x, std::vector<int> &parent) {
  if (x == parent[x]) {
    return x;
  }
  return parent[x] = find(parent[x], parent);
}

void Union(int x, int y, std::vector<int> &parent, std::vector<int> &rank) {
  int x_parent = find(x, parent);
  int y_parent = find(y, parent);

  if (x_parent == y_parent)
    return;

  if (rank[x_parent] > rank[y_parent]) {
    parent[y_parent] = x_parent;
  }
  else if (rank[y_parent] > rank[x_parent]) {
    parent[x_parent] = y_parent;
  }
  else {
    parent[x_parent] = y_parent;
    rank[y_parent]++;
  }
}

// * ------------------------- Approach 1: Brute Force Apprach -------------------------
// * Loop over the whole grid
// * TIME COMPLEXITY O(m * n^2)
// * SPACE COMPLEXITY O(1)
int countServersBrute(std::vector<std::vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  int res = 0;

  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == 0)
        continue;

      bool found = false;

      // * check in same row
      for (int col = 0; col < n; ++col) {
        if (col != c && grid[r][col] == 1) {
          found = true;
          break;
        }
      }

      // * check in same col
      if (!found) {
        for (int row = 0; row < m; ++row) {
          if (row != c && grid[row][c] == 1) {
            found = true;
            break;
          }
        }
      }

      // * If server found in same row or col
      if (found)
        res++;
    }
  }

  return res;
}

// * ------------------------- Approach 2: Better Approach -------------------------
// * Using DSU
// * TIME COMPLEXITY O(m ∗ n ∗ Alpha(m ∗ n))
// * SPACE COMPLEXITY O(m * n)
int countServers(std::vector<std::vector<int>>& grid) {
  int ROWS = grid.size(), COLS = grid[0].size();

  // * DSU boilerplate
  int n = ROWS * COLS;
  std::vector<int> rank(n, 1);
  std::vector<int> parent(n);
  std::iota(begin(parent), end(parent), 0);
  
  std::vector<int> row_servers_cnt(ROWS, 0); // * no of servers in each row
  std::vector<int> col_servers_cnt(COLS, 0); // * no of servers in each col
  for (int r = 0; r < ROWS; ++r) {
    for (int c = 0; c < COLS; ++c) {
      if (grid[r][c] == 1) {
        Union(r, c, parent, rank);

        int r_parent = find(r, parent);
        int c_parent = find(c, parent);
        if (r_parent == c_parent) {
          row_servers_cnt[r]++;
          col_servers_cnt[c]++;
        }
      }
    }
  }

  // * For debugging
  std::cout << "Servers count in each row & col" << std::endl;
  printArr(row_servers_cnt);
  printArr(col_servers_cnt);

  int res = 0;
  for (int r = 0; r < ROWS; ++r) {
    for (int c = 0; c < COLS; ++c) {
      // * If either of current row & col has more than 1 server
      if (grid[r][c] == 1 && std::max(row_servers_cnt[r], col_servers_cnt[c]) > 1) {
        res += 1;
      }
    }
  }

  return res;
}


// * ------------------------- Approach 3: Better Approach -------------------------
// * More easy
// * Save the server count on each row and col in separate array
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(m * n)
int countServersBetter(std::vector<std::vector<int>>& grid) {
  int ROWS = grid.size(), COLS = grid[0].size();

  std::vector<int> row_servers_cnt(ROWS, 0); // * no of servers in each row
  std::vector<int> col_servers_cnt(COLS, 0); // * no of servers in each col

  for (int r = 0; r < ROWS; ++r) {
    for (int c = 0; c < COLS; ++c) {
      if (grid[r][c] == 1) {
        row_servers_cnt[r] += 1;
        col_servers_cnt[c] += 1;
      }
    }
  }

  // * For debugging
  std::cout << "Servers count in each row & col" << std::endl;
  printArr(row_servers_cnt);
  printArr(col_servers_cnt);
  
  int res = 0;
  for (int r = 0; r < ROWS; ++r) {
    for (int c = 0; c < COLS; ++c) {
      // * If either of current row & col has more than 1 server
      if (grid[r][c] == 1 && std::max(row_servers_cnt[r], col_servers_cnt[c]) > 1) {
        res += 1;
      }
    }
  }

  return res;
}


int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> grid = {{1, 0}, {0, 1}};

  // * testcase 2
  // std::vector<std::vector<int>> grid = {{1, 0}, {1, 1}};

  // * testcase 3
  std::vector<std::vector<int>> grid = {{1, 1, 0, 0},
                                        {0, 0, 1, 0},
                                        {0, 0, 1, 0},
                                        {0, 0, 0, 1}};

  // * testcase 4
  // std::vector<std::vector<int>> grid = {{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  //                                       {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
  //                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  //                                       {0, 1, 0, 0, 0, 0, 0, 1, 0, 0}};

  std::cout << "grid: " << std::endl;
  for (auto &vec : grid)
    printArr(vec);

  // int ans = countServersBrute(grid);
  int ans = countServersBetter(grid);
  // int ans = countServers(grid);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 24-cnt-servers-that-communicate.cpp -o output && ./output