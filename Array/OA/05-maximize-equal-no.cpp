/*
 * Maximize Equal Numbers
 * 
 * Description:
 * You are given an integer array `nums` consisting of `n` elements and an integer `k`.
 * For each element at index `i` (0 <= i < n), you must perform the following operation exactly once:
 * - Replace `nums[i]` with `nums[i] + x`, where `x` is any integer in the range `[-k, k]` inclusive.
 * 
 * Return the maximum length of a subsequence of `nums` such that all elements in that subsequence 
 * can be made equal after applying the operation to each element.
 * 
 * Example 1
 * Input  : nums = [5, 8, 10], k = 2
 * Output : 2
 
 * Example 2
 * Input  : nums = [5, 8, 10], k = 3
 * Output : 3
 * 
 * https://www.desiqna.in/13650/google-girl-hackathon-coding-questions-solutions-2023-kumar
*/

// ! 1 <= a[i] <= 100000
// ! 1 <= k <= 100000
// ! nums[i] - k >= 1 & nums[i] + k <= 1e5

// ! Google Hackathon

#include <deque>
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

// ! Range update trick
// * TIME COMPLEXITY O(N+Q)
// * SPACE COMPLEXITY O(1e5)
int maximumBeauty(vector<int> nums, int k) {
  int n = nums.size();
  // int MAXN = 1e5+5;
  int MAXN = 15;
  vector<int> a(MAXN, 0);
  for (int i = 0; i < n; ++i) {
    int l = nums[i] - k, r = (nums[i] + k);
    cout << l << " " << r << endl;
    a[l] += 1;
    a[r + 1] += -1;
  }
  // printArr(a);

  // * Prefix sum on vector a
  int ans = 1;
  for (int i = 1; i < MAXN; ++i) {
    a[i] = (a[i - 1] + a[i]);
    ans = max(ans, a[i]);
  }
  // printArr(a);

  return ans;
}


int main() {
  // * testcase 1 (Ans = 2)
  // int k = 2;
  // vector<int> nums = {5, 8, 10};
  
  // * testcase 2 (Ans = 3)
  int k = 3;
  vector<int> nums = {5, 8, 10};

  cout << "nums: ";
  printArr(nums);

  int ans = maximumBeauty(nums, k);

  cout << "Maximum Equal in Array After Applying Operation: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 05-maximize-equal-no.cpp -o output && ./output

