/*
 * Leetcode - 1768
 * Merge Strings Alternately
 * 
 * You are given two strings word1 and word2. Merge the strings by adding letters in alternating order,
 * starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
 * 
 * Example 1
 * Input  : word1 = "abc", word2 = "pqr"
 * Output : "apbqcr"
 * 
 * Example 2
 * Input  : word1 = "ab", word2 = "pqrs"
 * Output : "apbqrs"

 * https://leetcode.com/problems/merge-strings-alternately/description/
*/

// ! Amazon, Meta, Google, MIcrosoft, Apple, Uber

#include <iostream>

using namespace std;

string mergeAlternately(string s, string t) {
  int n1 = s.length(), n2 = t.length();
  string ans = "";
  int i = 0, j = 0;
  while (i < n1 || j < n2) {
    if (i < n1)
      ans.push_back(s[i++]);
    if (j < n2)
      ans.push_back(t[j++]);
  }
  return ans;
}

int main() {
  // * testcase 1
  // string word1 = "abc", word2 = "pqr";

  // * testcase 2
  string word1 = "ab", word2 = "pqrs";

  cout << word1 << " " << word2 << endl;

  string ans = mergeAlternately(word1, word2);
  cout << ans << endl;

  return 0;
}

// * run the code
// * g++ --std=c++17 01-merge-strings.cpp -o output && ./output