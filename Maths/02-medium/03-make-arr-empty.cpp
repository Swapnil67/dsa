/*
 * Minimum Number of Operations to Make Array Empty
 * You are given a 0-indexed array nums consisting of positive integers.
 * There are two types of operations that you can apply on the array any number of times:
 * 
 * - Choose two elements with equal values and delete them from the array.
 * - Choose three elements with equal values and delete them from the array.

 * Return the minimum number of operations required to make the array empty, or -1 if it is not possible.
 * 
 * Example 1:
 * Input: nums = [2,3,3,2,2,4,2,3,4]
 * Output: 4
 * 
 * Example 2:
 * Input: nums = nums = [2,1,2,2,3,3]
 * Output: -1
 * 
 * https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/
*/

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
  cout << " ]" << "\n";
}

int minOperations(vector<int> nums) {
  unordered_map<int, int> freq_mp;
  for (auto &x : nums)
    freq_mp[x]++;

  // * count map
  // for (auto it : freq_mp) {
  //   cout << it.first << " => " << it.second << endl;
  // }

  int c = 0;
  for (auto it : freq_mp) {
    if (it.second == 1)
      return -1;

    c += ceil(it.second / 3.0);
  }

  return c;
}

int main() {
  vector<int> arr = {3, 3};
  // vector<int> arr = {2, 1, 2, 2, 3, 3};
  // vector<int> arr = {2, 3, 3, 2, 2, 4, 2, 3, 4};
  // vector<int> arr = {14, 12, 14, 14, 12, 14, 14, 12, 12, 12, 12, 14, 14, 12, 14, 14, 14, 12, 12};
  printArr(arr);

  int ans = minOperations(arr);
  cout << "Minimum Number of Operations to Make Array Empty " << ans << endl;
  return 0;
}

// * run the code
// * g++ --std=c++20 03-make-arr-empty.cpp -o output && ./output