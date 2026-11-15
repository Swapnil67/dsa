/*
 * Numbers Box
 * 
 * Given an n x m rectangular grid of integers, you can perform an operation 
 * any number of times: choose any two adjacent cells and multiply both 
 * by -1. Determine the maximum possible sum of all numbers in the grid 
 * that can be achieved.
 * 
 * Constraints  :
 *                1 <= t <= 100 (number of test cases)
 *                2 <= n, m <= 10
 *                -100 <= a_ij <= 100
 * 
 * Example 1    :
 * Input        : n = 2, m = 2, grid = [[-1, 1], [1, 1]]
 * Output       : 2
 * Explanation  : You can flip the adjacent elements (-1, 1) in the first row. The grid becomes 
 *                [[1, -1], [1, 1]]. Then, you flip the adjacent elements (-1, 1) vertically 
 *                in the second column. The grid becomes [[1, 1], [1, -1]]. The sum of all elements 
 *                is 1 + 1 + 1 - 1 = 2. It is impossible to eliminate the last negative sign.
 * 
 * Example 2    :
 * Input        : n = 3, m = 3, grid = [[-1, -1, -1], [-1, -1, -1], [-1, -1, -1]]
 * Output       : 9
 * Explanation  : Since there is an odd number of negative elements (9), you can flip pairs 
 *                continually until exactly one negative sign remains. By steering that negative 
 *                sign to the element with the smallest absolute value (which is 1), all other 
 *                elements become positive. The sum becomes 8 * 1 - 1 = 7 (assuming all values are 1).
 *
 * https://codeforces.com/problemset/problem/1447/B
*/

// ! Observation

/*
* Intuition for odd number of negatives:
* 1. Total `sum` stores absolute values, meaning the minimum element X is added as (+X).
* 2. Since negatives are odd, exactly one element must remain negative in the final grid.
* 3. To maximize the sum, we choose the smallest absolute value to stay negative (-X).
* 4. Changing (+X) to (-X) requires removing it once and subtracting it once: sum - X - X = sum - 2*X.

* Formula for Maximum Grid Sum:
* * If count of negative numbers is EVEN:
*   Max Sum = Total Absolute Sum
*   (All negative signs can be completely eliminated)
*
* * If count of negative numbers is ODD:
*   Max Sum = Total Absolute Sum - (2 * Minimum Absolute Value)
*   (One element must stay negative; changing it from +X to -X requires subtracting 2*X)
*/

#include <vector>
#include <iostream>
 
using namespace std;
typedef long long ll;

void solve()
{
  int n, m;
  cin >> n >> m;
	vector<vector<ll>> g(n, vector<ll>(m));
  for (int i = 0; i < n; ++i) 
    for (int j = 0; j < m; ++j) 
      cin >> g[i][j]; // * Read each value into the grid
    
  ll negatives = 0; // * count total negatives in grid
  ll minimum = INT_MAX; // * Minimum absolute value in the grid
	ll sum = 0; // * Sum of absolute values of all numbers
	
	for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (g[i][j] < 0) {
        negatives++;
      }
      minimum = min(minimum, abs(g[i][j])); // * Update minimum absolute value
      sum += abs(g[i][j]);
    }
	}
	
	// * If odd, subtract twice the smallest absolute value to maximize sum
	if (negatives & 1) {
    cout << sum - 2 * minimum << "\n";
  } else {
	  // * If the count of negative numbers is even, the sum is maximum
	  cout << sum << "\n";
	}
}

// * Time Complexity (TC): O(n*m) = O(100)
// * Space Complexity (SC): O(n*m) = O(100)
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
