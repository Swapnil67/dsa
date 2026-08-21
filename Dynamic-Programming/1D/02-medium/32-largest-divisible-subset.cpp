/*
 * Leetcode - 368
 * Largest Divisible Subset
 * 
 * Given a set of distinct positive integers nums, return the largest subset answer such that every pair 
 * (answer[i], answer[j]) of elements in this subset satisfies:
 * 
 * answer[i] % answer[j] == 0, or answer[j] % answer[i] == 0
 * 
 * If there are multiple solutions, return any of them.
 * 
 * Example 1    :
 * Input        : nums = [1,2,3]
 * Output       : [1,2]
 * Explanation  : [1,3] is also accepted.
 * 
 * Example 2    :
 * Input        : nums = [1,2,4,8]
 * Output       : [1,2,4,8]
 * Explanation  : There are 10 pairs of indices that satisfy the conditions in the statement:
 * 
 * https://leetcode.com/problems/largest-divisible-subset/
*/

// ! LIS

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

/*
! Intuition
* [a, b, c]
* Assume b % a = 0
* Assume c % b = 0
* therefore we can also say that c % a = 0
*/

void dfs(int i, vector<int> &cur, vector<int> &ans, vector<int> &nums) {
	if (i >= nums.size()) {
		// * If the current subset is larger than our best answer, update it
		if (cur.size() > ans.size()) {
			ans = cur;
		}
		return;
	}

	// * --- OPTION 1: Try INCLUDING nums[i] ---
	// * We can only include it if cur is empty OR if nums[i] is divisible by the last number
	if (cur.empty() || (nums[i] % cur.back() == 0)) {
		cur.push_back(nums[i]);			// * Choose: Add to current subset
		dfs(i + 1, cur, ans, nums); // * Explore down this path
		cur.pop_back();							// * Backtrack: Remove it for other paths
	}

	// * --- OPTION 2: Try EXCLUDING nums[i] ---
	// * We skip the current number and just move to the next index
	dfs(i + 1, cur, ans, nums);
}


// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * Generate All the subsequences
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(2^n) 
vector<int> bruteForce(vector<int> &nums) {
	// * Sort the array first so we only need to check if a larger number
	// * is divisible by a smaller number (nums[i] % cur.back() == 0)
	sort(begin(nums), end(nums));

	vector<int> ans;
	vector<int> cur;
	dfs(0, cur, ans, nums);

	return ans;
}

// * ------------------------- Approach 2: Optimal Approach -------------------------
// * Bottom Up DP
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n) 
vector<int> largestDivisibleSubset(vector<int>& nums) {
	// * Step 1: Sort the numbers so we can easily check divisibility
	// * (A larger number % smaller number == 0)
	sort(begin(nums), end(nums));
	int n = nums.size();
	
	// * t[i] will store the length of the longest divisible subset ending at index i
	vector<int> t(n, 1);
	
	// * lis[i] will store the index of the previous number in our subset 
	// * This acts like a breadcrumb trail to rebuild our final answer
	vector<int> lis(n);

	// * Keep track of the maximum length found and its ending index
	// * Start maxLen at 0 so it always updates on the very first number
	int maxLen = 0, lastIdx = 0;
	
	// * Step 2: Fill the DP table
	for (int i = 0; i < n; ++i) {
		lis[i] = i; // * Point to itself by default (subset of size 1)
		int cur = nums[i];
		
		// * Check all previous numbers before index i
		for (int j = 0; j < i; ++j) {
			// * If cur can divide nums[j], and using nums[j] gives us a longer chain
			if ((cur % nums[j] == 0) && (t[j] + 1 > t[i])) {
				lis[i] = j;			 // * Remember that nums[j] comes before nums[i]
				t[i] = t[j] + 1; // * Update the new max length ending at i
			}
		}

		// * If we found a chain longer than our current record, update it
		if (t[i] > maxLen) {
			lastIdx = i;
			maxLen = t[i];
		}
	}

	// * Step 3: Rebuild the actual subset using our breadcrumb trail (lis)
	vector<int> ans;
	ans.push_back(nums[lastIdx]); // Add the last element of the longest chain
	
	// * Follow the trail backward until an element points to itself
	while (lastIdx != lis[lastIdx]) {
		lastIdx = lis[lastIdx];
		ans.push_back(nums[lastIdx]);
	}
	
	return ans;
}


int main(void) {
  // * testcase 1
	vector<int> nums = {1, 2, 3};

	// * testcase 2
	// vector<int> nums = {1, 2, 4, 8};

	cout << "Input nums: ";
  printArr(nums);

  // int ans = bruteForce(nums);
  vector<int> ans = largestDivisibleSubset(nums);
  cout << "Ans: ";
  printArr(ans);

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 32-largest-divisible-subset.cpp -o output && ./output
