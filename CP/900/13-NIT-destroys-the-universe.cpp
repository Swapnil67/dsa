/*
 * NIT Destroys the Universe
 * 
 * You are given a 1-indexed array a of n non-negative integers. You can perform 
 * the following operation on the array any number of times: choose a subsegment 
 * from index l to r (where 1 <= l <= r <= n), calculate w = mex({a[l], a[l+1], 
 * ..., a[r]}), and replace all elements in this subsegment with w.
 * The mex (minimum excluded value) of a set is the smallest non-negative integer 
 * that does not belong to the set.
 * Your goal is to find the minimum number of operations required to make all 
 * elements in the array equal to 0.
 * 
 * Constraints:
 * 1 <= n <= 10^5
 * 0 <= a[i] <= 10^9
 * The sum of n over all test cases does not exceed 2 * 10^5
 * 
 * Example 1    :
 * Input        : nums = [0, 0, 0, 0]
 * Output       : 0
 * Explanation  : All elements are already 0, so no operations are needed.
 * 
 * Example 2    :
 * Input        : nums = [1, 2, 3, 0]
 * Output       : 1
 * Explanation  : Select the subsegment from index 1 to 3 ([1, 2, 3]). The mex of this subsegment is 0. Replacing these elements with 0 yields [0, 0, 0, 0] in exactly 1 operation.
 *
 * https://codeforces.com/problemset/problem/1696/B
*/

// ! Greedy

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// ! Observation

// * Then answer will be always 0, 1 or 2.

/*
* Case 1 - Array with no segments
* s = [0 0 0 0]
* Answer = 0


* Case 2 - Array with 1 segment
* s = [0 1 2 0]
* Answer = 1

* Case 3 - Array with segment >= 2
* s = [0 1 2 0 3 4 0 5 6 0]
* Answer = 2
* Here we'll choose segment from 1 to n and change it to some mex 'm'
* With 1 snap
* s = [m m m m m m m m m m]
* Again choose segment from 1 to n and change it to mex '0'
* With 1 snap
* s = [0 0 0 0 0 0 0 0 0 0]
* Here we need max 2 snaps for this case.
*
*/

// * TC = O(n)
// * SC = O(n) (Input array)
int main(void)
{
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;
    vector<ll> s(n);
    for (int i = 0; i < n; ++i) 
      cin >> s[i];

    // * Count the no. of segments for every [l...r] which is >= 0
    ll segments = 0;
    bool start = false;
    for (int i = 0; i < n; ++i) {
      if (s[i] != 0) {
        if (!start) {
          segments++;   // * Increase segment count
          start = true; // * start new segment
        }
      }
      else {
        start = false;
      }

      if (segments >= 2) // * Pruning
        break;
    }

    if (segments >= 2)
      cout << 2 << "\n";
    else
      cout << segments << "\n";
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 13-NIT-destroys-the-universe.cpp -o output && ./output

// * testcases
/*
4
4
0 0 0 0
5
0 1 2 3 4
10
0 2 3 0 1 2 0 3 4 0 
1
1000000000

*/

// * Output
/*
0
1
2
1
*/