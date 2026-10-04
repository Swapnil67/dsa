/*
 * Leetcode - 1970
 * Last Day Where You Can Still Cross
 * 
 * There is a 1-based binary matrix where 0 represents land and 1 represents water. 
 * You are given integers row and col representing the number of rows and columns in the matrix, respectively.
 * 
 * Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. 
 * You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith 
 * row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).
 * 
 * You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. 
 * You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four 
 * cardinal directions (left, right, up, and down).
 * 
 * Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.
 *
 * Example 1    :
 * Input        : row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
 * Output       : 2
 *
 * Example 2    :
 * Input        : row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
 * Output       : 1
 *
 * Example 3    :
 * Input        : row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
 * Output       : 3
 *
 * https://leetcode.com/problems/last-day-where-you-can-still-cross/description/
 */

#include <queue>
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

const vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool inBounds(int &r, int &c, int &m, int &n) {
	return r >= 0 && r < m && c >= 0 && c < n;
}

// * Simple BFS that runs in O(Rows * Cols) without modifying or copying
// grids
bool canCross(int rows, int cols, int day, vector<vector<int>> &waterDay) {
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
	queue<pair<int, int>> q;

	// * Initialize BFS with all valid land cells in the top rows on 'day'
	for (int c = 0; c < cols; ++c) {
		if (waterDay[0][c] > day) {
			q.push({0, c});
			visited[0][c] = true;
		}
	}

	while (!q.empty()) {
		auto [r, c] = q.front();
		q.pop();

		if (r == rows - 1)
			return true; // Reached the bottom row

		for (auto &dir : dirs) {
			int dr = r + dir[0];
			int dc = c + dir[1];

			if (inBounds(dr, dc, rows, cols) && !visited[dr][dc]) {
				// * Crucial Step: Use the timestamp matrix to check
				// validity in O(1)
				// * Only go to cell if water is yet to flood.
				if (waterDay[dr][dc] > day) {
					q.push({dr, dc});
					visited[dr][dc] = true;
				}
			}
		}
	}
	return false;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * N = (r x c)
// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(N)
int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
	// * Step 1: Create a timestamp matrix initialized to a late day
	vector<vector<int>> waterDay(row, vector<int>(col, cells.size() + 1));

	// * Record the exact day (1-indexed timestamp) each cell becomes water
	for (int i = 0; i < cells.size(); ++i) {
		int r = cells[i][0] - 1;
		int c = cells[i][1] - 1;
		waterDay[r][c] = i + 1;
	}

	// cout << "waterDay: " << endl;
	// for (auto& vec : waterDay)
	//     printArr(vec);

	// * Step 2: Binary Search on the day count
	int l = 1, r = cells.size(), ans = 0;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (canCross(row, col, m, waterDay)) {
			ans = m;
			l = m + 1; // Try to wait for more days
		}
		else {
			r = m - 1; // Turn back the days
		}
	}
	return ans;
}

int main(void) {
	// * testcase 1
	int row = 2, col = 2;
	vector<vector<int>> cells = {{1, 1}, {2, 1}, {1, 2}, {2, 2}};

	// * testcase 2
	// int row = 2, col = 2;
	// vector<vector<int>> cells = {{1, 1}, {1, 2}, {2, 1}, {2, 2}};

	// * testcase 3
	// int row = 3, col = 3;
	// vector<vector<int>> cells = {{1, 2}, {2, 1}, {3, 3}, {2, 2}, {1, 1}, {1, 3}, {2, 3}, {3, 2}, {3, 1}};

	cout << "cells: " << endl;
	for (auto &vec : cells)
		printArr(vec);

	int ans = latestDayToCross(row, col, cells);
	cout << "Answer: " << ans << endl;

	return 0;
}

// * Run the code
// * g++ --std=c++20 14-last-day-where-you-can-still-cross.cpp -o output && ./output
