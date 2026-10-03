/*
 * Permutation Swap
 * 
 * Description:
 * You are given an unsorted permutation p of length n, containing distinct 
 * integers from 1 to n. 
 * 
 * To sort the permutation in increasing order, you choose a fixed constant 
 * k (k >= 1) and perform swap operations. In one operation, you can choose 
 * two indices i and j (1 <= j < i <= n) such that i - j = k, and swap 
 * the elements p[i] and p[j].
 * 
 * Find the maximum possible value of k that allows you to sort the 
 * permutation using this operation any number of times.
 * 
 * Constraints:
 * 2 <= n <= 10^5
 * p is a permutation of length n containing distinct integers from 1 to n.
 * The given permutation p is guaranteed to be unsorted.
 * 
 * Example 1    :
 * Input        : p = [3, 1, 2]
 * Output       : 1
 * Explanation  : With k = 1, we can swap p[1] and p[2] to get [1, 3, 2], and then swap p[2] and p[3] to get [1, 2, 3]. 
 *                No value of k > 1 can sort it.
 * 
 * Example 2    :
 * Input        : p = [2, 4, 1, 3]
 * Output       : 1
 * Explanation  : The maximum distance step that allows all elements to reach their sorted positions is 1.
 * 
 * https://codeforces.com/problemset/problem/1828/B
*/

// ! Math, GCD

// ! Observation
// * To move a[i] to its correct position,
// * |a[i] - i| % k == 0 (i.e |a[i] - i| should be a multiple of k)

/*
* p       = 1 2  3 4 5 6 7 8 9 10 11
* a       = 1 11 6 4 8 3 7 5 9 10 2
* |p - a| = 0 9  3 0 3 3 0 3 0 0  9

* So if we see carefully some needs k = 9 swaps while some need k = 3 swaps 
* but we cannot take k = 9 swaps becoz if we do that we won't be able to sort no. which need k = 3 swaps
* but we can do k = 9 swaps in multiple of 3 [3 swaps, 3 times].

* So our ans = GCD(|p1 - a[1]|, |p2 - a[2]|, |p3 - a[3]|,.....,|pn - a[n]|)
* Awesome right!
*/

#include <vector>
#include <iostream>
#include <numeric>

using namespace std;
typedef long long ll;

// * GCD of index gaps
// * TC = O(n*logn)
// * SC = O(1)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    
    ll k = abs(a[1] - 1);
    for (int i = 2; i <= n; ++i) {
      k = gcd(k, abs(i - a[i])); // * O(logn)
    }

    cout << k << "\n";
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 09-permutation-swap.cpp -o output && ./output

// * testcases
/*
7
3
3 1 2
4
3 4 1 2
7
4 2 6 7 5 3 1
9
1 6 7 4 9 2 3 8 5
6
1 5 3 4 2 6
10
3 10 5 2 9 6 7 8 1 4
11
1 11 6 4 8 3 7 5 9 10 2

*/


// * Output
/*
1
2
3
4
3
2
3
*/