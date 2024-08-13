/*
 * Spiral Matrix

 * Example 

 * Input
 * 1 2 3
 * 4 5 6
 * 7 8 9

 * Output
 * 1 2 3 6 9 8 7 4 5 6
 * 
 * https://leetcode.com/problems/spiral-matrix/description/
 * https://www.naukri.com/code360/problems/spiral-matrix_840698
*/

#include<iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void printMatrix(std::vector<std::vector<int>> matrix) {
  int r = matrix.size(), c = matrix[0].size();
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

// * Space Complexity O(r * c)
// * Time Complexity O(r * c)
std::vector<int> spiralMatrix(std::vector<std::vector<int>> matrix) {
  int r = matrix.size(), c = matrix[0].size();
  int top = 0, bottom = r - 1, left = 0, right = c - 1;
  std::vector<int> ans;
  while(top <= bottom && left <= right) {
    for (int i = left; i <= right; ++i) {
      ans.push_back(matrix[top][i]);
    }
    top++;
    for (int i = top; i <= bottom; ++i) {
      ans.push_back(matrix[i][right]);
    }
    right--;
    if (top <= bottom) {
      for (int i = right; i >= left; --i) {
        ans.push_back(matrix[bottom][i]);
      }
      bottom--;
    }
    if (left <= right) {
      for (int i = bottom; i >= top; --i) {
        ans.push_back(matrix[i][left]);
      }
      left++;
    }
  }
  return ans;
}

int main() {
  std::vector<std::vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  std::cout << "Input Matrix" << std::endl;
  printMatrix(matrix);
  std::cout << "Spiral Matrix Print" << std::endl;
  std::vector<int> ans = spiralMatrix(matrix);
  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++17 02-spiral-matrix.cpp -o 02-spiral-matrix && ./02-spiral-matrix
