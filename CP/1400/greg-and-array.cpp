
// ! Observation
// ! Difference Arrays + Range Prefix Sum

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]
#define PRINT_VEC_PAIRS(p) for (auto &it: p) cout << it.first << ' ' << it.second << '\n'

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

// * Time Complexity (TC): O(n * m)
// * Space Complexity (SC): O(n)
void solveBrute() {
  ll n, m, k;
  cin >> n >> m >> k;
  
  VEC(a, n + 1, ll);
  a[0] = 0;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  // printArr(a);
  
  // * Create a difference array
  VEC(diff, n + 2, ll);
  diff[0] = 0;
  diff[1] = a[1];
  for (int i = 2; i <= n; ++i) 
    diff[i] = a[i] - a[i - 1];
    
  // printArr(diff);
  
  // * Create vector of operations
  vector<vector<ll>> edits(m + 1);
  int i = 1;
  for (int j = 0; j < m; ++j) {
    ll left, right, val;
    cin >> left >> right >> val;
    edits[i++] = {left, right, val};
  }
  // for (auto e: edits) printArr(e);
  
  // * Do the operations for given x & y
  while (k--) {
    ll x, y;
    cin >> x >> y;
    int i = x;
    while (i <= y) {
      // cout << i << '\n';
      // cout << edits[i][0] << ' ' << edits[i][1] + 1 << " => " << edits[i][2] << '\n';
      diff[edits[i][0]] += edits[i][2];
      diff[edits[i][1] + 1] += -(edits[i][2]);
      i++;
      // printArr(diff);
    }
  }
  
  // * Do final Prefix Sum and print
  vector<ll> ans(n + 1, 0);
  ans[1] = diff[1];
  cout << ans[1] << ' ';
  for (int i = 2; i <= n; ++i) {
    ans[i] = ans[i - 1] + diff[i];
    cout << ans[i] << ' ';
  }
  cout << '\n';
  
}

// * Time Complexity (TC): O(n)
// * Space Complexity (SC): O(n)
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  
  vector<ll> a(n, 0);
  for (int i = 0; i < n; ++i) 
    cin >> a[i];
    
  // * Build the difference array of the original array.
  vector<long long> diff(n + 1, 0);
  diff[0] = a[0];
  for (int i = 1; i < n; i++)
    diff[i] = a[i] - a[i - 1];
  
  // * Store all operations:
  // * operation i adds val[i] to the range [l[i], r[i]]
  vector<long long> l(m), r(m), val(m);
  for (int i = 0; i < m; i++)
    cin >> l[i] >> r[i] >> val[i];
  
  // * Difference array over the operations.
  // * opCount[i] will store how many times
  // * the i-th operation should be applied.
  vector<ll> opCount(m + 1, 0);
  for (int i = 1; i <= k; ++i) {
    ll x, y;
    cin >> x >> y;
    x--, y--;
    opCount[x] += 1;
    opCount[y + 1] -= 1;
  }
  
  for (int i = 1; i < m; ++i)
    opCount[i] += opCount[i - 1];

  // * Apply every operation exactly opCount[i] times
  // * using another difference array.
  for (int i = 0; i < m; i++) {
    ll times = opCount[i];
    ll total = times * val[i];

    // * Convert to 0-based indexing
    l[i]--, r[i]--;

    // * Apply the total contribution of this operation
    diff[l[i]] += total;
    diff[r[i] + 1] -= total;
  }
  
  // * Do final Prefix Sum and print
  a[0] = diff[0];
  for (int i = 1; i < n; ++i)
    a[i] = a[i - 1] + diff[i];
  
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';

  cout << '\n';
}

int main() {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  solve();

  return 0;
}

 
// * Run the code
// * g++ --std=c++20 greg-and-array.cpp -o output && ./output

// * Testcase
/*
3 3 3
1 2 3
1 2 1
1 3 2
2 3 4
1 2
1 3
2 3

*/

// * Output
/*
9 18 17
*/