/*
 * First and Last Position of an Element In Sorted Array
 * You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
 * Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.

 * Note :
 * 1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
 * 2. 'arr' may contain duplicate elements.
 * 
 * Example 1:
 * Input: arr = [ 0, 1, 1, 5 ],  k = 1
 * Output: [1,2]

 * Example 2:
 * Input: arr = [ 1, 3, 3, 5 ], k = 9
 * Output: [-1, -1]
 * 
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 * https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549
*/

#include<iostream>

// * Using Plain Binary Search

// * ------------------------- Utility Functions -------------------------

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * O(logN)
int findFirstOccurence(std::vector<int> arr, int k) {
  int n = arr.size();
  int l = 0, r = n - 1;
  int idx = -1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] == k) {
      idx = m;
      r = m - 1;
    }
    else if(arr[m] > k) {
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  
  return idx;
}

// * O(logN)
int findLastOccurence(std::vector<int> arr, int k) {
  int n = arr.size();
  int l = 0, r = n - 1;
  int idx = -1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if(arr[m] == k) {
      idx = m;
      l = m + 1;
    }
    else if(arr[m] < k) {
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }

  return idx;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::pair<int, int> bruteForce(std::vector<int> arr, int k) {
  std::pair<int, int> ans(-1, -1);
  int n = arr.size();
  for(int i=0; i<n; i++) {
    if(arr[i] == k) {
      if(ans.first == -1) {
        ans.first = i;
        ans.second = i;
      }
      else if(ans.first != -1) {
        ans.second = i;
      }
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(2logN)
// * SPACE COMPLEXITY O(1)
std::pair<int, int> firstAndLastOccurence(std::vector<int> arr, int k) {
  int n = arr.size();
  int firstOccurence = findFirstOccurence(arr, k);

  // * If k not found
  if(firstOccurence == -1) {
    return { -1, -1 };
  }

  int lastOccurence = findLastOccurence(arr, k);
  std::pair<int, int> ans(firstOccurence, lastOccurence);
  return ans;
}

int main() {
  // * testcase 1
  std::vector<int> arr = {0, 1, 1, 5};
  int k = 1;

  // * testcase 2
  // std::vector<int> arr = {1, 3, 9, 15};
  // int k = 9;

  // * testcase 3
  // std::vector<int> arr = {1, 3, 3, 5};
  // int k = 9;
  printArr(arr);

  // std::pair<int, int> ans = bruteForce(arr, k);
  std::pair<int, int> ans = firstAndLastOccurence(arr, k);
  std::cout<<"First Occurence: "<<ans.first<<std::endl;
  std::cout<<"Second Occurence: "<<ans.second<<std::endl;

  
  return 0;
}

// * Run the code
// * g++ --std=c++17 06-first-and-last-occurence-b.cpp -o 06-first-and-last-occurence-b && ./06-first-and-last-occurence-b
