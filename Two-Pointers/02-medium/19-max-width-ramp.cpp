/*
 * Leetcode - 962
 * Maximum Width Ramp
 * 
 * A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. 
 * The width of such a ramp is j - i.
 * 
 * Given an integer array nums, return the maximum width of a ramp in nums.
 * If there is no ramp in nums, return 0.

 * Example 1
 * * Input       : nums = [6, 0, 8, 2, 1, 5]
 * * Output      : 4
 * * Explanation : The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
 * 
 * Example 2
 * * Input       : nums = [9, 8, 1, 0, 1, 9, 4, 0, 4, 1]
 * * Output      : 7
 * * Explanation : The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
 * 
 * Example 3
 * * Input       : nums = [2, 2, 1]
 * * Output      : 1
 * * Explanation : The maximum width ramp is achieved at (i, j) = (0, 1): nums[0] = 2 and nums[1] = 2.
 * 
 * https://leetcode.com/problems/maximum-width-ramp/description/
*/

#include <vector>
#include <climits>
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

// * ------------------------- APPROACH 1: Brute Approach -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> &nums) {
  int n = nums.size();
  int ans = INT_MIN;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (nums[i] <= nums[j]) {
        ans = max(ans, j - i);
      }
    }
  }
  return ans < 0 ? 0 : ans;
}

// * ------------------------- APPROACH 2: Better Approach -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int betterApproach(vector<int> &nums) {
  int n = nums.size();
  int ans = INT_MIN;
  
  for (int i = 0; i < n; ++i) {
    // * start from the back for every 'i'
    int j = n - 1;
    while (nums[i] > nums[j]) {
      j--;
    }
    ans = max(ans, j - i);
  }

  return ans < 0 ? 0 : ans;
}


// * ------------------------- APPROACH 3A: Optimal Approach -------------------------`
// * Two Pointers
// * Pre calculate next greater element to the right of each element
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int maxWidthRampA(vector<int> &nums) {
  int n = nums.size();
  
  // * Create a vector where for each element next greater element
  vector<int> maxToRight(n);
  int curMax = INT_MIN;
  for (int i = n - 1; i >= 0; --i) {
    curMax = max(curMax, nums[i]);
    maxToRight[i] = curMax;
  }
  // printArr(maxToRight);
  
  int ans = INT_MIN;
  int i = 0, j = 0;
  while (j < n) {
    if(nums[i] <= maxToRight[j]) {
      ans = max(ans, j - i);
    }
    else {
      i++;
    }
    j++;
  }

  return ans < 0 ? 0 : ans;
}

int main() {
  // * testcase 1
  vector<int> nums = {6, 0, 8, 2, 1, 5};

  // * testcase 2
  // vector<int> nums = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
  
  // * testcase 3
  // vector<int> nums = {2, 2, 1};

  printArr(nums);

  // int ans = bruteForce(nums);
  // int ans = betterApproach(nums);

  int ans = maxWidthRampA(nums);
  cout << "Maximum Width Ramp: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 19-max-width-ramp.cpp -o output && ./output



// * 6 0 8 2 1 5

// * Next greater element to right vector
// * 8 8 8 5 5 5 


// * 0 1 2 3 4 5 
// * 6 0 8 2 1 5 
// * 8 8 8 5 5 5 
// *   i
// *           j

// * ans =  4