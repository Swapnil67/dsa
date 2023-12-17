/*
 * Foa a sorted array 'arr' 'lower_bound' of a number 'x' is defined as the smallest index 'idx'
 * such that arr[i] >= x
 * If all the numbers are smaller than 'x' then 'n' should be the 'lower_bount' of 'x'.
 * 'n' = size of array
 * 
 * Example 1:
 * Input: arr = [ 1, 2, 2, 3, 3, 5, 6 ], x = 2
 * Output: 1

 * Example 2:
 * Input: arr = [ 1, 2, 2, 3, 3, 5, 6 ], x = 5
 * Output: 5
*/

#include<iostream>
using namespace std;

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
int lowerBoundBrute(vector<int> arr, int n, int x) {
  int ans = n;
  for(int i=0; i<n; i++) {
    if(arr[i] >= x) {
      ans = min(i, ans);
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(logn)
int lowerBoundOptimal(vector<int> arr, int n, int x) {
  int low = 0, high = n-1, ans = n;
  while(low <= high) {
    int mid = (low+high)/2;
    if(arr[mid] >= x) {
      ans = mid;
      high = mid-1;
    }
    else {
      low = mid+1;
    } 
  }
  return ans;
}

int main() {
  int x = 5;
  vector<int> arr = { 1, 2, 2, 3, 3, 5, 6 };

  // int x = 10063;
  // vector<int> arr = { 2462, 3941, 4337, 6505, 11444, 12819, 13811, 18113, 23214, 26985, 29076 };
  int n = arr.size();
  // int idx = lowerBoundBrute(arr, n, x);
  int idx = lowerBoundOptimal(arr, n, x);
  cout<<"Lower bound: "<<idx<<endl;
  return 0;
}