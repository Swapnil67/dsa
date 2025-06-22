/*
 * First and Last Position of an Element In Sorted Array
 * You have been given a sorted array/list of integers 'arr' of size 'n' and an integer 'x'.
 * Find the total number of occurrences of 'x' in the array/list.
 * 
 * 
 * Example 1:
 * Input: arr = [ 1, 1, 1, 2, 2, 3, 3 ],  k = 3
 * Output: 2

 * Example 2:
 * Input: arr = [ 1, 1, 3, 3, 5 ], k = 9
 * Output: 0
 * 
 * https://www.naukri.com/code360/problems/occurrence-of-x-in-a-sorted-array_630456
*/

#include <vector>
#include <iostream>

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

int countOccurences(std::vector<int> arr, int k) {
  int firstOccurence = findFirstOccurence(arr, k);
  if(firstOccurence == -1) return 0;
  int secondOccurence = findLastOccurence(arr, k);
  return secondOccurence - firstOccurence + 1;
}

int main() {
  // * testcase 1
  // int k = 3;
  // std::vector<int> arr = { 1, 1, 1, 2, 2, 3, 3 };

  // * testcase 2
  int k = 8;
  std::vector<int> arr = { 1, 1, 1, 2, 2, 3, 3 };

  int occurences = countOccurences(arr, k);
  std::cout<<"Total Occurences: "<<occurences<<std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 07-count-occurences.cpp -o output && ./output