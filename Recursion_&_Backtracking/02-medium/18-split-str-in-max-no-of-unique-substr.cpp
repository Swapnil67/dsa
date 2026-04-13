/*
 * Leetcode - 1593
 * Split a String Into the Max Number of Unique Substrings
 * 
 * Given a string s, return the maximum number of unique substrings that the given string can be split into.
 * 
 * You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms
 * the original string. However, you must split the substrings such that all of them are unique.
 
 * A substring is a contiguous sequence of characters within a string.

 * Example 1
 * input       : s = "ababccc"
 * output      : 5
 * Explanation : One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. 
 *               Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
 
 * Example 2
 * input       : s = "aba"
 * output      : 2
 * Explanation : One way to split maximally is ['a', 'ba'].
 
 * Example 3
 * input       : s = "aa"
 * output      : 1
 * Explanation : It is impossible to split the string any further.

 * https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/
*/

#include <vector>
#include <iostream>
#include <unordered_set>

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

/*
* How is pruning helping here eg below
* String: "aabbc", ans (best so far) = 4.
* Current state: You've picked ["a", "ab"]. st.size() is 2.
* Remaining string: "bc" (length 2, starting at index i = 3).
* Calculation: 2 (current) + 2 (remaining) <= 4
* Result: Since 4 <= 4, this branch cannot possibly result in a better answer (it can only match it at best).
* The code returns early.
*/

// * ------------------------- Approach: Optimal Approach -------------------------
// * TIME COMPLEXITY O(2^n * n)
// * SPACE COMPLEXITY O(n)
void dfs(string &s, int &ans, unordered_set<string> &st, int i) {
  if ((st.size() + (s.length() - i)) <= ans) // * pruning
    return;

  if (i >= s.size()) {
    ans = max(ans, (int)st.size());
    return;
  }

  for (int j = i; j < s.size(); ++j) {
    string str = s.substr(i, (j - i + 1));
    // cout << str << endl;
    // * Unique substr then find next substr
    if (st.find(str) == st.end()) {
      st.insert(str);
      dfs(s, ans, st, j + 1);
      st.erase(str);
    }
  }
}

int maxUniqueSplit(string &s) {
  unordered_set<string> st;
  int ans = 0;
  dfs(s, ans, st, 0);
  return ans;
}

int main(void) {
  // * testcase 1
  string s = "ababccc";

  // * testcase 2
  // string s = "aba";

  // * testcase 3
  // string s = "aa";

  cout << "Input string: " << s << endl;

  int ans = maxUniqueSplit(s);
  cout << "Unique Binary String: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 18-split-str-in-max-no-of-unique-substr.cpp -o output && ./output

/*
*
* DFS = i = 0, j = 0
*      i
* s = "ababccc";
*      j
* substr = "a"
*
* ---------------------------
*
* DFS = i = 1, j = 1
*       i
* s = "ababccc";
*       j
* substr = "b"
*
* ---------------------------
*
* DFS = i = 2, j = 3
*        i 
* s = "ababccc";
*         j
* substr = "ab"
*
* ---------------------------
*
* DFS = i = 4, j = 4
*          i 
* s = "ababccc";
*          j
* substr = "c"
*
* ---------------------------
*
* DFS = i = 5, j = 6
*           i 
* s = "ababccc";
*            j
* substr = "cc"
* 
* Substrs = ["a", "b", "ab", "c", "cc"]
*
*/