/*
 * Max subset sum with no adjacent element in two arrays
 * 
 * - Two elements cannot be picked from same column 
 * - Two elements cannot be picked from adjacent column
 * 
 * Example 1    :
 * Input        : a: [ 2, 3, 4, -8, 2 ], b: [ -5, 8, 3, 1, -4 ]
 * Output       : 10 => (2 + 4 + 2)
 * 
 * Example 2    :
 * Input        : a: [ 1, 5, 3, 21234 ], b: [ -4509, 200, 3, 40 ]
 * Output       : 21434 => (200 + 21234)
 * 
 * 
 * https://www.desiqna.in/dp3
 * https://drive.google.com/file/d/1aVaVeGDUlkinRW7Z1BTVY59t_exe70iA/view
 * 
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * ------------------------- APPROACH 1: OPTIMAL APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
ll optimal(vector<ll> &a, vector<ll> &b) {
  ll n = a.size();
  vector<ll> dp(n + 1, 0);
  // * Include 0LL to allow skipping column 0 entirely if both elements are negative
  dp[0] = max({0LL, a[0], b[0]});
  if (n > 1) {
    dp[1] = max({dp[0], a[1], b[1]});
  }

  for (int i = 2; i < n; ++i) {
    ll skip = dp[i - 1];
    ll take = max(a[i], b[i]) + dp[i - 2];
    dp[i] = max(skip, take);
  }
  // printArr(dp);
  return dp[n - 1];
}

int main(void) {
  // * testcase 1
  // vector<ll> a = {2, 3, 4, -8, 2};
  // vector<ll> b = {-5, 8, 3, 1, -4};

  // * testcase 2
  // vector<ll> a = {1, 5, 3, 21234};
  // vector<ll> b = {-4509, 200, 3, 40};

  // * testcase 3
  vector<ll> a = {-1, -2, 4, -4, 5};
  vector<ll> b = {-1, -2, -3, 4, 10};

  cout << "a: ";
  printArr(a);
  cout << "b: ";
  printArr(b);

  ll ans = optimal(a, b);
  
  cout << "Max Sum: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 07-max-alternate-sum-ii.cpp -o output && ./output
