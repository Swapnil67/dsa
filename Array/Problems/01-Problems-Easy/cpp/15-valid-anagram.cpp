/**
 * * Valid Anagram
 * * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
 * * typically using all the original letters exactly once.

 * * Example 1
 * * Input  : s = "anagram", t = "nagaram"
 * * Output : true

 * * Example 2
 * * Input  : s = "rat", t = "car"
 * * Output : false

 * * https://leetcode.com/problems/valid-anagram/description/
*/

#include<map>
#include<string>
#include<iostream>

bool validAnagram(std::string s, std::string t) {
  if(s.size() != t.size()) return false;

  std::map<char, int> charMap;
  // * O(S)
  for(char &c: s) {
    charMap[c]++;
  }

  // * O(TlogN)
  for(char &c: t) {
    if(charMap.find(c) != charMap.end() && charMap[c] > 0) charMap[c]--;
    else return false;
  }

  return true;
}

int main() {
  // * testcase 1
  // std::string s = "anagram", t = "nagaram";
  // * testcase 2
  // std::string s = "rat", t = "car";
  // * testcase 3
  std::string s = "aacc", t = "ccac";

  bool isValidAnagram = validAnagram(s, t);
  std::cout<<"String A: "<<s<<std::endl;
  std::cout<<"String B: "<<t<<std::endl;
  std::cout<<"Is Calid Anagram "<<isValidAnagram<<std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 15-valid-anagram.cpp -o 15-valid-anagram && ./15-valid-anagram
