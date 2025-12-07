/*
 * Leetcode - 1553
 * Minimum Number of Days to Eat N Oranges 
 * 
 * There are n oranges in the kitchen and you decided to eat some of these oranges every day as follows:
 * 
 * - Eat one orange.
 * - If the number of remaining oranges n is divisible by 2 then you can eat n / 2 oranges.
 * - If the number of remaining oranges n is divisible by 3 then you can eat 2 * (n / 3) oranges.
 * 
 * You can only choose one of the actions per day.
 * 
 * Given the integer n, return the minimum number of days to eat n oranges.
 * 
 * https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges
*/

// ! Google

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

int solve(int n, std::unordered_map<int, int> &dp) {
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


// * ------------------------- APPROACH 1: Brute Force -------------------------
// ! TLE
// * Dynamic Programming (Top-Down)
// * TIME COMPLEXITY  O(N)
// * SPACE COMPLEXITY O(N)
int bruteForce(int n) {
  std::unordered_map<int, int> dp;
  dp[0] = 0;
  dp[1] = 1;
  int res = solve(n, dp);
  return res;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------
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

// * ------------------------- APPROACH 3: Optimal Approach -------------------------
// * BFS
// * TIME COMPLEXITY  O(logN)
// * SPACE COMPLEXITY O(logN)
int minDaysBFS(int n) {
  if (n <= 1)
    return n;

  std::queue<int> q;
  q.push(n);

  std::unordered_set<int> visit;

  int level = 0;
  while (!q.empty()) {
    level++;
    int N = q.size();
    while (N--) {
      int node = q.front();
      q.pop();

      int nei = node - 1;
      if (nei == 0)
        return level;

      if (!visit.count(nei)) {
        visit.insert(nei);
        q.push(nei);
      }
      
      // * check if divisible by '2' or '3'
      for (int i = 2; i <= 3; ++i) {
        if (node % i == 0) {
          nei = node / i;
          if (nei == 0)
            return level;

          if (!visit.count(nei)) {
            visit.insert(nei);
            q.push(nei);
          }
        } 
      }
    }
  }

  return level;
}

int main(void) {
  int n = 10;
  std::cout << "Oranges: " << n << std::endl;

  // int min_days = bruteForce(n);
  // int min_days = minDays(n);
  int min_days = minDaysBFS(n);
  std::cout << "Minimum Days: " << min_days << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 05-min-no-of-days-to-eat-n-oranges.cpp -o output && ./output
