/*
 * Leetcode - 90
 * Subsets II
 * 
 * Given an integer array nums of unique elements, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets. Return the solution in any order.

 * Example 1
 * input  : nums = [1,2,2]
 * output : [[],[1],[1,2],[1,2,2],[2],[2,2]]

 * Example 2
 * input  : nums = [0]
 * output : [[],[0]]
 * 
 * https://leetcode.com/problems/subsets-ii/description/
*/

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

// * ------------------------- Optimal Approach -------------------------`
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n * 2^n)
void helper(std::vector<int> &nums, int i, std::vector<int> &temp, std::vector<std::vector<int>> &ans) {
  if (i >= nums.size()) {
    ans.push_back(temp);
    return;
  }

  // * All subsets that include nums[i]
  temp.push_back(nums[i]); // * take
  helper(nums, i + 1, temp, ans);

  temp.pop_back();  // * Not take

  // * All subsets that don't include nums[i]
  while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
    i += 1;
  }
  helper(nums, i + 1, temp, ans);

}

std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
  std::sort(nums.begin(), nums.end()); // * to handle duplicates

  std::vector<std::vector<int>> ans;
  std::vector<int> temp;
  helper(nums, 0, temp, ans);
  return ans;
}

int main(void) {
  std::vector<int> nums = {1, 2, 2};
  std::cout<<"Input nums: ";
  printArr(nums);
  
  std::vector<std::vector<int>> ans = subsets(nums);
  std::cout << "Subsets: " << std::endl;
  for (auto &vec : ans)
    printArr(vec);

 return 0;
}

// * Run the code
// * g++ --std=c++20 02-subsets-ii.cpp -o output && ./output