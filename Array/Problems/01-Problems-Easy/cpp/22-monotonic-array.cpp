/**
 * * Monotonic Array 
 * * An array is monotonic if it is either monotone increasing or monotone decreasing.
 * * An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j].
 * * An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
 * 
 * * Given an integer array nums, return true if the given array is monotonic, or false otherwise.

 * * Example 1
 * * Input  : nums = [1,2,2,3]
 * * Output : true

 * * Example 2
 * * Input  : nums = [6,5,4,4]
 * * Output : true

 * * Example 2
 * * Input  : nums = [1,3,2]
 * * Output : false
 * 
 * * https://leetcode.com/problems/monotonic-array/description/
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
// TODO

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
bool isMonotonic(std::vector<int> arr) {
  int n = arr.size();
  bool monotonicIncreasing = true, monotonicDecreasing = true;
  for (int i = 0; i < n - 1; i++) {
    // * Check if not monotonic increasing
    if(arr[i] > arr[i+1]) {
      monotonicIncreasing = false;
    }
    // * Check if not monotonic decreasing
    if(arr[i] < arr[i+1]) {
      monotonicDecreasing = false;
    }

    if(!monotonicIncreasing && !monotonicDecreasing) {
      break;
    }
  }
  return monotonicIncreasing || monotonicDecreasing;
}

int main() {
  // * testcase 1
  // std::vector<int> arr = {1, 2, 2, 3};
  // * testcase 2
  // std::vector<int> arr = {6, 5, 4, 4};
  // * testcase 3
  std::vector<int> arr = {1, 3, 2};
  printArr(arr);
  bool ans = isMonotonic(arr);
  std::cout << "Is array monotonic: " << ans << std::endl;
}

// * Run the code
// * g++ --std=c++17 22-monotonic-array.cpp -o 22-monotonic-array && ./22-monotonic-array