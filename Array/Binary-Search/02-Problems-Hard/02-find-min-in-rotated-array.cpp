/*
* Given the sorted rotated array nums of unique elements, return the minimum element of this array.

* Example 1:
* Input: nums = [3,4,5,1,2]
* Output: 1

* Example 2:
* Input: nums = [4,5,6,7,0,1,2]
* Output: 0

* https://www.codingninjas.com/studio/problems/rotated-array_1093219?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
* https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

*/

#include<iostream>
using namespace std;

int findMin(vector<int>& arr) {
	int n = arr.size(), ans = INT_MAX;
	long long low = 0, high = n - 1;
	while(low <= high) {
		long long mid = (low + (high - low)/2);
		if(arr[low] > arr[mid]) {
			// Right part is sorted
			ans = min(ans, arr[mid]);
			high = mid - 1;
		}
		else {
			// Left part is sorted
			ans = min(ans, arr[low]);
			low = mid + 1;
		}
	}
	return ans;
}


int main() {
  // vector<int> arr = {1,2,3};
  // vector<int> arr = {2,3,4,1};
  vector<int> arr = {5,6,0,1,2};
  int r = findMin(arr);
  cout<<"Minimum: "<<r<<endl;
  return 0;
}