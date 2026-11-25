/*
* B. Intercepted Inputs
*
* https://codeforces.com/contest/2037/problem/B
*/

#include <map>
#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

// ! Observation
/*
* 1. Total elements in the stream = k (stored as 'n' here). Out of these, 2 integers
*    represent the grid dimensions (row and col), and the remaining (k - 2) integers
*    form the grid elements.
* 2. Therefore, row * col = k - 2. Both 'row' and 'col' must be divisors of (k - 2)
*    and must exist in the given array.
* 3. Edge Case: If row == col (i.e., i == q), that value must appear at least twice
*    in the input stream (mp[i] >= 2) to account for both dimensions.
*/

// ! Approach: Frequency Hashing + Divisor Enumeration up to sqrt(n - 2)
// * Time Complexity: O(nlogn)
// * Space Complexity: O(n)
void solve() {
  // * take input
  int n; cin >> n;
  vl a(n);
  map<ll, ll> mp;
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
    mp[a[i]]++;
  }
  
  ll row = 0, col = 0;
  ll N = n - 2; // * Find two factors of 'N'
  for (int i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      ll q = N / i;
      if (i == q && mp[i] >= 2) {
         row = i, col = q;
         break;
      }
      if (mp.count(i) && mp.count(q)) {
        row = i, col = q;
        break;
      }
    }
  }
  
  cout << row << ' ' << col << '\n';
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
// * g++ --std=c++20 B_Intercepted_Inputs.cpp -o output && ./output
