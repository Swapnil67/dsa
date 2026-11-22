/*
 * E. Best Price
 *
 * https://codeforces.com/contest/2051/problem/E
*/

#include <map>
#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define PRINT_VEC(p)   \
  for (auto &it : p)   \
    cout << it << ' '; \
  cout << '\n'
#define PRINT_VEC_PAIRS(p) for (auto &it: p) cout << it.first << ' ' << it.second << '\n'


int M = 1e9 + 7;

// ! Observation
/*
* At start (no_buys, neg_rating) => (n, 0) at price 0
* (n, 0)
* (n, 0)
* (n, 1)    a[i] + 1   - (price increased so neg_rating can also increase)
* (n, 2)    a[i] + 1   
* ...
* (n-1, 1)  b[i] + 1   - (b prices is increased so no_buys and neg_rating both will decrease)
*
*
* So we can see that no_buys and neg_rating will change after each price changes
* using some price we'll not be able to buy only.
*
* So we need to find max profit using one of these 'price * no_buys'
*/

// Time Complexity: O(n)
// Space Complexity: O(1)
void solve() {
  // * take input
  ll n, k;
  cin >> n >> k;
  vl a(n, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vl b(n, 0);
  for (int i = 0; i < n; ++i) cin >> b[i];
  
  map<ll, ll> diff_neg_rating;
  map<ll, ll> diff_no_buys;
  for (int i = 0; i < n; ++i) {
    diff_neg_rating[a[i]]++;
  }
  for (int i = 0; i < n; ++i) {
    diff_neg_rating[b[i]]--;
    diff_no_buys[b[i]]--;
  }
  // PRINT_VEC_PAIRS(diff_neg_rating);
  // PRINT_VEC_PAIRS(diff_no_buys);
  
  ll max_profit = 0LL;
  // * assume initial price to be 0, everyone will buy with +ve rating.
  ll no_buys = n, neg_rating = 0;
  for (auto &[price, rating]: diff_neg_rating) {
    if (neg_rating <= k) {
      max_profit = max(max_profit, (price * no_buys));
    }
    
    neg_rating += diff_neg_rating[price];
    no_buys += diff_no_buys[price];
  }
  
  cout << max_profit << '\n';
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