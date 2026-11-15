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
 * 
 */

// ! OA
// ! Amazon

// ! Divide And Conquer

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


// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int maxSubArray(vector<int> nums) {
	int n = nums.size();

	// * Maximum Subarray sum which ends at index 'i'
	vector<int> pMax(n, -1e9);
	pMax[0] = nums[0];
	for (int i = 1; i < n; ++i) {
		pMax[i] = max(pMax[i - 1] + nums[i], nums[i]);
	}
	printArr(pMax);

	// * Subarray sum which starts at index 'i'
	// * max suffix sum at 'i'
	vector<int> s(n + 1, -1e9);
	for (int i = n - 1; i >= 0; --i) {
		s[i] = max(s[i + 1] + nums[i], nums[i]);
	}
	printArr(s);
	
	// * largest suffix sum till 'i'
	vector<int> sMax(n + 2, -1e9);
	sMax[n] = s[n];
	for (int i = n - 1; i >= 0; --i) {
		sMax[i] = max(sMax[i + 1], s[i]);
	}
	printArr(sMax);

	int maxSum = INT_MIN;
	for (int i = 0; i < n - 1; ++i) {
		// int leftMax = *max_element(begin(prefixSum), begin(prefixSum) + i);
		// int rightMax = *max_element(begin(suffixSum) + i, end(suffixSum));
		int leftMax = pMax[i];
		int rightMax = sMax[i + 1];
		cout << i << " => " << leftMax << " + " << rightMax << endl;
		maxSum = max(maxSum, leftMax + rightMax);
	}
	return maxSum;
}


int main(void) {
	// * testcase 1
	vector<int> nums = {5, 8, 10, 2, 5, 5};
	
	// * testcase 2
	// vector<int> nums = {-10, -5, 2, 4, -15, -20, 1, 2};

	// * testcase 3
	// vector<int> nums = {-5, 6, 6, -3, 2, 2};

	// * testcase 3
	// vector<int> nums = {0, -1};

	cout << "Input Array: ";
	printArr(nums);
	
	// int ans = bruteForce(nums);
	int ans = maxSubArray(nums);

	// cout << (-2147483648 + (-1)) << '\n';

	cout << "Max 2 Subarray sums: " << ans << endl;

	return 0;
}

// * Run the code
// * g++ --std=c++20 20-find-2-subarr-with-max-sum.cpp -o output && ./output
