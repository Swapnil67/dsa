/*
 * Leetcode -  
 * NAME
 * 
 * Description
 * 
 * Example 1    :
 * Input        : nums = [-1,1,2,3,1], target = 2
 * Output       : 3
 * Explanation  : There are 3 pairs of indices that satisfy the conditions in the statement:
 * 
 * Example 2    :
 * Input        : nums = [-6,2,5,-2,-7,-1,3], target = -2
 * Output       : 10
 * Explanation  : There are 10 pairs of indices that satisfy the conditions in the statement:
 * 
 * https://leetcode.com/contest/biweekly-contest-192/problems/longest-subarray-divisible-by-k-with-at-most-one-negation-i/
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()

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

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
int longestSubarray(vector<int> &nums, int k) {
  int n = nums.size();

  unordered_map<int, int> mp;

  // * let x be current running sum
  // * x % k = 0                 --- eq1
  // * x - 2*p[i] % k = 0        --- i is any index b/w l...r
  // * x % k = 2*p[i] % k          --- eq2

  int maxLen = 0;
  for (int l = 0; l < n; ++l) {
    long long sum = 0;
    for (int r = l; r < n; ++r) {
      sum += nums[r];
      int x = ((2LL * nums[r]) + k) % k;
      mp[x]++;

      int rem = ((sum % k) + k) % k;
      if (rem == 0 || mp.count(rem)) {
        maxLen = max(maxLen, (r - l + 1));
      }
    }
  }

  return maxLen;
}

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

