/*
 * Leetcode - contest
 * Filter Occupied Intervals
 * You are given a 2D integer array occupiedIntervals, where occupiedIntervals[i] = [starti, endi] 
 * represents a time interval during which you are occupied. Each interval starts at starti and ends at endi, inclusive. 
 * These intervals may overlap.
 * 
 * You are also given two integers freeStart and freeEnd, which define a free time interval from freeStart to freeEnd, inclusive.
 * Your task is to merge all occupied intervals that overlap or touch, then remove all integer points in the free interval 
 * from the merged occupied intervals.
 * 
 * Two intervals touch if the second interval starts immediately after the first one ends. For example, [1, 1] and [2, 2] 
 * touch and should be merged into [1, 2].
 * 
 * Return the remaining occupied intervals in sorted order. The returned intervals must be non-overlapping and must contain 
 * the minimum number of intervals possible. If there are no remaining occupied points, return an empty list.
 *  
 * Example 1
 * Input  : occupiedIntervals = [[2,6],[4,8],[10,10],[10,12],[14,16]], freeStart = 7, freeEnd = 11
 * Output : [[2,6],[12,12],[14,16]]
 * Explanation: After merging, the occupied intervals are [2, 8], [10, 12], and [14, 16].
 *             Excluding the free interval [7, 11] results in [2, 6], [12, 12], and [14, 16].
 *  
 * Example 2
 * Input  : occupiedIntervals = [[1,5],[2,3]], freeStart = 3, freeEnd = 8
 * Output : [[1,2]]
 * Explanation: After merging, the occupied interval is [1, 5].
 *             Excluding the free interval [3, 8] results in [1, 2].
 *
 * https://leetcode.com/contest/weekly-contest-508/problems/filter-occupied-intervals/description/
 */

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

vector<vector<int>> filterOccupiedIntervals(vector<vector<int>> &occupiedIntervals,
												int freeStart, int freeEnd) {
	sort(begin(occupiedIntervals), end(occupiedIntervals));
	vector<vector<int>> mi;
	int n = occupiedIntervals.size();
	for (auto &interval : occupiedIntervals) {
		if (mi.empty() || interval[0] > mi[mi.size() - 1][1] + 1) {
			mi.push_back(interval);
		} else {
			mi[mi.size() - 1][1] = max(mi[mi.size() - 1][1], interval[1]);
		}
	}

	vector<vector<int>> ans;
	for (int i = 0; i < mi.size(); ++i)
	{
		int s = mi[i][0], e = mi[i][1];
		if (e < freeStart || s > freeEnd) {
			ans.push_back(mi[i]);
		}
		else {
			// * left overlap
			// *                  * -------- *
			// * (freeStart)* -------- *(freeEnd)
			if (s <= freeEnd && s >= freeStart) {
				mi[i][0] = freeEnd + 1;
				if (mi[i][0] <= mi[i][1]) {
					ans.push_back(mi[i]);
				}
			}
			else if (e >= freeStart && e <= freeEnd) {
				// * right overlap
				// * * ------------------ *
				// *        (freeStart)* -------- *(freeEnd)
				mi[i][1] = freeStart - 1;
				if (mi[i][0] <= mi[i][1]) {
					ans.push_back(mi[i]);
				}
			}
			else {
				if (s == freeStart && e == freeEnd) {
					// * complete overlap
					// * * -------- *
					// * * -------- *
					continue;
				}
				else {
					// * Following overlap (2 splits can happen)
					// *          * -------- *
					// * * ------------------------ *
					int s1 = mi[i][0], e1 = freeStart - 1;
					if (s1 <= e1) {
						ans.push_back({s1, e1});
					}
					int s2 = freeEnd + 1, e2 = mi[i][1];
					if (s2 <= e2) {
						ans.push_back({s2, e2});
					}
				}
			}
		}
	}

	return ans;
}

int main(void) {
	// * testcase 1
	vector<vector<int>> occupiedIntervals = {{2, 6}, {4, 8}, {10, 10}, {10, 12}, {14, 16}};
	int freeStart = 7, freeEnd = 11;
	
	// * testcase 2
	// vector<vector<int>> occupiedIntervals = {{1, 5}, {2, 3}};
	// int freeStart = 3, freeEnd = 8;
	
	// * testcase 3
	// vector<vector<int>> occupiedIntervals = {{1, 1}, {2, 2}};
	// int freeStart = 100, freeEnd = 100;
	
	// * testcase 4
	// vector<vector<int>> occupiedIntervals = {{5, 7}, {1, 2}, {3, 4}, {8, 8}};
	// int freeStart = 6, freeEnd = 6;

	cout << "Intervals" << endl;
	for (auto &it: occupiedIntervals) {
		cout << "(" << it[0] << ", " << it[1] << ")" << endl;
	}

	vector<vector<int>> ans = filterOccupiedIntervals(occupiedIntervals, freeStart, freeEnd);
	cout << "Merged Intervals" << endl;
	for (auto &it: ans) {
		cout << "(" << it[0] << ", " << it[1] << ")" << endl;
	}

	return 0;
}

// * Run the code
// * g++ --std=c++20 10-filter-occupied-intervals.cpp -o output && ./output
