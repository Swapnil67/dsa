/*
 * Leetcode - 1137
 * N-th Tribonacci Number
 * 
 * The Tribonacci sequence Tn is defined as follows: 
 * T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

 * Example 1 :
 * Input     : n = 4
 * Output    : 4
 * 
 * Example 2 :
 * Input     : n = 25
 * Output    : 1389537
 * 
 * https://leetcode.com/problems/n-th-tribonacci-number/description/
 * https://www.geeksforgeeks.org/problems/tribonacci-number/1
 * https://www.naukri.com/code360/problems/tribonacci-sequence_3929491
*/

// ! Amazon, Google, Meta

#include <vector>
#include <iostream>

using namespace std;
const int MOD = 1e9 + 7;

long long dfs_brute(int n) {
  if (n <= 1)
    return n;

  if (n == 2)
    return 1;

  return (dfs_brute(n - 1) + dfs_brute(n - 2) + dfs_brute(n - 3)) % MOD;
}

long long dfs(int n, vector<long long> &cache) {
  if (cache[n] != -1)
    return cache[n];
  return cache[n] = (dfs(n - 1, cache) + dfs(n - 2, cache) + dfs(n - 3, cache)) % MOD;
}

// * Top Down approach (Without Memoization)
// * TIME COMPLEXITY O(3^N)
// * SPACE COMPLEXITY O(3^N)
int bruteForce(int n) {
  return dfs_brute(n);
}

// * Top Down approach (With Memoization)
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int betterApprach(int n) {
  vector<long long> cache(100, -1);
  cache[0] = 0;
  cache[1] = 1;
  cache[2] = 1;
  return dfs(n, cache);
}

// * Bottom Up Approach
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int tribonacci(int n) {
  vector<long long> dp(40, 0);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;
  for (int i = 3; i <= n; ++i) {
    dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
  }
  return dp[n];
}

// * Bottom Up Approach (Space Optimizatoin)
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int tribonacci2(int n) {
  if (n == 0)
    return 0;
    
  if (n == 1 || n == 2)
    return 1;

  long long a = 0, b = 1, c = 1; 
  long long ans = 0;

  for (int i = 3; i <= n; ++i) {
    ans = (a + b + c) % MOD;
    a = b;
    b = c;
    c = ans;
  }

  return ans % MOD;
}

int main(void) {
  // * testcase 1
  // int n = 4;
  
  // * testcase 2
  // int n = 25;
  
  // * testcase 3
  int n = 95;

  cout << "n: " << n << endl;
  
  // int ans = bruteForce(n);
  int ans = betterApprach(n);
  // int ans = tribonacci(n);
  // int ans = tribonacci2(n);
  cout << "Ans: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-nth-tribonacci-number.cpp -o output && ./output

