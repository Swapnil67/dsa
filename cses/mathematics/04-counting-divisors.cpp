/*
 * Counting Divisors
 * 
 * https://cses.fi/problemset/task/1713/
*/

#include <iostream>
#include <cmath>

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

void optimal() {
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

int main() {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);

  ll t;
  cin >> t;
  while (t--) {
    bruteForce();
    optimal();
  }
  return 0;
}

// * Run the code
// * g++ --std=c++20 04-counting-divisors.cpp -o output && ./output