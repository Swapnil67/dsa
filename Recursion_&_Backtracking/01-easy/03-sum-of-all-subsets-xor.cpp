/*
 * Leetcode - 1863
 * Sum of All Subset XOR Totals
 * 
 * The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.
 * - For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
 
 * Given an array nums, return the sum of all XOR totals for every subset of nums. 
 * Note: Subsets with the same elements should be counted multiple times.
 
 * An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

 * Example 1
 * input  : nums = [1,3]
 * output : 6

 * Example 2
 * input  : nums = [5,1,6]
 * output : 28

 * Example 3
 * input  : nums = [3,4,5,6,7,8]
 * output : 480
 * 
 * https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/
*/

#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// * All subsets
void helper(std::vector<int> &nums,
            std::vector<int> &temp,
            int &sum, int i,
            std::vector<std::vector<int>> subsets)
{
  if(i >= nums.size()) {
    // * xor sum
    int cur_xor = 0;
    for (auto &x : temp) {
      cur_xor = cur_xor ^ x;
    }
    sum += cur_xor;
    return;
  }

  // * All subsets that include nums[i]
  temp.push_back(nums[i]);
  helper(nums, temp, sum, i + 1, subsets);

  // * All subsets that don't include nums[i]
  temp.pop_back();
  helper(nums, temp, sum, i + 1, subsets);
}

// * Calculate xor on the go
int helper2(std::vector<int> &nums, int i, int cur_xor)
{
  if(i >= nums.size()) {
    return cur_xor;
  }

  int include = helper2(nums, i + 1, cur_xor ^ nums[i]);
  int exclude = helper2(nums, i + 1, cur_xor);
  return include + exclude;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Find all possible subsets
// * TIME COMPLEXITY O(n * 2^n)
// * SPACE COMPLEXITY O(n * 2^n)
int bruteForce(std::vector<int> &nums) {
  std::vector<std::vector<int>> subsets;
  std::vector<int> temp;
  int sum = 0;
  helper(nums, temp, sum, 0, subsets);
  return sum;
}

// * ------------------------- APPROACH 2: Better APPROACH -------------------------`
// * Find all possible subsets
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n) (Recursion Stack Depth)
int betterApproach(std::vector<int> &nums) {
  int cur_xor = 0;
  return helper2(nums, 0, cur_xor);
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * Using logical OR operation & bit shifting
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
int subsetXORSum(std::vector<int> &nums) {
  int n = nums.size();

  // * Do logical or on all the values in num
  int or_val = 0;
  for (auto &x : nums) {
    or_val |= x;
  }

  // * Append n-1 zeros to the end of or_val
  return or_val << (n - 1);
}

int main(void) {
  // std::vector<int> nums = {1, 3};
  // std::vector<int> nums = {5, 1, 6};
  std::vector<int> nums = {3, 4, 5, 6, 7, 8};

  std::cout<<"Input nums: ";
  printArr(nums);

  // int ans = bruteForce(nums);
  // int ans = betterApproach(nums);
  int ans = subsetXORSum(nums);
  std::cout << "Sum of All Subset XOR Totals: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-sum-of-all-subsets-xor.cpp -o output && ./output