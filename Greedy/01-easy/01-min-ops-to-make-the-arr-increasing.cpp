/*
 * Leetcode - 1827
 * Minimum Operations to Make the Array Increasing
 * 
 * Description  : You are given an integer array nums (0-indexed). In one operation, 
 *                you can choose an element of the array and increment it by 1.
 *                Return the minimum number of operations needed to make nums 
 *                strictly increasing.
 * 
 * Constraints  :
 *                1 <= nums.length <= 5000
 *                1 <= nums[i] <= 10^4
 * 
 * Example 1    :
 * Input        : nums = [1,1,1]
 * Output       : 3
 * Explanation  : You can do the following operations:
 *                1) Increment nums[2], so nums becomes [1,1,2].
 *                2) Increment nums[1], so nums becomes [1,2,2].
 *                3) Increment nums[2], so nums becomes [1,2,3].
 * 
 * Example 2    :
 * Input        : nums = [1,5,2,4,1]
 * Output       : 14
 * Explanation  : Increment elements sequentially to make the array strictly increasing.
 *
 * https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << "\n";
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int minOperations(vector<int>& nums) {
  int n = nums.size();
  int prev_max = nums[0];
  int operations = 0;
  for (int i = 1; i < n; ++i) {
    if (nums[i] <= prev_max) {
      operations += (prev_max - nums[i] + 1);
      prev_max = prev_max + 1;
    }
    else {
      prev_max = nums[i];
    }
  }
  return operations; 
}

int main(void) {
  // * testcase 1
  // vi nums = {1, 1, 1};

  // * testcase 2
  vi nums = {1, 5, 2, 4, 1};

  // * testcase 3
  // vi nums = {8};

  cout << "nums: ";
  printArr(nums);

  int ops = minOperations(nums);
  cout << "Minimum Operations to Make the Array Increasing: " << ops << "\n";

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 01-min-ops-to-make-the-arr-increasing.cpp -o output && ./output
