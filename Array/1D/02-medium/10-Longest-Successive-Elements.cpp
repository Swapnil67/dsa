/*
 * Leetcode - 128
 * Longest Successive Elements
 *
 * A sequence is successive when the adjacent elements of the sequence have a difference of 1.
 * You must return the length of the longest successive sequence.
 * 
 * Example 1:
 * Input: nums = [5,8,3,2,1,4]
 * Output: 5
 * Explanation: The resultant sequence can be 1,2,3,4,5 therefore its length 5
 * 
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 * https://www.naukri.com/code360/problems/longest-successive-elements_6811740
*/

// ! Amazon, Google, Meta, Microsoft, Apple, Oracle, Tiktok

#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_set>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

bool linearSearch(std::vector<int> arr, int ele) {
  for (int i = 0; i < arr.size(); i++) {
    if(arr[i] == ele) 
      return true;
  }
  return false;
}

// * ------------------------- APPROACH 1 -------------------------
// * Nested Loop [Linear search]
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr) {
  int n = arr.size();
  int maxC = 0, curC = 0;
  for (int i = 0; i < arr.size(); i++) {
    int cur = arr[i];
    while (linearSearch(arr, cur)) {
      curC++;
      cur += 1;
      maxC = std::max(maxC, curC);
    }
    curC = 0;
  }
  return maxC;
}

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * Sort the array and then found longest subsequence
// * TIME COMPLEXITY O(nlogn) + O(n)
// * SPACE COMPLEXITY O(1)
int betterApproach(std::vector<int> nums) {
  // * O(nlogn)
  std::sort(begin(nums), end(nums));
  int n = nums.size(), longest = 1, lastSmaller = INT_MIN;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    // std::cout << lastSmaller << " " << nums[i] - 1 << std::endl;
    if (lastSmaller == nums[i] - 1) {
      cnt++;
      lastSmaller = nums[i];
    }
    else if(nums[i] != lastSmaller) {
      lastSmaller = nums[i];
      cnt = 1;
    }
    longest = std::max(longest, cnt);
  }
  return longest;
}

// * ------------------------- APPROACH 3: Optimal Approach -------------------------`
// * Find the starting point and then search 
// * TIME COMPLEXITY O(3N)
// * SPACE COMPLEXITY O(N)
int findlongestConsecutive(std::vector<int> &arr) {
  int n = arr.size();
  if (n == 0)
    return 0;

  // * Push all the elements into set
  std::unordered_set<int> st(begin(arr), end(arr));

  // * O(2N)
  int longest = 1;
  for (auto it : st) {
    if (st.find(it - 1) == st.end()) {
      // * You are a first element
      int next_ele = it + 1, cnt = 1;
      while (st.find(next_ele) != st.end()) {
        cnt++;
        next_ele += 1;
      }
      longest = std::max(longest, cnt);
    }
    else {
      // * Not a first element
    }
  }
  return longest;
}

int main() {
  // * testcase 1
  // std::vector<int> nums = {102, 4, 100, 1, 101, 3, 2, 1, 1};

  // * testcase 2
  // std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

  // * testcase 3
  std::vector<int> nums = {15, 6, 2, 1, 16, 4, 2, 29, 9, 12, 8, 5, 14, 21, 8, 12, 17, 16, 6, 26, 3}; // * o/p = 6

  std::cout << "Input Array: " << std::endl;
  printArr(nums);

  // int longestSubsequence = bruteForce(nums);
  // int longestSubsequence = betterApproach(nums);
  int longestSubsequence = findlongestConsecutive(nums);
  std::cout << "Longest subsequence is " << longestSubsequence << std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++20 10-Longest-Successive-Elements.cpp -o output && ./output

