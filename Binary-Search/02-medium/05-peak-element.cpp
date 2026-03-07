/*
 * Leetcode - 162
 * Find Peak Element
 * A peak element is an element that is strictly greater than its neighbors.
 * 
 * Example 1:
 * Input: nums = [1, 2, 3, 1]
 * Output: 3
 * Explanation: Index 2 is peak element

 * Example 1:
 * Input: nums = [1, 2, 1, 3, 5, 6]
 * Output: 1 or 5
 * Explanation: Index 1 or 5 are peak elements

 * https://leetcode.com/problems/find-peak-element/description/
 * https://leetcode.com/problems/peak-index-in-a-mountain-array
 * https://www.naukri.com/code360/problems/find-peak-element_1081482
*/

#include <vector>
#include <iostream>

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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Linear search
int bruteForce(vector<int> nums) {
  int n = nums.size();
  int peakEle;
  for (int i = 0; i < n; i++) {
    if ((i == 0 || nums[i] > nums[i - 1]) && (i == n || nums[i] > nums[i + 1])) {
      peakEle = nums[i];
      break;
    }
  }
  return peakEle;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(logN)
// * SPACE COMPLEXITY O(1)
int findPeakElement(vector<int> nums) {
  int n = nums.size();

  // * Array with only one element
  if(n == 1)
    return nums[0];
  if (nums[0] > nums[1])
    return nums[0];
  if (nums[n - 1] > nums[n - 2])
    return nums[n - 1];

  int l = 1, r = n - 2; // * '0' & 'n-1' handled above
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1]) {
      return nums[m];
    }

    // * Increasing curve
    if (nums[m] > nums[m - 1]) {
      l = m + 1;
    } else {
      // * Decreasing curve
      r = m - 1;
    }
  }
  return -1;
}

int main(void) {
  // * testcase 1
  vector<int> nums = {1, 10, 13, 7, 6, 5, 4, 2, 1, 0};

  // * testcase 2
  // vector<int> nums = {5, 4, 3, 2, 1};

  // * testcase 3
  // vector<int> nums = {1, 2, 3, 4, 5};

  // * testcase 4
  // vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};

  cout << "Input nums: ";
  printArr(nums);

  // int peakEle = bruteForce(nums);
  int peakEle = findPeakElement(nums);
  cout << "Peak Element: " << peakEle << endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 05-peak-element.cpp -o output && ./output

