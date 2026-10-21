/*
 * Sliding Window Mode
 * 
 * Given an array of n integers, calculate the mode (the most frequent element) 
 * in each sliding window of k elements from left to right. If multiple elements 
 * share the highest frequency, choose the smallest element among them.
 * 
 * Constraints  : 1 <= k <= n <= 2 * 10^5
 *                1 <= x_i <= 10^9
 * 
 * Example 1    :
 * Input        : n = 8, k = 3
 *                array = [1, 2, 3, 2, 5, 2, 4, 4]
 * Output       : [1, 2, 2, 2, 2, 4]
 * Explanation  : The modes for each window of size k = 3 are calculated as follows:
 *                - [1, 2, 3] -> Frequencies: 1:1, 2:1, 3:1. Multiple modes exist, the smallest is 1.
 *                - [2, 3, 2] -> Frequencies: 2:2, 3:1. The mode is 2.
 *                - [3, 2, 5] -> Frequencies: 3:1, 2:1, 5:1. Multiple modes exist, the smallest is 2.
 *                - [2, 5, 2] -> Frequencies: 2:2, 5:1. The mode is 2.
 *                - [5, 2, 4] -> Frequencies: 5:1, 2:1, 4:1. Multiple modes exist, the smallest is 2.
 *                - [2, 4, 4] -> Frequencies: 4:2, 2:1. The mode is 4.
 * 
 * https://cses.fi/problemset/task/3224
*/


// ! Observation
/*
* Set without negative 
* [{1, 1}, {3, 5}, {3, 7}]
* Here, st.rbegin()->second = 7 
* which is correct according to set but we need the minimum value if freq is same.
*
* So we'll keep the 2nd value as -ve in the set
* [{1, -1}, {3, -7}, {3, -5}]
* Here, st.rbegin()->second = 5
* 5 is correct since it has max freq and it is smallest among the [7, 5] both have freq of 3.
*
*/

#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

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


// * Using set
// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(N)
void solve(){ 
  ll n, k;
  cin >> n >> k;
  VEC(a, n, ll); READ_VEC(a);

  // * {freq, -element} adding '-' here becoz it we want the min element with least frequency
  set<pair<int, int>> st;
  map<int, int> freq;
  const auto insert = [&](int i) {
    int x = a[i];
    st.erase({freq[x], -x});
    freq[x]++;
    st.insert({freq[x], -x});
  };  

  const auto erase = [&](int i) {
    int x = a[i];
    st.erase({freq[x], -x});
    freq[x]--;
    st.insert({freq[x], -x});
  };  

  // * For first 0...k window
  for (int i = 0; i < k; ++i) {
    insert(i);
  }
  cout << -st.rbegin()->second;
  // * For every next k size window
  for (int i = k; i < n; ++i) {
    insert(i);
    erase(i - k);
    cout << ' ' << -st.rbegin()->second;
  }
  cout << '\n';
}

// ! Coordinate Compression
// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(N)
void solve2(){ 
  ll n, k;
  cin >> n >> k;
  VEC(a, n, ll); READ_VEC(a);

  // * Coordinate Compression
  vi v = a;
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for (auto &x: a) {
    x = lower_bound(v.begin(), v.end(), x) - v.begin();
  }
  // printArr(a);

  // * {freq, -element} adding '-' here becoz it we want the min element with least frequency
  set<pair<int, int>> st;
  vector<int> freq(n);
  const auto insert = [&](int i) {
    int x = a[i];
    st.erase({freq[x], -x});
    freq[x]++;
    st.insert({freq[x], -x});
  };  

  const auto erase = [&](int i) {
    int x = a[i];
    st.erase({freq[x], -x});
    freq[x]--;
    st.insert({freq[x], -x});
  };  

  // * For first 0...k window
  for (int i = 0; i < k; ++i) {
    insert(i);
  }
  cout << v[-st.rbegin()->second];
  // * For every next k size window
  for (int i = k; i < n; ++i) {
    insert(i);
    erase(i - k);
    cout << ' ' << v[-st.rbegin()->second];
  }
  cout << '\n';
}

int main(void) {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);

  // solve();
  solve2();
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 06-sliding-window-mode.cpp -o output && ./output

/*
* Input:
8 3
1 2 3 2 5 2 4 4

* Output:
1 2 2 2 2 4
*/