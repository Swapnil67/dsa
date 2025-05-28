#include <vector>
#include <stack>
#include <iostream>

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// * 01 - Baseball Game
// int calPoints(std::vector<std::string>& operations) {
// TODO
// }

// * 02 - Final Prices With a Special Discount in a Shop
// int calPoints(std::vector<std::string>& operations) {
// TODO
// }

int main() {
  return 0;
}

// * Run the code
// * g++ -std=c++20 practice.cpp -o output && ./output