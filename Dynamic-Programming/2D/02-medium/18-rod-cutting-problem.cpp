/*
 * Rod Cutting Problem
 * 
 * Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated
 * with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.
 * 
 * 1. The sizes will range from 1 to ‘N’ and will be integers.
 * 2. The sum of the pieces cut should be equal to ‘N’.
 * 3. Consider 1-based indexing.
 * 
 * https://www.naukri.com/code360/problems/rod-cutting-problem_800284
*/

// ! Amazon, Google, Meta, IBM, PayU, Samsung

// * Same as Partitions With Given Difference

#include <vector>
#include <numeric>
#include <climits>
#include <iostream>
#include <algorithm>

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
int dfs_brute(int i, int n, vector<int> &price) {
  cout << i << " " << n << endl;
  if (i == 0) {
    return n * price[0];
  }

  int not_take = dfs_brute(i - 1, n, price);
  int take = INT_MIN;
  int rod_length = i + 1;
  if (n >= rod_length) {
    take = price[i] + dfs_brute(i, n - rod_length, price);
  }
  return max(not_take, take);
}

// * With Memoization
int dfs(int i, int n, vector<int> &price, vector<vector<int>> &dp) {
  if (i == 0)
    return (n * price[0]);

  if (dp[i][n] != -1)
    return dp[i][n];

  int not_take = dfs(i - 1, n, price, dp);
  int take = INT_MIN;
  int rod_length = i + 1;
  if (n >= rod_length) {
    take = price[i] + dfs(i, n - rod_length, price, dp);
  }

  return dp[i][n] = max(not_take, take);
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
int bruteForce(vector<int> &price, int n) {
  int len = price.size();
  return dfs_brute(len - 1, n, price);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Solved in a little different way
// * Top Down + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2)
int betterApproach(vector<int> &price, int n) {
  int len = price.size();
  vector<vector<int>> dp(len + 1, vector<int>(n + 1, -1));
  return dfs(len - 1, n, price, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
int cutRod(vector<int> &price, int n) {
  int len = price.size();
  vector<vector<int>> dp(len + 1, vector<int>(n + 1, -1));
  for (int i = 0; i <= n; ++i)
    dp[0][i] = (i * price[0]);

  for (int i = 1; i < len; ++i) {
    for (int j = 0; j <= n; ++j) {
      int not_take = dp[i - 1][j];
      int take = INT_MIN;
      int rod_lenth = i + 1;
      if (j >= rod_lenth) {
        take = price[i] + dp[i][j - rod_lenth];
      }
      dp[i][j] = max(not_take, take);
    }
  }

  // * For Debugging
  for (auto &vec : dp)
    printArr(vec);

  return dp[len - 1][n];
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
int cutRodDP2(vector<int> &price, int n) {
  int len = price.size();
  vector<int> prev(n + 1, -1);
  for (int i = 0; i <= n; ++i)
    prev[i] = (i * price[0]);
  printArr(prev);
  
  vector<int> cur(n + 1, -1);
  for (int i = 1; i < len; ++i) {
    for (int j = 0; j <= n; ++j) {
      int not_take = prev[j];
      int take = INT_MIN;
      int rod_lenth = i + 1;
      if (j >= rod_lenth) {
        take = price[i] + cur[j - rod_lenth];
      }
      cur[j] = max(not_take, take);
    }
    prev = cur;
    printArr(prev);
  }

  return prev[n];
}

int main(void) {
  cout << "Rod Cutting Problem: " << endl;
  // * testcase 1
  int n = 8;
  vector<int> price = {2, 5, 7, 8, 10};

  // * testcase 2
  // int n = 2;
  // vector<int> price = {2, 2, 2};

  cout << "n: " << n << endl;
  cout << "price: ";
  printArr(price);

  // int ans = bruteForce(price, n);
  // int ans = betterApproach(price, n);
  // int ans = cutRod(price, n);
  int ans = cutRodDP2(price, n);

  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 18-rod-cutting-problem.cpp -o output && ./output