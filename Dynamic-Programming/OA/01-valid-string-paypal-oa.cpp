/*
 * Max Valid String
 * 
 * A string is said to be k-interspace string if the abs diff of the ASCII values of every pair of adj chars is at most k
 * for eg, "abac" is k-interspace string for k >= 2 since abs diff b/w every adj char of it is at most 2.
 * 
 * Given a string, word and an integer k, find longest k-interspace substring within word. If there are multiple substrings
 * return the longest length, return that occurs first in word.
 * 
 * Example 1    :
 * Input        : s = "wedding", k = 0
 * Output       : "dd"
 * 
 * Example 2    :
 * Input        : s = "ababbacaabbbb", k = 1
 * Output       : "ababba"
 * 
 * https://docs.google.com/document/d/1tCEKs5DZtb-hILaYNgMNN8SSQBcQLWm33g2YDljrQBg/edit?tab=t.0
 * https://drive.google.com/file/d/1avmrLmG5iAVLJJZ_H1tIhU5nyIvzLLao/view
*/

// ! OA
// ! Paypal

// ! DP on strings

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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
string bruteForce(string s, int k) {
  ll n = s.length();
  ll maxLen = 0, startIdx = -1;
  for (ll i = 0; i < n; ++i) {
    ll minChar = s[i];
    ll maxChar = s[i];
    for (ll j = i; j < n; ++j) {
      minChar = min(minChar, (ll)s[j]);
      maxChar = max(maxChar, (ll)s[j]);
      if (abs(maxChar - minChar) > k)
        break;
      if ((j - i + 1) > maxLen) {
        startIdx = i;
        maxLen = (j - i + 1);
      }
    }
  }

  if (startIdx == -1)
    return "";
  return s.substr(startIdx, maxLen);
}

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
string optimal(string s, int k) {
  ll n = s.length();
  vector<ll> dp(n + 1, 1);
  dp[0] = 1;
  dp[1] = abs(s[0] - s[1]) <= k ? 2 : 1;
  ll maxLen = 0ll, maxIdx = -1;
  for (ll j = 2; j <= n; ++j) {
    if (abs(s[j] - s[j - 1]) <= k) {
      dp[j] = dp[j - 1] + 1;
    }

    // * Update maxLen and maxIdx if we find a longer valid substring
    if (dp[j] > maxLen) {
      maxLen = dp[j];
      maxIdx = j;
    }
  }
  printArr(dp); // * For debug

  int startIdx = (maxIdx - maxLen) + 1;
  return s.substr(startIdx, maxLen);
}

int main(void) {
  // * testcase 1
  // ll k = 0;
  // string s = "wedding";

  // * testcase 2
  ll k = 1;
  string s = "ababbacaabbbb";

  cout << "k: " << k << endl;
  cout << "s: " << s << endl;
  
  // string ans = bruteForce(s, k);
  string ans = optimal(s, k);

  cout << "Valid String: " << ans << endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 06-valid-string-paypal-oa.cpp -o output && ./output
