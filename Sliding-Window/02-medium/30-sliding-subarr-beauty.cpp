/**
 * * Leetcode - 2653
 * * Sliding Subarray Beauty
 * 
 * * Given an integer array nums containing n integers, find the beauty of each subarray of size k.
 * * The beauty of a subarray is the xth smallest integer in the subarray if it is negative, or 0 
 * * if there are fewer than x negative integers.
 * * Return an integer array containing n - k + 1 integers, which denote the beauty of the subarrays in order 
 * * from the first index in the array.
 * 
 * * https://leetcode.com/problems/sliding-subarray-beauty/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * TIME COMPLEXITY O(N * K)
// * SPACE COMPLEXITY O(1)
std::vector<int> bruteForce(std::vector<int> &nums, int k, int x) {
  std::vector<int> ans;
  int n = nums.size();

  // * O(N * K)
  for(int i = 0; i <= n - k; ++i) {
    std::vector<int> temp;
    for (int j = i; j < (i + k); ++j) {
      temp.push_back(nums[j]);
    }

    int val = 0;
    if (temp.size() >= x) {
      std::sort(temp.begin(), temp.end());  // * O(KlogK)
      val = temp[x - 1] <= 0 ? temp[x - 1] : 0;
    }
    ans.push_back(val);
  }

  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Classic Sliding Window + Counting Sort
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
std::vector<int> getSubarrayBeauty(std::vector<int> &nums, int k, int x) {
  int n = nums.size();
  std::vector<int> ans;

  if (n == 0)
    return ans;

  // * map[number, count]
  std::unordered_map<int, int> mp;

  int i = 0, j = 0;
  while (j < n) {
    // * Update the number frequency
    mp[nums[j]]++;
    
    // * Shrink the window
    if ((j - i + 1) > k) {
      mp[nums[i]]--;
      i++;
    }

    // * Counting sort
    if ((j - i + 1) == k) {
      int f = 0, val = 0;
      for (int i = -50; i <= -1; ++i) {
        f += mp[i];
        if (f >= x) {
          val = i;
          break;
        }
      }
      ans.push_back(val);
    }

    j++;
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // int k = 3, x = 2;
  // std::vector<int> nums = {1, -1, -3, -2, 3};

  // * testcase 2
  int k = 2, x = 2;
  std::vector<int> nums = {-1, -2, -3, -4, -5};

  // * testcase 3
  // int k = 2, x = 1;
  // std::vector<int> nums = {-3, 1, 2, -3, 0, -3};

  // * testcase 3
  // int k = 9, x = 4;
  // std::vector<int> nums = {-14, 9, 13, -26, 47, -39, -49, -14, 29};

  std::cout << "k = " << k << ", x = " << x << std::endl;
  std::cout << "Input Array" << std::endl;
  printArr(nums);
  
  // std::vector<int> ans = bruteForce(nums, k, x);
  std::vector<int> ans = getSubarrayBeauty(nums, k, x);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 30-sliding-subarr-beauty.cpp -o output && ./output 