// * Merge Sort - Divide & Combine

#include<iostream>
using namespace std;

void print(vector<int> &arr, int size) {
  for(int i=0; i<size; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

// * Merge two arrays in sorted way
void mergeArrays(vector<int> &arr, int low, int mid, int high) {
  vector<int> temp;

  // * [low...mid] 1st Array
  // * [mid+1...high] 2nd Array

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

  for(int i = low; i <= high; i++) {
    arr[i] = temp[i-low];
  } 

}

// * TIME COMPLEXITY O(N) * O(LogN) = O(NlogN)
// * SPACE COMPLEXITY O(N) - (for temp array)
void mergeSort(vector<int> &arr, int low, int high) {

  // * O(logN)
  if(low == high) return;
  int mid = (low + high) / 2;
  cout<<"low "<<low<<" high "<<high<<" mid "<<mid<<endl;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid+1, high);

  // * O(N)
  mergeArrays(arr, low, mid, high);
}

int main() {
  vector<int> arr = { 3, 2, 4, 1, 3 };
  int size = arr.size();

  cout<<"Merge Sort"<<endl;
  print(arr, size);
  mergeSort(arr, 0, size-1);
  print(arr, size); 
  return 0;
}