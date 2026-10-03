/*
 * Mocha and Math (Codeforces 1559A)
 * 
 * Description  : You are given an array a of length n. You can perform the following 
 *                operation any number of times: choose an arbitrary interval [l, r] 
 *                and for each i from 0 to r - l, replace a[l + i] with a[l + i] & a[r - i] 
 *                simultaneously (where & denotes the bitwise AND operation). Your objective 
 *                is to minimize the maximum element of the array after any number of 
 *                operations.
 * 
 * Constraints  : 
 *                - 1 <= t <= 100 (Number of test cases)
 *                - 1 <= n <= 100 (Length of the array)
 *                - 0 <= a[i] <= 10^9 (Elements of the array)
 * 
 * Example 1    :
 * Input        : n = 2, a = [1, 2]
 * Output       : 0
 * Explanation  : Choose the interval [1, 2]. After the operation, the array becomes 
 *                [1 & 2, 2 & 1], which is [0, 0]. The maximum value is 0.
 * 
 * Example 2    :
 * Input        : n = 3, a = [5, 5, 5]
 * Output       : 5
 * Explanation  : No matter what intervals we choose, performing bitwise AND with the 
 *                same values will keep the elements at 5. The maximum value is 5.
 *
 * https://codeforces.com/problemset/problem/1559/A
*/

// ! Bit Manipulation

// ! Observation

/*
* The bitwise AND operation never increases a value. This means there's a "floor" or minimum possible value 
* that any element can become

* If we calcuate bitwise AND of all the numbers we'll get the minimum possible value.
* Since final number will have bits set to 1 at some position then all other number will have 1 bit set to that position.
*/

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

ll solve() {
  int n;
  cin >> n;
  
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  int ans = a[0];
  for (int i = 1; i < n; ++i) {
    ans &= a[i];
  }
  
  return ans;
}

// * TC = O(n)
// * SC = O(n) (Input Array)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 23-mocha-and-math.cpp -o output && ./output

// * testcases
/*
4
2
1 2
3
1 1 3
4
3 11 3 7
5
11 7 15 3 7

*/

// * Output
/*
0
1
3
3
*/
