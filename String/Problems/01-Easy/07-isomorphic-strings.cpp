/**
 * * Isomorphic Strings
 * * Given two strings s and t, determine if they are isomorphic.

 * * Two strings s and t are isomorphic if the characters in s can be replaced to get t.
 * * All occurrences of a character must be replaced with another character while preserving the order of characters. 
 * * No two characters may map to the same character, but a character may map to itself.

 * * Example 1
 * * Input  : s = "egg", t = "add"
 * * Output : true  

 * * Example 2
 * * Input  : s = "foo", t = "bar"
 * * Output : false

 * * Example 3
 * * Input  : s = "paper", t = "title"
 * * Output : true

 * * https://leetcode.com/problems/isomorphic-strings/description/
 * * https://www.naukri.com/code360/problems/check-if-two-given-strings-are-isomorphic-to-each-other_1117636
*/

#include<string>
#include<iostream>
#include<unordered_map>

// * TIME COMPLEXITY O(S)
/*
* S = length of s string
*/
// * SPACE COMPLEXITY O(s + t)
bool isIsomorphic(std::string s, std::string t) {
  std::unordered_map<char, char> st_map;
  std::unordered_map<char, char> ts_map;

  int n1 = s.size();
  for (int i = 0; i < n1; ++i) {
    char ch1 = s[i], ch2 = t[i];
    if(st_map.find(ch1) != st_map.end() && st_map[ch1] != ch2) {
      return false;
    }
    
    if(ts_map.find(ch2) != ts_map.end() && ts_map[ch2] != ch1) {
      return false;
    }

    st_map[ch1] = ch2;
    ts_map[ch2] = ch1;
  }
  return true;
}

int main() {
  // * testcase 1
  // std::string s = "egg", t = "add";
  // * testcase 2
  // std::string s = "foo", t = "bar";
  // * testcase 3
  std::string s = "title", t = "paper";

  std::cout << "s = " << s << " t = " << t << std::endl;
  bool ans = isIsomorphic(s, t);
  std::cout << "Isomorphic strings " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 07-isomorphic-strings.cpp -o 07-isomorphic-strings && ./07-isomorphic-strings