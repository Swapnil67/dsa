/*
 * Leetcode - 1671
 * Minimum Number of Removals to Make Mountain Array
 *
 *
 * Example 1    :
 * Input        : nums = [1,3,1]
 * Output       : 0
 * Explanation  : The array itself is a mountain array so we do not need to remove any elements.
 *
 * Example 2    :
 * Input        : nums = [2,1,1,5,6,2,3,1]
 * Output       : 3
 * Explanation  : Remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
 *
 * Example 3    :
 * Input        : nums = [9, 8, 1, 7, 6, 5, 4, 3, 2, 1]
 * Output       : 2
 * Explanation  : Remove the elements at indices 0 and 1 making the array nums = [9,8].
 *
 * https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
 * https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
 * https://www.naukri.com/code360/problems/longest-bitonic-sequence_1062688?leftPanelTabValue=PROBLEM
 */

// ! LIS

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr)
{
	int n = arr.size();
	cout << "[ ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i];
		if (i != n - 1)
			cout << ", ";
	}
	cout << " ]" << endl;
}

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * Bottom Up DP
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n) 
int minimumMountainRemovals(vector<int> &nums) {
	int n = nums.size();

	// * --- STEP 1: Longest Increasing Subsequence (LIS) ---
	// * dp1[i] stores the length of the longest uphill slope ending at index i
	vector<int> dp1(n + 1, 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			// * If the current number is bigger, we can climb up from j to i
			if (nums[i] > nums[j]) {
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}

	// * --- STEP 2: Longest Decreasing Subsequence (LDS) ---
	// * dp2[i] stores the length of the longest downhill slope starting at index i
	vector<int> dp2(n + 1, 1);
	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j > i; --j) {
			// * If the current number is bigger, we can slide down from i to j
			if (nums[i] > nums[j]) {
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}

	// * --- STEP 3: Find the Maximum Mountain Length ---
	int maxLen = 0;
	for (int i = 0; i < n; ++i) {
		// * CRITICAL CHECK: The peak at index i MUST have a valid uphill
		// * slope (dp1[i] > 1) AND a valid downhill slope (dp2[i] > 1) to
		// * form a real mountain shape.
		if (dp1[i] != 1 && dp2[i] != 1) {
			// * Total length = uphill length + downhill length - 1 (don't
			// * count the peak twice)
			maxLen = max(maxLen, (dp1[i] + dp2[i] - 1));
		}
	}

	// * --- STEP 4: Calculate Removals ---
	// * Total elements minus the longest mountain gives the minimum removals needed
	return n - maxLen;
}

int main(void) {
  // * testcase 1
	vector<int> nums = {9, 8, 1, 7, 6, 5, 4, 3, 2, 1};

	// * testcase 2
	// vector<int> nums = {2, 1, 1, 5, 6, 2, 3, 1};

	// * testcase 3
	// vector<int> nums = {1, 3, 1};

	cout << "Input nums: ";
  printArr(nums);

  int ans = minimumMountainRemovals(nums);
  cout << "Minimum Removals: " << ans << endl;

	return 0;
}

// * Run the code
// * g++ --std=c++20 33-min-no-of-removals-to-make-mountain-array.cpp -o output && ./output
