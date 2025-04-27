#include <vector>
#include <deque>
#include <iostream>
#include <numeric>
#include <climits>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * 02 - med
// int subarraySum(std::vector<int> arr, int k) {    
// TODO
// }

// * 03 - med
// std::vector<int> firstNegative(std::vector<int> arr, int k) {
// TODO
// }

// * 04 - med
// int longestOnes(std::vector<int> arr, int k) {
// TODO
// }

// * 05 - med
// int totalFruit(std::vector<int> fruits) {
// TODO  
// }

// * 06 - med
// int maxFrequency(std::vector<int> arr, int k) {
// TODO 
// }

// * 07 - med
// int minSubArrayLen(std::vector<int> arr, int target) {
// TODO 
// }

// * 08 - med
// std::vector<int> findClosestElements(std::vector<int> arr, int k, int x) {
// TODO
// }

// * 09A - med
// int minOperations(std::vector<int> arr, int x) {
// TODO
// }

// * 09B - med
// int minOperations2(std::vector<int> arr, int x) {
// TODO
// }

// * 10 - med
// int numSubarraysWithSum(std::vector<int> arr, int goal) {
// TODO
// }

// * 11 - med
// int numSubarrayProductLessThanK(std::vector<int> arr, int k) {
// TODO
// }

// * 12 - med
// int numSubarrayProductLessThanK(std::vector<int> arr, int k) {
// TODO
// }

// int maxSubarrayLength(std::vector<int> arr, int k) {
// TODO
// }

int getMax(std::vector<int> &arr) {
  int max_ele = INT_MIN;
  for(int i = 0; i < arr.size(); ++i) {
    max_ele = std::max(max_ele, arr[i]);
  }
  return max_ele;
}

int countSubarrays(std::vector<int> arr, int k) {
  int n = arr.size(), ans = 0;
  return ans;
}

int main() {
  // * testcase 1
  int k = 2;
  std::vector<int> arr = {1, 3, 2, 3, 3};

  // * testcase 1
  // int k = 2;
  // std::vector<int> arr = {1, 3, 2, 5, 1, 5};

  // * testcase 2
  // int k = 3;
  // std::vector<int> arr = {1, 4, 2, 1};

  // * testcase 3
  // int k = 4;
  // std::vector<int> arr = {5, 5, 5, 5, 5, 5, 5};

  printf("Appear at least: %d\n", k);
  printf("Input Array\n");
  printArr(arr);  

  int ans = countSubarrays(arr, k);
  // int ans = countSubarrays2(arr, k);
  printf("Length of Longest Subarray With at Most %d Frequency is %d\n", k, ans);
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output