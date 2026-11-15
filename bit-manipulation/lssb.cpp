// * Least Significant set bit
#include <iostream>

using namespace std;

// * TIME COMPLEXITY O(32) for 32-bit integer
// * SPACE COMPLEXITY O(1)
int getLSSB(int n) {
  int bit = 1, bitCount = 0;
  while ((n & bit) == 0) {
    // cout << bit << '\n';
    bit <<= 1;
    bitCount++;
  }
  return bit; // * returns lssb value

  // * Alternative implementation using GCC built-in
  // int lssbIndex = __builtin_ctz(n); // * count trailing zeros
  // int lssbValue = 1 << lssbIndex;
  // return lssbValue;
}

int main(void) {
  cout << getLSSB(1) << '\n';
  cout << getLSSB(12) << '\n';
  cout << getLSSB(64) << '\n';
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 lssb.cpp -o output && ./output

