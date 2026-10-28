/*
 * Coin Combinations I
 *
 * Calculate the number of distinct ways to produce a money sum x
 * using available coins. 
 * The order of coins matters (permutations).
 * 
 * Print the total number of ways modulo 10^9+7.
 * 
 * https://cses.fi/problemset/task/1635
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
int MOD = 1e9 + 7;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << "\n";
}

// * Faster modulo operation
void add_self(ll &a, ll &b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

// * TIME COMPLEXITY O(X*N)
// * SPACE COMPLEXITY O(N)
void solve() {
  // * Take input
  ll n, x;
  cin >> n >> x;
  vector<ll> coins(n);
  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
  }

  // * dp[s] = total ways to make value s
  vector<ll> dp(x + 1, 0);
  dp[0] = 1;
  for (ll s = 0; s <= x; ++s) {
    // * push dp: we know the value of dp[s] and we propogate further
    for (int coin: coins) {
      if (s + coin <= x) {
        // dp[s + coin] = (dp[s + coin] + dp[s]) % MOD; // * slower
        add_self(dp[s + coin], dp[s]); // * To make it little faster
      }
    }
    // * For debug
    // cout << s << ' '; // printArr(dp);
  }

  cout << dp[x] << '\n';
}

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);

  solve();

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-coin-combinations-I.cpp -o output && ./output

/*
Input:
3 9
2 3 5


Output:
8

Explanation:
2+2+5 = 9
2+5+2 = 9
5+2+2 = 9
3+3+3 = 9
2+2+2+3 = 9
2+2+3+2 = 9
2+3+2+2 = 9
3+2+2+2 = 9
*/