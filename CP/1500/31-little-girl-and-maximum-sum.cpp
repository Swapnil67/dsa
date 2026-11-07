/*
* C. Little Girl and Maximum Sum
*
* https://codeforces.com/contest/276/problem/C
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
  
void solve() {
  // * take input
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) 
    cin >> a[i];
    
  // * Sort array to later match largest values
  // * with highest frequencies
  sort(begin(a), end(a));
  // PRINT_VEC(a);
  
  vector<ll> diff(n, 0);
  // * Process queries
  for (int i = 0; i < q; i++) {
    int L, R;
    cin >> L >> R;

    L--, R--; // * convert to 0-based indexing

    diff[L]++; // * start adding frequency
    if (R + 1 < n)
      diff[R + 1]--; // * stop after R
  }
  // PRINT_VEC(diff);
  
  // * Prefix sum to compute actual frequency
  // * range[i] = number of queries covering index i
  for (int i = 1; i < n; ++i) {
    diff[i] += diff[i - 1];
  }
  sort(begin(diff), end(diff)); // * Sort frequencies
  // PRINT_VEC(diff); 
  
  // * Multiply smallest freq with smallest value
  // * (Rearrangement inequality → maximum sum)
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += (diff[i] * a[i]);
  }
  cout << ans << '\n';
    
}

int main() {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  // ll t;
  // cin >> t;
  // while (t--)
  solve();
  
  return 0;
}

