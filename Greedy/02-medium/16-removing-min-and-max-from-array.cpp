/*
 * Leetcode -  2091
 * Removing Minimum and Maximum From Array
 * 
 * There is an element in nums that has the lowest value and an element that has the highest value. 
 * We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.
 * 
 * A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.
 * 
 * Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.
 * 
 * 
 * Example 1    :
 * Input        : nums = [2,'10',7,5,4,'1',8,6]
 * Output       : 5
 * Explanation  : We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
 *                This results in 2 + 3 = 5 deletions, which is the minimum number possible.
 * 
 * Example 2    :
 * Input        : nums = [0,'-4','19',1,8,-2,-3,5]
 * Output       : 3
 * Explanation  : We can remove both the minimum and maximum by removing 3 elements from the front.
 *
 * https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
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

int minimumDeletions(vector<int>& A) {
	int i = 0, j = 0, n = A.size();
	// * Find min & max ele index
	for (int k = 0; k < n; ++k) {
		if (A[i] < A[k]) i = k; // * max
		if (A[j] > A[k]) j = k; // * min
	}
	// cout << i << " " << j << endl;
	// * To remove element A[i],
	// * we can remove i + 1 elements from front,
	// * or we can remove n - i elements from back.

	// * max(i + 1, j + 1) => remove both from front 
	// * max(n - i, n - j) => remove both from back
	// * i + 1 + n - j => remove 'i' from front & 'j' from back
	// * j + 1 + n - i => remove 'j' from front & 'i' from back
	return min({max(i + 1, j + 1), max(n - i, n - j), i + 1 + n - j, j + 1 + n - i});
}

int main(void) {
	// * testcase 1
	vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};

	// * testcase 2
	// vector<int> nums = {0, -4, 19, 1, 8, -2, -3, 5};
	
	// * testcase 3
	// vector<int> nums = {101};

	cout << "Input ";
	printArr(nums);

	int ans = minimumDeletions(nums);
	cout << "Answer " << ans << endl;

	return 0;
}
 
// * Run the code
// * g++ --std=c++20 16-removing-min-and-max-from-array.cpp -o output && ./output
