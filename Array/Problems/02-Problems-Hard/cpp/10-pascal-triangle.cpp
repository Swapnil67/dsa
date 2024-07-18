/*
 * Pascal Triangle
 * 
 * Example 1:
 * Input: n = 5
 * Output: 1 
 *         1 1 
 *         1 2 1 
 *         1 3 3 1 
 *         1 4 6 4 1 

 * Example 2:
 * Input: n = 1
 * Output: 1
 * 
 * https://leetcode.com/problems/pascals-triangle/description/
 * https://www.naukri.com/code360/problems/pascal-s-triangle_1089580
 * https://www.naukri.com/code360/problems/print-pascal-s-triangle_6917910
*/

#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void print2DArr(std::vector<std::vector<int>> arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

// * Get value of given row and columns
// * Time Complexity T(N) = O(r)
// * nCr = n!/r! * (n-r)!
int getValue(int n, int r) {
  int res = 1;
  for (int i = 0; i < r; i++) {
    res = res * (n - i);
    res = res / (i + 1);
  }
  return res;
}

// * Pascal Row
// * Time Complexity = O(N)
std::vector<int> pascalRow(int n) {
  int ans = 1;
  std::vector<int> rowVec;
  rowVec.push_back(1);
  for (int i = 1; i < n; i++) {
    ans = ans * (n - i);
    ans = ans / i;
    rowVec.push_back(ans);
  }
  return rowVec;
}

// * Pascal Triangle
// * Time Complexity = O(N * N)
std::vector<std::vector<int>> pascalTringe(int n) {
  std::vector<std::vector<int>> triangle;
  for (int i = 1; i <= n; i++) {
    std::vector<int> row = pascalRow(i);
    triangle.push_back(row);
  }
  return triangle;
}

int main() {
  // * Print value at particular row & column
  int n = 4, r = 2;
  int val = getValue(n, r);
  std::cout << "Val of " << n << "C" << r << " is: " << val << std::endl;

  // * Print Pascal Row
  int row = 5;
  std::cout << "------ Pascal Row -------" << std::endl;
  std::cout << row << " pascal row: ";
  std::vector<int> ans = pascalRow(row);
  printArr(ans);

  // * Pascal Triangle
  std::cout << "------ Pascal Triangle ------" << std::endl;
  std::vector<std::vector<int>> triangle = pascalTringe(5);
  print2DArr(triangle);

  return 0;
}

// * Run the code
// * g++ --std=c++17 10-pascal-triangle.cpp -o 10-pascal-triangle && ./10-pascal-triangle