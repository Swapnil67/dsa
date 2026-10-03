/*
 * Deletive Editing
 * 
 * Daisy plays a game with a starting word s and a target word t.
 * In each move, a letter is selected, and its very first (leftmost) occurrence 
 * in the current string is deleted.
 * 
 * Given two strings s and t, determine whether it is possible to transform 
 * s into t through zero or more moves of this game.
 * 
 * Constraints:
 * 1 <= n <= 10000 (number of test cases)
 * 1 <= |s|, |t| <= 30
 * s and t consist solely of uppercase English letters.
 * 
 * Example 1    :
 * Input        : s = "DETERMINED", t = "TRME"
 * Output       : "YES"
 * Explanation  : Deleting the first occurrences of 'D', 'E', 'T', 'E', 'I', and 'N' in proper succession yields "TRME".
 * 
 * Example 2    :
 * Input        : s = "DETERMINED", t = "TERM"
 * Output       : "NO"
 * Explanation  : To preserve the target characters in their proper order, removing the surplus characters would inevitably erase letters needed for "TERM" due to the leftmost-first deletion rule.
 * 
 * https://codeforces.com/problemset/problem/1666/D
*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

// ! Observation
/*
* s = DETERMINED t = TERM
* t_freq = {T: 1, E: 1, R: 1, M: 1}
*
* After traversing from right to left we'll only keep the char which is present in t_freq from back
* the string 's' will become s = ..T.RM..E. 
* 
* the '.' represents char which we don't need in string 't'
*
* so our final string becomes str = "TRME" != TERM ====> "NO"
*/


// * Greedy from end
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
string solve(string s, string t) {
  // * Count frequency chars of string t
  vector<ll> t_freq(26, 0);
  for (auto &c: t) 
    t_freq[c - 'A']++;
    
  int n = s.length();
  string str = "";
  
  // * From right to left keep the last occurences of needed chars for string 't'
  // * create a string str out of it and check it with the string 't'.
  for (int i = n - 1; i >= 0; --i){
    char ch = s[i];
    if (t_freq[ch - 'A'] > 0) {
      t_freq[ch - 'A']--;
      str = ch + str;
    }
  }
  
  // cout << t << " " << str << "\n";
  
  return (t == str) ? "YES" : "NO";
}

// * TC = O(n^2)
// * SC = O(n) (Input array)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    string s, t;
    cin >> s >> t;
    string ans = solve(s, t);
    cout << ans << "\n";
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 16-deletive-editing.cpp -o output && ./output

// * testcases
/*
6
DETERMINED TRME
DETERMINED TERM
PSEUDOPSEUDOHYPOPARATHYROIDISM PEPA
DEINSTITUTIONALIZATION DONATION
CONTEST CODE
SOLUTION SOLUTION

*/

// * Output
/*
YES
NO
NO
YES
NO
YES
*/