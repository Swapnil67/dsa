/*
* In dynamic memory allocation in C++, the memory is defined during the execution of the program.
* It is known as run-time allocation. 
* Heap memory is used.
*/

#include<iostream>
using namespace std;

int getSum(int* arr, int n) {
  int sum = 0; 
  for(int i=0; i<n; i++) {
    sum += arr[i];
  }
  return sum;
}

void print(int* arr, int n) {
  for(int i=0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main() {
  int n;
  cout<<"Enter the size of array: ";
  cin>>n;

  // * Allocate memory.
  int* arr = new int[n];

  cout<<"Enter the elements of array"<<endl;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }

  cout<<"Sum of all elements of array: ";
  int sum = getSum(arr, n);
  cout<<sum<<endl;

  // * Free up space.
  delete[] arr;

  print(arr, n);

  return 0;
}