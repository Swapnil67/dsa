/*
 * Mainak and Array
 * 
 * Description:
 * You are given an array a of n positive integers. You can perform the following 
 * operation exactly once: choose any subsegment [l, r] (where 1 <= l <= r <= n) 
 * and cyclically rotate it by any amount. 
 * Formally, a single cyclic rotation shift moves the elements such that the 
 * element at index l moves to l+1, l+1 to l+2, ..., and the element at index r 
 * moves to l. This rotation can be repeated any number of times.
 * Your goal is to maximize the value of (a[n] - a[1]) after performing this 
 * operation exactly once.
 * 
 * Constraints:
 * 1 <= n <= 2000
 * 1 <= a[i] <= 999
 * The sum of n over all test cases does not exceed 2000
 * 
 * Example 1    :
 * Input        : nums = [1, 3, 9, 11, 5, 7]
 * Output       : 10
 * Explanation  : You can choose the subsegment from index 2 to 6 ([3, 9, 11, 5, 7]) and cyclically rotate it to the left by 2 positions. This transforms the subsegment into [11, 5, 7, 3, 9], making the full array [1, 11, 5, 7, 3, 9]. The value of a[n] - a[1] becomes 9 - 1 = 8. Alternatively, rotating the subsegment from index 2 to 4 ([3, 9, 11]) by 1 position transforms it into [11, 3, 9], resulting in the array [1, 11, 3, 9, 5, 7] where a[n] - a[1] = 7 - 1 = 6. The maximum possible value achievable through any valid subsegment rotation is 10.
 * 
 * Example 2    :
 * Input        : nums = [9, 99, 999]
 * Output       : 990
 * Explanation  : You do not need to change the array since the maximum difference is already achieved between the last and first element: 999 - 9 = 990.
 *
 * https://codeforces.com/problemset/problem/1726/A
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// ! Observation
/*
* a = [a1, a2, a3, a4, a5]
* 
* Case 1: lock a1
*     lock ______________
* a = [a1, a2, a3, a4, a5]
*
* a5 - a1
* a4 - a1 - (k = 1 i.e rotate 1) 
* a3 - a1 - (k = 2 i.e rotate 2) 
* a2 - a1 - (k = 3 i.e rotate 3) 

* Case 2: lock a5
*     ______________   lock
* a = [a1, a2, a3, a4, a5]
*
* a5 - a1
* a5 - a4 - (k = 1 i.e rotate 1) 
* a5 - a3 - (k = 2 i.e rotate 2)
* a5 - a2 - (k = 3 i.e rotate 3)

* Case 3: a5 to a1
*      ___________________
* a = [a1, a2, a3, a4, a5]
*
* a5 - a1 - (k = 0 i.e rotate 0)
* a4 - a5 - (k = 1 i.e rotate 1) 
* a3 - a4 - (k = 2 i.e rotate 2)
* a2 - a3 - (k = 3 i.e rotate 3)
* a1 - a2 - (k = 3 i.e rotate 3)
* 
*/

// ! Greedy on rotations
// * TC = O(n)
// * SC = O(n) (Input array)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    ll ans = a[n - 1] - a[0];

    // * case 1 - lock a[0] and rotate from 1 to n - 1
    for (int i = 1; i < n; ++i) {
      ans = max(ans, a[i] - a[0]);
    }

    // * case 2 - lock a[n] and rotate from 0 to n - 1
    for (int i = 0; i < n - 1; ++i) {
      ans = max(ans, (a[n - 1] - a[i]));
    }

    // * case 3 - all adj diff a[i] - a[i + 1]
    for (int i = 0; i < n - 1; ++i) {
      ans = max(ans, (a[i] - a[i + 1]));
    }

    cout << ans << "\n";
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 12-mainak-and-array.cpp -o output && ./output

// * testcases
/*
5
6
1 3 9 11 5 7
1
20
3
9 99 999
4
2 1 8 1
3
2 1 5

*/

// * Output
/*
10
0
990
7
4
*/