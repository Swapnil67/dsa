/*
 * Leetcode - 215
 * Kth Largest Element in an Array
 * 
 * Given an integer array nums and an integer k, return the kth largest element in the array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Can you solve it without sorting?

 * Example 1
 * input  : nums = [3,2,1,5,6,4], k = 2
 * output : 5

 * Example 2
 * input  : nums = [3,2,3,1,2,4,5,5,6], k = 4
 * output : 4
 * 
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
*/

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop + Sorting
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> nums, int k) {
  int n = nums.size();
  if (n == 0)
    return 0;

  // * sort the coordinates in ASC order 
  std::sort(nums.begin(), nums.end());
  return nums[n - k];
}

// * ------------------------- APPROACH 2A: Optimal Approach -------------------------`
// * Using min_heap
// * TIME COMPLEXITY O(nlogk)
// * SPACE COMPLEXITY O(k)
int findKthLargest(std::vector<int> nums, int k) {
  int n = nums.size();
  if (n == 0)
    return 0;

  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  for(int i = 0; i < n; ++i) {
    min_heap.push(nums[i]);
    if (min_heap.size() > k)
      min_heap.pop();
  }

  return min_heap.top();
}

// * ------------------------- APPROACH 2B: Optimal Approach -------------------------`
// * Quick Select algorithm
// * TIME COMPLEXITY 
// * - Avg Case   : O(n)
// * - Worst Case : O(n^2)
// * SPACE COMPLEXITY O(1)
int quickSelect(std::vector<int> &nums, int l, int r, int k) {
  int pivot = nums[r];
  int p = l;

  for (int i = l; i < r; ++i) {
    if (nums[i] <= pivot) {
      swap(nums[p], nums[i]);
      p++;
    }
  }
  swap(nums[p], pivot);

  if (p > k) {
    return quickSelect(nums, l, p - 1, k);
  } else if(p < k) {
    return quickSelect(nums, p + 1, r, k);
  }
  
  return nums[p];
}

int findKthLargest2(std::vector<int> &nums, int k) {
  int n = nums.size();
  if (n == 0)
    return 0;

  k = n - k;
  return quickSelect(nums, 0, n - 1, k);
}

int main() {
  // * testcase 1
  // int k = 2;
  // std::vector<int> nums = {3, 2, 1, 5, 6, 4};

  // * testcase 2
  int k = 4;
  std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};

  std::cout << "k: " << k << std::endl;
  std::cout << "Nums: ";
  printArr(nums);

  // int ans = bruteForce(nums, k);
  // int ans = findKthLargest(nums, k);
  int ans = findKthLargest2(nums, k);

  std::cout << "Kth Largest Element in an Array: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-kth-largest-element.cpp -o output && ./output


