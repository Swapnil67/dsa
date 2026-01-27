/*
 * Champagne Tower
 *
 * We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.
 * Each glass holds one cup of champagne.
 * 
 * Then, some champagne is poured into the first glass at the top.  When the topmost glass is full, any excess liquid poured 
 * will fall equally to the glass immediately to the left and right of it. 
 * When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.
 * (A glass at the bottom row has its excess champagne fall on the floor.)
 * 
 * For example, after one cup of champagne is poured, the top most glass is full.  After two cups of champagne are poured, 
 * the two glasses on the second row are half full.  After three cups of champagne are poured, those two cups become full 
 * there are 3 full glasses total now.  After four cups of champagne are poured, the third row has the middle glass half full, 
 * and the two outside glasses are a quarter full, as pictured below.

 * Input: poured = 1, query_row = 1, query_glass = 1
 * Output: 0.00000
 * 
 * Input: poured = 2, query_row = 1, query_glass = 1
 * Output: 0.5

 * https://leetcode.com/problems/champagne-tower/description/
*/


#include<iostream>

template <typename T>
void printMatrix(std::vector<std::vector<T>> matrix) {
  int r = matrix.size(), c = matrix[0].size();
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

// * TIME COMPLEXITY O(100 x 100)
// * SPACE COMPLEXITY O(100 x 100)
double champagneTower(int poured, int query_row, int query_glass) {
  // * Initialize the tower
  // double tower[101][101] = {0.0}; // * OR
  std::vector<std::vector<double>> tower(10, std::vector<double>(10, 0.0));
  tower[0][0] = poured;
  for (int i = 0; i <= poured; ++i) {
    for (int j = 0; j <= i; ++j) {
      if(tower[i][j] >= 1) {
        tower[i + 1][j] += (double)(tower[i][j] - 1) / 2.0;
        tower[i + 1][j + 1] += (double)(tower[i][j] - 1) / 2.0;
        tower[i][j] = 1;
      }
    }
  }
  // * Debugging
  printMatrix(tower);
  return tower[query_row][query_glass];
}

int main() {
  // int poured = 3, query_row = 1, query_glass = 1;
  int poured = 4, query_row = 2, query_glass = 1;
  double ans = champagneTower(poured, query_row, query_glass);
  std::cout << "Answer " << ans << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 08-champagne-tower.cpp -o output && ./output