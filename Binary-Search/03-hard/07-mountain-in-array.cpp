/*
 * Leetcode - 1095
 * Find in Mountain Array
 *
 * https://neetcode.io/problems/find-in-mountain-array/question
 * https://leetcode.com/problems/find-in-mountain-array/description/
 */

// ! Amazon, Google, Meta, Microsoft, Oracle

// ! Solve this on leetcode

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// * Leetcode class
class MountainArray {
public:
	int get(int index);
	int length();
};

unordered_map<int, int> cache;
class Solution {
public:
	int peakIdxMountainArr(int n, MountainArray &ma) {
		// * Check edge cases
		int val1 = cache.count(0) ? cache[0] : ma.get(0);
		int val2 = cache.count(1) ? cache[1] : ma.get(1);
		if (val1 > val2)
			return 0;

		val1 = cache.count(n - 1) ? cache[n - 1] : ma.get(n - 1);
		val2 = cache.count(n - 2) ? cache[n - 2] : ma.get(n - 2);
		if (val1 > val2)
			return n - 1;

		// * Get the Peak index in mountain
		int l = 1, r = n - 2;
		while (l <= r) {
			int m = l + (r - l) / 2;
			// cout << m << endl;
			int mid_val = cache.count(m) == 0 ? ma.get(m) : cache[m];
			cache[m] = mid_val;

			int left_val =
					cache.count(m - 1) == 0 ? ma.get(m - 1) : cache[m - 1];
			cache[m - 1] = left_val;

			int right_val =
					cache.count(m + 1) == 0 ? ma.get(m + 1) : cache[m + 1];
			cache[m + 1] = right_val;

			// cout << left_val << " " << mid_val << " " << right_val
			//           << endl;

			if (left_val < mid_val && mid_val > right_val) {
				return m;
			}
			else if (left_val < mid_val) {
				// * increasing curve
				l = m + 1;
			}
			else {
				// * decreasing curve
				r = m - 1;
			}
		}
		return -1;
	}

	// * Increasing Array
	int binarySearch(int &target, MountainArray &ma, int l, int r) {
		while (l <= r) {
			int m = l + (r - l) / 2;
			int mid_val = cache.count(m) == 0 ? ma.get(m) : cache[m];
			cache[m] = mid_val;

			if (target == mid_val) {
				return m;
			}
			else if (target > mid_val) {
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}

		return -1;
	}

	// * Decreasing Array
	int binarySearch2(int target, MountainArray &ma, int l, int r) {
		while (l <= r) {
			int m = l + (r - l) / 2;
			int mid_val = cache.count(m) == 0 ? ma.get(m) : cache[m];
			cache[m] = mid_val;

			if (target == mid_val) {
				return m;
			}
			else if (target > mid_val) {
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}

		return -1;
	}

	int findInMountainArray(int target, MountainArray &ma) {
		int n = ma.length();
		unordered_map<int, int> cache;

		int peak = peakIdxMountainArr(n, ma);
		// cout << "Peak: " << peak << endl;

		int ans = binarySearch(target, ma, 0, peak);
		if (ans == -1) {
			ans = binarySearch2(target, ma, peak, n - 1);
		}
		return ans;
	}
};