/*
 * Leetcode - 1508
 * Range Sum of Sorted Subarray Sums
 * 
 * You are given the array nums consisting of n positive integers. 
 * You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, 
 * creating a new array of n * (n + 1) / 2 numbers.

 * Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. 
 * Since the answer can be a huge number return it modulo 109 + 7.

 * If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

 * Example 1
 * input  : nums = [1,2,3,4], n = 4, left = 1, right = 5
 * output : 13

 * Example 2
 * input  : nums = [1,2,3,4], n = 4, left = 3, right = 4
 * output : 6
 * 
 * https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/
*/

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

int bruteForce(std::vector<int>& nums, int n, int left, int right) {
  int m = nums.size();
  std::vector<int> sums;
  for (int i = 0; i < n; ++i) {
    int cur_sum = 0;
    for (int j = i; j < n; ++j) {
      cur_sum += nums[j];
      sums.push_back(cur_sum);
    }
  }
  
  std::sort(sums.begin(), sums.end());

  int ans = 0;
  for (int i = 0; i < sums.size(); ++i) {
    if ((i + 1) >= left && (i + 1) <= right) {
      // std::cout << sums[i] << std::endl;
      ans += sums[i];
    }
  }

  return ans;
}

int betterApproach(std::vector<int>& nums, int n, int left, int right) {
  int M = 1e9 + 7;
  std::vector<int> sums;
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  
  for (int i = 0; i < n; ++i) {
    int cur_sum = 0;
    for (int j = i; j < n; ++j) {
      cur_sum = ((cur_sum % M) + nums[j] % M) % M;
      min_heap.push(cur_sum);
    }
  }

  int ans = 0;
  int x = 1;

  while (!min_heap.empty()) {
    if (x >= left && x <= right) {
      ans += min_heap.top();
    }
    x++;
    min_heap.pop();
  }

  return ans;
}


// * ------------------------- Optimal Approach -------------------------`
// * using min_heap
// * TIME COMPLEXITY O(nlogn) + O(n^2)
// * SPACE COMPLEXITY O(n)
int rangeSum(std::vector<int>& nums, int n, int left, int right) {
  int M = 1e9 + 7;

  // * Push all the initial values into heap with their indexes
  typedef std::pair<int, int> P;
  std::priority_queue<P, std::vector<P>, std::greater<P>> min_heap;
  for (int i = 0; i < n; ++i) { // * O(nlogn)
    min_heap.push({nums[i], i});
  }

  int ans = 0;
  int count = 1;

  while (!min_heap.empty()) { // * O(n^2)
    std::pair<int, int> p = min_heap.top();
    if (count >= left && count <= right) {
      ans = (ans + p.first) % M;
    }

    // std::cout << p.first << std::endl;
    min_heap.pop();

    int next_idx = p.second + 1;
    if (next_idx < n) {
      min_heap.push({p.first + nums[next_idx], next_idx});
    }

    count++;
  }

  return ans;
}


int main(void) {
  // * testcase 1
  int n = 4, left = 1, right = 5;
  std::vector<int> nums = {1, 2, 3, 4};

  std::cout << "n: " << n << ", left: " << left << ", right: " << std::endl;
  printArr(nums);

  // int ans = bruteForce(nums, n, left, right);
  // int ans = betterApproach(nums, n, left, right);
  int ans = rangeSum(nums, n, left, right);
  std::cout << "Range Sum of Sorted Subarray Sums " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 16-range-sum-of-sorted-subarray-sums.cpp -o output && ./output