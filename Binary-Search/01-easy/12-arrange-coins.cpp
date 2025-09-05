/*
 * Leetcode - 441
 * Arranging Coins
 * 
 * You have n coins and you want to build a staircase with these coins. 
 * The staircase consists of k rows where the ith row has exactly i coins. 
 * The last row of the staircase may be incomplete.

 * Given the integer n, return the number of complete rows of the staircase you will build.

 * 
 * Example 1 
 * Input     : n = 5
 * Output    : 2

 * 
 * Example 2
 * Input     : n = 8
 * Output    : 3
 * 
 * https://leetcode.com/problems/arranging-coins/description/
*/

#include <iostream>

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(logn)
// * SPACE COMPLEXITY O(1)
int arrangeCoins(int n) {
  int l = 0, r = n;
  int ans = 0;
  while (l <= r) {
    long long m = l + (r - l) / 2;
    long long cur_sum = (m * (m + 1ll)) / 2ll;

    // std::cout << "\n" << m << " -> " << cur_sum << std::endl;
    if (cur_sum > n) {
      r = m - 1;
    } else {
      ans = m;
      l = m + 1;
    }
  }

  return ans;
}

int main(void) {
  std::cout << "Arranging Coins: " << arrangeCoins(5) << std::endl;
  std::cout << "Arranging Coins: " << arrangeCoins(8) << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 12-arrange-coins.cpp -o output && ./output