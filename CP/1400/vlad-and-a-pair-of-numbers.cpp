/*
 * E. Vlad and a Pair of Numbers
 * 
 * https://codeforces.com/problemset/problem/1790/E 
*/

#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;

// ! Observation
/*
* We know the following identity of XOR and Addition
* A + B = (A ^ B) + 2 * (A & B)                       - (Eq1)
*
* Here we have given
* a ^ b = x                (Already provided value in input)  (Eq2)
* a ^ b = (a + b) / 2;     (Given formula)
* (a + b) = 2(a ^ b)
* (a + b) = 2x
* 
* Now from the Eq1
*
* a + b = (a ^ b) + 2 * (a & b) 
*
* 2x = x + 2(a & b)
* x = 2(a & b)
* (a & b) = x / 2;       (Eq3)  (This also proves 'x' cannot be odd)

*
* From Eq2 & Eq3 we have following information
* a ^ b = x
* a & b = x / 2 = y      -- (lets call this y)
* 
* So now we need to build a, b such that
* a ^ b = x
* a & b = y
*
* If not we return -1.
*
* x   y      a   b
* 0   0      0   0
* 0   1      1   1
* 1   0      1   0
* 1   1      Not Possible
*/

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << "\n";
}

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
