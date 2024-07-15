#include<iostream>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void print(int arr[], int size) {
  for(int i=0; i<size; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

// * Push the largest element at last
// * For every i there are n-i comparisions
void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    bool swapped = false;
    for (int j = 0; j < n - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if(swapped == false) break;
  }
}


int main() {
  int size = 5;
  int arr[5] = {17,27,9,2,10};
  cout<<"Bubble Sort"<<endl;
  cout<<"Before Swapping"<<endl;
  print(arr, size);
  bubbleSort(arr, size);
  cout<<"After Swapping"<<endl;
  print(arr, size); 
  return 0;
}