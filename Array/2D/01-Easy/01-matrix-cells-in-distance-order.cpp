/*
 * Leetcode - 1030
 * Matrix Cells in Distance Order
 * 
 * You are given four integers row, cols, rCenter, and cCenter. There is a rows x cols matrix and you are on the cell 
 * with the coordinates (rCenter, cCenter).
 * 
 * Return the coordinates of all cells in the matrix, sorted by their distance from (rCenter, cCenter) from the smallest 
 * distance to the largest distance. You may return the answer in any order that satisfies this condition.
 * 
 * The distance between two cells (r1, c1) and (r2, c2) is |r1 - r2| + |c1 - c2|.
 * 
 * Example 2    :
 * Input        : rows = 1, cols = 2, rCenter = 0, cCenter = 0
 * Output       : 5
 * Explanation  : 
 * 
 * Example 1    :
 * Input        : rows = 2, cols = 2, rCenter = 0, cCenter = 1
 * Output       : 5
 * Explanation  : 
 * 
 * Example 2    :
 * Input        : rows = 2, cols = 3, rCenter = 1, cCenter = 2
 * Output       : 5
 * Explanation  : 
 * 
 * https://leetcode.com/problems/matrix-cells-in-distance-order/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>

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

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(m x n)
// * SPACE COMPLEXITY O(m x n)
vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter,
                                      int cCenter) {
  vector<vector<int>> ans;
  // * For every co-ordinate from {rCenter, cCenter} we'll calculate the Manhattan distance
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      int dr = abs(rCenter - r), dc = abs(cCenter - c);
      int dist = dr + dc;
      // cout << r << " " << c << " -> " << dist << endl;
      ans.push_back({r, c, dist});
    }
  }

  // * Sort by Manhattan Distance
  sort(begin(ans), end(ans), [](const vector<int> &v1, const vector<int> &v2) {
    return v1[2] < v2[2];
  });

  // * Pop the Manhattan Distance from every vector 
  for (vector<int> &vec : ans)
    vec.pop_back();

  return ans;
}

int main(void) {
  // * testcase 1
  // int rows = 1, cols = 2, rCenter = 0, cCenter = 0;

  // * testcase 2
  // int rows = 2, cols = 2, rCenter = 0, cCenter = 1;

  // * testcase 3
  int rows = 2, cols = 3, rCenter = 1, cCenter = 2;

  std::cout << "rows: " << rows << ", cols: " << cols << std::endl;
  std::cout << "rCenter: " << rCenter << ", cCenter: " << cCenter << std::endl;

  std::vector<std::vector<int>> ans = allCellsDistOrder(rows, cols, rCenter, cCenter);
  std::cout << "All Co-ordinates" << std::endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 01-matrix-cells-in-distance-order.cpp -o output && ./output
