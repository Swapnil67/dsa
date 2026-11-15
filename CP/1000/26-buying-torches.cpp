#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define PRINT_VEC(p) \
  for (auto &it : p) \
  cout << it << ' '; cout << '\n'

long long ceil_division(long long a, long long b) {
  return (a + b - 1) / b;
}

// * TIME COMPLEXITY O(1)
// * SPACE COMPLEXITY O(1)
void solve() {
  // * take input
  ll x, y, k;
  cin >> x >> y >> k;

  // * 1 torch requires 1 stick and 1 coal, hence k torches require k sticks and k coals
  ll total_sticks = (y * k) + (k - 1);

  ll trades = 0;
  // * Calculate the no. of trades needed to gain the required no. of sticks
  trades += ceil_division(total_sticks, (x - 1LL));
  // * Add the number of trades needed to get k coals
  trades += k;
  // cout << total_sticks << ' ' << total_trades << '\n';
  
  cout << trades << '\n';
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