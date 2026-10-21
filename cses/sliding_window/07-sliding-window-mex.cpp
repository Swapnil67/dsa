/*
 * Sliding Window Mex
 * 
 * Description  : Given an array of n integers, calculate the mex (the smallest 
 *                nonnegative integer that does not appear) in each sliding window 
 *                of k elements from left to right.
 * 
 * Constraints  : 1 <= k <= n <= 2 * 10^5
 *                0 <= x_i <= 10^9
 * 
 * Example 1    :
 * Input        : n = 8, k = 3
 *                array =
 * Output       :
 * Explanation  : The mex values for each window of size k = 3 are calculated as follows:
 *                - -> The values are {1, 2}. The smallest missing nonnegative integer is 0.
 *                - -> The values are {2, 1}. The smallest missing nonnegative integer is 3.
 *                - -> The values are {1, 0}. The smallest missing nonnegative integer is 2.
 *                - -> The values are {0, 5}. The smallest missing nonnegative integer is 2.
 *                - -> The values are {5, 1}. The smallest missing nonnegative integer is 0.
 *                - -> The values are {1, 0}. The smallest missing nonnegative integer is 2.
 * 
 * https://cses.fi/problemset/task/3219
*/

#include <set>
#include <map>
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

// * mex value will lie in 0 >= mex <= k
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
void solve() {
  ll n, k;
  cin >> n >> k;
  VEC(a, n, ll); READ_VEC(a);

  set<int> st; // * non-existing values
  for (int x = 0; x <= k; ++x) { // * let all elements be non-existant
    st.insert(x);
  }

  map<int, int> freq_mp;
  const auto insert = [&](int i) {
    if (++freq_mp[a[i]] == 1) { // * found one element
      st.erase(a[i]); // * remove from non-existant set
    }
  };

  const auto erase = [&](int i) {
    if (--freq_mp[a[i]] == 0) { // * Element freq became 0
      st.insert(a[i]); // * add to non-existant set
    }
  };

  // * For first 0...k window
  for (int i = 0; i < k; ++i) {
    insert(i);
  }
  cout << *st.begin();
  // * For every next k size window
  for (int i = k; i < n; ++i) {
    insert(i);
    erase(i - k);
    cout << ' ' << *st.begin();
  }
  cout << '\n';
}

int main(void) {
  solve();
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 07-sliding-window-mex.cpp -o output && ./output
