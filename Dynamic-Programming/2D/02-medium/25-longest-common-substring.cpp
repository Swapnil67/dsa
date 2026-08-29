/*
 * Leetcode - ?
 * Longest Common Substring
 * 
 * 
 * Example 1    :
 * Input        : s = "abcjklp", t = "acjkp";
 * Output       : 3
 * Explanation  : 'cjk' is common in both strings
 * 
 * Example 2    :
 * Input        : s = "ABCDGH", t = "ACDGHR";
 * Output       : 4
 * Explanation  : 'CDGH' is common in both strings
 * 
 * Example 3    :
 * Input        : s = "abc", t = "acb";
 * Output       : 1
 * Explanation  : 'a' is common in both strings
 *
 * 
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


// * ------------------------- Approach 3: Optimal Approach -------------------------
// * m - size of s, n - size of t
// * Bottom Up Approach
// * TIME COMPLEXITY  O(m * n)
// * SPACE COMPLEXITY O(m * n) (No Auxillary Stack Space)
int longCommSubstr(string &s, string &t){
	int m = s.length(), n = t.length();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

	int maxLength = 0; // * 1. Track the highest match found
	for (int i = m - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			if (s[i] == t[j]) {
				dp[i][j] = 1 + dp[i + 1][j + 1];
				maxLength = max(maxLength, dp[i][j]); // * 2. Update the highest match
			}
			else {
				dp[i][j] = 0;
			}
		}
	}

	return maxLength; // * 3. Return the global maximum
}

int main(void) {
    // * testcase 1
    // string s = "abcjklp", t = "acjkp";

    // * testcase 2
    // string s = "ABCDGH", t = "ACDGHR";

    // * testcase 3
    string s = "abc", t = "acb";

    cout << "s: " << s << endl;
    cout << "t: " << t << endl;

    int ans = longCommSubstr(s, t);
    cout << "Longest Common Substring: " << ans << endl;
    return 0;
}
 
// * Run the code
// * g++ --std=c++20 25-longest-common-substring.cpp -o output && ./output
