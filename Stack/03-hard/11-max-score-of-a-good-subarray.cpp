/*
 * Leetcode - 1793
 * Maximum Score of a Good Subarray
 * 
 * You are given an array of integers nums (0-indexed) and an integer k.
 * 
 * The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1).
 * A good subarray is a subarray where i <= k <= j.
 * 
 * Return the maximum possible score of a good subarray.
 * 
 * Example 1
 * Input   : nums = [1,4,3,7,4,5], k = 3
 * Output  : 15
 * 
 * Example 2
 * Input   : nums = [5,5,4,5,4,1,1,1], k = 0
 * Output  : 20
 * 
 * https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/
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

// * ------------------------- APPROACH 1: Optimal Approach -------------------------
// * Use Next & Previous smaller elements
// * While popping the elements we find the area of the popped element
// * rectangle must include k-th element of histogram.
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int maximumScore(vector<int> &nums, int k) {
	int n = nums.size();
	stack<int> st;
	int ans = 0;
	for (int i = 0; i < n; ++i)	{
		while (!st.empty() && nums[st.top()] > nums[i]) {
			int top = st.top();
			st.pop();
			int nse = i;
			int pse = !st.empty() ? st.top() : -1;
			// cout << nums[top] << " -> " << nse << " " << pse << endl;
			if (pse < k && nse > k) { // * '<' & '>' becoz we need nse & pse out of the range of 'k'
				int cur = (nums[top] * (nse - pse - 1));
				// cout << cur << endl;
				ans = max(ans, cur);
			}
		}
		st.push(i);
	}

	while (!st.empty()) {
		int top = st.top();
		st.pop();
		int nse = n;
		int pse = !st.empty() ? st.top() : -1;
		// cout << nums[top] << " -> " << nse << " " << pse << endl;
		if (pse < k && nse > k) { // * '<' & '>' becoz we need nse & pse out of the range of 'k'
			ans = max(ans, (nums[top] * (nse - pse - 1)));
		}
	}
	return ans;
}

int main(void) {
  // * testcase 1
	int k = 3;
	vector<int> nums = {1, 4, 3, 7, 4, 5};

	// * testcase 2
	// int k = 0;
  // vector<int> nums = {5,5,4,5,4,1,1,1};

	cout << "k: " << k << endl;
	cout << "nums: ";
	printArr(nums);

  int ans = maximumScore(nums, k);
  cout << "Maximum Score of a Good Subarray: " << ans << endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 11-max-score-of-a-good-subarray.cpp -o output && ./output
