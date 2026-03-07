/*
  * Leetcode - 1283
  * Smallest Divisor
  * 
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
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void printArr(vector<T> &nums) {
  int n = nums.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << nums[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

bool findIsPossibleDivisor(vector<int> &nums, int &threshold, int &divisor) {
  int divisor_sum = 0;
  for(auto &x: nums) {
    divisor_sum += ceil((float)x / (float)(divisor));
    if (divisor_sum >= threshold)
      break;
  }
  // cout << "divisor " << divisor << " | " << "divisor_sum " << divisor_sum << endl;
  return divisor_sum <= threshold;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(Max) * O(N) 
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> arr, int threshold) {
  int n = arr.size();
  // * O(Max)
  int maxEle = *max_element(arr.begin(), arr.end());
  int start = 1, end = maxEle;
  for (int i = start; i <= end; i++) {
    // * O(N)
    bool isPossibleDivisor = findIsPossibleDivisor(arr, threshold, i);
    if (isPossibleDivisor)
      return i;
  }
  return -1;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(log(Max)) * O(N) 
// * SPACE COMPLEXITY O(1)
int findSmallestDivisor(vector<int> arr, int threshold) {
  int l = 1, r = *max_element(arr.begin(), arr.end());;
  // * O(log(Max))
  while (l <= r) {
    int m = l + (r - l) / 2;
    // * O(N)
    if (findIsPossibleDivisor(arr, threshold, m)) {
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
  int threshold = 8;
  vector<int> arr = {1, 2, 3, 4, 5};

  // * testcase 2
  // int threshold = 6;
  // vector<int> arr = {1, 2, 5, 9};

  cout << "Threshold " << threshold << endl;
  std::cout << "Input nums: ";
  printArr(arr);

  // int smallestDivisor = bruteForce(arr, threshold);
  int smallestDivisor = findSmallestDivisor(arr, threshold);
  cout << "The smallest divisor is " << smallestDivisor << endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 13-smallest-divisor.cpp -o output && ./output