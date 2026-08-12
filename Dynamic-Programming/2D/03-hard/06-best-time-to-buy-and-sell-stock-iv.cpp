/*
 * Leetcode - 122
 * Best Time to Buy and Sell Stock IV
 * 
 * You are given an integer array prices where prices[i] is the price of a given stock on the ith day, 
 * and an integer k.
 * 
 * Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most 
 * k times and sell at most k times.
 * 
 * Note: You may not engage in multiple transactions simultaneously 
 * (i.e., you must sell the stock before you buy again).
 * 
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
*/

// ! Same as Best Time to Buy and Sell Stock III

// ! Amazon, Google, Meta, Uber

#include <vector>
#include <numeric>
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

// * Without Memoization
int dfs(int i, bool buy, int k, vector<int> &prices) {
  if (i == prices.size() || k == 0)
    return 0;

  // * Option 1: Skip today
  int res = dfs(i + 1, buy, k, prices);
  if (buy) {
    // * Option 2: Buy today (Pay money now, move to sell state)
    res = max(res, dfs(i + 1, false, k, prices) - prices[i]);
  } else {
    // * Option 2: Sell today (Get money now)
    // * when selling we decrease no of transaction (i.e k)
    res = max(res, dfs(i + 1, true, k - 1, prices) + prices[i]);
  }

  return res;
}

// * With Memoization
int dfs(int i, bool buy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp) {
  if (i == prices.size() || k == 0)
    return 0;

  if (dp[i][buy][k] != -1)
    return dp[i][buy][k];

  // * Option 1: Skip today
  int res = dfs(i + 1, buy, k, prices, dp);
  if (buy) {
    // * Option 2: Buy today (Pay money now, move to sell state)
    res = max(res, dfs(i + 1, false, k, prices, dp) - prices[i]);
  } else {
    // * Option 2: Sell today (Get money now, decrease remaining transactions)
    // * when selling we decrease no of transaction (i.e k)
    res = max(res, dfs(i + 1, true, k - 1, prices, dp) + prices[i]);
  }

  return dp[i][buy][k] = res;
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
int bruteForce(int k, vector<int> &prices) {
  return dfs(0, true, k, prices);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
int betterApproach(int k, vector<int> &prices) {
  int n = prices.size();
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(3, -1)));
  return dfs(0, true, k, prices, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
int maxProfit(int k, vector<int> &prices) {
  int n = prices.size();
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k, 0)));
  for (int i = n - 1; i >= 0; --i) {
    for (int cap = 1; cap <= 2; ++cap) {
      // * Sell logic (decrease no of transaction, i.e cap)
      dp[i][0][cap] =
          max(dp[i + 1][0][cap], dp[i + 1][1][cap - 1] + prices[i]);

      // * Buy logic
      dp[i][1][cap] =
          max(dp[i + 1][1][cap], dp[i + 1][0][cap] - prices[i]);
    }
  }
  return dp[0][1][k];
}

int main(void) {
  // * testcase 1
  // int k = 2;
  // vector<int> prices = {2, 4, 1};

  // * testcase 2
  int k = 2;
  vector<int> prices = {3, 2, 6, 5, 0, 3};

  cout << "k: " << k << endl;
  cout << "Prices: ";
  printArr(prices);

  int ans = bruteForce(k, prices);
  // int ans = betterApproach(k, prices);
  // int ans = maxProfit(k, prices);

  cout << "Answer: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-best-time-to-buy-and-sell-stock-iv.cpp -o output && ./output