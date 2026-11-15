/*
* Check K-th Bit
*
* https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1
* https://www.naukri.com/code360/problems/check-whether-k-th-bit-is-set-or-not_5026446
*/

#include <iostream>

using namespace std;

// * TIME COMPLEXITY O(1)
// * SPACE COMPLEXITY O(1)
bool checkKthBit(int n, int k) {
  // * Shift n left by k bits
  int check = (1 << k);
  return (n & check);
}

int main(void) {
  cout << "is bit set: " << checkKthBit(4, 0) << '\n';
  cout << "is bit set: " << checkKthBit(4, 1) << '\n';
  cout << "is bit set: " << checkKthBit(4, 2) << '\n';

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 check-kth-bit-set.cpp -o output && ./output

