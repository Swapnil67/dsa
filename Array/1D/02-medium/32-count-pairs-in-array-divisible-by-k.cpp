/*
 * Leetcode - ?
 * Count Pairs Divisible By K
 * 
 * Example 1    :
 * Input        : nums = [2, 2, 1, 7, 5, 3], k = 4
 * Output       : 5
 * Explanation  : There are five pairs possible whose sum is divisible by '4' i.e., (2, 2), (1, 7), (7, 5), (1, 3) and (5, 3).
 * 
 * Example 2    :
 * Input        : nums = [5, 9, 36, 74, 52, 31, 42], k = 3
 * Output       : 7
 * Explanation  : There are seven pairs whose sum is divisible by 3, i.e, (9, 36), (9,42), (74, 52), (36, 42), (74, 31), (31, 5) and (5, 52).
 *
 * https://www.naukri.com/code360/problems/sum-of-numbers_975486
 * https://www.geeksforgeeks.org/problems/pairs-with-difference-k1713/1
*/

// ! Paypal

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
* (x + y) % k = 0
* (x % k) = a
* (y % k) = b

* therefore we can say
* (a + b) % k = 0
* b = (k - a) % k         (check in our case)
*/

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(min(N,K))
int countKdivPairs(vector<int> &arr, int k) {
	int n = arr.size();
	int pairs = 0;
	unordered_map<int, int> mp;
	for (auto &x : arr) {
		// * 1. Get the remainder (and handle negative numbers safely)
		int rem = ((x % k) + k) % k;

		// * 2. Calculate the target remainder we need to form a pair
		int check = (k - rem) % k; // * % k to if rem becomes '0'

		// * 3. If we saw that target remainder before, add its count to pairs
		if (mp.count(check))
			pairs += mp[check];

		// * 4. Record the current remainder in our map
		mp[rem]++;
	}
	return pairs;
}

// * Another same questoin
int countOfDivisiblePairs(int n, int m){
	int pairs = 0;
	for (int i = 1; i <= n; ++i) {
		pairs += (m + i % 5) / 5;
	}
	return pairs;
}

int main(void) {
	// * testcase 1
	int k = 4;
	vector<int> nums = {2, 2, 1, 7, 5, 3};

	// * testcase 2
	// int k = 3;
	// vector<int> nums = {5, 9, 36, 74, 52, 31, 42};

	cout << "k: " << k << endl;
	cout << "Array: ";
	printArr(nums);

	int ans = countKdivPairs(nums, k);
	cout << "No of pairs divisible by k: " << ans << endl;
	cout << "No of pairs divisible by 5: " << countOfDivisiblePairs(4, 5) << endl;

	return 0;
}
 
// * Run the code
// * g++ --std=c++20 32-count-pairs-in-array-divisible-by-k.cpp -o output && ./output
