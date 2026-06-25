/*
 * Leetcode - 3264
 * Final Array State After K Multiplication Operations I
 * 
 * You are given an integer array nums, an integer k, and an integer multiplier.
 * You need to perform k operations on nums. In each operation:

 * - Find the minimum value x in nums. If there are multiple occurrences of the minimum value,
 *   select the one that appears first.
 * - Replace the selected minimum value x with x * multiplier.
 * 
 * Return an integer array denoting the final state of nums after performing all k operations.

 * Example 1
 * input  : nums = [2,1,3,5,6], k = 5, multiplier = 2
 * output : [8,4,6,5,6]
 * 
 * https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/
*/

#include <queue>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

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

int get_smallest_index(vector<int> &nums) {
  int idx = 0;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[idx] > nums[i])
      idx = i;
  }
  return idx;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop + Sorting
// * TIME COMPLEXITY O(k * n)
// * SPACE COMPLEXITY O(1)
vector<int> bruteForce(vector<int>& nums, int k, int multiplier) {
  int n = nums.size();
  if (n == 0)
    return nums;
    
  while (k > 0) {
    // * get the smallest element index
    int smallest_idx = get_smallest_index(nums);
    int smallest_ele = nums[smallest_idx];
    nums[smallest_idx] = smallest_ele * multiplier;
    
    k--;
    // printArr(nums); // * for debugging
  }

  return nums;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using min_heap
// * TIME COMPLEXITY O(nlogn + klogn)
// * SPACE COMPLEXITY O(n)
vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {

  typedef pair<int, int> P;
  priority_queue<P, vector<P>, greater<P>> min_heap; // * O(nlogn)

  int n = nums.size();
  
  // * 1. push nums to min_heap
  for (int i = 0; i < n; ++i) {
    min_heap.push({nums[i], i});
  }

  while (k > 0) { // * O(klogn)
    // * take the smallest val
    auto [cur_min, cur_min_idx] = min_heap.top();
    min_heap.pop();
    
    int new_val = cur_min * multiplier;
    min_heap.push({new_val, cur_min_idx});
    nums[cur_min_idx] = new_val;

    k--;
  }

  return nums;
}

int main() {
  // * testcase 1
  // int k = 5, multiplier = 2;
  // vector<int> nums = {2, 1, 3, 5, 6};
  
  // * testcase 2
  int k = 3, multiplier = 4;
  vector<int> nums = {1, 2};

  cout << "k: " << k << " multiplier: " << multiplier << endl;
  cout << "nums: ";
  printArr(nums);

  // vector<int> ans = bruteForce(nums, k, multiplier);
  vector<int> ans = getFinalState(nums, k, multiplier);

  cout << "Answer nums " << endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 04-final-arr-state-after-k-mul-i.cpp -o output && ./output

