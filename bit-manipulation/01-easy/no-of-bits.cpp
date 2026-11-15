/*
* 191. Number of 1 Bits
*
* https://leetcode.com/problems/number-of-1-bits/description/
*/

#include <iostream>

using namespace std;

// * TIME COMPLEXITY O(32) for 32-bit integer
// * SPACE COMPLEXITY O(1)
int hammingWeight(int n) {
  int bits = 0;
  while (n > 0) {
    bits += (n & 1);
    n >>= 1;
  }

  // * Alternative implementation using GCC built-in
  // bits = __builtin_popcount(n);

  return bits;
}

int main(void) {
  cout << "set bits: " << hammingWeight(13) << '\n';
  cout << "set bits: " << hammingWeight(12) << '\n';
  cout << "set bits: " << hammingWeight(64) << '\n';
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 no-of-bits.cpp -o output && ./output

