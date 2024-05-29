/*
* Search In Rotated Sorted Array
* There is an integer array nums sorted in ascending order (with distinct values).
* Given the array nums after the possible rotation and an integer target, return the index of target
* if it is in nums, or -1 if it is not in nums.

! Array has duplicates

* Example 1:
* Input: nums = [2,5,6,0,0,1,2], target = 0
* Output: true

* Example 2:
* Input: nums = [2,5,6,0,0,1,2], target = 3
* Output: false

* https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
* https://www.naukri.com/code360/problems/search-in-a-rotated-sorted-array-ii_7449547
*/

// ! Array has duplicates

#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}



int main() {
  std::vector<int> arr = {2, 5, 6, 0, 0, 1, 2};
  int target = 0;

  printArr(arr);

  return 0;
}

// * Run the code
// * g++ --std=c++17 01-search-in-rotated-sorted-array.cpp -o 01-search-in-rotated-sorted-array && ./01-search-in-rotated-sorted-array