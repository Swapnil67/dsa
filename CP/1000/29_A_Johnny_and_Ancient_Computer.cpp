/*
 * A. Johnny and Ancient Computer
 *
 * https://codeforces.com/problemset/problem/1362/A
*/

#include <cmath>
#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define PRINT_VEC(p) \
  for (auto &it : p) \
  cout << it << ' '; cout << '\n'

// * We'll remove all the power of 2 from a and b.    
// * a = ra * 2^x
// * b = rb * 2^y

void solve() {
  // * take input
  ll a, b;
  cin >> a >> b;
  
  // * Reduce a and b by continuously dividing by 2 until they are odd
  ll ra = a, rb = b;
  
  while (ra % 2 == 0) // * Remove all x from a
    ra /= 2;
    
  while (rb % 2 == 0) // * Remove all y from b
    rb /= 2;
    
  // * If the odd components of a and b are not equal, it's impossible to transform a to b
  if (ra != rb) {
    cout << -1 << '\n';
  } else {
    // * Normalize a and b by their odd components
    a /= rb; 
    b /= ra;
    
		// * Calculate the number of times a and b have been divided by 2
	  a = log2(a); // * x: number of times a was divided by 2
		b = log2(b); // * y: number of times b was divided by 2

    // * Calculate the minimum number of operations needed
    ll ans = ceil(abs(a - b) / 3.0);
    
    cout << ans << '\n';
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
// * g++ --std=c++20 29_A_Johnny_and_Ancient_Computer.cpp -o output && ./output
