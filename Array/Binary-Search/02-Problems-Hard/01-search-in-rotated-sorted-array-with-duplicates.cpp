/*
* There is an integer array nums sorted in ascending order (not necessarily with distinct values).
* Given the array nums after the rotation and an integer target, return true if target is in nums, 
* or false if it is not in nums.

* Example 1:
* Input: nums = [2,5,6,0,0,1,2], target = 0
* Output: true

* Example 2:
* Input: nums = [2,5,6,0,0,1,2], target = 3
* Output: false

* https://www.codingninjas.com/codestudio/problems/search-in-a-rotated-sorted-array-ii_7449547?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
* https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

*/

#include<iostream>
using namespace std;

// * T(N) = O(logn)
// * S(N) = O(1)
bool searchNonDistinctSortedArray(vector<int> arr, int n, int target) {
  long long low = 0, high = n-1;
  while(low <= high) {
    long long mid = (low + (high-low)/2);
    
    if(arr[mid] == target) return true;

    if(arr[low] == arr[mid] == arr[high]) {
      low = low + 1;
      high = high - 1;
      continue;
    }

    if(arr[low] > arr[mid]) {
      // * Search in right side
      if(arr[mid] <= target && target <= arr[high]) {
        low = mid + 1;
      } 
      else {
        high = mid - 1;
      }
    } 
    else {
      // * Search in left side
      if(arr[low] <= target && target <= arr[mid]) {
        high = mid - 1;
      }
      else {
        low = mid + 1;
      }
    }

  }
  return false;
}

int main() {
  vector<int> arr = {2,5,6,0,0,1,2};
  int target = 0, n = arr.size();
  bool isExists = searchNonDistinctSortedArray(arr, n, target);
  cout<<"Is Exists: "<<isExists<<endl;
  return 0;
}