#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * 01 - Binary Search
// int binarySearch(std::vector<int> arr, int target) {
// TODO
// }

// * 02 - Lower Bound
// int findLowerBound(std::vector<int> arr, int x) {
// TODO
// }

// * 03 - Upper Bound
// int findUpperBound(std::vector<int> arr, int x) {
// TODO
// }

// * 04 - Search Insert Position
// int findInsertIndex(std::vector<int> arr, int x) {
// TODO
// }

int main() {
  // * Problem 5
  // * Find Floor & Ceil
  // std::vector<int> arr = {1, 2, 3, 4, 8, 10, 10, 12, 19};
  // int x = 4;
  // printArr(arr);
  // std::pair<int, int> ans = getFloorAndCeil(arr,x);
  // std::cout << "Floor of " << x << " is: " << ans.first << std::endl;
  // std::cout << "Ceil of " << x << " is: " << ans.second << std::endl;
  
  // * Problem 6
  // * Find First & Last
  // int x = 10;
  // std::vector<int> arr = { 0, 1, 1, 5 };
  // printArr(arr);
  // std::pair<int, int> ans = getFirstAndLastOccurence(arr,x);
  // std::cout << "First Occurence of " << x << " is " << ans.first << std::endl;
  // std::cout << "Last Occurence of " << x << " is " << ans.second << std::endl;

  // * Problem 7
  // * Search In Rotated Sorted Array (A)
  // std::cout << "----------- Search In Rotated Sorted Array I -----------" << std::endl;
  // int target = 0;
  // std::vector<int> arr = {4, 5, 6, 0, 1, 2};
  // int target = 8;
  // std::vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
  // ! Below testcase will fail 
  // int target = 1;
  // std::vector<int> arr = {3, 1, 2, 3, 3, 3, 3};
  // printArr(arr);
  // int idx = searchInRotatedSortedA(arr, target);
  // std::cout << "Index " << idx << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o output && ./output

