/*
 * Leetcode -  PAID
 * Paint House
 * 
 * There is a row of n houses, where each house can be painted one of three colors: red, blue, or green. 
 * The cost of painting each house with a certain color is different. You have to paint all the houses such that 
 * no two adjacent houses have the same color.
 * 
 * The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.
 * 
 * For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2] is the cost of 
 * painting house 1 with color green, and so on...
 * 
 * Return the minimum cost to paint all houses.
 * 
 * Example 1    :
 * Input        : costs = [[17,2,17],[16,16,5],[14,3,19]]
 * Output       : 10
 * 
 * Example 2    :
 * Input        : costs = [[7,6,2]]
 * Output       : 2
 *
 * Example 2    :
 * Input        : costs = [[15,10,16],[10,1,11]]
 * Output       : 16
 *
 * https://neetcode.io/problems/paint-house/question
*/

// ! Amazon, Uber, Google, Microsoft, LinkedIn, Shopify

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

// * Recursion 
int dfs(int i, int prevColor, vector<vector<int>> &costs) {
	if (i == costs.size())
		return 0;

	int res = INT_MAX;
	for (int c = 0; c < 3; ++c) {
		if (c == prevColor)
			continue;
		res = min(res, costs[i][c] + dfs(i + 1, c, costs));
	}

	return res;
}

// * Recursion With Memoization
int dfs(int i, int prevColor, vector<vector<int>> &costs, vector<vector<int>> &dp) {
	if (i == costs.size())
		return 0;

	if (dp[i][prevColor + 1] != -1)
		return dp[i][prevColor + 1];

	int res = INT_MAX;
	for (int c = 0; c < 3; ++c) {
		if (c == prevColor)
			continue;
		res = min(res, costs[i][c] + dfs(i + 1, c, costs, dp));
	}

	return dp[i][prevColor + 1] = res;
}

// * ------------------------- APPROACH: Brute Force -------------------------
// * Top Down approach 
// * TIME COMPLEXITY O(2^N)
// * SPACE COMPLEXITY O(N) (recursion stack)
int bruteForce(vector<vector<int>> &costs) {
	int n = costs.size();
	return dfs(0, -1, costs);
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * Top Down approach + Memoization
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int minCost(vector<vector<int>> &costs) {
	int n = costs.size();
	vector<vector<int>> dp(n + 1, vector<int>(4, -1));
	return dfs(0, -1, costs, dp);
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * Bottom up approach
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int minCost(vector<vector<int>> &costs) {
	int n = costs.size();
	vector<vector<int>> dp(n + 1, vector<int>(4, 0));
	for (int c = 0; c < 3; ++c) {
		dp[0][c] = costs[0][c];
	}

	for (int i = 1; i < n; ++i) {
		for (int c = 0; c < 3; ++c) {
			dp[i][c] = costs[i][c] + min(dp[i - 1][(c + 1) % 3], dp[i - 1][(c + 2) % 3]);
		}
	}

	return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}

int main(void) {
	// * testcase 1
	// vector<vector<int>> costs = {{17, 2, 17}, {16, 16, 5}, {14, 3, 19}};
	// * testcase 2
	vector<vector<int>> costs = {{7, 6, 2}};
	// * testcase 3
	// vector<vector<int>> costs = {{15, 10, 16}, {10, 1, 11}};

	for (auto &vec: costs) printArr(vec);

	int ans = minCost(costs);
	cout << "minimum cost to paint all houses: " << ans << endl;

	return 0;
}

// * Run the code
// * g++ --std=c++20 12-paint-house.cpp -o output && ./output
