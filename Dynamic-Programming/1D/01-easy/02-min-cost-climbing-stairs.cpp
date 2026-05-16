/*
 * Leetcode - 746
 * Min Cost Climbing Stairs
 * 
 * You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
 * Once you pay the cost, you can either climb one or two steps.
 * 
 * You can either start from the step with index 0, or the step with index 1.
 * 
 * Return the minimum cost to reach the top of the floor.
 * 
 * Example 1 :
 * Input     : cost = [10,15,20]
 * Output    : 15
 * 
 * Example 2 :
 * Input     : cost = [1,100,1,1,1,100,1,1,100,1]
 * Output    : 6
 * 
 * https://leetcode.com/problems/min-cost-climbing-stairs/description/
*/

// ! Google

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


int dfs_brute(int i, vector<int> &cost) {
  if (i >= cost.size()) // * base case
    return 0;

  return cost[i] + min(dfs_brute(i + 1, cost), dfs_brute(i + 2, cost));
}

int solve(int i, vector<int> &cost, vector<int> &dp) {
  if (i >= cost.size()) // * base case
    return 0;

  if (dp[i] != -1)
    return dp[i];

  int cur_cost = cost[i];
  int a = cur_cost + solve(i + 1, cost, dp);
  int b = cur_cost + solve(i + 2, cost, dp);
  return dp[i] = min(a, b);
}

// * ------------------------- APPROACH: Brute Force -------------------------

// * Top Down approach 
// * TIME COMPLEXITY O(2^N)
// * SPACE COMPLEXITY O(2^N)
int bruteForce(vector<int> &cost) {
  int n = cost.size();
  return min(dfs_brute(0, cost), dfs_brute(1, cost));
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * Top Down approach (With Memoization)
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int minCostClimbingStairs(vector<int> &cost) {
  int n = cost.size();
  vector<int> dp(1000, -1);
  return min(solve(0, cost, dp), solve(1, cost, dp));
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * Bottom Up Approach
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int minCostClimbingStairs2(vector<int> &cost) {
  int n = cost.size();
  if (n == 2)
    return min(cost[0], cost[1]);

  for (int i = 2; i < n; ++i) {
    cost[i] = cost[i] + min(cost[i - 1], cost[i - 2]);
  }
  printArr(cost); // * For debugging

  return min(cost[n - 1], cost[n - 2]);
}

int main(void) {
  // * testcase 1
  // vector<int> cost = {10, 15, 20};

  // * testcase 2
  vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

  cout << "Cost: " << endl;
  printArr(cost);
  
  // int ans = minCostClimbingStairs(cost);
  int ans = minCostClimbingStairs2(cost);
  cout << "Ans: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-min-cost-climbing-stairs.cpp -o output && ./output

