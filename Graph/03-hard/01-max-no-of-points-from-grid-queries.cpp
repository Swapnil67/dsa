/*
 * Leetcode - 2503
 * Maximum Number of Points From Grid Queries
 *
 * You are given an m x n integer matrix grid and an array queries of size k.
 * Find an array answer of size k such that for each integer queries[i] you start in the top left cell of 
 * the matrix and repeat the following process:

 * - If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if 
 * it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
 * - Otherwise, you do not get any points, and you end this process.
 * 
 * After the process, answer[i] is the maximum number of points you can get. 
 * Note that for each query you are allowed to visit the same cell multiple times.
 * 
 * Return the resulting array answer.

 * * Example 1  :
 * * Input      : grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
 * * Output     : [5,8,1]
 * 
 * * Example 2  :
 * * Input      : grid = [[5,2,1],[1,1,2]], queries = [3]
 * * Output     : [0]
 * 
 * https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/
 * 
 */

// ! Google, Amazon, Microsoft, uber

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

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

// * check out of bound
bool check_not_oob(const int &row, const int &col, std::vector<std::vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  return row >= 0 && row < m && col >= 0 && col < n;
}

const std::vector<std::vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(
    int r, int c,
    int &points, int query,
    std::vector<std::vector<bool>> &visited,
    std::vector<std::vector<int>> &grid)
{
  visited[r][c] = true;
  points += 1;
  for (auto &dir : dirs) {
    int dr = r + dir[0], dc = c + dir[1];
    if (check_not_oob(dr, dc, grid) && !visited[dr][dc] && query > grid[dr][dc]) {
      dfs(dr, dc, points, query, visited, grid);
    }
  }
}

int bfs(
    int query,
    std::vector<std::vector<int>> &grid)
{
  int m = grid.size(), n = grid[0].size();

  int points = 0;
  std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
  visited[0][0] = true;

  std::queue<std::pair<int, int>> q;
  q.push({0, 0});
  while (!q.empty()) {
    int N = q.size();
    while (N--) {
      auto [r, c] = q.front();
      q.pop();

      if (grid[r][c] > query)
        continue;

      points++;

      for (auto &dir : dirs) {
        int dr = r + dir[0], dc = c + dir[1];
        if (check_not_oob(dr, dc, grid) && !visited[dr][dc]) {
          q.push({dr, dc});
          visited[dr][dc] = true;
        }
      }
    }
  }

  return points;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------
// ! TLE
// * TIME COMPLEXITY  O(N) + O(V + 2E) ~ O(N)
// * SPACE COMPLEXITY O(v)
std::vector<int> bruteForce(std::vector<int> &queries, std::vector<std::vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  
  int Q = queries.size();
  std::vector<int> ans(Q);
  for (int i = 0; i < Q; ++i) {
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    int points = 0;
    if (queries[i] > grid[0][0])
      dfs(0, 0, points, queries[i], visited, grid);
    // std::cout << points << std::endl;
    ans[i] = points;
  }
  return ans;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------
// ! TLE
// * TIME COMPLEXITY  O(N) + O(V + 2E) ~ O(N)
// * SPACE COMPLEXITY O(v)
std::vector<int> bruteForceBFS(std::vector<int> &queries, std::vector<std::vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  
  int Q = queries.size();
  std::vector<int> ans(Q);
  for (int i = 0; i < Q; ++i) {
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    int points = 0;
    if (queries[i] > grid[0][0]) {
      points = bfs(queries[i], grid);
    }
    ans[i] = points;
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal  -------------------------`
// * Sort the queries array
// * TIME COMPLEXITY  O(Q(logQ) + m * nlog(m*n))
// * Notice that we won't visit any cell more than once (we mark them visited). 
// * Total cells = m * n and heap can have m * n cells in worst case
// * SPACE COMPLEXITY O(m * n)
std::vector<int> maxPoints(std::vector<int> &queries, std::vector<std::vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  
  int Q = queries.size();
  std::vector<std::pair<int, int>> sorted_queries;
  // * 1. Sort the queries array & store the index so that we don't lose original index
  for (int i = 0; i < Q; ++i) {
    sorted_queries.push_back({queries[i], i});
  }
  std::sort(begin(sorted_queries), end(sorted_queries));  // * Q(logQ)

  std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
  visited[0][0] = true;

  typedef std::pair<int, std::pair<int, int>> P;
  std::priority_queue<P, std::vector<P>, std::greater<>> min_heap;
  min_heap.push({grid[0][0], {0, 0}});
  
  int points = 0;
  std::vector<int> ans(Q, 0);
  for (int i = 0; i < Q; ++i) {
    auto [query, idx] = sorted_queries[i];
    // std::cout << query << std::endl;

    while (!min_heap.empty()) {
      auto [val, p] = min_heap.top();
      if (val >= query)  // * If current cell value is greater than equal to query then break
        break;

      // std::cout << "\t" << val << std::endl;
      min_heap.pop();
      points++;

      // * Go to current cell neighbours
      for (auto &dir: dirs) {
        int dr = p.first + dir[0], dc = p.second + dir[1];
        if (check_not_oob(dr, dc, grid) && !visited[dr][dc]) {
          visited[dr][dc] = true;
          min_heap.push({grid[dr][dc], {dr, dc}});
        }
      }
    }

    ans[idx] = points;
  }
  return ans;

}

int main(void) {
  // * testcase 1
  std::vector<int> queries = {5, 6, 2};
  std::vector<std::vector<int>> grid = {{1, 2, 3}, {2, 5, 7}, {3, 5, 1}};
  
  // * testcase 2
  // std::vector<int> queries = {3};
  // std::vector<std::vector<int>> grid = {{5, 2, 1}, {1, 1, 2}};

  std::cout << "Queries: ";
  printArr(queries);
  std::cout << "-------- Grid -------- " << std::endl;
  for (auto &vec : grid)
    printArr(vec);
  
  // std::vector<int> ans = bruteForce(queries, grid);
  std::vector<int> ans = maxPoints(queries, grid);
  std::cout << "-------- Answer -------- " << std::endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-max-no-of-points-from-grid-queries.cpp -o output && ./output
