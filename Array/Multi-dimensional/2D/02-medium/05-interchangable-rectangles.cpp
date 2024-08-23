/*
 * Number of Pairs of Interchangeable Rectangles

 * https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/description/
*/

#include<iostream>
#include<unordered_set>

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

int bruteForce(std::vector<std::vector<int>> rectangles) {
  int c = 0;
  int r = rectangles.size();
  for (int i = 0; i < r; ++i) {
    float ratio1 = (float)rectangles[i][0] / (float)rectangles[i][1];
    for (int j = i + 1; j < r; ++j) {
      float ratio2 = (float)rectangles[j][0] / (float)rectangles[j][1];
      if(ratio1 == ratio2)
        c++;
    }
  }
  return c;
}

int getValue(int n, int r) {
  int res = 1;
  for (int i = 0; i < r; i++) {
    res = res * (n - i);
    res = res / (i + 1);
  }
  return res;
}


// * Combination Problem (nCr)
// * => n! / r! * (n-r)!  (Not Linear)
// * => n * (n - 1) / r   (Linear)

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
long long interchangeableRectangles(std::vector<std::vector<int>> rectangles) {
  int r = rectangles.size();
  std::unordered_map<float, int> ratiosMap;
  long double ratio;
  // * calculate the ratio count
  for (int i = 0; i < r; ++i) {
    ratio = (long double)rectangles[i][0] / (long double)rectangles[i][1];
    ratiosMap[ratio]++;
  }
  long long c = 0;
  for(auto it : ratiosMap) {
    if(it.second > 1) {
      // std::cout << it.second << std::endl;
      c = c + (long long)it.second * (long long)(it.second - 1) / 2;
    }
  }
  return c;
}

int main() {
  std::vector<std::vector<int>> rectangles = {{4, 8}, {3, 6}, {10, 20}, {15, 30}};
  // std::vector<std::vector<int>> rectangles = {{4, 5}, {7, 8}};
  // printMatrix(rectangles);
  // int ans = bruteForce(rectangles);
  int ans = interchangeableRectangles(rectangles);
  std::cout << "Number of pairs of interchangaeble rectangles are " << ans << std::endl;
  return 0;
}

// * run the code 
// * g++ --std=c++17 05-interchangable-rectangles.cpp -o output && ./output