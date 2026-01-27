#include <vector>
#include <iostream>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

// * 03 - Upper Bound
// int findUpperBound(std::vector<int> &arr, int x) {
// TODO
// }

// * 04 - Search Insert Position
// int findInsertIndex(std::vector<int> arr, int x) {
// TODO
// }

// * 05 - Ceil The Floor
// std::pair<int, int> getFloorAndCeil(std::vector<int> &arr, int x) {
// TODO
// }

// * 06 - First and Last Position of an Element In Sorted Array
// std::pair<int, int> firstAndLastOccurence(std::vector<int> &arr, int k) {
// TODO
// }

// * 09 - Square Root of a number
// int findSquareRoot(int n) {
// TODO
// }

// * 10 - Kth Missing Positive Number 
// int findKthMissingNumber(std::vector<int> &arr, int k) {
// TODO
// }

// * -----------------------------------------------------------------------------

// * 01 - Binary Search
// int binarySearch(std::vector<int> arr, int target) {
// TODO
// }

// * 02 - Lower Bound
// int findLowerBound(std::vector<int> &arr, int x) {
// TODO
// }

int main() {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output