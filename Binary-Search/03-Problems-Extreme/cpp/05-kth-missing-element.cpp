/*
* Kth Missing Positive Number 

* You are given a strictly increasing array 'vec' and a positive integer 'k'.
* Find the 'kth' positive integer missing from 'vec'.

* Example 1:
* Input: vec = [1,2,3,4], k = 2
* Output: missing-number = 6
* Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

* Example 2:
* Input: arr = [2,3,4,7,11], k = 5
* Output: missing-number = 9
* Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

* https://www.naukri.com/code360/problems/kth-missing-element_893215
* https://leetcode.com/problems/kth-missing-positive-number/description/

*/

#include<iostream>


// * ------------------------- Utility Functions -------------------------`

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N) 
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr, int k) {
  for(int i=0; i<arr.size(); i++) {
    if(arr[i] <= k) {
      k++;
    }
    else {
      break;
    }
  }
  return k;
}

int findKthMissingNumber(std::vector<int> arr, int k) {
  // TODO
  return k;
}

int main() {
  std::vector<int> arr = {2, 3, 4, 7, 11};
  int k = 5;
  printArr(arr);
  int missingNumber = bruteForce(arr, k);
  std::cout << k << " missing number is " << missingNumber << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 05-kth-missing-element.cpp -o 05-kth-missing-element && ./05-kth-missing-element