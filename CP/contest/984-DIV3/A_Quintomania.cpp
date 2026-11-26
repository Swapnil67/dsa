/*
* A. Quintomania
*
* https://codeforces.com/contest/2036/problem/A
*/

#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

// ! Approach: 
// * Time Complexity: O(n)
// * Space Complexity: O(n)
void solve() {
  // * take input
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x: a) cin >> x;
  
  for (int i = 0; i < n - 1; ++i) {
    int semitone = abs(a[i] - a[i + 1]);
    if (semitone != 5 && semitone != 7) {
      cout << "NO" << '\n';
      return;
    }
  }
  
  cout << "YES" << '\n';
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
// * g++ --std=c++20 A_Quintomania.cpp -o output && ./output
