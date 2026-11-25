/*
* D. Sharky Surfing
*
* https://codeforces.com
*/

#include <set>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

// ! Observation
/*
* 1. Minimum Jump Needed: To cross a hurdle spanning [l, r], we must jump from at most (l - 1) 
*    to at least (r + 1). Thus, the minimum jump power required is: (r + 1) - (l - 1) = r - l + 2.
* 2. Position Constraint: We can only use power-ups located strictly BEFORE the hurdle we are 
*    currently trying to cross. Power-ups located after the last hurdle are completely useless.
* 3. Greedy Choice: If we pass a power-up and don't need it immediately, we can still keep it in 
*    mind and "retroactively" pick it up later when we encounter a harder hurdle. To minimize the 
*    total number of power-ups used, we should always pick the LARGEST available power-up first.
*/

// ! Approach: 
// * Assign each power-up to the first hurdle after it using binary search, then sweep left-to-right greedily 
// * picking the largest available power-ups from a multiset.

// * Time Complexity: O((n + m) log n + m log m)
// * Space Complexity: O(n + m)
void solve() {
  // * take input
  ll n, m, L; 
  cin >> n >> m >> L;
  
  // * Each tuple stores: {hurdle_start, min_jump_needed, vector_of_powerups_before_this_hurdle}
  vector<tuple<ll, ll, vector<ll>>> a(n);
  for (auto &[x, y, _] : a)
    cin >> x >> y, y = y - x + 2;

  while (m--) {
    ll power_up_pos, power_up_val;
    cin >> power_up_pos >> power_up_val;

    // * Find the first hurdle whose starting position is strictly greater than power-up position 'x'.
    // * Note: tuple compares lexicographically (1st element first). Since power-ups never spawn 
    // * at a hurdle's start 'x', comparing against (x, 0, {}) accurately finds the next hurdle ahead.
    auto it = upper_bound(begin(a), end(a), tuple(power_up_pos, 0, vector<ll>{}));
    
    // * If no hurdle exists after position 'x', this power-up will never be needed.
    if (it == a.end()) continue;
    
    // * Attach this power-up's value to the next hurdle's bucket of available power-ups.
    get<2>(*it).emplace_back(power_up_val);
  }

  ll ans = 0, jump = 1;
  multiset<ll> ms;
  for (auto &[l, d, v] : a) {
    // * Unlock all power-ups located between the previous hurdle and the current hurdle
    for (int p: v) ms.emplace(p);
    
    // * Greedily use the largest available power-ups until we can clear the current hurdle
    while (jump < d) {
      if (ms.empty()) {
        cout << -1 << '\n';
        return;
      }
      jump += *ms.rbegin();     // * add the largest power-up to jump.
      ms.erase(prev(ms.end())); // * remove the greatest power-up.
      ans++;                    // * increase number of power-ups.
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


// * Run the code
// * g++ --std=c++20 D_Sharky_Surfing.cpp -o output && ./output
