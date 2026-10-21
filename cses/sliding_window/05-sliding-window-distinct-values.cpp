/*
 * Sliding Window Distinct Values
 * 
 * Description  : Given an array of n integers, calculate the number of distinct values 
 *                in each sliding window of k elements, moving from left to right.
 * 
 * Constraints  : 1 <= k <= n <= 2 * 10^5
 *                1 <= x_i <= 10^9
 * 
 * Example 1    :
 * Input        : n = 8, k = 3
 *                array = [1, 2, 3, 2, 5, 2, 2, 2]
 * Output       : [3, 2, 3, 2, 2, 1]
 * Explanation  : The distinct count for each window of size 3 is:
 *                - [1, 2, 3] -> 3 distinct elements
 *                - [2, 3, 2] -> 2 distinct elements (2, 3)
 *                - [3, 2, 5] -> 3 distinct elements
 *                - [2, 5, 2] -> 2 distinct elements (2, 5)
 *                - [5, 2, 2] -> 2 distinct elements (2, 5)
 *                - [2, 2, 2] -> 1 distinct element (2)
 * 
 * https://cses.fi/problemset/task/3222
*/

#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
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

// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(N)
void solve() {
  ll n, k;
  cin >> n >> k;
  VEC(a, n, ll); READ_VEC(a);

  map<int, int> mp;
  // * For first 0...k
  for (int i = 0; i < k; ++i) {
    mp[a[i]]++;
  }
  cout << mp.size();

  // * For every next k size window
  for (int i = k; i < n; ++i) {
    mp[a[i]]++;
    if (--mp[a[i - k]] == 0) {
      mp.erase(a[i - k]);
    }
    cout << ' ' << mp.size();
  }
  cout << '\n';
}

// ! Coordinate Compression
// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(N)
void solve2() {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  ll n, k;
  cin >> n >> k;
  VEC(a, n, ll); READ_VEC(a);
  // printArr(a);

  // * Coordinate Compression
  // * Sort & remove duplicates
  vi v = a;
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  // printArr(v);
  for (auto &x: a) {
    x = lower_bound(v.begin(), v.end(), x) - v.begin();
  }

  int nonzeros = 0;
  vector<ll> freq(n);
  const auto insert = [&](int i) {
    if (++freq[a[i]] == 1) {
      nonzeros++;
    }
  };
  const auto erase = [&](int i) {
    if (--freq[a[i]] == 0) {
      nonzeros--;
    }
  };

  // * For first 0...k window
  for (int i = 0; i < k; ++i) {
    insert(i);
  }
  cout << nonzeros;
  
  // * For every next k size window
  for (int i = k; i < n; ++i) {
    insert(i);
    erase(i - k);
    cout << ' ' << nonzeros;
  }
  cout << '\n';
}

int main(void) {
  // solve();
  solve2();
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 05-sliding-window-distinct-values.cpp -o output && ./output


/*
* Input:
8 3
1 2 3 2 5 2 2 2

* Output:
3 2 3 2 2 1
*/