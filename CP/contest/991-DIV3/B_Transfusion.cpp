/*
* B. Transfusion
*
* https://codeforces.com/contest/2050/problem/B
*/

#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

// ! Observation
/*
* a = [a1, a2, a3, a4, a5]
*
* 1. If we do a1 += 1 and a3 -= 1, the total sum of array 'a' still remains same.
* 2. Each time operations are only applied on the elements with same parity.
* 3. We need the odd_sum and even_sum to be divisible by their lengths so each group can equalize internally.
* 4. Since odd and even indices never interact, their final equalized values (averages) must also match:
*    (odd_sum / odd_cnt) == (even_sum / even_cnt).
*/

// * Time Complexity: O(n)
// * Space Complexity: O(1)
void solve() {
  // * take input
  ll n;
  cin >> n;
  ll odd_sum = 0LL, even_sum = 0LL;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    if (i & 1) {
      odd_sum += x;
    } else {
      even_sum += x;
    }
  }
  
  ll odd_cnt = n / 2;
  ll even_cnt = (n + 1) / 2;

  if ((odd_sum % odd_cnt == 0) && (even_sum % even_cnt == 0) && (odd_sum / odd_cnt) == (even_sum / even_cnt)) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
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
// * g++ --std=c++20 B_Transfusion.cpp -o output && ./output

// * testcases
/*
8
3
3 2 1
3
1 1 3
4
1 2 5 4
4
1 6 6 1
5
6 2 1 4 2
4
1 4 2 1
5
3 1 2 1 3
3
2 4 2

*/

// * output
/*
YES
NO
YES
NO
YES
NO
NO
NO

*/