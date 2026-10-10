/*
 * Trailing Zeros
 * 
 * https://cses.fi/problemset/task/1618
*/

#include <iostream>

using namespace std;
typedef long long ll;


/*
* LEMA PROOF: TRAILING ZEROS IN N!
* ===================================
* A trailing zero is created by a factor of 10 (2 * 5).
* In N!, multiples of 2 occur every 2 numbers, while multiples of 5 
* occur every 5 numbers. Because 2s are abundant and 5s are scarce, 
* the number of 5s is the limiting factor (the bottleneck).
* 
* Legendre's Formula counts the total factors of 5 in N!:
* Z(N) = floor(N/5) + floor(N/25) + floor(N/125) + ... + floor(N/5^k)
* 
* - floor(N/5)   counts numbers with at least one factor of 5 (5, 10, 15...)
* - floor(N/25)  counts the extra, second factor of 5 in multiples of 25 (25, 50...)
* - floor(N/125) counts the third factor of 5 in multiples of 125, and so on.
* 
* EXAMPLE: Trailing zeros in 32!
* -----------------------------------
* 1. Single 5s: floor(32 / 5)   = 6  -> [5, 10, 15, 20, 25, 30]
* 2. Extra 5s:  floor(32 / 25)  = 1  -> [25 contributes its second '5']
* 3. Triple 5s: floor(32 / 125) = 0  -> (125 > 32, stop)
* 
* Total Trailing Zeros = 6 + 1 = 7
*/

// * Standard implementation of Legendre's Formula for Base 10
// * TIME COMPLEXITY O(logn)
// * SPACE COMPLEXITY O(1)
int main() {
  ll n;
  cin >> n;
  int zeros = 0;
  while (n >= 5) {
    zeros += (n / 5);
    n /= 5; // * Efficiently scales to N/25, N/125, etc.
  }
  cout << zeros << "\n";
  return 0;
}

// * Run the code
// * g++ --std=c++20 10-trailing-zeros.cpp -o output && ./output

/*
Input:
20

Output:
4              (factorial = 2432902008176640000)
*/