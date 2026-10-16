/*
 * Sliding Window Xor
 * 
 * Description:
 * You are given an array of n integers. Your task is to calculate the bitwise XOR of each 
 * sliding window of k elements, from left to right. The input array is generated using a 
 * linear congruential pseudo-random number generator to handle the large input size.
 * 
 * Return the bitwise XOR of all computed window XOR values.
 * 
 * Constraints:
 * 1 <= k <= n <= 10^7
 * 0 <= x, a, b <= 10^9
 * 1 <= c <= 10^9
 * 
 * Example 1    :
 * Input        : n = 8, k = 5
 *                x = 3, a = 7, b = 1, c = 11
 * Output       : 0
 * Explanation  : The generated array is. 
 *                The sliding windows and their XOR sums are:
 *                - [3, 0, 1, 8, 2] -> 3 ^ 0 ^ 1 ^ 8 ^ 2 = 8
 *                - [0, 1, 8, 2, 4] -> 0 ^ 1 ^ 8 ^ 2 ^ 4 = 15
 *                - [1, 8, 2, 4, 7] -> 1 ^ 8 ^ 2 ^ 4 ^ 7 = 8
 *                - [8, 2, 4, 7, 6] -> 8 ^ 2 ^ 4 ^ 7 ^ 6 = 15
 *                The final answer is the XOR of all window XORs: 8 ^ 15 ^ 8 ^ 15 = 0.
 *
 * Link         : https://cses.fi/problemset/task/3426
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

// Macros
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))

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
void optimalApproach(vi nums, ll k) {
  ll n = nums.size();
  ll XOR = 0;
  for (int i = 0; i < k; ++i) {
    XOR ^= nums[i];
  }

  ll answer = XOR;
  for (int i = k; i < n; ++i) {
    // * remove nums[i-k] from the current XOR
    XOR ^= nums[i] ^ nums[i - k];
    answer ^= XOR;
  }

  cout << answer << '\n';
}

int main(void) {
  ll n, k;
  cin >> n >> k;
  ll A, B, C;
  VEC(a, n, ll);
  cin >> a[0] >> A >> B >> C;
  for (int i = 1; i < n; ++i) { // * input generator
    // cout << a << " * " << x[i - 1] << " + " << b << " % " << c << '\n';
    a[i] = (1LL * A * a[i - 1] + B) % C;
  }
  // cout << "nums: ";
  // printArr(a); // * For debug

  optimalApproach(a, k);
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 03-sliding-window-xor.cpp -o output && ./output


/*
* Input:
8 5
3 7 1 11

* Output:
0

* Explanation:
* The input array is [3,0,1,8,2,4,7,6]. 
* The windows are [3,0,1,8,2], [0,1,8,2,4], [1,8,2,4,7] and [8,2,4,7,6], 
* and their xors are 8, 15, 8 and 15. 
* Thus, the answer is 8 ^ 15 ^ 8 ^ 15 = 0.
*/