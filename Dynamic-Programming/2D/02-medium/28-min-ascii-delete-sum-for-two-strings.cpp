/*
 * Leetcode - 712
 * Minimum ASCII Delete Sum for Two Strings
 * 
 * Example 1    :
 * Input        : word1 = "sea", word2 = "eat"
 * Output       : 2
 * Explanation  : Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
 *                Deleting "t" from "eat" adds 116 to the sum.
 *                At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
 * 
 * Example 2    :
 * Input        : s1 = "delete", s2 = "leet"
 * Output       : 403
 * Explanation  : Deleting "dee" from "delete" to turn the string into "let",
 *                adds 100[d] + 101[e] + 101[e] to the sum.
 *                Deleting "e" from "leet" adds 101[e] to the sum.
 *                At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
 *                If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
 * 
 * https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
*/

#include <vector>
#include <iostream>

using namespace std;

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

int minimumDeleteSum(string s, string t) {
	int m = s.size(), n = t.size();
	// * dp[i][j] will store the minimum delete sum for suffixes s[i...] and t[j...]
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	// * Base case: If string t is empty, we must delete all remaining characters of s
	for (int i = m - 1; i >= 0; --i) {
		dp[i][n] = dp[i + 1][n] + s[i];
	}

	// * Base case: If string s is empty, we must delete all remaining characters of t
	for (int j = n - 1; j >= 0; --j) {
		dp[m][j] = dp[m][j + 1] + t[j];
	}

	// * Fill the DP table from bottom to top, right to left
	for (int i = m - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			if (s[i] == t[j]) {
				// * Characters match, no cost added
				dp[i][j] = dp[i + 1][j + 1];
			} else {
				// * Take the minimum of deleting s[i] OR deleting t[j]
				dp[i][j] = min(s[i] + dp[i + 1][j], t[j] + dp[i][j + 1]);
			}
		}
	}

	// * The answer for the full strings is at the top-left corner
	return dp[0][0];
}

int main(void) {
  // * testcase 1
  string s = "sea", t = "eat";

  // * testcase 2
  // string s = "leetcode", t = "etco";

  // * testcase 3
  // string s = "abc", t = "def";

  cout << "s: " << s << ", t: " << t << endl;

  int ans = minimumDeleteSum(s, t);

  cout << "Minimum ASCII Delete Sum for Two Strings: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 28-min-ascii-delete-sum-for-two-strings.cpp -o output && ./output


/*
* After both base case
*                e (j=0)    a (j=1)    t (j=2)    Empty (j=3)
* s (i=0)           0          0          0           313
* e (i=1)           0          0          0           198
* a (i=2)           0          0          0            97
* Empty (i=3)      313        212        116            0
*
*/