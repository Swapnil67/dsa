/*
 * Leetcode - 1929
 * Concatenation of Array
 * Given an integer array nums of length n, you want to create an array ans of length 2n 
 * where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

 * Specifically, ans is the concatenation of two nums arrays.
 * Return the array ans.

 * * Example 1
 * * Input  : nums = [1,2,1]
 * * Output : [1,2,1,1,2,1]
 * 
 * * Example 2
 * * Input  : nums = [1,3,2,1]
 * * Output : [1,3,2,1,1,3,2,1]

 * https://leetcode.com/problems/concatenation-of-array/description/
*/

#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

std::vector<int> getConcatenation(std::vector<int>& nums) {
  std::vector<int> ans(nums.begin(), nums.end());

  int n = nums.size();
  if (n == 0)
    return ans;

  for (int i = 0; i < n; ++i) {
    ans.push_back(nums[i]);
  }

  return ans;
}

int main() {
  // * testcase 1
  // std::vector<int> arr = {1, 2, 1};

  // * testcase 2
  std::vector<int> arr = {1, 3, 2, 1};

  std::cout << "Before Concatenation" << std::endl;
  printArr(arr);

  std::vector<int> ans = getConcatenation(arr);

  std::cout<<"After Concatenation"<<std::endl;
  printArr(ans);
  
  return 0;
}

// * Run the code
// * g++ --std=c++17 04-concatenation-of-array.cpp -o output && ./output
