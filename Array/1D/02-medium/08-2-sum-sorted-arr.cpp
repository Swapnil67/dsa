/*
 * Two Sum II - Input Array Is Sorted
 * Find two numbers such that they add up to a specific target number.
 * Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

 * ***** Your solution must use only constant extra space. *****

 * 
 * Example 1:
 * Input: arr = [2,7,11,15], target = 9
 * Output: [1,2]
 * 
 * Example 2:
 * Input: arr = [2,3,4], target = 6
 * Output: [1,3]
 * 
 * https://www.naukri.com/code360/problems/reading_6845742
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
*/

#include <vector>
#include <iostream>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

// * Two Pointers
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::vector<int> twoSum(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while(l < r) {
    int left_number = arr[l];
    int right_number = arr[r];
    int sum = left_number + right_number;
    if (sum == target) {
      return {l, r};
    } else if (sum > target) {
      r--;
    } else {
      l++;
    }
  }
  return {l, r};
}

int main() {
  // * testcase 1
  // int target = 9;
  // std::vector<int> arr = { 2,7,11,15 };
  
  // * testcase 2
  int target = 6;
  std::vector<int> arr = { 2,3,4 };
  
  std::cout<<"Input Array"<<std::endl;
  printArr(arr);

  std::vector<int> ans = twoSum(arr, target);
  std::cout << "Sum Indexes" << std::endl;
  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++20 08-2-sum-sorted-arr.cpp -o output && ./output
