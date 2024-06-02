/*
* Kth Missing Positive Number
* Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
* Return the kth positive integer that is missing from this array.

* Example 1:
* Input: arr = [2,3,4,7,11], k = 5
* Output: 9
* Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

* Example 2:
* Input: arr = [1,2,3,4], k = 2
* Output: 6
* Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

* https://leetcode.com/problems/kth-missing-positive-number/description/
* https://www.codingninjas.com/studio/problems/kth-missing-element_893215

*/

#include<iostream>
using namespace std;

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> arr, int k) {
  for(int i=0; i<arr.size(); i++) {
    if(arr[i] <= k) k++;
    else break;
  }
  return k;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// TODO

int main() {
  vector<int> arr = { 2, 3, 4, 7, 11 };
  int k = 5;

  int missingInteger = bruteForce(arr, k);
  cout<<"The "<<k<<" missing integer is "<<missingInteger<<endl;
} 