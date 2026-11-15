/*
* D. Lock and Unlock
*
* https://codeforces.com/contest/2278/problem/D
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
#define PRINT_VEC(p)   \
  for (auto &it : p)   \
    cout << it << ' '; \
  cout << '\n'

// ! Observation
/*
* This is a common pattern we'll try to make all elements equal to median of array.
* This will get us the minimum cost as possible.
* 
* For no. of operations it will be max_element - min_element.
*/
  
void solve() {
  // * take input
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) 
    cin >> a[i];
    
  // * Sort the vector
  sort(begin(a), end(a));
  
  // * Find the distance each a[i] to median
  ll median = a[n/2];
  ll cost = 0;
  for (int i = 0; i < n; ++i) {
    cost += abs(a[i] - median);
  }
  
  ll ops = a[n-1] - a[0]; // * max - min
  cout << cost << " " << ops  << '\n';
}

int main() {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  ll t;
  cin >> t;
  while (t--)
    solve();
  
  return 0;
}

