/*
 * United We Stand
 * 
 * Description:
 * Given an array a of n positive integers, partition all elements into two non-empty 
 * arrays b and c such that no element in c is a divisor of any element in b (i.e., for 
 * any bi in b and cj in c, bi % cj != 0). If such a partition is possible, return the 
 * lengths and elements of both arrays; otherwise, return -1.
 * 
 * Constraints:
 * - 1 <= t <= 500 (number of test cases).
 * - 2 <= n <= 100 (length of array a).
 * - 1 <= a[i] <= 10^9 (elements of array a).
 * 
 * Example 1    :
 * Input        : a = [2, 1, 3]
 * Output       : b = [1, 2], c = [3]
 * Explanation  : Neither 3 divides 1 nor 3 divides 2. Array b has length 2 and 
 *                array c has length 1, satisfying all conditions.
 * 
 * Example 2    :
 * Input        : a = [2, 2, 2]
 * Output       : -1
 * Explanation  : All elements are identical. Any partition into non-empty arrays 
 *                would place equal values into b and c, making an element in c divide 
 *                an element in b (2 % 2 == 0). Hence, no valid partition exists.
 *
 * https://codeforces.com/problemset/problem/1859/A
*/

// ! Number theory

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

// ! Observation

// * We want 
// * b = {x}
// * c = {y}
// * Such that x % y != 0
// * It is always possible if y > x

// * So we can say the following.
// * If I've more than 1 distinct element then the answer exists always.

// * c = {all max elements}
// * b = {everything besides max elements}

// * Put all the max elements in array 'c' and smaller in array 'b'
// * This how any element of 'c' will never divide any element of 'b'.
// * TC = O(n)
// * SC = O(n)
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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    ll mx = *max_element(begin(a), end(a));
    vector<ll> b, c;
    for (int i = 0; i < n; ++i) {
      if (a[i] != mx) {
        b.push_back(a[i]);
      } else {
        c.push_back(a[i]);
      }
    }

    if (b.size() == 0) { // * All elements are same
      cout << -1 << endl;
    } else {
      cout << b.size() << " " << c.size() << endl;
      for (auto it : b)
        cout << it << " ";
      cout << endl;

      for (auto it : c)
        cout << it << " ";
      cout << endl;
    }
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 13-united-we-stand.cpp -o output && ./output

// * testcase

/*
5
3
2 2 2
5
1 2 3 4 5
3
1 3 5
7
1 7 7 2 9 1 4
5
4 8 12 12 4

*/

// * output
/*
-1
3 2
1 3 5 
2 4 
1 2
1 
3 5 
2 5
1 1 
2 4 7 7 9 
3 2
4 8 4 
12 12 
*/

