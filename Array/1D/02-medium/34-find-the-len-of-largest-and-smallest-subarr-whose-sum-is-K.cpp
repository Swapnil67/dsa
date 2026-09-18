/*
 * Leetcode - ?
 * Find the length of largest and smallest subarray whose sum is K
 * 
 * Given an array of size “N” -> find the largest and shortest subarray[i…..j] 
 * with sum equal to “K”
 * In case the answer is not possible print (-1 -1)
 * 
 * Example 1    :
 * Input        : nums = [2,2,1,4], target = 5
 * Output       : {3,2}
 * Explanation  : largest subarry = [2,2,1], shortest subarray = [1,4]
 * 
 * Example 2    :
 * Input        : nums = [1, 5, 3, 4], target = 5
 * Output       : {-1, -1}
 * Explanation  : There is no subarray with sum 5
 *
 * https://drive.google.com/file/d/10AzAC2B0hyBvsxb0VQ5cnul1_fescjDs/view
*/

#include <vector>
#include <iostream>
#include <unordered_map>

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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
pair<int, int> bruteForce(vector<int> &nums, int target) {
	int n = nums.size();
	int minLen = n+1, maxLen = -1;
	for (int i = 0; i < n; ++i) {
		int curSum = 0;
		for (int j = i; j < n; ++j) {
			curSum += nums[j];
			if (curSum == target) {
				minLen = min(minLen, (j - i + 1));
				maxLen = max(maxLen, (j - i + 1));
			}
		}
	}
	if (maxLen == -1)
		return {-1, -1};

	return {maxLen, minLen};
}


// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
pair<int, int> findLargestAndSmallestSubarraySum(vector<int> &nums, int target) {
	int n = nums.size();
	vector<int> prefixSum(n, 0);
	prefixSum[0] = nums[0];
	for (int i = 1; i < n; ++i)
		prefixSum[i] = prefixSum[i - 1] + nums[i];

	// * {prefixSum, index}
	unordered_map<int, int> mp;
	mp[0] = -1;

	// * totalSum till 'j' = prefixSum[j]
	// * find the remaning from mp
	// * rem = prefixSum[j] - target

	// * Find smallest subarray sum
	int minLen = n + 1;
	for (int j = 0; j < n; ++j) {
		// * Get the remaining sum
		int rem = prefixSum[j] - target;
		if (mp.count(rem)) {
			int i = mp[rem] + 1;
			minLen = min(minLen, (j - i + 1));
		}
		mp[prefixSum[j]] = j; // * Overwrite the prefixSum index
	}

	// * Find largest subarray sum
	mp.clear();
	mp[0] = -1;
	int maxLen = -1;
	for (int j = 0; j < n; ++j) {
		// * Get the remaining sum
		int rem = prefixSum[j] - target;
		if (mp.count(rem)) {
			int i = mp[rem] + 1;
			maxLen = max(maxLen, (j - i + 1));
		}

		// * Don't overwrite the prefixSum index
		if (!mp.count(prefixSum[j]))
			mp[prefixSum[j]] = j;
	}

	if (maxLen == -1)
		return {-1, -1};

	return {maxLen, minLen};
}

int main(void) {
	// * testcase 1
	int k = 5;
	vector<int> nums = {2, 2, 1, 4};

	// * testcase 2
	// int k = 2;
	// vector<int> nums = {1, 5, 3, 4};

	cout << "k: " << k << endl;
	cout << "Array: ";
	printArr(nums);

	// pair<int, int> ans = bruteForce(nums, k);
	pair<int, int> ans = findLargestAndSmallestSubarraySum(nums, k);
	cout << "Largest subarray: " << ans.first << endl;
	cout << "Smallest subarray: " << ans.second << endl;

	return 0;
}

// * Run the code
// * g++ --std=c++20 34-find-the-len-of-largest-and-smallest-subarr-whose-sum-is-K.cpp -o output && ./output
