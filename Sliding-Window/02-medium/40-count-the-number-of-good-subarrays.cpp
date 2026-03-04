/*
 * Leetcode - 2537
 * Count the Number of Good Subarrays
 * 
 * Given an integer array nums and an integer k, return the number of good subarrays of nums.
 * 
 * A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
 * A subarray is a contiguous non-empty sequence of elements within an array.
 * 
 * Example 1    :
 * Input        : nums = [1,1,1,1,1], k = 10
 * Output       : 1
 * Explanation  : 
 * 
 * Example 2    :
 * Input        : nums = [3,1,4,3,2,2,4], k = 2
 * Output       : 5
 * Explanation  : 
 * 
 * https://leetcode.com/problems/count-the-number-of-good-subarrays/description/
*/

// ! Amazon, Uber

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
long long countGood(vector<int> &nums, int k) {
  int n = nums.size();
  unordered_map<int, int> freq_mp;
  int i = 0, j = 0, pairs = 0;
  long long ans = 0;
  while (j < n) {
    pairs += freq_mp[nums[j]]; // * Add the possible pairs
    freq_mp[nums[j]]++;
    
    while (pairs >= k) {
      ans += (n - j);            // * Take all subarray after and including 'j'
      freq_mp[nums[i]]--;        // * Decr freq
      pairs -= freq_mp[nums[i]]; // * Remove the pairs
      i++;
    }

    j++;
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // int k = 10;
  // vector<int> nums = {1, 1, 1, 1, 1};

  // * testcase 2
  int k = 2 ;
  vector<int> nums = {3, 1, 4, 3, 2, 2, 4};

  cout << "k: " << k << endl;
  cout << "Input nums: ";
  printArr(nums);

  int ans = countGood(nums, k);
  cout << "Good Subarrays: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 40-count-the-number-of-good-subarrays.cpp -o output && ./output
