/*
 * Luke is a Foodie
 * 
 * Description  : You are given an array a of n items, each with a given cost, and 
 *                an integer x. You must choose a changing target value v. Every time 
 *                the condition |v - a_i| <= x is violated by the current item a_i, 
 *                you are forced to change the value of v to a new integer. Find the 
 *                minimum number of times you need to change v if you choose its 
 *                initial and subsequent values optimally.
 * 
 * Constraints  : 1 <= t <= 10^4
 *                2 <= n <= 2 * 10^5, sum of n <= 2 * 10^5
 *                1 <= x <= 10^9
 *                1 <= a_i <= 10^9
 * 
 * Example 1    :
 * Input        : n = 5, x = 3, a = [3, 8, 1, 1, 10]
 * Output       : 2
 * Explanation  : Initially choose v = 6. For a_1=3 (|6-3|=3<=3) and a_2=8 (|6-8|=2<=3), 
 *                no change is needed. For a_3=1, we must change v (e.g., to 2). For a_5=10, 
 *                we must change v again. Total changes = 2.
 * 
 * Example 2    :
 * Input        : n = 5, x = 0, a = [5, 5, 5, 5, 5]
 * Output       : 0
 * Explanation  : We can keep v = 5 for the entire array since x = 0 and all elements 
 *                equal 5. No changes are required.
 *
 * https://codeforces.com/problemset/problem/1704/B
*/

// ! Observations
/*
* Track overlapping segments; reset when overlap breaks.

* If |y| <= x
* then -x <= y <= x
*
* same can be said for
* |v - a[i]| <= x
* -x <= v - a[i] <= x
* a[i] - x <= v <= x + a[i]           --- (eq1)
* 
* With eq1 we get the range for 'v'
*
*       =-----------=3                                                8=-----------=
*           =-----------=2      =-------=4                          7=-------=
* 1=------------------=           =-------------=5       6=-------------=
*           v                         v'                             v''
*
*
* Keep your current 'v' till you find intersection, and change 'v' as soon as no intersection is found.
* Here above we changed 'v' two time (v' & v'') since they have completely different intersections.
*/

#include<vector>
#include<iostream>

using namespace std;

typedef long long ll;
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

ll solve() {
  ll n, x;
  cin >> n >> x;
  
  VEC(a, n, ll); READ_VEC(a);
  
  // * Create segments for each pile representing the range [a[i] - x, a[i] + x]
  VEC(segments, n, pair<ll, ll>);
  for (int i = 0; i < n; ++i) {
    segments[i] = {a[i]-x, a[i]+x};
  }
  
  ll ans = 0;
  ll l = segments[0].first;
  ll r = segments[0].second;
  for (int i = 1; i < n; ++i) {
    // * Update the current range to the intersection of the current segment
    l = max(l, segments[i].first);
    r = min(r, segments[i].second);
    
    // * If the current range is invalid, increment the change counter
    if (l > r) {
      ans += 1;
      // * Reset the range to the current segment
      l = segments[i].first;
      r = segments[i].second;
    }
  }
  
  return ans;
}

// * Greedy Range Intersection
// * Time Complexity (TC): O(n) = O(2*10^5)
// * Space Complexity (SC): O(n) = O(2*10^5)
int main() {
  ll t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 13-luke-is-a-foodie.cpp -o output && ./output

// * testcases
/*
7
5 3
3 8 5 6 7
5 3
3 10 9 8 7
12 8
25 3 3 17 8 6 1 16 15 25 17 23
10 2
1 2 3 4 5 6 7 8 9 10
8 2
2 4 6 8 6 4 12 14
8 2
2 7 8 9 6 13 21 28
15 5
11 4 13 23 7 10 5 21 20 11 17 5 29 16 11

*/

// * Output
/*
0
1
2
1
2
4
6
*/