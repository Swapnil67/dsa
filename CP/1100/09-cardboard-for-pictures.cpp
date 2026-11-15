/*
 * Cardboard for Pictures
 * 
 * Description  : You are given n square pictures, where the i-th picture has a side 
 *                length of s_i centimeters. Each picture is mounted on a larger square 
 *                piece of cardboard such that it leaves a uniform border of w centimeters 
 *                on all four sides. Knowing that the total area of all cardboard pieces 
 *                combined equals c square centimeters, find the integer value of w.
 * 
 * Constraints  : 1 <= t <= 1000 (number of test cases)
 *                1 <= n <= 2 * 10^5
 *                1 <= c <= 10^18
 *                1 <= s_i <= 10^4
 *                The sum of n over all test cases does not exceed 2 * 10^5.
 *                It is guaranteed that a valid integer w exists for each test case.
 * 
 * Example 1    :
 * Input        : n = 3, c = 50
 *                s = [3, 2, 1]
 * Output       : 1
 * Explanation  : For w = 1, the total area of the cardboards is calculated as:
 *                - Picture 1: (3 + 2*1)^2 = 5^2 = 25
 *                - Picture 2: (2 + 2*1)^2 = 4^2 = 16
 *                - Picture 3: (1 + 2*1)^2 = 3^2 = 9
 *                Total Area = 25 + 16 + 9 = 50. This matches c exactly.
 * 
 * https://codeforces.com/problemset/problem/1850/E
*/

// ! Observation
/*
*
* ---------------------
* |         |         |
* |         | w       |
* |         |         |
* |    ----------     |
* |    |         |    |
* |    |    s    |    |
* |    ----------     |
* |                   |
* |                   |
* |                   |
* ---------------------
*
* The border length from all 4 sides is 'w' centimeters.
* picture is a square with a side length of 's' centimeters.
* We are given the total cardboard area for all the pictures 'c'.

* Expected Cardboard Area = (s * 2*w)^2
* So using above formula we'll find expected Cardboard Area for all pictures and compare it with the given area 'c'.
* We can use here BS on answers
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

bool isValid(vector<ll> &s, ll w, ll &max_area) {
  // * Area of picture = (s[i] + 2*w)^2
  ll n = s.size();
  ll cur_area = 0;
  for (size_t i = 0; i < n; ++i) {
    cur_area += ((s[i] + 2*w) * (s[i] + 2*w));
    if (cur_area > max_area)
      break;
  }
  // cout << w << " " << cur_area << '\n';
  return cur_area <= max_area;
}

void solve() {
  ll n, c;
  cin >> n >> c;
  
  VEC(s, n, ll); READ_VEC(s);
  
  ll l = 0, r = 1e9;
  ll ans = 0;
  while (l <= r) {
    ll m = l + (r - l) / 2;
    if (isValid(s, m, c)) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cout << ans << '\n';
}

// ! Binary Search on Answers
// * Time Complexity (TC): O(nlog(1e9)
// * Space Complexity (SC): O(1)
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