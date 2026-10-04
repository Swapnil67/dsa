/*
 * Leetcode -  
 * NAME
 * 
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
*/

// ! OA
// ! IBM

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
// * TIME COMPLEXITY O(N^3)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> &nums, int d) {
	int n = nums.size();
	int triplets = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if ((nums[i] + nums[j] + nums[k]) % d == 0)
					triplets += 1;
			}
		}
	}
	return triplets;
}

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
int countKdivTriplets(vector<int> &nums, int d) {
	int n = nums.size();
	unordered_map<int, int> mp;
	int triplets = 0;
	for (int k = 0; k < n; ++k) {
		int rem = ((nums[k] % d) + d) % d;
		int check = (d - rem) % d;
		if (mp.count(check)) 
			triplets += mp[check];

		for (int i = 0; i < k; ++i) {
			int sum = (nums[i] + nums[k]) % d;
			mp[sum] += 1;
		}
	}

	// * For debugging
	// for (auto &it: mp) {
	// 	cout << it.first << " " << it.second << endl;
	// }

	return triplets;
}

int main(void) {
	// * testcase 1
	int k = 5;
	vector<int> nums = {3, 3, 4, 7, 8};

	// * testcase 2
	// int k = 2;
	// vector<int> nums = {1, 2, 3, 4};

	cout << "k: " << k << endl;
	cout << "Array: ";
	printArr(nums);

	int triplets = bruteForce(nums, k);
	// int triplets = countKdivTriplets(nums, k);
	cout << "No of pairs divisible by k: " << triplets << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 33-count-triplets-in-array-divisible-by-k.cpp -o output && ./output
