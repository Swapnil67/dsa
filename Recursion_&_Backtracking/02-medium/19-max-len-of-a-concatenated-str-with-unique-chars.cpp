/*
 * Leetcode - 1239
 * Maximum Length of a Concatenated String with Unique Characters
 * 
 * You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr
 * that has unique characters.
 * 
 * Return the maximum possible length of s.
 
 * A subsequence is an array that can be derived from another array by deleting some or no elements without
 * changing the order of the remaining elements.

 * Example 1
 * input       : arr = ["un","iq","ue"]
 * output      : 4
 * Explanation : All the valid concatenations are:
 *               - ""
 *               - "un"
 *               - "iq"
 *               - "ue"
 *               - "uniq" ("un" + "iq")
 *               - "ique" ("iq" + "ue")
 *               Maximum length is 4.
 
 * Example 2
 * input       : arr = ["cha","r","act","ers"]
 * output      : 6
 * Explanation : Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").

 * Example 3
 * input       : arr = ["cabcdefghijklmnopqrstuvwxyz"]
 * output      : 26
 * Explanation : The only string in arr has all 26 characters.

 * https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
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

bool overlap(std::unordered_set<char> &st, std::string s) {
  std::unordered_set<char> prev;
  for (char &c : s) {
    if (st.count(c) || prev.count(c)) {
      return true;
    }
    prev.insert(c);
  }
  return false;
}

void dfs(std::vector<std::string> &strs, std::unordered_set<char> st, int &ans, int i) {
  ans = std::max(ans, (int)st.size());
  
  if (i >= strs.size()) {
    return;
  }

  for (int j = i; j < strs.size(); ++j) {
    if (!overlap(st, strs[j])) {
      for (char &c : strs[j])
        st.insert(c);

      dfs(strs, st, ans, j + 1);

      for (char &c : strs[j])
        st.erase(c);
    }
  }
}

// * ------------------------- Approach: Optimal Approach -------------------------`
// * - 'm' is the length of all strings in strs
// * TIME COMPLEXITY O(2^n * m)
// * SPACE COMPLEXITY O(n)
int maxLength(std::vector<std::string> &strs) {
  int ans = 0;
  std::unordered_set<char> st;
  dfs(strs, st, ans, 0);
  return ans;
}

int main(void) {
  // * testcase 1
  // std::vector<std::string> strs = {"un", "iq", "ue"};
  
  // * testcase 2
  // std::vector<std::string> strs = {"cha", "r", "act", "ers"};

  // * testcase 3
  std::vector<std::string> strs = {"abcdefghijklmnopqrstuvwxyz"};

  std::cout << "Input strings: ";
  printArr(strs);

  int ans = maxLength(strs);
  std::cout << "Unique Binary String: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 19-max-len-of-a-concatenated-str-with-unique-chars.cpp -o output && ./output