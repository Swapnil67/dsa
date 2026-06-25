/*
 * Leetcode - 
 * Perfect Squares
 * 
 * You are given an integer n, return the least number of perfect square numbers that sum to n.
 * 
 * A perfect square is an integer that is the square of an integer. For example, 1, 4, 9, 16, 25... are perfect squares.

 * Example 1
 * input            : n = 12
 * output           : 3 
 * Explanation      : 12 = 4 + 4 + 4.

 * Example 2
 * input            : n = 13
 * output           : 2
 * Explanation      : 12 = 4 + 9
 * 
 * https://leetcode.com/problems/perfect-squares
 * https://neetcode.io/problems/perfect-squares
*/

// ! Amazon, Google, Meta, Microsoft, Bloomberg, Zoho

#include <vector>
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

int dfs(int n) {
  if (n == 0)
    return 0;

  int res = n;
  for (int i = 1; i * i <= n; ++i) {
    res = min(res, 1 + dfs(n - i * i));
  }
  return res;
}

int dfs(int n, vector<int> &dp) {
  if (n == 0)
    return 0;

  if (dp[n] != -1)
    return dp[n];

  int res = n;
  for (int i = 1; i * i <= n; ++i) {
    res = min(res, 1 + dfs((n - i * i), dp));
  }
  return dp[n] = res;
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(n^(sqrt(n)))
// * SPACE COMPLEXITY O(n)
int bruteForce(int n) {
  if (n <= 1)
    return n;
  return dfs(n);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(n * sqrt(n))
// * SPACE COMPLEXITY O(n)
int betterApproach(int n) {
  if (n <= 1)
    return n;
  vector<int> dp(n + 1, -1);
  return dfs(n, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n * sqrt(n))
// * SPACE COMPLEXITY O(n)
int numSquares(int n) {
  vector<int> dp(n + 1, n);
  dp[0] = 0;
  for (int target = 1; target <= n; ++target) {
    for (int s = 1; s * s <= target; ++s) {
      dp[target] = min(dp[target], 1 + dp[target - s * s]);
    }
  }
  return dp[n];
}

int main(void) {
  // * testcase 1
  int n = 12;

  // * testcase 2
  // int n = 13;

  cout << "n: " << n << endl;
  // int ans = bruteForce(n);
  // int ans = betterApproach(n);
  int ans = numSquares(n);

  cout << "Ans: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 30-perfect-squares.cpp -o output && ./output
