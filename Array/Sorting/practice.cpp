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
  int n = arr.size();
  for(int i=0; i<n; i++) {
    int minIdx = i;
    for(int j=i+1; j<n; j++) {
      if(arr[j] < arr[minIdx]) {
        minIdx = j;
      }
    }
    swap(arr[i], arr[minIdx]);
  }
}

// * --------------------- Bubble Sort ---------------------


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
    if(!swapped) {
      break;
    }
  }
}

// * --------------------- Insertion Sort ---------------------

// * Shift the elements
void insertionSort(vector<int> &arr) {
  int n = arr.size();
  for(int i=1; i<n; i++) {
    int temp = arr[i];
    int j = i-1;
    while(j >= 0) {
      if(arr[j] > temp) {
        arr[j+1] = arr[j];
        j--;
      } else {
        break;
      }
    }
    arr[j+1] = temp;
  }
}

// * --------------------- Merge Sort ---------------------

void merge(vector<int> &arr, int low, int mid, int high) {
  vector<int> temp;
  int left = low, right = mid+1;

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

  for(int i=low; i<=high; i++) {
    arr[i] = temp[i-low];
  }
  
}

// * Divide & Merge
void mergeSort(vector<int>&arr, int low, int high) {
  if(low == high) return;

  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid+1, high);

  merge(arr, low, mid, high);
}

// * --------------------- Quick Sort ---------------------

int findPartitionEle(vector<int>&arr, int low, int high) {
  int pivot = arr[low];
  int i = low, j = high;
  while(i < j) {
    // * From left find element greater than pivot
    while(arr[i] <= pivot && i <= high) {
      i++;
    }

    // * From right find element smaller than pivot
    while(arr[j] > pivot && j >= low) {
      j--;
    }

    if(i < j) swap(arr[i], arr[j]);
  }

  // * Put the partition element at its correct place
  swap(arr[low], arr[j]);
  return j;
}

void quickSort(vector<int>&arr, int low, int high) {
  if(low < high) {
    int partitionIdx = findPartitionEle(arr, low, high);
    // cout<<"partitionIdx "<<partitionIdx<<endl;
    quickSort(arr, low, partitionIdx);
    quickSort(arr, partitionIdx+1, high-1);
    return;
  }
}


int main() {
  // vector<int> arr = { 2, 1 };
  // vector<int> arr = { 9,7,1,10,5 };
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
  // mergeSort(arr, 0, n-1);
  // * Quick Sort
  quickSort(arr, 0, n-1);

  print(arr);
  return 0;
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice 

/**
 * * 4 3 2 1
 * * 4 4 2 1
 * 
 * * 3 4 2 1
*/