
/*
 * Leetcode -  
 * NAME
 * 
 * 
 * Example 1    :
 * Input        : nums = [-1,1,2,3,1], target = 2
 * Output       : 3
 * Explanation  : There are 3 pairs of indices that satisfy the conditions in the statement:
 * 
 * Example 2    :
 * Input        : nums = [-6,2,5,-2,-7,-1,3], target = -2
 * Output       : 10
 * Explanation  : There are 10 pairs of indices that satisfy the conditions in the statement:
 *
 * 
*/

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}
int dfs(int i, int n, int x, int limit, vector<vector<int>>& dp) {
	// * Base case: successfully formed the target sum
	if (n == 0)
		return 1;

	// * Base case: if current number's power exceeds limit, stop exploring
	if (i > limit)
		return 0;

	// * If this state has already been calculated, return the cached result
	if (dp[i][n] != -1)
		return dp[i][n];

	int res = 0;
	// * Loop through choices starting from 'i'
	for (int j = i; j <= limit; ++j) {
		int power = pow(j, x);

		if (n - power >= 0) {
			res += dfs(j + 1, n - power, x, limit, dp);
		} else {
			break; // * Smart pruning remains intact
		}
	}

	// * Store the result in the dp table before returning
	return dp[i][n] = res;
}


// * ------------------------- Approach: Brute Force Approach -------------------------
// * Top Down
// * TIME COMPLEXITY O(Limit^2 * n)
// * SPACE COMPLEXITY O(Limit * n)
int bruteForce(int n, int x) {
	// Find the maximum base number purely using integers
	int limit = 1;
	while (pow(limit, x) <= n) {
		limit++;
	}
	limit--;

	vector<vector<int>> dp(limit + 2, vector<int>(n + 1, -1));
	return dfs(1, n, x, limit, dp);
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * BOTTOM UP 
// * TIME COMPLEXITY O(Limit * n)
// * SPACE COMPLEXITY O(n)
int numberOfWays(int n, int x) {
	const int MOD = 1e9 + 7;

	// * Find the maximum base number purely using integers
	int limit = 1;
	while (pow(limit, x) <= n) {
		limit++;
	}
	limit--;

	// * dp[t] stores the number of ways to form the sum 't'
	vector<int> dp(n + 1, 0);
	dp[0] = 1; // * Base case: 1 way to make a sum of 0 (empty set)

	// * Iterate through all possible base numbers from 1 up to limit
	for (int j = 1; j <= limit; ++j) {
		int power = round(pow(j, x));

		// * Loop backwards to ensure each number's power is used AT MOST ONCE
		for (int t = n; t >= power; --t) {
			dp[t] = (dp[t] + dp[t - power]) % MOD;
		}
	}

	return dp[n];
}

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
