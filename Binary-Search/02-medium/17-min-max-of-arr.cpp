/*
 * Leetcode - 2439
 * Minimize Maximum of Array
 * 
 * You are given a 0-indexed array nums comprising of n non-negative integers.
 * In one operation, you must:
 * 
 * Choose an integer i such that 1 <= i < n and nums[i] > 0.
 * - Decrease nums[i] by 1.
 * - Increase nums[i - 1] by 1.
 *  Return the minimum possible value of the maximum integer of nums after performing any number of operations.
 * 
 * Example 1   :
 * Input       : nums = [3, 7, 1, 6]
 * Output      : 5
 * Explanation : 
 * One set of optimal operations is as follows:
 * - Choose i = 1, and nums becomes [4,6,1,6].
 * - Choose i = 3, and nums becomes [4,6,2,5].
 * - Choose i = 1, and nums becomes [5,5,2,5].
 
 * https://leetcode.com/problems/minimize-maximum-of-array/description/
 */

// ! Meta

#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

bool isValid(std::vector<int> nums, int maxVal) {
  int n = nums.size();
  for (int i = 0; i < n - 1; ++i) {
    if (nums[i] > maxVal)
      return false;

    // * how much we need to subtract to nums[i+1] element if we make nums[i] to maxVal
    long long buffer = maxVal - nums[i];
    nums[i + 1] = nums[i + 1] - buffer; // * subtract the buffer to nums[i+1]
  }

  return nums[n - 1] <= maxVal;
}

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * Binary Search On Answers
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1)
int minimizeArrayValue(std::vector<int> nums) {
  int l = 1, r = *std::max_element(begin(nums), end(nums));
  int ans = 0;
  while (l <= r) {
    // * We need to check if every element in array is <= to the 'm'.
    int m = l + (r - l) / 2;
    if (isValid(nums, m)) {
      ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }

  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Goal is to evenly distribute the value
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int minimizeArrayValue2(std::vector<int> arr) {
  int n = arr.size();
  long long sum = 0;
  int res = -1;
  for (int i = 0; i < n; ++i) {
    sum += arr[i];
    int cur = std::ceil((float)sum / (float)(i + 1)); // * Get the avg no.
    res = std::max(res, cur);
    std::cout << sum << " " << cur  << std::endl;
  }
  return res;
}


int main(void) {
  // * testcase 1
  std::vector<int> arr = {3, 7, 1, 6};

  // * testcase 2
  // std::vector<int> arr = {10, 1};

  // * testcase 3
  // std::vector<int> arr = {13, 13, 20, 0, 8, 9, 9};

  std::cout << "Input Array: ";
  printArr(arr);

  int ans = minimizeArrayValue(arr);
  // int ans = minimizeArrayValue2(arr);
  std::cout << "Minimize Maximum of Array " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 17-min-max-of-arr.cpp -o output && ./output

// * DRY RUN

// * We are doing following two operations (simultaneously) on every pass
// * arr[i] = arr[i] - 1              - (i > 1 && i < n)
// * arr[i - 1] = arr[i - 1] + 1          

/*
* i = 0
*        4   3   6   2 => [4,3,6,2] -> [5,2,6,2]
*       +1|  -1|  
*        5   2    
*        
* i = 1
*        5   2   6   2 => [5,2,6,2] -> [5,5,3,2]  
*           +3| -3| 
*        5   5   3   2
*        
* i = 2
*        5   5   3   2 => [5,5,3,2] -> [5,5,5,0]
*               +2| -2|
*                5   0
*/

// * Max ele = 5
