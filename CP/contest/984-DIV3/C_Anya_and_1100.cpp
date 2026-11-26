/*
* C. Anya and 1100
*
* https://codeforces.com/contest/2036/problem/C
*/

#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define PRINT_VEC_PAIRS(p) for (auto &it: p) cout << it.first << ' ' << it.second << '\n'

// ! Observation
/*
* the number of times “1100” occurs in 's'
*
* Then for each of 'q' queries we will update count : consider the substring s[max(1,i−4);min(i+4,n)]
* before changing s[i] and find before — the number of times that “1100” occurs in it. 
* Then update s[i] = v and similarly find after — the number of times that “1100” occurs in s[max(1,i−4);min(i+4,n)]
* after applying the query.
*
* Thus, by doing count=count+(after - before), we get the number of times that “1100” occurs in 's' 
* after the query is applied. If count > 0, the answer to the query is “YES”, otherwise it is “NO”.
*
*/

// ! Approach: Greedy Range check
// * Time Complexity: O(n + q)
// * Space Complexity: O(1)
void solve() {
  // * take input
  string s;
  cin >> s;

  ll n = s.length();

  // * Step 1: count occurences of 1100 in string 's'
  ll count = 0;
  for (int i = 0; i < n - 3; ++i) {
    if (s.substr(i, 4) == "1100")
      count++;
  }
  // cout << count << '\n';

  ll q;
  cin >> q;
  while (q--) {
    int idx, v;
    cin >> idx >> v;

    // * Substring in range [L:R] got affected.
    int L = max(0, idx - 4);
    int R = min((int)n, idx + 4);

    // * check all substrings from range s[L:R] before changing s[i] and count "1100" occurences.
    int before = 0;
    for (int i = L; i < R; ++i) {
      if (s.substr(i, 4) == "1100")
        before += 1;
    }

    s[idx - 1] = v + '0';

    // * check all substrings from range s[L:R] after changing s[i] and count "1100" occurences.
    int after = 0;
    for (int i = L; i < R; ++i) {
      if (s.substr(i, 4) == "1100")
        after += 1;
    }

    // cout << s << ' ' << before << ' ' << after << '\n';

    count = count + (after - before);
    if (count > 0) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
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
// * g++ --std=c++20 C_Anya_and_1100.cpp -o output && ./output
