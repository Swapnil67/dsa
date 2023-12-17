/*
 * Given an integer array nums, return the number of reverse pairs in the array.
 * such that 'i' < 'j' and A[i] > (2 * A[j])
 * 
 * Example 1:
 * Input: nums = [5, 3, 2, 1, 4]
 * Output: 3
 * Explanation: Number of inversions (5, 2), (5, 1), (3, 1)
 * 
 * Example 2:
 * Input: nums = [4, 1, 2, 3, 1]
 * Output: 3
 * Explanation: Number of inversions (4, 1), (4, 1), (3, 1)
*/

#include<iostream>
using namespace std;


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

int countPairs(vector<int> &arr, int low, int mid, int high) {
  int c = 0, right = mid+1;
  for(int i=low; i<=mid; i++) {
    while(right <= high && arr[i] > 2*arr[right]) {
      right++;
    }
    c = c + (right - (mid+1));
  }
  return c;
}

int mergeSort(vector<int> &arr, int low, int high) {
  int c = 0;
  if(low >= high) return c;
  int mid = (low + high) / 2;
  c += mergeSort(arr, low, mid);
  c += mergeSort(arr, mid+1, high);
  c += countPairs(arr, low, mid, high);
  mergeArrays(arr, low, mid, high);
  return c;
}

int main() {
  vector<int> arr = { 1,3,2,3,1 };
  // vector<int> arr = { 5,3,2,1,4 };
  // vector<int> arr = { 4,1,2,3,1 };
  int n = arr.size();
  int c = mergeSort(arr, 0, n-1);
  cout<<"Reverse Pairs "<<c<<endl;
  return 0;
}
