/*
 * Weird Algorithm
 * 
 * https://cses.fi/problemset/task/1068
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int main(void) {
  ll n;
  cin >> n;
  cout << n << " ";
  while (n != 1) {
    if (n & 1) {
      n = n * 3 + 1;
    } else {
      n /= 2;
    }
    cout << n << " ";
  }
  cout << endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 01-weird-algorithm.cpp -o output && ./output
