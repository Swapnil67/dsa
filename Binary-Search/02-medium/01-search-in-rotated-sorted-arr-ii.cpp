/*
* Leetcode - 81
* Search In Rotated Sorted Array - II
* There is an integer array nums sorted in ascending order (with distinct values).
* Given the array nums after the possible rotation and an integer target, return the index of target
* if it is in nums, or -1 if it is not in nums.

* Example 1:
* Input: nums = [2, 5, 6, 0, 0, 1, 2], target = 0
* Output: true

* Example 2:
* Input: nums = [2, 5, 6, 0, 0, 1, 2], target = 3
* Output: false

* https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
* https://www.naukri.com/code360/problems/search-in-a-rotated-sorted-array-ii_7449547
*/

// ! Array has duplicates

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
// * Linear search
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Find which part of array is sorted and search there
// * TIME COMPLEXITY O(logN) [Best Case]
// * TIME COMPLEXITY O(N) [Worst Case] All elements are duplicate
// * SPACE COMPLEXITY O(1)

// * Search In Rotated Sorted Array
// ! Array has duplicates
int searchInRotatedSorted(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == target) {
      return m;
    }

    // * If arr[l] == arr[m] == arr[r]
    if (arr[l] == arr[m] && arr[m] == arr[r]) {
      l++, r--;
      continue;
    }

    // * Left part is sorted
    if(arr[l] <= arr[m]) {
      // * target lies in left part
      if(arr[l] <= target && target <= arr[m]) {
        r = m - 1;
      }
      else {
        l = m + 1;
      }
    }
    else {
      // * Right part is sorted
      if(arr[m] <= target && target <= arr[r]) {
        // * Target lies in right part
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
  // * testcase 1
  int target = 0;
  std::vector<int> arr = {2, 5, 6, 0, 0, 1, 2};

  // * testcase 2
  // int target = 1;
  // std::vector<int> arr = {3, 1, 2, 3, 3, 3, 3};

  // * testcase 3
  // int target = 0;
  // std::vector<int> arr = {1, 0, 1, 1, 1};

  printArr(arr);

  int idx = searchInRotatedSorted(arr, target);
  std::cout << "Index " << idx << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 01-search-in-rotated-sorted-arr-ii.cpp -o output && ./output