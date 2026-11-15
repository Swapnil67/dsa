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
 * 
 * https://codeforces.com/problemset/problem/1398/C (Easier Version)
 * 
 * https://ideone.com/hSbSA4
 * Old recording
 * https://drive.google.com/file/d/1fXzb7EMA72N4SSoRmVSnm0kaheg9BEnI/view
 * https://docs.google.com/document/d/1KvjLTpkL1NtQ4ZdkFpWQr1yfWoeW1J3jb1WH4oFTWTc/edit?tab=t.0
 * 
 * Same taught again
 * https://drive.google.com/file/d/1CmU1DDfDhiS4PJtBGvGAVmSvt81zZ8Ac/view
 * https://docs.google.com/document/d/1KvjLTpkL1NtQ4ZdkFpWQr1yfWoeW1J3jb1WH4oFTWTc/edit?tab=t.0
*/

// ! OA 
// ! Amazon

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

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

// ! Observation

// ! sum[i...j] = (j - i + 1)
// ! let 'p' be the prefix array
// ! p[j] - p[i - 1] = j - i + 1
// ! p[j] - j = p[i - 1] - i + 1
// ! p[j] - j = p[i - 1] - (i - 1)
// ! p[j] - j = p[k] - k

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int countGoodSubarrays(vector<int> &nums, int k) {
	int n = nums.size();
	if (n == 0 || k <= 0)
		return 0;

	// * 1. Build the Prefix Sum array safely (size n)
	vector<ll> p(n + 1, 0);
	p[0] = 0;
	for (int i = 1; i <= n; ++i)
		p[i] = p[i - 1] + nums[i - 1];

	printArr(p); // * For debug

	// * Base Case for i - 1 = -1: (p[-1] - 0) % k = (0 - 0) % k = 0
	unordered_map<int, int> mp;
	mp[0] = 1;
 
	int count = 0;
	// * Maximum valid length based on your intuition (Sum % k can only be 0 to k-1)
	int max_valid_len = k - 1;

	
	for (int j = 1; j <= n; ++j) {
		// * B. MATCH CHECK & MAP UPDATE
		// * Grouping formula for current index j: p[j] - (j + 1)
		ll check = (((p[j] % k) - (j % k)) + k) % k;
		cout << "(" << p[j] << " % " << k << ") - (" << j << " % " << k << ") => " << check << endl;

		if (mp.count(check))
			count += mp[check];
		
		// * (j - i + 1) < k      - (len of valid subarray must be less than 'k' since we are doing sum % k)
		// * (j - k + 1) < i
		// * A. SLIDING WINDOW CLEANUP
		if ((j - k + 1) >= 0) {
			ll idx = (j - k + 1);
			ll check2 = (((p[idx] % k) - (idx % k)) + k) % k;
			mp[check2]--;
		}

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
	
	// * testcase 6
	// int k = 3;
	// vector<int> nums = {1, 2, 3, 4, 5};

	cout << "k: " << k << endl;
	cout << "Array: ";
	printArr(nums);

	int ans = bruteForce(nums, k);
	// int ans = countGoodSubarrays(nums, k);
	
	cout << "Number of good subarrays: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-count-good-subarrays-amazon-oa.cpp -o output && ./output
