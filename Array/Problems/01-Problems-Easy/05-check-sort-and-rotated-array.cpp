/*
 * Leetcode - 1752
 * Check if Array Is Sorted and Rotated
 * 
 * Given an array nums, return true if the array was originally sorted in non-decreasing order, 
 * then rotated some number of positions (including zero). Otherwise, return false.
 * 
 * There may be duplicates in the original array.
 * 
 * Note: An array A rotated by x positions results in an array B of the same length such that 
 * B[i] == A[(i+x) % A.length] for every valid index i.
 * 
 * Example 1:
 * Input: nums = [3,4,5,1,2]
 * Output: true
 * Explanation: [1,2,3,4,5] is the original sorted array.
 * You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].
 * 
 * Example 2:
 * Input: nums = [2,1,3,4]
 * Output: false
 * Explanation:  There is no sorted array once rotated that can make nums.
 * 
 * https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printArr(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}


// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Check all possible rotated & sorted arrays
// * TIME COMPLEXITY O(N) * O(3N) ~ O(N^2)
// * SPACE COMPLEXITY O(N)
bool bruteForce(std::vector<int>& nums) {
  int n = nums.size();

  for (int r = 0; r < n; ++r) {
    std::vector<int> sorted(n);
    int idx = 0;
    // * from r to n
    for (int i = r; i < n; ++i) {
      sorted[idx] = nums[i];
      idx++;
    }
    
    // * from 0 to r
    for (int i = 0; i < r; ++i) {
      sorted[idx] = nums[i];
      idx++;
    }

    printArr(sorted);

    // * Check if sorted actually sorted array
    bool is_sorted = true;
    for (int i = 0; i < n - 1; ++i) {
      if (sorted[i] > sorted[i + 1]) {
        is_sorted = false;
        break;
      }
    }

    if (is_sorted)
      return true;
  }

  return false;
}


// * ------------------------- APPROACH 2: BETTER FORCE APPROACH -------------------------`
// * Check all possible rotated & sorted arrays in place
// * TIME COMPLEXITY O(N^2) + O(nlogn) ~ O(N^2) 
// * SPACE COMPLEXITY O(N)
bool betterApproach(std::vector<int>& nums) {
  int n = nums.size();

  // * Sort the given input array
  std::vector<int> sorted(nums.begin(), nums.end());
  std::sort(sorted.begin(), sorted.end());

  for (int r = 0; r < n; ++r) {

    bool is_sorted = true;
    for (int i = 0; i < n; ++i) {
      if (nums[i] != sorted[(i + r) % n]) {
        is_sorted = false;
        break;
      }
    }

    if (is_sorted)
      return true;
  }

  return false;
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * Count the number of peak. It should only have one peak
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
bool checkSortedAndRotated(vector<int> nums) {
  int peak = 0;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    if (nums[i] > nums[(i + 1) % n])
        peak++;
  }
  return peak <= 1;
}

int main() {
  // std::vector<int> nums = {3, 4, 5, 1, 2};
  std::vector<int> nums = {2, 1, 3, 4};
  printArr(nums);

  // bool check = bruteForce(nums);
  // bool check = betterApproach(nums);
  bool check = checkSortedAndRotated(nums);
  std::cout << "Is Sorted & Rotated: " << check << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 05-check-sort-and-rotated-array.cpp -o output && ./output
