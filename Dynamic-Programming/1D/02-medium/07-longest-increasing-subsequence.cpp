/*
 * Leetcode - 300 
 * Longest Increasing Subsequence (LIS)
 * 
 * Given an integer array nums, return the length of the longest strictly increasing subsequence.
 *
 * Example 1    :
 * Input        : nums = [10,9,2,5,3,7,101,18]
 * Output       : 4
 * Explanation  : The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 * 
 * Example 2    :
 * Input        : nums = [0,1,0,3,2,3]
 * Output       : 4
 * Explanation  : The longest increasing subsequence is [0,1,2,3], therefore the length is 4.
 * 
 * Example 3    :
 * Input        : nums = [7,7,7,7,7,7,7]
 * Output       : 1
 * Explanation  : The longest increasing subsequence is [7], therefore the length is 1.
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 * https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1
 * https://www.naukri.com/code360/problems/printing-longest-increasing-subsequence_8360670
 * https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
*/

// ! Amazon, Google, Meta, Microsoft, Oracle, Uber, Paypal, Bloomberg

// ! LIS

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

bool is_increasing(vector<int> &nums) {
  int n = nums.size();
  for (int i = 1; i < n; ++i) {
    if (nums[i - 1] >= nums[i])
      return false;
  }
  return true;
}

void solve_brute(int i, int &ans, vector<int> cur, vector<int> &nums) {
  if (i >= nums.size()) {
    ans = max(ans, (int)cur.size());
    return;
  }

  if (cur.empty() || cur.back() < nums[i])
    cur.push_back(nums[i]);
  solve_brute(i + 1, ans, cur, nums);

  if (cur.size() > 0)
    cur.pop_back();

  solve_brute(i + 1, ans, cur, nums);
}

int dfs(int i, int prev_idx, vector<int> &nums, vector<vector<int>> &dp) {
  if (i >= nums.size()) {
    return 0;
  }

  // * Add +1 to prevent indexing '-1'
  if (dp[i][prev_idx + 1] != -1) 
    return dp[i][prev_idx + 1];

  // * only take if cur number is strictly greater previous number
  int take = 0;
  if (prev_idx == -1 || nums[prev_idx] < nums[i]) { 
    take = 1 + dfs(i + 1, i, nums, dp);
  }
  int skip = dfs(i + 1, prev_idx, nums, dp);

  return dp[i][prev_idx + 1] = max(take, skip);
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * Generate All the subsequences
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(2^n) 
int bruteForce(vector<int> &nums) {
  int ans = 0;
  solve_brute(0, ans, {}, nums);
  return ans;
}

// * ------------------------- Approach 2: Better Approach -------------------------
// * Recursion + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2) 
int lengthOfLIS(vector<int> &nums) {
  int n = nums.size();
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  return dfs(0, -1, nums, dp);
}

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * Bottom Up DP
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n) 
int lengthOfLIS2(vector<int> &nums) {
  int n = nums.size();
  vector<int> t(n + 1, 1);
  int max_len = 1;
  for (int i = 0; i < n; ++i) {
    int cur = nums[i];
    for (int j = 0; j < i; ++j) {
      if (cur > nums[j]) {
        t[i] = max(t[i], t[j] + 1);
        max_len = max(max_len, t[i]);
      }
    }
    // printArr(t);
  }
  
  return max_len;
}


// * Print LIS
// * TIME COMPLEXITY O(n * n)
// * SPACE COMPLEXITY O(n) 
vector<int> getLIS(vector<int> &nums) {
  int n = nums.size();
  vector<int> t(n + 1, 1);
  vector<int> lis(n);

  int max_len = 1, last_idx = 0;
  for (int i = 0; i < n; ++i) {
    lis[i] = i;
    int cur = nums[i];
    for (int j = 0; j < i; ++j) {
      if (cur > nums[j]) {
        if (t[j] + 1 > t[i]) {
          lis[i] = j;
          t[i] = t[j] + 1;
        }
      }
    }
    if (t[i] > max_len) {
      max_len = t[i];
      last_idx = i;
    }
  }

  // * Build the LIS array
  vector<int> ans;
  ans.push_back(nums[last_idx]);
  while (last_idx != lis[last_idx]) {
    last_idx = lis[last_idx];
    ans.push_back(nums[last_idx]);
  }

  reverse(begin(ans), end(ans));
  return ans;
}


int main(void) {
  // * testcase 1
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

  // * testcase 2
  // vector<int> nums = {0, 1, 0, 3, 2, 3};

  // * testcase 3
  // vector<int> nums = {7, 7, 7, 7, 7, 7, 7};

  // * testcase 4
  // vector<int> nums = {13, 10, 4, 4};

  cout << "Input nums: ";
  printArr(nums);

  // int ans = bruteForce(nums);
  // int ans = lengthOfLIS(nums);
  int ans = lengthOfLIS2(nums);
  
  cout << "LIS Length: " << ans << endl;
  vector<int> lisArr = getLIS(nums);
  cout << "LIS: ";
  printArr(lisArr);

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 07-longest-increasing-subsequence.cpp -o output && ./output
