/*
 * Number of inversions in an array can be defined as the number of pairs of 'i', 'j' 
 * such that 'i' < 'j' and A[i] > A[j]
 * 
 * Example 1:
 * Input: nums = [5, 3, 2, 1, 4]
 * Output: 7
 * Explanation: Number of inversions (5, 3), (5, 2), (5, 1), (5, 4), (3, 2), (3, 1), (2, 1)
*/

#include<iostream>
using namespace std;

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void print(vector<int> &arr) {
  int size = arr.size();
  for(int i=0; i<size; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> arr) {
  int n = arr.size(), count = 0;
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      if(arr[i] > arr[j]) {
        cout<<arr[i]<<" "<<arr[j]<<endl;
        count++;
      }
    }
  }
  return count;
}

// * ------------------------- APPROACH 2: Optimal APPROACH (MERGE SORT) -------------------------

// * Merge two arrays in sorted way
int merge(vector<int> &arr, int low, int mid, int high) {
  vector<int> temp;
  int i = low, j = mid+1, count = 0;
  while(i <= mid && j <= high) {
    if(arr[i] <= arr[j]) {
      temp.push_back(arr[i]);
      i++;
    } 
    else {
      count = count + (i+mid);
      temp.push_back(arr[j]);
      j++;
    }
  }

  while(i <= mid) {
    temp.push_back(arr[i]);
    i++;
  }

  while(j <= high) {
    temp.push_back(arr[j]);
    j++;
  }

  for(int i=low; i<=high; i++) {
    arr[i] = temp[i-low];
  }
  return count;
}

int ms(vector<int> &arr, int low, int high) {
  int count = 0;
  if(low == high) return count;
  int mid = (low+high)/2;
  // cout<<"mid: "<<mid<<endl;
  count += ms(arr, low, mid);
  count += ms(arr, mid+1, high);
  count += merge(arr, low, mid, high);
  return count;
}

int mergeSort(vector<int> &arr) {
  int n = arr.size();
  int c = ms(arr, 0, n-1);
  return c;
}

// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(N) - (for temp array)
int optimalApproach(vector<int> arr) {
  int c = mergeSort(arr);
  return c;
  // print(arr);
}

int main() {
  // vector<int> arr = { 5, 3, 2, 1, 4 };
  vector<int> arr = { 4, 3, 2, 1 };
  // int count = bruteForce(arr);
  int count = optimalApproach(arr);
  cout<<"Number of Inversions: "<<count<<endl;
  return 0;
}