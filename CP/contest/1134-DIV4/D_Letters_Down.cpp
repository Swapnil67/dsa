/*
 * D. Letters Down
 * 
 * https://codeforces.com/contest/2290/problem/D 
*/

#include <vector>
#include <iostream>
#include <algorithm>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

// * Macros
#define all(v) v.begin(), v.end()
#define PRINT_VEC_PAIRS(p) for (auto &it: p) cout << it.first << ' ' << it.second << '\n'

/*
* (97)a---------c(99)
*        (98)b------------d(100)
* Above is overlapping components 
* Total cost = (d - c) + (c - b) + (b - a) => (d - a)

* l1------r1
*    l2-------r2
* Total cost = (r2 - l1)
*/

// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
void solve() {
  // * take input
  ll n;
  string s;
  cin >> n >> s;

  // * create pairs of components & sort them
  vector<pair<int, int>> pairs;
  for (int i = 0; i < n; ++i) {
    int a = (int)s[i], b = (int)s[n - i - 1];
    if (a > b)
      swap(a, b);
    pairs.push_back({a, b});
  }
  sort(all(pairs));
  // PRINT_VEC_PAIRS(pairs);

  ll ans = 0;
  auto [l1, r1] = pairs[0];
  for (auto [l2, r2]: pairs) {
    // cout << l1 << ' ' << r1 << " & " << l2 << ' ' << r2 << '\n';
    if (l2 <= r1) { // * Check if overlapping pair
      r1 = max(r1, r2);
    } else { // * add the changes for previous overlapping components
      ans += (r1 - l1);
      l1 = l2, r1 = r2;
    }
  }
  ans += (r1 - l1); // * For last component.

  cout << ans << '\n';
}

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--)
    solve();
  
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 D_Letters_Down.cpp -o output && ./output

// * https://codeforces.com/bestRatingChanges/21722089