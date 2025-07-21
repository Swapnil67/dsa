/*
 * Given an array of integers nums which is sorted in ascending order, and an integer target,
 * write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
 * 
 * Example 1:
 * Input: arr = [ 1, 4, 7, 8, 10 ], target = 7
 * Output: 2

 * Example 2:
 * Input: arr = [ 2, 4, 6, 7 ], target = 5
 * Output: 2
 * 
 * https://www.naukri.com/code360/problems/implement-upper-bound_8165383
*/

// ! First element greater than 'x'

/* 
 * The upper bound in a sorted array is the index of the first value that is greater than a given value. 
 * If the greater value does not exist then the answer is 'n', Where 'n' is the size of the array.
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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int upperBoundBrute(std::vector<int> arr, int x) {
  int n = arr.size();
  int uppderIdx = n;
  for(int i=0; i<n; i++) {
    if(arr[i] > x) {
      uppderIdx = std::min(uppderIdx, i);
    }
  }
  return uppderIdx;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Smallest element greater than x
// * TIME COMPLEXITY O(logn)
// * SPACE COMPLEXITY O(1)
int findUpperBound(std::vector<int> arr, int x) {
  int n = arr.size();
  int l = 0, r = n - 1;
  int upperIdx = n;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] > x) {
      upperIdx = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return upperIdx;
}

int main() {
  // * testcase 1
  // int x = 7;
  // std::vector<int> arr = {1, 4, 7, 8, 10};

  // * testcase 2
  int x = 5;
  std::vector<int> arr = {2, 4, 6, 7};

  std::cout << "Input Array" << std::endl;
  printArr(arr);
  
  // int upperBound = upperBoundBrute(arr, x);
  int upperBound = findUpperBound(arr, x);
  std::cout<<"Upper Bound Index: "<<upperBound<<std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 03-upper-bound.cpp -o output && ./output