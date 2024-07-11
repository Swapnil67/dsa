/*
* There is an integer array nums sorted in ascending order (with distinct values).
* The array is right rotated 'r' times
* Find the minimum value of 'r'

* Example 1:
* Input: nums = [5,6,0,1,2]
* Output: 2
* Explanation: 2 times rotated

* Example 2:
* Input: nums = [2,3,4,1]
* Output: 3 
* Explanation: 3 times rotated from [1,2,2,4]

* Example 3:
* Input: nums = [1,2,3]
* Explanation: 0 times rotated from [1,2,3]

* https://www.naukri.com/code360/problems/rotation_7449070
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

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Find which part of array is sorted and find the min and then exclude that part
// * Minimum element is not present in sorted part [Exclude that part]
// * TIME COMPLEXITY O(logN)
// * SPACE COMPLEXITY O(1)
int findKRotation(std::vector<int> arr) {
  int n = arr.size();
  int l = 0, r = n - 1;
  int minEle = INT_MAX, cnt = INT_MAX;
  while(l <= r) {
    int m = l + (r - l) / 2;

    // * Search space is sorted
    if(arr[l] <= arr[r]) {
      if(arr[l] < minEle) {
        minEle = arr[l];
        cnt = l;
        break;
      }
    }

    if(arr[l] <= arr[m]) {
      // * Left part of array is sorted
      if(arr[l] < minEle) {
        minEle = arr[l];
        cnt = l;
      }
      l = m + 1;
    }
    else {
      // * Right part of array is sorted
      if(arr[m] < minEle) {
        minEle = arr[m];
        cnt = m;
      }
      r = m - 1;
    }
  }
  return cnt;
}

int main() {
  // std::vector<int> arr = {5, 6, 0, 1, 2};
  std::vector<int> arr = {2, 3, 4, 1};
  printArr(arr);
  int count = findKRotation(arr);
  std::cout << "Rotation Count " << count << std::endl;
  return 0;
}

// * Run the code 
// * g++ --std=c++17 03-find-count-of-rotation.cpp -o 03-find-count-of-rotation && ./03-find-count-of-rotation