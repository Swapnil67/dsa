/*
 * Leetcode - 309
 * Best Time to Buy and Sell Stock with Cooldown
 * 
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * 
 * Find the maximum profit you can achieve. You may complete as many transactions as you like 
 * (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
 * 
 * After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
 * 
 * Note: You may not engage in multiple transactions simultaneously
 * (i.e., you must sell the stock before you buy again).
 * 
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
 * https://neetcode.io/problems/buy-and-sell-crypto-with-cooldown
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
  // * Base Case: If we reach or pass the last day, no more transactions can be made
  if (i >= prices.size())
    return 0;

  // * Option 1: Cooldown/Skip today. 
  // * We do nothing today, keep the same state (buying or selling), and move to day i + 1
  int cooldown = dfs(i + 1, buying, prices);
  
  if (buying) {
    // * Option 2 (When looking to buy): Buy today.
    // * Subtract today's price (-prices[i]) and move to day i + 1 with buying set to false
    int buy = dfs(i + 1, false, prices) - prices[i];
    
    // * Cache and return the maximum profit between buying today or skipping today
    return max(buy, cooldown);
  }
  
  // * Option 2 (When holding a stock): Sell today.
  // * Add today's price (+prices[i]). Due to the mandatory 1-day cooldown after a sell,
  // * we must skip the next day and jump directly to day i + 2 to buy again
  int sell = dfs(i + 2, true, prices) + prices[i];
  
  return max(sell, cooldown);
}

// * With Memoization
int dfs(int i, bool buying, vector<int> &prices, vector<vector<int>> &dp) {
  // * Base Case: If we reach or pass the last day, no more transactions can be made
  if (i >= prices.size())
    return 0;

  // * Memoisation: Return the result if we have already calculated this state
  if (dp[i][buying] != -1)
    return dp[i][buying];

  // * Option 1: Cooldown/Skip today. 
  // * We do nothing today, keep the same state (buying or selling), and move to day i + 1
  int cooldown = dfs(i + 1, buying, prices, dp);
  
  if (buying) {
    // * Option 2 (When looking to buy): Buy today.
    // * Subtract today's price (-prices[i]) and move to day i + 1 with buying set to false
    int buy = dfs(i + 1, false, prices, dp) - prices[i];
    
    // * Cache and return the maximum profit between buying today or skipping today
    return dp[i][buying] = max(buy, cooldown);
  }
  
  // * Option 2 (When holding a stock): Sell today.
  // * Add today's price (+prices[i]). Due to the mandatory 1-day cooldown after a sell,
  // * we must skip the next day and jump directly to day i + 2 to buy again
  int sell = dfs(i + 2, true, prices, dp) + prices[i];
  
  return dp[i][buying] = max(sell, cooldown);
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

  // * Size is (n + 2) because a sell on day 'i' looks up day 'i + 2' due to cooldown.
  // * dp[i][0] -> Max profit starting at day 'i' if we do NOT hold a stock (free to buy)
  // * dp[i][1] -> Max profit starting at day 'i' if we HOLD a stock (free to sell)
  vector<vector<int>> dp(n + 2, vector<int>(2, 0));

  // * Iterate backwards from the last day to the first day
  for (int i = n - 1; i >= 0; --i) {

    // * Case 0: Free to buy. We take the max of:
    // * 1. Skipping today: stay free to buy tomorrow -> dp[i + 1][0]
    // * 2. Buying today: spend prices[i], must sell tomorrow onwards -> dp[i + 1][1] - prices[i]
    dp[i][0] = max(dp[i + 1][0], dp[i + 1][1] - prices[i]);

    // * Case 1: Free to sell. We take the max of:
    // * 1. Skipping today: stay holding the stock tomorrow -> dp[i + 1][1]
    // * 2. Selling today: gain prices[i], must skip tomorrow due to 1-day cooldown,
    // *    so we are free to buy again on day 'i + 2' -> dp[i + 2][0] + prices[i]
    dp[i][1] = max(dp[i + 1][1], dp[i + 2][0] + prices[i]);
  }

  // * Return the maximum profit starting from Day 0 without holding any stock initially
  return dp[0][0];
}

int main(void) {
  // * testcase 1
  // vector<int> prices = {1, 2, 3, 0, 2};

  // * testcase 2
  // vector<int> prices = {1};

  // * testcase 3
  vector<int> prices = {1, 3, 4, 0, 4};

  cout << "Prices: ";
  printArr(prices);

  // int ans = bruteForce(prices);
  // int ans = betterApproach(prices);
  int ans = maxProfit(prices);

  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 11-best-time-to-buy-and-sell-stock-with-cooldown.cpp -o output && ./output

/*
* Tree Diagram
*                             [1, 2, 3, 0, 2]
*                                 (0, T)
*                             /            \
*                  Buy (-1) /                \ Cooldown (+0)
*                         /                    \
*                     (1, F)                  (1, T)
*                    /      \                /      \
*         Sell (+2) /        \ Cool        /          \
*                  /          \           /            \
*              (3, T)        (2, F)    (2, T)        (2, T) [Duplicate]
*              /    \         /   \     /    \       ...
*    Buy (0)  /      \ Cool  /     \   /      \ 
*            /        \     /       \ /        \ 
*        (4, F)      (4,T) (4,T)  (3,F)(3,T)  (3, T)
*        /    \       |     |     /   \  |      |
*  Sell /      \Cool  |     | Sell/    \ |      |
*  (+2)/        \(+0) |     | (+0)/     \|      |
*    (6,T)     (5,F) (5,T) (5,T)(5,T)  (4,F)  (4, T)
*   [Base]    [Base][Base][Base][Base]  ...    ...
*   Ret:0     Ret:0  Ret:0 Ret:0 Ret:0
* 
* 
*/