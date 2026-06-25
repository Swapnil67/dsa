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
int dfs(int i, bool buying, vector<int> &prices) {
  if (i >= prices.size())
    return 0;

  int profit = 0;
  if (buying) {
    profit = max((dfs(i + 1, false, prices) - prices[i]),
                 dfs(i + 1, buying, prices));
  } else {
    profit = max((dfs(i + 1, true, prices) + prices[i]),
                 dfs(i + 1, buying, prices));
  }

  return profit;
}

// * With Memoization
int dfs(int i, bool buying, vector<int> &prices, vector<vector<int>> &dp) {
  if (i >= prices.size())
    return 0;

  if (dp[i][buying] != -1)
    return dp[i][buying];

  int profit = 0;
  if (buying) {
    profit = max((dfs(i + 1, false, prices, dp) - prices[i]),
                 dfs(i + 1, buying, prices, dp));
  } else {
    profit = max((dfs(i + 1, true, prices, dp) + prices[i]),
                 dfs(i + 1, buying, prices, dp));
  }

  return dp[i][buying] = profit;
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
int bruteForce(vector<int> &prices) {
  int n = prices.size();
  return dfs(0, true, prices);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
int betterApproach(vector<int> &prices) {
  int n = prices.size();
  vector<vector<int>> dp(n + 1, vector<int>(2, -1));
  return dfs(0, true, prices, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
int maxProfit(vector<int> &prices) {
  int n = prices.size();
  vector<vector<int>> dp(n + 1, vector<int>(2, 0));
  for (int i = n - 1; i >= 0; --i) {
    for (int buying = 1; buying >= 0; --buying) {
      if (buying == 1) {
        dp[i][buying] = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
      } else {
        dp[i][buying] = max(dp[i + 1][1] + prices[i], dp[i + 1][0]);
      }
    }
  }

  for (auto &vec : dp)
    printArr(vec);

  return dp[0][1];
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
int maxProfitDP2(vector<int> &prices) {
  int n = prices.size();
  int cur_buy = 0, cur_sell = 0;
  int next_buy = 0, next_sell = 0;
  for (int i = n - 1; i >= 0; --i) {
    cur_buy = max(next_sell - prices[i], next_buy);
    cur_sell = max(next_buy + prices[i], next_sell);
    next_buy = cur_buy;
    next_sell = cur_sell;
  }

  return cur_buy;
}

int main(void) {
  // * testcase 1
  vector<int> prices = {7, 1, 5, 3, 6, 4};

  // * testcase 2
  // vector<int> prices = {1, 2, 3, 4, 5};

  // * testcase 3
  // vector<int> prices = {7, 6, 4, 3, 1};

  cout << "Prices: ";
  printArr(prices);

  // int ans = bruteForce(prices);
  // int ans = betterApproach(prices);
  // int ans = maxProfit(prices);
  int ans = maxProfitDP2(prices);

  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 10-best-time-to-buy-and-sell-stock-ii.cpp -o output && ./output