/*
 * Maximum length of a contiguous consistent activity streak
 * 
 * Atlassian tracks various project activities over time, such as issues created, tasks completed, 
 * or deployments made each day.
 * 
 * You are given an array representing the activity recorded on consecutive days. 
 * A consistent activity streak is a contiguous sequence of days where the change in activity between 
 * every pair of consecutive days remains the same. 
 * 
 * Your task is to determine the maximum length of a contiguous consistent activity streak in the 
 * given array. 
 * 
 * The streak must contain at least two days.
 * 
 * Example 1    :
 * Input        : nums = [10 7 4 6 8 10 11]
 * Output       : 4
 * Explanation  : [4 6 8 10] longest subarray with AP = 2
 * 
 * Example 2    :
 * Input        : nums = [9 7 5 3]
 * Output       : 4
 * Explanation  : [9 7 5 3] longest subarray with AP = 2
 * 
 * Example 3    :
 * Input        : nums = [5 5 4 5 5 5 4 5 6]
 * Output       : 3
 * Explanation  : [5 5 5] longest subarray with AP = 1
 * 
 * Example 4    :
 * Input        : nums = [5 4 3 2 1 2 3 4 5 6]
 * Output       : 6
 * Explanation  : [1 2 3 4 5 6] longest subarray with AP = 1
 * 
 *
 * https://docs.google.com/document/d/1_PXMAgdojmZV9UJCPhV8zXghZfu6_N8ILGVTUM7Mrlg/edit?tab=t.0
*/

// ! OA
// ! Microsoft
// ! Google Kickstart

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

// * Create diff array and find longest len with same elements
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int bruteForce(vector<ll> nums) {
  int n = nums.size();
  // * Save the diff in adj elements
  vector<ll> diff(n - 1, 0);
  for (int i = 1; i < n; ++i) {
    diff[i - 1] = nums[i] - nums[i - 1];
  }
  // printArr(diff);

  int cnt = 1, ans = 1;
  for (int i = 1; i <= diff.size() - 1; ++i) {
    if (diff[i] == diff[i - 1]) {
      cnt++;
    } else {
      cnt = 1;
    }
    ans = max(ans, cnt);
  }

  return ans + 1;
}

// * Use the diff as variable
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int optimal(vector<ll> nums) {
  int n = nums.size();
  int diff = nums[1] - nums[0];
  int cnt = 0, ans = 1;
  for (int i = 1; i < n; ++i) {
    // cout << diff << endl;
    if (diff == (nums[i] - nums[i - 1])) {
      cnt++;
    } else {
      diff = (nums[i] - nums[i - 1]);
      cnt = 1;
    }
    ans = max(ans, cnt);
  }

  return ans + 1;
}

int main(void) {
  // * testcase 1
  // vector<ll> nums = {10, 7, 4, 6, 8, 10, 11};

  // * testcase 2
  // vector<ll> nums = {9, 7, 5, 3};

  // * testcase 3
  // vector<ll> nums = {5, 5, 4, 5, 5, 5, 4, 5, 6};

  // * testcase 4
  vector<ll> nums = {5, 4, 3, 2, 1, 2, 3, 4, 5, 6};

  cout << "nums: ";
  printArr(nums);

  // int ans = bruteForce(nums);
  int ans = optimal(nums);

  cout << "Maximum length of a contiguous consistent activity streak: " << ans << endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 08-max-len-of-a-contiguous-consistent-activity-streak-atlassian-oa-1.cpp -o output && ./output
