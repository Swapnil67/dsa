/*
 * Sliding Window Or
 * 
 * Description:
 * You are given an array of n integers. Your task is to calculate the bitwise OR of each 
 * sliding window of k elements, from left to right. The input array is generated using a 
 * linear congruential pseudo-random number generator to handle the large input size.
 * 
 * Return the bitwise XOR of all computed window OR values.
 * 
 * Constraints:
 * 1 <= k <= n <= 10^7
 * 0 <= x, a, b <= 10^9
 * 1 <= c <= 10^9
 * 
 * Example 1    :
 * Input        : n = 8, k = 5
 *                x = 3, a = 7, b = 1, c = 11
 * Output       : 4
 * Explanation  : The generated array is. 
 *                The sliding windows and their bitwise OR values are:
 *                - [3, 0, 1, 8, 2] -> 3 | 0 | 1 | 8 | 2 = 11
 *                - [0, 1, 8, 2, 4] -> 0 | 1 | 8 | 2 | 4 = 15
 *                - [1, 8, 2, 4, 7] -> 1 | 8 | 2 | 4 | 7 = 15
 *                - [8, 2, 4, 7, 6] -> 8 | 2 | 4 | 7 | 6 = 15
 *                The final answer is the XOR of all window ORs: 11 ^ 15 ^ 15 ^ 15 = 4.
 *
 * https://cses.fi/problemset/task/3405
*/

// ! Divide And Conquer 

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
  int n = nums.size();
  vector<int> suf(n), pref(n);
  ll answer = 0;
  for (int mid = k - 1; mid < n; mid += k) {
    // * mid-k+1...mid
    suf[mid] = nums[mid];
    for (int i = mid - 1; i >= mid - k + 1; --i) {
      suf[i] = (suf[i + 1] | nums[i]);
    }

    // * mid+1...mid+k
    if (mid + 1 < n) // * Imp boundary check
      pref[mid + 1] = nums[mid + 1];
    for (int i = mid + 2; i < n && i <= mid + k; ++i) {
      pref[i] = (pref[i - 1] | nums[i]);
    }

    for (int i = mid - k + 1; i <= mid && i <= n - k; ++i) {
      // * i...i+k-1
      if (i == mid - k + 1) {
        answer ^= suf[i];
        // cout << "OR: " << (suf[i]) << '\n';
      } else {
        answer ^= (suf[i] | pref[i + k - 1]);
        // cout << "OR: " << (suf[i] | pref[i + k - 1]) << '\n';
      }
    }
    // printArr(suf);
    // printArr(pref);
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
// * g++ --std=c++20 04-sliding-window-or.cpp -o output && ./output


/*
* Input:
8 5
3 7 1 11

* Output:
4

* Explanation:
* The input array is [3,0,1,8,2,4,7,6]. 
* The windows are [3,0,1,8,2], [0,1,8,2,4], [1,8,2,4,7] and [8,2,4,7,6], 
* and their ors are 11, 15, 15 and 15.
* Thus, the answer is 11 ^ 15 ^ 15 ^ 15 = 4.
*/