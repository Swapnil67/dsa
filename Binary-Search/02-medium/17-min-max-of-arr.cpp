/**
 * * Leetcode - 2439
 * * Minimize Maximum of Array
 * * You are given a 0-indexed array nums comprising of n non-negative integers.
 * * In one operation, you must:
 * 
 * * Choose an integer i such that 1 <= i < n and nums[i] > 0.
 * * - Decrease nums[i] by 1.
 * * - Increase nums[i - 1] by 1.
 * *  Return the minimum possible value of the maximum integer of nums after performing any number of operations.
 * 
 * * Example 1:
 * * Input       : nums = [3,7,1,6]
 * * Output      : 5
 * * Explanation : 
 * * One set of optimal operations is as follows:
 * * - Choose i = 1, and nums becomes [4,6,1,6].
 * * - Choose i = 3, and nums becomes [4,6,2,5].
 * * - Choose i = 1, and nums becomes [5,5,2,5].
 
 * * https://leetcode.com/problems/minimize-maximum-of-array/description/
 */

#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

bool isValid(std::vector<int> arr, int maxVal) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    if (arr[i] > maxVal)
      return false;

    // * how much we need to subtract to arr[i+1] element if we make arr[i] to maxVal
    long long buffer = maxVal - arr[i];
    arr[i + 1] = arr[i + 1] - buffer; // * subtract the buffer to arr[i+1]
  }

  return arr[n - 1] <= maxVal;
}

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1)
int minimizeArrayValue(std::vector<int> arr) {
  int n = arr.size();
  int l = 0, r = *std::max_element(arr.begin(), arr.end());
  int ans = 0;
  while(l <= r) {
    int m = l + (r - l) / 2;
    if (isValid(arr, m)) {
      ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }

  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Goal is to evenly distribute the value
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int minimizeArrayValue2(std::vector<int> arr) {
  int n = arr.size();
  long long sum = 0;
  int res = -1;
  for (int i = 0; i < n; ++i) {
    sum += arr[i];
    int cur = std::ceil((float)sum / (float)(i + 1)); // * Get the avg no.
    res = std::max(res, cur);
    std::cout << sum << " " << cur  << std::endl;
  }
  return res;
}


int main(void) {
  // * testcase 1
  // std::vector<int> arr = {3, 7, 1, 6};

  // * testcase 2
  // std::vector<int> arr = {10, 1};

  // * testcase 3
  std::vector<int> arr = {13, 13, 20, 0, 8, 9, 9};

  printArr(arr);

  // int ans = minimizeArrayValue(arr);
  int ans = minimizeArrayValue2(arr);
  std::cout << "Minimize Maximum of Array " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 17-min-max-of-arr.cpp -o output && ./output

// * DRY RUN

// * We are doing following two operations (simultaneously) on every pass
// * arr[i] = arr[i] - 1              - (i > 1 && i < n)
// * arr[i - 1] = arr[i - 1] + 1          

// * i = 0
// * 3 7 1 6
// * 4 6

// * i = 1
// * 4 6 1 6
// * 5 5

// * i = 2
// * 5 5 1 6
// *     5 2

// * i = 3
// * 5 5 5 2


// * For i = 5 till i < n - 1

// * i = 0
// * 3 7 1 6
// * 2 5

// * i = 1
// * 4 6 1 6
// * 2 5 

// * i = 2
// * 4 6 1 6
// * 2 5 5 2

// * Max ele = 5