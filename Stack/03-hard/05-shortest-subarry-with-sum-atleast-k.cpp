/*
 * Leetcode - 862
 * Shortest Subarray with Sum at Least K
 * 
 * Given an integer array nums and an integer k, return the length of the shortest non-empty
 * subarray of nums with a sum of at least k. If there is no such subarray, return -1.

 * Example 1
 * * Input       : nums = [1], k = 1
 * * Output      : 1

 * Example 2
 * * Input       : nums = [1,2], k = 4
 * * Output      : -1

 * Example 3
 * * Input       : nums = [2,-1,2], k = 3
 * * Output      : 3
 * 
 * https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/
*/

#include <deque>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

void printArr(vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * ------------------------- APPROACH 1: Brute Force -------------------------
// * Nexted Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr, int k) {
  int n = arr.size();
  int ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int cur_sum = 0;
    for (int j = i; j < n; ++j) {
      cur_sum += arr[j];
      if(cur_sum >= k) {
        ans = std::min((j - i + 1), ans);
        break;
      }
    }
  }
  return ans == INT_MAX ? -1 : ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * Sliding Window + Monotonic Stack
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
int shortestSubarray(std::vector<int>& nums, int k) {
  int n = nums.size();

  int j = 0;
  int curSum = 0;
  int ans = INT_MAX;

  // * monotonic increasing 
  std::deque<int> dq;
  std::vector<long long> prefixSums(n, 0);

  while (j < n) {
    // * keep calculating the prefix array
    if(j == 0) {
      prefixSums[j] = nums[j];
    } else {
      prefixSums[j] = prefixSums[j - 1] + nums[j];
    }

    if (prefixSums[j] >= k) {
      ans = std::min(ans, j + 1);
    }

    // * shrink the window
    // * Check if subracting from dq front elements will keep the following true
    // * prefix_sum >= k
    while (!dq.empty() && prefixSums[j] - prefixSums[dq.front()] >= k) {
      ans = std::min(ans, j - dq.front());
      dq.pop_front();
    }

    // * Maintain monotonicity by removing indices with larger prefix sums
    // * strictly increasing
    while (!dq.empty() && prefixSums[dq.back()] >= prefixSums[j]) {
      dq.pop_back();
    }
    dq.push_back(j);

    j++;
  }

  return ans == INT_MAX ? -1 : ans;
}

int main() {
  // * testcase 1
  // int k = 3;
  // std::vector<int> nums = {2, -1, 2};

  // * testcase 2
  // int k = 4;
  // std::vector<int> nums = {1, 2};
  
  // * testcase 3
  int k = 167;
  std::vector<int> nums = {84, -37, 32, 40, 95};


  // int ans = bruteForce(nums, k);
  int ans = shortestSubarray(nums, k);
  std::cout << "Shortest Subarray with Sum at Least K is " << ans << std::endl;

  return 0;
}

// * run the code
// * g++ --std=c++17 05-shortest-subarry-with-sum-atleast-k.cpp -o output && ./output
