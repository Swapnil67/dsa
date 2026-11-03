/*
 * Static Range Sum Queries
 *
 * https://cses.fi/problemset/task/1646 
*/

#include <vector>
#include <iostream>

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
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) 
    cin >> a[i];
  // printArr(a);

  // * count the prefix sum
  vector<ll> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] + a[i - 1];
  }
  // printArr(p);

  // * Process each query
  while (q--) {
    ll l, r;
    cin >> l >> r;
    cout << p[r] - p[l - 1] << '\n';
  }
}

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);

  solve();
  
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 01-static-range-sum-queries.cpp -o output && ./output

/*
Input:
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3

Output:
11
2
24
4
*/