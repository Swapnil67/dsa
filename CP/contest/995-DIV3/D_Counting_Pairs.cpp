/*
 * D. Counting Pairs
 *
 * https://codeforces.com/contest/2051/problem/D
*/

#include <vector>
#include <iostream>
#include <algorithm>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define PRINT_VEC(p)   \
  for (auto &it : p)   \
    cout << it << ' '; \
  cout << '\n'

// ! Observation
// ! Binary Search

/* 
* We know that
* x <= sum - (a[i]+a[j]) <= y
* x - sum <= -(a[i]+a[j]) <= y - sum
* sum - x >= (a[i]+a[j]) <= sum - y
*
* let x' = sum - x  and y' = sum - y
*
* y' <= (a[i] + a[j]) <= x'
*
* y' - a[i] <= a[j] <= x' - a[i]
*
* So now we fix a[i] and find valid a[j].
* 
* 
*                           Valid Pairs
*                       <----------------->
* ------------------------------------------------------------
*        a[i]           L                 R
*          ^
*                      
* L = y' - a[i]
* R = x' - a[i]
*
* ans += (R - L) ------ valid pairs
*
*/

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
void solve() {
  // * take input
  ll n, x, y;
  cin >> n >> x >> y;
  vl a(n, 0);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  sort(begin(a), end(a));
  
  ll x1 = sum - x;
  ll y1 = sum - y;
  // cout << x1 << ' ' << y1 << '\n'; 
  
  ll ans = 0;
  
  for (int i = 0; i < n; ++i) {
    ll k = y1 - a[i];
    ll lb = lower_bound(begin(a) + i + 1, end(a), k) - begin(a);
    k = x1 - a[i];
    ll ub = upper_bound(begin(a) + lb, end(a), k) - begin(a);
    // cout << ub << " - " << lb << " = " << (ub-lb) << '\n';
    ans += (ub - lb);
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