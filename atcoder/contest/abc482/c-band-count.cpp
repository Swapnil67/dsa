/*
* C - Band Count
*
* https://atcoder.jp/contests/abc482/tasks/abc482_c
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define PRINT_VEC(p)   \
  for (auto &it : p)   \
    cout << it << ' '; \
  cout << '\n'

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  ll H, W, N, Q;
  cin >> H >> W >> N >> Q;
  
  // * pieces
  vector<ll> rows;
  vector<ll> cols;
  while (N--) {
    ll r, c;
    cin >> r >> c;
    rows.push_back(r);
    cols.push_back(c);
  }
  sort(all(rows)); // * sort rows
  sort(all(cols)); // * sort cols
  
  // * Binary Search
  while (Q--) {
    int i, L, R;
    cin >> i >> L >> R;
    
    int ans = 0;
    if (i == 1) {
      ans = upper_bound(all(rows), R) - lower_bound(all(rows), L);
    } else {
      ans = upper_bound(all(cols), R) - lower_bound(all(cols), L);
    }
    
    cout << ans << '\n';
  }
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 c-band-count.cpp -o output && ./output

// * testcase
/*
5 7 5 6
1 1
2 3
2 5
4 3
5 7
1 2 4
2 3 5
1 3 3
2 1 7
1 2 2
2 7 7

*/

/*
3
3
0
5
2
1
*/
