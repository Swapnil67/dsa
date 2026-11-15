/*
* B. Stakes and Shapes
*
* https://codeforces.com/contest/2278/problem/B
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

void solve() {
  int r, s, p;
  cin >> r >> s >> p;
  string ans = "";
  if (r >= s && r >= p) { // * Playing all Paper
    ans = string(r + s + p, 'P');
  } else if (s >= r && s >= p) { // * Playing all Rock
    ans = string(r + s + p, 'R');
  } else { // * Playing all Scissors 
    ans = string(r + s + p, 'S');
  }
  cout << ans << '\n';
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

