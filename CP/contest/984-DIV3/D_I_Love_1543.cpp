/*
* D. I Love 1543
*
* https://codeforces.com/contest/2036/problem/D
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

// ! Observation
// * Create the spiral layer for each layer.

// ! Approach: Brute force the spiral
// * Time Complexity: O(n + q)
// * Space Complexity: O(1)
void solve() {
  // * take input
  ll n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      cin >> a[r][c];
    }
  }

  ll ans = 0;
  for (int k = 0; k < min(n, m) / 2; ++k) {
    // vector<char> layer;
    string layer = "";

    // * 1. Top: left to right (includes top-left and top-right corners)
    int r = k, c = k;
    for (int c = k; c < m - k; ++c) {
      layer += a[r][c];
    }

    // * 2. Right: top+1 to bottom-1 (excludes corners)
    for (int r = k + 1; r < n - k - 1; ++r) {
      layer += a[r][m - k - 1];
    }

    // * 3. Bottom: right to left (includes bottom-right and bottom-left corners)
    for (int c = m - k - 1; c >= k; --c) {
      layer += a[n - k - 1][c];
    }

    // * 4. Left: bottom-1 to top+1 (excludes corners)
    for (int r = n - k - 2; r > k; --r) {
      layer += a[r][c];
    }

    // * For circular check
    if (layer.size() >= 4) {
      string s = layer.substr(0, 3);
      layer += s;
    }

    // * Check occurence of 1543 in string 'layer'
    for (int i = 0; i <= layer.size() - 3; ++i) {
      string s = layer.substr(i, 4);
      if (s == "1543")
        ans++;
    }

    // cout << layer << '\n';
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
// * g++ --std=c++20 D_I_Love_1543.cpp -o output && ./output
