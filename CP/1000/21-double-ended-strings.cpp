/*
 * Double-ended Strings
 * 
 * You are given two strings a and b consisting of lowercase Latin letters. 
 * You can perform the following operations any number of times in any order:
 * 1. If |a| > 0, delete the first character of string a.
 * 2. If |a| > 0, delete the last character of string a.
 * 3. If |b| > 0, delete the first character of string b.
 * 4. If |b| > 0, delete the last character of string b.
 * 
 * Your goal is to make string a and string b equal (both strings can become empty). 
 * Find the minimum total number of operations required to make the two strings equal.
 * 
 * Constraints:
 * 1 <= |a|, |b| <= 20
 * The number of test cases t does not exceed 100.
 * 
 * Example 1    :
 * Input        : a = "a", b = "a"
 * Output       : 0
 * Explanation  : The strings are already equal, so no operations are needed.
 * 
 * Example 2    :
 * Input        : a = "abcd", b = "bc"
 * Output       : 2
 * Explanation  : Delete the first character of string a ("bcd") and then delete 
 *                the last character of string a ("bc"). Now both strings are equal 
 *                to "bc". Total operations = 2.
 *
 * https://codeforces.com/problemset/problem/1506/C
*/

// ! Observation
/*
* LCS - Longest Common substring
* answer = (n + m) - (2 * lcs)               --- (minimum operations)
*/

#include <iostream>

using namespace std;
typedef long long ll;

// ! Longest Common substring
// * Time Complexity (TC): O(20^4) = O(160000) ~ O(10^5)
// * Space Complexity (SC): O(2*20)
ll bruteForce() {
  string a, b;
  cin >> a >> b;
  ll n = a.length(), m = b.length();
  ll lcs = 0;
  for (ll len = 1; len <= min(n, m); ++len) {
    for (ll i = 0; i <= n - len; ++i) {
      for (ll j = 0; j <= m - len; ++j) {
        // * Extract substrings of length 'len' from A and B
        string extract_A = a.substr(i, len);
        string extract_B = b.substr(j, len);
        // cout << extract_A << " " << extract_B << endl;
        if (extract_A == extract_B) {
          lcs = max(lcs, len);
        }
      }
    }
  }

  // * Calculate the minimum number of operations to make A and B equal
  return (n + m) - (2 * lcs);
}

int main(void) {
  ll t;
  cin >> t;

  while (t--) {
    ll ans = bruteForce();
    cout << ans << "\n";
  }
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 21-double-ended-strings.cpp -o output && ./output

// * testcases
/*
5
a
a
abcd
bc
hello
codeforces
hello
helo
dhjakjsnasjhfksafasd
adjsnasjhfksvdafdser

*/

// * Output
/*
0
2
13
3
20
*/
