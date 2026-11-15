/*
* A. Numbers on the Board
*
* https://codeforces.com/contest/2283/problem/A
*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
#define PRINT_VEC_PAIRS(p) for (auto &it: p) cout << it.first << ' ' << it.second << '\n'

// ! Observation
/*
* Find the largest array with sum 0
* Let count = largest array with sum 0
* Answer = (r - l + 1) - (count + 1)
*/
void bruteForce() {
  // * take input
  int l, r;
  cin >> l >> r;
  
  // * Find the largest array with sum 0
  unordered_map<int, int> mp;
  mp[0] = -1;
  int sum = 0, k = 0, count = 0;
  int idx = 0;
  for (int i = l; i <= r; ++i) {
    sum += i;
    int check = sum - k;
    // cout << sum << " " << check << '\n';
    if (mp.count(check)) {
      count = max(count, (idx - mp[check])); 
    }
    if (!mp.count(sum)) {
      mp[sum] = idx;
    }
    idx += 1;
  }

  // cout << count << '\n';
  int range_len = (r - l + 1);
  if ((count + 1) > range_len)
    cout << 0 << '\n';
  else
    cout << (range_len - (count + 1)) << '\n';
}


// * Time Complexity: O(1)
// * Space Complexity: O(1)
void solve() {
  // * take input
  ll l, r;
  cin >> l >> r;
  
  // * When both l & r are negative or positive ([1, 3] or [-2, -2])
  if (l > 0 || r < 0) { 
    cout << (r - l) << '\n';
  } else { // * Eg: [-6, 2]
    cout << max(0LL, (abs(l + r) - 1LL)) << '\n';
  }
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

// * testcase
/*
8
0 0
2 6
-5 -3
-2 2
-2 3
-2 5
-6 2
0 4


*/

/*
0
4
2
0
0
2
3
3
*/
