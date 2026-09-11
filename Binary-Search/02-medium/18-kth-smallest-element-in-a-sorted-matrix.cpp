/*
 * Leetcode - 378
 * Kth Smallest Element in a Sorted Matrix
 * 
 * Given an n x n matrix where each of the rows and columns is sorted in ascending order, 
 * return the kth smallest element in the matrix.
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 * 
 * You must find a solution with a memory complexity better than O(n2).
 *
 * Example 1    :
 * Input        : matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 * Output       : 3
 * Explanation  : There are 3 pairs of indices that satisfy the conditions in the statement:
 *
 * Example 2    :
 * Input        : nums = [-6,2,5,-2,-7,-1,3], target = -2
 * Output       : 10
 * Explanation  : There are 10 pairs of indices that satisfy the conditions in the statement:
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
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


// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * min-heap greedy expansion
// * TIME COMPLEXITY O(m * n * logk)
// * SPACE COMPLEXITY O(k)
int bruteForce(vector<vector<int>> &matrix, int k) {
	int m = matrix.size(), n = matrix[0].size();
	priority_queue<int> pq;
	for (int r = 0; r < m; ++r) {
		for (int c = 0; c < n; ++c) {
			pq.push({matrix[r][c]});
			if (pq.size() > k)
				pq.pop();
		}
	}
	return pq.top();
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * min-heap greedy expansion
// * TIME COMPLEXITY O(klogk)
// * SPACE COMPLEXITY O(k)
int betterApproach(vector<vector<int>> &matrix, int k) {
	int n = matrix.size();
	using T = tuple<int, int, int>;
	priority_queue<T, vector<T>, greater<T>> pq;
	// * Fill the pq with smallest matrix values
	for (int r = 0; r < min(k, n); ++r) {
		pq.push({matrix[r][0], r, 0});
	}

	int ans = 0;
	// * min-heap greedy expansion
	for (int i = 1; i <= k; ++i) {
		auto [cur_min, r, c] = pq.top();
		pq.pop();
		ans = cur_min;
		if (c + 1 < n)
			pq.push({matrix[r][c + 1], r, c + 1});
	}
	return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Binary Search
// * TIME COMPLEXITY O(klogk)
// * SPACE COMPLEXITY O(k)
int kthSmallest(vector<vector<int>> &matrix, int k) {
	int m = matrix.size(), n = matrix[0].size();
}

int main(void) {
	// * testcase 1
	int k = 8;
	vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
	
	// * testcase 2
	// int k = 1;
	// vector<vector<int>> matrix = {{-5}};

	cout << "k: " << k << endl;
	cout << "Matrix" << endl;
	for (auto &vec: matrix) 
		printArr(vec);

	// int ans = bruteForce(matrix, k);
	// int ans = betterApproach(matrix, k);
	int ans = kthSmallest(matrix, k);

	cout << "Kth Smallest Element in a Sorted Matrix " << ans << endl;

	return 0;
}

// * Run the code
// * g++ --std=c++20 18-kth-smallest-element-in-a-sorted-matrix.cpp -o output && ./output

