/*
* D. Digital string maximization
*
* https://codeforces.com/contest/2050/problem/D
*/

#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

vector<vl> dp;
int n, m;

ll dfs(int i, int j, string &a, string &b, string &c) {
  if (i >= n && j >= m) 
    return 0;
    
  if (dp[i][j] != -1)
    return dp[i][j];
    
  int pos = i + j; // * pos in c
  ll res = 1e8;
  
  if (i < n) {
    ll cost = dfs(i + 1, j, a, b, c) + (c[pos] != a[i]);
    res = min(res, cost);
  }
  
  if (j < m) {
    ll cost = dfs(i, j + 1, a, b, c) + (c[pos] != b[j]);
    res = min(res, cost);
  }
  
  return dp[i][j] = res; 
}

// * Time Complexity: O(n*m)
// * Space Complexity: O(n*m)
void solve() {
  // * take input
  string a, b, c;
  cin >> a >> b >> c;
  n = a.length(), m = b.length();

  // * dp[i][j] = min cost of char changes to make string c[0..i+j] from a[0....i] & b[0....j]
  dp.assign(n + 1, vector<ll>(m + 1, -1));

  cout << dfs(0, 0, a, b, c) << '\n';
}

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  ll t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}