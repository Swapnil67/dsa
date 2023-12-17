#include<iostream>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void printArr(int arr[], int n) {
  for(int i=0; i<n; i++)  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

// * ------------------------- APPROACH 1: Two Pointer Approach -------------------------`

void approachOne(int arr[], int l, int r) {
  if(l >= r) return;
  swap(arr[l], arr[r]);
  approachOne(arr, l+1, r-1);
}

// * ------------------------- APPROACH 2: Single Pointer Approach -------------------------`

void approachTwo(int arr[], int n, int i) {
  if(i >= n/2) return;
  swap(arr[i], arr[n-i-1]);
  approachTwo(arr, n, i+1);
}

int main() {
  int n;
  cout<<"Enter the size of array: ";
  cin>>n;

  int *arr = new int[n];
  cout<<"Enter the elements of array"<<endl;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }

  cout<<"Before swapping"<<endl;
  printArr(arr, n);
  
  // * Approach 1
  // approachOne(arr, 0, n-1);

  // * Approach 2
  approachTwo(arr, n, 0);

  cout<<"After swapping"<<endl;
  printArr(arr, n);
  return 0;
}

/*
 *  0 1 2 3 4
 *  1 2 3 4 5
 *  i
*/