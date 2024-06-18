/*
 * Zero Matrix
 * Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
 * You must do it inplace
 * 
 * https://leetcode.com/problems/set-matrix-zeroes/description/
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
// * Mark -1 to all which are zeros
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

// * ------------------------- APPROACH 2: Better APPROACH -------------------------`
// * Create two vectors for maintaining zero rows and columns
// * TIME COMPLEXITY O(2(r * c))
// * SPACE COMPLEXITY O(r) + O(c)
void betterApproach(std::vector<std::vector<int>> &matrix, int r, int c) {
  std::vector<int> zeroRows(r, 0);
  std::vector<int> zeroCols(c, 0);

  // * O(r * c)
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if(matrix[i][j] == 0) {
        zeroRows[i] = 1;
        zeroCols[j] = 1;
      }
    }
  }

  // * O(r * c)
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if(zeroRows[i] == 1 || zeroCols[j] == 1) {
        matrix[i][j] = 0;
      }
    } 
  }
}


// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// ! Only Space complexity is optimized
// * Create two vectors for maintaining zero rows and columns 
// * TIME COMPLEXITY O(2(r * c))
// * SPACE COMPLEXITY O(1)
void optimalApproach(std::vector<std::vector<int>> &matrix, int r, int c) {
  int col0 = 1;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if(matrix[i][j] == 0) {
        // * mark i-th row to 1
        matrix[i][0] = 0;

        // * mark j-th col to 1
        if(j == 0) {
          col0 = 0;
        }
        else {
          matrix[0][j] = 0;
        }
      }
    }
  }

  for (int i = 1; i < r; i++) {
    for (int j = 1; j < c; j++) {
      if(matrix[i][j] != 0) {
        if(matrix[0][i] == 0 || matrix[j][0] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
  }

  // * Mark first row
  if(matrix[0][0] == 0) {
    for (int j = 0; j < c; j++) {
      matrix[0][j] = 0;
    }
  }

  // * Mark first col
  if(col0 == 0) {
    for (int i = 0; i < r; i++) {
      matrix[i][0] = 0;
    } 
  }

}


int main() {
  std::vector<std::vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}};
  int rows = 4, cols = 4;
  std::cout << "Input Matrix" << std::endl;
  printMatrix(matrix, rows, cols);

  std::cout << "\nZero Matrix" << std::endl;
  // bruteForce(matrix, rows, cols);
  // betterApproach(matrix, rows, cols);
  optimalApproach(matrix, rows, cols);
  
  printMatrix(matrix, rows, cols);
  return 0;
}

// * Run the code
// * g++ --std=c++17 01-zero-matrix.cpp -o 01-zero-matrix && ./01-zero-matrix