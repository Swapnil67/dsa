#include <math.h>
#include <climits>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * 00 - Search In Rotated Sorted Array (Without duplicates)
// int findInRotatedSortedArray(std::vector<int> arr, int target) {
// TODO
// }

// * 01 - Search In Rotated Sorted Array - II (With duplicates)
// int searchInRotatedSorted(std::vector<int> arr, int target) {
// TODO
// }

// * 02 - Find Minimum in Rotated Sorted Array
// int findMinimum(std::vector<int> arr) {
// TODO
// }

// * 03 - Count of rotation
// int findKRotation(std::vector<int> arr) {
// TODO
// }

// * 04 - Single element in a Sorted Array
// int singleNonDuplicate(std::vector<int> arr) {
// TODO
// }

// * 05 - Find Peak Element
// int findPeakElement(std::vector<int> arr) {
// TODO
// }

// * 06 - Nth Root of a number
// int findNthRoot(int n, int m) {
// TODO
// }

// * 09 - Koko eating bananas
// int findMinimumBananasToEat(std::vector<int> piles, int h) {
// TODO
// }

// * 10 - Capacity To Ship Packages Within D Days
// int findLeastPossileWeight(std::vector<int> weights, int days) {
// TODO
// }

// * 11 - Maximum Candies Allocated to K Children
// int maximumCandies(std::vector<int> candies, int k) {
// TODO
// }

// * 12 - Rose Garden
// int minDays(std::vector<int> bloomDay, int flowersInAbouquet, int m) {
// TODO
// }

bool isValidDivisor(std::vector<int> arr, int divisor, int threshold) {
  int n = arr.size();
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += std::ceil((arr[i] / (divisor * 1.0)));
  }
  return sum <= threshold;
}

// * 13 - Smallest Divisor
int findSmallestDivisor(std::vector<int> arr, int threshold) {
  int maxEle = *std::max_element(arr.begin(), arr.end());
  int l = 0, r = maxEle;
  int ans = 0;
  while (l <= r) {
    int divisor = l + (r - l) / 2;
    if(isValidDivisor(arr, divisor, threshold)) {
      ans = divisor;
      r = divisor - 1;
    }
    else {
      l = divisor + 1;
    }
  }

  return ans;
} 

int main() {
  // * testcase 1
  // int threshold = 6;
  // std::vector<int> arr = {1, 2, 5, 9};

  // * testcase 2
  int threshold = 11000000;
  std::vector<int> arr = {21212, 10101, 12121};
  printArr(arr);

  int smallestDivisor = findSmallestDivisor(arr, threshold);
  std::cout << "The smallest divisor is " << smallestDivisor << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

