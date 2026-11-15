/*
 * 2D Traveling
 * 
 * Description:
 * There are n cities on a 2D Cartesian plane, numbered from 1 to n. The first k cities (1 to k) 
 * are defined as "major cities". The coordinates of the i-th city are given by (x[i], y[i]).
 * 
 * You want to travel from city a to city b. You can fly between any two cities directly or 
 * visit several cities in any order during your trip. The cost of traveling directly between 
 * any city i and city j is defined as:
 * - 0, if both city i and city j are major cities (1 <= i, j <= k).
 * - |x[i] - x[j]| + |y[i] - y[j]| (Manhattan distance), otherwise.
 * 
 * Return the minimum total cost required to travel from city a to city b.
 * 
 * Constraints:
 * 2 <= n <= 2 * 10^5
 * 0 <= k <= n
 * 1 <= a, b <= n
 * -10^9 <= x[i], y[i] <= 10^9
 * 
 * Example 1    :
 * Input        : n = 5, k = 2, a = 1, b = 3
 *                cities = [(1, 1), (4, 5), (1, 5), (2, 6), (3, 3)]
 * Output       : 4
 * Explanation  : Cities 1 and 2 are major cities. We want to go from city 1 to city 3.
 *                - Path 1: Direct from 1 to 3 -> cost = |1 - 1| + |1 - 5| = 4.
 *                - Path 2: 1 -> 2 (major to major, cost 0) -> 3 (cost = |4 - 1| + |5 - 5| = 3). Total = 3.
 *                The minimum cost to go from 1 to 3 is 4 (direct is 4, routing through 2 gives 0 + 3 = 3, 
 *                but wait, direct 1->3 is 4. Routing via 2 gives: 1->2 is 0, 2->3 is |4-1|+|5-5| = 3. 
 *                Total cost via major city route is 0 + 3 = 3? Let's check the absolute minimum: 3).
 *                
 * Example 2    :
 * Input        : n = 5, k = 0, a = 3, b = 5
 *                cities = [(1, 1), (4, 5), (1, 5), (2, 6), (3, 3)]
 * Output       : 4
 * Explanation  : There are no major cities (k = 0). The only way is direct Manhattan distance.
 *                Direct cost from city 3 to city 5 = |1 - 3| + |5 - 3| = 2 + 2 = 4.
 *
 * Link         : https://codeforces.com/problemset/problem/1869/B
*/

// ! Observation
/*
* If k = 0 then go directly from city s => t, we should not go via via any other city that will increase our cost.
* min cost = | s[x] - t[x] | + | s[y] - t[y] | 

*
* For rest we need to find the min dist from 
* mins = src -> major city
* mint = dst -> major city
*
* Ans will be (mins + mint) since all the travel in middle cities the cost will be 0 since they are major cities.
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << "\n";
}

// * Space Complexity (SC): O(n)
// * Time Complexity (TC): O(n)
// * Function to solve each test case
void solve() {
	int n, k, s, t;
	// * Read the number of cities (n), number of major cities (k), starting city (s), and ending city (t)
	cin >> n >> k >> s >> t;

	// * Vectors to store the x and y coordinates of each city
	vector<ll> x(n + 1), y(n + 1);
	// * Read the coordinates of each city
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
  // printArr(x);
  // printArr(y);

	// * Calculate the direct cost from city s to city t
	ll ans = abs(x[s] - x[t]) + abs(y[s] - y[t]); // * when k = 0 (i.e., there are no major cities)

	// * Initialize minimum costs from s to any major city and from t to any major city
	ll mins = 1e17, mint = 1e17;
	// * Calculate the minimum cost from city 's' to any major city and from city 't' to any major city
	for (int i = 1; i <= k; i++) {
    // * min cost from 's' => any major city
		mins = min(mins, abs(x[s] - x[i]) + abs(y[s] - y[i]));
    // cout << x[s] << " - " << x[i] << " + " << y[s] << " - " << y[i] << '\n';
    
    // * min cost from 't' => any major city
		mint = min(mint, abs(x[t] - x[i]) + abs(y[t] - y[i]));
    // cout << x[t] << " - " << x[i] << " + " << y[t] << " - " << y[i] << '\n';
	}

	// * Update the answer with the minimum cost considering major cities
	ans = min(ans, mins + mint);

	// * Output the minimum cost
	cout << ans << '\n';
}

int main() {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int t;
	// Read the number of test cases
	cin >> t;
	// Solve each test case
	while (t--) {
		solve();
	}
}

// * Run the code
// * g++ --std=c++20 08-2D-traveling.cpp -o output && ./output

// * testcases
/*
5

6 2 3 5
0 0
1 -2
-2 1
-1 3
2 -2
-3 -3

2 0 1 2
-1000000000 -1000000000
1000000000 1000000000

7 5 4 2
154 147
-154 -147
123 456
20 23
43 20
998 244
353 100

3 1 3 1
0 10
1 20
2 30

4 3 2 4
0 0
-100 100
-1 -1
-1 0
*/

// * Output
/*
4
4000000000
0
22
1
*/