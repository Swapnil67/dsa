/*
 * Unbounded Knapsack
 *
 * https://www.naukri.com/code360/problems/unbounded-knapsack_1215029
*/

// * Infinite Supply Pattern

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

int dfs(int i, int cap, vector<int> &profit, vector<int> &weight) {
  if (i >= weight.size())
    return 0;

  int not_take = dfs(i + 1, cap, profit, weight);
  int take = 0;
  if (cap >= weight[i]) {
    take = profit[i] + dfs(i, cap - weight[i], profit, weight);
  }
  return max(not_take, take);
}

int dfs(int i, int cap,
        vector<int> &profit,
        vector<int> &weight,
        vector<vector<int>> &dp)
{
  if (i == 0)
    return (cap / weight[i]) * profit[i];

  if (dp[i][cap] != -1)
    return dp[i][cap];

  // * Skip item 'i'
  int not_take = dfs(i - 1, cap, profit, weight, dp);

  // * Include item 'i'
  int take = 0;
  if (cap >= weight[i]) {
    take = profit[i] + dfs(i, cap - weight[i], profit, weight, dp);
  }
  return dp[i][cap] = max(not_take, take);
}


// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down [from 0 to n]
// * TIME COMPLEXITY O(n^t)
// * SPACE COMPLEXITY O(n)
int bruteForce(int capacity, vector<int> &profit, vector<int> &weight) {
  int n = profit.size();
  return dfs(0, capacity, profit, weight);
}

// * ------------------------- Approach: Better Approach -------------------------
// * Top Down + Memoization [from n - 1 to 0]
// * TIME COMPLEXITY O(n * t)
// * SPACE COMPLEXITY O(n * t) * O(n)
int betterApproach(int capacity, vector<int> &profit, vector<int> &weight) {
  int n = profit.size();
  vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
  return dfs(n - 1, capacity, profit, weight, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n * t)
// * SPACE COMPLEXITY O(n * t)
int unboundedKnapsack(int capacity, vector<int> &profit, vector<int> &weight) {
  int n = profit.size();
  int m = capacity;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int c = 0; c <= m; ++c) {
    if (c >= weight[0])
      dp[0][c] = (c / weight[0]) * profit[0];
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <=m;++j) {
      int not_take = dp[i - 1][j];
      int take = 0;
      if (j - weight[i] >= 0) {
        take = profit[i] + dp[i][j - weight[i]];
      }
      dp[i][j] = max(not_take, take);
    }
  }

  // * For Debugging
  for (auto &vec : dp)
    printArr(vec);

  return dp[n - 1][m];
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(n * t)
// * SPACE COMPLEXITY O(t)
int unboundedKnapsackDP2(int capacity, vector<int> &profit, vector<int> &weight) {
  int n = profit.size();
  int m = capacity;
  vector<int> dp(m + 1, 0), next_dp(m + 1, 0);
  for (int c = 0; c <= m; ++c) {
    dp[c] = (c / weight[0]) * profit[0];
  }
  printArr(dp);

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int not_take = dp[j];
      int take = 0;
      if (j - weight[i] >= 0) {
        take = profit[i] + next_dp[j - weight[i]];
      }
      next_dp[j] = max(not_take, take);
    }
    dp = next_dp;
    printArr(dp);
  }

  return dp[m];
}

int main(void) {
  // * testcase 1
  int capacity = 8;
  vector<int> profit = {4, 4, 7, 1};
  vector<int> weight = {5, 2, 3, 1};

  // * testcase 2
  // int capacity = 50;
  // vector<int> profit = {60, 100, 120};
  // vector<int> weight = {10, 20, 30};

  // * testcase 3
  // int capacity = 10;
  // vector<int> profit = {5, 11, 13};
  // vector<int> weight = {2, 4, 6};

  cout << "capacity: " << capacity << endl;
  cout << "profit: ";
  printArr(profit);
  cout << "weight: ";
  printArr(weight);


  // int ans = bruteForce(capacity, profit, weight);
  // int ans = betterApproach(capacity, profit, weight);
  // int ans = unboundedKnapsack(capacity, profit, weight);
  int ans = unboundedKnapsackDP2(capacity, profit, weight);

  cout << "Maximum Profit: " << ans << endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++17 unboundedKnapsack.cpp -o output && ./output
