/*
 * Leetcode - 78
 * Subsets
 * 
 * Given an integer array nums of unique elements, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets. Return the solution in any order.

 * Example 1
 * input  : nums = [1,2,3]
 * output : [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

 * Example 2
 * input  : nums = [0]
 * output : [[],[0]]
 * 
 * https://leetcode.com/problems/subsets/description/
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

// * ------------------------- Optimal Approach -------------------------
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
void helper(std::vector<int> &nums,
            int i,
            std::vector<int> &temp,
            std::vector<std::vector<int>> &ans)
{
  if (i >= nums.size()) {
    ans.push_back(temp);
    return;
  }

  // * All subsets that include nums[i]
  temp.push_back(nums[i]); // * take
  helper(nums, i + 1, temp, ans);
  
  // * All subsets that don't include nums[i]
  temp.pop_back();  // * Not take
  helper(nums, i + 1, temp, ans);
}

std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
  std::vector<std::vector<int>> ans;
  std::vector<int> temp;
  helper(nums, 0, temp, ans);
  return ans;
}

int main(void) {
  // * testcase 1
  std::vector<int> nums = {1, 2, 3};

  // * testcase 2
  // std::vector<int> nums = {1, 2, 3, 4};

  std::cout<<"Input nums: ";
  printArr(nums);
  
  std::vector<std::vector<int>> ans = subsets(nums);
  std::cout << "Subsets: " << std::endl;
  for (auto &vec : ans)
    printArr(vec);

 return 0;
}

// * Run the code
// * g++ --std=c++20 01-subsets.cpp -o output && ./output