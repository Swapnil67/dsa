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
  if (i >= prices.size())
    return 0;

  int cooldown = dfs(i + 1, buying, prices);
  if (buying) {
    int buy = dfs(i + 1, false, prices) - prices[i];
    return max(buy, cooldown);
  } else {
    int sell = dfs(i + 2, true, prices) + prices[i];
    return max(sell, cooldown);
  }
}

// * With Memoization
int dfs(int i, bool buying, vector<int> &prices, vector<vector<int>> &dp) {
  if (i >= prices.size())
    return 0;

  if (dp[i][buying] != -1)
    return dp[i][buying];

  int cooldown = dfs(i + 1, buying, prices, dp);
  if (buying) {
    int buy = dfs(i + 1, false, prices, dp) - prices[i];
    return dp[i][buying] = max(buy, cooldown);
  }
  else {
    int sell = dfs(i + 2, true, prices, dp) + prices[i];
    return dp[i][buying] = max(sell, cooldown);
  }
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
        int buy = dp[i + 1][0] - prices[i];
        int cooldown = dp[i + 1][1];
        dp[i][1] = max(buy, cooldown);
      } else {
        int sell = (i + 2 < n) ? dp[i + 2][1] + prices[i] : prices[i];
        int cooldown = dp[i + 1][0];
        dp[i][0] = max(sell, cooldown);
      }
    }
  }

  return dp[0][1];
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
int maxProfitDP2(vector<int> &prices) {
  return 0;
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

  int ans = bruteForce(prices);
  // int ans = betterApproach(prices);
  // int ans = lastStoneWeightII(prices);
  // int ans = lastStoneWeightIIDP2(prices);

  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 12-best-time-to-buy-and-sell-stock-with-cooldown.cpp -o output && ./output

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