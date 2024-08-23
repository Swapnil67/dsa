/*
 * Best Time to Buy and Sell Stock II
 * On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time.
 * However, you can buy it then immediately sell it on the same day.

 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 * 
 * Example 1:
 * Input: prices = [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
 * Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
 * Total profit is 4 + 3 = 7.

 * https://www.naukri.com/code360/problems/selling-stock_630282
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
*/


#include<iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * Less Readable Approach
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int>& prices) {
  int buy = 1, sell = 0;
  int n = prices.size();

  int buyPrice, maxProfit = 0;
  for (int i = 0; i < n; ++i) {
    if(buy == 1) {
      if(prices[i] > prices[i+1]) {
        continue;
      }
      else{
        buyPrice = prices[i];
        sell = 1;
        buy = 0;
      }
    }
    else if(sell == 1) {
      if (prices[i] < prices[i + 1]) {
        continue;
      }
      else {
        int profit = prices[i] - buyPrice;
        maxProfit += profit;
        buy = 1;
        sell = 0;
      }
    }
  }
  return maxProfit;
}

// * More Readable Approach
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int optimalApproach(std::vector<int> prices) {
  int n = prices.size();
  int profit = 0;
  for (int i = 1; i < n; ++i) {
    if (prices[i] > prices[i - 1]) {
      profit += (prices[i] - prices[i-1]);
    }
  }
  return profit;
}

int main() {
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};
  // std::vector<int> prices = {1, 2, 3, 4, 5};
  // std::vector<int> prices = {7, 6, 4, 3, 1};
  std::cout << "Stock Prices" << std::endl;
  printArr(prices);
  // int maxProfit = bruteForce(prices);
  int maxProfit = optimalApproach(prices);
  std::cout << "Max Profit from buy & sell is " << maxProfit << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 07-best-time-to-buy-sell-stock-2.cpp -o output && ./output