#include<iostream>
#include<vector>

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

class NumMatrix {
  public: 
    std::vector<std::vector<int>> prefixMatrix;

    NumMatrix(std::vector<std::vector<int>> matrix) {
      int r = matrix.size(), c = matrix[0].size();
      std::vector<std::vector<int>> temp(r + 1, std::vector<int>(c + 1, 0));
    
      for (int i = 0; i < r; ++i) {
        int sum = 0;
        for (int j = 0; j < c; ++j) { 
          sum += matrix[i][j];
          int above = temp[i][j + 1];
          temp[i + 1][j + 1] = sum + above;
        }
      }

      this->prefixMatrix = temp;
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
      r1 = r1 + 1, c1 = c1 + 1, r2 = r2 + 1, c2 = c2 + 1;
      int bottomRight = this->prefixMatrix[r2][c2];
      int above = this->prefixMatrix[r1 - 1][c2];
      int left = this->prefixMatrix[r2][c1 - 1];
      int topLeft = this->prefixMatrix[r1 - 1][c1 - 1];

      return bottomRight - above - left + topLeft;
    }

};

int main() {
  // std::vector<std::vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
  std::vector<std::vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 2}, {1, 3, 2, 4}, {1, 5, 6, 2}};
  printMatrix(matrix);

  NumMatrix m1 = NumMatrix(matrix);
  // printMatrix(m1.prefixMatrix);
  int sum = m1.sumRegion(1,1,2,3);

  std::cout << "Sum region: " << sum << std::endl;

  return 0;
}

// *  run the code
// * g++ --std=c++17 07-range-sum-query.cpp -o output && ./output
