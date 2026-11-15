/*
* C. Math and Physics
*
* https://codeforces.com/contest/2278/problem/C
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

// ! Observation
/*
* This of this a chain reaction
* a = [a1 a2 a3 a4 a5]
* 
* To maximize the total final mass we'll always break some middle neuclear core so weight get
* re-distributed among its neighbors.
* 
* If we break a2 we'll break it in 2 parts x = 1 unit, y = (a2 - 1) units, so that the
* bigger mass can be added to any one neighbor.

* lets say we break a2 = {a2', a2''}
* a = a1 + a2' + a3 + a2'' + a4 + a5
* We can also write above equation as 
* a = a1 + a3 + a4 + a5 + (a2 - 1)
*
* This is nothing but the total_sum - 1
* but this will only work if we've a >= 2 from [2...n-1]
*
* This won't work on following array
* a = [1, 1, 1, 2]
* Here at we have following formula
* ans = total_sum - (n - 1)        (n - 1  are the operations we'll do)
*/

void solve() {
  // * Take input
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll total = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    total += a[i];
  }
    
  // * If all are '1' then answer is -1
  ll maxx = *max_element(begin(a), end(a));
  if (maxx == 1) {
    cout << -1 << '\n';
    return;
  }
  
  // * Check if any mass >= 2 from [2...n-1]
  bool ok = false;
  for (int i = 1; i < n - 1; ++i) {
    if (a[i] >= 2) {
      ok = true;
      break;
    }
  }
  
  if (!ok) { // * eg: a = [2, 1, 1, 1]
    // * total - no. of operations
    cout << total - (n - 1) << '\n';
  } else { // * eg: a = [1, 2, 3, 4]
    // * total - 1
    cout << (total - 1) << '\n';
  }
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

