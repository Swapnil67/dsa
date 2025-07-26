/*
* Leetcode - 154
* Find Minimum in Rotated Sorted Array II
* Given the sorted rotated array nums of unique elements, return the minimum element of this array.

* Example 1:
* Input: nums = [3, 4, 5, 1, 2]
* Output: 1

* Example 2:
* Input: nums = [10, 1, 10, 10, 10]
* Output: 1

* https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
*/

#include <vector>
#include <climits>
#include <iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Linear search
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Find which part of array is sorted and find the min and then exclude that part
// * Minimum element is not present in sorted part [Exclude that part]
// * TIME COMPLEXITY O(logN)
// * SPACE COMPLEXITY O(1)
int findMinimum(std::vector<int> arr) {
  int n = arr.size();
  if(n == 1) return arr[0];

  int l = 0, r = n - 1;
  int minEle = INT_MAX;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == arr[l] && arr[m] == arr[r]) {
      minEle = std::min(minEle, arr[l]);
      l++, r--;
    }
    else if (arr[l] <= arr[m]) {
      // * Left part is sorted
      minEle = std::min(minEle, arr[l]);
      l = m + 1;
    }
    else {
      // * Right part is sorted
      minEle = std::min(minEle, arr[m]);
      r = m - 1;
    }
  }
  return minEle;
}

int main() {
  // * testcase 1
  // std::vector<int> arr = {25, 30, 5, 10, 15, 20};
  // * testcase 2
  // std::vector<int> arr = {10, 1, 10, 10, 10};
  // * testcase 3
  // std::vector<int> arr = {3, 1, 3, 3};
  // * testcase 3
  std::vector<int> arr = {-1,-1,-1,-1};
  printArr(arr);

  int minimum = findMinimum(arr);
  std::cout << "Find Minimum " << minimum << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 02-find-min-in-rotated-array.cpp -o 02-find-min-in-rotated-array && ./02-find-min-in-rotated-array