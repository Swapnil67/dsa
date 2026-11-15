/*
 * Leetcode - 665
 * Non-decreasing Array
 * 
 * Check if an array with n integers can become non-decreasing (nums[i] <= nums[i + 1]) by 
 * modifying at most one element.
 * 
 * Constraints  : n == nums.length, 1 <= n <= 10^4, -10^5 <= nums[i] <= 10^5
 * Example 1    : nums = [4,2,3] -> true (modify 4 to 1)
 * Example 2    : nums = [4,2,1] -> false
 * 
 * https://leetcode.com/problems/non-decreasing-array/
*/

#include <vector>
#include <iostream>

using namespace std;
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
bool checkPossibility(vector<int> &nums) {
  int n = nums.size();
  bool modify = false;
  for (int i = 0; i < n - 1; ++i) {
    if (nums[i] <= nums[i + 1]) {
      continue;
    }
    else {
      if (modify)
        return false;
      if (i == 0 || nums[i + 1] >= nums[i - 1]) { // * testcase 3
        nums[i] = nums[i + 1];
      } else {
        nums[i + 1] = nums[i];
      }
      modify = true;
    }
  }
  return true;
}

int main(void) {
  // * testcase 1
  vi nums = {4, 2, 3};

  // * testcase 2
  // vi nums = {4, 2, 1};

  // * testcase 3
  // vi nums = {3, 4, 2, 3};

  // * testcase 4
  // vi nums = {3, 4, 1, 5};

  cout << "nums: ";
  printArr(nums);

  int ops = checkPossibility(nums);
  cout << "Minimum Operations to Make the Array Increasing: " << ops << "\n";

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 21-non-decreasing-array.cpp -o output && ./output

