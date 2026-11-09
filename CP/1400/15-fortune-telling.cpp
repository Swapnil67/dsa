/*
 * Fortune Telling
 *
 * https://codeforces.com/problemset/problem/1634/B
*/

#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

// * Time Complexity: O(n)
// * Space Complexity: O(1)
void solve() {
  // * take input
  ll n, x, y;
  cin >> n >> x >> y;
  ll a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  // * Count the number of odd elements.
  int numOdds = 0;
  for (int i = 0; i < n; i++) {
    numOdds += (a[i] & 1);
  }

  // * Initial parity of Alice's number.
  // * 0 -> even, 1 -> odd
  int aliceStart = x % 2;

  // * Bob starts from x + 3.
  // * Since 3 is odd, Bob's parity is
  // * always opposite to Alice's.
  int bobStart = 1 - aliceStart;

  int aliceEnd, bobEnd;

  // * Observation:
  // * - Adding or XORing an even number
  // *   does not change parity.
  // * - Adding or XORing an odd number
  // *   flips parity.
  // *
  // * Therefore, only the parity of the
  // * count of odd elements matters.
  if (numOdds % 2 == 0) {
    // * Even number of flips.
    // * Final parity remains unchanged.
    aliceEnd = aliceStart;
    bobEnd = bobStart;
  } else {
    // * Odd number of flips.
    // * Final parity gets inverted.
    aliceEnd = 1 - aliceStart;
    bobEnd = 1 - bobStart;
  }

  // * Exactly one of Alice or Bob can
  // * reach y. Compare the final parity.
  if (y % 2 == aliceEnd) {
    cout << "Alice" << "\n";
  }
  else {
    cout << "Bob" << "\n";
  }
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
