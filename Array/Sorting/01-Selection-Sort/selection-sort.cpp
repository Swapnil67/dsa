// * Selection Sort
#include<iostream>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// * Takes the minimum at front
// * Time Complexity O(N^2)
// * Space Complexity O(1)
void selectionSort(int arr[], int size) {
  for(int i=0; i<size-1; i++) {
    int minIndex = i;
    for(int j=i+1; j<size; j++) {
      if(arr[minIndex] > arr[j]) {
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
  }
}

void print(int arr[], int size) {
  for(int i=0; i<size; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main() {
  int size = 5;
  int arr[5] = {17,27,9,2,10};
  cout<<"Selection Sort"<<endl;
  cout<<"Before Swapping"<<endl;
  print(arr, size);
  selectionSort(arr, size);
  cout<<"After Swapping"<<endl;
  print(arr, size); 
  return 0;
}

// * Run the code
// * g++ --std=c++17 selection-sort.cpp -o selection-sort && ./selection-sort 