/**
 * * Is Subsequence
 * * Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
 * 
 * * A subsequence of a string is a new string that is formed from the original string by deleting some
 * * (can be none) of the characters without disturbing the relative positions of the remaining characters. 
 * * (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 * * Example 1
 * * Input : s = "abc", t = "ahbgdc"
 * * Output : true

 * * Example 2
 * * Input : s = "axc", t = "ahbgdc"
 * * Output : false

 * * https://leetcode.com/problems/is-subsequence/description/
 * * https://www.naukri.com/code360/problems/is-subsequence_892991
*/

#include<string>
#include<iostream>

// * TIME COMPLEXITY O(n1 + n2)
// * SPACE COMPLEXITY O(1)
bool isSubsequence(std::string s, std::string t) {
  int i = 0, j = 0;
  int n1 = s.size(), n2 = t.size();
  while(i < n1 && j < n2) {
    if(s[i] == t[j]) {
      i++;
    }
    j++; // * j is going to increment every time
  }

  // std::cout << "i " << i << " j " << j << std::endl;
  return i == n1;
}

int main() {
  // std::string s = "abc", t = "ahbgdc";
  std::string s = "ace", t = "ahbgdc";
  std::cout << "s = " << s << std::endl;
  std::cout << "t = " << t << std::endl;
  bool ans = isSubsequence(s, t);
  std::cout<<"Is Subsequence "<<ans<<std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 03-is-subsequence.cpp -o 03-is-subsequence && ./03-is-subsequence