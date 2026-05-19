/*
 * Leetcode - 1420
 * Build Array Where You Can Find The Maximum Exactly K Comparisons
 * 
 * You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:
 * 
 * 
 * Example 1    :
 * Input        : n = 2, m = 3, k = 1
 * Output       : 6
 * Explanation  : The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
 * 
 * Example 2    :
 * Input        : n = 5, m = 2, k = 3
 * Output       : 0
 * Explanation  : There are no possible arrays that satisfy the mentioned conditions.
 * 
 * Example 3    :
 * Input        : n = 9, m = 1, k = 1
 * Output       : 1
 * Explanation  : The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]
 * 
 * https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/
*/


#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int MOD = 1e9 + 7;

int solve_brute(int search_cost, int cur_max, int n, int m, int k) {
  if (n == 0) {
    return search_cost == k;
  }

  int res = 0;
  for (int i = 1; i <= m; ++i) {
    if (i > cur_max) { // * update the cur_max -> i
      res = (res + solve_brute(search_cost + 1, i, n - 1, m, k)) % MOD;
    } else { // * No need to update the cur_max
      res = (res + solve_brute(search_cost, cur_max, n - 1, m, k)) % MOD;
    }
  }

  return res % MOD;
}

int solve(int search_cost, int cur_max, int n, int m, int k, int (&t)[][51][101]) {
  if (n == 0) {
    return (search_cost == k) ? 1 : 0;
  }

  if (t[n][search_cost][cur_max] != -1) {
    return t[n][search_cost][cur_max];
  }

  int res = 0;
  for (int i = 1; i <= m; ++i) {
    if (i > cur_max) {
      res = (res + solve(search_cost + 1, i, n - 1, m, k, t)) % MOD;
    }
    else {
      res = (res + solve(search_cost, cur_max, n - 1, m, k, t)) % MOD;
    }
  }

  return t[n][search_cost][cur_max] = res % MOD;
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * TIME COMPLEXITY O(2^(m * n * k))
// * SPACE COMPLEXITY O(2^(m * n * k))
int bruteForce(int n, int m, int k) {
  return solve_brute(0, 0, n, m, k);
}

// * ------------------------- Approach 2: Optimal Approach -------------------------
// * Using Recursion + Memoization (Top Down)
// * TIME COMPLEXITY O(m * n * k)
// * SPACE COMPLEXITY O(m * n * k)
int numOfArrays(int n, int m, int k) {
  int t[51][51][101];
  memset(t, -1, sizeof(t));
  return solve(0, 0, n, m, k, t);
}

int main(void) {
  // * testcase 1
  int n = 2, m = 3, k = 1;

  // * testcase 2
  // int n = 5, m = 2, k = 3;

  // * testcase 3
  // int n = 9, m = 1, k = 1;

  std::cout << "n: " << n << ", m: " << m << ", k: " << k << std::endl;

  // int ans = bruteForce(n, m, k);
  int ans = numOfArrays(n, m, k);

  std::cout << "Ans: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 01-build-array-where-you-can-find-the-max-exactly-k-comparisons.cpp -o output && ./output