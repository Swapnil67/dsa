/*
 * Sliding Window Sum
 * 
 * Description:
 * Calculate the sum of each sliding window of size k in an array of n integers, 
 * where elements are generated using a linear congruential pseudo-random number generator.
 * Return the bitwise XOR of all window sums.
 * 
 * Constraints:
 * 1 <= k <= n <= 10^7, elements generated via coefficients a, b, c up to 10^9.
 * 
 * Example:
 * For n = 8, k = 5, x = 3, a = 7, b = 1, c = 11, the window sums are 14, 15, 22, and 27, 
 * yielding a final XOR sum of 12.
 *
 * https://cses.fi/problemset/task/3220
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
  ll n, k;
  cin >> n >> k;
  ll a, b, c;
  VEC(x, n, ll);
  cin >> x[0] >> a >> b >> c;
  for (int i = 1; i < n; ++i) { // * input generator
    // cout << a << " * " << x[i - 1] << " + " << b << " % " << c << '\n';
    x[i] = (1LL * a * x[i - 1] + b) % c;
  }
  // printArr(x); // * For debug

  ll sum = 0;
  // * add the first k elements
  for (int i = 0; i < k; ++i) {
    sum += x[i];
  }
  // cout << sum << ' ';
  ll answer = sum;
  for (int i = k; i < n; ++i) {
    // * sum from x[i-k+1...i]
    sum += x[i] - x[i - k];
    // cout << sum << ' ';
    answer ^= sum;
  }
  cout << answer << '\n';

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 01-sliding-window-sum.cpp -o output && ./output
