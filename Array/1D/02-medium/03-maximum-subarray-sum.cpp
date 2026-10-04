/*
 * Leetcode - 53
 * Maximum Subarray Sum
 * 
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
 * https://leetcode.com/problems/maximum-subarray/description/
 * https://www.naukri.com/code360/problems/maximum-subarray-sum_628288
 * https://www.naukri.com/code360/problems/maximum-subarray-sum_630526
 * https://www.naukri.com/code360/problems/max-subarray-sum_873852
 * https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
*/

// ! Amazon, Google, Meta, Microsoft, Uber, Adobe, Paypal, Oracld

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> arr) {
  int n = arr.size();
  int max_sum = INT_MIN;
  for (int i = 0; i < n; i++) {
    int sum = arr[i];
    for (int j = i + 1; j < n; j++) {
      sum += arr[j];
      max_sum = max(max_sum, sum);
    }
  }

  return max_sum < 0 ? 0 : max_sum;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * kadane's Algorithm
// * Only take positive sum forward
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxSubArray(vector<int>arr) {
  int n = arr.size();
  int max_sum = INT_MIN, sum = 0;
  for (int i = 0; i < n; i++) {
    sum = max(sum + arr[i], arr[i]);
    max_sum = max(max_sum, sum);
  }
  return max_sum;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
vector<int> maxSubArray2(vector<int> arr) {
  int n = arr.size();
  int max_sum = INT_MIN, sum = 0;
  int start = 0, ans_start = -1, ans_end = -1;

  for (int i = 0; i < n; i++) {
    if (sum == 0)
      start = i;
    
    sum += arr[i];
    if (sum > max_sum) {
      max_sum = sum;
      ans_start = start, ans_end = i;
    }

    if (sum < 0) sum = 0;
  }

  return {ans_start, ans_end};
}

int main() {
  // * testcase 1
  // vector<int> nums = {-3, -5, -6}; // * -3
  
  // * testcase 2
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // * 6
  cout << "Input Array: ";
  printArr(nums);

  // int max_sum = bruteForce(nums);
  int max_sum = maxSubArray(nums);
  cout << "Maximum subarray sum: " << max_sum << endl;

  vector<int> ans = maxSubArray2(nums);
  cout << "Subarray Index Range: ";
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-maximum-subarray-sum.cpp -o output && ./output