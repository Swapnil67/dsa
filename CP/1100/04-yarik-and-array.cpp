/*
 * Yarik and Array
 * 
 * You are given an array `nums` of `n` integers. A subarray is a continuous part of the array. 
 * Find the maximum possible sum of a non-empty subarray such that any two adjacent elements 
 * within the subarray have strictly alternating parities (i.e., one is even and the next 
 * is odd, or vice versa).
 * 
 * Constraints:
 * - 1 <= t <= 10^4 (Number of test cases)
 * - 1 <= n <= 2 * 10^5 (Length of the array)
 * - -10^3 <= nums[i] <= 10^3
 * - The sum of `n` over all test cases does not exceed 2 * 10^5.
 * 
 * Example 1    :
 * Input        : nums = [1, 2, 3, 4]
 * Output       : 10
 * Explanation  : The entire array [1, 2, 3, 4] alternates in parity (odd, even, odd, even), 
 *                so its total sum is 1 + 2 + 3 + 4 = 10.
 * 
 * Example 2    :
 * Input        : nums = [1, 2, 4, 3]
 * Output       : 7
 * Explanation  : The optimal alternating subarray is [4, 3] (even, odd) with a sum of 7. 
 *                We cannot pick [1, 2, 4, 3] because 2 and 4 are both even and adjacent.
 *
 * Link to similar problems on LeetCode:
 * - [LeetCode 53: Maximum Subarray - https://leetcode.com/problems/maximum-subarray]
 * - [LeetCode 918: Maximum Sum Circular Subarray - https://leetcode.com/problems/maximum-sum-circular-subarray]
 * - [LeetCode 2760: Longest Even Odd Subarray With Threshold - https://leetcode.com/problems/longest-even-odd-subarray-with-threshold]
 * 
 * https://codeforces.com/problemset/problem/1899/C
*/

// ! Observation
// ! Kadanes Algorithm

/*
* How do we identify if two numbers have different parity (.i.e, even & odd or odd & even)
* a = even => _ _ _ 0       (last bit will always be set to 0)
* b = odd =>  _ _ _ 1      (last bit will always be set to 1)
*
* if we do XOR of these two we'll always get odd number since last bit are opposite.
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))

void solve() {
  ll n;
  cin >> n;
  VEC(a, n, ll);
  for (size_t i= 0; i < n; ++i) {
    cin >> a[i];
  }
  
  ll cur = INT_MIN, ans = INT_MIN;
  for (size_t i = 0; i < n; ++i) {
    if (i > 0 && ((a[i] ^ a[i - 1]) & 1)) { // * check if last element have different parity
      cur = max(cur + a[i], a[i]);
    }
    else {
      cur = a[i];
    }
    ans = max(ans, cur);
  }
  cout << ans << "\n";
} 

// ! Kadane with parity
// * Time Complexity (TC): O(n)
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
// * g++ --std=c++20 04-yarik-and-array.cpp -o output && ./output

// * testcases
/*
7
5
1 2 3 4 5
4
9 9 8 8
6
-1 4 -1 0 5 -4
4
-1 2 4 -3
1
-1000
3
101 -99 101
20
-10 5 -8 10 6 -10 7 9 -2 -6 7 2 -4 6 -1 7 -6 -7 4 1
*/

// * Output
/*
15
17
8
4
-1000
101
10
*/