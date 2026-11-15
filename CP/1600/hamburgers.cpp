/*
 * Hamburgers
 * 
 * https://codeforces.com/problemset/problem/371/C
 */

// ! Binary Search on Answers

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

ll pb, ps, pc;
ll breads = 0, sausages = 0, cheese = 0;

bool canMake(ll burgers_count, ll nb, ll ns, ll nc, ll total_money) {
  ll extra_money = 0;
  extra_money += max(0LL, (breads * burgers_count) - nb) * pb;   // * check extra breads cost
  extra_money += max(0LL, (sausages * burgers_count) - ns) * ps; // * check extra sausage cost
  extra_money += max(0LL, (cheese * burgers_count) - nc) * pc;   // * check extra cheese cost
  return (extra_money <= total_money);                           // * can make burgers_count
}

// * Time Complexity (TC): O(nlog(1e13))
// * Space Complexity (SC): O(1)
void solve() {
  string recipe;
  cin >> recipe;
  
  // * initial count of bread, sausage and cheese
  ll nb, ns, nc;
  cin >> nb >> ns >> nc;
  
  // * cost of bread, sausage and cheese
  cin >> pb >> ps >> pc;
  
  // * Total extra money we have
  ll r;
  cin >> r;
  
  // * count total bread, sausage, and cheese in single burgers
  for (char c : recipe) {
    if (c == 'B') breads++;
    if (c == 'S') sausages++;
    if (c == 'C') cheese++;
  }
  // cout << "b: " <<  b << " s: "  << s << ", c: " << c << '\n';
  
  // * Binary Search
  ll i = 1, j = 1e13;
  ll ans = 0;
  while (i <= j) {
    ll m = i + (j - i) / 2;
    if (canMake(m, nb, ns, nc, r)) { // * can make 'm' burgers with 'r' cost
      ans = m;
      i = m + 1;
    } else {
      j = m - 1;
    }
  }
  
  cout << ans << '\n';
    
}

int main() {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  solve();
  return 0;
}

