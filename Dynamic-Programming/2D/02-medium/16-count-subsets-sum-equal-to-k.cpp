/*
 * Count Subsets Sum Equal To K

 * Example 1
 * input            : k = 5, nums = {1, 1, 4, 5};
 * output           : 3
 * Explanation      : subsets sum {1,4}, {1, 4} & {5} equals 5

 * Example 2
 * input            : k = 4, nums = {0, 1, 3};
 * output           : 2
 * Explanation      : subsets sum {1,3}, {0, 1, 2} equals 4

 * https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532
*/

// ! PharmEasy

// ! DP on subsequences (Same as question 15)

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

typedef long long ll;

// * Without Memoization
int dfs(int i, int k, vector<int>& nums) {
  if (i == 0)  {
    if (k == 0 && nums[0] == 0) {
      // * since nums[0] == 0, we have 2 options either take or not take 
      // * it won't change our answer
      return 2;
    }
    return (k == 0) ? 1 : 0;
  }

  int not_take = dfs(i - 1, k, nums);
  int take = 0;
  if (k >= nums[i]) {
    take = dfs(i - 1, k - nums[i], nums);
  }
  return (not_take + take);
}

// * With Memoization
int dfs(int i, int k, vector<int>& nums, vector<vector<int>> &dp) {
  if (dp[i][k] != -1)
    return dp[i][k];

  if (i == 0)  {
    if (k == 0 && nums[0] == 0) {
      // * since nums[0] == 0, we have 2 options either take or not take 
      // * it won't change our answer
      return 2;
    }
    return (k == 0) ? 1 : 0;
  }

  int not_take = dfs(i - 1, k, nums, dp);
  int take = 0;
  if (k >= nums[i]) {
    take = dfs(i - 1, k - nums[i], nums, dp);
  }
  return dp[i][k] = (not_take + take);
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
int bruteForce(vector<int> nums, int k) {
  return dfs(nums.size() - 1, k, nums);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(n * k)
// * SPACE COMPLEXITY O(n * k) * O(n)
int betterApproach(vector<int> nums, int k) {
  int n = nums.size();
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
  return dfs(n - 1, k, nums, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
int countSubsetSumEqualsK(vector<int> &nums, int &k) {
  int n = nums.size();
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

  // * Base Cases
  dp[0][0] = (nums[0] == 0) ? 2 : 1;
  if (k >= nums[0] && nums[0] != 0) {
    dp[0][nums[0]] = 1;
  }

  int M = (int)(1e9 + 7);

  for (int i = 1; i < n; i++) {
    for (int t = 0; t <= k; t++) {
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

  return dp[n - 1][k] % M;
}


// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(n * k)
// * SPACE COMPLEXITY O(n)
int countSubsetSumEqualsKDP2(vector<int> &nums, int k) {
  int n = nums.size();

  vector<int> dp(k + 1, 0);
  dp[0] = nums[0] == 0 ? 2 : 1;

  vector<int> next_dp(k + 1, 0);
  next_dp[0] = nums[0] == 0 ? 2 : 1;

  int M = (int)(1e9 + 7);
  for (int i = 0; i < n; ++i) {
    for (int t = 1; t <= k; ++t) {
      int not_take = dp[t];
      int take = 0;
      if (t >= nums[i]) {
        take = dp[t - nums[i]] % M;
      }
      next_dp[t] = (not_take % M + take % M);
    }

    dp = next_dp;
    printArr(dp);
  }

  return dp[k];
}

int main(void) {
  // * testcase 1
  // int k = 5;
  // vector<int> nums = {1, 1, 4, 5};

  // * testcase 2
  // int k = 2;
  // vector<int> nums = {1, 1, 1};

  // * testcase 3
  // int k = 40;
  // vector<int> nums = {2, 34, 5};

  // * testcase 4
  int k = 4;
  vector<int> nums = {0, 1, 3};

  cout << "k: " << k << endl;
  cout << "Input nums: ";
  printArr(nums);

  // int ans = bruteForce(nums, k);
  // int ans = betterApproach(nums, k);
  // int ans = countSubsetSumEqualsK(nums, k);
  int ans = countSubsetSumEqualsKDP2(nums, k);
  
  cout << "Number of subsets: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 16-count-subsets-sum-equal-to-k.cpp -o output && ./output