// * WAP to find a element in array using Binary Search
// ! Note: Binary Search only works in monotonic function

#include<iostream>
using namespace std;

// * Time Complexity O(logn)
int BinarySearch(int arr[], int size, int key) {
  int start = 0;
  int end = size-1;
  while(start<=end) {
    int mid = start + (end-start)/2;
    if(arr[mid] == key) {
      return mid;
    }

    if(arr[mid] > key) {
      end = mid-1;
    } else {
      start = mid+1;
    }
  }
  return -1;
}

// * Time Complexity O(logn)
int binarySearchRecursive(int arr[], long long low, long long high, int target) {
  if(low > high) return -1;
  long long mid = low + (high - low) / 2;
  if(arr[mid] == target) return mid;
  else if(arr[mid] > target) {
    high = mid-1;
  }
  else {
    low = mid+1;
  }
  return binarySearchRecursive(arr, low, high, target);
} 

int main() {
  int even[6] = { 2,6,10,20,36,100 };
  int odd[6] = { 1,3,7,19,23,25 };
  
  // int idx1 = BinarySearch(even, 6, 20);
  // cout<<"Even Array: "<<idx1<<endl;
  // int idx2 = BinarySearch(odd, 6, 20);
  // cout<<"Odd Array: "<<idx2<<endl;

  cout<<"Recursive Approach"<<endl;
  int idx = binarySearchRecursive(even, 0, 5, 20);
  cout<<"idx: "<<idx<<endl;

  return 0;
}