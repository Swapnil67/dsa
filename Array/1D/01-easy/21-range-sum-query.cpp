/**
 * * Leetcode - 303
 * * Range Sum Query - Immutable
 * * Given an integer array nums, handle multiple queries of the following type:

 * * Example 1
 * * Input: ["NumArray", "sumRange", "sumRange", "sumRange"]
 * *        [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
 * * Output: [null, 1, -1, -3]
 * 
 * * https://leetcode.com/problems/range-sum-query-immutable/
*/

#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

class NumArray {
  std::vector<int> prefixSumVector;

  public:
    NumArray(std::vector<int> &nums) {
      int sum = 0;
      for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        prefixSumVector.push_back(sum);
      }
    }

    // * Find prefix sum
    int sumRange(int left, int right) {
      int leftPrefix = 0;
      if (left > 0) {
        leftPrefix = prefixSumVector[left - 1];
      }

      int rightPrefix = prefixSumVector[right];
      return rightPrefix - leftPrefix;
    }
};

int main() {
  std::vector<int> nums = {-2, 0, 3, -5, 2, -1};

  std::cout << "Input Vector" << std::endl;
  printArr(nums);
  
  NumArray *obj = new NumArray(nums);
  std::cout << "Prefix Sum from 0 to 2 : " << obj->sumRange(0, 2) << std::endl;
  std::cout << "Prefix Sum from 2 to 5 : " << obj->sumRange(2, 5) << std::endl;
  std::cout << "Prefix Sum from 0 to 5 : " << obj->sumRange(0, 5) << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 21-range-sum-query.cpp -o output && ./output