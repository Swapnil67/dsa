/*
 * Search Insert Position
 * You are given a sorted array 'arr' of distinct values and a target value 'm'.
 * You need to search for the index of the target value in the array.
 * 
 * Example 1:
 * Input: arr = [1, 2, 4, 7],  target = 6 
 * Output: 3

 * Example 2:
 * Input: arr = [ 1 2 4 7 ], target = 9
 * Output: 4
 * 
 * https://www.naukri.com/code360/problems/algorithm-to-find-best-insert-position-in-sorted-array_839813
*/

#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
int bruteForce(std::vector<int> arr, int target) {
  int idx = -1;
  int n = arr.size();
  for(int i=0; i<n; i++) {
    if(arr[i] < target) {
      idx = i+1;
    }
  }
  return idx;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Lower bound (Smallest element greater than x)
// * TIME COMPLEXITY O(logn)
int findInsertIndex(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n - 1;
  int idx = n;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] >= target) {
      idx = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return idx;
}


int main() {
  // * testcase 1
  std::vector<int> arr = {1, 2, 4, 7};
  int target = 6;

  std::cout<<"Input Array"<<std::endl;
  printArr(arr);
  // int insertIndex = bruteForce(arr, target);
  int insertIndex = findInsertIndex(arr, target);
  std::cout<<"Insert Index: "<<insertIndex<<std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 04-search-insert-index.cpp -o 04-search-insert-index && ./04-search-insert-index