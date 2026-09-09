
/*
 * Leetcode - 2009
 * Minimum Number of Operations to Make Array Continuous

 * You are given an integer array nums. In one operation, you can replace any element in nums with any integer.
 * nums is considered continuous if both of the following conditions are fulfilled:
 * - All elements in nums are unique.
 * - The difference between the maximum element and the minimum element in nums equals nums.length - 1.
 * 
 * For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.
 * 
 * Example 1
 * Input  : nums = [4,2,5,3]
 * Output : 0
 * Explanation: nums is already continuous.
 * 
 * Example 2
 * Input  : nums = [1,2,3,5,6]
 * Output : 1
 * Explanation: One possible solution is to change the last element to 4.
 * The resulting array is [1,2,3,5,4], which is continuous.
 * 
 * Example 3
 * Input  : nums = [1,10,100,1000]
 * Output : 3
 * Explanation: One possible solution is to:
 * Change the second element to 2.
 * Change the third element to 3.
 * Change the fourth element to 4.
 * The resulting array is [1,2,3,4], which is continuous.
 * 
 * https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
*/

#include <set>
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

// * NOTE
// * nums = [1,10,100,1000] after making this arr continous we get [1,2,3,4] or [9,10,11,12] or [98,99,100,101]
// * Here basically question is asking us to sort the array in increasing order

// * Formula
// * max_ele - min_ele = n - 1;
// * max_ele = (n - 1) + min_ele ------ (from above eq)

// * if our n = 5 the we can have following ranges
// * min_ele = 1, max_ele = 5
// * min_ele = 2, max_ele = 6
// * min_ele = 3, max_ele = 7
// * min_ele = 5, max_ele = 9
// * min_ele = 6, max_ele = 10

// ! Intuition
// * Target Length (N) = original = nums.size()
// * Target Window for Element x = [x, x + N - 1]
// * Valid Elements (K) = Count of unique elements in [x, x + N - 1]
// * Operations Needed = N - K
// * Objective = min(N - K) -> max(K)

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Treat each ith element as min_ele
// * Find [min_ele, max_ele] window for every 'i'
// * Find operations by iterating over range [min_ele, max_ele]
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
int bruteForce(vector<int> &nums) {
  int n = nums.size();
  int min_ops = n;
  for (int i = 0; i < n; ++i) {
    set<int> st;                                        // * Set is used for tracking duplicate elements
    int cur_ops = 0;
    int min_ele = nums[i], max_ele = min_ele + (n - 1); // * cur range [min_ele, max_ele]
    for (int j = 0; j < n; ++j) {
      // * cur element exists b/w [min_ele...max_ele] range & also unique.
      if ((nums[j] >= min_ele && nums[j] <= max_ele) && (!st.count(nums[j]))) {
        st.insert(nums[j]);
        continue;
      }
      else {
        // * cur element does not exists b/w [min_ele...max_ele] range.
        cur_ops += 1;
      }
    }
    min_ops = min(min_ops, cur_ops);
  }
  return min_ops;
}


// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1) + auxiliary space because you are modifying the input vector nums in-place.
int minOperations(vector<int>& nums) {
  int original = nums.size();

  // * Sort and remove duplicates (duplicates must be replaced anyway)
  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());

  int n = nums.size();
  int ans = original;
  int r = 0; // * Right pointer for the sliding window

  // * Slide the left pointer 'l' to test each element as the minimum value
  for (int l = 0; l < n; ++l) {
    int minimum = nums[l];
    int max_needed =
        minimum + original - 1; // * Maximum valid value for this window

    // * Expand right pointer while numbers fit within the range
    while (r < n && nums[r] <= max_needed) {
      r++;
    }

    int already = r - l;                 // * Unique numbers already valid in this window
    int operations = original - already; // * Elements left to replace

    ans = min(ans, operations); // * Track the minimum operations needed
  }

  return ans;
}

int main() {
  // * testcase 1
  vector<int> arr = {1, 2, 3, 5, 6};

  // * testcase 3
  // vector<int> arr = {1, 3, 2, 3};

  printf("Input Array\n");
  printArr(arr);

  // int ans = bruteForce(arr);
  int ans = minOperations(arr);
  printf("Minimum Number of Operations to Make Array Continuous: %d\n", ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 04-min-ops-to-make-arr-continous.cpp -o output && ./output