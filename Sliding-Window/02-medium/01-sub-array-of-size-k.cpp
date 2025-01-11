/**
 * * Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 * * Given an array of integers arr and two integers 'k' and 'threshold', return the number of 
 * * sub-arrays of size 'k' and average greater than or equal to 'threshold'.
 * 
 * * Example 1
 * * Input  : nums = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
 * * Output : 3
 * * Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively.

 * * Example 2
 * * Input  : nums = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
 * * Output : 6

 * * https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/
*/

#include <map>
#include <vector>
#include <iostream>
#include <unordered_set>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1A: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> &arr, int &k, int &threshold) {
  int n = arr.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int sum = 0, c = 0;
    // * Loop only i to i + 3 places [our window]
    for (int j = i; (j < i + k) && (i + k <= n); ++j) {
      sum += arr[j];
      c++;
    }
    // std::cout << c << " " << sum << " " << sum / k << std::endl;
    if(c == k) {
      int avg = sum / k;
      if(avg >= threshold)
        ans++;
    }
  }
  return ans;
}

// * ------------------------- APPROACH 1B: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int bruteForce2(std::vector<int> &arr, int k, int threshold) {
  int n = arr.size();
  int ans = 0;
  long long cur_sum = 0;
  for(int i = 0; i < n; ++i) {
    cur_sum += arr[i];
    // * window < k
    if(i < k - 1) 
      continue;

    // * Shrink the window
    if(i > k - 1) 
      cur_sum -= arr[i - k];

    if (cur_sum / k >= threshold)
      ans++;
  }
  return ans;
}

// * ------------------------- APPROACH 2A: Optimal Approach -------------------------`
// * Classic Sliding Window
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int numOfSubarrays1(std::vector<int> &arr, int k, int threshold) {
  int n = arr.size();
  int ans = 0, i = 0, j = 0;
  long long sum = 0;
  while(j < n) {
    // * check the window execeeds
    if(j - i + 1 > k) {
      sum -= arr[i];
      i++;
    }

    sum += arr[j];

    // * Check if window sum >= threshold
    if (j - i + 1 == k) {
      int avg = sum / k;
      if(avg >= threshold)
        ans++;
    }
    j++;
  }
  return ans;
}

// * ------------------------- APPROACH 2A: Optimal Approach -------------------------`
// * Classic Sliding Window
// * Sliding Window Approach 2
// * For threshold average the sum of subarray must be >= (k * threshold)
// * If avg of size 'k' array is 'threshold'
// * then sum_of_k >= (k * threshold)
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int numOfSubarrays(std::vector<int> &arr, int &k, int &threshold) {
  int n = arr.size(); 
  int sum = 0, ans = 0;
  int target = k * threshold;

  for (int i = 0; i < n; ++i) {
    sum += arr[i];

    // * add elements till 'k'
    if (i < k - 1)
      continue;

    // * Remove the start ele
    if (i > k - 1)
      sum -= arr[i - k];

    // * Avg >= threshold
    if(sum >= target)
      ans++;
    std::cout << sum << std::endl;
  }

  return ans;
}

int main() {
  // * testcase 1
  int k = 3, threshold = 4;
  std::vector<int> arr = {2, 2, 2, 2, 5, 5, 5, 8};
  // * testcase 1
  // int k = 3, threshold = 5;
  // std::vector<int> arr = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
  std::cout << "k = " << k << " & threshold = " << threshold << std::endl;
  std::cout << "Input Array " << std::endl;
  printArr(arr);
  // int ans = bruteForce(arr, k, threshold);
  int ans = numOfSubarrays(arr, k, threshold);
  std::cout << "Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold " << ans << std::endl;
  return 0;
}

// * run the code
// * $CXX --std=c++20 01-sub-array-of-size-k.cpp -o output && ./output