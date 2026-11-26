/*
* B. Startup
*
* https://codeforces.com/contest/2036/problem/B
*/

#include <vector>
#include <iostream>
#include <algorithm>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define PRINT_VEC_PAIRS(p) for (auto &it: p) cout << it.first << ' ' << it.second << '\n'

// ! Approach: 
// * Time Complexity: O(n + klogk)
// * Space Complexity: O(k)
void solve() {
  // * take input
  ll n, k;
  cin >> n >> k;
  vector<ll> cost_of_brand(k + 1, 0);
  while (k--) {
    ll b, c;
    cin >> b >> c;
    cost_of_brand[b] += c;
  }
  
  sort(begin(cost_of_brand), end(cost_of_brand)); // * O(klogk)

  ll ans = 0;
  // * Greedily take the 'n' bottles with larger total cost.
  for (int i = cost_of_brand.size() - 1; (n > 0 &&i >= 0); --i) {
    if (cost_of_brand[i] > 0) {
      ans += cost_of_brand[i];
      n--;
    }
  }
  
  cout << ans << '\n';
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

