/*
* Set kth bit
*
* https://www.geeksforgeeks.org/problems/set-kth-bit3724/1
* https://www.naukri.com/code360/problems/set-k-bits_972999
*/

#include <iostream>

using namespace std;

// * TIME COMPLEXITY O(1)
// * SPACE COMPLEXITY O(1)
int setKthBit(int n, int k) {
  return n | (1 << k);
}

int main(void) {
  cout << "set bits: " << setKthBit(10, 2) << '\n';
  cout << "set bits: " << setKthBit(212, 0) << '\n';
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 set-kth-bit.cpp -o output && ./output

