/*
 * AvtoBus
 * 
 * Description:
 * You are given a positive integer n representing the total number of wheels 
 * on all buses in a fleet. The fleet consists of two types of buses:
 * - 2-axle buses, which have exactly 4 wheels.
 * - 3-axle buses, which have exactly 6 wheels.
 * Find the minimum and maximum possible number of buses that could be in 
 * the fleet. If no valid combination of 4-wheel and 6-wheel buses can result 
 * in exactly n wheels, return -1.
 * 
 * Constraints:
 * 1 <= n <= 10^18
 * The sum of n over all test cases does not exceed 10^18
 * 
 * Example 1    :
 * Input        : n = 24
 * Output       : 4 6
 * Explanation  : The minimum number of buses is 4 (all 4 buses have 6 wheels: 4 * 6 = 24). The maximum number of buses is 6 (all 6 buses have 4 wheels: 6 * 4 = 24).
 * 
 * Example 2    :
 * Input        : n = 7
 * Output       : -1
 * Explanation  : It is impossible to get a total of 7 wheels using combinations of 4-wheel and 6-wheel buses.
 *
 * https://codeforces.com/problemset/problem/1679/A
*/

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

// ! Observation

/*
 * We need 4 wheel buses and 6 wheel buses out of total n wheels given
 * 
 * 4a + 6b = n 
 * 2(2a + 3b) = n
 * 
 * 2a + 3b = n/2          - eq1
 * 
 * So the eq1 says two things the answer is integer and always even since its divided by '2'
 * So if n < 4 || n is odd then answer is never possible
 * 
 * Case A: 4 wheel
 *      1: (n % 4) = 0 
 *      2: (n % 4) = 1  (not possible since n cannot be odd)
 *      3: (n % 4) = 2  
 *      4: (n % 4) = 3  (not possible since n cannot be odd)
 *  
 * if n % 4 == 1 or 3 its better to ignore those extra tires since we cannot make any bus with them 
 * so here we always go for floor.
 * Eg: n = 9,  9 % 4 = floor(1.2) = 1, so here answer is 2 (since 9/4 = 2)
 * 
 * 
 * Case B: 6 wheel
 *      1: (n % 6) = 0 
 *      2: (n % 6) = 1  (not possible since n cannot be odd)
 *      3: (n % 6) = 2  
 *      4: (n % 6) = 3  (not possible since n cannot be odd)
 *      5: (n % 6) = 4  
 *      6: (n % 6) = 5  (not possible since n cannot be odd)
 *  
 * if n % 6 == 2 or 4 we'll always get a extra bus if we hence we do ceil.
 * Eg: n = 23,  22 % 6 = ceil(3.6) = 4, 3 buses of 6 wheels (18 wheels) and 1 bus of 4 wheel (4 wheels)
 * 
*/

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

    // * If n is odd or n < 4 answer not possible
    if (n & 1LL || n < 4LL) {
      cout << -1 << "\n";
      continue;
    }

    ll min_buses = ceil((n * 1.0) / 6); // * ceil
    ll max_buses = n / 4;               // * floor
    cout << min_buses << " " << max_buses << "\n";
  }

  return 0;
}


// * Run the code
// * g++ --std=c++20 14-avto-bus.cpp -o output && ./output

// * testcases
/*
5
4
7
24
998244353998244352
22
*/

// * Output
/*
1 1
-1
4 6
166374058999707392 249561088499561088
4 5
*/