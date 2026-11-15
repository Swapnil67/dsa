/*
 * Leetcode - 4089
 * Count Subarrays With Loose Bounds
 *
 * https://leetcode.com/problems/count-subarrays-with-loose-bounds/
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

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

// ! Intuition
/*
* 
* a = [1 4 3 7 2 3]
*
* a = [[1 4 3] 7 [2 3]]
* there are two valid sub arrays which follows [1, 4, 3] & [2 3]
* 
* Now we need to find all subarrays in our valid subarrays, so we'll use following formula
* Let valid subarray length = n
* Then All valid subarray = n * (n - 1) / 2
* We need to add all valid subarrays
*
* [1, 4, 3] => 3 * (3 + 1) / 2 => 6
* [2, 3]    => 2 * (2 + 1) / 2 => 3
*
* Answer = 6 + 3 = 9 subarrays
*
*/

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
ll countSubarrays(vector<int> &nums, int minK, int maxK) {
  int n = nums.size();
  ll ans = 0, cur = 0;
  for (int i = 0; i < n; ++i) {
    // * Valid Subarray
    if (nums[i] >= minK && nums[i] <= maxK) {
      cur++;
    }
    else {
      // * All the subarrays b/w from 1...cur
      // cout << cur << '\n';
      ans += (cur * (cur + 1LL) / 2LL);
      cur = 0;
    }
  }
  if (cur > 0) {
    ans += (cur * (cur + 1LL) / 2LL);
  }
  return ans;
}

int main(void) {
  // * testcase 1
  int minK = 1, maxK = 5;
  vector<int> nums = {1, 4, 3, 7, 2, 3};
  
  // * testcase 1
  // int minK = 1, maxK = 1;
  // vector<int> nums = {1, 1};

  cout << "minK: " << minK << ", maxK: " << maxK << '\n';
  cout << "nums: ";
  printArr(nums);

  ll ans = countSubarrays(nums, minK, maxK);
  cout << "Subarrays With Loose Bounds: " << ans << '\n';

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 02-count-subarrays-with-loose-bounds.cpp -o output && ./output
