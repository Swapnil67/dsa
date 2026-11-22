/*
 * A. Preparing for the Olympiad
 *
 * https://codeforces.com/contest/2051/problem/A
*/

#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<int> vi;

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
void solve() {
  // * take input
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vi b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  int ans = a[n - 1]; // * Last problem will be solved by monocarp only since there no problem after that.
  int j = n - 2;
  while (j >= 0) {
    // * Only solve problem if diff is positive, so it will increase our answer more.
    if (a[j] - b[j + 1] >= 0) {
      ans += (a[j] - b[j + 1]); // * increase our gap
    }
    j--;
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
// * g++ --std=c++20 A_Preparing_for_the_Olympiad.cpp -o output && ./output
