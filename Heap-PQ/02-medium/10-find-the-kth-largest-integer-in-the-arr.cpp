/*
 * Leetcode - 1985
 * Find the Kth Largest Integer in the Array
 * 
 * You are given an array of strings nums and an integer k. 
 * Each string in nums represents an integer without leading zeros.
 
 * Return the string that represents the kth largest integer in nums.

 * Example 1
 * input  : nums = ["3","6","7","10"], k = 4
 * output : "3"

 * Example 2
 * input  : nums = ["2","21","12","1"], k = 3
 * output : "2"
 * 
 * https://leetcode.com/problems/process-tasks-using-servers/description/
*/

#include <queue>
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

string kthLargestNumber(vector<string>& nums, int k) {
  int n = nums.size();
  const auto compare = [&](const auto &a, const auto &b)
  { 
    if(a.length() == b.length()) {
      return a > b;
    }
    return a.length() > b.length();
  };

  priority_queue<string, vector<string>, decltype(compare)>
      min_heap(compare);
  for (auto &num: nums) {
    min_heap.push(num);
    if (min_heap.size() > k)
      min_heap.pop();
  }

  // * For debugging
  // while (!min_heap.empty()) { 
  //   string ele = min_heap.top();
  //   cout<< ele <<endl;
  //   min_heap.pop();
  // }

  return min_heap.top();
}

// * Without heap
string kthLargestNumber2(vector<string>& nums, int k) {
  int n = nums.size();
  sort(begin(nums), end(nums), [](const auto &a, const auto &b) { 
    if(a.length() == b.length()) {
      return a < b;
    }
    return a.length() < b.length(); });

  // printArr(nums);
  return nums[n - k];
}

int main(void) {
  // * testcase 1
  int k = 4;
  vector<string> nums = {"3", "6", "7", "10"};

  // * testcase 2
  // int k = 3;
  // vector<string> nums = {"2", "21", "12", "1"};

  cout << "K: " << k << endl;
  cout << "nums: ";
  printArr(nums);
  
  string ans = kthLargestNumber(nums, k);
  // string ans = kthLargestNumber2(nums, k);
  cout << "Ans: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 10-find-the-kth-largest-integer-in-the-arr.cpp -o output && ./output