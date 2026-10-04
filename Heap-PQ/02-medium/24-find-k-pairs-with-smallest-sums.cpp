/*
 * Leetcode - 373
 * Find K Pairs with Smallest Sums
 * 
 * You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
 * 
 * Define a pair (u, v) which consists of one element from the first array and one element from the second array.
 * 
 * Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
 * 
 * Example 1    :
 * Input        : nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * Output       : [[1,2],[1,4],[1,6]]
 * Explanation  : The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * 
 * Example 2    :
 * Input        : nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * Output       : [[1,1],[1,1]]
 * Explanation  : The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
 * 
*/

// ! Google

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

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * min-heap greedy expansion
// * TIME COMPLEXITY O(k*(log(min(k, n))))
// * SPACE COMPLEXITY O(min(k, n))

// * - Seed the min-heap with (nums1[i] + nums2[0], i, 0) for all i up to
// *   min(k, n) — one starting point per row, all beginning at column 0.
// * - Each heap entry stores (sum, i, j) so we know which pair produced it.
// * - Repeatedly pop the smallest pair (i, j), record {nums1[i], nums2[j]} in
// *  the result, then push (i, j+1) if j+1 is still in bounds. Stop when k
// *  pairs have been collected or the heap is empty.
vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                   int k) {
	using T = tuple<int, int, int>;
	priority_queue<T, vector<T>, greater<T>> pq;
	int n = nums1.size(), m = nums2.size();
	// * Fill the pq with smallest possible pairs
	for (int i = 0; i < min(k, n); ++i) {
		pq.push({nums1[i] + nums2[0], i, 0});
	}

	vector<vector<int>> ans;
	while (!pq.empty() && (int)ans.size() < k) {
		auto [sum, i, j] = pq.top();
		pq.pop();
		ans.push_back({nums1[i], nums2[j]});
		if (j + 1 < m) { // * in bound of nums2
			pq.push({nums1[i] + nums2[j + 1], i, j + 1});
		}
	}
	return ans;
}

int main(void) {
	// * testcase 1
	int k = 3;
	vector<int> nums1 = {1, 7, 11}, nums2 = {2, 4, 6};

	// * testcase 2
	// int k = 2;
	// vector<int> nums1 = {1, 1, 2}, nums2 = {1, 2, 3};

	vector<vector<int>> ans = kSmallestPairs(nums1, nums2, k);

	return 0;
}
 
// * Run the code
// * g++ --std=c++20 24-find-k-pairs-with-smallest-sums.cpp -o output && ./output
