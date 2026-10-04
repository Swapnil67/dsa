/*
 * Check Armstrong
 * You are given an integer 'n'. Return 'true' if 'n' is an Armstrong number, and 'false' otherwise.
 * 
 * An Armstrong number is a number (with 'k' digits) such that the sum of its digits raised to 'kth' power
 * is equal to the number itself. For example, 371 is an Armstrong number because 3^3 + 7^3 + 1^3 = 371.
 * 
 * Example 1:
 * Input: n = 1634
 * Output: true
 * 
 * Example 2:
 * Input: n = 103
 * Output: false

 * https://www.naukri.com/code360/problems/check-armstrong_589
*/

#include<iostream>

// * TIME COMPLEXITY O(Log10(N))
// * SPACE COMPLEXITY O(1)
bool checkArmstrong(int n) {
  int t = n;
  int s = 0;

  // * count the digits
  int k = (int)std::log10(n) + 1;

  while(n > 0) {
    int i = 1;
    int last = n % 10;
    last = std::pow((long double)last, (long double)k);
    s += last;
    n = n / 10;
  }

  return t == s;
}

int main() {
  // int n = 103;
  // int n = 1634;
  int n = 371;
  std::cout << "Input Number: " << n << std::endl;
  bool ans = checkArmstrong(n);
  std::cout << "Is Armstrong: " << ans << std::endl;
  return 0;
}


// * run the code
// * g++ --std=c++17 03-armstrong.cpp -o output && ./output
