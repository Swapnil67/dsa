/*
* A. Twice
*
* https://codeforces.com/contest/2037/problem/A
*/

#include <map>
#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

// * Time Complexity: O(n)
// * Space Complexity: O(n)
void solve() {
  // * take input
  int n; cin >> n;
  vl a(n);
  for (auto &x: a) cin >> x;
  
  map<int, int> freq_mp;
  for (auto &x: a) {
    freq_mp[x]++;
  }
  
  ll ans = 0;
  for (auto [val, freq]: freq_mp) {
    ans += (freq / 2);
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
// * g++ --std=c++20 A_Twice.cpp -o output && ./output
