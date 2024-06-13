/*
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
*/

#include<iostream>

int maxCircularSubarraySum(std::vector<int> arr) {
  int n = arr.size();
  int curMax = 0, curMin = 0;
  int globalMax = arr[0], globalMin = arr[0];
  int total = 0;
  for(int i=0; i<n; i++) {
    curMax = std::max(curMax + arr[i], arr[i]);
    curMin = std::min(curMin + arr[i], arr[i]);
    total += arr[i];
    globalMax = std::max(globalMax, curMax);
    globalMin = std::min(globalMin, curMin);
  }

  if(globalMax < 0) {
    // * All the elements in array is negative
    return globalMax;
  }
  else 
    return std::max(globalMax, (total-globalMin));
}

int main() {
  // * testcase 1
  // std::vector<int> arr = { 5, -1, 5 };
  // * testcase 2
  std::vector<int> arr = { -3, -2, -3 };
  int maxSum = maxCircularSubarraySum(arr);
  std::cout<<"Maximum circular subarray sum: "<<maxSum<<std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++17 05-circular-subarray-sum.cpp -o 05-circular-subarray-sum && ./05-circular-subarray-sum
