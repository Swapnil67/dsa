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
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}
long long dfsBrute(int i, bool flag, vector<int> &nums) {
  if (i >= nums.size())
    return 0;

  long long skip = dfsBrute(i + 1, flag, nums);
  long long val = flag ? -nums[i] : nums[i];
  long long steal = val + dfsBrute(i + 1, !flag, nums);

  return max(skip, steal);
}

// * flag -> true : odd
// * flag -> false : even
long long dfs(int i, bool flag, vector<int> &nums,
              vector<vector<long long>> &dp) {
  if (i >= nums.size())
    return 0;

  if (dp[i][flag] != -1)
    return dp[i][flag];

  long long skip = dfs(i + 1, flag, nums, dp);
  long long val = flag ? -nums[i] : nums[i];
  long long steal = val + dfs(i + 1, !flag, nums, dp);

  return dp[i][flag] = max(skip, steal);
}

// * ------------------------- Approach 1: Brute Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^N)
// * SPACE COMPLEXITY O(2^N)
long long bruteForce(vector<int>& nums) {
  int n = nums.size();
  return dfsBrute(0, false, nums);
}

// * ------------------------- Approach 2: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
long long betterApproach(vector<int>& nums) {
  int n = nums.size();
  vector<vector<long long>> dp(n + 1, vector<long long>(2, -1));
  return dfs(0, false, nums, dp);
}

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * Classic Pattern
// * flag -> true : odd
// * flag -> false : even
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
long long maxAlternatingSum(vector<int> &nums) {
  long long even_sum = 0, odd_sum = 0;
  for (auto &x : nums) {
    long long next_even = max(even_sum, odd_sum + x);
    long long next_odd = max(odd_sum, even_sum - x);
    even_sum = next_even;
    odd_sum = next_odd;
  }
  return even_sum;
}

int main(void) {
  // * testcase 1
  vector<int> nums = {4, 2, 5};

  // * testcase 2
  // vector<int> nums = {5, 6, 7, 8};

  // long long ans = bruteForce(nums);
  // long long ans = betterApproach(nums);
  long long ans = maxAlternatingSum(nums);

  cout << "Maximum Alternating Subsequence Sum : " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 06-max-alternating-subsequence-sum.cpp -o output && ./output
