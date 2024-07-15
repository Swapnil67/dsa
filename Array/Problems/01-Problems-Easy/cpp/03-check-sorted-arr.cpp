/**
 * *  Largest Element in the Array
 * * You have been given an array ‘a’ of ‘n’ non-negative integers.
 * * You have to check whether the given array is sorted in the non-decreasing order or not.

 * * Example 1
 * * Input  : ‘n’ = 5, ‘a’ = [1, 2, 3, 4, 5]
 * * Output : 1
 * 
 * * Example 2
 * * Input  : ‘n’ = 5, ‘a’ = [4, 5, 4, 4, 4]
 * * Output : 0

 * * https://www.naukri.com/code360/problems/ninja-and-the-sorted-check_6581957
*/


#include<iostream>

bool checkSorted(std::vector<int> arr) {
  bool isSorted = true;
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    if (arr[i + 1] <= arr[i] && i < n - 1) {
      isSorted = false;
    }
  }
  return isSorted;
}

int main() {
  // * testcase 1
  std::vector<int> arr = {1, 2, 3, 4, 5};
  // * testcase 2
  // std::vector<int> arr = {4, 5, 4, 4, 4};

  bool isSorted = checkSorted(arr);
  std::cout<<"Is Array Sorted: "<<isSorted<<std::endl; 

  return 0;
}

// * Run the code
// * g++ --std=c++17 03-check-sorted-arr.cpp -o 03-check-sorted-arr && ./03-check-sorted-arr
