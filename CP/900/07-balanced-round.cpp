/*
 * NAME         : 1850D - Balanced Round
 * 
 * Description  : You are given an array `a` of `n` integers representing the difficulties of some problems. 
 *                You want to create a "balanced" round using a subset of these problems. You can remove any 
 *                number of problems (possibly zero) and rearrange the remaining ones in any order. 
 *                A round is considered balanced if the absolute difference between the difficulty of any two 
 *                consecutive problems in the final arrangement is at most `k`.
 *                Return the minimum number of problems you need to remove to make the remaining sequence balanced.
 * 
 * Constraints  : 1 <= t <= 10^4 (Number of test cases)
 *                1 <= n <= 2 * 10^5 (Sum of n over all test cases <= 2 * 10^5)
 *                1 <= k <= 10^9
 *                1 <= a_i <= 10^9
 * 
 * Example 1    :
 * Input        : n = 5, k = 1, a = [1, 2, 4, 5, 6]
 * Output       : 2
 * Explanation  : We can remove problem with difficulty 1, 2 so the remaining [4,5,6] is balanced.
 * 
 * Example 2    :
 * Input        : n = 5, k = 1, a = [2, 1, 4, 5, 3]
 * Output       : 0
 * Explanation  : We can rearrange all 5 problems as [1, 2, 3, 4, 5]. The absolute differences between 
 *                consecutive pairs are all 1, which is <= k (1). Thus, 0 problems need to be removed.
 * 
 * Example 2    :
 * Input        : n = 4, k = 2, a = [1, 5, 3, 10]
 * Output       : 1
 * Explanation  : If we sort the array, we get [1, 3, 5, 10]. The differences are: 
 *                |3-1|=2 (<=2), |5-3|=2 (<=2), but |10-5|=5 (>2). 
 *                By removing the problem with difficulty 10, the remaining [1, 3, 5] is balanced. 
 *                So the minimum number of removals is 1.
 * 
 * https://codeforces.com/problemset/problem/1850/D
*/

#include <vector>
#include <iostream>
#include <algorithm>

// ! Observation
// * We'll count the length of longest balanced subarray and subtract it from the total length.
/*
* n = 5, k = 1, a = [1, 2, 4, 5, 6]
* 
* Here the longest balanced subarray is [4,5,6], balanced = 3
* 
* Answer = n - balanced = 5 - 3 = 2
*
* So we need to remove 2 elements from array to make the array balanced.
*/


using namespace std;
typedef long long ll;

// * Count and Reset pattern
// * TC = O(nlogn)
// * SC = O(1)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(begin(a), end(a));

    ll cnt = 1LL, balanced = 1LL;
    for (int i = 1; i < n; ++i) {
      if ((a[i] - a[i - 1]) <= k) {
        cnt++;
      }
      else {
        cnt = 1;
      }
      balanced = max(balanced, cnt);
    }

    cout << n - balanced << "\n";
  }

  return 0;
}


// * Run the code
// * g++ --std=c++20 07-balanced-round.cpp -o output && ./output

// * testcases
/*
7
5 1
1 2 4 5 6
1 2
10
8 3
17 3 1 20 12 5 17 12
4 2
2 4 6 8
5 3
2 3 19 10 8
3 4
1 10 5
8 1
8 3 1 4 5 10 7 3

*/


// * Output
/*
2
0
5
0
3
1
4
*/