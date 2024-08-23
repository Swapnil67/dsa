/*
 * Unique Length-3 Palindromic Subsequences
 * Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * 
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 * 
 * Example 1:
 * Input : s = "aabca"
 * Output: 3
 * Explanation :   - "aba" (subsequence of "aabca")
 *                 - "aaa" (subsequence of "aabca")
 *                 - "aca" (subsequence of "aabca")


 * https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/
*/

#include<iostream>
#include<set>
#include<unordered_set>
#include<unordered_map>

// * TIME COMPLEXITY O(26*N)
// * SPACE COMPLEXITY O(N)
int countPalindromicSubsequence(std::string s) {
  int n = s.size();
  std::unordered_set<char> left;
  std::unordered_map<char,int> right;
  std::set<std::pair<char,char>> res;

  // * create a char count map
  for (int i = 0; i < n; ++i) {
    right[s[i]]++;
  }

  for (int i = 0; i < n; ++i) {
    char ch = s[i];
    right[ch]--;
    if(right[ch] == 0)
      right.erase(ch);

    for (int j = 0; j < 26; ++j) {
      char c = 'a' + j;
      if(left.count(c) && right.count(c)) {
        res.insert({ ch, c });
      }
    }
    left.insert(ch);
  }

  return res.size();
} 

int main() {
  std::string s = "aabca";
  // std::string s = "adc";
  // std::string s = "tlpjzdmtwderpkpmgoyrcxttiheassztncqvnfjeyxxp";

  std::cout << s << std::endl;
  int ans = countPalindromicSubsequence(s);
  std::cout << "There wiil be " << ans << " unique 3 length palindromic subsequences." << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 03-3-length-palindrome-subsequence.cpp -o output && ./output