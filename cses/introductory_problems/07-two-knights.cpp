/*
 * Number Spiral
 * 
 * https://cses.fi/problemset/task/1071
*/

#include <iostream>

using namespace std;
typedef long long ll;

// ! Observation
/*
* 2 3 4 4 4 4 3 2
* 3 4 6 6 6 6 4 3
* 4 6 8 8 8 8 6 4
* 4 6 8 8 8 8 6 4
* 4 6 8 8 8 8 6 4
* 4 6 8 8 8 8 6 4
* 3 4 6 6 6 6 4 3
* 2 3 4 4 4 4 3 2
*
* Ans = X - Y
* X = All psbl ways to place 2 knights (don't care if they kill each other).
* Y = All psbl ways to place 2 knights so they would attack each other.
*/

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int main(void) {
  ll n;
  cin >> n;
  for (ll k = 1; k <= n; ++k) {
    ll size = k * k;
    ll all_ways = (size * (size - 1)) / 2;
    ll bad_ways = 0;
    bad_ways += 8 * (k - 4) * (k - 4);
    bad_ways += 6 * (k - 4) * 4;
    bad_ways += 4 * (k - 3) * 4;
    bad_ways += 3 * 8;
    bad_ways += 2 * 4;
    bad_ways /= 2;
    cout << all_ways - bad_ways << "\n";
  }
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 07-two-knights.cpp -o output && ./output

/*
Input:
8

Output:
0
6
28
96
252
550
1056
1848
*/