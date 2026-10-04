/*
 * Count Good Subarrays
 *
 * Given an array :-> count the number of good subarrays; 
 * 
 * [i...j] is good if sum[i...j] % k == length of that subarray 
 * 
 * Example 1    :
 * Input        : nums = [-1,1,2,3,1], target = 2
 * Output       : 3
 * Explanation  : There are 3 pairs of indices that satisfy the conditions in the statement:
 * 
 * Example 2    :
 * Input        : nums = [-6,2,5,-2,-7,-1,3], target = -2
 * Output       : 10
 * Explanation  : There are 10 pairs of indices that satisfy the conditions in the statement:
 *
 * https://ideone.com/hSbSA4
 * https://drive.google.com/file/d/1fXzb7EMA72N4SSoRmVSnm0kaheg9BEnI/view
 * https://docs.google.com/document/d/1KvjLTpkL1NtQ4ZdkFpWQr1yfWoeW1J3jb1WH4oFTWTc/edit?tab=t.0
*/

// ! OA 
// ! Amazon

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


// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> &nums, int k) {
	int n = nums.size();
	int count = 0;
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = i; j < n; ++j) {
			sum += nums[j];
			int len = (j - i + 1);
			if ((sum % k) == len)
				count++;
		}
	}
	return count;
}

// ! sum[i...j] = (j - i + 1)
// ! let 'p' be the prefix array
// ! p[j] - p[i - 1] = j - i + 1
// ! p[j] - j = p[i - 1] - i + 1
// ! p[j] - j = p[j - 1] - (j - 1)
// ! p[x] - x = p[x] - (x)

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int countGoodSubarrays(vector<int> &nums, int k) {
	int n = nums.size();
	if (n == 0 || k <= 0)
		return 0;

	// * 1. Build the Prefix Sum array safely (size n)
	vector<int> p(n, 0);
	p[0] = nums[0];
	for (int i = 1; i < n; ++i)
		p[i] = p[i - 1] + nums[i];

	printArr(p); // * For debug

	// * Base Case for i - 1 = -1: (p[-1] - 0) % k = (0 - 0) % k = 0
	unordered_map<int, int> mp;
	mp[0] = 1;
	
	int count = 0;
	// * Maximum valid length based on your intuition (Sum % k can only be 0 to k-1)
	int max_valid_len = k - 1;

	for (int j = 0; j < n; ++j) {
		// * A. SLIDING WINDOW CLEANUP
		// * Identify the expired boundary index (i - 1) using max_valid_len
		int expired_idx = j - max_valid_len - 1;
		if (expired_idx >= -1) { // * testcase 4
			int old_p_val = (expired_idx == -1) ? 0 : p[expired_idx];
			// * Since (i - 1) = expired_idx, then i = expired_idx + 1
			long long old_expr = (long long)old_p_val - (expired_idx + 1);
			int old_check = ((old_expr % k) + k) % k;
			mp[old_check]--;
			if (mp[old_check] == 0) 
				mp.erase(old_check);
		}

		// * B. MATCH CHECK & MAP UPDATE
		// * Grouping formula for current index j: p[j] - (j + 1)
		long long val = (long long)p[j] - (j + 1);
		int check = ((val % k) + k) % k;
		cout << p[j] << " " << check << endl;

		if (mp.count(check))
			count += mp[check];

		mp[check]++;
	}

	for (auto &it : mp)
		cout << it.first << " " << it.second << endl;

	return count;
}

int main(void) {
	// * testcase 1
	// int k = 4;
	// vector<int> nums = {1, 3, 2, 4};

	// * testcase 2
	// int k = 4;
	// vector<int> nums = {1, 4, 3, 2, 4};

	// * testcase 3
	// int k = 3;
	// vector<int> nums = {1};
	
	// * testcase 4
	// int k = 2;
	// vector<int> nums = {2, 4};
	
	// * testcase 5
	int k = 2;
	vector<int> nums = {1, 1, 1, 1};
	
	cout << "k: " << k << endl;
	cout << "Array: ";
	printArr(nums);

	// int ans = bruteForce(nums, k);
	int ans = countGoodSubarrays(nums, k);
	
	cout << "Number of good subarrays: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-count-good-subarrays-amazon-oa.cpp -o output && ./output
