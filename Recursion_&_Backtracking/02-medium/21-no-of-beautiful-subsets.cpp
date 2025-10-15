/*
 * Leetcode - 2597
 * The Number of Beautiful Subsets
 * 
 * Given an integer array nums and an integer k, return true if it is possible to divide this array into 
 * k non-empty subsets whose sums are all equal.

 * Return the maximum possible length of s.
 
 * A subsequence is an array that can be derived from another array by deleting some or no elements without
 * changing the order of the remaining elements.

 * Example 1
 * input       : nums = [4,3,2,3,5,2,1], k = 4
 * output      : true

 * Example 1
 * input       : nums = [1,2,3,4], k = 3
 * output      : false

 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets
*/

#include <vector>
#include <iostream>
#include <unordered_map>

template <typename T>
void printArr(std::vector<T> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

bool is_beautiful(std::vector<int> &nums, int &k) {
  printArr(nums);
  int n = nums.size();

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i; j < n - 1; ++j) {
      if (std::abs(nums[i] - nums[j + 1]) == k) {
        std::cout << nums[i] << " " << nums[j + 1] << std::endl;
        return false;
      }
    }
  }
  return true;
}

int ans;
void solveBrute(std::vector<int> &nums,
                std::vector<int> temp,
                int &k, int i)
{
  if (i >= nums.size()) {
    if (is_beautiful(temp, k))
      ans++;
    return;
  }

  // * not take
  temp.push_back(nums[i]);
  solveBrute(nums, temp, k, i + 1);
  
  temp.pop_back();
  solveBrute(nums, temp, k, i + 1);
}

void solve(std::vector<int> &nums,
           std::unordered_map<int, int> mp,
           int &k, int i)
{
  if (i >= nums.size()) {
    ans++;
    return;
  }

  // * not take
  solve(nums, mp, k, i + 1);
  
  // * take
  if (!mp[nums[i] + k] && !mp[nums[i] - k]) {
    mp[nums[i]]++;
    solve(nums, mp, k, i + 1);
    mp[nums[i]]--;
  }
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------`
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
int bruteForce(std::vector<int>& nums, int k) {
  ans = 0;
  std::vector<int> temp;
  solveBrute(nums, temp, k, 0);
  return ans - 1; // * exclude empty subset
}

// * ------------------------- Approach: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
int beautifulSubsets(std::vector<int>& nums, int k) {
  ans = 0;
  std::unordered_map<int, int> mp;
  solve(nums, mp, k, 0);

  return ans - 1; // * exclude empty subset
}

int main(void) {
  // * testcase 1
  // int k = 2;
  // std::vector<int> nums = {2, 4, 6};

  // * testcase 2
  // int k = 3;
  // std::vector<int> nums = {1, 2, 3, 4};

  // * testcase 3
  int k = 3;
  std::vector<int> nums = {1, 1, 2, 2, 2};

  std::cout << "k: " << k << std::endl;
  std::cout << "Input nums: ";
  printArr(nums);


  // int ans = bruteForce(nums, k);
  int ans = beautifulSubsets(nums, k);
  std::cout << "Beautiful Subsets: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 21-no-of-beautiful-subsets.cpp -o output && ./output