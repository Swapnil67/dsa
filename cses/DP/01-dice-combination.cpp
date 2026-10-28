/*
 * Dice Combinations
 * 
 * Description:
 * Your task is to count the number of ways to construct a sum n by throwing a dice one or more times. 
 * Each throw produces an outcome between 1 and 6. Since the answer can be very large, return the 
 * number of ways modulo 10^9 + 7.
 * 
 * Constraints:
 * 1 <= n <= 10^6
 * 
 * Example 1    :
 * Input        : n = 3
 * Output       : 4
 * Explanation  : There are 4 distinct sequences of dice throws that sum up to 3:
 *                - 1 + 1 + 1
 *                - 1 + 2
 *                - 2 + 1
 *                - 3
 * 
 * Example 2    :
 * Input        : n = 4
 * Output       : 8
 * Explanation  : There are 8 distinct sequences of dice throws that sum up to 4:
 *                - 1 + 1 + 1 + 1
 *                - 1 + 1 + 2
 *                - 1 + 2 + 1
 *                - 2 + 1 + 1
 *                - 2 + 2
 *                - 1 + 3
 *                - 3 + 1
 *                - 4
 *
 * https://cses.fi/problemset/task/1633
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
int MOD = 1e9 + 7;

// * TIME COMPLEXITY O(n * 6)
// * SPACE COMPLEXITY O(n)
int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;

  vl dp(n + 1); 
  dp[0] = 1; // * Base case

  // * Check for all possible sum from 0 to n
  for (ll s = 0; s < n; ++s) {
    for (int i = 1; i <= 6; ++i) {
      if (i + s <= n) {
        dp[s + i] = (dp[s] + dp[s + i]) % MOD;
      }
    }
  }

  cout << dp[n] << '\n';

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 01-dice-combination.cpp -o output && ./output

/*
Input:
3

Output:
4

Explanation:
[1,1,1], [1,2], [2,1], [3]
*/