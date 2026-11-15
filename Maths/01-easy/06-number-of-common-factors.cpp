/*
 * Leetcode - 2427
 * Number of Common Factors
 * 
 * Description  : Given two positive integers a and b, return the number of 
 *                common factors of a and b. An integer x is a common factor 
 *                of a and b if x divides both a and b without leaving a remainder.
 * 
 * Constraints  : 1 <= a, b <= 1000
 * 
 * Example 1    :
 * Input        : a = 12, b = 6
 * Output       : 4
 * Explanation  : The common factors of 12 and 6 are 1, 2, 3, 6.
 * 
 * Example 2    :
 * Input        : a = 25, b = 30
 * Output       : 2
 * Explanation  : The common factors of 25 and 30 are 1, 5.
 *
 * https://leetcode.com/problems/number-of-common-factors/
*/

#include <iostream>

using namespace std;

// * Euclid's Algorithm
int findGCD(int a, int b) { // * O(logn)
  if (b == 0)
    return a;
  return findGCD(b, a % b);
}

// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
int commonFactors(int a, int b) {
  // * Find GCD using Euclid's Algorithm
  int gcd = findGCD(a, b);
  // cout << "gcd " << gcd << "\n";

  // * Count factors of GCD
  int ans = 0;
  for (int i = 1; i <= gcd; ++i) {
    if (gcd % i == 0)
      ans++;
  }

  return ans;
}

int main(void) {
  cout << "Number of Common Factors: " << commonFactors(12, 6) << "\n";
  cout << "Number of Common Factors: " << commonFactors(25, 30) << "\n";
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 06-number-of-common-factors.cpp -o output && ./output
