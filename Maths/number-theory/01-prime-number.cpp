/*
 * Primarility Test
 * 
 * Check if given number is prime or not.
 * 
 * Example 1    :
 * Input        : n = 53
 * Output       : true
 * 
 * Example 2    :
 * Input        : n = 24
 * Output       : false
 * 
 * https://cp-algorithms.com/algebra/primality_tests.html
 * https://www.codechef.com/practice/course/logical-problems/DIFF800/problems/PRB01
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
bool bruteForce(ll n) {
  if (n == 1)
    return false;
  for (int i = 2; i < n; ++i) {
    if (n % i == 0)
      return false;
  }
  return true;
}

/*
* Definition:
* A prime number 'n' is a whole number greater than 1 that has exactly 
* two distinct positive divisors: 1 and itself. 
* 
* Formulaic Test for Primality:
* If 'n' is prime, then for ALL integer divisors 'd' where 1 < d ≤ sqrt(n):
*     n % d != 0  (The remainder is never zero)
* 
* Consequently, BOTH of the following statements must be FALSE for all 
* integers 'd' greater than 1:
* 1. d <= sqrt(n)    and 'd' is an integer divisor of 'n'
* 2. n/d <= sqrt(n)  and 'n/d' is an integer divisor of 'n'
* 
* Example:
* n = 17
* 
* 1. Boundary Calculation:
*    The largest integer less than or equal to sqrt(17) is 4 (since 4 * 4 = 16).
* 
* 2. Testing all possible values for 'd' from 2 up to 4:
*    - When d = 2: 17 % 2 = 1 (Not a divisor)
*    - When d = 3: 17 % 3 = 2 (Not a divisor)
*    - When d = 4: 17 % 4 = 1 (Not a divisor)
* 
* Conclusion:
* No integer 'd' satisfies the conditions to be a divisor in this range. 
* Therefore, 17 is a prime number.
*/

// * TIME COMPLEXITY O(sqrt(N))
// * SPACE COMPLEXITY O(1)
bool isPrime(ll n) {
  if (n == 1)
    return false;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main(void) {
  ll n = 24;
  // ll n = 7;
  // ll n = 53;

  // bool prime = bruteForce(n);
  bool prime = isPrime(n);
  cout << "Is " << n << " prime: " << prime << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 01-prime-number.cpp -o output && ./output
