/*
 * Print Maximum Subarray Sum
 * Find the sum of the subarray (including empty subarray) having 
 * maximum sum among all subarrays
 * 
 * Example 1:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: [3,6]
 * Explanation: The subarray [4,-1,2,1] has the largest sum 6.

 * Example 2:
 * Input: nums = [-3, -5, -6]
 * Output: [0]
 * Explanation: The subarray [-3, -5, -6] has the largest sum 0.
 * 
 * https://www.naukri.com/code360/problems/maximum-subarray-sum_628288
 * https://www.naukri.com/code360/problems/maximum-subarray-sum_630526
 * https://www.naukri.com/code360/problems/max-subarray-sum_873852
 * 
*/

#include<iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

std::vector<int> maxSubArray(std::vector<int> arr) {
  int n = arr.size();
  int maxSum = INT_MIN, sum = 0;
  int start = 0, ansStart = -1, ansEnd = -1;
  for (int i = 0; i < n; i++) {
    if(sum == 0) {
      start = i;
    }
    sum += arr[i];
    if(sum > maxSum) {
      maxSum = sum;
      ansStart = start, ansEnd = i;
    }

    if(sum < 0) sum = 0;
  }
  return {ansStart, ansEnd};
}

int main() {
  // * testcase 1
  // std::vector<int> arr = {-3, -5, -6}; // * [0,0]
  // * testcase 2
  std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // * [3,6]
  
  std::vector<int> ans = maxSubArray(arr);
  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++17 04-print-max-subarray-sum.cpp -o 04-print-max-subarray-sum && ./04-print-max-subarray-sum