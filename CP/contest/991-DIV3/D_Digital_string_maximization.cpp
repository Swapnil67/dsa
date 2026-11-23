/*
* D. Digital string maximization
*
* https://codeforces.com/contest/2050/problem/D
*/

#include <vector>
#include <iostream>
#pragma GCC optimize("O3")

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

// ! Observation
/*
* 1. To maximize the string lexicographically, we greedily want larger digits as far left as possible.
* 2. Moving a digit left by 1 position costs 1 decrement, so a swap only improves the string if:
*    s[j] - 1 > s[j - 1]  <=>  s[j] - s[j - 1] > 1.
* 3. Since digits are at most '9' and decrease by 1 on every swap, any digit can move left at most 9 times.
*    This bounds the inner while-loop to O(9) steps per index, making the overall time complexity O(9n) = O(n).
* 4. Processing left-to-right (i = 1 to n - 1) works in a single pass because bubbling s[i] left to its final
*    position never creates a new valid swap (diff > 1) behind it.
*/


// * Time Complexity: O(n)
// * Space Complexity: O(1)
void solve() {
  // * take input
  string s;
  cin >> s;

  int n = s.length();

  for (int i = 1; i < n; ++i) {
    int j = i;
    while (j > 0 && s[j] - s[j - 1] > 1) { // * O(9)
      // cout << s[j] << ' ' << s[j - 1] << '\n';
      s[j]--;
      swap(s[j], s[j - 1]);
      j--;
    }
    // cout << s << '\n';
  }

  cout << s << '\n';
  
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
// * g++ --std=c++20 C_Uninteresting_Number.cpp -o output && ./output
