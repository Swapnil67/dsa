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

template <typename T>
void printArr(std::vector<T> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// * ------------------------- Approach: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(2^n * n)
// * SPACE COMPLEXITY O(n)
void dfs(std::string &s, int &ans, std::unordered_set<std::string> &st, int i) {
  if ((st.size() - 1) + (s.size() - i + 1) <= ans) // * pruning
    return;

  if (i >= s.size()) {
    ans = std::max(ans, (int)st.size());
    return;
  }

  for (int j = i; j < s.size(); ++j) {
    std::string str = s.substr(i, (j - i + 1));
    // std::cout << str << std::endl;

    if (st.find(str) == st.end()) {
      st.insert(str);
      dfs(s, ans, st, j + 1);
      st.erase(str);
    }
  }
}

int maxUniqueSplit(std::string &s) {
  std::unordered_set<std::string> st;
  int ans = 0;
  dfs(s, ans, st, 0);
  return ans;
}

int main(void) {
  // * testcase 1
  // std::string s = "ababccc";

  // * testcase 2
  // std::string s = "aba";

  // * testcase 2
  std::string s = "aa";

  std::cout << "Input string: " << s << std::endl;

  int ans = maxUniqueSplit(s);
  std::cout << "Unique Binary String: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 18-split-str-in-max-no-of-unique-substr.cpp -o output && ./output