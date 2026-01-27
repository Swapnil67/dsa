/*
 * Leetcode - 1911
 * Maximum Alternating Subsequence Sum 
 * 
 * The alternating sum of a 0-indexed array is defined as the sum of the elements at even indices minus
 * the sum of the elements at odd indices.
 * 
 * For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.
 * 
 * Given an array nums, return the maximum alternating sum of any subsequence of nums (after reindexing the 
 * elements of the subsequence).
 * 
 * Example 1   : 
 * Input       : nums = [4,2,5,3]
 * Output      : 7
 * Explanation : It is optimal to choose the subsequence [4,2,5] with alternating sum (4 + 5) - 2 = 7.
 * 
 * Example 2   : 
 * Input       : nums = [5,6,7,8]
 * Output      : 8
 * Explanation : It is optimal to choose the subsequence [8] with alternating sum 8.
 * 
 * Example 3   : 
 * Input       : nums = [6,2,1,2,4,5]
 * Output      : 10
 * Explanation : It is optimal to choose the subsequence [6,1,5] with alternating sum (6 + 5) - 1 = 10.
 * 
 * https://leetcode.com/problems/maximum-alternating-subsequence-sum/description/
*/

// ! Google, Amazon, Meta

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

void solve(vector<int>& nums, int i, std::vector<int> cur) {
  if (i >= nums.size()) {
    printArr(cur);
    return;
  }

  cur.push_back(nums[i]);
  solve(nums, i + 1, cur);
  
  cur.pop_back();
  solve(nums, i + 1, cur);
}

long long maxAlternatingSum(vector<int>& nums) {
  solve(nums, 0, {});
  return 0;
}

int main(void) {
  // * testcase 1
  std::vector<int> nums = {4, 2, 5};

  // * testcase 2
  // std::vector<int> nums = {5, 6, 7, 8};

  long long ans = maxAlternatingSum(nums);
  std::cout << "Maximum Alternating Subsequence Sum : " << ans << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 06-max-alternating-subsequence-sum.cpp -o output && ./output
