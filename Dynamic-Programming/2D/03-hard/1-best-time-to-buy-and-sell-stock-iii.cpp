/*
 * Leetcode - 122
 * Best Time to Buy and Sell Stock III
 * 
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * 
 * Find the maximum profit you can achieve. You may complete at most two transactions.
 * 
 * Note: You may not engage in multiple transactions simultaneously 
 * (i.e., you must sell the stock before you buy again).
 * 
 * Find and return the maximum profit you can achieve.
 * 
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 * https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock-iii_1071012
*/

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
int dfs(int i, bool buy, int cap, vector<int> &prices) {
  if (i == prices.size() || cap == 0)
    return 0;

  // * Option 1: Skip today
  int res = dfs(i + 1, buy, cap, prices);
  if (buy) {
    // * Option 2: Buy today (Pay money now, move to sell state)
    res = max(res, dfs(i + 1, false, cap, prices) - prices[i]);
  } else {
    // * Option 2: Sell today (Get money now)
    // * when selling we decrease no of transaction (i.e cap)
    res = max(res, dfs(i + 1, true, cap - 1, prices) + prices[i]);
  }

  return res;
}

// * With Memoization
int dfs(int i, bool buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp) {
  if (i == prices.size() || cap == 0)
    return 0;

  if (dp[i][buy][cap] != -1)
    return dp[i][buy][cap];

  // * Option 1: Skip today
  int res = dfs(i + 1, buy, cap, prices, dp);
  if (buy) {
    // * Option 2: Buy today (Pay money now, move to sell state)
    res = max(res, dfs(i + 1, false, cap, prices, dp) - prices[i]);
  } else {
    // * Option 2: Sell today (Get money now, decrease remaining transactions)
    // * when selling we decrease no of transaction (i.e cap)
    res = max(res, dfs(i + 1, true, cap - 1, prices, dp) + prices[i]);
  }

  return dp[i][buy][cap] = res;
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
int bruteForce(vector<int> &prices) {
  int cap = 2; // * max no of transactions
  return dfs(0, true, cap, prices);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
int betterApproach(vector<int> &prices) {
  int n = prices.size();
  int cap = 2; // * max no of transactions
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
  return dfs(0, true, cap, prices, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
int maxProfit(vector<int> &prices) {
  int n = prices.size();
  int cap = 2;
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
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
  return dp[0][1][2];
}

int main(void) {
  // * testcase 1
  vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

  // * testcase 2
  // vector<int> prices = {1, 2, 3, 4, 5};

  // * testcase 3
  // vector<int> prices = {7, 6, 4, 3, 1};

  // * testcase 4
  // vector<int> prices = {2, 1, 4, 5, 2, 9, 7};

  cout << "Prices: ";
  printArr(prices);

  // int ans = bruteForce(prices);
  // int ans = betterApproach(prices);
  int ans = maxProfit(prices);

  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 1-best-time-to-buy-and-sell-stock-iii.cpp -o output && ./output