/*
 * Leetcode - 74
 * Search a 2D Matrix
 * 
 * You are given an m x n integer matrix matrix with the following two properties:
 *  - Each row is sorted in non-decreasing order.
 *  - The first integer of each row is greater than the last integer of the previous row.
 * 
 * Given an integer target, return true if target is in matrix or false otherwise.
 * 
 * https://leetcode.com/problems/search-a-2d-matrix/description/
*/

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &nums) {
  int n = nums.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << nums[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * ------------------------- APPROACH 1: Brute APPROACH -------------------------
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(1)
bool bruteForce(vector<vector<int>> &matrix, int target) {
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
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int rows = matrix.size();
  int cols = matrix[0].size();
  int l = 0, r = rows - 1;

  // * Using lower bound find the row which we need to search for target element
  int possibleRow = r;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (matrix[m][cols - 1] >= target) {
      possibleRow = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  // * Search the target element in 'possibleRow'
  l = 0, r = cols - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (matrix[possibleRow][m] == target)
      return true;
    else if (matrix[possibleRow][m] > target)
      r = m - 1; 
    else 
      l = m + 1;
  } 

  return false;
}


int main(void) {
  // * testcase 1
  // int target = 3;
  // vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

  // * testcase 2
  int target = 13;
  vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

  cout << "Target: " << target << endl;
  cout << "Input Matrix" << endl;
  for (auto &v : matrix)
    printArr(v);

  // bool isFound = bruteForce(matrix, target);
  bool isFound = searchMatrix(matrix, target);

  cout << "Found: " << isFound << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 08-search-in-2D-matrix.cpp -o output && ./output


