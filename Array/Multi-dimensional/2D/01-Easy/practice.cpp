#include<iostream>

// * Print the matrix
void printMatrix(std::vector<std::vector<int>> matrix) {
  int n = matrix.size(), m = matrix[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void reverse(std::vector<int> &arr) {
  int n = arr.size();
  int s = 0, e = n - 1;
  while(s < e) {
    swap(arr[s++], arr[e--]);
  }
}

// * Zero Matrix

void markMinuxOne(std::vector<std::vector<int>> &matrix, int row, int col) { 
  int n = matrix.size(), m = matrix[0].size();
  // * Mark Col -1 
  for (int i = 0; i < n; i++) {
    matrix[i][col] = -1;
  }

  // * Mark Row -1
  for (int i = 0; i < m; i++) {
    matrix[row][i] = -1;
  }
}

void zeroMatrixBrute(std::vector<std::vector<int>> &matrix) { 
  int n = matrix.size(), m = matrix[0].size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(matrix[i][j] == 0) {
        markMinuxOne(matrix, i, j);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(matrix[i][j] == -1) {
        matrix[i][j] = 0;
      }
    }
  }
}

void zeroMatrixBetter(std::vector<std::vector<int>> &matrix) { 

  int n = matrix.size(), m = matrix[0].size();
  std::vector<int> markRows(n, 0), markCols(m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(matrix[i][j] == 0) {
        markRows[i] = 1;
        markCols[j] = 1;
      }
    }
  }

  // * O(r * c)
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(markRows[i] == 1 || markCols[j] == 1) {
        matrix[i][j] = 0;
      }
    } 
  }

}

void zeroMatrixOptimal(std::vector<std::vector<int>> &matrix) { 
  int n = matrix.size(), m = matrix[0].size();
  int col0 = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(matrix[i][j] == 0) {
        matrix[i][0] = 0;

        if(j == 0) {
          col0 = 0;
        }
        else {
          matrix[0][j] = 0;
        }
      }
    }
  }

  // * Mark matrix except for first row & col
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if(matrix[0][i] == 0 || matrix[j][0] == 0) {
        matrix[i][j] = 0;
      }
    }
  }

  // * Mark first row
  if(matrix[0][0] == 0) {
    for (int j = 0; j < m; j++) {
      matrix[0][j] = 0;
    }
  }

  // * Mark first col
  if(col0 == 0) {
    for (int i = 0; i < n; i++) {
      matrix[i][0] = 0;
    }
  }
}

// * Rotate Matrix

std::vector<std::vector<int>> rotateBrute(std::vector<std::vector<int>> matrix) {
  int n = matrix.size(), m = matrix[0].size();
  std::vector<std::vector<int>> ans(m, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans[j][n - i - 1] = matrix[i][j];
    }
  }
  return ans;
}

// * Intuition =  Transpose + Reverse
void rotateMatrixOptimal(std::vector<std::vector<int>> &matrix) {
  int n = matrix.size(), m = matrix[0].size();
  // * Transpose Matrix
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  // * Reverse every row
  for (int i = 0; i < n; i++) {
    reverse(matrix[i]);
  }
}

int main() {
  // * Problem 1 
  // * Zero Matrix
  // std::vector<std::vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}};
  // std::cout << "Input Matrix" << std::endl;
  // printMatrix(matrix);
  // zeroMatrixBrute(matrix);
  // zeroMatrixBetter(matrix);
  // zeroMatrixOptimal(matrix);
  // std::cout << "Zero Matrix" << std::endl;
  // printMatrix(matrix);

  // * Problem 2
  // * Rotate Matrix
  // std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // std::cout << "Input Matrix" << std::endl;
  // printMatrix(matrix);
  // std::vector<std::vector<int>> ans = rotateBrute(matrix);
  // std::cout << "Rotated Matrix" << std::endl;
  // printMatrix(ans);
  // std::cout << "Rotated Matrix" << std::endl;
  // rotateMatrixOptimal(matrix);
  // printMatrix(matrix);


  return 0;
}

// * g++ --std=c++17 practice.cpp -o practice && ./practice

/*
 * Example 

 * Input
 * 1 2 3
 * 4 5 6
 * 7 8 9

 * Output
 * 7 4 1
 * 8 5 2
 * 9 6 3
 * 
 * [i][j] = [j][n-i]
 * [0][0] = [0][2]
 * [0][1] = [1][2]
 * [0][2] = [2][2]
 * 
 * [1][0] = [0][1]
 * [1][1] = [1][1]
 * [1][2] = [2][1]

*/