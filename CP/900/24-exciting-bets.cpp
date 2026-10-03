/*
 * Exciting Bets (Codeforces 1543A)
 * 
 * Description  : You are given two integers a and b. In one move, you can either 
 *                increase both a and b by 1, or decrease both a and b by 1 (this 
 *                is only allowed if both a and b are greater than 0). You can 
 *                perform this operation any number of times. Your task is to 
 *                find the maximum possible excitement—defined as gcd(a, b)—and 
 *                the minimum number of moves required to achieve it. If the 
 *                excitement can be infinitely large, output 0 0.
 * 
 * Constraints  : 
 *                - 1 <= t <= 10^4 (Number of test cases)
 *                - 0 <= a, b <= 10^18 (Initial bet amounts)
 * 
 * Example 1    :
 * Input        : a = 8, b = 5
 * Output       : 3 1
 * Explanation  : By decreasing both numbers by 1, we get a = 7 and b = 4, with 
 *                gcd(7, 4) = 1. By increasing both numbers by 1, we get a = 9 
 *                and b = 6, with gcd(9, 6) = 3. This is the maximum possible 
 *                excitement, achieved in exactly 1 move.
 * 
 * Example 2    :
 * Input        : a = 1, b = 1
 * Output       : 0 0
 * Explanation  : Since a and b are already equal, we can increase them indefinitely 
 *                to get an infinitely large GCD (e.g., gcd(x, x) = x). Thus, 
 *                the maximum excitement is infinite.
 *
 * https://codeforces.com/problemset/problem/1543/A
*/

// ! GCD

// ! Observation
/*
* gcd(a, b) = gcd(a - b, b)         where (a > b)
*
* the max gcd we can have is 'a - b'
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// * GCD on difference
// * TC = O(1)
// * SC = O(1)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;

    // * Ensure a is the larger number for simplicity
    if (b > a)
      swap(a, b);
    
    if (a == b) {
      cout << "0 0\n";
    } else {
      // Calculate the difference, which is the gcd when a != b
			ll gcd = a - b;
			
			// Calculate the minimum number of moves to achieve maximum excitement
			// Either increase or decrease to the nearest multiple of gcd
			long long moves = min(b % gcd, gcd - b % gcd);

			// Output the maximum excitement and the minimum moves required
			cout << gcd << " " << moves << endl;
    }
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 24-exciting-bets.cpp -o output && ./output

// * testcases
/*
4
8 5
1 2
4 4
3 9

*/

// * Output
/*
3 1
1 0
0 0
6 3
*/
