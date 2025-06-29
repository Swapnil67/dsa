/**
 * * Leetcode - 74
 * * Search a 2D Matrix
 * * You are given an m x n integer matrix matrix with the following two properties:
 * *  - Each row is sorted in non-decreasing order.
 * *  - The first integer of each row is greater than the last integer of the previous row.
 * * 
 * * Given an integer target, return true if target is in matrix or false otherwise.
 * * https://leetcode.com/problems/search-a-2d-matrix/description/
 * 
*/

#include <vector>
#include <iostream>

void printMatrix(std::vector<std::vector<int>> &matrix) {
  int r = matrix.size();
  int c = matrix[0].size();

  for (int y = 0; y < r; ++y) {
    for (int x = 0; x < c; ++x) {
      std::cout<<matrix[y][x]<<" ";
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;
}


// * ------------------------- APPROACH 1: Brute APPROACH -------------------------
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


// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(2*logn)
// * SPACE COMPLEXITY O(1)
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
  int rows = matrix.size();
  int cols = matrix[0].size();
  int l = 0, r = rows - 1;

  // * Using lower bound find the row which we need to search for target element
  int searchRow = r;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (matrix[m][cols - 1] >= target) {
      searchRow = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }

  // * Search the target element in that row
  l = 0, r = cols - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (matrix[searchRow][m] == target) {
      return true;
      r = m - 1;
    }
    else if(matrix[searchRow][m] > target) {
      r = m - 1; 
    }
    else {
      l = m + 1;
    }
  } 

  return false;
}


int main(void) {
  // * testcase 1
  int target = 3;
  std::vector<std::vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

  // * testcase 2
  // int target = 13;
  // std::vector<std::vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

  printMatrix(matrix);

  // bool isFound = bruteForce(matrix, target);
  bool isFound = searchMatrix(matrix, target);
  std::cout << isFound << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 08-search-in-2D-matrix.cpp -o output && ./output


