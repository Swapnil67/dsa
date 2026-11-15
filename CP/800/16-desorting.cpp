/*
 * Desorting
 * 
 * Description  : Given an array 'a' of length 'n', determine the minimum number of operations 
 *                needed to make the array not sorted. An operation allows you to choose an 
 *                index 'i' (1 <= i <= n-1), add 1 to elements from a[1] to a[i], and subtract 
 *                1 from elements from a[i+1] to a[n].
 * 
 * Constraints  :
 *                2 <= n <= 500
 *                1 <= a_i <= 10^9
 * 
 * Example 1    :
 * Input        : n = 2, a = [1, 1]
 * Output       : 1
 * Explanation  : Choose i = 1. Add 1 to a[1] and subtract 1 from a[2]. 
 *                The array becomes [2, 0], which is not sorted.
 * 
 * Example 2    :
 * Input        : n = 4, a = [1, 8, 10, 13]
 * Output       : 2
 * Explanation  : Choose i = 2. Add 1 to a[1], a[2] and subtract 1 from a[3], a[4]. 
 *                The array becomes [2, 9, 9, 12]. Choose i = 2 again. 
 *                The array becomes [3, 10, 8, 11], which is not sorted.
 *
 * https://codeforces.com/problemset/problem/1853/A
*/

// ! Observation

/*
* Target the weakest link: find the adjacent pair with the smallest non-negative difference; 
* changing one of them breaks sorted order with the fewest ops.
*
* Find the sorted pair with least difference and try to make then unsorted.
* d = min(a[i + 1] - a[i])
* operations = d/2 + 1
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

ll solve() {
  ll n;
  cin >> n;
  
  VEC(a, n, ll); READ_VEC(a);
  ll operations = INT_MAX;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] <= a[i + 1]) { // * sorted
      ll diff = a[i + 1] - a[i];  // * Calculate the difference between consecutive elements
      ll required_ops = diff / 2 + 1; // * Calculate the minimum operations needed to make them unsorted
      operations = min(operations, required_ops);
    } else {
      operations = 0;
    }
  }
  return operations;
}

// * Time Complexity (TC): O(n) = O(500)
// * Space Complexity (SC): O(n) = O(500)
int main(void) {
  ll t;
  cin >> t;
  while (t--) {
    ll ans = solve();
    cout << ans << endl;
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 16-desorting.cpp -o output && ./output

// * testcase

/*
4
2
1 1
4
1 8 10 13
3
1 3 2
3
1 9 14

*/

// * output
/*
1
2
0
3
*/

