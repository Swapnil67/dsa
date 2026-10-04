/*
 * Count subarrays with sum greater than k 
 *
 * A[i] + A[j] > k
 *
 * Example 1    :
 * Input        : nums = [1, 3, 4, 5, 8], k = 4
 * Output       : 8
 * Explanation  : There are 8 pairs with sum > k
 *
 * Example 2    :
 * Input        : nums = [-4, -1, 1, 3], k = -2
 * Output       : 4
 * Explanation  : There are 4 pairs with sum > k
 * 
 * Example 3    :
 * Input        : nums = [-10, -5, 0, 5, 10], k = -20
 * Output       : 10
 * Explanation  : There are 10 pairs with sum > k
 *
 * https://docs.google.com/document/d/1HJ-uQ5VpiTRoW50S0L6sootpiOR_gJ1k6vHUxAiVgR0/edit?tab=t.0
 * https://drive.google.com/file/d/1ZaW2csWFdSKu_onDtE4i3BVLV0pgO5KG/view
 */

// ! Two Pointer Template
// ! Works only on sorted array

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr)
{
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

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> nums, int k) {
	int n = nums.size();
	int count = 0;
	for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int sum = nums[i] + nums[j];
      if (sum > k) {
        count++;
      }
    }
  }
	return count;
}

// * Two Pointer Template
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int countPairsWithSumMoreThanK(vector<int> nums, int k) {
	int count = 0;
	int i = 0, j = nums.size() - 1;
	while (i < j) {
    int sum = nums[i] + nums[j];
    if (sum > k) {
      // * If nums[i] + nums[j] > k, then because the array is sorted,
      // * nums[i+1] + nums[j], nums[i+2] + nums[j], ... nums[j-1]+nums[j], will also be > k.
      count += (j - i);
      j--;
    } else {
      i++; // * Move the left pointer right to get a larger sum
    }
	}
	return count;
}

int main(void) {
	// * testcase 1
  // int k = 5;
  // vector<int> nums = {1, 3, 4, 5, 8};

  // * testcase 2
  int k = -2;
  vector<int> nums = {-4, -1, 1, 3};

  // * testcase 3
	// int k = -20;
	// vector<int> nums = {-10, -5, 0, 5, 10};

	cout << "k: " << k << endl;
	cout << "Array: ";
	printArr(nums);

	int ans = bruteForce(nums, k);
	// int ans = countPairsWithSumMoreThanK(nums, k);

	cout << "Subarray with sum atmost k: " << ans << endl;

	return 0;
}

// * Run the code
// * g++ --std=c++20 05-count-pairs-sum-atleast-k.cpp -o output && ./output
