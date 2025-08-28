/**
 * * Leetcode - 283
 * * Move Zero's to End
 * * Given an array 'arr' of 'n' non-negative integers, your task is to move all the zeros to the end of the array while keeping 
 * * the non-zero elements at the start of the array in their original order. Return the modified array.

 * * Example 1
 * * Input  : 'k' = 1, 'arr '= [1, 2, 0, 0, 2, 3]
 * * Output : [1, 2, 2, 3, 0, 0]
 * 
 * * Example 2
 * * Input  : 'k' = 4, 'arr '= [0, 0, 0, 1]
 * * Output : [1, 0, 0, 0]

 * * https://www.naukri.com/code360/problems/ninja-and-the-zero-s_6581958
 * * https://leetcode.com/problems/move-zeroes/
*/

#include <iostream>
#include <vector>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void moveZeroes(std::vector<int> &nums) {
  int n = nums.size();
  int i = -1;
    
  // * go to first zero index
  for (int k = 0; k < n; ++k) {
    if(nums[k] == 0) {
      i = k;
      break;
    }
  }

  if (i == -1)
    return;

  int j = i + 1;
  for (int j = j + 1; j < n; ++j) {
    if(nums[j] != 0) {
      nums[i] = nums[j];
      nums[j] = 0;
      i++;
    }
  }
}

int main(void) {
  std::vector<int> arr = {1, 2, 0, 0, 2, 3};
  // std::vector<int> arr = {0, 0, 0, 1};
  // std::vector<int> arr = {8, 6, 9};

  std::cout<<"Before Moving Zero's"<<std::endl;
  printArr(arr);

  std::cout<<"After Moving Zero's"<<std::endl;
  moveZeroes(arr);
  printArr(arr);

  return 0;
}

// * Run the code
// * g++ --std=c++20 09-move-zeros.cpp -o output && ./output