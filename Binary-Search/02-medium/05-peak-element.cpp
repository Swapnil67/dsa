/*
 * Leetcode - 162
 * Find Peak Element
 * A peak element is an element that is strictly greater than its neighbors.
 * 
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: Index 2 is peak element

 * Example 1:
 * Input: nums = [1,2,1,3,5,6,]
 * Output: 1 or 5
 * Explanation: Index 1 or 5 are peak elements

 * https://leetcode.com/problems/find-peak-element/description/
 * https://www.naukri.com/code360/problems/find-peak-element_1081482
*/

#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Linear search
int bruteForce(std::vector<int> arr) {
  int n = arr.size();
  int peakEle;
  for (int i = 0; i < n; i++) {
    if ((i == 0 || arr[i] > arr[i - 1]) && (i == n || arr[i] > arr[i + 1])) {
      peakEle = arr[i];
      break;
    }
  }
  return peakEle;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(logN)
// * SPACE COMPLEXITY O(1)
int findPeakElement(std::vector<int> arr) {
  int n = arr.size();

  // * Array with only one element
  if(n == 1)
    return arr[0];
  if (arr[0] > arr[1])
    return arr[0];
  if (arr[n - 1] > arr[n - 2])
    return arr[n - 1];

  int l = 1, r = n - 2; // * '0' & 'n-1' handled above
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] > arr[m - 1] && arr[m] > arr[m + 1]) {
      return arr[m];
    }

    // * Increasing curve
    if (arr[m] > arr[m - 1]) {
      l = m + 1;
    } else {
      // * Decreasing curve
      r = m - 1;
    }
  }
  return -1;
}

int main() {
  // * testcase 1
  // std::vector<int> arr = {1, 2, 3, 4, 5};
  // * testcase 2
  // std::vector<int> arr = {5, 4, 3, 2, 1};
  // * testcase 3
  // std::vector<int> arr = {1, 10, 13, 7, 6, 5, 4, 2, 1, 0};
  // * testcase 4
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
  printArr(arr);
  int peakEle = bruteForce(arr);
  // int peakEle = findPeakElement(arr);
  std::cout << "Peak Element " << peakEle << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 05-peak-element.cpp -o 05-peak-element && ./05-peak-element

