/*
 * 250 Thousand Tons of TNT
 * 
 * You are given an array `nums` of `n` integers representing the weights of `n` boxes in a row. 
 * You need to partition the boxes into equal-sized trucks. If you choose an integer `k` such 
 * that `k` divides `n`, you will allocate the first `k` boxes to the first truck, the next 
 * `k` boxes to the second truck, and so on (preserving their relative order).
 * 
 * Calculate the maximum possible absolute difference between the total weights of any two 
 * trucks across all valid values of `k` (1 <= k <= n). If only one truck is used, the 
 * difference is 0.
 * 
 * Constraints:
 * - 1 <= t <= 10^4 (Number of test cases)
 * - 1 <= n <= 150,000 (Length of the array)
 * - 1 <= nums[i] <= 10^9 (Weights of the boxes)
 * - The sum of `n` over all test cases does not exceed 150,000.
 * 
 * Example 1    :
 * Input        : nums = [1, 2, 3, 4, 5, 6]
 * Output       : 9
 * Explanation  : 
 * - If k = 1: Truck weights are [1, 2, 3, 4, 5, 6]. Max diff = 6 - 1 = 5.
 * - If k = 2: Truck weights are [(1+2), (3+4), (5+6)] = [3, 7, 11]. Max diff = 11 - 3 = 8.
 * - If k = 3: Truck weights are [(1+2+3), (4+5+6)] = [6, 15]. Max diff = 15 - 6 = 9.
 * - If k = 6: Only 1 truck with total weight 21. Max diff = 0.
 * The maximum absolute difference achieved is 9.
 * 
 * Example 2    :
 * Input        : nums = [10, 10, 10]
 * Output       : 0
 * Explanation  : Since k can only be 1 or 3, the trucks will always have equal total weights 
 *                (either all 10s or a single truck of 30). The max difference is 0.
 *
 * Link to similar problems on LeetCode:
 * - [LeetCode 413: Arithmetic Slices](https://leetcode.com "LeetCode 413") (Fixed subarray segment distribution)
 * - [LeetCode 1013: Partition Array Into Three Parts With Equal Sum](https://leetcode.com "LeetCode 1013") (Dividing arrays into contiguous chunks based on sum rules)
 * - [LeetCode 2256: Minimum Average Difference](https://leetcode.com "LeetCode 2256") (Using prefix sums to calculate segment comparisons efficiently)
 * 
 * https://codeforces.com/problemset/problem/1899/B
*/

// ! Observation

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

void solve() {
  ll n;
  cin >> n;
  VEC(a, n, ll); READ_VEC(a);
  
  // * Calculate Prefix Sum
  VEC(pre, n, ll);
  pre[0] = a[0];
  for (size_t i= 1; i < n; ++i) {
    pre[i] = pre[i - 1] + a[i];
  }
  
  ll ans = 0; // Variable to store the maximum absolute difference
  for (ll k = 1; k <= n; k++) { // Iterate over all possible k values
    if (n % k) // * If k does not divide n, skip this k
      continue; 
    
    ll start = k - 1; // Starting index for the first truck
    ll maxi = pre[start]; // Initialize maximum sum for the first truck
		ll mini = pre[start]; // Initialize minimum sum for the first truck
		
		for (ll idx = start + k; idx < n; idx += k) {
		  ll cur = pre[idx] - pre[idx - k]; // * Calculate current truck's weight
		  maxi = max(maxi, cur); // Update maximum weight
      mini = min(mini, cur); // Update minimum weight
		}  

		ans = max(ans, maxi - mini); // Update the maximum absolute difference
  }
  
  cout << ans << "\n";
} 

// * Time Complexity (TC): O(nlogn)
// * Space Complexity (SC): O(n)
int main() {
  // Optimize standard I/O operations for competitive programming
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
	return 0;
}


// * Run the code
// * g++ --std=c++20 05-250-thousand-tons-of-TNT.cpp -o output && ./output

// * testcases
/*
5
2
1 2
6
10 2 3 6 1 3
4
1000000000 1000000000 1000000000 1000000000
15
60978 82265 78961 56708 39846 31071 4913 4769 29092 91348 64119 72421 98405 222 14294
8
19957 69913 37531 96991 57838 21008 14207 19198
*/

// * Output
/*
1
9
0
189114
112141
*/