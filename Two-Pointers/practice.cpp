#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

template <typename T>
void printArr(std::vector<T> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void printMatrix(std::vector<std::vector<T>> matrix) {
  int r = matrix.size();
  if(r == 0) return;
  int c = matrix[0].size();
  for (int i = 0; i < r; ++i) {
    printf("[");
    for (int j = 0; j < c; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    printf("]");
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int bagOfTokensScore(std::vector<int> tokens, int power) {
  int n = tokens.size();
  std::sort(tokens.begin(), tokens.end());
  int i = 0, j = n - 1;
  int points = 0, max_points = 0;
  std::sort(tokens.begin(), tokens.end());
  while(i <= j) {
    if (power >= tokens[i]) {
      power -= tokens[i];
      points += 1;
      i += 1;
      max_points = std::max(max_points, points);
    }
    else {
      if (points >= 1) {
        power += tokens[j]; 
        points -= 1;
        j -= 1;
      } else {
        return max_points;
      }
    }
  }
  return max_points;
}

int main() {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output