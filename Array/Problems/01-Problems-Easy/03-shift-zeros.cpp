// * INPUT: arr = [0,1,0,3,12]
// * OUTPUT: arr = [1,3,12,0,0]

#include<iostream>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void print(int arr[], int n) {
 for(int i=0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void moveZeros(int arr[], int n) {
  int i = 0;
  for(int j=0; j<n; j++) {  
    if(arr[j] != 0) {
      swap(arr[i], arr[j]);
      i++;
    }
  }
}

int main() {
  int n = 6;
  int arr[6] = { 0,1,0,3,12,0 };
  print(arr, n);
  moveZeros(arr, n);
  print(arr, n);
  return 0;
}