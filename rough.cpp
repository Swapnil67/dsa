#include <vector>
#include <iostream>
#include <algorithm>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define PRINT_VEC(p) \
  for (auto &it : p) \
  cout << it << ' '; cout << '\n'
  
void solve() {
  // * take input
  int n;
  string s;
  cin >> n >> s;
  
  int l,r;
  bool ok = false;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] > s[i + 1]) {
      swap(s[i], s[i + 1]);
      l = i, r = i + 1;
      ok = true;
      break;
    }
  }
  // cout << s << '\n';
  
  if (ok) {
    cout << "YES" << '\n';
    cout << l << ' ' << r << '\n';
  } else {
    cout << "NO" << '\n';
  }
  
}

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  // ll t;
  // cin >> t;
  // while (t--)
  solve();

  return 0;
}

// * Run the code
// * g++ --std=c++20 rough.cpp -o output && ./output
