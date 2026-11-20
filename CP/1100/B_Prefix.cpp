/*
 * B. Prefix
 *
 * https://codeforces.com/contest/2274/problem/B
*/

#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define PRINT_VEC(p)   \
  for (auto &it : p)   \
    cout << it << ' '; \
  cout << '\n'

int M = 1e9 + 7;

/*
 * CORE PATTERN & OBSERVATION:
 * - 's' is the sum of ALREADY-MODIFIED elements before index i (s = a[0] + ... + a[i-1]).
 * - Because each step branches into 3 choices, there are many possible past prefix sums.
 * - Since all transitions are linear and non-decreasing, we only need to track the two
 *   extremes: 'smin' (smallest possible past prefix sum) and 'smax' (largest possible).
 *
 * EXAMPLE TRACE (How [3, -5] reaches a prefix sum of 1 at index 1):
 * - Start (i = 0): Prefix sum s = a[0] = 3.
 * - At i = 1 (a[1] = -5), we have 3 choices to replace a[1]:
 *     1. a[1] - s = -5 - 3 = -8  -> Array: [3, -8] -> New sum: 3 + (-8) = -5 (smin)
 *     2. a[1]     = -5           -> Array: [3, -5] -> New sum: 3 + (-5) = -2
 *     3. a[1] + s = -5 + 3 = -2  -> Array: [3, -2] -> New sum: 3 + (-2) =  1 (smax)
 * - Notice how modifying a[1] in-place changes the running sum for all future steps!
 */

// Time Complexity: O(n)
// Space Complexity: O(1)
void solve() {
  // * take input
  ll n;
  cin >> n;
  vl a(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];
  
  vl b = a;
  ll ans = a[0];
  ll smin = a[0];
  ll smax = a[0];
  for (int i = 1; i < n; ++i) {
    // 1. Maximize current element a[i] using extremes of previous prefix sum s:
    //    - Subtracting the smallest/most negative sum (a[i] - smin) maximizes a[i]
    //    - Adding the largest sum (a[i] + smax) maximizes a[i]
    ll max_val = max({a[i]-smin, a[i]+smax, a[i]});
    ans = max(ans, max_val);
    
    // 2. Update running prefix sum bounds (new_s = old_s + new_a[i]):
    //    Since all 3 transitions are non-decreasing functions of s:
    //      - Choose a[i] - s  =>  s + (a[i] - s) = a[i]
    //      - Choose a[i]      =>  s + a[i]
    //      - Choose a[i] + s  =>  s + (a[i] + s) = 2*s + a[i]
    //    New extremes come directly from plugging smin and smax into these 3 formulas.
    smin = min({smin+a[i]-smin, smin+a[i]+smin, smin+a[i]});
    smax = max({smax+a[i]-smax, smax+a[i]+smax, smax+a[i]});
    // cout << smin << ' ' << smax << '\n';
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

