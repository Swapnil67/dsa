/*
 * Leetcode - 918
 * Maximum Sum Circular Subarray
 * Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums
 * 
 * Example 1:
 * Input: nums = [1,-2,3,-2]
 * Output: 3
 * Explanation: Subarray [3] has maximum sum 3.

 * Example 2:
 * Input: nums = [5,-3,5]
 * Output: 10
 * Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.

 * Example 3:
 * Input: nums = [-3,-2,-3]
 * Output: -2
 * Explanation: Subarray [-2] has maximum sum -2.
 * 
 * https://leetcode.com/problems/maximum-sum-circular-subarray/
 * https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1
 * https://www.naukri.com/code360/problems/maximum-sum-circular-subarray_1264302
*/

// ! Google, Meta, Amazon, Microsoft, Uber

#include <vector>
#include <climits>
#include <iostream>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

void rotateOneLeft(int &n, std::vector<int> &nums) {
  int first_ele = nums[0];
  for (int i = 1; i < n; ++i) {
    nums[i - 1] = nums[i];
  }
  nums[n - 1] = first_ele;
}

int kadanesAlgo(std::vector<int> &nums) {
  int n = nums.size();
  int max_sum = INT_MIN, cur_sum = 0;
  for (int i = 0; i < n; ++i) {
    cur_sum = std::max(cur_sum + nums[i], nums[i]);
    max_sum = std::max(max_sum, cur_sum);
  }
  return max_sum;
}

// * ------------------------- APPROACH 1: Brute Force APPROACH -------------------------`
// * Using Kadanes Algorithm
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr) {
  int n = arr.size();
  int max_sum = kadanesAlgo(arr);
  for (int i = 0; i < n; ++i) {
    rotateOneLeft(n, arr);
    max_sum = std::max(max_sum, kadanesAlgo(arr));
  }
  return max_sum;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Proof Contradiction
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxCircularSubarraySum(std::vector<int> &nums) {
  int n = nums.size();

  int total = 0, cur_max = 0, cur_min = 0;
  int global_max = nums[0], global_min = nums[0];
  for (int i = 0; i < n; i++) {
    total += nums[i];

    // * Max subarray sum
    cur_max = std::max(cur_max + nums[i], nums[i]);
    global_max = std::max(global_max, cur_max);

    // * Min subarray sum
    cur_min = std::min(cur_min + nums[i], nums[i]);
    global_min = std::min(global_min, cur_min);
  }

  // * All the elements in array is negative
  if (global_max < 0)
    return global_max;

  return std::max(global_max, (total - global_min));
}

int main() {
  // * testcase 1
  std::vector<int> arr = {5, -1, 5};

  // * testcase 2
  // std::vector<int> arr = {-3, -2, -3};

  std::cout << "Input Array: " << std::endl;
  printArr(arr);

  int maxSum = bruteForce(arr);
  // int maxSum = maxCircularSubarraySum(arr);
  std::cout << "Maximum circular subarray sum: " << maxSum << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 05-circular-subarray-sum.cpp -o output && ./output