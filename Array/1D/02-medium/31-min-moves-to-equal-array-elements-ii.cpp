/*
 * Leetcode - 462
 * Minimum Moves to Equal Array Elements II
 * 
 * 
 * Example 1    :
 * Input        : nums = [1,2,3]
 * Output       : 2
 * Explanation  : [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 * 
 * Example 2    :
 * Input        : nums = [1,10,2,9]
 * Output       : 16
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/ 
*/

#include <vector>
#include <iostream>
#include <algorithm>

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

// * Because you can move numbers both up and down freely, you want to find a central "meeting point" 
// * that minimizes total travel distance. 
// * The median is perfectly balanced because there are an equal number of elements smaller than it and larger than it. 
// * Any step you take away from the median would make the journey longer for the majority of the numbers.

// * ------------------------- APPROACH : Optimal Approach -------------------------
// * Median Approach
// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(1)
int minMoves(vector<int>& nums) {
	// * Step 1: Sort the array to easily find the median element
	sort(nums.begin(), nums.end());

	// * Step 2: Choose the median element as our target
	int median = nums[nums.size() / 2];

	int moves = 0;

	// * Step 3: Calculate total moves to bring every element to the median
	for (int n : nums)
		moves += abs(n - median);

	return moves;
}


int main(void) {
  // * testcase 1
  // vector<int> nums = {1, 2, 3};

  // * testcase 2
  vector<int> nums = {1, 10, 2, 9};

  cout << "nums: ";
  printArr(nums);

  int ans = minMoves(nums);
  cout << "Minimum Moves to Equal Array Elements: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 31-min-moves-to-equal-array-elements-ii.cpp -o output && ./output
