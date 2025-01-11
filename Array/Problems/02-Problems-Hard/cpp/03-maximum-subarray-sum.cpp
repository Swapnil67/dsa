/*
 * Maximum Subarray Sum
 * Find the sum of the subarray (including empty subarray) having 
 * maximum sum among all subarrays
 * 
 * Example 1:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: The subarray [4,-1,2,1] has the largest sum 6.

 * Example 2:
 * Input: nums = [-3, -5, -6]
 * Output: 0
 * Explanation: The subarray [-3, -5, -6] has the largest sum 0.
 * 
 * https://www.naukri.com/code360/problems/maximum-subarray-sum_628288
 * https://www.naukri.com/code360/problems/maximum-subarray-sum_630526
 * https://www.naukri.com/code360/problems/max-subarray-sum_873852
*/

#include<iostream>
#include<vector>
#include<climits>

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr) {
  int n = arr.size();
  int maxSum = INT_MIN;
  for (int i = 0; i < n; i++) {
    int sum = arr[i];
    for (int j = i + 1; j < n; j++) {
      sum += arr[j];
      maxSum = std::max(maxSum, sum);
    }
  }
  if(maxSum < 0) return 0;
  return maxSum;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * kadane's Algorithm
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxSubArray(std::vector<int>arr) {
  int n = arr.size();
  int maxSum = INT_MIN, sum = 0;
  for (int i = 0; i < n; i++) {
    sum = std::max(sum + arr[i], arr[i]);
    maxSum = std::max(maxSum, sum);
  }
  // * OR
  // for(int i=0; i<n; i++) {
  //   sum = sum + arr[i];
  //   maxSum = std::max(maxSum, sum);
  //   if(sum < 0) {
  //     sum = 0;
  //   }
  // }
  return maxSum;
}


int main() {
  // * testcase 1
  // std::vector<int> arr = {-3, -5, -6}; // * -3
  // * testcase 2
  std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // * 6

  // int maxSum = bruteForce(arr);
  int maxSum = maxSubArray(arr);
  std::cout<<"Maximum subarray sum: "<<maxSum<<std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 03-maximum-subarray-sum.cpp -o 03-maximum-subarray-sum && ./03-maximum-subarray-sum