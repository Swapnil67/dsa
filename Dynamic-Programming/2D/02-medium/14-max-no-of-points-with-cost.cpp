/*
 * Leetcode - 1937
 * Maximum Number of Points with Cost
 * 
 * Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
 * 
 * A falling path starts at any element in the first row and chooses the element in the next row that is either directly
 * below or diagonally left/right. Specifically, the next element from position 
 * (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
 * 
 * Example 1    :
 * Input        : points = [[1,2,3],[1,5,1],[3,1,1]]
 * Output       : 9
 * 
 * Example 2    :
 * Input        : points = [[1,5],[2,3],[4,2]]
 * Output       : 11
 *
 * https://leetcode.com/problems/minimum-falling-path-sum/description/
 * https://www.geeksforgeeks.org/problems/minimum-sum-in-a-falling-path/1
 * https://www.naukri.com/code360/problems/minimum-falling-path-sum_893012
*/

// ! Visa

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

int m, n;
typedef long long ll;
vector<vector<ll>> dp;

ll dfs(int r, int c, vector<vector<int>> &points) {
	if (r < 0 || r >= m || c < 0 || c >= n) // * Out-of-bounds guard
		return -1e9;

	// * Base Case: If we reach the top row (row 0), the max value is just the cell's points
	if (r == 0)
		return points[r][c];

	// * Choice 1: Move straight up from the same column in the previous row (No distance penalty)
	ll upper = points[r][c] + dfs(r - 1, c, points);

	// * Choice 2: Move from the left diagonal (column c - 1) in the previous row. Penalty = abs(c - (c-1)) = 1
	ll leftDiagnol = (points[r][c] + dfs(r - 1, c - 1, points)) - abs(c - (c - 1));

	// * Choice 3: Move from the right diagonal (column c + 1) in the previous row. Penalty = abs(c - (c+1)) = 1
	ll rightDiagnol = (points[r][c] + dfs(r - 1, c + 1, points)) - abs(c - (c + 1));

	return max({upper, leftDiagnol, rightDiagnol});
}

ll dfs(int r, int c, vector<vector<int>> &points) {
	if (r < 0 || r >= m || c < 0 || c >= n) // * Out-of-bounds guard
		return -1e9;

	// * Base Case: If we reach the top row (row 0), the max value is just the cell's points
	if (r == 0)
		return points[r][c];

	// * Memoization check: If we have already calculated this state, return it immediately
	if (dp[r][c] != -1)
		return dp[r][c];

	// * Choice 1: Move straight up from the same column in the previous row (No distance penalty)
	ll upper = points[r][c] + dfs(r - 1, c, points);

	// * Choice 2: Move from the left diagonal (column c - 1) in the previous row. Penalty = abs(c - (c-1)) = 1
	ll leftDiagnol = (points[r][c] + dfs(r - 1, c - 1, points)) - abs(c - (c - 1));

	// * Choice 3: Move from the right diagonal (column c + 1) in the previous row. Penalty = abs(c - (c+1)) = 1
	ll rightDiagnol = (points[r][c] + dfs(r - 1, c + 1, points)) - abs(c - (c + 1));

	return dp[r][c] = max({upper, leftDiagnol, rightDiagnol});
}

// * ------------------------- Approach: Brute Force Approach -------------------------
// ! TLE
// * Top Down
// * TIME COMPLEXITY O(3^n)
// * SPACE COMPLEXITY O(n)
ll bruteForce(vector<vector<int>>& points) {
	m = points.size();
	n = points[0].size();
	
	// Initialize the memoization table with -1 (representing unvisited states)
	// dp.assign(m, vector<ll>(n, -1));
	
	ll ans = LLONG_MIN;
	
	// Start the DFS from every possible starting column in the bottom row (row m - 1)
	for (int j = 0; j < n; ++j) {
			ans = max(ans, dfs(m - 1, j, points));
	}
	
	return ans;
}

// * ------------------------- Approach: Better Approach -------------------------
// ! TLE
// * Top Down + Memoization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2) + O(n) (for recursion stack)
int betterApprach(vector<vector<int>>& points) {
	m = points.size();
	n = points[0].size();
	
	// Initialize the memoization table with -1 (representing unvisited states)
	dp.assign(m, vector<ll>(n, -1));
	
	ll ans = LLONG_MIN;
	
	// Start the DFS from every possible starting column in the bottom row (row m - 1)
	for (int j = 0; j < n; ++j) {
			ans = max(ans, dfs(m - 1, j, points));
	}
	
	return ans;
}

// * ------------------------- Approach: Better Approach -------------------------
// * Bottom Up
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n^2) (No recursion stack)
int minFallingPathSum(vector<vector<int>> &mat) {
	int n = mat.size();

	// * Allocate an (n + 1) x (n + 1) DP table initialized to 0.
	// * dp[r][c] will store the minimum falling path sum to reach cell (r, c).
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	// * Base Case: The first row of the DP table is exactly the same as the first row of the matrix,
	// * since a falling path starting there has no previous elements.
	for (int c = 0; c < n; ++c) {
		dp[0][c] = mat[0][c];
	}

	// * Iterate through the matrix row by row, starting from the second row (r = 1)
	for (int r = 1; r < n; ++r) {
		for (int c = 0; c < n; ++c) {
			// * Choice 1: Coming straight down from the cell directly above
			int upper = mat[r][c] + dp[r - 1][c];

			// * Choice 2: Coming diagonally from the top-left cell.
			// * If we are on the leftmost column (c = 0), this move is invalid, so we use 1e9 as a boundary guard.
			int leftDiagnol = c - 1 >= 0 ? mat[r][c] + dp[r - 1][c - 1] : 1e9;

			// * Choice 3: Coming diagonally from the top-right cell.
			// * If we are on the rightmost column (c = n - 1), this move is invalid, so we use 1e9 as a boundary guard.
			int rightDiagnol = c + 1 < n ? mat[r][c] + dp[r - 1][c + 1] : 1e9;

			// * The minimum path to the current cell is the best of these three valid paths
			dp[r][c] = min({upper, leftDiagnol, rightDiagnol});
		}
	}

	// * Answer can exist in any column of n - 1 (last) row 
	int ans = dp[n - 1][0];
	for (int c = 1; c < n; ++c) {
		ans = min(ans, dp[n - 1][c]);
	}

	return ans;
}


// * ------------------------- Approach: Optimal Approach -------------------------
// * Bottom Up + Space Optimization
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n)
int minFallingPathSum2(vector<vector<int>> &mat) {
	int n = mat.size();

	// * Track path sums of the previous row (initialized with row 0)
	vector<int> prevDp(n);
	for (int c = 0; c < n; ++c) {
		prevDp[c] = mat[0][c];
	}

	// * Process matrix row by row
	for (int r = 1; r < n; ++r) {
		vector<int> curDp(n); // * Temporarily stores results for the current row

		for (int c = 0; c < n; ++c) {
			// * Choice 1: Straight down
			int upper = mat[r][c] + prevDp[c];

			// * Choice 2: Diagonally from top-left (1e9 if out of bounds)
			int leftDiagnol = (c - 1 >= 0) ? mat[r][c] + prevDp[c - 1] : 1e9;

			// * Choice 3: Diagonally from top-right (1e9 if out of bounds)
			int rightDiagnol = (c + 1 < n) ? mat[r][c] + prevDp[c + 1] : 1e9;

			// * Pick the cheapest of the three paths
			curDp[c] = min({upper, leftDiagnol, rightDiagnol});
		}
		prevDp = std::move(curDp);
	}

	// * Return the minimum path sum found across the final row
	return *min_element(begin(prevDp), end(prevDp));
}

int main(void) {
	// * testcase 1
	vector<vector<int>> points = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};

	// * testcase 2
	// vector<vector<int>> points = {{1,5},{2,3},{4,2}};

	cout << "points" << endl;
	for (auto &vec : points)
		printArr(vec);

	// int ans = bruteForce(points);
	// int ans = betterApprach(points);
	// int ans = minFallingPathSum(points);
	int ans = minFallingPathSum2(points);

	cout << "Minimum Falling Path Sum " << ans << endl;

	return 0;
}

// * Run the code
// * g++ --std=c++20 13-minimum-falling-path-sum.cpp -o output && ./output
