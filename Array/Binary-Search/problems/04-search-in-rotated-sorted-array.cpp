// * WAP to find index of element in rotated sorted array

// * Ex Array
// * [3,8,10,17,1], [8,10,17,1,3]

#include<iostream>
using namespace std;

int getPivotIndex(int arr[], int size) {
  int s = 0, e = size-1;
  while(s<e) {
    int mid = s+(e-s)/2;
    if(arr[mid] > arr[0]) {
      s = mid+1;
    } else {
      e = mid;
    }
  }
  return s;
}

int binarySearch(int arr[], int start, int end, int key) {
  int s = start;
  int e = end;
  while(s<=e) {
    int mid = s+(e-s)/2;
    if(arr[mid] == key) return mid;
    if(key > arr[mid]) {
      s = mid+1;
    } else {
      e = mid-1;
    }
  }
  return -1;
}

int findPosition(int arr[], int size, int key) {
  int keyIndex = -1;
  int pivotIdx = getPivotIndex(arr, size);
  if(key >= arr[pivotIdx] && key <= arr[size-1]) {
    keyIndex = binarySearch(arr, pivotIdx, size, 1);
  } else {
    keyIndex = binarySearch(arr, 0, pivotIdx, 1);
  }
  return keyIndex;
}

int main() {
  int size = 5;
  int key = 1;
  // int arr[5] = { 3, 8, 10, 17, 1 };
  int arr[5] = { 8, 10, 17, 1, 3 };
  int position = findPosition(arr, size, key);
  cout<<"position: "<<position<<endl;
  return 0;
}