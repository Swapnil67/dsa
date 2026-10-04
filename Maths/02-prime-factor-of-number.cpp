/*
 * Find Prime factors of a number
 * 
 * 
 * Example 1    :
 * Input        : n = 12
 * Output       : 2^2 + 3^1
 * 
 * Example 2    :
 * Input        : n = 50
 * Output       : 2^1 + 5^2
 * 
 * https://drive.google.com/file/d/1ginV-ZWVf-iE_KBSRWeWaoMhnER0hTq0/view
 * https://docs.google.com/document/d/15ZFZuxIGZgwbrT9NeBfUT00c-6KMjpuN-M7JRl8HFVI/edit?tab=t.0
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_map>

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

// * TIME COMPLEXITY O(sqrt(N))
// * SPACE COMPLEXITY O(1)
unordered_map<ll, ll> bruteForce(int n) {
  unordered_map<ll, ll> pf; // * Prime factors map
  
  // * First check how many times it can be factored by 2
  while (n % 2 == 0) {
    pf[2]++;
    n = n / 2;
  }

  // * n must be odd at this point. So we can skip
  for (ll i = 3; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      pf[i]++;
      n = n / i;
    }
  }
   
	// * This condition is to handle the case when n
	// * is a prime number greater than 2
  if (n > 2)
    pf[n]++;

  return pf;
}

vector<ll> computeSPF(int n) {
  // * Assume every number is spf of itself
  vector<ll> spf(n + 1, 0);
  iota(all(spf), 0);

  ll m = sqrt(m);
  for (ll p = 2; p <= m; ++p) {
    if (spf[p] == p) {
      // * SPF of all the multiples of 'i' will be 'i'.
      for (ll i = p * p; i <= n; i += p) {
        if (spf[i] == i) {
          spf[i] = p;
        }
      }
    }
  }

  return spf;
}

// * Using Smallest Prime Factor
// * TIME COMPLEXITY O(nlog(logn))
// * SPACE COMPLEXITY O(1)
unordered_map<ll, ll> findPrimeFactors(int n) {
  vector<ll> spf = computeSPF(n);
  unordered_map<ll, ll> pf; // * Prime factors map
  
  // * For 10^6 this will run atmost 20 times (since 10^6 ~ 2^20)
  while (n != 1) {
    pf[spf[n]]++;
    n = n / spf[n];
  }
  return pf;
}

int main(void) {
  // * testcase 1
  // int n = 12;

  // * testcase 2
  // int n = 18;

  // * testcase 3
  int n = 50;

  // unordered_map<ll, ll> pf = bruteForce(n);
  unordered_map<ll, ll> pf = findPrimeFactors(n);

  cout << "Prime Factors of " << n << endl;
  for (auto &it: pf) {
    cout << it.first << "^" << it.second << endl;
  }
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 02-prime-factor-of-number.cpp -o output && ./output
