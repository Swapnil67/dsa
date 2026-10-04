/*
 * Leetcode - 795
 * Number of Subarrays with Bounded Maximum
 * 
 * 
 * Example 1    :
 * Input        : nums = [2,1,4,3], left = 2, right = 3
 * Output       : 3
 * Explanation  : There are three subarrays that meet the requirements: [2], [2, 1], [3].
 * 
 * Example 2    :
 * Input        : nums = [2,9,2,5,6], left = 2, right = 8
 * Output       : 7
 *
 * https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/
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

// * culprit_pos is the boundary wall. A valid subarray cannot start at or before this index.

// * Three Pointer Approach
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
  int n = nums.size();
  // * culprit_idx blocks windows; valid_idx tracks the latest valid max candidate
  int culprit_idx = -1, valid_idx = -1;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    // * Element is too large; creates a hard wall for all future windows
    if (nums[i] > right)
      culprit_idx = i;

    // * Element is a valid candidate to be the maximum value in a
    // * subarray
    if (nums[i] >= left)
      valid_idx = i;

    // * Count valid starting positions between the barrier and the valid
    // * element If valid_idx is behind culprit_idx, this naturally adds 0
    // * or negative values
    ans += max(0, valid_idx - culprit_idx);
  }
  return ans;
}

int main(void) {
  // * testcase 1 (ans = 3)
  int left = 2, right = 3;
  vector<int> nums = {2, 1, 4, 3};

  // * testcase 2 (ans = 7)
  // int left = 2, right = 8;
  // vector<int> nums = {2, 9, 2, 5, 6};

  cout << "left = " << left << ", right = " << right << endl;
  cout << "Input Array: ";
  printArr(nums);

  int ans = numSubarrayBoundedMax(nums, left, right);
  cout << "Count: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 24-no-of-subarrays-with-bounded-max.cpp -o output && ./output


