/*
 * Leetcode - 2653
 * Sliding Subarray Beauty
 * 
 * Given an integer array nums containing n integers, find the beauty of each subarray of size k.
 * The beauty of a subarray is the xth smallest integer in the subarray if it is negative, or 0 
 * if there are fewer than x negative integers.
 * Return an integer array containing n - k + 1 integers, which denote the beauty of the subarrays in order 
 * from the first index in the array.
 * 
 * Example 1    :
 * Input        : nums = [1,-1,-3,-2,3], k = 3, x = 2
 * Output       : [-1,-2,-2]
 * Explanation  : There are 3 subarrays with size k = 3. 
 *                1st - [1, -1, -3] and the 2nd smallest negative integer is -1. 
 *                2nd - [-1, -3, -2] and the 2nd smallest negative integer is -2. 
 *                3rd - [-3, -2, 3] and the 2nd smallest negative integer is -2.
 * 
 * Example 2    :
 * Input        : nums = [-1,-2,-3,-4,-5], k = 2, x = 2
 * Output       : [-1,-2,-3,-4]
 * Explanation  : There are 4 subarrays with size k = 2.
 *                For [-1, -2], the 2nd smallest negative integer is -1.
 *                For [-2, -3], the 2nd smallest negative integer is -2.
 *                For [-3, -4], the 2nd smallest negative integer is -3.
 *                For [-4, -5], the 2nd smallest negative integer is -4. 
 * 
 * Example 3    :
 * Input        : nums = [-3,1,2,-3,0,-3], k = 2, x = 1
 * Output       : [-3,0,-3,-3,-3]
 * Explanation  : There are 5 subarrays with size k = 2.
 *                For [-3, 1], the 1st smallest negative integer is -3.
 *                For [1, 2], there is no negative integer so the beauty is 0.
 *                For [2, -3], the 1st smallest negative integer is -3.
 *                For [-3, 0], the 1st smallest negative integer is -3.
 *                For [0, -3], the 1st smallest negative integer is -3.
 * 
 * 
 * https://leetcode.com/problems/sliding-subarray-beauty/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

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

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * TIME COMPLEXITY O(N * K)
// * SPACE COMPLEXITY O(1)
vector<int> bruteForce(vector<int> &nums, int k, int x) {
  int n = nums.size();

  vector<int> ans(n - k + 1, 0);
  // * O(N * K)
  for(int i = 0; i <= n - k; ++i) {
    vector<int> temp;
    for (int j = i; j < (i + k); ++j) {
      temp.push_back(nums[j]);
    }

    if (temp.size() >= x) {
      sort(temp.begin(), temp.end());  // * O(KlogK)
      ans[i] = temp[x - 1] <= 0 ? temp[x - 1] : 0;
    }
  }

  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Classic Sliding Window + Counting Sort
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x) {
  int n = nums.size();
  vector<int> ans;

  if (n == 0)
    return ans;

  // * map[number, count]
  unordered_map<int, int> mp;

  int i = 0, j = 0;
  while (j < n) {
    // * Update the number frequency
    mp[nums[j]]++;
    
    // * Shrink the window
    if ((j - i + 1) > k) {
      mp[nums[i]]--;
      i++;
    }

    // * Counting sort
    if ((j - i + 1) == k) {
      int f = 0, val = 0;
      for (int k = -50; k <= -1; ++k) {
        f += mp[k];
        if (f >= x) {
          val = k;
          break;
        }
      }
      ans.push_back(val);
    }
    
    j++;
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // int k = 3, x = 2;
  // vector<int> nums = {1, -1, -3, -2, 3};

  // * testcase 2
  int k = 2, x = 2;
  vector<int> nums = {-1, -2, -3, -4, -5};

  // * testcase 3
  // int k = 2, x = 1;
  // vector<int> nums = {-3, 1, 2, -3, 0, -3};

  // * testcase 3
  // int k = 9, x = 4;
  // vector<int> nums = {-14, 9, 13, -26, 47, -39, -49, -14, 29};

  cout << "k = " << k << ", x = " << x << endl;
  cout << "Input Array" << endl;
  printArr(nums);
  
  // vector<int> ans = bruteForce(nums, k, x);
  vector<int> ans = getSubarrayBeauty(nums, k, x);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 30-sliding-subarr-beauty.cpp -o output && ./output 