/*
 * Leetcode - 1909
 * Remove One Element to Make the Array Strictly Increasing
 * 
 * Given a 0-indexed integer array nums, return true if it can be made strictly increasing after removing 
 * exactly one element, or false otherwise. If the array is already strictly increasing, return true.
 * 
 * The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).
 * 
 * Example 1    :
 * Input        : nums = [1,2,10,5,7]
 * Output       : true
 * Explanation  : By removing 10 at index 2 from nums, it becomes [1,2,5,7].
 *                [1,2,5,7] is strictly increasing, so return true.
 * 
 * Example 2    :
 * Input        : nums = [2,3,1,2]
 * Output       : false
 * Explanation  : 
 * 
 * Example 3    :
 * Input        : nums = [1,1,1]
 * Output       : false
 * Explanation  : The result of removing any element is [1,1].
 *                [1,1] is not strictly increasing, so return false.
 * 
 * https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/description/
*/

#include <vector>
#include <iostream>

using namespace std;

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

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * When we find two consecutive elements which are not increasing, we have to analyze which one should be removed. 
// * If possible we should remove the bigger element.
// * Ex: [1, 7, 2, 3] - we should remove 7 when we analyze [7, 2]
// * [6, 7, 2, 3] - we can't remove 7 when we analyze [7, 2] because 2 <= 6
// * TIME COMPLEXITY O(N^2) + O(nlogn) ~ O(N^2) 
// * SPACE COMPLEXITY O(N)
bool canBeIncreasing(vector<int> &nums) {
  int n = nums.size();
  int previous = nums[0];
  bool used = false;
  for (int i = 1; i < n; ++i) {
    if (previous >= nums[i]) { // it's not strictly increasing
      if (used)
        return false;

      // we haven't used the element removal yet.
      used = true;
      if (i == 1 || nums[i] > nums[i - 2]) {
        // we remove the element from i - 1 position because it's
        // bigger, so we update previous.
        previous = nums[i];
      }
      // else we remove current element and leave previous to it's
      // existing value.
    } else {
      previous = nums[i];
    }
  }
  return true;
}

int main(void) {
  // * testcase 1
  std::vector<int> nums = {1, 2, 10, 5, 7};

  // * testcase 2
  std::vector<int> nums = {2, 3, 1, 2};

  // * testcase 3
  std::vector<int> nums = {1, 1, 1};

  std::cout << "Input nums: ";
  printArr(nums);

  bool ans = canBeIncreasing(nums);
  std::cout << "Can Increasing: " << ans << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 07-remove-one-element-to-make-the-array-strictly-increasing.cpp -o output && ./output
