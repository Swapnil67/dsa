/*
 * B. Journey
 *
 * https://codeforces.com/contest/2051/problem/B
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

// * Time Complexity: O(1)
// * Space Complexity: O(1)
void solve() {
  // * take input
  ll n, a, b, c;
  cin >> n >> a >> b >> c;
  
  ll sum = a + b + c;
  ll d = n / sum * 3; // * Total days to reach atleast n with 3 different speed
  // cout << d << '\n';
  
  if (n % sum == 0) {
    cout << d << '\n';
  } 
  else if (n % sum <= a) {
    cout << (d + 1) << '\n';
  } 
  else if (n % sum <= a + b) {
    cout << (d + 2) << '\n';
  } 
  else {
    cout << (d + 3) << '\n';
  }
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