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
// * Partition the sum in two parts such that
// * (sum1 - sum2) is minimized.
void solve() {
  // * take input
  int n;
  cin >> n;
  
  // * we do this becoz we need abs(sum1 - sum2) to be minimized
  ll sum1 = n / 2;
  ll sum2 = n - sum1;
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