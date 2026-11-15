#include <vector>
#include <iostream>
#include <algorithm>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define PRINT_VEC(p) \
  for (auto &it : p) \
  cout << it << ' '; cout << '\n'
  
// * Observation
// * Partition the array in two parts such that
// * (sum1 - sum2) is minimized.
  
void solve() {
  // * take input
  int n;
  cin >> n;
  vector<ll> a(n);
  ll total_sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] = (1 << a[i]);
    total_sum += a[i];
  }
  
  // * Sort in descending
  sort(rbegin(a), rend(a));
  // PRINT_VEC(a);
  
  ll sum1 = 0;
  for (int i = 0; i < n; ++i) {
    if (sum1 + a[i] > (total_sum / 2)) {
    } else {
      sum1 += a[i];
    }
  }
  
  ll sum2 = total_sum - sum1;
  // cout << sum1 << ' ' << sum2 << '\n';
  cout << (sum1 * sum2) << '\n';
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