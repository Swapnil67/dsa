/*
 * Leetcode - 2207
 * Maximize Number of Subsequences in a String
 * 
 * You are given a 0-indexed string text and another 0-indexed string pattern of length 2, 
 * both of which consist of only lowercase English letters.
 * 
 * You can add either pattern[0] or pattern[1] anywhere in text exactly once. 
 * Note that the character can be added even at the beginning or at the end of text.
 * 
 * Return the maximum number of times pattern can occur as a subsequence of the modified text.
 * 
 * A subsequence is a string that can be derived from another string by deleting some or no 
 * characters without changing the order of the remaining characters.
 * 
 * Example 1    :
 * Input        : text = "abdcdbc", pattern = "ac"
 * Output       : 4
 * 
 * Example 2    :
 * Input        : text = "aabb", pattern = "ab"
 * Output       : 6
 * Explanation  : Some of the strings which can be obtained from text and have 6 subsequences
 * "ab" are "aaabb", "aaabb", and "aabbb".
 * 
 * Example 3    :
 * Input        : s = ""
 * Output       : 0
 *
 * https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/description/
*/

// ! Prefix Sum + Greedy

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

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
long long maximumSubsequenceCount(string &s, string &pattern) {
    int n = s.size();
    long long res = 0, cnt1 = 0, cnt2 = 0;
    for (char& c : s) {
        if (c == pattern[1]) {
            res += cnt1;
            cnt2++;
        }
        if (c == pattern[0]) {
            cnt1++;
        }
    }
    return res + max(cnt1, cnt2);
}

int main(void) {
	// * testcase 1
	string text = "abdcdbc", pattern = "ac";

	// * testcase 2
	// string text = "aabb", pattern = "ab";

    cout << "text: " << text << ", pattern: " << pattern << endl;

    long long ans = maximumSubsequenceCount(text, pattern);
	cout << ans << endl;
	return 0;
}

// * Run the code
// * g++ --std=c++20 19-maximize-no-of-subseq-in-a-string.cpp -o output && ./output
