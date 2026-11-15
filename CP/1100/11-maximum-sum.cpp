/*
 * Maximum Sum
 * 
 * Description  : You are given an array of n distinct integers and must perform 
 *                exactly k operations on it. During each operation, you choose 
 *                one of two actions:
 *                1. Find the two minimum elements in the array and delete them.
 *                2. Find the maximum element in the array and delete it.
 *                Calculate the maximum possible sum of the elements remaining in the 
 *                array after completing all k operations.
 * 
 * Constraints  : 1 <= t <= 10^4 (number of test cases)
 *                3 <= n <= 2 * 10^5
 *                1 <= k <= 99,999 (with 2k < n)
 *                1 <= a_i <= 10^9
 *                The sum of n over all test cases does not exceed 2 * 10^5.
 * 
 * Example 1    :
 * Input        : n = 5, k = 1
 *                array = [2, 5, 1, 10, 6]
 * Output       : 21
 * Explanation  : Sorting the array gives [1, 2, 5, 6, 10]. We have two options for k = 1:
 *                - Remove two minimum elements (1 and 2): remaining array is [5, 6, 10], sum = 21.
 *                - Remove one maximum element (10): remaining array is [1, 2, 5, 6], sum = 14.
 *                The maximum possible sum is 21.
 * 
 * https://codeforces.com/problemset/problem/1832/B
*/

// ! Observation
// ! Greedy fails here
/*
* a = [a1, a2, a3, a4, a5]
* 
* if (a1 + a2 > a5) {
*   remove [a5]
* } else {
*   remove [a1, a2]
* }
*
* But this above greedy approach will fail
* So we need to find some other solution.
*
*
* Iterate through the number of times you remove the minimums, from m = 0 to k. 
* For each m, the elements removed are the 2m smallest and k−m largest from the initially sorted array, 
* which can be computed using prefix sums. The maximum sum over all choices of m is your answer.
* 
* if k = 2 then following are operations
* (0, 2), (1, 1), (2, 0) 
* 
*/


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

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

// * Time Complexity (TC): O(NlogN)
// * Space Complexity (SC): O(N)
void solve() {
  ll n, k;
  cin >> n >> k;

  ll s = 0;
  VEC(a, n, ll); READ_VEC(a);
  sort(all(a));
  // printArr(a);
  
  // * Calculate Prefix Array
  VEC(p, n, ll);
  p[0] = a[0];
  for (size_t i = 1; i < n; ++i) {
    p[i] = p[i - 1] + a[i];
  }
  // printArr(p);
  
  ll max_sum = 0;
  for (size_t first = 0; first <= k; ++first) {
		ll second = k - first;  // * Calculate the number of second operations
		ll left = 2 * first;  // * Calculate the number of elements removed by first operations
		ll right = n - second - 1;  // * Calculate the index of the last element not removed by second operations
    // cout << l << " " << r << '\n';
    max_sum = max(max_sum, p[right] - p[left] + a[left]);
  }
  
  cout << max_sum << '\n';
}

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
// * g++ --std=c++20 11-maximum-sum.cpp -o output && ./output

// * testcases
/*
6
5 1
2 5 1 10 6
5 2
2 5 1 10 6
3 1
1 2 3
6 1
15 22 12 10 13 11
6 2
15 22 12 10 13 11
5 1
999999996 999999999 999999997 999999998 999999995
*/

// * Output
/*
21
11
3
62
46
3999999986
*/