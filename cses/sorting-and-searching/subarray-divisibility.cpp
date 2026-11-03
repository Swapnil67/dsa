/*
 * Subarray Divisibility
 *
 * https://cses.fi/problemset/task/1662
*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << "\n";
}

// * TIME COMPLEXITY O(n + q)
// * SPACE COMPLEXITY O(n)
void solve() {
  // * take input
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  // * sum[i..j] = p[j] - p[i - 1]   ---- (We know already)
  // * (p[j] - p[i - 1]) % n = 0
  // * p[j] % n = p[i - 1] % n
  unordered_map<ll, ll> mp;
  mp[0] = 1;
  ll pref_sum = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    pref_sum += a[i];
    ll check = ((pref_sum % n) + n) % n;
    if (mp.count(check)) {
      ans += mp[check];
    }
    mp[check]++;
  }

  cout << ans << '\n';
}

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);

  solve();
  
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 subarray-divisibility.cpp -o output && ./output

/*
Input:
5
3 1 2 7 4

5
1 3 2 5 5

Output:
1

6
*/