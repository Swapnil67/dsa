/*
 * Leetcode - 2444
 * Count Subarrays With Fixed Bounds
 * 
 * You are given an integer array nums and two integers minK and maxK.
 * 
 * A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
 * 
 * - The minimum value in the subarray is equal to minK.
 * - The maximum value in the subarray is equal to maxK.
 * 
 * Return the number of fixed-bound subarrays.
 * 
 * A subarray is a contiguous part of an array.
 * 
 * Example 1
 * Input       : nums = [1,3,5,2,7,5], minK = 1, maxK = 5
 * Output      : 2
 * Explanation : The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
 * 
 * Example 2
 * Input       : nums = [1,1,1,1], minK = 1, maxK = 1
 * Output      : 10
 * Explanation : Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
 * 
 * https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/
*/

// ! microsoft

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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
long long bruteForce(vector<int> &nums, int minK, int maxK) {
  int n = nums.size();
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int cur_min = nums[i], cur_max = nums[i];
    for (int j = i; j < n; ++j) {
      cur_min = min(cur_min, nums[j]);
      cur_max = max(cur_max, nums[j]);
      // cout << cur_min << " " << cur_max << " " << endl;
      if (cur_min == minK && cur_max == maxK)
        ans++;
    }
  }

  return ans;
}

// * culprit_pos is the boundary wall. A valid subarray cannot start at or before this index.

// * smaller is the bottleneck index. A valid subarray must start at or before this index to guarantee 
// * that both minK and maxK are included in the window.

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Three Pointer Approach
// * Find Index of minK & maxK & culprit_idx
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
long long countSubarrays(vector<int> &nums, int minK, int maxK) {
  int n = nums.size();
  long long ans = 0;
  
  // * Track most recent positions of bounds and invalid elements
  int min_k_pos = -1, max_k_pos = -1, culprit_pos = -1;

  for (int i = 0; i < n; ++i) {
    // * Element out of bounds; acts as a hard barrier for valid windows
    if (nums[i] < minK || nums[i] > maxK) 
      culprit_pos = i;

    // * Found a valid minimum boundary
    if (nums[i] == minK) 
      min_k_pos = i;

    // * Found a valid maximum boundary
    if (nums[i] == maxK) 
      max_k_pos = i;

    // * Farthest left a valid subarray can start for this index
    long long smaller = min(min_k_pos, max_k_pos);
    
    // * Number of valid starting positions between the barrier and the boundary
    long long temp = smaller - culprit_pos;
    
    // * Add valid count if positive (valid window exists)
    ans += (temp <= 0 ? 0 : temp);
  }

  return ans;
}

int main(void) {
  // * testcase 1 (ans = 2)
  // int minK = 1, maxK = 5;
  // vector<int> nums = {1, 3, 5, 2, 7, 5};

  // * testcase 2 (ans = 10)
  int minK = 1, maxK = 5;
  vector<int> nums = {2, 1, 3, 5, 1, 4};

  // * testcase 3 (ans = 2)
  // int minK = 1, maxK = 1;
  // vector<int> nums = {1, 1, 1, 1};

  cout << "minK = " << minK << ", maxK = " << maxK << endl;
  cout << "Input Array: ";
  printArr(nums);

  // long long ans = bruteForce(nums, minK, maxK);
  long long ans = countSubarrays(nums, minK, maxK);
  cout << "Count: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 07-cnt-subarr-with-fixed-bounds.cpp -o output && ./output 

/*
* ## 💡 Example from the text dry run:
* nums = [2, 1, 3, 5, 1, 4], minK = 1, maxK = 5
* At Index 4 (Value: 1) in testcase 2

* culprit_pos = -1 (no bad numbers yet)
* smaller = 3 (index of the element 5)

* Count = 3 - (-1) = 4$
* This means there are 4 valid starting choices (indices 0, 1, 2, and 3):
* 
*    1. Start at 0: [2, 1, 3, 5, 1] (Valid)
*    2. Start at 1: [1, 3, 5, 1] (Valid)
*    3. Start at 2: [3, 5, 1] (Valid)
*    4. Start at 3: [5, 1] (Valid)
* 
* Any starting index after smaller (like starting at index 4: [1]) would be invalid because it
* leaves out the 5 at index 3.
*/