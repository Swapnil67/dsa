
// * Ex Array
// * [3,8,10,17,1], [8,10,17,1,3]

#include<iostream>
using namespace std;

int getPivotIndex(int arr[], int size) {
  int s=0, e = size-1;
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

int main() {
  int size = 5;
  // int arr[5] = { 3, 8, 10, 17, 1 };
  int arr[5] = { 8, 10, 17, 1, 3 };
  int pivotIndex = getPivotIndex(arr, size);
  cout<<"pivotIndex: "<<pivotIndex;
  return 0;
}