/*
 * NAME         : Odd Queries
 * 
 * Description:
 * You have an array a1, a2, ..., an and q independent queries. For each query [l, r, k], 
 * replace elements from index l to r with k and determine if the total array sum is odd.
 * 
 * Constraints:
 * 1 <= t <= 10^4, 1 <= n, q <= 2 * 10^5, 1 <= a_i, k <= 10^9, 1 <= l <= r <= n
 * 
 * Example 1    :
 * Input        : nums = [2, 2, 1, 3, 2], queries = [[2, 3, 3], [2, 3, 4], [1, 5, 5], [1, 4, 9], [2, 4, 3]]
 * Output       : ["YES", "YES", "YES", "NO", "YES"]
 * Explanation  : Modifying ranges yields sums of 13 (odd), 15 (odd), 25 (odd), 38 (even), and 13 (odd).
 * 
 * Example 2    :
 * Input        : nums = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1], queries = [[3, 8, 13], [2, 5, 10], [3, 8, 10], [1, 10, 2], [1, 9, 100]]
 * Output       : ["NO", "NO", "NO", "NO", "YES"]
 * Explanation  : Modifying ranges independently yields sums of 82, 46, 64, 20, and 901 respectively.
 *
 * https://codeforces.com/problemset/problem/1807/D 
*/

#include <vector>
#include <iostream>
#include <numeric>

using namespace std;
typedef long long ll;

// * Prefix sums and Parity
// * TC = O(N + Q)
// * SC = O(N)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    ll n, Q;
    cin >> n >> Q;

    vector<ll> nums(n + 1LL, 0LL);
    vector<ll> p(n + 1LL, 0LL);
    for (int i = 1; i <= n; ++i) {
      cin >> nums[i];
      p[i] = p[i - 1] + nums[i];
    }

    ll total_sum = p[n];
    for (int q = 1; q <= Q; ++q) {
      ll l = 0, r = 0, val = 0;
      cin >> l >> r >> val;
      ll range_sum = p[r] - p[l] + nums[l];
      ll new_sum = (total_sum - range_sum) + (r - l + 1LL) * val;
      // cout << range_sum << " " << new_sum << endl;
      if (new_sum & 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 10-odd-queries.cpp -o output && ./output

// * testcases
/*
2
5 5
2 2 1 3 2
2 3 3
2 3 4
1 5 5
1 4 9
2 4 3
10 5
1 1 1 1 1 1 1 1 1 1
3 8 13
2 5 10
3 8 10
1 10 2
1 9 100

*/


// * Output
/*
YES
YES
YES
NO
YES
NO
NO
NO
NO
YES
*/