/*
 * Odd Divisor
 * 
 * Description:
 * Given an integer n, check if n has an odd divisor greater than one (i.e., if there is an odd number x > 1 such that n is divisible by x).
 * 
 * Constraints:
 * 2 <= n <= 10^14
 * 
 * Example 1    :
 * Input        : n = 6
 * Output       : YES
 * Explanation  : The number 6 has an odd divisor 3 (3 > 1 and 6 % 3 == 0).
 * 
 * Example 2    :
 * Input        : n = 4
 * Output       : NO
 * Explanation  : The divisors of 4 are 1, 2, and 4. None of them are odd and greater than 1.
 *
 * https://codeforces.com/problemset/problem/1475/A
*/

#include <iostream>
using namespace std;

// * Time Complexity (TC): O(log2(n)) = O(log2(10^14)) = O(50)
// * Space Complexity (SC): O(1)

int main()
{
	long long t;
	cin >> t; // Read the number of test cases
	while (t--)
	{
		long long n;
		cin >> n; // Read the integer n for the current test case

		// * Continuously divide n by 2 to remove all factors of 2
		while (n % 2 == 0)
			n /= 2;

		// * After removing all factors of 2, if n is greater than 1,
		// * it means n has an odd divisor greater than 1
		if (n > 1)
			cout << "YES" << endl; // * Output YES if an odd divisor exists
		else
			cout << "NO" << endl; // * Output NO if no odd divisor exists
	}
	return 0;
}

// * Run the code
// * g++ --std=c++20 26-odd-divisor.cpp -o output && ./output

// * testcases
/*
6
2
3
4
5
998244353
1099511627776

*/

// * Output
/*
NO
YES
NO
YES
YES
NO
*/
