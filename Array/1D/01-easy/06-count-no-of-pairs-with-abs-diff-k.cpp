/*
 * Leetcode - 2006
 * Count Number of Pairs With Absolute Difference 
 * 
 * Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.
 * 
 * The value of |x| is defined as:
 * x if x >= 0.
 * -x if x < 0.
 * 
 * Example1  :
 * Input     : nums = [1,2,2,1], k = 1
 * Output    : 4
 * 
 * Example2  :
 * Input     : nums = [1,3], k = 3
 * Output    : 0
 * 
 * Example3  :
 * Input     : nums = [3,2,1,5,4], k = 2
 * Output    : 3
 * 
 * https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/
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

int countKDifference(std::vector<int> &nums, int k) {
  std::unordered_map<int, int> freq_mp;
  for (auto &x : nums) {
    freq_mp[x]++;
  }

  int pairs = 0;
  for (auto &x : nums) {
    // * nums[i] - nums[j] = k
    // * nums[i] = k + nums[j]
    pairs += freq_mp[std::abs(k + x)];
  }

  return pairs;
}

int main(void) {
  // * testcase 1
  // int k = 1;
  // std::vector<int> nums = {1, 2, 2, 1};

  // * testcase 2
  int k = 2;
  std::vector<int> nums = {3, 2, 1, 5, 4};

  // * testcase 3
  // int k = 3;
  // std::vector<int> nums = {1, 3};

  std::cout << "k: " << k << std::endl;
  std::cout << "Nums: ";
  printArr(nums);

  int ans = countKDifference(nums, k);
  std::cout << "Pairs: " << ans << std::endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 06-count-no-of-pairs-with-abs-diff-k.cpp -o output && ./output
