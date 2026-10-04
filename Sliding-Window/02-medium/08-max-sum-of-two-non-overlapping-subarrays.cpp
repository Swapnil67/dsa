/*
 * Leetcode - 1031
 * Maximum Sum of Two Non-Overlapping Subarrays
 *
 * Given an integer array nums and two integers firstLen and secondLen, return the maximum sum of elements in two non-overlapping subarrays with lengths firstLen and secondLen.
 * The array with length firstLen could occur before or after the array with length secondLen.
 *
 * Example 1    :
 * Input        : nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2
 * Output       : 20
 * Explanation  : One choice of subarrays is [9] with length 1, and [6,5] with length 2. 
 *                The sum is 9 + 11 = 20.
 *
 * Example 2    :
 * Input        : nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
 * Output       : 29
 * Explanation  : One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2. 
 *                The sum is 12 + 17 = 29.
 *
 * Example 3    :
 * Input        : nums = [2,1,5,6,0,9,5,0,3,8], firstLen = 4, secondLen = 3
 * Output       : 31
 * Explanation  : One choice of subarrays is [5,6,0,9] with length 4, and [0,3,8] with length 3. 
 *                The sum is 20 + 11 = 31.
 * 
 * https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
 */

// ! Sliding Window + History Tracking

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()

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
 ! INTUITION:
 * To find the maximum sum of two non-overlapping subarrays of lengths L1 and L2, 
 * we can break the problem down into two independent scenarios:
 * 1. Subarray L1 appears completely to the left of Subarray L2.
 * 2. Subarray L2 appears completely to the left of Subarray L1.
 * 
 * Using a sliding window approach, we maintain the running sum of both windows. 
 * As we slide them across the array from left to right, we keep track of the maximum 
 * sum seen so far for the left window (maxLeft). We then pair this historical maximum 
 * with the current right window's sum to update our global maximum. By computing both 
 * scenarios and taking their maximum, we cover all valid non-overlapping configurations 
 * efficiently in O(N) time and O(1) space.
*/


// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int helper(vector<int> &nums, int firstLen, int secondLen) {
  int n = nums.size();
  int sumFirst = 0, sumSecond = 0;

  // * Compute initial window sums
  for (int i = 0; i < firstLen; ++i)
    sumFirst += nums[i];
  for (int i = firstLen; i < firstLen + secondLen; ++i)
    sumSecond += nums[i];

  int maxFirst = sumFirst;
  int maxTotal = maxFirst + sumSecond;

  // cout << sumFirst << " " << sumSecond << endl;
  for (int i = firstLen + secondLen; i < n; ++i) {
    // * Update the second window by adding the new element and removing the oldest
    sumSecond += nums[i] - nums[i - secondLen];

    // * Update the first window that ends exactly before the second window starts
    sumFirst += nums[i - secondLen] - nums[i - secondLen - firstLen];

    // cout << sumFirst << " " << sumSecond << endl;

    // * Keep track of the best first window seen so far
    maxFirst = max(maxFirst, sumFirst);

    // * Update global maximum
    maxTotal = max(maxTotal, maxFirst + sumSecond);
  }

  return maxTotal;
}

int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
  // * Case 1: Subarray of firstLen comes before subarray of secondLen
  // * Case 2: Subarray of secondLen comes before subarray of firstLen
  return max(helper(nums, firstLen, secondLen),
             helper(nums, secondLen, firstLen));
}

int main(void) {
  // * testcase 1
  // int firstLen = 1, secondLen = 2;
  // vector<int> nums = {0, 6, 5, 2, 2, 5, 1, 9, 4};
  
  // * testcase 2
  // int firstLen = 3, secondLen = 2;
  // vector<int> nums = {3, 8, 1, 3, 2, 1, 8, 9, 0};
  
  // * testcase 3
  int firstLen = 4, secondLen = 3;
  vector<int> nums = {2, 1, 5, 6, 0, 9, 5, 0, 3, 8};

  cout << "firstLen: " << firstLen << ", secondLen: " << secondLen << endl;
  cout << "nums: ";
  printArr(nums);

  int ans = maxSumTwoNoOverlap(nums, firstLen, secondLen);
  cout << "Max Sum: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 08-max-sum-of-two-non-overlapping-subarrays.cpp -o output && ./output
