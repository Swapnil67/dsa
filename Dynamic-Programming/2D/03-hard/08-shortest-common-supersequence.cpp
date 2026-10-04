/*
 * Leetcode - 1092
 * Shortest Common Supersequence 
 * 
 * Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. 
 * If there are multiple valid strings, return any of them.
 * 
 * A string s is a subsequence of string t if deleting some number of characters from t (possibly 0)
 * results in the string s.
 * 
 * Example 1    :
 * Input        : s = "abac", t = "cab"
 * Output       : "cabac"
 * Explanation  : There are 3 pairs of indices that satisfy the conditions in the statement:
 * 
 * Example 2    :
 * Input        : s = "aaaaaaaa", t = "aaaaaaaa"
 * Output       : "aaaaaaaa"
 * 
 * Example 3    :
 * Input        : s = "brute", t = "groot"
 * Output       : "bgruoote"
 *
 * https://leetcode.com/problems/shortest-common-supersequence/description/ 
 * https://www.naukri.com/code360/problems/shortest-supersequence_4244493
 * https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
 * https://www.youtube.com/watch?v=xElxAuBcvsU&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=32
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

vector<vector<int>> dp;
int longestCommonSubsequence(string &s, string &t) {
	int m = s.length(), n = t.length();
	for (int i = m - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			if (s[i] == t[j]) {
				dp[i][j] = 1 + dp[i + 1][j + 1];
			} else {
				dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
	return dp[0][0];
}

string shortestCommonSupersequence(string s, string t) {
	int m = s.length(), n = t.length();
	dp.resize(m + 1, vector<int>(n + 1, 0));
	int lcs = longestCommonSubsequence(s, t);

  // * For Debugging
  for (auto &vec : dp)
    printArr(vec);

	string ans = "";
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (s[i] == t[j]) {
			ans += s[i];
			i++, j++;
		}
		else if (dp[i][j + 1] >= dp[i + 1][j]) {
			ans += t[j];
			j++;
		} else {
			ans += s[i];
			i++;
		}
	}

	if (i <= m - 1)
		ans += s[i];
	if (j <= n - 1)
		ans += t[j];

	return ans;
}


int main(void) {
	// * testcase 1
	// string s = "abac", t = "cab";

	// * testcase 2
	// string s = "aaaaaaaa", t = "aaaaaaaa";

	// * testcase 3
	string s = "brute", t = "groot";

	cout << "s: " << s << ", t: " << t << endl;
	string ans = shortestCommonSupersequence(s, t);
	cout << "Shortest Common Supersequence " << ans << endl;

	return 0;
}
 
// * Run the code
// * g++ --std=c++20 08-shortest-common-supersequence.cpp -o output && ./output
