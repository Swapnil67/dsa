/*
* Number of Pairs
*
* https://codeforces.com/problemset/problem/1538/C
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()

#define PRINT_VEC(p) \
  for (auto &it : p) \
  cout << it << ' '; cout << '\n'
  
// ! Observation
// ! Binary Search

/* 
*                           Valid Pairs
*                       <----------------->
* ------------------------------------------------------------
*        a[i]           L                 R
*          ^

* Find smallest idx 'j' such that its sum with current idx is greater than equal to 'l'.
* a[i] + a[j] >= l
* a[j] = l - a[i]      ---- (L)
*
* Find smallest idx 'j' such that its sum with current idx is greater than 'r'.
* a[i] + a[j] > r
* a[j] = l - a[i]      ---- (R)
*
*
* Valid Pairs = (R - L)
*/

// * Time Complexity:  O(n log n)
// * Space Complexity: O(n)
void solve() {
  // * * Take input
  ll n, l, r;
  cin >> n >> l >> r;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) 
    cin >> a[i];
    
  sort(all(a)); // * Sort array for binary search
  // * PRINT_VEC(a);
  
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    if (a[i] > r) break;
    
    // * Find how many elements a[j] satisfy a[i] + a[j] >= L   (Lower Bound)
    // * * a[i] + a[j] >= L  =>  a[j] >= L - a[j]
    ll L = lower_bound(a.begin() + i + 1, a.end(), (l-a[i])) - a.begin();
    
    // * Find how many elements a[j] satisfy a[i] + a[j] >= R  (Upper Bound)
    // * * a[i] + a[j] >= R  =>  a[j] >= R - a[j]
    ll R = upper_bound(a.begin() + L, a.end(), (r-a[i])) - a.begin();
    
    // * cout << L << ' ' << R << " => " << (R - L) << '\n';
    
    if (L <= R)
      ans += (R - L);
  }
  
  cout << ans << '\n';
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
// * g++ --std=c++20 number-of-pairs.cpp -o output && ./output

// * Testcase
/*
4
3 4 7
5 1 2
5 5 8
5 1 2 4 3
4 100 1000
1 1 1 1
5 9 13
2 5 5 1 1


*/

// * Output
/*
2
7
0
1
*/