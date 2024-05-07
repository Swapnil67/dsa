/**
 * * Missing Number
 * * Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that
 * * is missing from the array.

 * * Example 1
 * * Input  : 'arr' = [3,0,1]
 * * Output : 2

 * * Example 2
 * * Input  : 'arr' = [0,1]
 * * Output : 2
 * 
 * * Example 3
 * * Input  : 'arr' = [9,6,4,2,3,5,7,0,1]
 * * Output : 8

 * * https://leetcode.com/problems/missing-number/
*/

#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr) {
  int n = arr.size();
  for(int i=1; i<=n; i++) {
    bool exists = false;
    for(int j=0; j<n; j++) {
      if(arr[j] == i) {
        exists = true;  
        break;
      }
    }
    if(exists == false) {
      return i;
    }
  }
  return 0;
}

// * ------------------------- APPROACH 2: Better APPROACH -------------------------`
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int betterApproach(std::vector<int> arr) {
  int n = arr.size();
  std::vector<int> temp(n, 0);
  for(int i=0; i<n; i++) {
    temp[arr[i]] = 1;
  }
  // printArr(temp);
  for(int i=1; i<n; i++) {
    if(temp[i] == 0) 
      return i;
  }
  return 0;
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int optimal(std::vector<int>arr) {
  int n = arr.size();
  long long sumN = n*(n+1)/2;
  long long sumArr = 0;
  for(int i=0; i<n; i++) {
    sumArr += arr[i];
  }
  // std::cout<<sumN<<std::endl;
  // std::cout<<sumArr<<std::endl;
  return sumN-sumArr;
}

int main() {
  // std::vector<int> arr = {3, 0, 1};
  std::vector<int> arr = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  // int missingNumber = bruteForce(arr);
  // int missingNumber = betterApproach(arr);
  int missingNumber = optimal(arr);
  std::cout << "Missing Number: " << missingNumber << std::endl;
  return 0;
}

// * g++ --std=c++17 09-missing-number.cpp -o 09-missing-number && ./09-missing-number