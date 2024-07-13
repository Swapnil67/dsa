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
  for (int i = 0; i < arr.size(); i++) {
    if(arr[i] <= k) {
      k++;
    }
    else {
      break;
    }
  }
  return k;
}

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------`
// * Find the missing number at each arr[i]
// * TIME COMPLEXITY O(logN) 
// * SPACE COMPLEXITY O(1)
int findKthMissingNumber(std::vector<int> arr, int k) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    int missingTillM = arr[m] - (m + 1);
    if(missingTillM < k) {
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }

  // * kth = arr[r] + more
  // * kth = arr[r] + (k - missingTillR)
  // * kth = arr[r] + (k - (arr[r] - (r+1)))
  // * kth = k + r + 1
  // * kth = k + l ------------ (l = r + 1)

  return k + l;
}

int main() {
  int k = 5;
  std::vector<int> arr = {2, 3, 4, 7, 11};
  printArr(arr);
  // int missingNumber = bruteForce(arr, k);
  int missingNumber = findKthMissingNumber(arr, k);
  std::cout << k << " missing number is " << missingNumber << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 05-kth-missing-element.cpp -o 05-kth-missing-element && ./05-kth-missing-element