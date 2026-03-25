/*
 * Leetcode - 128
 * Longest Consecutive Sequence
 * 
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 * 
 * You must write an algorithm that runs in O(n) time.
 * 
 * Example 1    :
 * Input        : nums = [100,4,200,1,3,2]
 * Output       : 4
 * 
 * Example 2    :
 * Input        : nums = [0,3,7,2,5,8,4,6,0,1]
 * Output       : 9
 * 
 * Example 3    :
 * Input        : nums = [1,0,1,2]
 * Output       : 3
 * 
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int bruteForce(vector<int> &nums) {
  int n = nums.size();
  if (n == 0)
    return 0;

  unordered_set<int> st(begin(nums), end(nums));
  int ans = 0, cnt = 0;
  for (auto num : nums) {
    int streak = 0, cur = num;
    while (st.count(cur)) {
      streak++;
      cur += 1;
    }
    ans = max(ans, streak);
  }
  return ans;
}

// * ------------------------- APPROACH 1: Optimal Approach -------------------------

// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(1)
int longestConsecutive(vector<int> &nums) {
  int n = nums.size();
  if (n == 0)
    return 0;

  unordered_set<int> st(begin(nums), end(nums));
  int longest = 1;
  for (auto &it : st) {
    // * New streak can be started
    if (st.count(it - 1) == 0) {
      int next_ele = it + 1, streak = 1;
      while (st.count(next_ele)) {
        streak++;
        next_ele += 1;
      }
      longest = max(longest, streak);
    }
  }

  return longest;
}

int main(void) {
  // * testcase 1
  // std::vector<int> nums = {100, 4, 200, 1, 3, 2};

  // * testcase 2
  std::vector<int> nums = {1, 0, 1, 2};

  // * testcase 3
  // std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

  std::cout << "Input Array: ";
  printArr(nums);

  int ans = longestConsecutive(nums);
  std::cout << "Longest Consecutive Sequence: " << ans << std::endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 23-longest-consecutive-sequence.cpp -o output && ./output
