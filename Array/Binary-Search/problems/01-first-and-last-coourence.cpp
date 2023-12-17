// * WAP to find first & last occurence of element in array using Binary Search
// ! Note: Binary Search only works in monotonic function

#include<iostream>
using namespace std;

int firstOccurence(int arr[], int size, int key) {
  int s = 0;
  int e = size-1;
  int firstOcc = -1;
  while(s<=e) {
    int mid = s + ((e-s)/2);
    if(arr[mid] == key) {
      firstOcc = mid;
      e = mid-1;
    } else if(arr[mid] > key) {
      e = mid-1;
    } else if(arr[mid] < key) {
      s = mid+1;
    }
  }
  return firstOcc;
}

int lastOccurence(int arr[], int size, int key) {
  int s = 0;
  int e = arr[size-1];
  int lastOcc = -1;
  while(s<=e) {
    int mid = s + ((e-s)/2);
    if(arr[mid] == key) {
      lastOcc = mid;
      s = mid+1;
    } else if(arr[mid] > key) {
      e = mid-1;
    } else if(arr[mid] < key) {
      s = mid+1;
    }
  }
  return lastOcc;
}

int totalOccurence(int arr[], int size, int key) {
  int firstOcc = firstOccurence(arr, size, 3);
  int lastOcc = lastOccurence(arr, size, 3);
  return (lastOcc-firstOcc)+1;
}

int main() {
  int size = 8;
  int arr[8] = { 1,2,3,3,4,5,6,7 };
  cout<<"First occurence of 3 is at index: "<<firstOccurence(arr, size, 3)<<endl;
  cout<<"Last occurence of 3 is at index: "<<lastOccurence(arr, size, 3)<<endl;
  cout<<"Total occurence of 3: "<<totalOccurence(arr, size, 3);
  return -1;
}