/**
 * * Max Sum Subarray of size K
 * * Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.
 * 
 * * Example 1
 * * Input  : nums = [100, 200, 300, 400], k = 2
 * * Output : 700

 * * Example 2
 * * Input  : nums = [100, 200, 300, 400], k = 4
 * * Output : 1000

 * * Example 3
 * * Input  : nums = [100, 200, 300, 400], k = 1
 * * Output : 400

 * * https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
*/

#include <iostream>
void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}


int maxSumOfKSubarray(std::vector<int> arr, int window_size) {
  int n = arr.size();
  int i = 0, j = 0;
  long long max_sum = 0, cur_sum = 0;
  while(j < n) {
    // * Check if window size exceeded
    if(j - i + 1 > window_size) {
      cur_sum -= arr[i];
      i++;
    }
    cur_sum += arr[j];
    // * Calculate max_sum for window
    if (j - i + 1 == window_size) {
      max_sum = std::max(max_sum, cur_sum);
    }
    j++;
  }
  return max_sum;
}

int main() {
  int k = 2;
  std::vector<int> arr = {100, 200, 300, 400};
  // int k = 3;
  // std::vector<int> arr = {1, 2, 3, 5, 6, 7};
  std::cout << "k " << k << std::endl;
  std::cout << "Input Array " << std::endl;
  printArr(arr);
  int ans = maxSumOfKSubarray(arr, k);
  std::cout << "Maximum sum of subarray with " << k << " is " << ans << std::endl;
  return 0;
}

// * g++ --std=c++17 02-max-sum-subarray-of-size-k.cpp -o output && ./output