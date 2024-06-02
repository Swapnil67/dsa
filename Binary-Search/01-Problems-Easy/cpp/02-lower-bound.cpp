/*
 * Implement Lower Bound
 * For a sorted array 'arr' 'lower_bound' of a number 'x' is defined as the smallest index 'idx'
 * such that arr[i] >= x
 * If all the numbers are smaller than 'x' then 'n' should be the 'lower_bount' of 'x'.
 * 'n' = size of array
 * 
 * Example 1:
 * Input: arr = [ 1, 2, 2, 3, 3, 5, 6 ], x = 2
 * Output: 1

 * Example 2:
 * Input: arr = [ 1, 2, 2, 3, 3, 5, 6 ], x = 5
 * Output: 5
 * 
 * https://www.naukri.com/code360/problems/lower-bound_8165382
*/


/*
 * For a sorted array 'arr', 'lower_bound' of a number 'x' is defined as the smallest index 'idx' 
 * such that the value 'arr[idx]' is not less than 'x' 
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
int lowerBoundBrute(std::vector<int> arr, int x) {
  int n = arr.size();
  int ans = n;
  for(int i=0; i<n; i++) {
    if(arr[i] >= x) {
      ans = min(i, ans);
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Lower bound (Smallest element greater than x)
// * TIME COMPLEXITY O(logn)
int findLowerBound(std::vector<int> arr, int x) {
  int n = arr.size();
  int l = 0, r = n - 1;
  int lowIdx = n;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] >= x) {
      lowIdx = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return lowIdx;
}


int main() {
  // * testcase 1
  // std::vector<int> arr = {1, 2, 2, 3};
  // int x = 0;

  // * testcase 2
  std::vector<int> arr = {1, 2, 2, 3, 3, 5};
  int x = 2;

  std::cout<<"Input Array"<<std::endl;
  printArr(arr);
  int lowerBound = findLowerBound(arr, x);
  std::cout<<"Lower Bound Index: "<<lowerBound<<std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 02-lower-bound.cpp -o 02-lower-bound && ./02-lower-bound