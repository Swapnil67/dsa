/*
* E. Power of Points
*
* https://codeforces.com/problemset/problem/1857/E
*/


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
#define PRINT_VEC(p)   \
  for (auto &it : p)   \
    cout << it << ' '; \
  cout << '\n'
  
/*
* Observation
* a = [x1, x2, x3, x4, x5]
*
* if we take x3 (i = 3) then we'll have following ranges
* [x1, x3], [x2, x3], [x3, x3], [x3, x4], [x3, x5]
*
* So we can say that range [x1, x3] is adding '1' all points from x1...x3 
* so tatal is x3 - x2 + 1 points got added, same we can do for all ranges
* (x3 - x1 + 1)
* (x3 - x2 + 1)
* (x3 - x3 + 1)
* (x4 - x3 + 1)
* (x5 - x3 + 1)
*
* 
* So we can generalize this as
* 
* n + i*x3 - (n-i) * x3 - pre[i] + suf[i + 1]
* n + i*x3 - x3*n + x3i - pre[i] + suf[i + 1]
* n + x3*2*i - x3*n - pre[i] + suf[i + 1] 
* n + x3*(2 * i - n) - pre[i] + suf[i + 1] --- (take x3 common)
*/

void solve() {
  // * take input
  int n;
  cin >> n;
  vector<pair<ll, ll>> x(n);
  ll prefix_sum = 0, suffix_sum = 0;
  for (int i = 0; i < n; ++i) { 
    cin >> x[i].first;
    x[i].second = i;
    suffix_sum += x[i].first;
  }
  sort(begin(x), end(x));
  
  vector<ll> ans(n);
  for (int i = 0; i < n; ++i) { 
    // Current value is being processed,
    ll s = x[i].first;
    
    // so remove it from suffixSum
    suffix_sum -= s;
    
    // Add it to prefixSum
    prefix_sum += s;
    
    ans[x[i].second] = n + s * (2LL * (i + 1) - n) - prefix_sum + suffix_sum;
  }
  
  for (int i = 0; i < n; ++i) { 
    cout << ans[i] << ' ';
  }
  cout << '\n';
  
}

int main() {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  ll t;
  cin >> t;
  while (t--)
    solve();
  
  return 0;
}

