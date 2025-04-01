#include<vector>
#include<deque>
#include<iostream>
#include <numeric>
#include <climits>
#include <map>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  return 0;
}

// * Run the code
// * $CXX --std=c++20 practice.cpp -o output && ./output