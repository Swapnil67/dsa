/*
 * G2. Subsequence Addition (Hard Version)
 *
 * https://codeforces.com/problemset/problem/1807/G2
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
  
// * Time Complexity (TC): O(n log n)
// * Space Complexity (SC): O(n)
void solve() {
  // * take input
  ll n;
  cin >> n;
  vl c(n);
  for (auto &x: c) cin >> x;

  sort(begin(c), end(c)); // * O(n log n)

  // * If the smallest element is not 1, it's impossible to form the array
  if (c[0] > 1) {
    cout << "NO" << '\n';
    return;
  }

  ll sum = 1LL; // * Initialize sum with the first element (which is 1)
  // * Check if each element can be formed by the sum of previous elements
  for (int i = 1; i < n; ++i) {
    // cout << sum << ' ' << c[i] << '\n';
    if (c[i] > sum) {
      cout << "NO" << '\n';
      return;
    }
    sum += c[i];
  }
  
  // * If all elements can be formed, output "Yes"
  cout << "YES" << '\n';
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