/*
 * C. Quests
 *
 * https://codeforces.com/problemset/problem/1914/C
*/
 
#include <vector>
#include <iostream>
#include <algorithm>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

// ! Greedy with prefix sums
// * Time Complexity (TC): O(n)
// * Space Complexity (SC): O(n)
void solve() {
  // * take input
  ll n, k;
  cin >> n >> k;
  vl a(n), b(n);
  for (auto&x: a) cin >> x;
  for (auto&x: b) cin >> x;
  
  ll cur = 0, ans = 0, b_max = 0;
  for (int i = 0; i < n && k > 0; ++i) {
    k--;
    cur += a[i];                         // * Add the experience points for the first completion
    b_max = max(b_max, b[i]);            // * Update the maximum experience points for subsequent completions
    ans = max(ans, (cur + (k * b_max))); // * Calculate the maximum possible total experience
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
// * g++ --std=c++20 02_C_Quests.cpp -o output && ./output
