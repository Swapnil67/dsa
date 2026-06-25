/*
 * Leetcode -343
 * Integer Break
 * 
 * Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize
 * the product of those integers.
 * 
 * Return the maximum product you can get.

 * Example 1
 * input            : n = 2
 * output           : 1
 * Explanation      : 2 = 1 + 1, 1 × 1 = 1..

 * Example 2
 * input            : n = 10
 * output           : 36
 * Explanation      : 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * https://leetcode.com/problems/integer-break/
 * https://neetcode.io/problems/integer-break/
*/

// ! Amazon, Google, Meta, Microsoft, Bloomberg

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

// * Without Memoization
int dfs(int n) {
  if (n == 1)
      return 1;

  int ans = INT_MIN;
  for (int i = 1; i < n; ++i) {
    int res = i * max(n - i, dfs(n - i));
    ans = max(ans, res);
  }

  return ans;
}

// * With Memoization
int dfs(int n, vector<int>& dp) {
  if (n == 1)
      return 1;

  if (dp[n] != -1)
      return dp[n];

  int ans = INT_MIN;
  for (int i = 1; i < n; ++i) {
    int res = i * max(n - i, dfs(n - i, dp));
    ans = max(ans, res);
  }

  return dp[n] = ans;
}


// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(N^N)
// * SPACE COMPLEXITY O(N)
int bruteForce(int n) {
  if (n <= 1)
    return n;
  return dfs(n);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(n^2 target)
// * SPACE COMPLEXITY O(n)
int betterApproach(int n) {
  if (n <= 1)
    return n;

  vector<int> dp(60, -1);
  return dfs(n, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n^2 target)
// * SPACE COMPLEXITY O(n)
int integerBreak(int n) {
  vector<int> dp(n + 1, 0);
  dp[1] = 1;
  for (int num = 2; num <= n; ++num) {
    int ans = INT_MIN;
    for (int i = 1; i <= num; ++i) {
      int res = i * max((num - i), dp[num - i]);
      ans = max(ans, res);
    }
    dp[num] = ans;
  }
  return dp[n];
}

int main(void) {
  // * testcase 1
  int n = 12;

  // * testcase 2
  // int n = 4;

  cout << "n: " << n << endl;

  // int ans = bruteForce(n);
  // int ans = betterApproach(n);
  int ans = integerBreak(n);

  cout << "Ans: " << ans << endl;
}


// * Run the code
// * g++ --std=c++17 31-integer-break.cpp -o output && ./output


// * Tree Diagram
/*
*                      dfs(4)
*                     /   |   \
*           i=1      /    |    \      i=3
*                   /    i=2    \
*                  /      |      \
*              1 * max(3, |       3 * max(1, dfs(1))
*                dfs(3))  |                    |
*                 /   \   |                    1
*        i=1     /     \  | 
*               /       \ | 2 * max(2, dfs(2))
*              /         \|             |
*      1 * max(2, dfs(2)) 2 * max(1,    |
*
*                  |          dfs(1))   | 1 * max(1, dfs(1))
*                  |             |      |             |
*         1 * max(1, dfs(1))     1      |             1
*
*                     |                 |
*                     1                 v
*                                2 * max(1, 1) = 2
*
*/

// * For Bottom Up
/*
* +-----------------+-------------------------------------------------------+-------------------------+
* | Array Index (i) | Inner Loop Calculations (j)                           | Maximum Product dp[i]   |
* +-----------------+-------------------------------------------------------+-------------------------+
* | dp[1]           | Base Case                                             | 1                       |
* +-----------------+-------------------------------------------------------+-------------------------+
* | dp[2]           | j=1: 1 * max(1, dp[1]) -> 1 * 1 = 1                   | 1                       |
* +-----------------+-------------------------------------------------------+-------------------------+
* | dp[3]           | j=1: 1 * max(2, dp[2]) -> 1 * 2 = 2                   | 2                       |
* |                 | j=2: 2 * max(1, dp[1]) -> 2 * 1 = 2                   |                         |
* +-----------------+-------------------------------------------------------+-------------------------+
* | dp[4]           | j=1: 1 * max(3, dp[3]) -> 1 * 3 = 3                   | 4                       |
* |                 | j=2: 2 * max(2, dp[2]) -> 2 * 2 = 4                   |                         |
* |                 | j=3: 3 * max(1, dp[1]) -> 3 * 1 = 3                   |                         |
* +-----------------+-------------------------------------------------------+-------------------------+
*/
