/*
 * Leetcode - 2780
 * Minimum Index of a Valid Split
 * 
 * An element x of an integer array arr of length m is dominant if more than half the elements of
 * arr have a value of x.
 * 
 * You are given a 0-indexed integer array nums of length n with one dominant element.
 * 
 * You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], 
 * but the split is only valid if:
 * 
 * - 0 <= i < n - 1
 * - nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
 * 
 * Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, 
 * both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.
 * 
 * Return the minimum index of a valid split. If no valid split exists, return -1.
 * 
 * Example 1:
 * Input: nums = [1,2,2,2]
 * Output: 2

 * Example 2:
 * Input: nums = [2,1,3,1,1,1,7,1,2,1]
 * Output: 4

 * Example 3:
 * Input: nums = [3,3,3,3,7,2,2]
 * Output: -1
 * 
 * https://leetcode.com/problems/minimum-index-of-a-valid-split/description/
*/

#include <vector>
#include <iostream>
#include <unordered_map>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

std::pair<int, int> majorityElement(std::vector<int> &nums) {
  int n = nums.size();
  int cnt = 0, majority_ele = -1;
  for (int i = 0; i < n; ++i) {
    if (cnt == 0) {
      majority_ele = nums[i];
      cnt = 1;
    } else if (majority_ele == nums[i]) {
      cnt++;
    } else {
      cnt--;
    }
  }

  cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (nums[i] == majority_ele)
      cnt++;
  }

  if (cnt > (n / 2))
    return {majority_ele, cnt};

  return {-1, -1};
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(2N)
int bruteForce(std::vector<int> &nums) {
  int n = nums.size();
  std::unordered_map<int, int> freq_mp1, freq_mp2;

  // * Fill the freq_mp2 first
  for (int i = 0; i < n; ++i) {
    freq_mp2[nums[i]]++;
  }
  
  // * Find the valid split
  for (int i = 0; i < n; ++i) {
    int cur = nums[i];
    freq_mp1[cur]++; // * Add to freq_mp1
    freq_mp2[cur]--; // * Remove from freq_mp2

    int left = i + 1, right = n - i - 1;
    std::cout << "left: " << left << ", right: " << right << std::endl;
    
    // if (freq_mp1[cur] > (left / 2) && freq_mp2[cur] > (right / 2))
    if (freq_mp1[cur] * 2 > left && freq_mp2[cur] * 2 > right)
      return i; // * valid split
  }
  return -1;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Moore's Voting Algorithm
// * If x is dominant the following should be true
// * count2(x) > (n1 / 2) and count2 > (n2 / 2)
// * count1(x) + count2(x) > (n1 + n2) / 2
// * count > (n / 2) ===== This is same as majority element
// * TIME COMPLEXITY O(N) 
// * SPACE COMPLEXITY O(1)
int minimumIndex(std::vector<int> &nums) {
  int n = nums.size();

  // * Step 1. Find majority element
  auto [majority_ele, majority_cnt] = majorityElement(nums);
  if (majority_ele == -1)
    return -1;

  // std::cout << "Dominant Element: " << majority_ele << std::endl;

  // * Step 2.
  int cur_majority_cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (nums[i] == majority_ele) {
      cur_majority_cnt++;
    }
    int rem_majority_cnt = majority_cnt - cur_majority_cnt; // * Majority ele count in other half of split
    // std::cout << cur_majority_cnt << " " << rem_majority_cnt << std::endl;
    int n1 = i + 1, n2 = n - i - 1;
    if (cur_majority_cnt * 2 > n1 && rem_majority_cnt * 2 > n2) {
      return i;
    }
  }

  return -1;
}

int main() {
  // * testcase 1
  std::vector<int> arr = {1, 2, 2, 2};

  // * testcase 2
  // std::vector<int> arr = {2, 1, 3, 1, 1, 1, 7, 1, 2, 1};

  // * testcase 3
  // std::vector<int> arr = {3, 3, 3, 3, 7, 2, 2};

  std::cout << "Input Array: ";
  printArr(arr);

  // int ans = bruteForce(arr);
  int ans = minimumIndex(arr);
  std::cout << "Valid Split Index: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 09-min-index-of-a-valid-split.cpp -o output && ./output