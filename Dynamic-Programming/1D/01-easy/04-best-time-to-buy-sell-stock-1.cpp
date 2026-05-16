/*
 * Leetcode - 2016
 * Maximum Difference Between Increasing Elements
 * 
 * Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] 
 * (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].
 * 
 * Return the maximum difference. If no such i and j exists, return -1.
 * 
 * Example 1:
 * Input: nums = [7,1,5,4]
 * Output: 4
 * Explanation: The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
 * 
 * Example 2:
 * Input: nums = [9,4,3,2]
 * Output: -1
 * Explanation: There is no i and j such that i < j and nums[i] < nums[j].
 * 
 * https://leetcode.com/problems/maximum-difference-between-increasing-elements
*/

// ! Amazon, Google, Meta, Microsoft, Uber, Apple, IBM

#include <vector>
#include <climits>
#include <iostream>

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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
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

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Sliding Window
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxProfit(std::vector<int>& prices) {
  int n = prices.size();
  if (n == 0 || n == 1)
    return 0;

  int i = 0, j = 1;
  int max_profit = 0;

  while (j < n) {
    int cur_profit = prices[j] - prices[i];
    max_profit = std::max(max_profit, cur_profit);

    if (prices[i] > prices[j]) {
      i = j;
    }

    j++;
  }

  return max_profit;
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------
// * Dynamic Programming
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxProfitDP(vector<int> &prices) {
  int n = prices.size();
  if (n <= 1)
    return 0;

  int j = 1;
  int max_profit = 0, min_buy = prices[0];
  while (j < n) {
    max_profit = max(max_profit, (prices[j] - min_buy));
    min_buy = min(min_buy, prices[j]);
    j++;
  }

  return max_profit;
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
  // int p = maxProfitDP(prices);
  std::cout << "Maximum profit: " << p << std::endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 04-best-time-to-buy-sell-stock-1.cpp -o output && ./output