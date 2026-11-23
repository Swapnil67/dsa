/*
* C. Uninteresting Number
*
* https://codeforces.com/contest/2050/problem/C
*/

#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

// ! Observation
/*
* 1. A number is divisible by 9 iff the sum of its digits is divisible by 9.
* 2. Since x^2 must be a single digit (< 10), only 0, 1, 2, and 3 can be squared:
*    - 0 -> 0 (adds 0)
*    - 1 -> 1 (adds 0)
*    - 2 -> 4 (adds +2)
*    - 3 -> 9 (adds +6)
* 3. Digits >= 4 cannot be changed (4^2 = 16 >= 10), and 0 or 1 don't change the sum, so only '2' and '3' matter.
* 4. Squaring 'a' twos and 'b' threes increases the digit sum by (2a + 6b).
* 5. Using modular congruence (mod 9):
*    sum + 2a + 6b ≡ 0 (mod 9)
*    2a + 6b ≡ (9 - sum % 9) % 9 (mod 9)   [where RHS = diff_to_cover]
*    2a ≡ diff_to_cover - 6b (mod 9)
* 6. Since gcd(2, 9) = 1, 2 has a modular multiplicative inverse of 5 (2 * 5 = 10 ≡ 1 mod 9):
*    a ≡ (diff_to_cover - 6b) * 5 (mod 9)  [gives minimum non-negative 'a' needed; valid if a <= two_count].
*/

// * Time Complexity: O(n)
// * Space Complexity: O(1)
void solve() {
  // * take input
  string s;
  cin >> s;
  
  ll sum = 0;
  ll two_count = 0, three_count = 0;
  for (char c: s) {
    sum += (c - '0');
    if (c == '2') two_count++;
    if (c == '3') three_count++;
  }
  
  // cout << sum << '\n';
  // * how much extra do i need to add to 'n' to make it divisible by 9.
  ll diff_to_cover = (9 - (sum % 9)) % 9;

  // * 2a + 6b = diff_to_cover
  // * 2a = (diff_to_cover - 6b) % 9
  // * a  = (diff_to_cover - 6b) * 5 % 9     ----- (5 is multiplative inverse of 2 with respect to mod 9)
  for (ll b = 0; b <= three_count; ++b) {
    ll new_diff_to_cover = ((diff_to_cover - 6LL * b) % 9 + 9) % 9;

    // * multiplative inverse of 2
    ll a = (new_diff_to_cover * 5) % 9;
    if (a <= two_count) {
      cout << "YES" << '\n';
      return;
    }
  }

  cout << "NO" << '\n';
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

// * Run the code
// * g++ --std=c++20 C_Uninteresting_Number.cpp -o output && ./output
