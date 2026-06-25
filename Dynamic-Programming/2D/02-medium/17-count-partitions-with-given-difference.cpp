/*
 * Partitions With Given Difference

 * Example 1
 * input            : nums = [5, 2, 6, 4], diff = 3
 * output           : 1
 * Explanation      : There is only one possible partition of this array. Partition : [6, 4], [5, 2]. 
 *                    The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.

 * Example 2
 * input            : nums = [1, 1, 1, 1], diff = 3
 * output           : 6
 * Explanation      : We can choose two 1's from indices [0,1], [0,2], [0,3], [1,2], [1,3], [2,3].

 * Example 3
 * input            : nums = [3, 2, 7, 1], diff = 4  
 * output           : 0
 * Explanation      : There is no possible partition of the array that satisfy the given difference.
 * 
 * https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628
 * https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
*/

// ! DP on subsequences (Same as question 15)

#include <vector>
#include <numeric>
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

const int M = (int)(1e9 + 7);

// * Without Memoization
int dfs(int i, int k, vector<int>& nums) {
  // cout << i << " " << k << endl;
  if (i == nums.size()) {
    return (k == 0);
  }

  int not_take = dfs(i + 1, k, nums);
  int take = 0;
  if (k >= nums[i]) {
    take = dfs(i + 1, k - nums[i], nums);
  }
  return (take + not_take) % M;
}

// * With Memoization
int dfs(int i, int k, vector<int>& nums, vector<vector<int>> &dp) {
  if (i == nums.size()) {
    return (k == 0);
  }

  if (dp[i][k] != -1)
    return dp[i][k];

  int not_take = dfs(i + 1, k, nums, dp);
  int take = 0;
  if (k >= nums[i]) {
    take = dfs(i + 1, k - nums[i], nums, dp);
  }
  return dp[i][k] = (not_take + take);
}

// * Intuition
// * s1 = total_sum - s2
// * s1 - s2 = d
// * total_sum - s2 - s2 = d
// * total_sum - d = 2 * s2
// * s2 = (total_sum - d) / 2;
// * We need to find subsets whose sum is equal to s2

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
int bruteForce(vector<int> &nums, int &diff) {

  int total_sum = accumulate(begin(nums), end(nums), 0);
  if (total_sum - diff < 0 || (total_sum - diff) % 2  != 0)
    return 0; 
  int target = (total_sum - diff) / 2; 
  cout << "Target: " << target << endl;
  return dfs(0, target, nums);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(n * k)
// * SPACE COMPLEXITY O(n * k) * O(n)
int betterApproach(vector<int> nums, int diff) {
  int n = nums.size();

  int total_sum = accumulate(begin(nums), end(nums), 0);
  if (total_sum - diff < 0 || (total_sum - diff) % 2 != 0)
    return 0;

  int target = (total_sum - diff) / 2; 
  vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
  // cout << "Target: " << target << endl;
  return dfs(0, target, nums, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
int countSubsetSumEqualsK(vector<int> &nums, int &diff) {
  int n = nums.size();
  
  int total_sum = accumulate(begin(nums), end(nums), 0);
  if (total_sum - diff < 0 || (total_sum - diff) % 2 != 0)
    return 0;
  
  int target = (total_sum - diff) / 2; 
  vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

  // * Base Cases
  dp[0][0] = (nums[0] == 0) ? 2 : 1;
  if (nums[0] != 0 && target >= nums[0]) {
    dp[0][nums[0]] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int t = 0; t <= target; t++) {
      int not_take = dp[i - 1][t];
      int take = 0;
      if (nums[i] <= t) {
        take = dp[i - 1][t - nums[i]];
      }
      dp[i][t] = (take + not_take) % M;
    }
  }

  // * For Debugging
  for (auto &vec : dp)
    printArr(vec);

  return dp[n - 1][target] % M;
}


// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(n * k)
// * SPACE COMPLEXITY O(n)
int countSubsetSumEqualsKDP2(vector<int> &nums, int &diff) {
  int n = nums.size();

  int total_sum = accumulate(begin(nums), end(nums), 0);
  if ((total_sum - diff) < 0 || (total_sum - diff) % 2 != 0)
    return 0;
  
  int target = (total_sum - diff) / 2; 

  vector<int> dp(target + 1, 0);
  dp[0] = nums[0] == 0 ? 2 : 1; // * Base Case
  if (nums[0] != 0 && target >= nums[0]) // * Base Case
    dp[nums[0]] = 1;

  vector<int> next_dp(target + 1, 0);

  for (int i = 1; i < n; ++i) {
    for (int t = 0; t <= target; ++t) {
      int not_take = dp[t];
      int take = 0;
      if (t >= nums[i]) {
        take = dp[t - nums[i]];
      }
      next_dp[t] = (not_take + take);
    }

    dp = next_dp;
    printArr(dp);
  }

  return dp[target] % M;
}

int main(void) {
  // * testcase 1
  // int diff = 3;
  // vector<int> nums = {5, 2, 6, 4};

  // * testcase 2
  int diff = 0;
  vector<int> nums = {1, 1, 1, 1};

  // * testcase 3
  // int diff = 4;
  // vector<int> nums = {3, 2, 7, 1};

  // * testcase 4
  // int diff = 4;
  // vector<int> nums = {0, 1, 3};

  cout << "diff: " << diff << endl;
  cout << "Input nums: ";
  printArr(nums);

  // int ans = bruteForce(nums, diff);
  // int ans = betterApproach(nums, diff);
  // int ans = countSubsetSumEqualsK(nums, diff);
  int ans = countSubsetSumEqualsKDP2(nums, diff);
  
  cout << "Number of subsets: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 17-count-partitions-with-given-difference.cpp -o output && ./output