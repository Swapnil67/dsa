/*
 * Leetcode - 2176
 * Count Equal and Divisible Pairs in an Array
 * 
 * Given a 0-indexed integer array nums of length n and an integer k, 
 * return the number of pairs (i, j) where 0 <= i < j < n, such that nums[i] == nums[j] and (i * j) is divisible by k.
 * 
 * 
 * Example 1    :
 * Input        : nums = [3,1,2,2,2,1,3], k = 2
 * Output       : 4
 * 
 * Example 2    :
 * Input        : nums = [1,2,3,4], k = 1
 * Output       : 0
 *
 * https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/ 
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

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * Hash Map Group
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
int countPairs(vector<int>& nums, int k) {
	unordered_map<int, vector<int>> group;
	int n = nums.size();
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int cur = nums[i];
		for (auto &j : group[cur]) {
			if ((i * j) % k == 0) {
				ans += 1;
			}
		}
		group[cur].push_back(i);
	}
	return ans;
}

int main(void) {
	// * testcase 1
	// int k = 2;
	// vector<int> nums = {3, 1, 2, 2, 2, 1, 3};
	
	// * testcase 2
	int k = 1;
	vector<int> nums = {1, 2, 3, 4};

	int ans = countPairs(nums, k);
	cout << "Answer: " << ans << endl;

	return 0;
}
 
// * Run the code
// * g++ --std=c++20 07-count-equal-and-divisible-pairs-in-an-array.cpp -o output && ./output
