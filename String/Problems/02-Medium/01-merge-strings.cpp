/*
 * Merge Strings Alternately
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

#include<iostream>

std::string mergeAlternately(std::string word1, std::string word2) {
  int n1 = word1.size(), n2 = word2.size();
  int i = 0, j = 0;
  std::string ans = "";
  while (i < n1 && j < n2) {
    ans += word1[i++];
    ans += word2[j++];
  }

  while (i < n1) {
    ans += word1[i++];
  }

  while (j < n2) {
    ans += word2[j++];
  }
  return ans;
}

int main() {
  // * testcase 1
  // std::string word1 = "abc", word2 = "pqr";
  // * testcase 2
  std::string word1 = "ab", word2 = "pqrs";
  std::cout << word1 << " " << word2 << std::endl;

  std::string ans = mergeAlternately(word1, word2);
  std::cout << ans << std::endl;

  return 0;
}

// * run the code
// * g++ --std=c++17 01-merge-strings.cpp -o output && ./output