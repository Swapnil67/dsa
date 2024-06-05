/*
  * Smallest Divisor
  * You are given an array of integers 'arr' and an integer 'limit'.
  * Your task is to find the smallest positive integer divisor, such that upon dividing all the elements
  * of the given array by it, the sum of the division's result is less than or equal to the given integer's limit
  * 
  * Example 1:
  * Input: arr = [1,2,3,4,5], threshold = 8
  * Output: 3 

  * Example 2:
  * Input: arr = [1,2,5,9], threshold = 6
  * Output: 5
  * 
  * https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
  * https://www.naukri.com/code360/problems/smallest-divisor-with-the-given-limit_1755882
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

int findMaxEle(std::vector<int> arr) {
  int n = arr.size();
  int maxEle = INT_MIN;
  for(int i=0; i<n; i++) {
    maxEle = std::max(maxEle, arr[i]);
  }
  return maxEle;
}

bool findIsPossibleDivisor(std::vector<int> arr, int threshold, int divisor) {
  int divisorSum = 0;
  for(int i=0; i<arr.size(); i++) {
    divisorSum = divisorSum + std::ceil((float)arr[i]/(float)divisor);
  }
  // std::cout << "divisor " << divisor << std::endl;
  // std::cout << "divisorSum " << divisorSum << std::endl;
  if(divisorSum <= threshold) return true;
  return false;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(Max) * O(N) 
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr, int threshold) {
  int n = arr.size();
  // * O(Max)
  int start = 1, end = findMaxEle(arr);
  for (int i = start; i <= end; i++) {
    // * O(N)
    bool isPossibleDivisor = findIsPossibleDivisor(arr, threshold, i);
    if(isPossibleDivisor) return i;
  }
  return -1;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(log(Max)) * O(N) 
// * SPACE COMPLEXITY O(1)
int findSmallestDivisor(std::vector<int> arr, int threshold) {
  int l = 1, r = findMaxEle(arr);
  // * O(log(Max))
  while(l <= r) {
    int m = l + (r - l) / 2;
    // * O(N)
    bool isPossibleDivisor = findIsPossibleDivisor(arr, threshold, m);
    if(isPossibleDivisor) {
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return l;
}

int main() {
  // * testcase 1
  // std::vector<int> arr = {1, 2, 3, 4, 5};
  // int threshold = 8;

  // * testcase 2
  std::vector<int> arr = {1, 2, 5, 9};
  int threshold = 6;

  printArr(arr);

  // int smallestDivisor = bruteForce(arr, threshold);
  int smallestDivisor = findSmallestDivisor(arr, threshold);
  std::cout << "The smallest divisor is " << smallestDivisor << std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++17 03-smallest-divisor.cpp -o 03-smallest-divisor && ./03-smallest-divisor