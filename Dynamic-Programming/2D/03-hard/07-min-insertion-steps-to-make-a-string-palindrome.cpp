/*
 * Leetcode - 1312
 * Minimum Insertion Steps to Make a String Palindrome
 * 
 * Given a string s. In one step you can insert any character at any index of the string.
 * 
 * Return the minimum number of steps to make s palindrome.
 * 
 * A Palindrome String is one that reads the same backward as well as forward.
 * 
 * Example 1    :
 * Input        : s = "zzazz"
 * Output       : 0
 * Explanation  : The string "zzazz" is already palindrome we do not need any insertions.
 * 
 * Example 2    :
 * Input        : s = "mbadm"
 * Output       : 2
 * Explanation  : String can be "mbdadbm" or "mdbabdm".
 * 
 * Example 3    :
 * Input        : s = "leetcode"
 * Output       : 5
 * Explanation  : Inserting 5 characters the string becomes "leetcodocteel".
 * 
 * https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
 * https://www.geeksforgeeks.org/problems/form-a-palindrome2544/1
 * https://www.naukri.com/code360/problems/minimum-insertions-to-make-a-string-palindrome_985293
*/

// ! Amazon, Google, Meta, Apple, Samsung

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


// * ------------------------- Approach 1: Optimal Approach -------------------------
// * Bottom Up Approach
// * TIME COMPLEXITY  O(m^2)
// * SPACE COMPLEXITY O(m) (No Auxillary Stack Space)
int longestPalindromeSubseq(string s) {
  int m = s.length();
  
  // * 1. Create a reversed copy of the string
  string t = s;
  reverse(begin(t), end(t));
  
  // * 2. Space Optimization: Instead of a full grid, we only keep two rows.
  // * 'prev' represents the row below (i + 1)
  // * 'cur' represents the current row we are filling right now (i)
  vector<int> prev(m + 1, 0);
  vector<int> cur(m + 1, 0);
  
  // * 3. Loop backwards through both strings
  for (int i = m - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (s[i] == t[j]) {
				// * If letters match, look diagonally down-right:
				// * This means look at the next character in 'prev' (row i + 1, col j + 1)
				cur[j] = 1 + prev[j + 1];
			}
			else {
				// * If they don't match, take the max of:
				// * Skipping s[i] -> look down at prev[j] (row i + 1, col j)
				// * Skipping t[j] -> look right at cur[j + 1] (row i, col j + 1)
				cur[j] = max(prev[j], cur[j + 1]);
			}
		}
		// * 4. Important: The current row is finished. It now becomes 
		// * the 'previous' row for the next iteration of the outer loop.
		prev = cur;
  }
  
  // * 5. The final answer sits at the start of our last computed row
  return prev[0];
}

int minInsertions(string s) {
	int n = s.length();
	// * we get the Longest Palindromic Subsequence and subtract it from the length of string
	// * since that much characters we can insert in reverse order to make the string palindrome.
	return n - longestPalindromeSubseq(s);
}


int main(void) {
  // * testcase 1
  string s = "bbbab";

  // * testcase 2
  // string s = "cbbd";

  cout << "s: " << s << endl;

  // int ans = bruteForce(s);
  // int ans = betterApproach(s);
  // int ans = longestPalindromeSubseq(s);
  int ans = minInsertions(s);

  cout << "Longest Palindromic Subsequence: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 26-longest-palindromic-subsequence.cpp -o output && ./output
