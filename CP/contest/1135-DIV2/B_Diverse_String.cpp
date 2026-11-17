/*
* B. Diverse String
*
* https://codeforces.com/contest/2285/problem/B
*/

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

// ! Observation
/*
* s = 1001
*
* If we want to flip 0 -> 1 and create a distinct string then only 0 contributes to the string
* Eg: In our example count of 0 is 2, & 1 is 2 so following combination can be made
* 0 -> 1 = [1101, 1011, 1111] (4 combinations)
* 1 -> 0 = [0001, 0000, 1000] (4 combinations)
* So total 3 + 3 + 1 = 7 combination (1 extra for orignal string
*
* combination = n * (n + 1) / 2
*
* We need to greedily increase the count of 0s or count of 1s and then find total combinations.
*/
  
// * Time Complexity (TC): O(n)
// * Space Complexity (SC): O(1)
void solve() {
  // * take input
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  
  // * count number of 0 in string s
  ll c0 = 0;
  for (auto c: s) {
    c0 += (c == '0');
  }
  // * get number of 1 in string s
  ll c1 = n - c0;
  
  ll ma = max(c0, c1);
  ll mi = min(c0, c1);
  
  ma = min(ma + k, n);    // * Add k flips to maximum & check bounds
  mi = max(0LL, mi - k);  // * Remove k flips from minimum & check bounds 
  
  ll ds1 = (ma * (ma + 1)) / 2; // * count of distinct str with char count ma
  ll ds2 = (mi * (mi + 1)) / 2; // * count of distinct str with char count mi
  cout << (ds1 + ds2 + 1) << '\n';
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
// * g++ --std=c++20 B_Diverse_String.cpp -o output && ./output
