/*
 * B - Longest Rainy Streak 
 * 
 * https://atcoder.jp/contests/abc479/tasks/abc479_b
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;

  string s;
  cin >> s;

  ll max_rainy_days = 0;
  ll cur = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') {
      cur += 1;
    } else {
      cur = 0;
    }
    max_rainy_days = max(max_rainy_days, cur);
  }

  cout << max_rainy_days << '\n';
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 b-longest-rainy-streak.cpp -o output && ./output
