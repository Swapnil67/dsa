/*
 * Array Merging
 * 
 * Given two arrays a and b of length n. You merge them into an array c of length 2n by 
 * sequentially taking the first remaining element of either array a or b. Find the maximum 
 * length of a contiguous subarray consisting of identical values that can be formed in c.
 * 
 * Constraints:
 * 1 <= t <= 10^4 (number of test cases)
 * 1 <= n <= 2 * 10^5 (length of arrays a and b)
 * 1 <= a_i, b_i <= 2 * n (array element values)
 * The sum of n over all test cases does not exceed 2 * 10^5.
 * 
 * Example 1    :
 * Input        : n = 5, a = [1 2 2 2 2], b = [2 1 1 1 1]
 * Output       : 5
 * Explanation  : c = [1 2 2 2 2 2 1 1 1 1]
 *                       _________
 * 
 * Example 2    :
 * Input        : n = 1, a = [6], b = [6]
 * Output       : 2
 * Explanation  : Merging gives c = [6, 6]. The maximum length of identical values is 2.
 *
 * https://codeforces.com/problemset/problem/1831/B
*/

// ! Observation
/*
* Track longest equal subarrays in a and b separately.
* Calculate longest subarray for each value in a and b, then combine them to find max across both arrays.
*
* n = 5, a = [1 2 2 2 2], b = [2 1 1 1 1]
*
* We'll create two helper array for giving us the longest equal subarray of 'i' in O(1)
* for a_freq = {1: 1, 2: 4}
* for b_freq = {1: 4, 2: 1}
*
* For every i b/w   1 <= i <= 10^5 we'll check the following condition
* max_freq = max(max_freq, a_freq[i] + b_freq[i])
*/

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

ll solve() {
	ll n;
	cin >> n;

  // * Read array a
	VEC(a, n, ll); READ_VEC(a);
	// * Read array b
	VEC(b, n, ll); READ_VEC(b);
	
	// * Vectors to store the longest subarray of equal values for 
	// * each possible value in a and b
	vector<ll> longest_subarray_a(2 * n + 1, 0);
	vector<ll> longest_subarray_b(2 * n + 1, 0);
	
	ll counter = 1; // * Counter to track the length of current subarray of equal values
	// * Calculate the longest subarray of equal values in array a
	for (int i = 1; i < n; i++) {
	  if (a[i] == a[i - 1]) {
	    counter++;
	  } else {
	    // * Update the longest subarray length for the current value
      longest_subarray_a[a[i - 1]] = max(longest_subarray_a[a[i - 1]], counter);
      counter = 1;
	  } 
	}
	// * Update for the last sequence in array a
  longest_subarray_a[a[n - 1]] = max(longest_subarray_a[a[n - 1]], counter);

  // * Calculate the longest subarray of equal values in array b
	counter = 1;
	for (int i = 1; i < n; i++) {
	  if (b[i] == b[i - 1]) {
	    counter++;
	  } else {
	    // * Update the longest subarray length for the current value
      longest_subarray_b[b[i - 1]] = max(longest_subarray_b[b[i - 1]], counter);
      counter = 1;
	  } 
	}
	// * Update for the last sequence in array b
  longest_subarray_b[b[n - 1]] = max(longest_subarray_b[b[n - 1]], counter);

  // * Calculate the maximum length of subarray of equal values across both arrays
  ll max_freq = -1;
	for (int i = 1; i <= 2*n; ++i) {
	  max_freq = max(max_freq, longest_subarray_a[i] + longest_subarray_b[i]);
	}
  return max_freq;
}

// * Time Complexity (TC): O(n) ~ O(2*10^5)
// * Space Complexity (SC): O(n) ~ O(2*10^5)
int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll longest = solve();
    cout << longest << "\n";
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 07-array-merging.cpp -o output && ./output

// * testcases
/*
4
1
2
2
3
1 2 3
4 5 6
2
1 2
2 1
5
1 2 2 2 2
2 1 1 1 1

*/

// * Output
/*
2
1
2
5
*/