/*
 * Leetcode - 518
 * Coin Change II
 * 
 * You are given an integer array coins representing coins of different denominations and an integer 
 * amount representing a total amount of money.
 * 
 * Return the number of combinations that make up that amount. 
 * If that amount of money cannot be made up by any combination of the coins, return 0.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * The answer is guaranteed to fit into a signed 32-bit integer.
 * 
 * Example 1
 * input            : amount = 5, coins = [1,2,5]
 * output           : 4
 * Explanation      : there are four ways to make up the amount:
 *                    5=5
 *                    5=2+2+1
 *                    5=2+1+1+1
 *                    5=1+1+1+1+1
 *
 * Example 2
 * input            : amount = 3, coins = [2]
 * output           : 0
 * Explanation      : the amount of 3 cannot be made up just with coins of 2.
 * 
 * Example 3
 * input            : amount = 10, coins = [10]
 * output           : 1
 * 
 * https://leetcode.com/problems/coin-change-ii
 */

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

int dfs(int i, int amount, vector<int> &coins) {
  if (amount == 0)
    return 1;

  if (i >= coins.size())
    return 0;

  int res = 0;
  if (amount >= coins[i]) {
    res = dfs(i + 1, amount, coins);            // * skip
    res += dfs(i, amount - coins[i], coins); // * take
  }

  return res;
}


int dfs(int i, int amount, vector<int> &coins, vector<vector<int>> &dp) {
  if (amount == 0)
    return 1;

  if (i >= coins.size())
    return 0;

  if (dp[i][amount] != -1)
    return dp[i][amount];

  int res = 0;
  if (amount >= coins[i]) {
    res = dfs(i + 1, amount, coins, dp);            // * skip
    res += dfs(i, amount - coins[i], coins, dp); // * take
  }

  return dp[i][amount] = res;
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^N)
// * SPACE COMPLEXITY O(N)
int bruteForce(int amount, vector<int> &coins) {
  sort(begin(coins), end(coins));
  return dfs(0, amount, coins);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(N * target)
// * SPACE COMPLEXITY O(N * target)
int betterApproach(int amount, vector<int> &coins) {
  sort(begin(coins), end(coins));
  vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
  return dfs(0, amount, coins);
}


// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(N * target)
// * SPACE COMPLEXITY O(N * target)
int change(int amount, vector<int> &coins) {
  sort(begin(coins), end(coins));
  int n = coins.size();

  vector<vector<uint>> dp(n + 1, vector<uint>(amount + 1, 0));
  for (int i = 0; i <= n; ++i)
    dp[i][0] = 1;

  for (int i = n - 1; i >= 0; --i) {
    for (int a = 0; a <= amount; ++a) {
      if (a >= coins[i]) {
        dp[i][a] = dp[i + 1][a];
        dp[i][a] += dp[i][a - coins[i]];
      }
    }
  }

  // * Debugging
  // for (auto &vec : dp)
  //   printArr(vec);

  return dp[0][amount];
}


// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(N * amount)
// * SPACE COMPLEXITY O(amount)
int change2(int amount, vector<int> &coins) {
  sort(begin(coins), end(coins));
  vector<uint> dp(amount + 1, 0);
  dp[0] = 1;
  
  int n = coins.size();
  for (int i = n - 1; i >= 0; --i) {
    vector<uint> next_dp(amount + 1, 0);
    next_dp[0] = 1;
    for (int a = 1; a <= amount; ++a) {
      next_dp[a] = dp[a];
      if (a - coins[i] >= 0)
        next_dp[a] += next_dp[a - coins[i]];
    }
    dp = next_dp;
  }

  return dp[amount];
}

int main(void) {
  // * testcase 1
  int amount = 5;
  vector<int> coins = {1, 2, 5};

  // * testcase 2
  // int amount = 3;
  // vector<int> coins = {2};

  // * testcase 3
  // int amount = 0;
  // vector<int> coins = {1};

  cout << "Amount: " << amount << endl;
  cout << "Input coins: ";
  printArr(coins);
  
  // int ans = bruteForce(amount, coins);
  // int ans = betterApproach(amount, coins);
  int ans = change(amount, coins);
  // int ans = change2(amount, coins);

  cout << "number of combinations: " << ans << endl;
}

// * Run the code
// * g++ --std=c++17 03-coin-change-ii.cpp -o output && ./output

