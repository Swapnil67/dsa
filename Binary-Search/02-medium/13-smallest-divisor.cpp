/*
  * Leetcode - 1283
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

#include <vector>
#include <math.h>
#include <climits>
#include <iostream>
#include <algorithm>

// * ------------------------- Utility Functions -------------------------`

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

bool findIsPossibleDivisor(std::vector<int> &arr, int &threshold, int &divisor) {
  int divisorSum = 0;
  for (int i = 0; i < arr.size(); i++) {
    divisorSum = divisorSum + std::ceil(arr[i] / (divisor * 1.0));
  }
  // std::cout << "divisor " << divisor << " | " << "divisorSum " << divisorSum << std::endl;
  return divisorSum <= threshold;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(Max) * O(N) 
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr, int threshold) {
  int n = arr.size();
  // * O(Max)
  int maxEle = *std::max_element(arr.begin(), arr.end());
  int start = 1, end = maxEle;
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
  int maxEle = *std::max_element(arr.begin(), arr.end());
  int l = 1, r = maxEle;
  // * O(log(Max))
  while (l <= r) {
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
// * g++ --std=c++17 03-smallest-divisor.cpp -o output && ./output