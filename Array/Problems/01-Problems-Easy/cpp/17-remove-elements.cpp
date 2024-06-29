/**
 * * Remove Element
 * * Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
 * * The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

 * * Example 1
 * * Input  : nums = [3,2,2,3], val = 3
 * * Output : 2, nums = [2,2,_,_]
 * * Explanation: Your function should return k = 2, with the first two elements of nums being 2.

 * * Example 2
 * * Input  : nums = [0,1,2,2,3,0,4,2], val = 2
 * * Output : 5, nums = [0,1,0,4,2,_,_,_]
 * * Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.

 * * https://leetcode.com/problems/remove-element/description/
*/

#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Two loops
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
int bruteForce(std::vector<int> &arr, int val) {
  int n = arr.size(), cnt = 0;
  std::vector<int> temp;
  for (int i = 0; i < n; i++) {
    if (arr[i] != val)
      temp.push_back(arr[i]);
  }

  for (int i = 0; i < temp.size(); i++) {
    arr[i] = temp[i];
  }

  return temp.size();
}


// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Two Pointer
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int removeElement(std::vector<int> &arr, int val) {
  int n = arr.size();
  int i = 0;
  while(i < n && arr[i] != val) {
    i++;
  }

  for (int j = i + 1; j < n; j++) {
    if(arr[j] != val) {
      swap(arr[i], arr[j]);
      i++;
    }
  }

  return i;
}

int main() {
  // * testcase 1
  // int val = 2;
  // std::vector<int> arr = {0, 1, 2, 2, 3, 0, 4, 2};
  // * testcase 2
  // int val = 2;
  // std::vector<int> arr = {3, 2, 2, 3};
  // * testcase 3
  int val = 3;
  std::vector<int> arr = {2};
  printArr(arr);
  // int ans = bruteForce(arr, val);
  int ans = removeElement(arr, val);
  std::cout << "Answer " << ans << std::endl;
  printArr(arr);
  return 0;
}

// * Run the code
// * g++ --std=c++17 17-remove-elements.cpp -o 17-remove-elements && ./17-remove-elements