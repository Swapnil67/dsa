/*
 * Leetcode - ?
 * Array partition with minimum difference
 *
 *
 * Example 1    :
 * Input        : nums = [1, 6, 11, 5]
 * Output       : 1
 * Explanation  : [1, 5, 6], sum of Subset1 = 12 
 *                [11], sum of Subset2 = 11 
 *                Hence, minimum difference is 1.  
 *
 * Example 2    :
 * Input        : nums = [3, 1, 5, 2, 8]
 * Output       : 1
 * Explanation  : [3, 1, 5], sum of Subset1 = 9 
 *                [2, 8], sum of Subset2 = 10
 *                Hence, minimum difference is 1.  
 *
 *
 *
 * https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
 * https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
 */

#include <vector>
#include <numeric>
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

int minDifference(vector<int> &nums) {
	int n = nums.size();
	int k = accumulate(begin(nums), end(nums), 0);
	vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

	// * 1. Same as subset sum equal to 'k'
  // * base cases
	for (int i = 0; i < n; ++i)
		dp[i][0] = true;
	if (nums[0] <= k)
		dp[0][nums[0]] = true;

	for (int i = 1; i < n; ++i) {
		for (int t = 1; t <= k; ++t) {
			bool not_take = dp[i - 1][t];
			bool take = false;
			if (t >= nums[i]) {
				take = dp[i - 1][t - nums[i]];
			}
			dp[i][t] = take | not_take;
		}
	}

	// * 2. Find the abs min diff
	int minDiff = INT_MAX;
	for (int s1 = 0; s1 <= k / 2; ++s1) { // * All possible subsets for s1
		if (dp[n - 1][s1] == true) { // * If this sum possible
			int s2 = k - s1;
			minDiff = min(minDiff, abs(s1 - s2));
		}
	}

	return minDiff;
}

int main(void) {
	// * testcase 1
	// vector<int> nums = {1, 6, 11, 5};

	// * testcase 2
	vector<int> nums = {3, 1, 5, 2, 8};

	cout << "nums: ";
	printArr(nums);

	int ans = minDifference(nums);
	cout << "Minimum abs diff: " << ans << endl;

	return 0;
}

// * Run the code
// * g++ --std=c++20 05-partition-arr-into-two-arr-to-minimize-sum-diff.cpp -o output && ./output
