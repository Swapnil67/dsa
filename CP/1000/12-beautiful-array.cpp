/*
 * Beautiful Array
 * 
 * Given four integers n, k, b, and s, construct an array of n 
 * non-negative integers such that the sum of the elements is 
 * exactly s, and the "beauty" of the array is exactly b. The 
 * beauty of an array is defined as the sum of floor(a_i / k) 
 * for all elements. If no such array exists, return -1.
 * 
 * Constraints  : 1 <= t <= 1000
 *                1 <= n <= 10^5
 *                1 <= k <= 10^9
 *                0 <= b <= 10^9
 *                0 <= s <= 10^18
 * 
 * Example 1    :
 * Input        : n = 1, k = 6, b = 3, s = 19
 * Output       : 19
 * Explanation  : The array [19] has a sum of 19, and its beauty is floor(19 / 6) = 3.
 * 
 * Example 2    :
 * Input        : n = 3, k = 6, b = 3, s = 19
 * Output       : 0 0 19
 * Explanation  : The array [0, 0, 19] has a sum of 19. The beauty is floor(0/6) + floor(0/6) + floor(19/6) = 3.
 *
 * https://codeforces.com/problemset/problem/1715/B
*/

// ! Observation

/*
* Following is how we calculate beauty of array.
* b = floor(a[0]/k) + floor(a[1]/k) + floor(a[2]/k) + floor(a[3]/k) + .... + floor(a[n]/k)
* s = a[0] + a[1] + a[2] + a[3] + .... + a[n]
* 
* Lets for now ignore the 's' first we'll find just the 'n' size array which has beauty 'b'
*
* a = [k*b, 0, 0, 0, 0, ...., 0]
*
* Then above array will give use beauty 'b' since (k * b) / k = b
* which means the minimum sum we can have is (k * b).
* Similarly if we add (k - 1) to all the elements our beauty won't change since ((k - 1)+0)/k = 0
*
* minimum_s = (k * b)
* maximum_s = (k * b) + (k - 1) * n
*
* so we can say  minimum_s <= 's' <= maximum_s. Anything apart from this will not be possible it will change beauty.
*
* Example: 
* N = 5, k = 4, b = 7, s = 38
* 
* a = [28, 0, 0, 0, 0]
* Here we have s = 28, rem = 38 - 28 = 10, we'll distribute the 10 in array.
* Each array element can have (k - 1) added to it, beauty won't change.
* 
* a = [31, 3, 3, 1, 0]
*
* Above is our final array, which satisfies our beauty and sum condition.
*/

#include<vector>
#include<iostream>

using namespace std;

typedef long long ll;

void solve() {
  ll n, k, b, s;
  cin >> n >> k >> b >> s;

  // ! Important observation
  // * Calculate the minimum and maximum possible sum s
  ll minimum_s = (k * b);
  ll maximum_s = (k * b) + ((k - 1) * n);

  if (!(s >= minimum_s && s <= maximum_s)) {
    cout << -1 << "\n";
  }
  else {
    vector<ll> beautiful(n, 0);
    beautiful[0] = minimum_s; // * Set the first element to minimum_s
    s -= minimum_s; // * Reduce s by minimum_s
    
    // * Distribute the remaining s across the array
    for (int i = 0; i < n; ++i) {
      ll add = min(k - 1, s); // * Calculate the amount to add to ans[i]
      beautiful[i] += add; // * Add the calculated amount to ans[i]
      s -= add; // * Reduce s by the added amount
    }
    
    for (auto &x: beautiful) {
      cout << x << " ";
    }
    cout << "\n";
  }
}

// * Time Complexity (TC): O(n) = O(10^5)
// * Space Complexity (SC): O(n) = O(10^5)
int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}