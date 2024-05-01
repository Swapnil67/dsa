// * Selection Sort

#include<vector>
#include<iostream>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void print(vector<int>arr) {
  for(int i=0; i<arr.size(); i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

// * --------------------- Selection Sort ---------------------

// * Takes the minimum at front
void selectionSort(vector<int> &arr) {
  // TODO
}

// * --------------------- Bubble Sort ---------------------


// * Push the largest element at last
void bubbleSort(vector<int> &arr){
  // TODO
}

// * --------------------- Insertion Sort ---------------------

// * Shift the elements
void insertionSort(vector<int> &arr) {
  // TODO
}

// * --------------------- Quick Sort ---------------------

void quickSort(vector<int>&arr, int low, int high) {
  // TODO
}

// * --------------------- Merge Sort ---------------------

// * Divide & Merge
void mergeSort(vector<int>&arr, int low, int high) {
  // TODO
}

int main() {
  vector<int> arr = { 9,7,1,10,5 };
  // vector<int> arr = { 7,5,1,9 };
  // vector<int> arr = { 17,27,9,2,10 };
  // vector<int> arr = { 5,2,3,7,1 };
  int n = arr.size();

  print(arr);

  // * Selection Sort
  // selectionSort(arr);
  // * Bubble Sort
  // bubbleSort(arr);
  // * Insertion Sort
  // insertionSort(arr);
  // * Merge Sort
  // mergeSort(arr, 0, n-1);
  // * Quick Sort
  // quickSort(arr, 0, n-1);

  print(arr);
  return 0;
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice 