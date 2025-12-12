/*
 * Leetcode - 2294
 * Max Consecutive Ones II
 * 
 * Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.

 * Example 1
 * * Input  : nums = [1,0,1,1,0]
 * * Output : 4

 * Example 2
 * * Input  : nums = [1,0,1,1,0,1]
 * * Output : 4
 * 
 * 
 * https://neetcode.io/problems/max-consecutive-ones-ii/question
*/

#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * Classic Sliding Window
// * TIME COMPLEXITY O(n)
int findMaxConsecutiveOnes(std::vector<int> &nums) {
// * SPACE COMPLEXITY O(1)
  int n = nums.size();
  int ans = 0;
  int i = 0, j = 0, flips = 1;
  while (j < n) {
    if (nums[j] == 0)
      flips--;

    while (flips < 0) {
      if (nums[i] == 0)
        flips++;
      i++;
    }

    ans = std::max(ans, (j - i + 1));
    j++;
  }

  return ans;
}

int main(void) {
  // * testcase 1 (ans = 4)
  // std::vector<int> nums = {1, 0, 1, 1, 0};

  // * testcase 2 (ans = 2)
  std::vector<int> nums = {1, 0, 1, 1, 0, 1};

  // * testcase 3 (ans = 3)
  // std::vector<int> nums = {2, 2, 4, 5};

  std::cout << "Input Array" << std::endl;
  printArr(nums);
  
  int ans = findMaxConsecutiveOnes(nums);
  std::cout << "Count: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 32-max-consecutive-ones-II.cpp -o output && ./output 