/*
 * Leetcode - 542
 * Path With Minimum Effort
 * 
 * Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

 * The distance between two cells sharing a common edge is 1.

 * Example 1  :
 * Input      : heights = [[0,0,0],[0,1,0],[0,0,0]]
 * Output     : [[0,0,0],[0,1,0],[0,0,0]]

 * Example 2  :
 * Input      : heights = [[0,0,0],[0,1,0],[1,1,1]]
 * Output     : [[0,0,0],[0,1,0],[1,2,1]]

 * https://leetcode.com/problems/01-matrix/description/
 * https://www.naukri.com/code360/problems/distance-of-nearest-cell-having-1-in-a-binary-matrix_1169913
 * https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
*/

// ! BFS

// ! Google, Amazon

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
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

const std::vector<std::vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// * ------------------------- APPROACH 1: Brute Force Approach -------------------------`
// * Go to every co-ordinate of 0 and do BFS from that position and find distance
// * Just explain this don't code

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Find the distance from 0s to 1s instead of 1s to 0s
// * TIME COMPLEXITY O(m x n)
// * SPACE COMPLEXITY O(m x n)
std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
  int m = mat.size(), n = mat[0].size();
  std::vector<std::vector<int>> result(m, std::vector<int>(n, -1));
  std::queue<std::pair<int, int>> q;

  // * push all the co-ordinates which has element 0 to `q`
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mat[i][j] == 0) {
        result[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  // * To check out of boundary
  const auto is_safe = [&](const int &x, const int &y) {
    return x >= 0 && x < m && y >= 0 && y < n;
  };

  // * Classic BFS
  while (!q.empty()) {
    auto p = q.front();
    q.pop();

    int x = p.first, y = p.second;

    // * Go to adjacent cells
    for (auto &dir: dirs) {
      int dx = x + dir[0];
      int dy = y + dir[1];
      if (is_safe(dx, dy) && result[dx][dy] == -1) {
        result[dx][dy] = result[x][y] + 1;
        q.push({dx, dy});
      }
    }
  }

  return result;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

  // * testcase 2
  std::vector<std::vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};

  std::cout << "mat" << std::endl;
  for (auto &vec : mat)
    printArr(vec);

  std::vector<std::vector<int>> ans = updateMatrix(mat);
  std::cout << "Answer: " << std::endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}

// * Run the code
// * g++ --std=c++20 17-01-matrix.cpp -o output && ./output

 