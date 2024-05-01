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

// * Takes the minimum at front
void selectionSort(vector<int> &arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) {
    int smallestIdx = i;
    for(int j=i+1; j<n; j++) {
      if(arr[smallestIdx] > arr[j]) {
        smallestIdx = j;
      }
    }
    swap(arr[i], arr[smallestIdx]);
  }
}

// * Push the largest element at last
void bubbleSort(vector<int> &arr){
  int n = arr.size();
  for(int i=0; i<n; i++) {
    bool swapped = false;
    for(int j=0; j<n-1; j++) {
      if(arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
        swapped = true;
      }
    }
    if(swapped == false) break;
  }
}

// * Shift the elements
void insertionSort(vector<int> &arr) {
  for(int i=1; i<arr.size(); i++) {
    int temp = arr[i];
    int j = i-1;
    for(; j>=0; j--) {
      if(arr[j] > temp) {
        arr[j+1] = arr[j];
      } else {
        break;
      }
    }
    arr[j+1] = temp;
  }
}

void quickSort(vector<int>&arr, int low, int high) {

}

// * --------------------- Merge Sort ---------------------

void merge(vector<int> &arr, int low, int mid, int high)  {
  vector<int> temp;
  int left = low;
  int right = mid+1;

  while(left <= mid && right <= high) {
    if(arr[left] <= arr[right]) {
      temp.push_back(arr[left]);
      left++;
    }
    else {
      temp.push_back(arr[right]);
      right++;
    }
  }

  while(left <= mid) {
    temp.push_back(arr[left]);
    left++;
  }

  while(right <= high) {
    temp.push_back(arr[right]);
    right++;
  }

  for(int i = low; i <= high; i++) {
    arr[i] = temp[i-low];
  } 
}

// * Divide & Merge
void mergeSort(vector<int>&arr, int low, int high) {
  if(low >= high) {
    return;
  }
  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid+1, high);
  merge(arr, low, mid, high);
}

int main() {
  // vector<int> arr = { 9,7,1,10,5 };
  // vector<int> arr = { 7,5,1,9 };
  vector<int> arr = { 17,27,9,2,10 };
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
  mergeSort(arr, 0, n-1);
  // * Quick Sort
  // quickSort(arr, 0, n-1);

  print(arr);
  return 0;
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice 