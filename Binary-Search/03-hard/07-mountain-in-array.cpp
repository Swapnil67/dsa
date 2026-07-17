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
	int peakIdxMountainArr(MountainArray &mountainArr) {
		int n = mountainArr.length() - 1;

		// * Check edge cases
		int first_val = cache.count(0) ? cache[0] : mountainArr.get(0);
		int second_val = cache.count(1) ? cache[1] : mountainArr.get(1);
		if (first_val > second_val)
			return 0;

		first_val = cache.count(n - 1) ? cache[n - 1] : mountainArr.get(n - 1);
		second_val = cache.count(n - 2) ? cache[n - 2] : mountainArr.get(n - 2);
		if (first_val > second_val)
			return n - 1;

		// * Get the Peak index in mountain
		int l = 1, r = n - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			// cout << m << endl;
			int mid_val = cache.count(m) == 0 ? mountainArr.get(m) : cache[m];
			cache[m] = mid_val;

			int left_val =
					cache.count(m - 1) == 0 ? mountainArr.get(m - 1) : cache[m - 1];
			cache[m - 1] = left_val;

			int right_val =
					cache.count(m + 1) == 0 ? mountainArr.get(m + 1) : cache[m + 1];
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

	int binarySearch(int &target, MountainArray &mountainArr, int l, int r) {
		while (l <= r) {
			int m = l + (r - l) / 2;
			int mid_val = cache.count(m) == 0 ? mountainArr.get(m) : cache[m];
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

	int binarySearch2(int target, MountainArray &mountainArr, int l, int r) {
		while (l <= r) {
			int m = l + (r - l) / 2;
			int mid_val = cache.count(m) == 0 ? mountainArr.get(m) : cache[m];
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

	int findInMountainArray(int target, MountainArray &mountainArr) {
		int n = mountainArr.length();
		unordered_map<int, int> cache;

		int peak = peakIdxMountainArr(mountainArr);
		// cout << "Peak: " << peak << endl;

		int ans = binarySearch(target, mountainArr, 0, peak);
		if (ans == -1) {
			ans = binarySearch2(target, mountainArr, peak, n - 1);
		}
		return ans;
	}
};