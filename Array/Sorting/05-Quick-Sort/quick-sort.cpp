// * Quick Sort - Divide & Conquer

#include<iostream>
using namespace std;

void printArr(vector<int> arr) {
  for(int i=0;i<arr.size();i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int findPartition(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int i = low, j = high;
  while(i < j) {
    while(arr[i] <= pivot && i <= high + 1) {
      i++;
    }
    while(arr[j] > pivot && j >= low) {
      j--;
    }
    if(i < j) swap(arr[i], arr[j]);
  }
  swap(arr[low], arr[j]);
  return j;
}

void quickSort(vector<int> &arr, int low, int high) {
  if(low < high) {
    int partition = findPartition(arr, low, high);
    // cout<<"partition: "<<partition<<endl;
    quickSort(arr, low, partition-1);
    quickSort(arr, partition+1, high);
    return;
  }
}

int main() {
  vector<int> arr = { 3,4,1,6,2,5,7 };
  printArr(arr);
  int n = arr.size();
  quickSort(arr, 0, n-1);
  printArr(arr);
  return 0;
}