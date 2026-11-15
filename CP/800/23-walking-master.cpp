/*
 * Walking Master
 * 
 * https://codeforces.com/problemset/problem/1806/A
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

void solve() {
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  // * Step 1
  // * If the destination y is below the source y,
  // * it is impossible to reach the destination.
  if (y2 < y1) { // * dest cannot be below the src
    cout << "-1" << '\n';
    return;
  }

  // * check the change in Y (y2 - y1)

  // * Step 2
  // * Calculate the min number of moves required to match the y-coordinate
  // * using operation type 1 (x+1 and y+1).
  ll moves = y2 - y1; // * - (dy)

  // * Step 3
  // * Adjust the source x-coordinate by the number of moves
  // * since moving up and right also increases x.
  x1 += moves; // * Update source x after moving up and right

  if (x2 > x1) {
    moves = -1;
  } else {
    moves += (x1 - x2); // * Move x1 to the left using (x-1, y) operation
  }
  cout << moves << '\n';
}

int main() {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  ll t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}

// * Run the code
// * g++ --std=c++20 23-walking-master.cpp -o output && ./output

// * testcase

/*
6
-1 0 -1 2
0 0 4 5
-2 -1 1 1
-3 2 -3 2
2 -1 -1 -1
1 1 0 2

*/

// * output
/*
4
6
-1
0
3
3

*/

