/*
 * Leetcode - 704
 * Binary Search
 * Given an array of integers nums which is sorted in ascending order, and an integer target,
 * write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
 * 
 * Example 1:
 * Input: arr = [ -1, 0, 3, 5, 9, 12 ], target = 9
 * Output: 4

 * Example 2:
 * Input: arr = [ -1, 0, 3, 5, 9, 12 ], target = 2
 * Output: -1
 * 
 * https://leetcode.com/problems/binary-search/description/
 * https://www.naukri.com/code360/problems/binary-search_972
*/

#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

int binarySearch(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] == target) {
      return m;
    }
    else if(arr[m] < target) {
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return -1;
}


int main() {
  // * testcase 1
  // int target = 5;
  
  // * testcase 2
  int target = 4;

  std::vector<int> arr = {-1, 0, 3, 5, 9, 12};

  std::cout<<"Input Array"<<std::endl;
  printArr(arr);
  int idx = binarySearch(arr, target);
  std::cout<<"Target Index: "<<idx<<std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 01-binary-search.cpp -o 01-binary-search && ./01-binary-search