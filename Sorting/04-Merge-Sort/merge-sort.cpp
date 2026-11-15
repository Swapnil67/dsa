// * Merge Sort - Divide & Combine

// ! Stable Sorting 
// * Relative order of SAME elements preserved.

#include <iostream>
using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << "\n";
}

// * Merge two arrays in sorted way
void mergeArrays(vector<int> &arr, int low, int mid, int high) {
  vector<int> temp;

  // * [low...mid] 1st Array
  // * [mid+1...high] 2nd Array

  int l = low, r = mid + 1;
  while (l <= mid && r <= high) {
    if (arr[l] <= arr[r]) {
      temp.push_back(arr[l++]);
    }
    else {
      temp.push_back(arr[r++]);
    }
  }

  // * Push all remaining left elements
  while (l <= mid) temp.push_back(arr[l++]);
  
  // * Push all remaining right elements
  while (r <= high) temp.push_back(arr[r++]);

  for (int i = low; i <= high; ++i) {
    arr[i] = temp[i - low];
  }
}

// * TIME COMPLEXITY O(N) * O(LogN) = O(NlogN)
// * SPACE COMPLEXITY O(N) - (for temp array)
void mergeSort(vector<int> &arr, int low, int high) { // * O(logN)
  if (low == high)
    return;

  int mid = (low + high) / 2;
  // cout << "low " << low << " high " << high << " mid " << mid << endl;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);

  // * O(N)
  mergeArrays(arr, low, mid, high);
}

int main() {
  vector<int> arr = {3, 2, 4, 1, 3};
  int size = arr.size();
  
  cout << "Merge Sort" << endl;
  printArr(arr);

  mergeSort(arr, 0, size - 1);

  printArr(arr);
  return 0;
}

// * Run the code
// * g++ --std=c++20 merge-sort.cpp -o output && ./output
