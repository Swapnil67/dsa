/*
 * NAME
 * Olya and Game with Arrays
 * 
 * Description:
 * Given n arrays of positive integers, you can move at most one integer from each array to another. Maximize the sum of the minimum elements of each array.
 * 
 * Constraints:
 * 1 <= t <= 25000, 1 <= n <= 25000, 2 <= m_i <= 50000, 1 <= a_{i,j} <= 10^9, sum of m_i <= 50000.
 * 
 * Example 1    :
 * Input        : n = 2, arrays = [[1, 2], [4, 3]]
 * Output       : 5
 * Explanation  : Move 3 to the first array to get [1, 2, 3] and [4], giving min 1 + 4 = 5.
 * 
 * Example 2    :
 * Input        : n = 1, arrays = [[100, 1, 6]]
 * Output       : 1
 * Explanation  : Only one array, beauty is min(100, 1, 6) = 1.
 *
 * Link 
 * https://codeforces.com/problemset/problem/1859/B
*/
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

// Macros
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))

// ! Observation
/*
* We've following 3 vectors

* a1 = [1001 7 1007 5]
* a2 = [8 11 6]
* a3 = [2 9]
*
* We'll first sort these vectors
* 
* a1 = [5 7 1001 1007]
* a2 = [6 8 11]
* a3 = [2 9]
* 
* Since we've option to move 1 element from one vector to another at most once
* We would ideally want to dump all the first minimums to an array which has lowest 2nd minimum.
*
* In our case we'll move 6,2 array a1 since it has lowest 2nd minimum
* 
* a1 = [2 5 6 7 1001 1007]
* a2 = [8 11]
* a3 = [9]
*
* So answer = 2 + 8 + 9 => 19
*
* Formula = M + K - S
* M = lowest first minimum min(2, 8, 9) => 2
* K = sum of all 2nd minimum 7 + 8 + 9 => 24
* S = lowest 2nd minimum which is 7 
*
* M + K - S = 2 + 24 - 7 = 19
*/

ll solve() {
	ll n;
	cin >> n; // * Read the number of arrays in the current test case

	vector<ll> second_elements; // * Vector to store the second smallest elements of each array
	ll lowest_first_minimum = INT_MAX; // * Variable to track the smallest of the first minimums

	for (int i = 0; i < n; i++) {
		ll m;
		cin >> m; // * Read the number of elements in the current array
		vector<ll> a(m); // * Vector to store elements of the current array
		for (auto &x : a) // * Read elements of the array
			cin >> x;

		sort(a.begin(), a.end()); // * Sort the array to find the smallest elements

		second_elements.push_back(a[1]); // * Store the second smallest element
		lowest_first_minimum = min(lowest_first_minimum, a[0]); // * Update the smallest of the first minimums
	}

	sort(second_elements.begin(), second_elements.end()); // * Sort the second smallest elements

	ll sum_of_second_elements = accumulate(second_elements.begin(), second_elements.end(), 0LL); // * Calculate the sum of second smallest elements
	ll lowest_second_minimum = second_elements[0]; // * Find the smallest of the second smallest elements

	return lowest_first_minimum + sum_of_second_elements - lowest_second_minimum; // * Calculate the maximum beauty
}

// * Time Complexity (TC): O(mlogm) = O(50000*log2(500000)) = O(50000*19) = O(950000) = O(10^6)
// * Space Complexity (SC): O(m) = O(50000) = O(10^5)
int main(void) {
	ll t;
	cin >> t; // * Read the number of test cases
	while (t--) {
    ll min_ops = solve();
		cout << min_ops << endl;
	}
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

// * testcases
/*
3
6 3
2 3 2 1 1 3
4 3 2 6 3 6
1 100000
100000
1
4 94
1 4 2 3
103 96 86 57

*/

// * Output
/*
16
100000
265
*/