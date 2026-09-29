/*
 * Chemistry - 1883A
 * 
 * Description
 * Given a string s of length n and an integer k, determine if you can remove exactly k 
 * characters from s such that the remaining characters can be rearranged to form a palindrome.
 * A palindrome is a string that reads the same backward as forward.
 * 
 * Return true if it is possible to obtain a palindrome after removing exactly k characters, 
 * and false otherwise.
 * 
 * Constraints:
 * 1 <= n <= 10^5
 * 0 <= k < n
 * s consists only of lowercase English letters.
 * 
 * Example 1    :
 * Input        : s = "abcde", k = 2
 * Output       : false
 * Explanation  : Removing 2 characters leaves 3 distinct characters (e.g., "abc"). 
 *                It is impossible to rearrange 3 distinct characters into a palindrome.
 * 
 * Example 2    :
 * Input        : s = "baadb", k = 1
 * Output       : true
 * Explanation  : We can remove 'b' to get "baad", which can be rearranged to "abad" (not a palindrome) 
 *                or remove the extra 'd' if available. Alternatively, removing one 'b' leaves "aadb", 
 *                which cannot, but removing 'b' leaves "baad". Wait, if we remove 'b' we get "aadb", 
 *                rearranged to "abda". The correct removal is 'b' from "baadb" leaving "aadb", or 
 *                removing 'b' to leave "baad". Actually, "baadb" has two 'b's, two 'a's, one 'd'. 
 *                Removing 'd' leaves "baab", which is already a palindrome.
 * 
 * Example 3    :
 * Input        : s = "a", k = 0
 * Output       : true
 * Explanation  : The string is already a palindrome and k = 0, so no removals are needed.
 * 
 * 
 * https://codeforces.com/problemset/problem/1883/B
*/


#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// ! Observation
// * If no. of odd occurences in string 's' > k + 1
// * then answer is "NO", else "YES".

bool solve() {
  ll n, k;
  cin >> n >> k;
  
  string s;
  cin >> s;
  
  // * Count the freq of each char and store that in map
  vector<int> freq_vec(26, 0);
  for (auto &c : s)
    freq_vec[c - 'a']++;

  // * Count total odd frequencies.
  ll odd_frequency = 0;
  for (int i = 0; i < 26; ++i) {
    odd_frequency += (freq_vec[i] % 2);
  }

  // * We subtract 1 becoz palindrome is allowed to have exactly one character with an odd frequency right in the middle
  return (odd_frequency - 1 <= k);
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    bool res = solve();
    if (res) 
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-chemistry.cpp -o output && ./output

// * testcases
/*
14
1 0
a
2 0
ab
2 1
ba
3 1
abb
3 2
abc
6 2
bacacd
6 2
fagbza
6 2
zwaafa
7 2
taagaak
14 3
ttrraakkttoorr
5 3
debdb
5 4
ecadc
5 3
debca
5 3
abaac

*/


// * Output
/*
YES
NO
YES
YES
YES
YES
NO
NO
YES
YES
YES
YES
NO
YES
*/