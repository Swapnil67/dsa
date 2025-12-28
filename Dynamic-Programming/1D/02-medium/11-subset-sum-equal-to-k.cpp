/*
 * Subset Sum Equal To K
 * 
 * You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. 
 * Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
 
 * Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

 * Example 1
 * input            : k = 5, nums = {4, 3, 9, 2};
 * output           : true
 * Explanation      : subset sum {3,2} equals 5

 * Example 2
 * input            : k = 1, nums = {4, 3, 9, 2};
 * output           : false
 * Explanation      : no subset sum equals 'k'

 * https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954
*/

#include <vector>
#include <iostream>

template <typename T>
void printArr(std::vector<T> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

bool solve(int& k, std::vector<int>& nums, int cur_sum, int i) {
  // std::cout<<cur_sum<<std::endl;
  if (cur_sum == k)
    return true;

  if (i >= nums.size())
    return false;

  bool not_take = solve(k, nums, cur_sum, i + 1); 

  bool take = false;

  if (cur_sum + nums[i] <= k)
    take = solve(k, nums, cur_sum + nums[i], i + 1);

  return take || not_take;

  // return solve(k, nums, cur_sum + nums[i], i + 1) ||
  //        solve(k, nums, cur_sum, i + 1);
}

// TODO Apply DP
// * ------------------------- Approach: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n) (Recursion Stack)
bool subsetSumToK(std::vector<int> nums, int k) {
  return solve(k, nums, 0, 0);
}

int main(void) {
  // int n = 3;
  int k = 5;
  std::vector<int> nums = {4, 3, 9, 2};

  std::cout << "k: " << k << std::endl;
  std::cout << "Input nums: ";
  printArr(nums);

  bool ans = subsetSumToK(nums, k);
  std::cout << "found: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 24-subset-sum-equal-to-k.cpp -o output && ./output 