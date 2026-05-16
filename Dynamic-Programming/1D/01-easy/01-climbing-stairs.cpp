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

// ! Amazon, Adobe, Flipkart, Microsoft, Google, Meta, Apple, Uber, Tiktok

#include <vector>
#include <iostream>

using namespace std;

// * ------------------------- APPROACH: Brute Force -------------------------

int dfs_brute(int n, int i) {
  if (i >= n)
    return i == n;

  return dfs_brute(n, i + 1) + dfs_brute(n, i + 2);
}

// * Plain Recursion
// * TIME COMPLEXITY O(2^N)
// * SPACE COMPLEXITY O(2^N)
int bruteForce(int n) {
  return dfs_brute(n, 0);
}

// * ------------------------- APPROACH: Optimal Approach -------------------------

// * Top Down Recursion
int dfs(int n, int i, vector<int> &cache) {
  if (i >= n)
    return i == n;

  if (cache[i] != -1)
    return cache[i];

  return cache[i] = dfs(n, i + 1, cache) + dfs(n, i + 2, cache);
}

// * Top Down approach with memoization
// * TIME COMPLEXITY O(N) 
// * SPACE COMPLEXITY O(N)
int climbStairs(int n) {
  int ans = 0;
  vector<int> cache(n, -1);
  return dfs(n, 0, cache);
}

// * ------------------------- APPROACH: Optimal Approach -------------------------

// * Bottom Up approach
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int climbStairs2(int n) {
  if (n <= 2)
    return n;

  vector<int> dp(n + 1, 0);
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; ++i) {
    dp[i] = dp[i - 1] + dp[i + 2];
  }
  return dp[n];
}

// * Space Optimized
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int climbStairs3(int n) {
  if (n <= 2)
    return n;

  int one = 1;
  int two = 2;
  int ans = 0;
  for (int i = 3; i <= n; ++i) {
    ans = one + two;
    one = two;
    two = ans;
  }
  return ans;
}

int main(void) {
  // * testcase 1
  // int n = 2;

  // * testcase 2
  // int n = 3;

  // * testcase 3
  // int n = 5;

  // * testcase 4
  int n = 44;

  cout << "N: " << n << endl;

  // int ans = bruteForce(n);
  // int ans = climbStairs(n);
  // int ans = climbStairs2(n);
  int ans = climbStairs3(n);

  cout << "Ans: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-climbing-stairs.cpp -o output && ./output

