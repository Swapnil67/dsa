/*
 * Leetcode - 453
 * Minimum Moves to Equal Array Elements
 * 
 * 
 * Example 1    :
 * Input        : nums = [1,2,3]
 * Output       : 3
 * Explanation  : [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
 * Example 2    :
 * Input        : nums = [1,1,1]
 * Output       : 0
 *  
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
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

// * Mathematical Trick: Incrementing n-1 elements by \(1\) is mathematically equivalent to decrementing a single element by 1
// * relative to the rest of the array.
// * To make all elements equal with the minimum number of decrements, your target value must be the minimum element in the 
// * array (minEle).
// * Therefore, the total moves required is simply the sum of the differences between each element and the minimum element:

// * ------------------------- APPROACH : Optimal Approach -------------------------

// * Decrementing all nums to minEle
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int minMoves(std::vector<int>& nums) {
	int minEle = INT_MAX;
	long long totalSum = 0;

	// * Single Pass: Track the minimum element and cumulative sum simultaneously
	for (auto &n : nums) {
		if (n < minEle) {
			minEle = n;
		}
		totalSum += n;
	}

	// * Formula: Total Sum - (Number of Elements * Minimum Element)
	return totalSum - (static_cast<long long>(nums.size()) * minEle);
}


int main(void) {
  // * testcase 1
  // vector<int> nums = {1, 2, 3};

  // * testcase 2
	vector<int> nums = {1, 1, 1};

	cout << "nums: ";
  printArr(nums);

  int ans = minMoves(nums);
  cout << "Minimum Moves to Equal Array Elements: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 30-min-moves-to-equal-array-elements.cpp -o output && ./output
