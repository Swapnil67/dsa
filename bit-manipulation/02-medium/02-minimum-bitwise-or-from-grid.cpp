/*
 * Leetcode - 3858
 * Minimum Bitwise OR From Grid
 * 
 * You are given a 2D integer array grid of size m x n.
 * 
 * You must select exactly one integer from each row of the grid.
 * 
 * Return an integer denoting the minimum possible bitwise OR of the selected integers from each row.
 * 
 * 
 * Example 1    :
 * Input        : grid = [[1,5],[2,4]]
 * Output       : 3
 * Explanation  : The bitwise OR of 1 | 2 = 3​​​​​​​, which is the minimum possible.
 * 
 * Example 2    :
 * Input        : grid = [[3,5],[6,4]]
 * Output       : 5
 * Explanation  : The bitwise OR of 5 | 4 = 5​​​​​​​, which is the minimum possible.
 *
 * https://leetcode.com/problems/minimum-bitwise-or-from-grid/description/ 
*/


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

// * Greedy + Bit Manipulation
// * We'll try to check if the bit can removed from the final answer
// * We take a 16 bit integer here for result
int minimumOR(vector<vector<int>>& grid) {
	int res = 0, forbid = 0;
	for (int bit = 16; bit >= 0; bit--) {
		forbid = forbid | (1 << bit); // * Check if this bit can be removed
		bool canAvoidBit = false;
		for (auto& row : grid) {
			bool canReplacable = false;
			for (auto val : row) {
					// * check in row that is it possible to remove this bit from result
					if ((forbid & val) == 0) {
						canReplacable = true;
						break;
					}
			}
			if (!canReplacable) {
				canAvoidBit = true;
				break;
			}
		}

		if (canAvoidBit) {
			forbid = forbid ^ (1 << bit); // * unset that bit from forbid
			res |= (1 << bit);						// * need this bit in result
		}
		// cout << forbid << " " << res << endl;
	}

	return res;
}

int main(void) {
	// * testcase 1
	vector<vector<int>> grid = {{1, 5}, {2, 4}};

	// * testcase 2
	// vector<vector<int>> grid = {{3, 5}, {6, 4}};

	// * testcase 3
	// vector<vector<int>> grid = {{7, 9, 8}};

	cout << "Grid" << endl;
	for (auto &v : grid)
		printArr(v);

	int ans = minimumOR(grid);
	cout << "Minimum OR: " << ans << endl;
	return 0;
}
 
// * Run the code
// * g++ --std=c++20 02-minimum-bitwise-or-from-grid.cpp -o output && ./output

/*
* [3, 5]        ->       [0011, 0101]
* [6, 4]                 [0110, 0100]

* | Bit | Forbid (Start) | Row 0 Check               | Row 1 Check               | Unavoidable? | Forbid (End) | Res (End) |
* |-----|----------------|---------------------------|---------------------------|--------------|--------------|-----------|
* | 2   | 4 (0100)       | 3 works (4 & 3 == 0)      | 6 fails, 4 fails          | Yes          | 0 (000)      | 4 (0100)  |
* | 1   | 2 (0010)       | 3 fails, 5 works (2&5==0) | 6 fails, 4 works (2&4==0) | No           | 2 (010)      | 4 (0100)  |
* | 0   | 3 (0011)       | 3 fails, 5 fails          | Skipped (Row 0 failed)    | Yes          | 2 (010)      | 5 (0101)  |
* | Final answer: 5.                                                                                                       |

*/