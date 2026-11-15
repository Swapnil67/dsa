#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define PRINT_VEC(p) \
  for (auto &it : p) \
  cout << it << ' '; cout << '\n'
  
/*
 * Function: isFair
 * ----------------
 * Checks whether a given number `n` is a "fair" number.
 * A number is fair if all of its non-zero digits divide the number itself.
 * Returns:
 *     true if n is fair, false otherwise.
*/
bool divideByDigits(ll n) {
  ll copy_n = n;
  while (copy_n > 0) {
    ll digit = (copy_n % 10LL);
    if (digit != 0 && n % digit != 0) 
      return false;
    copy_n /= 10LL;
  }
  return true;
}

// * LCM(1,2,3,...,9) => 2520
// * Time Complexity (TC): O(2520 * 18) = O(45360) ~ O(10^5)
// * Space Complexity (SC): O(1)
void solve() {
  // * take input
  ll n;
  cin >> n;

  // * Keep incrementing n until a fair number is found
  while (!divideByDigits(n)) {
    n += 1;
  }
  
  cout << n << '\n';
}

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  ll t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}