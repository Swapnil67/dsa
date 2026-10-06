/*
 * Ski Resort
 * 
 * Given an array of daily temperatures, find the total number of continuous vacation periods 
 * lasting at least k days where the temperature on every single day does not exceed q.
 * 
 * Constraints:
 * 1 <= t <= 10^4 (number of test cases)
 * 1 <= n <= 2 * 10^5 (length of the temperature array)
 * 1 <= k <= n (minimum number of consecutive vacation days)
 * -10^9 <= q <= 10^9 (maximum comfortable temperature threshold)
 * -10^9 <= a_i <= 10^9 (daily forecast temperatures)
 * The sum of n over all test cases does not exceed 2 * 10^5.
 * 
 * Example 1    :
 * Input        : n = 3, k = 1, q = 15, a = [10, 20, 10]
 * Output       : 2
 * Explanation  : Comfort intervals are single days. Valid days are day 1 (10) and day 3 (10). 
 *                Thus, there are 2 valid vacation options.
 * 
 * Example 2    :
 * Input        : n = 4, k = 2, q = -5, a = [-6, -5, -10, -15]
 * Output       : 6
 * Explanation  : All 4 days are <= -5. Any continuous interval of size >= 2 is valid.
 *                - 3 intervals of length 2: [-6,-5], [-5,-10], [-10,-15]
 *                - 2 intervals of length 3: [-6,-5,-10], [-5,-10,-15]
 *                - 1 interval of length 4: [-6,-5,-10,-15]
 *                Total valid vacation options = 3 + 2 + 1 = 6.
 *
 * https://codeforces.com/problemset/problem/1840/C
*/

// ! combinatorics

// ! Observation
/*
* Transform temperatures into binary: convert temperatures to 1 if ≤ q, else 0. Then count consecutive 1s.
* 
* Eg: a = [0 3 -2 5 -4 -4], q = 3, k = 1
* We'll make a binary array out of it, i.e, we'll mark 1 for all the days which are <= q and 0 for others

*      1 2 3 4 5 6
* a = [1 1 1 0 1 1]
* 
* from index 1 to 3 we can go to ski we need to find this for 'k = 1' consecutive days.
* count = 3
* Formula = (count - k + 1) -> (3 - 1 + 1) = 3 (let this be diff)
* So now we need to find ways
* ways = diff * (diff + 1) / 2 => (3 * (3 + 1) / 2) => 6
* 
* from index 5 to 6 we can go to ski we need to find this for 'k = 1' consecutive days.
* count = 2
* Formula = (count - k + 1) -> (2 - 1 + 1) = 2 (let this be diff)
* So now we need to find ways
* ways = diff * (diff + 1) / 2 => (2 * (2 + 1) / 2) => 3
*
* Total ways = 6 + 3 = 9
*/

#include<vector>
#include<iostream>

using namespace std;

typedef long long ll;
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))

ll solve() {
	ll n, k, q;
	cin >> n >> k >> q;

	VEC(can_go, n, ll);
	for (int i = 0; i < n; ++i) {
	  cin >> can_go[i];
    // * Mark the day as 1 if temperature is <= q, otherwise 0
	  can_go[i] = (can_go[i] <= q) ? 1 : 0;
	}
	
	ll ways = 0; // * To store the number of valid vacation periods
  ll count = 0; // * To count consecutive days with temperature <= q
	for (int i = 0; i < n; ++i) {
	  if (can_go[i] == 1) {
	    count++;
	  } else {
      // * If a sequence of valid days ends, calculate possible vacation periods
      if (count >= k) {
	      ll diff = count - k + 1;
	      ways += diff * (diff + 1) / 2; // * Add the number of ways for this sequence
	    }
	    count = 0; // * Reset the count for the next sequence
	  }
	}

  // * Check for any remaining sequence at the end of the array
  if (count >= k) {
	  ll diff = count - k + 1;
	  ways += diff * (diff + 1) / 2;
	}

  return ways;
}

// ! Two pointer with counting
// * Time Complexity (TC): O(n) = O(2*10^5)
// * Space Complexity (SC): O(n) = O(2*10^5)
int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll ways = solve();
    cout << ways << "\n";
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 06-ski-resort.cpp -o output && ./output

// * testcases
/*
7
3 1 15
-5 0 -10
5 3 -33
8 12 9 0 5
4 3 12
12 12 10 15
4 1 -5
0 -1 2 5
5 5 0
3 -1 4 -5 -3
1 1 5
5
6 1 3
0 3 -2 5 -4 -4

*/

// * Output
/*
6
0
1
0
0
1
9
*/