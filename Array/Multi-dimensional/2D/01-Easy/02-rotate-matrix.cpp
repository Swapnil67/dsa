/*
 * For a given 2D array of rotate it to 90 degree

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
 * https://www.naukri.com/code360/problems/rotate-the-matrix_6825090
*/

#include<iostream>


// * ------------------------- Utility Methods -------------------------
void printMatrix(std::vector<std::vector<int>> matrix) {
  int r = matrix.size(), c = matrix[0].size();
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      std::cout<<matrix[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
  std::cout<<std::endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void reverse(std::vector<int> &arr) {
  int n = arr.size();
  int start = 0, end = n-1;
  while(start < end) {
    swap(arr[start++], arr[end--]);
  }
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Check the existing and new positions of elements
// * Space Complexity O(N^2)
// * Time Complexity O(N^2)
std::vector<std::vector<int>> bruteForce(std::vector<std::vector<int>> &matrix) {
  int r = matrix.size(), c = matrix[0].size();
  std::vector<std::vector<int>> ans(r, std::vector<int>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      ans[j][(r-1)-i] = matrix[i][j];
    }
  } 
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Transpose + Reverse Matrix
// * Space Complexity O(N^2)
// * Time Complexity O(1)
void rotateMatrix(std::vector<std::vector<int>> &matrix) {
  int r = matrix.size(), c = matrix[0].size();
  // * Step 1: Transpose Matrix
  for (int i = 0; i < r-1; i++) {
    for (int j = i+1; j < c; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  // * Reverse the rows of transpose matrix
  for (int i = 0; i < r; i++) {
    reverse(matrix[i]);
  }
}

int main() {
  std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::cout << "Input Matrix" << std::endl;
  printMatrix(matrix);

  // * Brute Force Approach
  // std::vector<std::vector<int>> ans = bruteForce(matrix);
  // printMatrix(ans);

  // * Optimal Approach
  rotateMatrix(matrix);

  std::cout << "Rotated Matrix" << std::endl;
  printMatrix(matrix);

  return 0;
}

// * Run the code
// * g++ --std=c++17 02-rotate-matrix.cpp -o 02-rotate-matrix && ./02-rotate-matrix