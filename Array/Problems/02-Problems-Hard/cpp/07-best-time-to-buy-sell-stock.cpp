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

#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

int getMinBetweenGivenIndexes(std::vector<int> arr, int i, int j) {
  int min = INT_MAX;
  for (int i = 0; i <= j; ++i) {
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
  int maxProfit = 0;
  for (int i = n - 1; i >= 0; --i) {
    int sell = prices[i];
    int buy = getMinBetweenGivenIndexes(prices, 0, i - 1);
    // std::cout << buy << " - " << sell << " = " << sell - buy << std::endl;
    maxProfit = std::max(maxProfit, sell - buy);
  }
  return maxProfit;
}

// * ------------------------- APPROACH 3: Optimal FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int optimalApproach(std::vector<int> prices) {
  int n = prices.size();

  int mini = prices[0], maxProfit = 0;
  for (int i = 1; i < n; ++i) {
    int profit = prices[i] - mini;
    // std::cout << prices[i] << " - " << mini << " " << profit << std::endl;
    maxProfit = std::max(maxProfit, profit);
    mini = std::min(mini, prices[i]);
  }

  return maxProfit;
}

int main() {
  // * testcase 1
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};
  // * testcase 1
  // std::vector<int> prices = {7, 6, 4, 3, 1};

  std::cout << "Stock Prices" << std::endl;
  printArr(prices);
  // int maxProfit = bruteForce(prices);
  int maxProfit = optimalApproach(prices);
  std::cout << "Max Profit from buy & sell is " << maxProfit << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 07-best-time-to-buy-sell-stock.cpp -o output && ./output