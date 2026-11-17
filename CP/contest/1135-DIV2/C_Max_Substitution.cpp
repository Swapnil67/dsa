/*
* C. Max Substitution
*
* https://codeforces.com/contest/2285/problem/C
*/

#include <vector>
#include <iostream>
#include <algorithm>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define PRINT_VEC(p)   \
  for (auto &it : p)   \
    cout << it << ' '; \
  cout << '\n'
  
int M = 1e9 + 7;

// ! Observation
/*
* a = [7 6 2 2]
*
* We'll fix each element and check how many ways we can get distinct arrays.
*
* 0 element           -> 1 way.
* 1 element (7)       -> 6 ways.
* 2 element (7, 6)    -> 5 * 5 ways.
* 3 element (7, 6, 2) -> Invalid since 2 is not unique largest element.
*
* Total = 32 ways
*/
  
ll modPow(ll base, ll exp) {
  // cout << base << ' ' << exp << '\n';
  ll res = 1;
  base %= M;
  while (exp > 0) {
    if (exp & 1) res = (res * base) % M;
    base = (base * base) % M;
    exp >>= 1; // * divide by 2
  }
  return res;
}

// * Time Complexity (TC): O(n)
// * Space Complexity (SC): O(1)
void solve() {
  // * take input
  ll n;
  cin >> n;
  vl a(n);
  for(auto &x: a) cin >> x;
  
  sort(begin(a), end(a));
  reverse(begin(a), end(a));
  
  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    if (i != n - 1 && a[i] == a[i + 1]) {
      break;
    }
    
    ll ways = modPow(a[i] - 1, i + 1);
    // cout << ways << '\n';
    ans += ways;
    ans %= M;
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
// * g++ --std=c++20 C_Max_Substitution.cpp -o output && ./output
