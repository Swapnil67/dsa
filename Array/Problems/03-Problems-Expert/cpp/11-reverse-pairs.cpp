/*
 * Given an integer array nums, return the number of reverse pairs in the array.
 * such that 'i' < 'j' and A[i] > (2 * A[j])
 * 
 * Example 1:
 * Input: nums = [5, 3, 2, 1, 4]
 * Output: 3
 * Explanation: Number of inversions (5, 2), (5, 1), (3, 1)
 * 
 * Example 2:
 * Input: nums = [4, 1, 2, 3, 1]
 * Output: 3
 * Explanation: Number of inversions (4, 1), (4, 1), (3, 1)
 * 
 * https://leetcode.com/problems/reverse-pairs/description/
 * https://www.naukri.com/code360/problems/team-contest_6840309
*/

#include<iostream>

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * Count reverse pairs : O(N)
int countPairs(std::vector<int> arr, int low, int mid, int high) {
  int c = 0, j = mid+1;
  for (int i = low; i <= mid; i++) {
    while (j <= high && arr[i] > (2 * arr[j])) {
      j++;
    }
    c = c + (j - (mid + 1));
  }
  return c;
}

// * Perform merge sort : O(NlogN)
void merge(std::vector<int> &arr, int low, int mid, int high) {
  // * [low...mid] 1st Array
  // * [mid+1...high] 2nd Array

  int i = low, j = mid + 1;
  std::vector<int> temp;
  while (i <= mid && j <= high) {
    if (arr[i] >= arr[j]) {
      temp.push_back(arr[j++]);
    }
    else {
      temp.push_back(arr[i++]);
    }
  }

  while (i <= mid) {
    temp.push_back(arr[i++]);
  }

  while (j <= high) {
    temp.push_back(arr[j++]);
  }

  for (int i = low; i <= high; i++) {
    arr[i] = temp[i-low];
  }
}

int mergeSort(std::vector<int> &arr, int low, int high) {
  int cnt = 0;
  if(low >= high) return cnt;
  int mid = (low + high) / 2;
  cnt += mergeSort(arr, low, mid);
  cnt += mergeSort(arr, mid+1, high);
  cnt += countPairs(arr, low, mid, high);
  merge(arr, low, mid, high);
  return cnt;
}

// * ------------------------- APPROACH 1: Brute Approach -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr) {
  int n = arr.size();
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if(arr[i] > (2 * arr[j])) {
        cnt++;
      }
    }
  }
  return cnt;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Merge Sort & Count Pairs
// * TIME COMPLEXITY O(2nLogn)
// * SPACE COMPLEXITY O(N)
// * Here we are altering the given input
int findReversePairs(std::vector<int> &arr) {
  int n = arr.size();
  int c = mergeSort(arr, 0, n - 1);
  return c;
}

int main() {
  // std::vector<int> arr = {5, 3, 2, 1, 4};
  // std::vector<int> arr = {2, 4, 3, 5, 1};
  std::vector<int> arr = {40, 25, 19, 12, 9, 6, 2};

  printArr(arr);
  // int reversePairs = bruteForce(arr);
  int reversePairs = findReversePairs(arr);
  std::cout << "Reverse Pairs are " << reversePairs << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 11-reverse-pairs.cpp -o 11-reverse-pairs && ./11-reverse-pairs
