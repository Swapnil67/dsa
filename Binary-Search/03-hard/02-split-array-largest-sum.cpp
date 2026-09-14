/*
* Leetcode - 410
* Split Array Largest Sum / Painter's Partition Problem 
*
* Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any 
* subarray is minimized. Return the minimized largest sum of the split.
*
* Example 1:
* Input: nums = [7,2,5,10,8], k = 2
* Output: 18
* Explanation: There are four ways to split nums into two subarrays.
* The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
*
* https://leetcode.com/problems/split-array-largest-sum/
* https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1
* https://www.naukri.com/code360/problems/allocate-books_1090540
* https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557
* https://www.naukri.com/code360/problems/split-the-given-array-into-k-sub-arrays_1215015
*/

// ! Amazon

#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void printArr(vector<T> &nums) {
  int n = nums.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << nums[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * With a limit of maxSum, we can distribute these books using at most k students.
int isValidPartition(vector<int> &nums, int &maxSum, int &k) {
  int splits = 1;
  long long curSum = 0;
  for (auto &n: nums) {
    if (n > maxSum) return false;
    if (curSum + n <= maxSum) {
      curSum += n;
    } else {
      splits++;
      curSum = n;
    }
  }
  return splits <= k;
}

// * ------------------------- APPROACH : Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(nlog(total - max)) ~ O(nlogS)
// * SPACE COMPLEXITY O(1)
int splitArray(vector<int> a, int k) {
  int n = a.size();
  int l = *max_element(a.begin(), a.end());
  int r = accumulate(a.begin(), a.end(), 0);

  while (l <= r) {
    int m = l + (r - l) / 2;
    if (isValidPartition(a, m, k)) {
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return l;
}

int main() {
  cout << "Split Array Largest Sum" << endl;

  // * testcase 1 (Answer = 18)
  // int k = 2;
  // vector<int> arr = {7, 2, 5, 10, 8};
  
  // * testcase 2 (Answer = 4)
  int k = 3;
  vector<int> arr = {1, 4, 4};
  
  printArr(arr);
  int ans = splitArray(arr, k);
  cout << "Largest minimum sum is " << ans << endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 02-split-array-largest-sum.cpp -o output && ./output