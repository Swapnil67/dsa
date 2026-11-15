/*
 * Prefix XOR
 * 
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
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

// * TIME COMPLEXITY O(n + q)
// * SPACE COMPLEXITY O(n)
int main(void) {
  // * take input
  ll n, q;
  cin >> n >> q;
  vi a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  printArr(a);

  // * Build prefix XOR array
  vi p(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] ^ a[i - 1];
  }
  printArr(p);

  // * Solve for q queries
  while(q--) {
    ll l, r;
    cin >> l >> r;
    // cout << p[r] << '^' << p[l - 1] << '\n';
    cout << (p[r] ^ p[l - 1]) << '\n';
  }

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 prefix-xor.cpp -o output && ./output

// * testcase
/*
5 3
1 2 3 4 5
2 4
2 5
1 4



*/