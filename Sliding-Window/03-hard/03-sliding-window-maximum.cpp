
/**
 * * Leetcode - 239
 * * Sliding Window Maximum
 * * You are given an array of integers nums, there is a sliding window of size k which is moving from the very left 
 * * of the array to the very right. You can only see the k numbers in the window. 
 * * Each time the sliding window moves right by one position.
 * 
 * * Return the max sliding window.

 * 
 * * Example 1
 * * Input  : nums = [1,3,-1,-3,5,3,6,7], k = 3
 * * Output : [3,3,5,5,6,7]
 * * Explanation:
 * * Window position                Max
 * * ---------------               -----
 * * [1  3  -1] -3  5  3  6  7      3
 * * 1 [3  -1  -3] 5  3  6  7       3
 * * 1  3 [-1  -3  5] 3  6  7       5
 * * 1  3  -1 [-3  5  3] 6  7       5
 * * 1  3  -1  -3 [5  3  6] 7       6
 * * 1  3  -1  -3  5 [3  6  7]      7

 * * https://leetcode.com/problems/sliding-window-maximum/description/
 * * https://www.naukri.com/code360/problems/sliding-window-maximum_980226
 * * https://www.naukri.com/code360/problems/maximum-of-all-subarrays-of-size-k_1170789 
*/

#include <vector>
#include <iostream>
#include <climits>
#include <deque>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Nested Loop for every N => k
// * TIME COMPLEXITY O(N * K)
// * SPACE COMPLEXITY O(1)
std::vector<int> bruteForce(std::vector<int> arr, int k) {
  int n = arr.size();
  std::vector<int> ans;
  for (int i = 0; i <= n - k; ++i) {
    int cur_max = INT_MIN;
    for (int j = i; j < i + k; ++j) {
      cur_max = std::max(cur_max, arr[j]);
    }
    if (cur_max != INT_MIN)
      ans.push_back(cur_max);
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Monotonic Deque
// * Put the largest element at front of deque
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
std::vector<int> maxSlidingWindow(std::vector<int> arr, int k) {
  int n = arr.size();
  std::deque<int> dq;
  int i = 0, j = 0;
  std::vector<int> ans;
  while (j < n) {
    // * Monotonic Decreasing Deque
    while (!dq.empty() && dq.back() < arr[j]) {
      dq.pop_back();
    }
    dq.push_back(arr[j]);

    // * Shrink the window
    if ((j - i + 1) > k) {
      // * Remove from the front of deque
      // * since we are using queue ds 'i' element might be at queue front
      if (arr[i] == dq.front())
        dq.pop_front();
      i++;
    }

    if ((j - i + 1) == k)
      ans.push_back(dq.front());

    j++;
  }

  return ans;
}

int main() {
  // * testcase 1
  // int k = 3;
  // std::vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};

  // * testcase 2
  // int k = 1;
  // std::vector<int> arr = {1};

  // * testcase 3
  // int k = 1;
  // std::vector<int> arr = {1, -1};

  // * testcase 4
  int k = 3;
  std::vector<int> arr = {1, 3, 1, 2, 0, 5};

  printf("k window size: %d\n", k);
  printf("Input Array\n");
  printArr(arr);  

  // std::vector<int> ans = bruteForce(arr, k);
  std::vector<int> ans = maxSlidingWindow(arr, k);
  printf("Sliding window maximum:\n");
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-sliding-window-maximum.cpp -o output && ./output