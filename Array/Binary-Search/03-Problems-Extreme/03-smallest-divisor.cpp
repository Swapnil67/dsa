/*
  * Smallest Divisor
  * You are given an array of integers 'arr' and an integer 'limit'.
  * Your task is to find the smallest positive integer divisor, such that upon dividing all the elements
  * of the given array by it, the sum of the division's result is less than or equal to the given integer's limit
  * 
  * Example 1:
  * Input: arr = [1,2,3,4,5], h = 8
  * Output: 3 

  * Example 2:
  * Input: arr = [1,2,5,9], h = 6
  * Output: 5
  * 
  * https://www.codingninjas.com/studio/problems/smallest-divisor-with-the-given-limit_1755882
*/
#include<iostream>

// * ------------------------- Utility Function -------------------------`
int findMaxInArray(std::vector<int> arr) {
  int maxVal = INT_MIN; 
  for(int i=0; i<arr.size(); i++) {
    maxVal = std::max(maxVal, arr[i]);
  }
  return maxVal;
}

bool isValidDivisior(std::vector<int>arr, int threshold, int divisor) {
  int sum = 0;
  // std::cout<<"divisor "<<divisor<<std::endl;
  for(int i=0;i<arr.size();i++) {
    sum = sum + std::ceil(arr[i]/(float)divisor);
  }
  // std::cout<<"sum "<<sum<<std::endl;
  if(sum <= threshold) {
    return true;
  }
  return false;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(1-max) * O(N) [For Checking Divisor] 
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr, int threshold) {
  int maxArrVal = findMaxInArray(arr);
  for(int i=1; i<maxArrVal; i++) {
    bool isValid = isValidDivisior(arr, threshold, i);
    if(isValid) {
      return i;
    }
  }
  return -1;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY logn(1-max) * O(N) [For Checking Divisor] 
// * SPACE COMPLEXITY O(1)
int optimalApproach(std::vector<int> arr, int threshold) {
  int max_ele = findMaxInArray(arr);
  int min_divisor = INT_MAX;
  int low = 1, high = max_ele;
  while(low <= high) {
    int mid = low + (high - low)/2;
    bool isValid = isValidDivisior(arr, threshold, mid);
    if(isValid) {
      high = mid - 1;
    }
    else {
      low = mid+1;
    }
  }
  return low;
}

int main() {
  // std::vector<int> arr = {1,2,5,9};
  // int threshold = 6;
  std::vector<int> arr = { 8, 4, 2, 3 };
  int threshold = 10;
  // int minimum_divisor = bruteForce(arr, threshold);
  int minimum_divisor = optimalApproach(arr, threshold);
  std::cout<<"Smallest Divisor: "<<minimum_divisor<<std::endl;
  return 0;
}