/*
 * Number of Inversions 
 * Number of inversions in an array can be defined as the number of pairs of 'i', 'j' 
 * such that 'i' < 'j' and A[i] > A[j]
 * 
 * Example 1:
 * Input: nums = [5, 3, 2, 1, 4]
 * Output: 7
 * Explanation: Number of inversions (5, 3), (5, 2), (5, 1), (5, 4), (3, 2), (3, 1), (2, 1)
 * 
 * https://www.naukri.com/code360/problems/number-of-inversions_6840276
*/

#include<iostream>

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * Merge Arrays In sorted way & count pairs
int merge(std::vector<int> &arr, int low, int mid, int high) {
  std::vector<int> temp;
  int i = low, j = mid + 1, cnt = 0;
  while(i <= mid && j <= high) {
    if(arr[i] >= arr[j]) {
      // * Count the pairs
      cnt = cnt + (mid - i + 1);
      temp.push_back(arr[j++]);
    }
    else {
      temp.push_back(arr[i++]);
    }
  }

  while(i <= mid) {
    temp.push_back(arr[i++]);
  }

  while(j <= high) {
    temp.push_back(arr[j++]);
  }

  for (int i = low; i <= high; i++) {
    arr[i] = temp[i-low];
  }
  return cnt;
}

int mergeSort(std::vector<int> &arr, int low, int high) {
  int c = 0;
  if(low == high) return c;
  int mid = (low + high) / 2;
  c += mergeSort(arr, low, mid);
  c += mergeSort(arr, mid+1, high);
  c += merge(arr, low, mid, high);
  return c;
}

// * ------------------------- APPROACH 1: Brute Approach -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr) {
  int n = arr.size(), cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if(arr[i] > arr[j]) {
          cnt++;
      }
    }
  }
  return cnt;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Merge Sort & Count Pairs
// * TIME COMPLEXITY O(NLogN)
// * SPACE COMPLEXITY O(N)
// * Here we are altering the given input
int numberOfInversions(std::vector<int> arr) {
  int n = arr.size();
  int c = mergeSort(arr, 0, n - 1);
  return c;
}

int main() {
  std::vector<int> arr = {3, 2, 1};
  // std::vector<int> arr = {5, 4, 3, 2, 1};
  // std::vector<int> arr = {5, 3, 2, 1, 4};
  printArr(arr);
  // int inversions = bruteForce(arr);
  int inversions = numberOfInversions(arr);
  std::cout << "Number of inversions is " << inversions << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 09-number-of-inversion.cpp -o 09-number-of-inversion && ./09-number-of-inversion
