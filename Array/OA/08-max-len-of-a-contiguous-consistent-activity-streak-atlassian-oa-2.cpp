/*
 * Maximum length of a contiguous consistent activity streak - II
 * 
 * Building on the previous activity-streak problem, suppose Atlassian now allows you to modify at most one 
 * day's activity value in the data. 
 * 
 * You are given the same array representing activity recorded on consecutive days. 
 * You may replace at most one element of the array with any integer you choose, including a negative integer.
 * 
 * A consistent activity streak is a contiguous sequence of days where the change in activity between every 
 * pair of consecutive days remains the same.
 * 
 * Your task is to determine the maximum possible length of a contiguous consistent activity streak 
 * that can be obtained after replacing at most one element in the original array.
 * 
 * You may choose not to modify the array if the existing data already contains the optimal streak.
 * 
 * Example 1    :
 * Input        : nums = [10 7 4 6 8 10 11]
 * Output       : 5
 * Explanation  : Change element at index 2 to 2 ['2' 4 6 8 10] longest subarray with AP = 2
 * 
 * Example 2    :
 * Input        : nums = [5 5 4 5 5 5 4 5 6]
 * Output       : 6
 * Explanation  : change element at index 3 [5 5 '5' 5 5 5] longest subarray with AP = 0
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

int optimal(vector<ll> nums) {
  int n = nums.size();

  vector<int> diff(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    diff[i] = nums[i + 1] - nums[i];
  }
  printArr(diff);

  vector<int> p(n - 1, 0);
  for (int i = 0; i < n - 1; ++i) {
    if (i == 0) {
      p[i] = 1;
    } else {
      if (diff[i] == diff[i - 1]) {
        p[i] = p[i - 1] + 1;
      } else {
        p[i] = 1;
      }
    }
  }
  printArr(p);

  vector<int> s(n - 1, 1);
  for (int i = n - 2; i >= 0; --i) {
    if (i == n - 2) {
      s[i] = 1;
    } else {
      if (diff[i] == diff[i + 1]) {
        s[i] = s[i + 1] + 1;
      } else {
        s[i] = 1;
      }
    }
  }
  printArr(s);

  return 0;
}

int main(void) {
  // * testcase 1
  // vector<ll> nums = {10, 7, 4, 6, 8, 10, 11};

  vector<ll> nums = {2, 2, 2, 3, 3, 3, 3, 4, 5};

  // * testcase 2
  // vector<ll> nums = {5, 4, 3, 2, 1, 2, 3, 4, 5, 6};

  cout << "Nums: ";
  printArr(nums);

  int ans = optimal(nums);

  cout << "Maximum length of a contiguous consistent activity streak: " << ans << endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 08-max-len-of-a-contiguous-consistent-activity-streak-atlassian-oa-2.cpp -o output && ./output
