/*
 * Different Divisors
 * 
 * Description  : Find the smallest positive integer 'a' such that 'a' has at least 4 divisors, 
 *                and the absolute difference between any two of its divisors is at least 'd'.
 * 
 * Constraints  :
 *                1 <= t <= 3000 (number of test cases)
 *                1 <= d <= 10000
 * 
 * Example 1    :
 * Input        : d = 1
 * Output       : 6
 * Explanation  : The divisors of 6 are [1, 2, 3, 6]. There are 4 divisors, and the minimum 
 *                difference between any two adjacent divisors is 1 (e.g., 2 - 1 = 1), which is >= d.
 * 
 * Example 2    :
 * Input        : d = 2
 * Output       : 15
 * Explanation  : The divisors of 15 are [1, 3, 5, 15]. There are 4 divisors, and the minimum 
 *                difference between any two adjacent divisors is 2 (e.g., 3 - 1 = 2), which is >= d.
 *
 * https://codeforces.com/problemset/problem/1474/B
*/


// ! Observation

/*
* If we've some number 'N' then the total divisors of N are?
* 
* Prime Numbers = p1, p2, p3, ...., pn
* N = p1^a1 * p2^a2 * p3^a3 * ...... * pn^an
*
* Total Divisors = (a1 + 1) + (a2 + 1) + (a3 + 1) + .... + (an + 1)
* 
* We need the following
* (a1 + 1) * (a2 + 1) * (a3 + 1) * (a4 + 1) = 4 (divisors)

* Case I
* (a1 + 1) * (a2 + 1) * (a3 + 1) * (a4 + 1) = 4 (divisors)
*     |         |           |         |
*     4         1           1         1     = 4
*
* a1 + 1 = 4
* a1 = 3
* Therefore if we have p^3 then that number will have definitely 4 divisors.
* Eg: 3^3 = 27 => [1, 3, 9, 27]
* Eg: 4^3 = 64 => [1, 4, 16, 64]
* 
* Now we need the difference b/w any pairs is >= d
* divisors = [p^0, p^1, p^2, p^3]
*
* p - 1 >= d
* p^2 - p^1 >= d   => p(p - 1) >= d
* p^3 - p^2 >= d   => p^2(p - 1) >= d
* 
* So we only need to find p - 1 >= d, therefore p >= d + 1
* we need to find smallest prime >= d + 1

* Case 2
* (a1 + 1) * (a2 + 1) * (a3 + 1) * (a4 + 1) = 4 (divisors)
*     |         |           |         |
*     2         2           1         1     = 4
*
* a1 + 1 = 2   &    a2 + 1 = 2
* a1 = 1       &    a2 = 1         
*
* Therefore if we have pq then that number will have definitely 4 divisors.
* Eg: 2*3 = 6 => [1, 2, 3, 6]
* Eg: 7*3 = 21 => [1, 3, 7, 21]
* 
* Now we need the difference b/w any pairs is >= d
* divisors = [1, p, q, pq]
*
* p - 1 >= d                       - (eq1)
* q - p >= d                       - (eq2)
* pq - q >= d  => q(p - 1) >= d     - (eq3)
* 
* So here eq1 & eq3 are same we need to check anyone out of then and eq2 we need to check extra.
*
* So we only need to find prime which are p >= d + 1 & q >= d + p
* we need to find smallest prime >= d + 1
*
*/

#include <vector>
#include <iostream>
 
using namespace std;
typedef long long ll;

// * Total complexity for generating primes: O(10^5 * 10^2) = O(10^7)
vector<ll> generatePrimes() {
  // * Vector to store prime numbers
  vector<ll> primes;
  // * Generate prime numbers up to 100,000
  for (ll i = 2; i <= 100000; i++) // * O(10^5)
  {
    bool is_prime = true;
    // * Check if 'i' is a prime number
    for (ll j = 2; j * j <= i; j++) // * O(sqrt(10^5)) = O(10^2)
    {
      if (i % j == 0) {
        is_prime = false;
        break;
      }
    }
    // * If 'i' is prime, add it to the list of primes
    if (is_prime)
      primes.push_back(i);
  }
  return primes;
}

// ! Prime Gap
// * Time Complexity (TC): O(10^7) + O(3000 * 9000) = O(10^7) + O(3 * 10^7) = O(10^7)
// * Space Complexity (SC): O(10^4)
int main() {
  // * Generate primes (Cache)
  vector<ll> primes = generatePrimes(); 

	int t;
	cin >> t;

  // * O(3000)
	while (t--) {
		ll d;
		cin >> d;

		ll p = -1;
		// * Find the smallest prime >= (1 + d)
    for (ll pr: primes) { // * O(9000)
			if (pr >= (1 + d)) {
				p = pr;
				break;
			}
		}
    
		ll q = -1;
		// * Find the smallest prime >= (p + d)
    for (ll pr: primes) { // * O(9000)
			if (pr >= (p + d)) {
				q = pr;
				break;
			}
		}

		// * Calculate the smallest number 'a' with at least 4 divisors
		ll a = min(1LL * p * p * p, 1LL * p * q);
		cout << a << endl;
	}
}
 
// * Run the code
// * g++ --std=c++20 23-different-divisors.cpp -o output && ./output

// * testcases
/*
2
1
2
*/

// * Output
/*
6
15
*/
