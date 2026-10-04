/*
 * Find 2 subarray with max sum
 *
 * Example 1    :
 * Input        : nums = [5, 8, 10, 2, 5, 5]
 * Output       : 35
 * Explanation  : [5,8,10] + [2,5,5] = 35
 *
 * Example 2    :
 * Input        : nums = [-10, -5, 2, 4, -15, -20, 1, 2]
 * Output       : 9
 * Explanation  : [2, 4] + [1, 3] = 9
 *
 * https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/description/
 * https://drive.google.com/file/d/1ycnifnkUPwNd1LK-WVShouMr8-egcUi6/view
 * https://docs.google.com/document/d/1FqaW_z9jDbabEoFFBHrgcV5Ve4YyLOfjCmttwnbHSTM/edit?tab=t.0
 */

// ! OA
// ! Amazon

// ! Bidirectional Kadane's approach
// ! Divide And Conquer

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

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

int kadanesAlgo(int start, int end, vector<int> nums) {
	int n = nums.size();
	int maxSum = INT_MIN, curSum = 0;
	for (int i = start; i <= end; ++i) {
		curSum = max(curSum + nums[i], nums[i]);
		maxSum = max(maxSum, curSum);
	}
	return maxSum;
}

// * Find 2 subarray with max sum
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> nums) {
	int n = nums.size();
	int maxSum = INT_MIN;
	for (int i = 0; i < n; ++i) {
		int leftMax = kadanesAlgo(0, i, nums);
		int rightMax = kadanesAlgo(i + 1, n - 1, nums);
		maxSum = max(maxSum, leftMax + rightMax);
	}
	return maxSum;
}


// ! Bidirectional Kadane's approach
// * Using Divide and Conquer
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int maxSubArray(vector<ll> nums) {
	int n = nums.size();

	// * Prefix Sum
  vector<ll> preSum(n, 0); // * max prefix sum till subarray 'i'
  preSum[0] = nums[0];

  vector<ll> preMaxSum(n, 0); // * largest prefix sum till 'i'
  preMaxSum[0] = nums[0];
  for (int i = 1; i < n; ++i) {
    preSum[i] = max(preSum[i - 1] + nums[i], nums[i]);
    preMaxSum[i] = max(preMaxSum[i - 1], preSum[i]);
  }
  // printArr(preSum);
  // printArr(preMaxSum);

	// * Suffix Sum
	vector<ll> sufSum(n + 1, 0); // * max suffix sum till subarray 'i'
  sufSum[n - 1] = nums[n - 1];

  vector<ll> sufMaxSum(n + 2, 0); // * largest suffix sum till 'i'
  sufMaxSum[n - 1] = sufSum[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    sufSum[i] = max(sufSum[i + 1] + nums[i], nums[i]);
    sufMaxSum[i] = max(sufMaxSum[i + 1], sufSum[i]);
  }
  // printArr(sufSum);
  // printArr(sufMaxSum);

	int maxSum = INT_MIN;
	for (int i = 0; i < n; ++i) {
		int leftMax = preMaxSum[i];
		int rightMax = sufMaxSum[i + 1];
		cout << i << " = " << leftMax << " + " << rightMax << " => " << leftMax + rightMax << endl;
		maxSum = max(maxSum, leftMax + rightMax);
	}
	return maxSum;
}


int main(void) {
	// * testcase 1
	// vector<ll> nums = {5, 8, 10, 2, 5, 5};

	// * testcase 2
	vector<ll> nums = {-10, -5, 2, 4, -15, -20, 1, 2};

	cout << "Input Array: ";
	printArr(nums);

	// ll ans = bruteForce(nums);
	ll ans = maxSubArray(nums);

	cout << "Max 2 Subarray sums: " << ans << endl;

	return 0;
}

// * Run the code
// * g++ --std=c++20 01-find-2-subarr-with-max-sum-amazon-oa.cpp -o output && ./output
