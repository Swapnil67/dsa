/*
 * Minimizing Coins
 *
 * Consider a money system consisting of n coins. Each coin has a positive integer value. 
 * Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
 * 
 * For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
 * 
 * Find the minimum number of coins needed to produce a target sum x using a given set of coin values, 
 * or return -1 if impossible.
 * 
 * Constraints:
 * 1 <= n <= 100, 
 * 1 <= x <= 10^6 
 * 1 <= c_i <= 10^6 
 *
 * https://cses.fi/problemset/task/1634
 * https://leetcode.com/problems/coin-change/description/
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
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

// * TIME COMPLEXITY O(n*x)
// * SPACE COMPLEXITY O(n)
void solve() {
  // * Take input
  ll n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
  }
  
  // * dp[s] == min number of coins used to get to sum s  
  vector<int> dp(x + 1, INF);
  dp[0] = 0;
  for (int s = 0; s < x; ++s) {
    // * push dp: we know the value of dp[s] and we propogate further
    for (int coin: coins) {
      if (s + coin <= x) {
        dp[s + coin] = min(dp[s + coin], dp[s] + 1);
      }
    }
  }

  if (dp[x] >= INF) {
    cout << -1 << '\n';
  } else {
    cout << dp[x] << '\n';
  }
}

// * TIME COMPLEXITY O(n*x)
// * SPACE COMPLEXITY O(n)
void solveWithPath() {
  // * Take input
  ll n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
  }
  
  // * dp[s] == min number of coins used to get to sum s  
  vector<int> dp(x + 1, INF);
  dp[0] = 0;
  vector<int> parent(x + 1, -1);
  for (int s = 0; s < x; ++s) {
    // * push dp: we know the value of dp[s] and we propogate further
    for (int coin: coins) {
      if (s + coin <= x) {
        if (dp[s + coin] > (dp[s] + 1)) {
          dp[s + coin] = (dp[s] + 1);
          parent[s + coin] = coin; // * To reach 's + coin' we came from 'coin'
        }
      }
    }
  }
  // printArr(dp);
  // printArr(parent);

  // * Find the path using parent vector
  vector<int> path;
  int cur_amount = x;
  while (cur_amount > 0) {
    int coin = parent[cur_amount];
    path.push_back(coin);
    cur_amount -= coin;
  }

  cout << "path: ";
  printArr(path);
}

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);

  // solve();
  solveWithPath();

  return 0;
}


// * Run the code
// * g++ --std=c++20 02-minimizing-coins.cpp -o output && ./output

/*
Input:
3 11
1 5 7


Output:
3

Explanation:
coins = [1 5 5]
*/