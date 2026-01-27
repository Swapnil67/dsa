/**
 * * Leetcode - 209
 * * Minimum Size Subarray Sum
 * * Given an array of positive integers nums and a positive integer target, return the minimal length of a 
 * * subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
 * 
 * * Example 1
 * * Input  : target = 7, nums = [2, 3, 1, 2, 4, 3]
 * * Output : 2
 * * Explanation: The subarray [4,3] has the minimal length under the problem constraint.
 * 
 * * Example 2
 * * Input  : target = 4, nums = [1, 4, 4]
 * * Output : 1
 * * Explanation: The subarray [4] has the minimal length under the problem constraint.
 * 
 * * Example 3
 * * Input  : target = 11, nums = [1, 1, 1, 1, 1, 1, 1, 1]
 * * Output : 0
 * * Explanation: No Subarray of size target found
 * 
 * * https://leetcode.com/problems/minimum-size-subarray-sum/description/
*/

#include <vector>
#include <climits>
#include <iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Check all k size windows with k zeros
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr, int target) {
  int ans = INT_MAX;
  int n = arr.size();
  for(int i = 0; i < n; ++i) {
    int curSum = 0;
    int j = i;
    for(; j < n; ++j) {
      curSum += arr[j];
      // * break if we found the subarray
      if (curSum >= target)
        break;
    }
    // std::cout << curSum << std::endl;
    if (curSum >= target)
      ans = std::min(ans, j - i + 1);
  }
  return ans == INT_MAX ? 0 : ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Classic Sliding Window
// * Find the curSum
// * Then find the window while(curSum >= target)
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int minSubArrayLen(std::vector<int> arr, int target) {
  int n = arr.size();
  int ans = INT_MAX, sum = 0;
  int i = 0, j = 0;
  while (j < n) {
    sum += arr[j];

    // * While sum >= target shrink window and store new subarray size
    while (i < j && sum >= target) {
      // * Shrink the window
      ans = std::min(ans, j - i + 1);
      sum -= arr[i];
      i++;
    }

    j++;
  }
  return ans == INT_MAX ? 0 : ans;
}


int main() {
  // * testcase 1
  // int target = 7;
  // std::vector<int> arr = {2, 3, 1, 2, 4, 3};

  // * testcase 2
  int target = 11;
  std::vector<int> arr = {1, 1, 1, 1, 1, 1, 1, 1};

  // * testcase 3
  // int target = 4;
  // std::vector<int> arr = {1, 4, 4};

  std::cout<<"Input Array: ";
  printArr(arr);
  std::cout << "Target Sum: " << target << std::endl;

  // int ans = bruteForce(arr, target);
  int ans = minSubArrayLen(arr, target);
  std::cout << "Minimum Size Subarray Sum: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 07-min-size-subarray-sum.cpp -o output && ./output