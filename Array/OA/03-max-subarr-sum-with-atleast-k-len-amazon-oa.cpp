/*
 * Max Subarray sum with atleast k length
 * 
 * 
 * Example 1    :
 * Input        : nums = [5, -5, 4, 3, 2], k = 4
 * Output       : 9
 * Explanation  : [5, -5, 4, 3, 2] => 9
 * 
 * Example 2    :
 * Input        : nums = [-10, -2, 3, 5, -10, 15, 4], k = 4
 * Output       : 17
 * Explanation  : [3, 5, -10, 15, 4] => 17
 * 
 * https://ideone.com/Lny2Xp
 * https://docs.google.com/document/d/1NglShQ-xdblsT51FhU8It15WifvZcaUjhItdTirTb9A/
*/

// ! OA
// ! Amazon

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

/*
! Intuition
* p = max subarray sum ending at index 'i'
* sum = sum of subarray sum with length 'k'
* p[i - k] = max subarray sum at index 'i-k'
* 
*
*                        P[i-k]               i
*                           |                 |
* num = [............................................]
*                            <------ sum ----->
*
* possible ans = max(sum, sum + p[i - k]) do this for every index 'i' 
* we'll get max subarray sum with atleast size 'k'
*/


// ! Kadanes Algo Variation
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
ll maxSubArray(vector<ll> nums, int k) {
  int n = nums.size();

  // * p[i] => max subarray ending at index 'i'
  vector<ll> p(n, 0);
  p[0] = nums[0];
  for (int i = 1; i < n; ++i) {
    p[i] = max(nums[i], nums[i] + p[i - 1]);
  }
  // printArr(p);

  ll sum = 0; // * sum of len 'k' (sliding window)
  for (int i = 0; i <= k - 2; ++i) {
    sum += nums[i];
  }

  ll ans = 0;
  for (int i = k - 1; i < n; ++i) { // * For SW we started from k - 1, so we can add nums[i] to sum
    sum += nums[i]; 
    // cout << "Sum: " << sum << endl;
    ll p1 = 0;
    if (i - k >= 0) {
      // cout << sum << " " << p[i - k] << endl;
      p1 = max(sum, sum + p[i - k]);
    } else {
      p1 = max(sum, p1);
    }
    ans = max(ans, p1);

    sum -= p[i - k + 1]; // * since this sum is fixed k-sized
  }

  return ans; 
}

int main(void) {
	// * testcase 1
  int k = 4;
  vector<ll> nums = {5, -5, 4, 3, 2};
  
  // * testcase 2
  // int k = 4;
  // vector<ll> nums = {-10, -2, 3, 5, -10, 15, 4};
  
  cout << "Input Array: ";
	printArr(nums);

	ll ans = maxSubArray(nums, k);

	cout << "Max Subarray sum with atleast k len: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 03-max-subarr-sum-with-atleast-k-len-amazon-oa.cpp -o output && ./output
