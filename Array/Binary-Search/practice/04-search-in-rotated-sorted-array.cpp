// * WAP to find index of element in rotated sorted array

// * Ex Array
// * [3,8,10,17,1], [8,10,17,1,3]

#include<iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int key) {
}

int getPivotIndex(int arr[], int size) {
} 

int findPosition(int arr[], int size, int key) {
}


int main() {
  int size = 5;
  int key = 1;
  // int arr[5] = { 3, 8, 10, 17, 1 };
  int arr[5] = { 8, 10, 17, 1, 3 };
  int position = findPosition(arr, size, key);
  cout<<"Position "<<position;
  return 0;
}

/* 
* Steps
* 1. First find the pivot index
* 2. Decide which array to search on based on pivot
* 3. Find the key using binary search 
*/
