/*
 * Minimum LCM
 * 
 * You are given an integer n. Find two positive integers a and b 
 * such that a + b = n and the least common multiple (LCM) of a and b 
 * is minimized among all valid pairs. If there are multiple answers, 
 * any can be returned.
 * 
 * Constraints  : 1 <= t <= 100
 *                2 <= n <= 10^9
 * 
 * Example 1    :
 * Input        : n = 2
 * Output       : 1 1
 * Explanation  : 1 + 1 = 2, and LCM(1, 1) = 1, which is the minimum possible.
 * 
 * Example 2    :
 * Input        : n = 9
 * Output       : 3 6
 * Explanation  : 3 + 6 = 9, and LCM(3, 6) = 6. Any other split like (1, 8) yields LCM 8, (2, 7) yields 14, and (4, 5) yields 20.
 *
 * https://codeforces.com/problemset/problem/1765/M
*/

// ! Observation

/*
* n = 9
* (a b)        
* pairs      LCM
* (1, 8)      8  -------- (b % a = 0)
* (2, 7)      14
* (3, 6)      6  -------- (b % a = 0)
* (4, 5)      20
* ----------------------- symmetric
* (5, 4)      20
* (6, 3)      6
* (7, 2)      14
* (8, 1)      8

* If we observer the pairs we can see the symmetry after n/2
* We can make following observations
! #1. We only need to search in n/2 elements.
! #2. a <= b
! #3. b <= n - 1
! #4. b % a = 0 then LCM(a, b) = b
! #5. n % a = 0
* since b = n - a, 'a' should be the largest factor of 'n' to get minimum LCM
* the bigger the 'a' is smaller 'b' will be which is our LCM.
*/

#include <iostream>
using namespace std;

typedef long long ll;

pair<ll, ll> solve() {
  int n;
  cin >> n;

  ll ans_a = 1, ans_b = n - 1;
  
  // * Iterate over possible factors of n up to sqrt(n)
  for (int fac = 2; fac*fac <= n; ++fac) {
    
    // * Check if fac is a factor of n
    if (n % fac == 0) { // * (This is from #5)
			// * If fac is a factor, set ans_a to n / fac
      ans_a = n / fac;
      // * Set ans_b to n - ans_a (since we know this b = n - a)
			ans_b = n - ans_a;
			// * Break the loop as we found a valid pair
      break;
    }
  }
  
  return {ans_a, ans_b};
}

// * Time Complexity (TC): O(sqrt(10^9)) = O(10^4)
// * Space Complexity (SC): O(1)
int main() {
  ll t;
  cin >> t;
  while (t--) {
    pair<ll, ll> lcm = solve();
    cout << lcm.first << " " << lcm.second << "\n";
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 09-minimum-LCM.cpp -o output && ./output

// * testcases
/*
4
2
9
5
10

*/

// * Output
/*
1 1
3 6
1 4
5 5
*/