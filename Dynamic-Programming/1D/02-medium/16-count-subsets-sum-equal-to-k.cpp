/*
 * Count Subsets Sum Equal To K
 *
 * You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.
 * 
 * Find the number of ways of selecting the elements from the array such that the sum of chosen elements
 * is equal to the target 'k'.
 * 
 * Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.
 * 
 * Example 1
 * input            : k = 5, nums = {1, 1, 4, 5};
 * output           : 3
 * Explanation      : subsets sum {1,4}, {1, 4} & {5} equals 5
 * 
 * Example 2
 * input            : k = 4, nums = {0, 1, 3};
 * output           : 2
 * Explanation      : subsets sum {1,3}, {0, 1, 2} equals 4
 * 
 * https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
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
int dfs(int i, int k, vector<int> &nums) {
  if (i < 0)
    return k == 0 ? 1 : 0;

  int not_take = dfs(i - 1, k, nums);
  int take = 0;
  if (k >= nums[i])
  {
    take = dfs(i - 1, k - nums[i], nums);
  }
  return (not_take + take);
}

// * With Memoization
int dfs(int i, int k, vector<int>& nums, vector<vector<int>> &dp) {
  if (dp[i][k] != -1)
    return dp[i][k];

  if (i < 0)
    return k == 0 ? 1 : 0;

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
      if (t >= nums[i]) {
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

  // * Base case initialization
  if (nums[0] == 0) {
    dp[0] = 2; // * Can either pick or omit the 0
  } else {
    dp[0] = 1; // * Only 1 way to make 0 (empty set)
    if (nums[0] <= k) {
      dp[nums[0]] = 1; // * 1 way to make nums[0]
    }
  }

  int M = (int)(1e9 + 7);
  for (int i = 1; i < n; ++i) {
    for (int t = k; t >= 0; --t) {
      int not_take = dp[t];
      int take = 0;
      if (t >= nums[i]) {
        take = dp[t - nums[i]];
      }
      dp[t] = (not_take + take) % M;
    }
  }

  return dp[k] % M;
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
  // int k = 4;
  // vector<int> nums = {0, 1, 3};

  // * testcase 5
  int k = 10;
  vector<int> nums = {5, 2, 3, 10, 6, 8};

  cout << "k: " << k << endl;
  cout << "Input nums: ";
  printArr(nums);

  int ans = bruteForce(nums, k);
  // int ans = betterApproach(nums, k);
  // int ans = countSubsetSumEqualsK(nums, k);
  // int ans = countSubsetSumEqualsKDP2(nums, k);
  
  cout << "Number of subsets: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 16-count-subsets-sum-equal-to-k.cpp -o output && ./output

/*
? Intuition behind why are we using forward loop

* Let’s make it even simpler. Imagine you have a piggy bank (your dp array) and exactly one ₹5 coin in your hand.
* You want to track what total amounts of money you can make.
* Initially, your piggy bank tracks two amounts:

* ₹0: Yes (you can always have nothing) -> dp[0] = 1
* ₹5: No (you don’t have it in the bank yet) -> dp[5] = 0
* ₹10: No -> dp[10] = 0

------------------------------
* ## ❌ What happens if you go Forward (0 to 10)?
* You walk through the amounts from smallest to largest, deciding if your one ₹5 coin can help you reach that amount.

   * 1. At ₹5: You look back at ₹0. Since you can make ₹0, you add your ₹5 coin.
    * -> Result: Your bank now says "Yes, I can make ₹5!" (dp[5] = 1).
   * 2. At ₹10: You look back at ₹5. Your bank just said a second ago that ₹5 is possible. So you say, "Great! I'll add my ₹5 coin to that ₹5 to make ₹10!"
    * -> Result: Your bank now says "Yes, I can make ₹10!" (dp[10] = 1).
   
! The Bug: You only had one ₹5 coin in your hand, but because you updated the ₹5 slot before checking the ₹10 slot,
! you accidentally used that same coin twice!

* ------------------------------
* ## ✅ What happens if you go Backward (10 down to 0)?
* You walk through the amounts in reverse, from largest to smallest.

   * 1. At ₹10: You look back at ₹5. Is ₹5 currently possible? No (dp[5] = 0). You cannot use your coin here.
    * -> Result: ₹10 stays No (dp[10] = 0).
   * 2. At ₹5: You look back at ₹0. Is ₹0 possible? Yes (dp[0] = 1). You add your ₹5 coin here.
    * -> Result: ₹5 becomes Yes (dp[5] = 1).
   
* Why this works: By checking ₹10 first, it only saw the old, untouched state of the bank from before your 
* coin was introduced. The coin is safely used exactly once.

* ------------------------------
* ## 💡 Golden Rule

* Forward loop: You see your own updates as you move along. (Great if you have infinite copies of an item).
* Backward loop: You only see the "past" version of the array to your left. (Required when you have only one copy of each item).
*/