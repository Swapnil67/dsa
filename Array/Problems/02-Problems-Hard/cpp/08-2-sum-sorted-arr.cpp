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

 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
*/

#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * Two Pointers
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::vector<int> twoSum(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n-1;
  while(l < r) {
    int left_number = arr[l];
    int right_number = arr[r];
    int sum = left_number + right_number;
    if(sum == target) {
      return { l, r };
    }
    else if(sum > target) {
      r--;
    }
    else {
      l++;
    }
  }
  return { l, r };
}

int main() {
  // int target = 9;
  // std::vector<int> arr = { 2,7,11,15 };
  int target = 6;
  std::vector<int> arr = { 2,3,4 };
  std::cout<<"Input Array"<<std::endl;
  printArr(arr);
  std::vector<int> ans = twoSum(arr, target);
  std::cout<<"Sum Indexes"<<std::endl;
  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++17 08-2-sum-sorted-arr.cpp -o 08-2-sum-sorted-arr && ./08-2-sum-sorted-arr