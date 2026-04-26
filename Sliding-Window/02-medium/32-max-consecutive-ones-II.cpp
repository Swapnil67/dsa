/*
 * Leetcode - 2294
 * Max Consecutive Ones II
 * 
 * Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.
 *
 * Example 1
 * * Input  : nums = [1,0,1,1,0]
 * * Output : 4
 *
 * Example 2
 * * Input  : nums = [1,0,1,1,0,1]
 * * Output : 4
 * 
 * 
 * https://neetcode.io/problems/max-consecutive-ones-ii/question
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

// * ------------------------- APPROACH 1: Optimal Approach -------------------------
// * Classic Sliding Window
// * TIME COMPLEXITY O(n)
int findMaxConsecutiveOnes(vector<int> &nums) {
// * SPACE COMPLEXITY O(1)
  int n = nums.size();
  int ans = 0;
  int i = 0, j = 0, flips = 1;
  while (j < n) {
    if (nums[j] == 0)
      flips--;

    while (flips < 0) {
      if (nums[i] == 0)
        flips++;
      i++;
    }

    ans = max(ans, (j - i + 1));
    j++;
  }

  return ans;
}

int main(void) {
  // * testcase 1 (ans = 4)
  // vector<int> nums = {1, 0, 1, 1, 0};

  // * testcase 2 (ans = 2)
  vector<int> nums = {1, 0, 1, 1, 0, 1};

  // * testcase 3 (ans = 3)
  // vector<int> nums = {2, 2, 4, 5};

  cout << "Input Array" << endl;
  printArr(nums);
  
  int ans = findMaxConsecutiveOnes(nums);
  cout << "Count: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 32-max-consecutive-ones-II.cpp -o output && ./output 