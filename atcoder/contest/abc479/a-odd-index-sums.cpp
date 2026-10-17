/*
 * A - Odd Index Sum
 * 
 * https://atcoder.jp/contests/abc479/tasks/abc479_a
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

// Macros
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

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

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  VEC(a, n + 1, ll);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  ll sum = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 1) {
      sum += a[i];
    }
  }

  cout << sum << '\n';

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 a-odd-index-sums.cpp -o output && ./output
