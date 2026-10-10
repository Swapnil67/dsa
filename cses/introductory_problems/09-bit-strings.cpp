/*
 * Bit Strings
 * 
 * https://cses.fi/problemset/task/1617
*/

#include <iostream>

using namespace std;
typedef long long ll;

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int main(void) {
  ll n;
  cin >> n;
  int MOD = 1e9 + 7;
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    ans = (ans * 2) % MOD;
  }
  cout << ans << "\n";
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 09-bit-strings.cpp -o output && ./output

/*
Input:
8

Output:
256
*/