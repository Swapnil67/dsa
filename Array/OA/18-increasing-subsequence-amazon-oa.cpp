/*
 * Increasing Subsequence
 * 
 * Please find the increasing subsequence of size - “3” 
 * - return true if it exists; 
 * - return false if it does not exist 
 * 
 * a[i] < a[j] < a[k] && i < j < k
 * 
 * Constraints:
 * 
 * Example 1    :
 * Input        : nums = [18, 5, 4, 3, 2, 1, 8, 10]
 * Output       : true
 * Explanation  : Valid Triplets [(1,8,10) , (5,8,10) , (4,8,10) , (3,8,10) ,(2,8,10)]
 * 
 * https://docs.google.com/document/d/1D4g82GgNWVDpAhk5TaMT65yNbqFtFrbj87jbGvw7_Q4/edit?tab=t.0
*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

// Macros
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
  cout << " ]" << "\n";
}

// ! Iterate through all the triplets. 
// * TIME COMPLEXITY O(N^3)
// * SPACE COMPLEXITY O(1)
bool bruteForce(vi nums) {
  int n = nums.size();
  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      for (int k = j + 1; k < n; ++k) {
        // * increasing subsequence
        if (nums[i] < nums[j] && nums[j] < nums[k]) {
          // cout << nums[i] << " < " << nums[j] << " < " << nums[k] << "\n";
          return true;
        }
      }
    }
  }
  return false;
}

// ! Observation
/*
* -------------------------------------------
* 1                   i                     n
*
* If we are standing at index 'i' then we need to find 
* - minimum number in range of (1, i - 1)
* - maximum number in range of (i + 1, n)
* Then we can say in O(1) the following 
*         min < i < max
*/
// ! Prefix & Suffix 
// * TIME COMPLEXITY O(3N)  => O(N)  
// * SPACE COMPLEXITY O(2N) => O(N)
bool betterApproach(vi nums) {
  int n = nums.size();

  // * Prefix array of minimun
  // * p[i] = smallest number in range (0,i) 
  vector<int> pre(n);
  pre[0] = nums[0];
  for (int i = 1; i < n; ++i) {
    pre[i] = min(pre[i - 1], nums[i]);
  }
  // printArr(pre);

  // * Suffix array of maximum
  // * s[i] = biggest number in range (i,n-1)
  vector<int> suf(n);
  suf[n - 1] = nums[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    suf[i] = max(nums[i], suf[i + 1]);
  }
  // printArr(suf);

  // * For every 'i' from 1 to n - 1 check the following condition
  // * pre[i-1] < nums[i] && nums[i] < suf[i+1]
  for (int i = 1; i < n - 1; ++i) {
    if (pre[i - 1] < nums[i] && nums[i] < suf[i + 1]) {
      cout << pre[i - 1] << " < " << nums[i] << " < " << suf[i + 1] << "\n";
      return true;
    }
  }
  return false;
}

// ! Observation
/*
* Same as above observation we'll use the prefix & suffix concept 
* but here we'll only calculate suffix vector for prefix minimum 
* we'll calculate it on the go.
*/
// ! Prefix Variable & Suffix Vector
// * TIME COMPLEXITY O(2N)  => O(N)  
// * SPACE COMPLEXITY O(N)
bool optimalApproach(vi nums) {
  int n = nums.size();

  // * Suffix array of maximum
  // * s[i] = biggest number in range (i,n-1)
  vector<int> suf(n);
  suf[n - 1] = nums[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    suf[i] = max(nums[i], suf[i + 1]);
  }
  // printArr(suf);

  int min_p = nums[0];
  // * For every 'i' from 1 to n - 1 check the following condition
  // * pre[i-1] < nums[i] && nums[i] < suf[i+1]
  for (int i = 1; i < n - 1; ++i) {
    if (min_p < nums[i] && nums[i] < suf[i + 1]) {
      cout << min_p << " < " << nums[i] << " < " << suf[i + 1] << "\n";
      return true;
    }
    min_p = min(min_p, nums[i]);
  }
  return false;
}

// ! Observation
/*
* (a[i] + 1 == a[j] && a[j] + 1 == a[k]) 
* The above equation already implies the following 
* => b[i] < b[j] < b[k] 
* Eg of valid triplets is [2, 3, 4] or [3, 4, 5]
*/
// ! Prefix & Suffix 
// * TIME COMPLEXITY O(2N)  => O(N)  
// * SPACE COMPLEXITY O(N)
bool optimalApproachFollowUp(vi nums) {
  int n = nums.size();

  // * Prefix map of nums[i] - 1
  unordered_map<int, int> pre_mp;
  for (int i = 0; i < n; ++i) {
    pre_mp[nums[i] - 1]++;
  }
  // for (auto &it: pre_mp) cout << it.first << " " << it.second << "\n";

  // * suffix map of nums[i] + 1
  unordered_map<int, int> suf_mp;
  for (int i = n - 1; i >= 0; --i) {
    suf_mp[nums[i] + 1]++;
  }
  // for (auto &it: suf_mp) cout << it.first << " " << it.second << "\n";

  for (int i = 0; i < n; ++i) {
    if (pre_mp.count(nums[i] - 1) && suf_mp.count(nums[i] + 1)) {
      // cout << nums[i] - 1 << " < " << nums[i] << " < " << nums[i] + 1 << "\n";
      return true;
    }
  }
  return false;
}

int main(void) {
  // * testcase 1
  // vi nums = {18, 5, 4, 3, 2, 1, 8, 10};

  // * testcase 2
  // vi nums = {2, 5, 8, 1, 10};

  // cout << "nums: ";
  // printArr(nums);

  // bool ans = bruteForce(nums);
  // bool ans = betterApproach(nums);
  // bool ans = optimalApproach(nums);

  // * ------- Follow up 1

  vi nums2 = {1, 4, 2, 9, 3, 8, 4};
  cout << "nums2: ";
  printArr(nums2);
  bool ans = optimalApproachFollowUp(nums2);

  cout << "increasing subsequence: " << ans << "\n";
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 18-increasing-subsequence-amazon-oa.cpp -o output && ./output
