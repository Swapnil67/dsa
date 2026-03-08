/*
* Leetcode - 153
* Find Minimum in Rotated Sorted Array
*
* Given the sorted rotated array nums of unique elements, return the minimum element of this array.
*
* Example 1:
* Input: nums = [3, 4, 5, 1, 2]
* Output: 1
*
* Example 2:
* Input: nums = [4, 5, 6, 7, 0, 1, 2]
* Output: 0
*
* https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
* https://www.naukri.com/code360/problems/rotated-array_1093219
*
*/

// ! Amazon, Meta, Google, MIcrosoft, Apple, Uber, Flipkart, IBM

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Linear search
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Find which part of array is sorted and find the min and then exclude that part
// * Minimum element is not present in sorted part [Exclude that part]
// * TIME COMPLEXITY O(logn)
// * SPACE COMPLEXITY O(1)
int findMinimum(vector<int> nums) {
  int n = nums.size();
  if (n == 1)
    return nums[0];

  int l = 0, r = n - 1;
  int ans = nums[0];
  while (l <= r) {
    // * If the whole search space is sorted
    // * then find the ans & break
    if(nums[l] <= nums[r]) {
      ans = min(ans, nums[l]);
      break;
    }
    
    int m = l + (r - l) / 2;
    // * Left part is sorted
    if (nums[l] <= nums[m]) {
      ans = min(ans, nums[l]);
      l = m + 1;
    } else {
      // * Right part is sorted
      ans = min(ans, nums[m]);
      r = m - 1;
    }
  }

  return ans;
}

int main() {
  // * testcase 1
  // vector<int> nums = {2, 3, 4, 1};

  // * testcase 2
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

  // * testcase 3
  // vector<int> nums = {25, 30, 5, 10, 15, 20};

  cout << "Input nums: ";
  printArr(nums);
  int minimum = findMinimum(nums);
  cout << "Find Minimum: " << minimum << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 02-find-min-in-rotated-array.cpp -o output && ./output