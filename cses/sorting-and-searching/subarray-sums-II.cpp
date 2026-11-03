/*
 * Subarray Sums II
 *
 * https://cses.fi/problemset/task/1661
*/

#include <map>
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

// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(n)
void solve() {
  // * take input
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  // * Count subarrays with sum = k
  map<ll, ll> mp;
  mp[0] = 1;
  ll sum = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];

    // * If there was a previous prefix sum = sum - k,
    // * then subarray between that index and current index
    // * has exactly sum k
    if (mp.count(sum - x)) 
      ans += mp[sum - x];
    
    mp[sum]++;
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
// * g++ --std=c++20 subarray-sums-II.cpp -o output && ./output

/*
Input:
5 7
2 -1 3 5 -2

Output:
2
*/