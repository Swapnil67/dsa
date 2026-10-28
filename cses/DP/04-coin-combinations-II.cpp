/*
 * Coin Combinations II
 * 
 * Calculate the number of distinct ordered ways (combinations) to 
 * produce a money sum x using available coins. 
 * 
 * The order of coins does not matter. 
 * Print the number of ways modulo 10^9+7.
 * 
 * https://cses.fi/problemset/task/1636
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
int MOD = 1e9 + 7;
const int INF = 1e9 + 5;

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

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);

  // * Take input
  ll n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
  }

  // * dp[s] = total distinct ways to make value s
  vector<ll> dp(x + 1, 0);
  dp[0] = 1;
  for (int coin: coins) {
    for (int s = 0; s < x; ++s) {
      if (s + coin <= x) {
        // dp[s + coin] = (dp[s + coin] + dp[s]) % MOD; // * slower
        add_self(dp[s + coin], dp[s]);
      }
    }
    // * For debug
    // cout << coin << ' '; 
    // printArr(dp);
  }

  cout << dp[x] << '\n';

  return 0;
}


// * Run the code
// * g++ --std=c++20 04-coin-combinations-II.cpp -o output && ./output

/*
Input:
3 9
2 3 5

Output:
3

Explanation:
2+2+5 = 9
3+3+3 = 9
2+2+2+3 = 9
*/