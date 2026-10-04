/*
 * Leetcode - 1547
 * Minimum Cost to Cut a Stick
 * 
 * 
 * Example 1    :
 * Input        : n = 7, cuts = [1,3,4,5]
 * Output       : 16
 * 
 * Example 2    :
 * Input        : n = 9, cuts = [5,6,1,4,2]
 * Output       : 22
 *
 * https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
 * https://www.naukri.com/code360/problems/cost-to-cut-a-chocolate_3208460
 * https://www.youtube.com/watch?v=xwomavsC86c&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=52
*/

// ! Meta, Googles

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
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int dfs(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
	// * Base Case: If the starting index crosses the ending index,
	// * it means there are no more cuts left to make in this segment.
	if (i > j)
			return 0;

	if (dp[i][j] != -1)
			return dp[i][j];

	int mini = INT_MAX;

	// * Loop through all possible cut positions in the current segment
	for (int idx = i; idx <= j; ++idx) {
		// * 1. Calculate the cost of making the current cut.
		// *    The cost is equal to the length of the current stick segment.
		// *    The segment is bounded by cuts[i-1] on the left and cuts[j+1] on the right.
		int current_stick_length = cuts[j + 1] - cuts[i - 1];

		// * 2. Solve the left subproblem: cuts from index 'i' up to 'idx - 1'
		int left_segment_cost = dfs(i, idx - 1, cuts, dp);

		// * 3. Solve the right subproblem: cuts from index 'idx + 1' up to 'j'
		int right_segment_cost = dfs(idx + 1, j, cuts, dp);

		// * Total cost if we choose to cut at 'idx' right now
		int total_cost = current_stick_length + left_segment_cost + right_segment_cost;

		// * Keep track of the minimum cost among all choices
		mini = min(mini, total_cost);
	}

	// * Store the best result for this segment in our DP table and return it
	return dp[i][j] = mini;
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Recursion + Memoization (Top Down)
// * TIME COMPLEXITY  O(c^3)
// * SPACE COMPLEXITY O(c^2)
int minCost(int n, vector<int>& cuts) {
	int c = cuts.size();
	
	// * Create a 2D DP array initialized to -1.
	// * Size is (c + 2) x (c + 2) because we will add 2 elements to the cuts array.
	vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));

	// * Append the end boundary of the stick (length n)
	cuts.push_back(n);
	// * Insert the start boundary of the stick (0) at the beginning
	cuts.insert(cuts.begin(), 0);
	
	// * Sort the cuts so that we can process the stick segments from left to right
	sort(begin(cuts), end(cuts));

	// * Call the helper function. 
	// * Our actual cuts are now located from index 1 up to index 'c' 
	// * because of the 0 we added at index 0.
	return dfs(1, c, cuts, dp);
}

int main(void) {
	// * testcase 1
	// int n = 7;
	// vector<int> cuts = {1, 3, 4, 5};

	// * testcase 2
	int n = 9;
	vector<int> cuts = {5, 6, 1, 4, 2};

	cout << "n: " << n << endl;;
	cout << "Cuts: ";
	printArr(cuts);

	// int ans = bruteForce(n, cuts);
	int ans = minCost(n, cuts);

	cout << "Answer: " << ans << endl;

	return 0;
}
 
// * Run the code
// * g++ --std=c++20 30-matrix-chain-multiplication.cpp -o output && ./output
