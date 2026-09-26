/*
 * Line Trip (Codeforces 1901A)
 * 
 * There is a road represented as a number line. You start at point 0 and want to 
 * travel to point x, then return back to point 0. Your car consumes 1 liter of 
 * fuel per 1 unit of distance. You start with a full tank and there are n gas 
 * stations along the way at points a_1, a_2, ..., a_n where you can fully refuel. 
 * Find the minimum gas tank capacity required to make the round trip successfully.
 * 
 * Example 1    :
 * Input        : n = 3, x = 7, stations = [1, 2, 5]
 * Output       : 4
 * Explanation  : A 4-liter tank is sufficient:
 *                - Drive from 0 to 1 (uses 1L, refuels to 4L)
 *                - Drive from 1 to 2 (uses 1L, refuels to 4L)
 *                - Drive from 2 to 5 (uses 3L, refuels to 4L)
 *                - Drive from 5 to 7 and back to 5 (distance 4, uses 4L, refuels to 4L)
 *                - Drive from 5 back to 0 via stations without running out of fuel.
 * 
 * Example 2    :
 * Input        : n = 1, x = 10, stations = [7]
 * Output       : 7
 * Explanation  : You need 7 liters to get from 0 to the first station at 7. 
 *                On the way back, the distance from 7 to 0 also requires 7 liters.
 * 
 * https://codeforces.com/problemset/problem/1901/A
 */

#include <vector>
#include <iostream>

using namespace std;

void solve() {
  long long n, x;
  cin >> n;
  cin >> x;
  vector<long long> pos;
  pos.push_back(0);
  for (int i = 0; i < n; ++i) {
    long long gsPos;
    cin >> gsPos;
    pos.push_back(gsPos);
  }
  pos.push_back(x);

  n = pos.size();

  long long max_dist = INT_MIN; // * Max distance b/w two points
  for (int i = 0; i < n - 1; ++i) {
    if (i == (int)(pos.size() - 2)) {
      // * since we are coming back again so we need double distance.
      max_dist = max(max_dist, 2LL * (pos[i + 1] - pos[i]));
    }
    else {
      max_dist = max(max_dist, pos[i + 1] - pos[i]);
    }
  }

  cout << max_dist << endl;
}

int main() {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}

// * Run the code
// * g++ --std=c++20 02-line-trip.cpp -o output && ./output

// * Testcases
/*
3
3 7
1 2 5
3 6
1 2 5
1 10
7
*/