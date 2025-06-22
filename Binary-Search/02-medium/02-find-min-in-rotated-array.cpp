/*
* Leetcode - 153
* Find Minimum in Rotated Sorted Array
* Given the sorted rotated array nums of unique elements, return the minimum element of this array.

* Example 1:
* Input: nums = [3, 4, 5, 1, 2]
* Output: 1

* Example 2:
* Input: nums = [4, 5, 6, 7, 0, 1, 2]
* Output: 0

* https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
* https://www.naukri.com/code360/problems/rotated-array_1093219
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
// * TIME COMPLEXITY O(logn)
// * SPACE COMPLEXITY O(1)
int findMinimum(std::vector<int> arr) {
  int n = arr.size();
  if(n == 1) return arr[0];

  int l = 0, r = n - 1;
  int minEle = INT_MAX;
  while (l <= r) {
    int m = l + (r - l) / 2;

    // * If the whole search space is sorted
    // * then find the minEle & break
    if(arr[l] <= arr[r]) {
      minEle = std::min(minEle, arr[l]);
      break;
    }

    // * Left part is sorted
    if (arr[l] <= arr[m]) {
      minEle = std::min(minEle, arr[l]);
      l = m + 1;
    }
    else {
      // * Right part is sorted
      minEle = std::min(minEle, arr[m]);
      r = m - 1;
    }
  }

  return minEle == INT_MAX ? -1 : minEle;
}

int main() {
  // * testcase 1
  std::vector<int> arr = {2, 3, 4, 1};

  // * testcase 2
  // std::vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

  // * testcase 3
  // std::vector<int> arr = {25, 30, 5, 10, 15, 20};

  printArr(arr);

  int minimum = findMinimum(arr);
  std::cout << "Find Minimum " << minimum << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 02-find-min-in-rotated-array.cpp -o output && ./output