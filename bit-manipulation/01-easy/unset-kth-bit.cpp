/*
* Unset kth bit
*
* https://www.geeksforgeeks.org/problems/replace-the-bit3212/1
* https://www.geeksforgeeks.org/problems/replace-the-bit3212/1
*/

#include <iostream>

using namespace std;

string getBinaryString(int n) {
  string ans = "";
  while (n > 0) {
    ans = ((n & 1) ? '1' : '0') + ans;
    n >>= 1;
  }
  return ans;
}

// * Replace kth bit from the right
// * TIME COMPLEXITY O(1)
// * SPACE COMPLEXITY O(1)
int replaceBit(int n, int k) {
  return n & ~(1 << k);
}

// * Replace kth bit from the left
int replaceBit(int n, int k) {
    string bin_str = getBinaryString(n);
    int x = bin_str.length() - k;
    if (x < 0 || x >= 32) return n;
    return n & (~(1 << x));
}

int main(void) {
  cout << "unset bits: " << replaceBit(13, 2) << '\n';
  cout << "unset bits: " << replaceBit(13, 6) << '\n';
  cout << "unset bits: " << replaceBit(1, 1) << '\n';
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 unset-kth-bit.cpp -o output && ./output

