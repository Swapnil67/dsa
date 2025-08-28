/*
 * Leetcode - 2460
 * Apply Operations to an Array
 * You are given a 0-indexed array nums of size n consisting of non-negative integers.
 * You need to apply n - 1 operations to this array where, in the ith operation (0-indexed), you will apply
 * the following on the ith element of nums:
   * If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to 0. Otherwise, you skip this operation.
   * After performing all the operations, shift all the 0's to the end of the array.
   
 * 
 * Example 1
 * Input  : nums = [1, 2, 2, 1, 1, 0]
 * Output : [1, 4, 2, 0, 0, 0]
 * 
 * Example 2
 * Input  : nums = [0, 1]
 * Output : [1, 0]

 * https://leetcode.com/problems/merge-sorted-array/description/
*/

#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}


void moveZerosToEnd(std::vector<int>& nums) {
  int n = nums.size();

  // * go to first zero index
  int x = -1;
  for (int i = 0; i < n; ++i) {
    if (nums[i] == 0) {
      x = i;
      break;
    }
  }

  if (x == -1)
    return;

  for (int i = x + 1; i < n; ++i) {
    if (nums[i] != 0) {
      nums[x] = nums[i];
      nums[i] = 0;
      x++;
    }
  }

}

std::vector<int> applyOperations(std::vector<int>& nums) {
  int n = nums.size();

  int i = 0;
  while (i < n) {
    if (nums[i] == nums[i + 1]) {
      nums[i] = nums[i] * 2;
      nums[i + 1] = 0;
      i += 2;
    }
    else {
      i++;
    }
  }

  moveZerosToEnd(nums);
  return nums;
}

int main(void) {
  
  std::vector<int> nums = {1, 2, 2, 1, 1, 0};
  std::cout << "Before Applying operations" << std::endl;
  printArr(nums);

  std::cout << "After Applying operations" << std::endl;
  std::vector<int> ans = applyOperations(nums);
  printArr(ans);
  
  return 0;
}

// * Run the code
// * g++ -std=c++17 12-apply-operations-on-arr.cpp -o output && ./output