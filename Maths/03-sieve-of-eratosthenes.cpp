/*
 * Sieve of Eratosthenes
 * 
 * 
 * Example 1    :
 * Input        : n = 10
 * Output       : [ 2, 3, 5, 7 ]
 * 
 * https://www.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1
 * https://docs.google.com/document/d/15ZFZuxIGZgwbrT9NeBfUT00c-6KMjpuN-M7JRl8HFVI/edit?tab=t.0
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

vector<ll> sieve(ll n) {
  vector<bool> primes(n + 1, true);
  primes[0] = false;
  primes[1] = false;

  ll m = sqrt(n);
  for (ll p = 2; p <= m; ++p) {
    if (primes[p]) {
      // * Update all multiples of p
      for (ll i = p * p; i <= n; i += p) {
        primes[i] = false;
      }
    }
  }
	// * push all the primes into the vector ans 
	vector<ll> ans; 
	for (ll i = 0; i < n; i++) 
		if (primes[i]) 
			ans.push_back(i); 
  return ans;
}

// * TIME COMPLEXITY O(sqrt(n)loglog(n))
// * SPACE COMPLEXITY O(sqrt(n))
vector<ll> sieveRange(ll l, ll r) {
  // * find primes from [0..r] range 
	vector<ll> ans = sieve(r); 
  // printArr(ans);

  // * Find index of first prime greater than or equal to start 
	// * O(sqrt(n)loglog(n))
  ll lower_bound_index = lower_bound(all(ans), l) - ans.begin();
  // cout << "lower_bound_index: " << lower_bound_index << endl;

  // * Remove all elements smaller than start. (O(logn))
	ans.erase(ans.begin(), ans.begin() + lower_bound_index); 

  return ans;
}

int main(void) {
  // ll l = 1, r = 10;
  // ll l = 5, r = 10;
  ll l = 1, r = 100;

  cout << l << " " << r << endl;

  vector<ll> ans = sieveRange(l, r);

  cout << "All primes in range: ";
  printArr(ans);
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 03-sieve-of-eratosthenes.cpp -o output && ./output
