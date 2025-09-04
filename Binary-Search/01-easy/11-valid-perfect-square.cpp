/*
 * Leetcode - 367
 * Valid Perfect Square
 * 
 * Given a positive integer num, return true if num is a perfect square or false otherwise.
 * A perfect square is an integer that is the square of an integer. In other words,
 * it is the product of some integer with itself.
 * 
 * You must not use any built-in library function, such as sqrt.

 * 
 * Example 1 
 * Input     : num = 16
 * Output    : true

 * 
 * Example 2
 * Input     : num = 14
 * Output    : false
 * 
 * https://leetcode.com/problems/valid-perfect-square/
*/

#include <iostream>

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(logn)
// * SPACE COMPLEXITY O(1)
bool isPerfectSquare(int num) {
  int l = 1, r = num;
  while (l <= r) {
    long long m = l + (r - l) / 2;
    long long cur_sqr = m * m;
    if (cur_sqr == num) {
      return true;
    } else if (cur_sqr > num) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  return false;
}

int main(void) {
  std::cout << "Is Valid Perfect Square: " << isPerfectSquare(16) << std::endl;
  std::cout << "Is Valid Perfect Square: " << isPerfectSquare(14) << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 11-valid-perfect-square.cpp -o output && ./output