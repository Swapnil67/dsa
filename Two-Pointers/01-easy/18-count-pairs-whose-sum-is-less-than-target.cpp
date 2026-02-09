/*
 * Leetcode - 2824
 * Count Pairs Whose Sum is Less than Target
 * 
 * Given a 0-indexed integer array nums of length n and an integer target, return the number of pairs 
 * (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target.
 * 
 * Example 1    :
 * Input        : nums = [-1,1,2,3,1], target = 2
 * Output       : 3
 * Explanation  : There are 3 pairs of indices that satisfy the conditions in the statement:
 * 
 * Example 2    :
 * Input        : nums = [-6,2,5,-2,-7,-1,3], target = -2
 * Output       : 10
 * Explanation  : There are 10 pairs of indices that satisfy the conditions in the statement:
 *
 * https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/description/ 
*/

#include <vector>
#include <iostream>
#include <algorithm>

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

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Sorting + Two Pointer
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1)
int countPairs(vector<int> &nums, int target) {
  sort(begin(nums), end(nums));

  int ans = 0;
  int l = 0, r = nums.size() - 1;
  while (l <= r) {
    if (nums[l] + nums[r] < target) {
      ans += (r - l);
      l++;
    } else {
      r--;
    }
  }

  return ans;
}

int main(void) {
  int target = 2;
  vector<int> nums = {-1, 1, 2, 3, 1};

  cout << "Target: " << target << endl;
  std::cout << "Input Nums: ";
  printArr(nums);

  int ans = countPairs(nums, target);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
