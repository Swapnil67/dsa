// * Most Significant set bit
#include <iostream>
#include <bit>

using namespace std;

// * TIME COMPLEXITY O(32) for 32-bit integer
// * SPACE COMPLEXITY O(1)
int getMSSB(int n) {
  int bit = 1, bitCount = 0;
  while (n >= bit) {
    // cout << bit << '\n';
    bit <<= 1;
    bitCount++;
  }
  bitCount -= 1;
  bit >>= 1; // * go to mssb
  return bit; // * returns mssb value

  // * Alternative implementation using GCC built-in
  // int mssbIndex = bit_width(static_cast<unsigned int>(n)) - 1;
  // int mssbValue = 1 << mssbIndex;
  // return mssbValue;
}

int main(void) {
  cout << "mssb value: " << getMSSB(1) << '\n';
  cout << "mssb value: " << getMSSB(12) << '\n';
  cout << "mssb value: " << getMSSB(64) << '\n';
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 mssb.cpp -o output && ./output

