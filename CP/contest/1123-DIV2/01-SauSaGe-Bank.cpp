/*
* SauSaGe Bank
*
* https://codeforces.com/contest/2269/problem/A
*/

#include<iostream>

using namespace std;
typedef long long ll;

/*
* We'll greedily take the remove money at day which has max amount in bank.
* Rest we'll add 2 for the remaining days we remove.
*/
// * ans = 2^(n-k+1) + 2*(k-1)

ll solve(void) {
  ll n, k;
  cin >> n >> k;
  ll ans = 1 << (n - k + 1);
  ans += 2 * (k - 1);
  return ans;
}

// * Greedy Math
// * Time Complexity (TC): O(1)
// * Space Complexity (SC): O(1)
int main(void) {
  ll t;
  cin >> t;

  while (t--) 
    cout << solve() << "\n";
  
  return 0;
}