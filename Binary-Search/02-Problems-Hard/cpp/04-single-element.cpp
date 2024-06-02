/*
* Single element in a Sorted Array
* You are given a sorted array consisting of only integers where every element appears exactly twice,
* except for one element which appears exactly once.
* Return the single element that appears only once.

* Example 1:
* Input: nums = [1,1,2,3,3,4,4,8,8]
* Output: 2

* Example 2:
* Input: nums = [3,3,7,7,10,11,11]
* Output: 10

* https://leetcode.com/problems/single-element-in-a-sorted-array/
* https://www.naukri.com/code360/problems/unique-element-in-sorted-array_1112654
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
// * Linear search
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr) {
  int n = arr.size();

  // * Edge Cases
  if(n == 1) return arr[0];
  else if(arr[0] != arr[1]) {
    return arr[0];
  }
  else if(arr[n-1] != arr[n-2]) {
    return arr[n-1];
  }

  for(int i=1; i<n; i++) {
    if((arr[i] != arr[i-1] && arr[i] != arr[i+1]) && (i < n)) {
      return arr[i];
    }
  }
  return -1;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(logN)
// * SPACE COMPLEXITY O(1)
int findSinleNumber(std::vector<int> arr) {
  int n = arr.size();
  // * Edge Cases
  if(n == 1) return arr[0];
  else if(arr[0] != arr[1]) {
    return arr[0];
  }
  else if(arr[n-1] != arr[n-2]) {
    return arr[n-1];
  }

  int l = 0, r = n - 1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] != arr[m-1] && arr[m] != arr[m+1]) {
      return arr[m];
    }
    else if ((m % 2 == 0 && arr[m] == arr[m + 1]) || (m % 2 == 1 && arr[m] == arr[m - 1])) {
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return -1;
}

int main() {
  // std::vector<int> arr = {1};
  std::vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8};
  // std::vector<int> arr = {1, 2, 2, 3, 3};
  // std::vector<int> arr = {1, 1, 2, 2, 3};
  printArr(arr);
  // int singleNumber = bruteForce(arr);
  int singleNumber = findSinleNumber(arr);
  std::cout<<"Single Number "<<singleNumber<<std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 04-single-element.cpp -o 04-single-element && ./04-single-element