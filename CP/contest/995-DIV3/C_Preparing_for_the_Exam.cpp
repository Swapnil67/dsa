/*
 * C. Preparing for the Exam
 *
 * https://codeforces.com/contest/2051/problem/C
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
/*
* k == n         all list can be solved.
* k < n - 1      no list can be solved.
* k == n - 1     exactly one list can be solved.
*/

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
void solve() {
  // * take input
  ll n, m, k;
  cin >> n >> m >> k;

  vl a(m); // * list
  for (int i = 0; i < m; ++i) cin >> a[i];

  vl q(k); // * problems which we can solve
  for (int i = 0; i < k; ++i) cin >> q[i];

  vector<int> res(m);
  if (k == n) { // * all list can be solved.
    for (int i = 0; i < m; ++i)
      res[i] = 1;
  } else if (k == n - 1) { // * exactly one list can be solved
    // * Find question which is not present in the list
    int list_num = 1;
    for (auto ele : q) {
      if (ele == list_num)
        list_num++;
    }
    // * Update the only list which we are able to solve
    for (int i = 0; i < m; ++i) {
      if (a[i] == list_num)
        res[i] = 1;
    }
  }

  for (int i = 0; i < m; ++i)
    cout << res[i];
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
 
// * Run the code
// * g++ --std=c++20 A_Preparing_for_the_Olympiad.cpp -o output && ./output
