/*
 * Leetcode - 714
 * Best Time to Buy and Sell Stock with Transaction Fee
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
 * Example 1    :
 * Input        : prices = [1,3,2,8,4,9], fee = 2
 * Output       : 8
 * Explanation  : The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 * 
 * Example 2    :
 * Input        : prices = [1,3,7,5,10,3], fee = 3
 * Output       : 6
 * Explanation  : The total profit is ((10 - 1) - 3) = 6
 * 
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 * https://www.geeksforgeeks.org/problems/buy-stock-with-transaction-fee/1
 * https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock-with-transaction-fee_3118974
*/

// ! Amazon, Google, Meta, Uber, IBM

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
int dfs(int i, bool buying, vector<int> &prices, int &fee) {
	if (i >= prices.size())
		return 0;

	// * Option 1: Skip today. Move to day i + 1 keeping the exact same state
	int res = dfs(i + 1, buying, prices, fee);

	if (buying) {
		// * Option 2 (When looking to buy): Buy today.
		// * Subtract today's stock price and move to day i + 1 with buying set to false
		res = max(res, dfs(i + 1, false, prices, fee) - prices[i]);
	}
	else {
		// * Option 2 (When holding a stock): Sell today.
		// * Gain today's stock price, subtract the transaction fee (-fee),
		// * and move to day i + 1 where we are free to buy again (buying = true)
		res = max(res, (dfs(i + 1, true, prices, fee) + prices[i]) - fee);
	}
	return res;
}

// * With Memoization
int dfs(int i, bool buying, vector<int> &prices, int &fee, vector<vector<int>> &dp) {
	// * Base Case: If we pass the last day, no more transactions can occur, profit is 0
	if (i >= prices.size())
		return 0;

	if (dp[i][buying] != -1) // * cache
		return dp[i][buying];

	// * Option 1: Skip today. Move to day i + 1 keeping the exact same state
	int res = dfs(i + 1, buying, prices, fee, dp);

	if (buying) {
		// * Option 2 (When looking to buy): Buy today.
		// * Subtract today's stock price and move to day i + 1 with buying set to false
		res = max(res, dfs(i + 1, false, prices, fee, dp) - prices[i]);
	}
	else {
		// * Option 2 (When holding a stock): Sell today.
		// * Gain today's stock price, subtract the transaction fee (-fee),
		// * and move to day i + 1 where we are free to buy again (buying = true)
		res = max(res, (dfs(i + 1, true, prices, fee, dp) + prices[i]) - fee);
	}

	return dp[i][buying] = res;
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
int bruteForce(vector<int> &prices, int fee) {
  int n = prices.size();
  return dfs(0, true, prices, fee);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
int betterApproach(vector<int> &prices, int fee) {
	int n = prices.size();
	// * dp table initialized to -1 to track unvisited states
	// * dp[i][1] -> Max profit from day 'i' if we are looking to BUY
	// * dp[i][0] -> Max profit from day 'i' if we are looking to SELL
	vector<vector<int>> dp(n + 1, vector<int>(2, -1));
	return dfs(0, true, prices, fee, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
int maxProfit(vector<int> &prices, int fee) {
	int n = prices.size();
	// * dp[i][0]: Not holding stock
	// * dp[i][1]: Holding stock
	vector<vector<int>> dp(n + 1, vector<int>(2, 0));
	for (int i = n - 1; i >= 0; --i) {
		// * Option 1: Keep not holding OR Buy today (pay price)
		dp[i][0] = max(dp[i + 1][0], dp[i + 1][1] - prices[i]);
		// * Option 2: Keep holding OR Sell today (gain price, pay fee)
		dp[i][1] = max(dp[i + 1][1], dp[i + 1][0] + (prices[i] - fee));
	}
	return dp[0][0];
}

int main(void) {
  // * testcase 1
	// int fee = 2;
	// vector<int> prices = {1, 3, 2, 8, 4, 9};
	
	// * testcase 2
	int fee = 3;
	vector<int> prices = {1, 3, 7, 5, 10, 3};

  cout << "Fee: " << fee << endl;;
  cout << "Prices: ";
  printArr(prices);

  // int ans = bruteForce(prices, fee);
  int ans = betterApproach(prices, fee);
  // int ans = maxProfit(prices, fee);

  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 12-best-time-to-buy-and-sell-stock-with-transaction-fee.cpp -o output && ./output
