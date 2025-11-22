/*
 * Leetcode - 1553
 * Minimum Number of Days to Eat N Oranges 
 * 
 * 
 * 
*/

// ! Google

#include <vector>
#include <iostream>
#include <unordered_map>

int solve(int n, std::unordered_map<int, int> &dp) {
  if (n == 0)
    return 0;

  if (dp.count(n))
    return dp[n];

  int res = 1 + solve(n - 1, dp);
  if (n % 3 == 0) {
    res = std::min(res, 1 + solve(n / 3, dp));
  }
  if (n % 2 == 0) {
    res = std::min(res, 1 + solve(n / 2, dp));
  }

  return dp[n] = res;
}

// * we add (n % 2) == number of days we need to add to make 'n' divisible by '2
// * we add (n % 3) == number of days we need to add to make 'n' divisible by '3
int solve2(int n, std::unordered_map<int, int> &dp) {
  if (dp.count(n))
    return dp[n];

  int res = 1 + (n % 2) + solve2(n / 2, dp);
  res = std::min(res, 1 + (n % 3) + solve2(n / 3, dp));

  return dp[n] = res;
}

// * Dynamic Programming (Top-Down)
// * TIME COMPLEXITY  O(N)
// * SPACE COMPLEXITY O(N)
int bruteForce(int n) {
  std::unordered_map<int, int> dp;
  int res = solve(n, dp);
  return res;
}

// * Greedy + Dynamic Programming (Top-Down)
// * TIME COMPLEXITY  O(logN)
// * SPACE COMPLEXITY O(logN)
int minDays(int n) {
  std::unordered_map<int, int> dp;
  dp[0] = 0;
  dp[1] = 1;
  int res = solve2(n, dp);
  return res;
}

int main(void) {
  int n = 10;
  std::cout << "Oranges: " << n << std::endl;

  // int min_days = bruteForce(n);
  int min_days = minDays(n);
  std::cout << "Minimum Days: " << min_days << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 05-min-no-of-days-to-eat-n-oranges.cpp -o output && ./output
