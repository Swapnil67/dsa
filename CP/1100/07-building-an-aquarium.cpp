/*
 * Building an Aquarium
 * 
 * You have a piece of coral consisting of n columns, where the i-th column has a height of a[i] units.
 * You want to build a tank around the coral with integer height h >= 1 by building walls of height h
 * on either side of the tank.
 * 
 * Then, the tank is filled with water so that each column reaches height h. If a column is already
 * taller than h, no water is added to that column. The amount of water added to column i is max(0, h - a[i]).
 * You are given an integer x representing the maximum total units of water available.
 * 
 * Return the maximum possible integer height h of the tank such that the total units of water used does not exceed x.
 * 
 * Constraints:
 * 1 <= n <= 2 * 10^5
 * 1 <= x <= 10^9
 * 1 <= a[i] <= 10^9
 * 
 * Example 1    :
 * Input        : a = [3, 1, 2, 4, 6, 2, 5], x = 9
 * Output       : 4
 * Explanation  : If we choose h = 4, the water added to each column is:
 *                max(0, 4 - 3) = 1
 *                max(0, 4 - 1) = 3
 *                max(0, 4 - 2) = 2
 *                max(0, 4 - 4) = 0
 *                max(0, 4 - 6) = 0
 *                max(0, 4 - 2) = 2
 *                max(0, 4 - 5) = 0
 *                Total water used = 1 + 3 + 2 + 0 + 0 + 2 + 0 = 8 <= 9.
 *                A height of h = 5 would require 13 units of water, which exceeds 9.
 * 
 * Example 2    :
 * Input        : a = [1, 1, 1], x = 10
 * Output       : 4
 * Explanation  : Choosing h = 4 uses (4 - 1) + (4 - 1) + (4 - 1) = 9 units of water <= 10.
 *                Choosing h = 5 would require 12 units of water, which exceeds 10.
 *
 * https://codeforces.com/problemset/problem/1873/E
*/

// ! Binary Search on Answers

// ! Observation
/*
* Binary Search for the height h. 
* For any guessed height 'm', calculate the required water by summing up max(0, mid-a[i]) for all coral columns. 
* If this sum is within your budget x, try a larger h; otherwise, you must try a smaller one.
*/

#include<vector>
#include<iostream>

using namespace std;
typedef long long ll;

#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

// * Function to check if a given height 'mid' can be achieved
// * with the available water 'max_water_units'
bool check(vector<ll> heights, ll max_water_units, ll mid) {
  ll water_units = 0;
  for (auto &h: heights) {
    if (mid > h) {
      water_units += (mid - h);
    }
  }
  // cout << "mid: " << mid << ", water_units: " << water_units << '\n';
  return water_units <= max_water_units;
}

void solve() {
  ll n, x;
  cin >> n >> x;
  VEC(h, n, ll); READ_VEC(h);
  
  ll l = 1, r = 1e12, ans = -1; // Initialize binary search bounds and answer
  while (l <= r) {
    ll m = l + (r - l) / 2;
    if (check(h, x, m)) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  
  cout << ans << '\n';
}

// ! Binary Search on Answers
// * Time Complexity (TC): O(nlog(1e12))
// * Space Complexity (SC): O(n)
int main() {
  // Optimize standard I/O operations for competitive programming
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
	return 0;
}

// * Run the code
// * g++ --std=c++20 07-building-an-aquarium.cpp -o output && ./output

// * testcases
/*
5
7 9
3 1 2 4 6 2 5
3 10
1 1 1
4 1
1 4 3 4
6 1984
2 6 5 9 1 8
1 1000000000
1

*/

// * Output
/*
4
4
2
335
1000000001
*/