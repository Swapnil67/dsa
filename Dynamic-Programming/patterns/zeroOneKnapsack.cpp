/*
 * 
*/

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

int dfs(int i, vector<int> &profit, vector<int> &weight, int capacity) {
  if (i == profit.size())
    return 0;
  int skip = dfs(i + 1, profit, weight, capacity);
  int take = 0;
  if (capacity - weight[i] >= 0) {
    take += profit[i] + dfs(i + 1, profit, weight, capacity - weight[i]);
  }
  return max(skip, take);
}

int dfs(int i, vector<int> &profit, vector<int> &weight, int capacity, vector<vector<int>> &dp) {
  if (i == profit.size())
    return 0;

  if (dp[i][capacity] != -1)
    return dp[i][capacity];

  int skip = dfs(i + 1, profit, weight, capacity);
  int take = 0;
  if (capacity - weight[i] >= 0) {
    take += profit[i] + dfs(i + 1, profit, weight, capacity - weight[i]);
  }

  int ans = max(skip, take);
  dp[i][capacity] = ans;

  return ans;
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(2^N)
// * SPACE COMPLEXITY O(N)
int bruteForce(vector<int> &profit, vector<int> &weight, int capacity) {
  int n = profit.size();
  return dfs(0, profit, weight, capacity);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization
// * TIME COMPLEXITY O(N * capacity)
// * SPACE COMPLEXITY O(N * capacity)
int maximumProfit(vector<int> &profit, vector<int> &weight, int capacity) {
  int n = profit.size();
  vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
  return dfs(0, profit, weight, capacity, dp);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(N * capacity)
// * SPACE COMPLEXITY O(N * capacity)
int maximumProfit2(vector<int> &profit, vector<int> &weight, int capacity) {
  int n = profit.size(), m = capacity;
  vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

  for (int i = 0; i <= n; ++i) {
    dp[i][0] = 0;
  }
  
  for (int i = 0; i <= m; ++i) {
    if (i >= weight[0])
      dp[0][i] = profit[0];
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int skip = dp[i - 1][j];
      int take = 0;
      if (j >= weight[i - 1]) {
        take += profit[i - 1] + dp[i - 1][j - weight[i - 1]];
      }
      dp[i][j] = max(skip, take);
    }
  }

  // * For debugging
  // for (auto &vec: dp)
  //   printArr(vec);

  return dp[n - 1][capacity];
}


// * ------------------------- Approach: Better Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(N * capacity)
// * SPACE COMPLEXITY O(capacity)
int maximumProfit3(vector<int> &profit, vector<int> &weight, int capacity) {
  int n = profit.size(), m = capacity;
  vector<int> dp(m + 1, 0); 
  dp[0] = 0;

  // * Fill the first row to reduce edge cases
  for (int c = 0; c <= m; ++c) {
    if (c >= weight[0])
      dp[c] = profit[0];
  }
  // printArr(dp);

  for (int i = 1; i < n; ++i) {
    vector<int> next_dp(m + 1, 0); 
    for (int j = 1; j <= m; ++j) {
      int skip = dp[j];
      int take = 0;
      if (j - weight[i] >= 0) {
        take += profit[i] + dp[j - weight[i]];
      }
      next_dp[j] = max(skip, take);
    }
    dp = next_dp;
    // printArr(dp); // * For debugging
  }

  return dp[capacity - 1];
}

int main(void) {
  // * testcase 1
  vector<int> profit = {4, 4, 7, 1};
  vector<int> weight = {5, 2, 3, 1};
  int capacity = 8;

  // * testcase 2
  // vector<int> profit = {60, 100, 120};
  // vector<int> weight = {10, 20, 30};
  // int capacity = 50;

  cout << "capacit: " << capacity << endl;
  cout << "profit: ";
  printArr(profit);
  cout << "weight: ";
  printArr(weight);


  // int ans = bruteForce(profit, weight, capacity);
  // int ans = maximumProfit(profit, weight, capacity);
  // int ans = maximumProfit2(profit, weight, capacity);
  int ans = maximumProfit3(profit, weight, capacity);

  cout << "Maximum Profit: " << ans << endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++17 zeroOneKnapsack.cpp -o output && ./output
