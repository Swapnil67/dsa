/*
 * Leetcode - 2239
 * Find Closest Number to Zero 
 * 
 * https://leetcode.com/problems/find-closest-number-to-zero/description/
*/

// ! Microsoft

#include <vector>
#include <iostream>

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

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int findClosestNumber(std::vector<int> &nums) {
  int ans = nums[0];
  for (auto &x: nums) {
    if (std::abs(x) < std::abs(ans)) {
      ans = x;
    }
    else if (std::abs(x) == std::abs(ans)) {
      ans = std::max(ans, x);
    }
  }
  return ans;
}

int main(void) {
  // * testcase 1
  // std::vector<int> nums = {-4, -2, 1, 4, 8};

  // * testcase 2
  std::vector<int> nums = {2, -1, 1};

  std::cout << "Input Array" << std::endl;
  printArr(nums);

  int ans = findClosestNumber(nums);
  std::cout << "Closest Number to Zero: " << ans << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 31-find-closest-number-to-zero.cpp -o output && ./output