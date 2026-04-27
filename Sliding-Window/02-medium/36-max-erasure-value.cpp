/*
 * Leetcode - 1695
 * Maximum Erasure Value
 * 
 * You are given an array of positive integers nums and want to erase a subarray containing unique elements. 
 * The score you get by erasing the subarray is equal to the sum of its elements.
 * 
 * Return the maximum score you can get by erasing exactly one subarray.
 * 
 * An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, 
 * if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
 * 
 * 
 * Example 1    :
 * Input        : nums = [4,2,4,5,6]
 * Output       : 17
 * Explanation  : The optimal subarray here is [2,4,5,6].
 * 
 * Example 2    :
 * Input        : nums = [5,2,1,2,5,2,1,2,5]
 * Output       : 8
 * Explanation  : The optimal subarray here is [5,2,1] or [1,2,5].
 * 
 * https://leetcode.com/problems/maximum-erasure-value
*/

#include <vector>
#include <iostream>
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

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int maximumUniqueSubarray(vector<int> &nums) {
  int n = nums.size();
  unordered_map<int, int> freq_mp;
  int max_sum = 0, cur_sum = 0;
  int i = 0, j = 0;
  while (j < n) {
    freq_mp[nums[j]]++;
    cur_sum += nums[j];

    // * Shrink the window
    while (i <= j && freq_mp[nums[j]] > 1) {
      freq_mp[nums[i]]--;
      cur_sum -= nums[i];
      i++;
    }

    max_sum = max(max_sum, cur_sum);
    j++;
  }
  return max_sum;
}

int main(void) {
  // * testcase 1
  // std::vector<int> nums = {4, 2, 4, 5, 6};

  // * testcase 2
  std::vector<int> nums = {5, 2, 1, 2, 5, 2, 1, 2, 5};

  std::cout << "Nums: ";
  printArr(nums);

  int ans = maximumUniqueSubarray(nums);
  std::cout << "Maximum Erasure Value: " << ans << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 36-max-erasure-value.cpp -o output && ./output
