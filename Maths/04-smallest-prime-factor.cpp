/*
 * Smallest Prime Factors
 * 
 * 
 * Example 1    :
 * Input        : n = 12
 * Output       : [ 0, 1, 2, 3, 2, 5, 2, 7, 2, 3, 2, 11, 2 ]
 * 
 * https://www.jdoodle.com/ia/1zjt
 * https://www.geeksforgeeks.org/problems/x₹216/1
 * https://drive.google.com/file/d/1ThcGpV6DVjrXG_J5sgsFKw6CN4a5FFkV/view
 * https://docs.google.com/document/d/15ZFZuxIGZgwbrT9NeBfUT00c-6KMjpuN-M7JRl8HFVI/edit?tab=t.0
*/

#include <vector>
#include <numeric>
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


// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1)
vector<ll> leastPrimeFactor(ll n) {
  // * Assume every number is spf of itself
  vector<ll> spf(n + 1);
  iota(all(spf), 0);
  // printArr(spf);

  ll m = sqrt(n);
  for (ll p = 2; p <= m; p++) {
    // * If this is prime of itself
    if (spf[p] == p) {
      // * SPF of all the multiples of 'i' will be 'i'.
      for (ll i = p * p; i <= n; i += p) {
        // * Don't overwrite the smaller spf
        if (spf[i] == i) { // * Update spf[i] to the spf
          spf[i] = p;
        }
      }
    }
  }

  return spf;
}

int main(void) {
  // * testcase 1
  // int n = 6;

  // * testcase 2
  // int n = 10;
  
  // * testcase 3
  int n = 12;

  vector<ll> ans = leastPrimeFactor(n);

  cout << "SPF till " << n << endl;
  printArr(ans);

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 04-smallest-prime-factor.cpp -o output && ./output
