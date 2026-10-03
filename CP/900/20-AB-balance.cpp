/*
 * AB Balance
 * 
 * Description  : You are given a string s consisting of the characters 'a' and 'b'. 
 *                Let AB(s) be the number of substrings equal to "ab", and BA(s) be 
 *                the number of substrings equal to "ba". You can change any character 
 *                of s to 'a' or 'b'. Find a string s that can be obtained from the 
 *                original string with the minimum number of changes, such that AB(s) = BA(s).
 * 
 * Constraints  : 
 *                - 1 <= t <= 1000 (Number of test cases)
 *                - 1 <= s.length <= 100
 *                - s consists only of characters 'a' and 'b'.
 * 
 * Example 1    :
 * Input        : s = "b"
 * Output       : "b"
 * Explanation  : AB(s) = 0 and BA(s) = 0. They are already equal, so 0 changes are needed.
 * 
 * Example 2    :
 * Input        : s = "aab"
 * Output       : "aab" or "aaa"
 * Explanation  : For "aab", AB(s) = 1 and BA(s) = 0. Changing the last character to 'a' 
 *                gives "aaa", where AB(s) = 0 and BA(s) = 0 (1 change). Alternatively, 
 *                changing the first character to 'b' gives "bab", where AB(s) = 1 and BA(s) = 1.
 * 
 * Example 3    :
 * Input        : s = "abbaab"
 * Output       : "bbbaab" or "abbaaa"
 * Explanation  : For "bbbaab" & "abbaaa" AB(s) = 1 and BA(s) = 1. 
 *
 * https://codeforces.com/problemset/problem/1606/A
*/

// ! Observation

/*
* Ensure the first and last characters are identical.

* When the counts are same of ABs and BAs both first and last characters must be identical.
* Eg: s = aabbbabaa
* here AB = 2, BA = 2

* When the first and last characters are not identical 
* Eg: s = abbaab
* here AB = 2, BA = 1
* Here string starts with AB then BA is there and once again AB is there but it missed another BA for balancing it.
* That why the first and last characters are not identical, else if it was perfectly balanced then
* first and last characters will be identical.
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// * TC = O(100)
// * SC = O(100) (Input string)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    
    int n = s.length();
    if (s[0] != s[n - 1]) {
      if (s[0] == 'a')
        s[0] = 'b';
      else 
        s[0] = 'a';
    }
    cout << s << "\n";
  }
  return 0;
}


// * Run the code
// * g++ --std=c++20 20-AB-balance.cpp -o output && ./output

// * testcases
/*
4
b
aabbbabaa
abbb
abbaab

*/

// * Output
/*
b
aabbbabaa
bbbb
abbaaa
*/