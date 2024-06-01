/*
 * Single element in a Sorted Array
 * https://leetcode.com/problems/single-element-in-a-sorted-array/
 * https://www.codingninjas.com/codestudio/problems/unique-element-in-sorted-array_1112654
*/

#include<iostream>
using namespace std;

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> arr) {
  int n = arr.size();

  if(n == 1) return arr[0];

  for(int i=0; i<n; i++) {
    if(i==0) {
      if(arr[i] != arr[i+1]) {
          return arr[0];
      }
    } 
    else if(i == n-1) {
      if(arr[i] != arr[i-1]) {
          return arr[n-1];
      }
    } 
    else {
      if(arr[i] != arr[i-1] && arr[i] != arr[i+1]) {
          return arr[i];
      }
    }
  }

  return -1;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------

// * TIME COMPLEXITY O(logN)
// * SPACE COMPLEXITY O(1)
int optimalApproach(vector<int> arr) {
  int n = arr.size();

  // Solve some edge cases manually
  if(n == 1) return arr[0];
  if(arr[0] != arr[1]) return arr[0];
  if(arr[n-2] != arr[n-1]) return arr[n-1];

  long long low = 1, high = n-2;

	while(low <= high) {
		long long mid = (low + (high - low)/2);
		if(arr[mid-1] != arr[mid] && arr[mid+1] != arr[mid]) {
			return arr[mid];
		}

		// * Do elimination
		if((mid % 2 == 1 && arr[mid] == arr[mid-1]) || (mid % 2 == 0 && arr[mid] == arr[mid+1])) {
			// * Element is on right half
			low = mid+1;
		}
		else {
			// * Element is on left half
			high = mid-1;
		}

	}
	return -1;

}

int main() {
  vector<int> arr = { 1,1,2,3,3,4,4,8,8 };
  // vector<int> arr = { 3,3,7,7,10,11,11 };
  // int single_element = bruteForce(arr);
  int single_element = optimalApproach(arr);
  cout<<"Single ELement "<<single_element<<endl;
  return 0;
}