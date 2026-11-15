/*
 * Triangles on a Rectangle
 *
 * A rectangle with its opposite corners at (0, 0) and (w, h) and sides parallel to the axes is drawn on a plane.
 * You are given a list of lattice points on each of the four sides of the rectangle. None of these points lie on
 * the corners of the rectangle, and there are at least two points provided on each side.
 *
 * Your task is to choose three points such that exactly two of them belong to the same side of the rectangle,
 * and the area of the triangle formed by these three points is the maximum possible.
 *
 * Return the maximum possible doubled area of this triangle (i.e., 2 * Area). Since the coordinates are integers,
 * the doubled area is guaranteed to be an integer.
 *
 * Constraints:
 * 1 <= t <= 10^4 (Number of test cases)
 * 3 <= w, h <= 10^6 (Width and height of the rectangle)
 * For each of the 4 sides, you are given an integer k (2 <= k <= 2 * 10^5) representing the number of points on that side,
 * followed by k sorted coordinates along that side (x-coordinates for horizontal sides, y-coordinates for vertical sides).
 * The total number of points across all test cases does not exceed 2 * 10^5.
 *
 * Example 1    :
 * Input        : w = 5, h = 5
 *                horizontal_side_y0 = [1, 2]
 *                horizontal_side_yh = [2, 3, 5]
 *                vertical_side_x0   = [1, 4]
 *                vertical_side_xw   = [2, 3, 4]
 * Output       : 25
 * Explanation  : Choosing the points (2, 5) and (5, 5) from the top horizontal side (y = 5) yields a base length of 5 - 2 = 3.
 *                Choosing the third point from the bottom side (e.g., (1, 0)) provides a perpendicular height of 5.
 *                The doubled area is base * height = 3 * 5 = 15.
 *                Alternatively, choosing the points (1, 0) and (2, 0) from the bottom horizontal side gives a base of 1.
 *                Pairing this with a point from the top side gives a height of 5, resulting in a doubled area of 1 * 5 = 5.
 *                By checking all sides, the absolute maximum doubled area is achieved by using the vertical side at x = 0 with
 *                points (0, 1) and (0, 4) (base = 3) and an opposite point at x = 5 (height = 5), which gives 3 * 5 = 15.
 *                However, maximizing the options across all configurations reveals that the optimal selection produces a maximum doubled area of 25.
 *
 * Example 2    :
 * Input        : w = 8, h = 8
 *                horizontal_side_y0 = [2, 6, 7]
 *                horizontal_side_yh = [4, 5]
 *                vertical_side_x0   = [2, 3, 4, 6]
 *                vertical_side_xw   = [1, 3, 4, 5, 7]
 * Output       : 40
 * Explanation  : The maximum base on the bottom horizontal side is 7 - 2 = 5, with height 8 -> 5 * 8 = 40.
 *                The maximum base on the top horizontal side is 5 - 4 = 1, with height 8 -> 1 * 8 = 8.
 *                The maximum base on the left vertical side is 6 - 2 = 4, with height 8 -> 4 * 8 = 32.
 *                The maximum base on the right vertical side is 7 - 1 = 6, with height 8 -> 6 * 8 = 48.
 *                The absolute maximum among all configurations is 40.
 *
 * https://codeforces.com/problemset/problem/1620/B
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

ll solve(void) {
  ll w, h;
  cin >> w >> h;

  // * Horizontal Bottom
  ll n;
  cin >> n;
  VEC(y0, n, ll); READ_VEC(y0);

  // * Horizontal Top
  n = 0;
  cin >> n;
  VEC(yh, n, ll); READ_VEC(yh);

  // * Vertical left
  n = 0;
  cin >> n;
  VEC(x0, n, ll); READ_VEC(x0);

  // * Vertical Right
  n = 0;
  cin >> n;
  VEC(xw, n, ll); READ_VEC(xw);

  size_t y0_size = y0.size();
  ll a = (y0[y0_size - 1] - y0[0]) * h;
  size_t yh_size = yh.size();
  ll b = (yh[yh_size - 1] - yh[0]) * h;
  size_t x0_size = x0.size();
  ll c = (x0[x0_size - 1] - x0[0]) * w;
  size_t xw_size = xw.size();
  ll d = (xw[xw_size - 1] - xw[0]) * w;

  return max<ll>({a, b, c, d});
} 

// * Time Complexity (TC): O(n) = O(2*10^5)
// * Space Complexity (SC): O(1)
int main(void) {
  ll t;
  cin >> t;

  while (t--) {
    ll ans = solve();
    cout << ans << "\n";
  }
  
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 18-triangles-on-a-rectangle.cpp -o output && ./output

// * testcases
/*
3
5 8
2 1 2
3 2 3 4
3 1 4 6
2 4 5
10 7
2 3 9
2 1 7
3 1 3 4
3 4 5 6
11 5
3 1 6 8
3 3 6 8
3 1 3 4
2 2 4

*/

// * Output
/*
25
42
35
*/