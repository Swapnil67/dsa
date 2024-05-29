/*
* Search In Rotated Sorted Array
* There is an integer array nums sorted in ascending order (with distinct values).
* Given the array nums after the possible rotation and an integer target, return the index of target
* if it is in nums, or -1 if it is not in nums.

! Array does not have duplicates

* Example 1:
* Input: nums = [4,5,6,7,0,1,2], target = 0
* Output: 4

* Example 2:
* Input: nums = [4,5,6,7,0,1,2], target = 3
* Output: -1

* https://leetcode.com/problems/search-in-rotated-sorted-array/
* https://www.naukri.com/code360/problems/search-in-rotated-sorted-array_1082554
*/

// ! Array does not have duplicates

#include<iostream>

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Linear search
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr, int target) {
  int ans = -1;
  int n = arr.size();
  for(int i=0; i<n; i++) {
    if(arr[i] == target) {
      ans = i;
    }
  }
  return ans;
}


// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Find which part of array is sorted and search there
// * TIME COMPLEXITY O(logN)
// * SPACE COMPLEXITY O(1)
int findInRotatedSortedArray(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n-1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] == target) {
      return m;
    }
    else if(arr[l] <= arr[m]) {
      // * Left part of array is sorted
      if(arr[l] <= target && arr[m] >= target) {
        // * target lies in left side
        r = m - 1;
      }
      else {
        l = m + 1;
      }
    }
    else {
      // * Right part of array is sorted
      if(arr[m] <= target && arr[r] >= target) {
        // * target lies in right part
        l = m + 1;
      }
      else {
        r = m - 1;
      }
    }
  }
  return -1;
}


int main() {
  // std::vector<int> arr = {4, 5, 6, 0, 1, 2};
  // int target = 0;

  std::vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
  int target = 8;

  // int idx = bruteForce(arr, target);
  int idx = findInRotatedSortedArray(arr, target);
  std::cout<<"Index "<<idx<<std::endl;
}

// * Run the code
// * g++ --std=c++17 08-search-in-rotated-sorted-array.cpp -o 08-search-in-rotated-sorted-array && ./08-search-in-rotated-sorted-array