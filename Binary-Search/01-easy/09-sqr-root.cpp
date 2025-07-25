/*
 * Leetcode - 69
 * Square Root of a number
 * You are given a positive integer ‘n’.
 * Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).
 
 * Example 1:
 * Input: number = 7
 * Output: 2

 * Example 2:
 * Input: number = 100
 * Output: 10

 * https://leetcode.com/problems/sqrtx/description/
 * https://www.naukri.com/code360/problems/square-root-integral_893351
*/

#include <vector>
#include <iostream>

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Linear search
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int bruteForce(int n) {
  int sqrRoot = 1;
  for (int i = 0; i <= n; i++) {
    int val = i * i;
    if (val <= n) {
      sqrRoot = i;
    }
    else {
      break;
    }
  }
  return sqrRoot;
}


// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Binary Search on answers
// * TIME COMPLEXITY O(logN)
// * SPACE COMPLEXITY O(1)
int findSquareRoot(int n) {
  if(n == 0) return 0;
  if(n < 0) return 0;
  int l = 1, r = n;
  while(l <= r) {
    long long m = l + (r - l) / 2;
    long long val = m * m;
    if(val <= (long long)n) {
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  return r;
}

int main() {
  std::cout << "Square root of 1 is " << findSquareRoot(1) << std::endl;
  std::cout << "Square root of 2 is " << findSquareRoot(2) << std::endl;
  std::cout << "Square root of 4 is " << findSquareRoot(4) << std::endl;
  std::cout << "Square root of 8 is " << findSquareRoot(8) << std::endl;
  std::cout << "Square root of 28 is " << findSquareRoot(28) << std::endl;
  std::cout << "Square root of 25 is " << findSquareRoot(25) << std::endl;
  std::cout << "Square root of 100 is " << findSquareRoot(100) << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 09-sqr-root.cpp -o 06-sqr-root && ./06-sqr-root