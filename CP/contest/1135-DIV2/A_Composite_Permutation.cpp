/*
* B. Diverse String
*
* https://codeforces.com/contest/2285/problem/B
*/

#include <set>
#include <vector>
#include <iostream>
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
  cin >> n;
  if (n <= 3) {
    cout << -1 << '\n';
    return;
  }

  set<int> st = {1, 2, 3};
  vector<int> a(n + 2, -1);
  int p = 4;
  a[4] = 1;
  a[2] = 2;
  a[3] = 3;
  int idx = 1;
  while (p <= n) {
    if (st.count(p)) {
      p++;
      continue;
    }
    if (a[idx] == -1) {
      a[idx] = p;
      st.insert(p);
      p += 1;
    }
    idx += 1;
  }

  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != -1)
      cout << a[i] << ' ';
  }
  cout << '\n';
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


// https://codeforces.com/bestRatingChanges/21736121