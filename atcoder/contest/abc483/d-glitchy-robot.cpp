/*
 * D - Glitchy Robot
 * 
 * https://atcoder.jp/contests/abc483/tasks/abc483_d
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define PRINT_VEC_PAIRS(p) for (auto &it: p) cout << it.first << ' ' << it.second << '\n'

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << "\n";
}

// ! Observation
/*
* a = [-2 3 -2]
*
* distance = max - min + 1
*
* Case 1: No flips
* 0 -> -2 -> 1 -> -1      = (1 - (-2)) + 1 => 4            
*
* Case 2: flip -2
* 0 -> 2 -> 5 -> 3      = (5 - 0) + 1 => 6                (Add +4 to 0..2)
*
* Case 2: flip -3
* 0 -> -2 -> -5 -> -7      = (0 - (-7)) + 1 => 8          (Add -6 to 1..2)
*
* Case 2: flip -2
* 0 -> -2 -> 1 -> 3      = (3 - (-2)) + 1 => 6            (Add +4 to 2..2)
*
* So we can see there the max coordinates robot passes is 8.
* 
* We can also see that if we flip some a[i] then all the positions to its right
* are getting reduced by -2*a[i] (compare any flip with no flip)
*
* So we'll use prefix min and max & suffix min and max vectors.
*/

// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(n)
void solve(void) {
  // * take input
  int n;
  cin >> n;
  vl a(n), pre(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pre[i + 1] = pre[i] + a[i]; // * 1 based index
  }
  
  // * Prefix Left Minimum & Prefix Right Maximum
  vl lmn(n + 1), lmx(n + 1);
  lmn[0] = lmx[0] = 0;
  for (int i = 1; i <= n; ++i) {
    lmn[i] = min(lmn[i - 1], pre[i - 1]);
    lmx[i] = max(lmx[i - 1], pre[i - 1]);
  }

  // * Suffix Left Minimum & Suffix Right Maximum
  vl rmn(n + 1), rmx(n + 1);
  rmn[n] = rmx[n] = pre[n];
  for (int i = n - 1; i >= 0; --i) {
    rmn[i] = min(rmn[i + 1], pre[i]);
    rmx[i] = max(rmx[i + 1], pre[i]);
  }
  
  ll ans = (rmx[0] - rmn[0]) + 1;
  for (int i = 1; i <= n; ++i) {
    // * if we flip a[i] then all the elements from i+1...n changes by -2*a[i]
    // * but we only care about the min and max in right side
    ll d = -2 * a[i - 1]; 
    ll min_d = min(lmn[i], rmn[i] + d);
    ll max_d = max(lmx[i], rmx[i] + d);
    // cout << max_d << ' ' << min_d << '\n';
    ans = max(ans, max_d - min_d + 1);
  }
  
  cout << ans << '\n';
}

int main(void) {
  solve();
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 d-glitchy-robot.cpp -o output && ./output

// * testcase
/*
3
-2 3 -2

*/

// * output
/*
8

*/