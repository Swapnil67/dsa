/*
 * Leetcode - 121
 * Best Time to Buy and Sell Stock - i
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day
 * in the future to sell that stock.

 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 * 
 * Example 1:
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 * Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

 * 
 * Example 2:
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit = 0.

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


// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int>& prices) {
  int n = prices.size();
  if (n == 0 || n == 1)
    return 0;

  int maxProfit = 0;
  for (int i = 0; i < n; ++i) {
    for(int j = i + 1; j < n; ++j) {
      maxProfit = std::max(maxProfit, prices[j] - prices[i]);
    }
  }

  return maxProfit;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Sliding Window
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxProfit(std::vector<int>& prices) {
  int n = prices.size();
  if (n == 0 || n == 1)
    return 0;

  int i = 0, j = 1;
  int profit = 0;

  while (j < n) {
    int curProfit = prices[j] - prices[i];
    profit = std::max(profit, curProfit);

    if(prices[i] > prices[j]) {
      i = j;
    }

    j++;
  }

  return profit;
}

int main(void) {
  // * testcase 1
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};

  // * testcase 2
  // std::vector<int> prices = {7, 6, 4, 3, 1};

  std::cout << "Stock Prices" << std::endl;
  printArr(prices);

  int p = bruteForce(prices);
  // int p = maxProfit(prices);
  std::cout << "Maximum profit: " << p << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 05-best-time-to-buy-sell-stock-1.cpp -o output && ./output