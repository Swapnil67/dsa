/*
 * Fast hash calculation of substrings of given string
 * 
 * Given a string 's' and indices  'i' and 'j', find the hash of the substring  s [i....j].
 * 
 * Example 1    :
 * Input        : s = "abab", l = 0, r = 1
 * Output       : 63
 * 
 * https://ideone.com/I4gJay
 * https://cp-algorithms.com/string/string-hashing.html
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
const int M = 1e9 + 9; // * prevent overflow

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

// ! a, b < 10^9
// * TIME COMPLEXITY O(logN)
// * SPACE COMPLEXITY O(1)
int binExprIter(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) { // * check if 0th bit is set
      ans = (ans * a) % M; // * add that to answer
    }
    a = (a * a) % M;
    b >>= 1; // * right shift
  }
  return ans;
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
ll computeHash(string s) {
  const int p = 31;
  const int M = 1e9 + 9;
  ll hash = 0, p_pow = 1;
  for (char c : s) {
    hash += (((c - 'a' + 1) * p_pow) % M) ;
    p_pow = (p_pow * p) % M;
  }
  return hash % M;
}

int getSubstringHash(string const& s, ll l, ll r) {
  int n = s.length();
  const int P = 31;

  // * Create a 'p' pow prefix (helps to find sum of pow(p, n) for given i...j)
  vector<ll> p_pow(n + 1), inv_pow(n + 1);
  p_pow[0] = inv_pow[0] = 1;
  ll invP = binExprIter(P, M - 2); // * Modular Multiplicative Inverse
  // cout << "invP: " << invP << endl;
  for (int i = 1; i <= n; ++i) {
    p_pow[i] = (p_pow[i - 1] * P) % M;
    inv_pow[i] = inv_pow[i - 1] * invP % M;
  }
  // printArr(p_pow);
  // printArr(inv_pow);

  // * Calculate the has for string 0...n-1 and store it in prefix hash array
  vector<ll> hPrefix(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    hPrefix[i + 1] = (hPrefix[i] + (s[i] - 'a' + 1) * p_pow[i]) % M;
  }
  // printArr(hPrefix);

  ll hash = (hPrefix[r + 1] - hPrefix[l] + M) % M;
  hash = hash * inv_pow[l] % M;
  return hash;
}


int main(void) {
  string s = "abab";

  cout << s << " hash: " << computeHash(s) << endl;
  
  cout << "String hash: " << computeHash("ab") << endl;
  int hash = getSubstringHash(s, 0, 1);
  cout << "hash: " << hash << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 string-rolling-hashing.cpp -o output && ./output
