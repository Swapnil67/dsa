/*
 * Leetcode - 3097
 * Shortest Subarray With OR at Least K II
 * 
 * 
 * 
 * https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/description/
*/

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
	int n = arr.size();
	cout << "[ ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i];
		if (i != n - 1)
			cout << ", ";
	}
	cout << " ]" << endl;
}

void updateBits(int &num, int val, vector<int> &bits) {
	for (int i = 0; i < 32; ++i) {
		if ((num >> i) & 1) {
			bits[i] += val;
		}
	}
}

int getDecimal(vector<int> &bits) {
	int num = 0;
	for (int i = 0; i < 32; ++i) {
		if (bits[i] > 0) {
			num |= (1 << i);
		}
	}
	return num;
}

int minimumSubarrayLength(vector<int> &nums, int k) {
	int n = nums.size();
	vector<int> bits(32, 0);
	// * bits[i] = total number of set bits on ith position
	int i = 0, j = 0, ans = INT_MAX;
	while (j < n) {
		updateBits(nums[j], 1, bits); // * add in window
		while (i <= j && getDecimal(bits) >= k) {
			ans = min(ans, (j - i + 1));
			updateBits(nums[i], -1, bits); // * remove from window
			i++;
		}
		j++;
	}
	return (ans == INT_MAX) ? -1 : ans;
}

int main(void) {
  // * testcase 1 (Ans 1)
	// int k = 2;
	// std::vector<int> nums = {1, 2, 3};

	// * testcase 2 (Ans -1)
	// int k = 10;
	// std::vector<int> nums = {2, 1, 8};

	// * testcase 3 (Ans 1)
	// int k = 0;
	// std::vector<int> nums = {1, 2};

	// * testcase 3 (Ans -1)
	int k = 21;
	std::vector<int> nums = {2, 1, 9, 12};

	std::cout << "k: " << k << std::endl;
  std::cout << "Input nums: ";
  printArr(nums);

  int ans = minimumSubarrayLength(nums, k);
  std::cout << "Shortest Subarray With OR at Least K II: " << ans << std::endl;

	return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
