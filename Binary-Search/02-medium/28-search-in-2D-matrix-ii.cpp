/*
 * Leetcode - 240
 * Search a 2D Matrix II
 * 
 * You are given an m x n integer matrix matrix with the following two properties:
 *  - Each row is sorted in non-decreasing order.
 *  - The first integer of each row is greater than the last integer of the previous row.
 * 
 * Given an integer target, return true if target is in matrix or false otherwise.
 * 
 * Input  : matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
 * Output : true
 * 
 * Input : matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
 * Output : false
 * 
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 * https://www.naukri.com/code360/problems/search-in-a-2d-matrix-ii_1089637
 * 
*/

// ! Amazon

#include <vector>
#include <iostream>

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

bool bSearch(std::vector<int> &nums, int &target) {
  int n = nums.size();
  int l = 0, r = n - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] == target) 
      return true;
    else if (nums[m] > target)  
      r = m - 1;
    else 
      l = m + 1;
  }
  return false;
}

// * ------------------------- APPROACH 1: Brute APPROACH -------------------------
// * m = no. of rows.
// * n = no. of cols.
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(1)
bool bruteForce(std::vector<std::vector<int>> &matrix, int target) {
  int r = matrix.size();
  int c = matrix[0].size();

  for (int y = 0; y < r; ++y) {
    for (int x = 0; x < c; ++x) {
      if (matrix[y][x] == target)
        return true;
    }
  }

  return false;
}

// * ------------------------- APPROACH 2: Better APPROACH -------------------------
// * m = no. of rows.
// * n = no. of cols.
// * TIME COMPLEXITY O(m * log(n))
// * SPACE COMPLEXITY O(1)
bool betterApproach(std::vector<std::vector<int>> &matrix, int target) {
  int m = matrix.size(), n = matrix[0].size();
  for (int r = 0; r < m; ++r) {
    if (bSearch(matrix[r], target) == true)
      return true;
  }

  return false;
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------
// * start at the rightmost corner in the top of grid
// * m = no. of rows.
// * n = no. of cols.
// * TIME COMPLEXITY O(m + n)
// * SPACE COMPLEXITY O(1)
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
  int m = matrix.size(), n = matrix[0].size();
  int r = 0, c = n - 1;
  while (r < m && c > 0) {
    if (matrix[r][c] == target)
      return true;
    else if (matrix[r][c] < target) 
      r++;
    else 
      c++;
  }
}


int main(void) {
  // * testcase 1
  int target = 3;
  std::vector<std::vector<int>> matrix = {{1, 4, 7, 11, 15},
                                          {2, 5, 8, 12, 19},
                                          {3, 6, 9, 16, 22},
                                          {10, 13, 14, 17, 24},
                                          {18, 21, 23, 26, 30}};

  // * testcase 2
  // int target = 20;
  // std::vector<std::vector<int>> matrix = {{1, 4, 7, 11, 15},
  //                                         {2, 5, 8, 12, 19},
  //                                         {3, 6, 9, 16, 22},
  //                                         {10, 13, 14, 17, 24},
  //                                         {18, 21, 23, 26, 30}};

  std::cout << "Target: " << target << std::endl;
  std::cout << "Input Matrix" << std::endl;
  for (auto &vec : matrix)
    printArr(vec);

  // bool isFound = bruteForce(matrix, target);
  // bool isFound = betterApproach(matrix, target);
  bool isFound = searchMatrix(matrix, target);
  std::cout << "Target Found: " << isFound << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 28-search-in-2D-matrix-ii.cpp -o output && ./output


