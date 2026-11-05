/*
 * Forest Queries
 *
 * https://cses.fi/problemset/task/1652
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

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

// * TIME COMPLEXITY O((n * n) + q)
// * SPACE COMPLEXITY O(n * n)
void solve() {
  // * take input
  ll n, q;
  cin >> n >> q;

  vector<vl> a(n, vl(n, 0));
  for (int i = 0; i < n; ++i) {
    string row = "";
    cin >> row;
    for (int j = 0; j < n; ++j) {
      a[i][j] = (row[j] == '*');
    }
  }
  // for (auto &v : a) // * For Debug
  //   printArr(v);

  // * Create prefix 2D vector
  vector<vl> p(n + 1, vl(n + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      p[i][j] = p[i][j - 1] + p[i - 1][j];
      p[i][j] -= p[i - 1][j - 1];
      p[i][j] += a[i - 1][j - 1];
    }
  }
  // for (auto &v : p) // * For Debug
  //   printArr(v);

  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int ans = p[x2][y2];
    ans -= p[x1 - 1][y2];
    ans -= p[x2][y1 - 1];
    ans += p[x1 - 1][y1 - 1];

    cout << ans << '\n';
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
// * g++ --std=c++20 07-forest-queries.cpp -o output && ./output

/*
Input:
4 3

.*..
*.**
**..
****

2 2 3 4
3 1 3 1
1 1 2 2

Output:
3
1
2
*/