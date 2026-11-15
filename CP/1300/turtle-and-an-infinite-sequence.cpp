/*
* B. Turtle and an Infinite Sequence
*
* https://codeforces.com/problemset/problem/1981/B
*
* Problems on same concept
* https://leetcode.com/problems/bitwise-and-of-numbers-range/
* https://www.geeksforgeeks.org/problems/ishaans-curiosity0853/1
*/

#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

// * Time Complexity: O(60) Per testcase
// * Space Complexity: O(1)
void solve() {
  // * take input
  ll n, m;
  cin >> n >> m;

  ll L = max(0LL, (n - m));
  ll R = (n + m);
  
  ll ans = 0;
  for (int i = 0; i <= 60; ++i) {
    ll bit = 1LL << i;
    // * check if ith bit is ON for both L or R
    if ((L & bit) || (R & bit)) {
      ans |= bit;
    }
    
    // * Otherwise, both endpoints have this bit = 0.
    // *
    // * The bit can still become 1 if the range
    // * crosses a boundary where this bit changes.
    // *
    // * Comparing the higher bits tells us whether
    // * such a boundary lies inside [L, R].
    else if (!(L & (1 << i)) || !(R & (1 << i))) {
      // * Check if bit (i + 1) is different for both L & R
      // * which means we are in the different block.
      // * Which proves that some number will have ith bit set to 1 from L...R.
      if ((L >> (i + 1)) != (R >> (i + 1))) {
        ans |= (1 << i);
      }
    }
  }
  
  cout << ans << '\n';
}

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}

// * Run the code
// * g++ --std=c++20 turtle-and-an-infinite-sequence.cpp -o output && ./output

// * Testcase
/*
9
0 0
0 1
0 2
1 0
5 2
10 1
20 3
1145 14
19198 10


*/

// * Output
/*
0
1
3
1
7
11
23
1279
19455

*/