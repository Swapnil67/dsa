/*
* Toggle K-th Bit
*
* https://www.naukri.com/code360/problems/toggle-k-bits_973006
*/

#include <iostream>

using namespace std;

// * TIME COMPLEXITY O(1)
// * SPACE COMPLEXITY O(1)
int toggleKthBit(int n, int k) {
  // * Shift n right by k bits & Do xor
  return (n ^ (1 << k));
}

// * Toggle k-range bits
// * n = 12 (1100), k = 2 => ans = (1111) => 15
int toggleKBits(int n, int k) {
  int val = 0;
  while (k--) {
    val |= (1 << k);
  }
  return (n ^ val);
}

int main(void) {
  cout << "is bit set: " << toggleKthBit(4, 0) << '\n'; // * 0101
  cout << "is bit set: " << toggleKthBit(4, 1) << '\n'; // * 0110
  cout << "is bit set: " << toggleKthBit(4, 2) << '\n'; // * 0000

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 toggle-kth-bit.cpp -o output && ./output

