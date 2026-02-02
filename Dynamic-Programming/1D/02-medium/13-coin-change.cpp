/*
 * Leetcode - 322 
 * Coin Change
 * 
 * You are given an integer array coins representing coins of different denominations and an integer
 * amount representing a total amount of money.
 * 
 * Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be 
 * made up by any combination of the coins, return -1.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * 
 * Example 1   :
 * Input       : coins = [1,2,5], amount = 11
 * Output      : 3
 * Explanation : 11 = 5 + 5 + 1
 * 
 * Example 2   :
 * Input       : coins = [2], amount = 3
 * Output      : -1
 * 
 * Example 3   :
 * Input       : coins = [1], amount = 0
 * Output      : 0
 * 
 * https://leetcode.com/problems/coin-change/description/
*/

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

// * Recursion Without Memoization
int solve(int amount, vector<int> &coins) {
  if (amount == 0)
    return 0;

  int res = 1e9;
  for (auto &coin : coins) {
    if (amount - coin >= 0) {
      res = min(res, 1 + solve(amount - coin, coins));
    }
  }
  return res;
}

// * Recursion With Memoization
int solve(int amount, vector<int> &coins, vector<int> &dp) {
  if (amount == 0)
    return 0;

  if (dp[amount] != -1)
    return dp[amount];

  int res = 1e9;
  for (auto &coin : coins) {
    if (amount - coin >= 0) {
      res = min(res, 1 + solve(amount - coin, coins, dp));
    }
  }
  return dp[amount] = res;
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * 'n' - length of coins, 't' - given amount
// * TIME COMPLEXITY O(n^t)
// * SPACE COMPLEXITY O(t)
int bruteForce(int amount, vector<int> &coins) {
  return solve(amount, coins);
}

// * ------------------------- Approach 2: Better Approach -------------------------
// * Recursion + Memoization (Top Down)
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
int betterApproach(int amount, vector<int> &coins) {
  int n = coins.size();
  vector<int> dp(amount + 1, -1);
  int min_coins = solve(amount, coins, dp);
  return min_coins >= 1e9 ? -1 : min_coins;
}


// * ------------------------- Approach 3: Optimal Approach -------------------------
// * Instead of asking “how many coins to make this amount?” recursively, we build answers from smaller 
// * amounts to larger ones.
// * Dynamic Programming (Top-Down)
// * 'n' - length of coins, 't' - given amount
// * TIME COMPLEXITY O(n * t)
// * SPACE COMPLEXITY O(n)
int coinChange(int amount, std::vector<int> &coins) {

}

int main(void) {
  // * testcase 1
  // int amount = 11;
  // std::vector<int> coins = {1, 2, 5};

  // * testcase 2
  // int amount = 3;
  // std::vector<int> coins = {2};

  // * testcase 3
  int amount = 0;
  std::vector<int> coins = {1};

  std::cout << "Amount: " << amount << std::endl;
  std::cout << "Input coins: ";
  printArr(coins);
  
  // int ans = bruteForce(amount, coins);
  // int ans = betterApproach(amount, coins);
  int ans = coinChange(amount, coins);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 13-coin-change.cpp -o output && ./output
