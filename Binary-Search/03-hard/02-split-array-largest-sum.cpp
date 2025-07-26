/*
* Leetcode - 410
* Split Array Largest Sum
* Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
* Return the minimized largest sum of the split.

* Example 1:
* Input: nums = [7,2,5,10,8], k = 2
* Output: 18
* Explanation: There are four ways to split nums into two subarrays.
* The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

* https://leetcode.com/problems/split-array-largest-sum/
* https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557
*/

#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

// * ------------------------- Utility Functions -------------------------`

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

int isValidPartition(std::vector<int> arr, int maxSum, int k) {
  int n = arr.size();
  long long curSum = 0;
  int splits = 1;
  for (int i = 0; i < n; i++) {
    if (curSum + arr[i] <= maxSum) {
      curSum += arr[i];
    } else {
      splits++;
      curSum = arr[i];
    }
  }
  return splits <= k;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(log(total - max)) * O(N) 
// * SPACE COMPLEXITY O(1)
int splitArray(std::vector<int> a, int k) {
  int n = a.size();
  int l = *std::max_element(a.begin(), a.end());
  int r = accumulate(a.begin(), a.end(), 0);

  while (l <= r) {
    int m = l + (r - l) / 2;
    if (isValidPartition(a, m, k)) {
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return l;
}

int main() {
  std::cout << "Split Array Largest Sum" << std::endl;
  // int k = 2;
  // std::vector<int> arr = {7, 2, 5, 10, 8};

  int k = 3;
  std::vector<int> arr = {1, 4, 4};
  printArr(arr);
  int ans = splitArray(arr, k);
  std::cout << "Largest minimum sum is " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 02-split-array-largest-sum.cpp -o output && ./output