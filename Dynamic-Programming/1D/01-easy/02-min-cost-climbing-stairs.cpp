/*
 * Leetcode - 70
 * Climbing Stairs
 * 
 * You are climbing a staircase. It takes n steps to reach the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 
 * Example 1 :
 * Input     : n = 2
 * Output    : 2
 * 
 * Example 2 :
 * Input     : n = 3
 * Output    : 3
 * 
 * https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650 
 * https://leetcode.com/problems/climbing-stairs/description/
 * https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
*/

#include <vector>
#include <iostream>

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

// * Google

int dfs_brute(int i, std::vector<int> &cost) {
  if (i >= cost.size()) // * base case
    return 0;

  int cur_cost = cost[i];
  int a = cur_cost + dfs_brute(i + 1, cost);
  int b = cur_cost + dfs_brute(i + 2, cost);
  return std::min(a, b);
}

int solve(int i, std::vector<int> &cost, std::vector<int> &dp) {
  if (i >= cost.size()) // * base case
    return 0;

  if (dp[i] != -1)
    return dp[i];

  int cur_cost = cost[i];
  int a = cur_cost + solve(i + 1, cost, dp);
  int b = cur_cost + solve(i + 2, cost, dp);
  return dp[i] = std::min(a, b);
}

// * Top Down approach 
// * TIME COMPLEXITY O(2^N)
// * SPACE COMPLEXITY O(2^N)
int bruteForce(std::vector<int> &cost) {
  int n = cost.size();
  return std::min(dfs_brute(0, cost), dfs_brute(1, cost));
}

// * Top Down approach (With Memoization)
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int minCostClimbingStairs(std::vector<int> &cost) {
  int n = cost.size();
  std::vector<int> dp(1000, -1);
  return std::min(solve(0, cost, dp), solve(1, cost, dp));
}

// * Bottom Up Approach
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int minCostClimbingStairs2(std::vector<int> &cost) {
  int n = cost.size();
  if (n == 2)
    return std::min(cost[0], cost[1]);

  for (int i = 2; i < n; ++i) {
    cost[i] = cost[i] + std::min(cost[i - 1], cost[i - 2]);
  }
  // printArr(cost); // * For debugging

  return std::min(cost[n - 1], cost[n - 2]);
}

int main(void) {
  // * testcase 1
  // std::vector<int> cost = {10, 15, 20};

  // * testcase 2
  std::vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

  std::cout << "Cost: " << std::endl;
  printArr(cost);
  
  // int ans = minCostClimbingStairs(cost);
  int ans = minCostClimbingStairs2(cost);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-min-cost-climbing-stairs.cpp -o output && ./output

