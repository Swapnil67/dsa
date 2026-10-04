/*
 * Leetcode - 312
 * Burst Balloons
 * 
 * 
 * Example 1    :
 * Input        : nums = [3,1,5,8]
 * Output       : 167
 * Explanation  : nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
 *                coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
 * 
 * Example 2    :
 * Input        : nums = [1,5]
 * Output       : 10
 *
 * https://leetcode.com/problems/burst-balloons/description/
 * https://www.youtube.com/watch?v=Yz4LlDSlkns&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=52
*/

// ! Google, Meta, Microsoft, Paytm, Cisco, PhonePe

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

int dfs(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
	if (i > j) // * there are no balloons left in this segment to burst.
		return 0;

	if (dp[i][j] != -1)
			return dp[i][j];

	int max_coins_collected = INT_MIN;

	// * Try every balloon 'k' in the current range [i...j] 
	// * to see which one gives the maximum score if it bursts LAST.
	for (int k = i; k <= j; ++k) {
		// * 1. Calculate coins earned from bursting balloon 'k' LAST.
		// *    Since all other balloons between 'i' and 'j' are already gone,
		// *    its neighbors are the fixed boundaries outside the range: nums[i-1] and nums[j+1].
		int coins_from_k = nums[i - 1] * nums[k] * nums[j + 1];

		// * 2. Solve the left subproblem: maximum coins from bursting 
		// *    all balloons from index 'i' up to 'k - 1'.
		int left_segment_coins = dfs(i, k - 1, nums, dp);

		// * 3. Solve the right subproblem: maximum coins from bursting 
		// *    all balloons from index 'k + 1' up to 'j'.
		int right_segment_coins = dfs(k + 1, j, nums, dp);

		// * Total coins collected for this specific choice of 'k'
		int total_coins = coins_from_k + left_segment_coins + right_segment_coins;

		// * Keep track of the maximum coins possible among all choices of 'k'
		max_coins_collected = max(max_coins_collected, total_coins);
	}

	return dp[i][j] = max_coins_collected;
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * Recursion + Memoization (Top Down)
// * TIME COMPLEXITY  O(n^3)
// * SPACE COMPLEXITY O(n^2)
int maxCoins(vector<int>& nums) {
	int n = nums.size();
	
	// * Create a 2D DP array initialized to -1.
	// * Size is (n + 2) x (n + 2) because we add 2 boundary elements to the array.
	vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
	
	// * Add virtual balloons of value 1 at the boundaries as requested by the problem.
	nums.push_back(1);                   // * Add 1 at the end
	nums.insert(nums.begin(), 1);        // * Add 1 at the start
	
	// * Call our recursive function.
	// * The original balloons are now shifted and sit from index 1 to index n.
	return dfs(1, n, nums, dp);
}

int main(void) {
	// * testcase 1
	vector<int> nums = {3, 1, 5, 8};

	// * testcase 2
	// vector<int> nums = {1, 5};

	cout << "Nums: ";
	printArr(nums);

	int ans = maxCoins(nums);
	cout << "maximum coins: " << ans << endl;

	return 0;
}
 
// * Run the code
// * g++ --std=c++20 11-burst-balloons.cpp -o output && ./output

/*
! 💡 The Core Intuition: Thinking Backwards
* The Problem with Forward Thinking: 
* If we pick a balloon to burst first, it disappears. Its neighbors on the left and right suddenly touch each other.
* This creates a moving target where subproblems depend on each other, which breaks Dynamic Programming rules.

* The Backward Trick: Instead of choosing which balloon to burst first, we choose which balloon k will be the 
* absolute last balloon to burst in the current range [i, j].

* Why Last Works: If balloon k is the last one alive in its range, it means every other balloon between i and j 
* has already been popped and is gone. 
* Therefore: 
* The balloon immediately to its left must be the outer boundary nums[i - 1].
* The balloon immediately to its right must be the outer boundary nums[j + 1].

* Independent Splits: This allows us to cleanly split the problem into two 
* completely independent halves: the left side [i, k-1] and the right side [k+1, j].
*/