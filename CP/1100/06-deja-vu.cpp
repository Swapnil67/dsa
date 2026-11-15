/*
 * Deja Vu
 * 
 * You are given an array 'a' of length 'n', consisting of positive integers, and an array 'x' of length 'q', also consisting of positive integers.
 * There are 'q' modification queries. On the i-th modification (1 <= i <= q), for each element a[j] (1 <= j <= n) such that a[j] is divisible by 2^x[i], 
 * you add 2^(x[i] - 1) to a[j].
 * 
 * After processing all modification queries in order, return the final modified array.
 * 
 * Constraints:
 * 1 <= t <= 10^4 (Number of test cases)
 * 1 <= n, q <= 10^5 (Sum of n and sum of q over all test cases do not exceed 2 * 10^5)
 * 1 <= a[j] <= 10^9
 * 1 <= x[i] <= 30
 * 
 * Example 1    :
 * Input        : a = [1, 24, 4, 8, 16], x = [4, 6, 2]
 * Output       : [1, 28, 6, 10, 22]
 * Explanation  : 
 * - For x[1] = 4: 16 is divisible by 2^4 = 16, so we add 2^3 = 8 -> 16 becomes 24.
 * - For x[2] = 6: No element is divisible by 2^6 = 64.
 * - For x[3] = 2: 24, 4, 8, and 24 are divisible by 2^2 = 4. We add 2^1 = 2 to each -> [24+2, 4+2, 8+2, 24+2] resulting in [28, 6, 10, 22].
 * 
 * Example 2    :
 * Input        : a = [2, 4, 6, 8, 10], x = [1, 2, 3]
 * Output       : [3, 5, 7, 9, 11]
 * Explanation  : 
 * - For x[1] = 1: All elements are divisible by 2^1 = 2. We add 2^0 = 1 to all -> [3, 5, 7, 9, 11].
 * - For subsequent queries, all elements are now odd, so they are no longer divisible by any higher power of 2.
 *
 * https://codeforces.com/problemset/problem/1891/B
*/

// ! Observation
/*
* Let's make a claim
* if a[j] % 2^x = 0
* then we do a[j] = a[j] + 2^(x-1)
* Then the modified a[j] will not be divisible by 2^x
* Then we can also say that it will also not be divisible by any x greater than the previous.
*
* Eg: 
* a[j] = 16, let the x be 4
* then 16 % 2^4 = 0
* a[j] = a[j] + 2^3 => 16 + 8 = 24
* now 24 will not be divisible by 2^4 then we can also say that it will not be divisible by any x > 4. 
*/

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

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

void solve() {
  ll n, q; 
  cin >> n >> q;

  VEC(a, n, ll); READ_VEC(a);
  // printArr(a);
  VEC(x, q, ll); READ_VEC(x);
  // printArr(x);

  ll prev = 31; // * Initialize 'prev' to 31, which is greater than any possible x[i]
  for (size_t i = 0; i < q; ++i) {
    if (x[i] >= prev) continue; // * Skip if current x[i] is not less than 'prev'
    ll val = pow(2, x[i]); // * Calculate 2^x[i]
    
    cout << val << " " << prev << endl;

    for (ll j = 0; j < n; ++j) {
      if (a[j] % val == 0) { // * Check if a[j] is divisible by 2^x[i]
        a[j] += (val / 2); // * Add (2^x[i] / 2) to a[j]
      }
    }
    
    prev = x[i]; // * Update 'prev' to current x[i]
  }
  
  for (size_t i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
} 

// ! Greedy with powers of 2
// * Time Complexity (TC): O(n)
// * Space Complexity (SC): O(n)
int main() {
  // Optimize standard I/O operations for competitive programming
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
	return 0;
}

// * Run the code
// * g++ --std=c++20 06-deja-vu.cpp -o output && ./output

// * testcases
/*
4
5 3
1 2 3 4 4
2 3 4
7 3
7 8 12 36 48 6 3
10 4 2
5 4
2 2 2 2 2
1 1 1 1
5 5
1 2 4 8 16
5 2 3 4 1
*/

// * Output
/*
15
17
8
4
-1000
101
10
*/