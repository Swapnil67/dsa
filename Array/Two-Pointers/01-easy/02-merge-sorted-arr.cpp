/*
 * Minimum Difference Between Highest and Lowest of K Scores
 * You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. 
 * You are also given an integer k.
 * 
 * Pick the scores of any k students from the array so that the difference between the highest and the lowest of
 * the k scores is minimized.
 * Return the minimum possible difference.
 * 
 * Example 1
 * Input  : nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * Output : [1,2,2,3,5,6]
 * 
 * Example 2
 * Input  : nums1 = [1], m = 1, nums2 = [], n = 0
 * Output : [1]

 * https://leetcode.com/problems/merge-sorted-array/description/
*/

#include<iostream>

template <typename T>
void printArr(std::vector<T> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`

// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
void mergeBrute(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
  int l = 0, r = 0;
  std::vector<int> ans;
  while(l < m && r < n) {
    if(nums1[l] < nums2[r]) {
      ans.push_back(nums1[l++]);
    }
    else {
      ans.push_back(nums2[r++]);
    }
  }

  while(l < m) {
    ans.push_back(nums1[l++]); 
  }

  while(r < n) {
    ans.push_back(nums2[r++]);
  }

  l = 0;
  while (l < m + n) {
    nums1[l] = ans[l];
    l++;
  }

}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
  int last = m + n - 1;

  // * merge in reverse order
  while(m > 0 && n > 0) {
    if (nums1[m - 1] > nums2[n - 1]) {
      nums1[last] = nums1[m-1];
      m -= 1;
    }
    else {
      nums1[last] = nums2[n - 1];
      n -= 1;
    }
    last -= 1;
  }

  // * fill nums1 with leftover nums2 elements
  while(n > 0) {
   nums1[last] = nums2[n - 1];
    n -= 1;
    last -= 1;
  }
}

int main() {
  int m = 3, n = 3;
  std::vector<int> nums1 = {2, 2, 3, 0, 0, 0};
  std::vector<int> nums2 = {1, 5, 6};
  std::cout<<"nums1: ";
  printArr(nums1);
  std::cout<<"nums2: ";
  printArr(nums2);

  std::cout<<"Merged: ";
  // mergeBrute(nums1, m, nums2, n);
  merge(nums1, m, nums2, n);
  printArr(nums1);
}

// * Run the code
// * g++ --std=c++17 02-merge-sorted-arr.cpp -o output && ./output