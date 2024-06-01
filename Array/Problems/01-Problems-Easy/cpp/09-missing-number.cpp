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
// * Using Hashed array
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int betterApproach(std::vector<int> arr) {

  // * Find the largest element in array
  int maxEle = INT_MIN;
  int n = arr.size();
  for(int i=0; i<n; i++) {
    maxEle = std::max(maxEle, arr[i]);
  }
  
  // * Create a hashed array of length maxEle containing 0
  std::vector<int> hashedArr(maxEle, 0);

  // * Fill the hashed array
  for(int i=0; i<n; i++) {
    hashedArr[arr[i]] = 1;
  }

  for(int i=0; i<maxEle; i++) {
    if(hashedArr[i] == 0) return i;
  }
  
  return 0;
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * Using Sum of n natural numbers
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int optimal(std::vector<int>arr) {
  int n = arr.size();
  long long sumN = n*(n+1)/2;
  long long sumArr = 0;
  for(int i=0; i<=n; i++) {
    sumArr += arr[i];
  }
  // std::cout<<"sumN: "<<sumN<<std::endl;
  // std::cout<<"sumArr: "<<sumArr<<std::endl;
  return sumN-sumArr;
}

int main() {
  // std::vector<int> arr = {3, 0, 1};
  std::vector<int> arr = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  // std::vector<int> arr = { 4, 6, 7, 9, 2, 1, 8, 11, 10, 3, 0 };
  // int missingNumber = bruteForce(arr);
  // int missingNumber = betterApproach(arr);
  int missingNumber = optimal(arr);
  std::cout << "Missing Number: " << missingNumber << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 09-missing-number.cpp -o 09-missing-number && ./09-missing-number