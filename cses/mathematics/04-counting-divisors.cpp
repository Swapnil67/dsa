/*
 * Counting Divisors
 * 
 * https://cses.fi/problemset/task/1713/
*/

#include <iostream>

using namespace std;
typedef long long ll;

void bruteForce() {
  ll n;
  cin >> n;
  int count = 0;
  for (int d = 1; d * d <= n; ++d) {
    if (n % d == 0) {
      count++;
      if (n / d != d) 
        count++;
    }
  }
  cout << count << '\n';
}

// * TIME COMPLEXITY O(sqrt(n))
// * SPACE COMPLEXITY O(1)
void betterApproach() {
  ll n;
  cin >> n;
  int count = 0;
  for (int d = 1; d * d <= n; ++d) {
    if (n % d == 0) {
      count++;
      if (n / d != d) 
        count++;
    }
  }
  cout << count << '\n';
}

// * TIME COMPLEXITY O(logn)
// * SPACE COMPLEXITY O(1)
void optimal() {
  ll n;
  cin >> n;
  ll ans = 1;
  for (int d = 2; d * d <= n; ++d) {
    ll cnt = 0;
    while (n % d == 0) {
      n /= d;
      cnt++;
    }
    ans *= (cnt + 1);
  }
  if (n > 1)
    ans *= 2; // * remaining prime
  cout << ans << '\n';
}

int main() {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);

  ll t;
  cin >> t;
  while (t--) {
    // bruteForce();
    // betterApproach();
    optimal();
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 04-counting-divisors.cpp -o output && ./output