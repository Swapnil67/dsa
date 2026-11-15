/*
* E. Klee's SUPER DUPER LARGE Array!!!
*
* https://codeforces.com/problemset/problem/2009/E
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

/**
 * * INTUITION BEHIND THE VAL FUNCTION:
 * * Klee's array consists of consecutive integers: [k, k+1, k+2, ..., k+n-1].
 * * Since the difference between any two neighboring elements is always exactly 1, 
 * * this sequence forms a strict Arithmetic Progression (AP).
 * * 
 * * We can use the universal AP Sum formula: Sum = (Number of Terms * (First Term + Last Term)) / 2
 * * This allows us to calculate the sum of any chunk of the array in O(1) time without looping.
 */
pair<ll, ll> val(ll n, ll k, ll mid) {
  // * --- PART 1: SUM OF THE FIRST 'mid' ELEMENTS ---
  // * Number of terms = mid
  // * First term = k
  // * Last term = k + mid - 1 (since the 1st term adds 0, the 2nd adds 1, the mid-th adds mid-1)
  ll val1 = (k + (k + mid - 1)) * mid / 2;
  
  // * --- PART 2: TOTAL SUM OF THE ENTIRE ARRAY ---
  // * Number of terms = n
  // * First term = k
  // * Last term = k + n - 1
  ll total = (k + (k + n - 1)) * n / 2;
  
  // * --- PART 3: SUM OF THE REMAINING ELEMENTS ---
  // * Instead of recalculating a new AP, we simply subtract the first chunk from the total sum.
  ll val2 = total - val1;
  
  return {val1, val2};
}

void solve() {
  ll n, k;
  cin >> n >> k;
  
  // Binary search boundaries over the number of elements in the first part (from 1 to n)
  ll l = 1, r = n;
  ll idx = 1;  
  
  /**
   * * INTUITION BEHIND THE MONOTONIC PREDICATE:
   * * Let A be the left sum (val1) and B be the right sum (val2).
   * * - At mid = 1, A is small and B is large -> (B > A) is TRUE.
   * * - At mid = n, A holds everything and B is 0 -> (B > A) is FALSE.
   * * 
   * * As mid increases, A strictly increases and B strictly decreases. The property (B > A)
   * * is monotonic: it starts as all TRUEs and shifts to all FALSEs at some point.
   * * We want to find the LAST position where B is still greater than A.
   * * F F F F F F T T T T T     (MONOTONIC PREDICATE FUNCTION)
   * *           ^
   */
  while (l <= r) {
    ll m = l + (r - l) / 2;    
    
    auto [a, b] = val(n, k, m);
    
    if (b > a) {
      // If the right side is still heavier, our optimal balance point lies further to the right.
      // We record 'm' as a potential candidate and move our left pointer forward.
      idx = m;
      l = m + 1;
    } else {
      // If the left side has become heavier or equal (a >= b), we have overshot the balance point.
      // We look leftward to find the crossover boundary.
      r = m - 1;
    }
  }
  
  /**
   * INTUITION FOR THE FINAL BOUNDARY CHECK:
   * Our binary search found 'idx', which is the absolute last integer where B > A.
   * The very next integer, 'idx + 1', is guaranteed to be the first point where A >= B.
   * 
   * The absolute minimum difference must happen right at this crossover. We calculate the absolute 
   * difference for both neighboring integer split points and pick the smaller one.
   * Note: Since b1 > a1, (b1 - a1) is positive. Since a2 >= b2, (a2 - b2) is non-negative.
   */
  auto [a1, b1] = val(n, k, idx);
  auto [a2, b2] = val(n, k, idx + 1);
  
  cout << min((b1 - a1), (a2 - b2)) << '\n';
}

int main() {
  // Optimize standard I/O operations for competitive programming performance
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  ll t;
  cin >> t;
  while (t--)
    solve();
  
  return 0;
}


// * Run the code
// * g++ --std=c++20 klee-super-duper-large-arry.cpp -o output && ./output

// * Testcase
/*
3 3 3
1 2 3
1 2 1
1 3 2
2 3 4
1 2
1 3
2 3

*/

// * Output
/*
9 18 17
*/