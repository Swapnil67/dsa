/*
 * Zero Matrix
 * Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
 * You must do it inplace
 * 
 * https://www.naukri.com/code360/problems/zero-matrix_1171153
*/

/*
* i/p      ->    o/p
* 1 1 1 1      1 0 0 1
* 1 0 0 1  ->  0 0 0 0
* 1 1 0 1      0 0 0 0
* 1 1 1 1      1 0 0 1
*/

#include<iostream>

// * Print the matrix
void printMatrix(std::vector<std::vector<int>> matrix, int r, int c) {
  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      std::cout << matrix[i][j]<<" ";
    }
    std::cout << std::endl;
  }
}

// * Mark Row -1
void markRowForZero(int row, std::vector<std::vector<int>> &matrix, int r, int c) {
  for (int i = 0; i < c; i++) {
    matrix[row][i]  = -1;
  }
}

// * Mark Col -1
void markColForZero(int col, std::vector<std::vector<int>> &matrix, int r, int c) {
  for (int i = 0; i < r; i++) {
    matrix[i][col]  = -1;
  }
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(r * c) * 0(r + c) + O(r + c)
// * SPACE COMPLEXITY O(1)
void bruteForce(std::vector<std::vector<int>> &matrix, int r, int c) {

  // *  O(r * c)
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      // *  O(r + c)
      if(matrix[i][j] == 0) {
        markRowForZero(i, matrix, r, c);
        markColForZero(j, matrix, r, c);
      }
    }
  }

  // *  O(r * c)
  // * Set all -1 to 0 to create zero matrix
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if(matrix[i][j] == -1) {
        matrix[i][j] = 0;
      }
    }
  }
}

int main() {
  std::vector<std::vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}};
  int rows = 4, cols = 4;
  std::cout << "Input Matrix" << std::endl;
  printMatrix(matrix, rows, cols);
  std::cout << "\nZero Matrix" << std::endl;
  bruteForce(matrix, rows, cols);
  printMatrix(matrix, rows, cols);
  return 0;
}

// * Run the code
// * g++ --std=c++17 01-zero-matrix.cpp -o 01-zero-matrix && ./01-zero-matrix