/*
 * Best Time to Buy and Sell Stock
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day
 * in the future to sell that stock.

 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 * 
 * Example 1:
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * 
 * Example 2:
 * Input: prices = [7,6,4,3,1]
 * Output: 0

 * https://www.naukri.com/code360/problems/stocks-are-profitable_893405
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/

#include <vector>
#include <climits>
#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int getMinBetweenGivenIndexes(std::vector<int> arr, int buy_max) {
  int min = INT_MAX;
  for (int i = 0; i <= buy_max; ++i) {
    min = std::min(arr[i], min);
  }
  return min;
}

// * ------------------------- APPROACH BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> prices) {
  int n = prices.size();
  int max_profit = 0;
  for (int i = n - 1; i >= 0; --i) {
    int sell = prices[i];
    int buy = getMinBetweenGivenIndexes(prices, i - 1);
    max_profit = std::max(max_profit, sell - buy);
  }
  return max_profit;
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int optimalApproach(std::vector<int> prices) {
  int n = prices.size();

  int mini = prices[0], max_profit = 0;
  for (int i = 1; i < n; ++i) {
    // * Find the profit selling on current day
    int profit = prices[i] - mini;
    // * Find the max profit
    max_profit = std::max(max_profit, profit);
    // * Update the buying day
    mini = std::min(mini, prices[i]);
  }

  return max_profit;
}

int main() {
  // * testcase 1
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};
  // * testcase 1
  // std::vector<int> prices = {7, 6, 4, 3, 1};

  std::cout << "Stock Prices" << std::endl;
  printArr(prices);
  // int maxProfit = bruteForce(prices);
  int max_profit = optimalApproach(prices);
  printf("Max Profit from buy & sell is: %d\n", max_profit);
  return 0;
}

// * run the code
// * $CXX --std=c++20 07-best-time-to-buy-sell-stock-1.cpp -o output && ./output