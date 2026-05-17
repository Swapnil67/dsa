/*
 * Leetcode - 673
 * Number of Longest Increasing Subsequence
 * 
 * Given an integer array nums, return the number of longest increasing subsequences.
 * 
 * Notice that the sequence has to be strictly increasing.
 * 
 * 
 * Example 1    :
 * Input        : nums = [1,3,5,4,7]
 * Output       : 2
 * Explanation  : The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
 * 
 * Example 2    :
 * Input        : nums = [2,2,2,2,2]
 * Output       : 5
 * Explanation  : The length of the longest increasing subsequence is 1
 * 
 * https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
 * https://www.naukri.com/code360/problems/number-of-longest-increasing-subsequence_3751627
*/

// ! Apple, Samsung, Google, Meta

#include <vector>
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

// * TIME COMPLEXITY O(N * N)
// * SPACE COMPLEXITY O(N)
int findNumberOfLIS(vector<int> &nums) {
  int n = nums.size();
  vector<int> t(n, 1);
  vector<int> cnt(n, 1);

  int longest_lis = 1;
  for (int i = 0; i < n; ++i) {
    int cur = nums[i];
    for (int j = 0; j < i; ++j) {
      if (cur > nums[j]) {
        if (t[j] + 1 == t[i]) { // * add all the subseq at idx 'j' in idx 'i'
          cnt[i] += cnt[j];
        }
        else if (t[j] + 1 > t[i]) {
          t[i] = t[j] + 1;                      // * update the longest lis at index 'i'
          longest_lis = max(longest_lis, t[i]); // * update the longest lis value
          cnt[i] = cnt[j];
        }
      }
    }
  }
  // printArr(t);
  // printArr(cnt);

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (t[i] == longest_lis) {
      ans += cnt[i];
    }
  }
  return ans;
}

int main(void) {
  // * testcase 1
  // vector<int> nums = {1, 3, 5, 4, 7};

  // * testcase 2
  // vector<int> nums = {2, 2, 2, 2, 2};

  // * testcase 3
  vector<int> nums = {2, 24, 12, 18, 25, 20};

  cout << "Input Nums: ";
  printArr(nums);

  int ans = findNumberOfLIS(nums);
  std::cout << "Number of Longest Increasing Subsequence: " << ans << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 27-number-of-lis.cpp -o output && ./output
