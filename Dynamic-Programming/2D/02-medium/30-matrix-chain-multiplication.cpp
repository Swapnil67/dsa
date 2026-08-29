/*
 * Leetcode - ?
 * Matrix Chain Multiplication
 * 
 * 
 * Example 1    :
 * Input        : arr = {10, 20, 30, 40}
 * Output       : 18000
 * 
 * Example 2    :
 * Input        : arr = {10, 15, 20, 25}
 * Output       : 8000
 *
 * https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
 * https://www.naukri.com/code360/problems/matrix-chain-multiplication_975344 
*/

// ! HSBC, Walmart, Morgan Stanley

// ! Partition DP

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

int dfs(int i, int j, vector<int> &arr) {
	if (i == j)
		return 0;
	int mini = 1e9;
	for (int k = i; k < j; ++k) { // * partitions
		int steps = arr[i - 1] * arr[k] * arr[j] + dfs(i, k, arr) + dfs(k + 1, j, arr);
		mini = min(mini, steps);
	}
	return mini;
}

int dfs(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
	if (i == j)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	int mini = 1e9;
	for (int k = i; k < j; ++k) { // * partitions
		int steps = arr[i - 1] * arr[k] * arr[j];

		// * 2. Solve the left subproblem: from index 'i' up to 'k'.
		int left_steps = dfs(i, k, arr, dp);

		// * 3. Solve the right subproblem: from index 'k + 1' up to 'j'.
		int right_steps = dfs(k + 1, j, arr, dp);

		// * Total steps for this specific choice of 'k'
		int total_steps = steps + left_steps + right_steps;

		mini = min(mini, total_steps);
	}
	return dp[i][j] = mini;
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * Recursion
// * TIME COMPLEXITY  O(2^n)
// * SPACE COMPLEXITY O(n)
int bruteForce(vector<int> &arr) {
	int n = arr.size() - 1;
	return dfs(1, n, arr);
}

// * ------------------------- Approach 2: Optimal Approach -------------------------
// * Recursion + Memoization (Top Down)
// * TIME COMPLEXITY  O(n^3)
// * SPACE COMPLEXITY O(n^2)
int matrixMultiplication(vector<int> &arr) {
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(n, -1));
	return dfs(1, n - 1, arr, dp);
}

int main(void) {
	// * testcase 1
	// vector<int> arr = {10, 20, 30, 40};

	// * testcase 2
	vector<int> arr = {10, 15, 20, 25};

	cout << "Input: ";
	printArr(arr);

	// int ans = bruteForce(arr);
	int ans = matrixMultiplication(arr);

	cout << "Answer: " << ans << endl;

	return 0;
}
 
// * Run the code
// * g++ --std=c++20 30-matrix-chain-multiplication.cpp -o output && ./output
