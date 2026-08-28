/*
 * Leetcode - 377
 * Combination Sum IV
 *
 * Given an array of distinct integers nums and a target integer target, return the number of possible 
 * combinations that add up to target.
 * 
 * The test cases are generated so that the answer can fit in a 32-bit integer.
 *
 * Example 1
 * input            : nums = [1,2,3], target = 4
 * output           : 7
 * Explanation      : 
 *
 * Example 2
 * input            : nums = [9], target = 3
 * output           : 0
 * Explanation      :
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 * https://neetcode.io/problems/combination-sum-iv/question
 */

// ! Meta, Snapchat

#include <vector>
#include <iostream>
#include <algorithm>

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

// * without Memoization
int dfs(vector<int> &nums, int k) {
  if (k == 0)
    return 1;

  int res = 0;
  for (int num : nums) {
    if (k < num) // * early exit
      break;
    res += dfs(nums, k - num);
  }

  return res;
}

// * with Memoization
int dfs(vector<int> &nums, int k, unordered_map<int, int> &memo) {
  if (memo.count(k))
    return memo[k];

  int ways = 0;
  for (auto &num : nums) {
    if (k < num)
      break;
    ways += dfs(nums, k - num, memo);
  }

  return memo[k] = ways;
}


// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^t)
// * SPACE COMPLEXITY O(t)
int bruteForce(vector<int>& nums, int k) {
  sort(begin(nums), end(nums));
  return dfs(nums, k);
}


// * ------------------------- Approach: Better Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(N * t)
// * SPACE COMPLEXITY O(t)
int combinationSum4(vector<int>& nums, int k) {
  sort(begin(nums), end(nums));
  // * memo[t] = number of ways to sum to value t
  unordered_map<int, int> memo;
  memo[0] = 1;
  return dfs(nums, k, memo);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * BOTTOM UP 
// * TIME COMPLEXITY O(N * target)
// * SPACE COMPLEXITY O(N * target)
int combinationSum4(vector<int>& nums, int k) {
  // * dp[t] stores the number of unique combinations that sum up to t
  vector<unsigned int> dp(k + 1, 0); 
  
  // * Base case: There is exactly 1 way to make a sum of 0 (using an empty set)
  dp[0] = 1; 
  
  // * Iterate through all target values from 1 to k
  for (int t = 1; t <= k; ++t) {
    // * Try every number as the LAST element in the combination sequence
    for (int num : nums) {
      if (t >= num) {
        dp[t] += dp[t - num];
      }
    }
  }
  
  return dp[k];
}

int main(void) {
  // * testcase 1
  int target = 4;
  vector<int> nums = {1, 2, 3};

  cout << "target: " << target << endl;
  cout << "Nums: ";
  printArr(nums);

  int ans = bruteForce(nums, target);
  // bool ans = combinationSum4(nums);

  cout << "possible combinations: " << ans << endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++17 29-combination-sum-iv.cpp -o output && ./output


/*
* ---------- DRY RUN ----------
* To keep the dry run easy to follow, we will track the state of our 1D array,
* dp, which has a size of 5 (indices 0 to 4) for target = 4.

* ## Initial State

* dp[0] = 1 (Base case: 1 way to make a sum of 0—by picking nothing)
* dp = [1, 0, 0, 0, 0]
* ------------------------------

* ## Step-by-Step Execution ## 

* ## t = 1 (Finding ways to make sum 1)
* We loop through each number in nums = [1, 2, 3]:

* num = 1: 1 >= 1 → dp[1] += dp[1 - 1] → dp[1] += dp[0] ($0 + 1 = \mathbf{1}$)
* num = 2: 1 >= 2 is False.
* num = 3: 1 >= 3 is False.
* Result: dp[1] = 1 (Valid sequence: [1])

* ## t = 2 (Finding ways to make sum 2)
* We loop through each number in nums = [1, 2, 3]:

* num = 1: 2 >= 1 → dp[2] += dp[2 - 1] → dp[2] += dp[1] ($0 + 1 = \mathbf{1}$)
* num = 2: 2 >= 2 → dp[2] += dp[2 - 2] → dp[2] += dp[0] ($1 + 1 = \mathbf{2}$)
* num = 3: 2 >= 3 is False.
* Result: dp[2] = 2 (Valid sequences: [1, 1], [2])

* ## t = 3 (Finding ways to make sum 3)
* We loop through each number in nums = [1, 2, 3]:

* num = 1: 3 >= 1 → dp[3] += dp[3 - 1] → dp[3] += dp[2] ($0 + 2 = \mathbf{2}$)
* num = 2: 3 >= 2 → dp[3] += dp[3 - 2] → dp[3] += dp[1] ($2 + 1 = \mathbf{3}$)
* num = 3: 3 >= 3 → dp[3] += dp[3 - 3] → dp[3] += dp[0] ($3 + 1 = \mathbf{4}$)
* Result: dp[3] = 4 (Valid sequences: [1, 1, 1], [2, 1], [1, 2], [3])

* ## t = 4 (Finding ways to make final sum 4)
* We loop through each number in nums = [1, 2, 3]:

* num = 1: 4 >= 1 → dp[4] += dp[4 - 1] → dp[4] += dp[3] ($0 + 4 = \mathbf{4}$)
* num = 2: 4 >= 2 → dp[4] += dp[4 - 2] → dp[4] += dp[2] ($4 + 2 = \mathbf{6}$)
* num = 3: 4 >= 3 → dp[4] += dp[4 - 3] → dp[4] += dp[1] ($6 + 1 = \mathbf{7}$)
* Result: dp[4] = 7

* ------------------------------
* ## Final Table Overview

* | t (Target) | dp[t] | Combinations Found |
* |---|---|---|
* | 0 | 1 | [] |
* | 1 | 1 | [1] |
* | 2 | 2 | [1,1], [2] |
* | 3 | 4 | [1,1,1], [2,1], [1,2], [3] |
* | 4 | 7 | [1,1,1,1], [2,1,1], [1,2,1], [1,1,2], [2,2], [3,1], [1,3] |

* The function ends and returns 7.
*/