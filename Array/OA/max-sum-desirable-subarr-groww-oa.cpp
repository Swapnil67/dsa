/*
 * Maximum Sum Desirable Subarray
 * 
 * You are given an integer array a of length n and a non-negative integer k.
 * 
 * A subarray of an array is a contiguous sequence of one or more elements. 
 * We represent a subarray by the pair of indices [l, r], where 0 <= l <= r < n. 
 * Both indices are inclusive and use 0-based indexing.
 * 
 * A subarray [l, r] is called a desirable subarray if the absolute difference between its first and last elements
 * is exactly k. In other words, it must satisfy:
 * |a[l] - a[r]| = k
 * 
 * The sum of a subarray [l, r] is defined as:
 * a[l] + a[l+1] + ... + a[r]
 * 
 * Your task is to find the maximum sum among all desirable subarrays.
 * 
 * If no desirable subarray exists, report that no valid subarray exists.
 * 
 * 
 * Constraints:
 * 
 * Example 1    :
 * Input        : nums = [10 20 30 40], k = 20
 * Output       : 90
 * Explanation  : The subarray is [20, 30, 40]. Its endpoint difference is |20 - 40| = 20, so it is desirable. 
 *                Its sum is 20 + 30 + 40 = 90.
 * 
 * Example 2    :
 * Input        : nums = [10 -10 -20 10 30], target = -2
 * Output       : 10
 * Explanation  : There are 10 pairs of indices that satisfy the conditions in the statement:
 *
 * https://leetcode.com/problems/maximum-good-subarray-sum/
 * https://leetcode.com/discuss/post/8582548/groww-dsa-round-question-by-anonymous_us-sz03/
*/

// ! OA
// ! Groww

#include <map>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

// * Macros
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

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

// * Nested For loops
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
ll bruteForce(vl nums, int k) {
  int n = nums.size();
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll sum = 0; 
    for (int j = i; j < n; ++j) {
      sum += nums[j];
      if (abs(nums[i] - nums[j]) == k) {
        ans = max(ans, sum);
      }
    }
  }
  return ans;
}

// ! Intuition
/*
* |a[i] - a[j]| = k
* Now if we remove the mod we'll get following 2 equations
* a[i] - a[j] = k           ------- 1
* a[j] - a[i] = k           ------- 2

* Now we can rewrite the above 2 equations in following way
* a[j] = a[i] - k
* a[j] = a[i] + k
* 
* So if we store these min prefix sum till a[i] we can get the max subarray.
*/

// * Hashmap + Prefix sum
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
ll maxDesirableSubarrSum(vl nums, int k) {
  int n = nums.size();

  map<ll, ll> mp; // * {ele, min_pref_sum}
  mp[0] = 0;
  ll ans = -1e18, pref_sum = 0;
  for (int i = 0; i < n; ++i) {
    int val = nums[i];

    ll cur_prefix_sum = pref_sum + val; // * running prefix sum
    // pref_sum = pref_sum + val; // * running prefix sum
    cout << cur_prefix_sum << ' ' << pref_sum << '\n';

    // * search for valid "i" on left 
    ll cur_sum = -1e18;
		// * ll sum2 = pref_sum - mp[val - k];
    if (mp.count(val + k)) {
      cur_sum = max(cur_sum, cur_prefix_sum - mp[val + k]);
    }
    // * ll sum1 = pref_sum - mp[val + k];
    if (mp.count(val - k)) {
      cur_sum = max(cur_sum, cur_prefix_sum - mp[val - k]);
    }
    ans = max(ans, cur_sum);

    // * Save the previous prefix sum to map
    if (mp.find(val) == mp.end()) {
      mp[val] = pref_sum;
    } else {
      // * we need to save the min prefix sum to get the maximum subarray sum till 'i'
      mp[val] = min(mp[val], pref_sum);
    }

    pref_sum += val; // * running prefix sum
    // cout << pref_sum << '\n';
  }

  // * For debug
  // for (auto it: mp) cout << it.first << ' ' << it.second << '\n';

  return ans;
}

int main(void) {
  // * testcase 1
  // int k = 20;
  // vl nums = {10, 20, 30, 40};

  // * testcase 2
  // int k = 20;
  // vl nums = {10, -10, -20, 10, 30};

  // * testcase 3 (Wrong answer on this debug) 
  int k = 0;
  vl nums = {-5, 10, -2};

  // * testcase 4
  // int k = 5;
  // vl nums = {1, 2, 3, 4};

  cout << "k: " << k << '\n';
  cout << "Input: ";
  printArr(nums);

  // ll ans = bruteForce(nums, k);
  ll ans = maxDesirableSubarrSum(nums, k);

  cout << ans << '\n';

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 max-sum-desirable-subarr-groww-oa.cpp -o output && ./output
