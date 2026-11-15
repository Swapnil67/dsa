/*
 * Lunatic Never Content
 * 
 * Description  : You are given an array `a` of `n` non-negative integers. Let's define 
 *                a function f(a, x) = [a[1] % x, a[2] % x, ..., a[n] % x] for some positive 
 *                integer `x`. Find the maximum positive integer `x` such that the 
 *                remainder array f(a, x) is a palindrome.
 *                
 *                An array is a palindrome if it reads the same backward as forward. 
 *                Formally, for every 1 <= i <= n, a[i] % x == a[n - i + 1] % x. If `x` can 
 *                be infinitely large, return 0.
 * 
 * Constraints  : 
 *                1 <= t <= 10^5 (Number of test cases)
 *                1 <= n <= 10^5
 *                0 <= a[i] <= 10^9
 *                It is guaranteed that the sum of n over all test cases does not exceed 10^5.
 * 
 * Example 1    :
 * Input        : n = 2, a = [1, 2]
 * Output       : 1
 * Explanation  : For x = 1, [1 % 1, 2 % 1] = [0, 0], which is a palindrome. No larger 
 *                integer satisfies this.
 * 
 * Example 2    :
 * Input        : n = 8, a = [0, 1, 2, 3, 4, 5, 6, 7]
 * Output       : 1
 * Explanation  : For x = 1, all elements become 0, making it a palindrome. 
 * 
 * Example 3    :
 * Input        : n = 3, a = [1, 10, 1]
 * Output       : 0
 * Explanation  : The original array is already a palindrome, so `x` can be infinitely large. 
 *                Thus, we output 0.
 *
 * https://codeforces.com/problemset/problem/1826/B
 */

// ! GCD On Differences
// ! Observation
/*
* a = [a1, a2, a3, a4, a5]
* To make this palindrome we must follow the following
*
* a1 % x = a5 % x
* a2 % x = a4 % x
* a3 % x = 0
* 
* a1 % x - a5 % x = 0 
* (a1 - a5) % x = 0
*
* Same for 
*
* a2 % x - a4 % x = 0
* (a2 - a4) % x = 0
*
* This tells us that our 'x' should be multiple of (a1 - a5) & (a2 - a4) the differences.
* also we need the largest 'x' possible.
* 
* So a = [a1, a2, a3, a4, ...... an]
* 
* x = gcd((a1 - an), (a2 - a[n-1]), (a3 - a[n - 2]),....)
* So our 'x' is simply the GCD of differences.
* 
*/

#include <vector>
#include <numeric>
#include <iostream>

using namespace std;
typedef long long ll;

#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

// * Time Complexity (TC): O(n * log(1e9))
// * Space Complexity (SC): O(n)
void solve() {
  ll n;
  cin >> n;

  VEC(a, n, ll); READ_VEC(a);
  
  ll ans = 0;
  for (size_t i = 0; i < n; ++i) {
    // * Calculate the gcd of the current answer and the absolute difference
		// * between the i-th element and its corresponding element from the end
    ans = __gcd(ans, abs(a[i] - a[n - i - 1]));
  }
  
  cout << ans << '\n';
}

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
// * g++ --std=c++20 13-lunatic-never-content.cpp -o output && ./output

// * testcases
/*
4
2
1 2
8
3 0 1 2 0 3 2 1
1
0
3
100 1 1000000000

*/

// * Output
/*
1
2
0
999999900
*/