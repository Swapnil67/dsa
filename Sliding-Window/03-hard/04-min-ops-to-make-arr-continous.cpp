
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
 * https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/description/
*/

#include <set>
#include <vector>
#include <climits>
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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Treat each ith element as min_ele
// * Find [min_ele, max_ele] window for every 'i'
// * Find operations by iterating over range [min_ele, max_ele]
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
int bruteForce(vector<int> &nums) {
  int n = nums.size();
  int min_ops = INT_MAX;
  for (int i = 0; i < n; ++i) {
    set<int> st;                                  // * Set is used for tracking duplicate elements
    int min_ele = nums[i], max_ele = min_ele + n - 1; // * cur range [min_ele, max_ele]
    int cur_ops = 0;
    for (int j = 0; j < n; ++j) {
      // * cur element exists b/w [min_ele...max_ele] range & also not duplicate
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
// * Here we'll sort the inp nums array which will help us find the which elements are
// * out of our cur [min_ele, max_ele] range

// * TIME COMPLEXITY O(Nlogn)
// * SPACE COMPLEXITY O(N)
int minOperations(vector<int> &arr) {
  int n = arr.size();
  
  // * Sort the Arr & Eliminate Duplicates
  set<int> st(arr.begin(), arr.end());
  vector<int> temp(st.begin(), st.end());
  // printArr(temp);
  
  int r = 0, min_operations = INT_MAX;

  for (int l = 0; l < temp.size(); ++l) {
    int minEle = temp[l];
    int maxEle = minEle + (temp.size() - 1);

    // * Find the upper bound of maxEle
    int r = upper_bound(begin(temp), end(temp), maxEle) - begin(temp);

    // * Current valid window
    int within_range = r - l; // * elements b/w minEle & maxEle

    // * To find elements out of range we subtract from the total no. of elements
    min_operations = min(min_operations, (n - within_range));
  }

  return min_operations;
}

int minOperations2(vector<int>& nums) {
  int n = nums.size();

  // * Sort the Arr & Eliminate Duplicates
  set<int> st(nums.begin(), nums.end());
  vector<int> arr(st.begin(), st.end()); // * new nums without duplicates

  int r = 0, min_ops = n;
  for (int l = 0; l < arr.size(); ++l) {
    while (r < arr.size() && arr[r] < arr[l] + n) {
      r += 1;
    }

    int window = r - l;
    min_ops = min(min_ops, n - window);
  }
  return min_ops;
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