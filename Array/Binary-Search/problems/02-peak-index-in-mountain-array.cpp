// * WAP to find peak index in mountain array using Binary Search
// ! Note: Binary Search only works in monotonic function

// * Mountain Array
// * [0,1,0], [0,2,1,0], [0,10,5,0]

#include<iostream>
using namespace std;

int peakElement(int arr[], int size) {
  int s = 0;
  int e = size-1;
  while(s<e) {
    int mid = s+((e-s)/2);
    if(arr[mid] < arr[mid+ 1]) {
      s = mid+1;
    } else {
      e = mid;
    }
  }
  return s;
}

int main() {
  int size = 4;
  int arr[4] = {0,10,5,0};
  int peak = peakElement(arr, size);
  cout<<"Peak element in mountain array is: "<<arr[peak];
  return 0;
}