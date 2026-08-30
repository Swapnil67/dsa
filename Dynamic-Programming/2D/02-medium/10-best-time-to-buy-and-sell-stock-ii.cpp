/*
 * Leetcode - 122
 * Best Time to Buy and Sell Stock II
 * 
 * You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
 * 
 * On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock 
 * at any time. However, you can sell and buy the stock multiple times on the same day, 
 * ensuring you never hold more than one share of the stock.
 * 
 * Find and return the maximum profit you can achieve.
 * 
 * 
 * Example 1    :
 * Input        : prices = [7,1,5,3,6,4]
 * Output       : 7
 * Explanation  : Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
 *                Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
 *                Total profit is 4 + 3 = 7.
 * 
 * Example 2    :
 * Input        : prices = [1,2,3,4,5]
 * Output       : 4
 * Explanation  : Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 * 
 * Example 3    :
 * Input        : prices = [7,6,4,3,1]
 * Output       : 0
 * Explanation  : There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 *
 * 
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
 * https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock-ii_630282
*/

// ! Amazon, Google, Meta, Uber, PhonePe, LinkedIn

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
int dfs(int i, bool bought, vector<int> &prices) {
  if (i == prices.size())
    return 0;

  int res = dfs(i + 1, bought, prices);
  if (bought) { // * already bought
    // * add to profit
    res = max(res, dfs(i + 1, false, prices) + prices[i]);
  } else {
    // * buying so deduct from profit
    res = max(res, dfs(i + 1, true, prices) - prices[i]);
  }
  return res;
}

// * With Memoization
int dfs(int i, bool bought, vector<int> &prices, vector<vector<int>> &dp) {
  if (i == prices.size())
    return 0;

  if (dp[i][bought] != -1)
    return dp[i][bought];

  int res = dfs(i + 1, bought, prices, dp);
  if (bought) { // * already bought
    // * add to profit
    res = max(res, dfs(i + 1, false, prices, dp) + prices[i]);
  } else {
    // * buying so deduct from profit
    res = max(res, dfs(i + 1, true, prices, dp) - prices[i]);
  }

  return dp[i][bought] = res;
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
int bruteForce(vector<int> &prices) {
  int n = prices.size();
  return dfs(0, false, prices); // * starting with false since we have not bought yet
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
int betterApproach(vector<int> &prices) {
  int n = prices.size();
  vector<vector<int>> dp(n + 1, vector<int>(2, -1));
  return dfs(0, false, prices, dp); // * starting with false since we have not bought yet
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
int maxProfit(vector<int> &prices) {
  int n = prices.size();

  // * dp[i][0] represents the max profit at day 'i' if we do NOT hold a stock (free to buy)
  // * dp[i][1] represents the max profit at day 'i' if we HOLD a stock (free to sell)
  // * Size is (n + 1) to naturally handle the base case at day 'n' (out of bounds) as 0 profit
  vector<vector<int>> dp(n + 1, vector<int>(2, 0));

  // * Iterate backwards from the last day to the first day
  for (int i = n - 1; i >= 0; --i) {

    // * Case 0: We do not hold a stock today. We can either:
    // * 1. Skip today: keep the profit from not holding a stock tomorrow -> dp[i + 1][0]
    // * 2. Buy today: pay today's price (-prices[i]) and move to the 'holding' state tomorrow -> dp[i + 1][1] - prices[i]
    dp[i][0] = max(dp[i + 1][0], dp[i + 1][1] - prices[i]);

    // * Case 1: We hold a stock today. We can either:
    // * 1. Skip today: keep the profit from holding a stock tomorrow -> dp[i + 1][1]
    // * 2. Sell today: gain today's price (+prices[i]) and move to the 'not holding' state tomorrow -> dp[i + 1][0] + prices[i]
    dp[i][1] = max(dp[i + 1][1], dp[i + 1][0] + prices[i]);
  }

  // * Return the max profit starting from day 0 without holding any stock initially
  return dp[0][0];
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Greedy
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
int maxProfitDP2(vector<int> &prices) {
  int profit = 0;
  for (int i = 1; i < prices.size(); i++) {
    if (prices[i] > prices[i - 1]) {
      profit += (prices[i] - prices[i - 1]);
    }
  }
  return profit;
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