/*
* There is an integer array nums sorted in ascending order (with distinct values).
* Given the array nums after the possible rotation and an integer target, return the index of target
* if it is in nums, or -1 if it is not in nums.

* Example 1:
* Input: nums = [4,5,6,7,0,1,2], target = 0
* Output: 4

* Example 2:
* Input: nums = [4,5,6,7,0,1,2], target = 3
* Output: -1

* https://leetcode.com/problems/search-in-rotated-sorted-array/
* https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_1082554?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

*/

#include<iostream>
using namespace std;

// * T(N) = O(logn)
// * S(N) = O(1)
int searchDistinctSortedArray(vector<int>arr, int n, int target) {
  int low = 0, high = n-1;
  while(low <= high)  {
    int mid = (low + (high-low) / 2);
    if(arr[mid] == target) return mid;

    // * Identify the sorted half
    if(arr[low] > arr[mid]) {
      // * Search in Right Part
      if(arr[mid] <= target && target <= arr[high]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    } 
    else {
      // * Search in Left Part
      if(arr[low] <= target && target <= arr[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
  }
  return -1;
}

int main() {

  vector<int> arr = {4,5,6,7,0,1,2};
  int n = arr.size(), target = 0;
  int idx = searchDistinctSortedArray(arr, n, target);
  cout<<"Index: "<<idx<<endl;
  return 0;
}