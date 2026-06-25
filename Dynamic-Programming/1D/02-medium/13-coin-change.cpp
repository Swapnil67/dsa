/*
 * Leetcode - 322 
 * Coin Change
 * 
 * You are given an integer array coins representing coins of different denominations and an integer
 * amount representing a total amount of money.
 * 
 * Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be 
 * made up by any combination of the coins, return -1.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * 
 * Example 1   :
 * Input       : coins = [1,2,5], amount = 11
 * Output      : 3
 * Explanation : 11 = 5 + 5 + 1
 * 
 * Example 2   :
 * Input       : coins = [2], amount = 3
 * Output      : -1
 * 
 * Example 3   :
 * Input       : coins = [1], amount = 0
 * Output      : 0
 * 
 * https://leetcode.com/problems/coin-change/
 * https://www.naukri.com/code360/problems/minimum-elements_3843091
*/

// ! Amazon, Meta, Paypal, Microsoft, Flipkart, Tiktok, Visa

// * 0/1 Knapsack DP on subsequences 

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

// * Recursion Without Memoization
int solve(int amount, vector<int> &coins) {
  if (amount == 0)
    return 0;

  int res = 1e9;
  for (auto &coin : coins) {
    if (amount - coin >= 0) {
      res = min(res, 1 + solve(amount - coin, coins));
    }
  }
  return res;
}

// * Recursion With Memoization
int solve(int amount, vector<int> &coins, vector<int> &dp) {
  if (amount == 0)
    return 0;

  if (dp[amount] != -1)
    return dp[amount];

  int res = 1e9;
  for (auto &coin : coins) {
    if (amount - coin >= 0) {
      res = min(res, 1 + solve(amount - coin, coins, dp));
    }
  }
  return dp[amount] = res;
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * 'n' - length of coins, 't' - given amount
// * TIME COMPLEXITY O(n^t) // * since here our max tree height is not 'n' it's 'amount' aka 't'
// * SPACE COMPLEXITY O(t)
int bruteForce(int amount, vector<int> &coins) {
  return solve(amount, coins);
}

// * ------------------------- Approach 2: Better Approach -------------------------
// * Recursion + Memoization (Top Down)
// * TIME COMPLEXITY O(n * t)
// * SPACE COMPLEXITY O(n * t)
int betterApproach(int amount, vector<int> &coins) {
  int n = coins.size();
  vector<int> dp(amount + 1, -1);
  int min_coins = solve(amount, coins, dp);
  return min_coins >= 1e9 ? -1 : min_coins;
}

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * Bottom Up 
// * 'n' - length of coins, 't' - given amount
// * TIME COMPLEXITY O(n * t)
// * SPACE COMPLEXITY O(n * t)
int coinChange(vector<int> &coins, int amount) {
  int n = coins.size();
  vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
  for (int t = 0; t <= amount; ++t) {
    if (t % coins[0] == 0)
      dp[0][t] = t / coins[0];
    else
      dp[0][t] = 1e9;
  }

  for (int i = 1; i < n; ++i) {
    for (int t = 0; t <= amount; ++t) {
      int not_take = dp[i - 1][t];
      int take = 1e9;
      if (t >= coins[i]) {
        take = 1 + dp[i][t - coins[i]];
      }
      dp[i][t] = min(not_take, take);
    }
  }

  for (auto &vec : dp)
    printArr(vec);

  return dp[n - 1][amount] > amount ? -1 : dp[n - 1][amount];
}

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * Instead of asking “how many coins to make this amount?” recursively, we build answers from smaller 
// * amounts to larger ones.
// * Bottom Up - Space Optimized
// * 'n' - length of coins, 't' - given amount
// * TIME COMPLEXITY O(n * t)
// * SPACE COMPLEXITY O(t)
int coinChange(int amount, vector<int> &coins) {
  int n = coins.size();
  vector<int> dp(amount + 1, amount + 1);
  dp[0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= amount; ++j) {
      if (j >= coins[i]) {
        dp[j] = min(dp[j], dp[j - coins[i]] + 1);
      }
    }
  }

  return dp[amount] > amount ? -1 : dp[amount];
}

int main(void) {
  // * testcase 1
  // int amount = 11;
  // vector<int> coins = {1, 2, 5};

  // * testcase 2
  // int amount = 3;
  // vector<int> coins = {2};

  // * testcase 3
  int amount = 0;
  vector<int> coins = {1};

  cout << "Amount: " << amount << endl;
  cout << "Input coins: ";
  printArr(coins);
  
  // int ans = bruteForce(amount, coins);
  // int ans = betterApproach(amount, coins);
  int ans = coinChange(amount, coins);

  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 13-coin-change.cpp -o output && ./output
