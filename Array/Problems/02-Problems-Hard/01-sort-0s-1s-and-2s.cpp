// * WAP to sort 0's, 1's and 2's in an array
// * INPUT: arr = [0,1,2,0,1,2,1,2,0,0,0,1]
// * OUTPUT: arr = [0,0,0,0,0,1,1,1,1,2,2,2]

#include<iostream>
using namespace std;

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void print(int a[], int n) {
  for(int i=0; i<n; i++) {
    cout<<a[i]<<" ";
  }
  cout<<endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`

// TODO
// * Use Merge Sort

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------`

// * TIME COMPLEXITY O(N) + O(N) = O(2N)
// * SPACE COMPLEXITY O(1)
void betterApproach(int arr[], int n) {
  int zero_count = 0, one_count = 0, two_count = 0;
  for(int i=0; i<n; i++) {
    if(arr[i] == 0) zero_count++;
    if(arr[i] == 1) one_count++;
    if(arr[i] == 2) two_count++;
  }
  // cout<<"zero_count "<<zero_count<<endl;
  // cout<<"one_count "<<one_count<<endl;
  // cout<<"two_count "<<two_count<<endl;

  for(int i=0;i<zero_count;i++) {
    arr[i] = 0;
  }
  for(int j=zero_count;j<zero_count+one_count;j++) {
    arr[j] = 1;
  }
  for(int k=zero_count+one_count;k<n;k++) {
    arr[k] = 2;
  }
}

// * ------------------------- APPROACH 3: Dutch National Flag Algorithm -------------------------`

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
void optimalApproach(int arr[], int n) {
  int low = 0, mid = 0, high = n-1;
  while(mid <= high) {
    if(arr[mid] == 0) {
      swap(arr[mid], arr[low]);
      low++;
      mid++;
    } 
    else if(arr[mid] == 1) {
      mid++;
    }
    else if(arr[mid] == 2) {
      swap(arr[mid], arr[high]);
      high--;
    }
  }
}


int main() {
int n;
  cout<<"Enter a number ";
  cin>>n;
  int *arr = new int[n]; // * Dynamic Memory Allocation
  cout<<"Enter elements of array: ";
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  cout<<"Sorted 0s, 1s & 2s"<<endl;
  print(arr, n);
  betterApproach(arr, n);
  // optimalApproach(arr, n);
  print(arr, n);
  return 0;
}