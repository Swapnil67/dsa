/*
 * Leetcode - 304
 * Range Sum Query 2D Immutable
 * 
 * 
 * https://neetcode.io/problems/range-sum-query-2d-immutable/
 * https://leetcode.com/problems/range-sum-query-2d-immutable/
*/

// ! Amazon, Google, Meta, Microsoft

#include <vector>
#include <iostream>

using namespace std;


template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

vector<vector<int>> matrix;

// * ------------------------- Approach 1: Brute Force Approach -------------------------

// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(1)
int bruteForce(int r1, int c1, int r2, int c2) {
  int ans = 0;
  for (int r = r1; r <= r2; ++r) {
    for (int c = c1; c <= c2; ++c) {
      ans += matrix[r][c];
    }
  }
  return ans;
}

// * ------------------------- Approach 2: Optimal Approach -------------------------

// * TIME COMPLEXITY O(1)
// * SPACE COMPLEXITY O(m * n)
int sumRegion(int r1, int c1, int r2, int c2) {
  int m = matrix.size(), n = matrix[0].size();

  vector<vector<int>> prefix_mat(m + 1, vector<int>(n + 1, 0));
  for (int r = 0; r < m; ++r) {
    int prefix = 0;
    for (int c = 0; c < n; ++c) {
      prefix += matrix[r][c];
      int above = prefix_mat[r][c + 1];
      prefix_mat[r + 1][c + 1] = prefix + above;
    }
  }

  cout << "Prefix Sum Matrix" << endl;
  for (auto &vec: prefix_mat) {
    printArr(vec);
  }
  
  int ans = 0;
  r1++, r2++, c1++, c2++;
  int bottom_right = prefix_mat[r2][c2];
  int above = prefix_mat[r1 - 1][c2]; // * row above matrix.
  int left = prefix_mat[r2][c1 - 1];  // * row left to matrix.
  int top_left = prefix_mat[r1 - 1][c1 - 1];

  return (bottom_right - above - left + top_left);
}

int main(void) {
  matrix = {{3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}};

  // * testcase 1
  // int r1 = 2, c1 = 1, r2 = 4, c2 = 3;

  // * testcase 2
  // int r1 = 1, c1 = 1, r2 = 2, c2 = 2;

  // * testcase 3
  int r1 = 1, c1 = 2, r2 = 2, c2 = 4;

  cout << "Input Matrix" << endl;
  for (auto &vec: matrix) {
    printArr(vec);
  }

  // int ans = bruteForce(r1, c1, r2, c2);
  int ans = sumRegion(r1, c1, r2, c2);
  cout << "Region Sum: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 10-range-sum-query-2d-immutable.cpp -o output && ./output
