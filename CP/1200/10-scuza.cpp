/*
 * E. Scuza
 *
 * https://codeforces.com/problemset/problem/1742/E
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


// * Per testcase
// * Time Complexity: O(n + q log n)
// * Space Complexity: O(n)
void solve() {
  // * Input
  ll n, q;
  cin >> n >> q; // * n = size of array, q = number of queries
  vector<ll> a(n);
  for (auto &it : a)
    cin >> it;

  // * Precompute running prefix maximums for array a
  vector<ll> pre_max(n);
  pre_max[0] = a[0];
  for (ll i = 1; i < n; i++) {
    pre_max[i] = max(pre_max[i - 1], a[i]); // * Store max up to index i
  }
  // PRINT_VEC(pre_max);

  // * Precompute prefix sums of array a
  vector<ll> p(n + 1, 0); // p[0] = 0
  for (ll i = 1; i <= n; i++) {
    p[i] = p[i - 1] + a[i - 1];
  }
  // PRINT_VEC(p);

  // * Answer queries
  while (q--) {
    ll x;
    cin >> x; // Query value

    // * Find first index where running max > x
    ll idx = upper_bound(pre_max.begin(), pre_max.end(), x) - pre_max.begin();
    // cout << x << ' ' << idx << '\n';

    // * Output sum of all elements <= x
    // * Using prefix sum array for O(1) retrieval
    cout << p[idx] << ' ';
  }
  cout << "\n"; 
}

int main() {
  ll t;
  cin >> t; // Number of test cases

  while (t--)
    solve();

  return 0;
}

// * Run the code
// * g++ --std=c++20 10-scuza.cpp -o output && ./output

// * Testcase
/*
3
4 5
1 2 1 5
1 2 4 9 10
2 2
1 1
0 1
3 1
1000000000 1000000000 1000000000
1000000000


*/

// * Output
/*
1 4 4 9 9 
0 2 
3000000000 

*/