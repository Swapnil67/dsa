/*
 * C. Assembly via Minimums
 * 
 * https://codeforces.com/problemset/problem/1857/C
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

#define PRINT_VEC(p) \
  for (auto &it : p) \
  cout << it << ' '; cout << '\n'

// * Time Complexity:  O(mlogm)
// * Space Complexity: O(1)
void solve() {
  // * Take input
  ll n;
  cin >> n;
  
  ll m = (n * (n - 1) / 2);
  
  vector<ll> b(m);
  for (int i = 0; i < m; ++i)
    cin >> b[i];

  sort(begin(b), end(b));
  
  // * Reconstruct array 'a' from sorted 'b'
  // * The smallest element occurs (n-1) times, next smallest (n-2) times, etc.
  int x = n - 1, i = 0;
  while (x > 0) {
    cout << b[i] << ' ';
    i += x;
    x--;
  }
  
  // * Add a large number as the last element to complete array 'a'
  // * Any large number works to satisfy the constraints
  cout << 1000000000 << '\n';
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
// * Run the code
// * g++ --std=c++20 04-assembly-via-minimums.cpp -o output && ./output

// * Testcase
/*
5
3
1 3 1
2
10
4
7 5 3 5 3 3
5
2 2 2 2 2 2 2 2 2 2
5
3 0 0 -2 0 -2 0 0 -2 -2

*/

// * Output
/*
1 3 1000000000
10 1000000000
3 5 7 1000000000
2 2 2 2 1000000000
-2 0 0 3 1000000000
*/