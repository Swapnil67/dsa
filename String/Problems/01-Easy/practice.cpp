#include <map>
#include <string>
#include <iostream>
#include <unordered_set>

bool isAlphabet(char c) {
  return ((int)c >= (int)'A' && (int)c <= (int)'Z') || ((int)c >= (int)'a' && (int)c <= (int)'z');
}

void printVectorString(std::vector<std::string> arr) {
  std::cout << "[ ";
  for (std::string s : arr) { 
    std::cout << s;
    std::cout << ", ";
  }
  std::cout << "]\n";
}

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * -------------- Valid Anagram --------------

// * -------------- Is Subsequence --------------

// * ------------ Length of last word ------------

// * ------------ Longest Common Prefix ------------

// * ------------ Unique Email address ------------

// * ------------ Isomorphic Strings ------------

int main() {

  // * Problem 1 - Valid Anagram
  // std::cout << "Valid Anagram" << std::endl;
  // std::string s = "anagram", t = "nagaram";
  // std::string s = "aacc", t = "ccac";
  // std::cout << "s = " << s << " t = " << t << std::endl;
  // bool isValid = validAnagram(s, t);
  // std::cout << "Is valid anagram " << isValid << std::endl;

  // * Problem 2 - Is Subsequence
  // std::cout << "Is Subsequence" << std::endl;
  // std::string s = "abc", t = "ahbgdc";
  // std::string s = "ace", t = "ahbgdc";
  // std::cout << "s = " << s << " t = " << t << std::endl;
  // bool isValid = isSubsequence(s, t);
  // std::cout << "Is Subsequence " << isValid << std::endl;

  // * Problem 3 - Length of last word
  // std::string str = "luffy is still joyboy";
  // std::string str = "   fly me   to   the moon  ";
  // std::cout << str << std::endl;
  // int len = lengthOfLastWord(str);
  // std::cout << "Length of last word is " << len << std::endl;

  // * Problem 4 - Longest Common Prefix
  // std::vector<std::string> strs = {"flower", "flow", "flight"};
  // printVectorString(strs);
  // std::string commonPrefix = longestCommonPrefix(strs);
  // std::cout << "Longest Common Prefix is = " << commonPrefix << std::endl;

  // * Problem 5 - Unique Email address
  // std::vector<std::string> emails = {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com",
                                    //  "testemail+david@lee.tcode.com"};
  // std::vector<std::string> emails = {"a@leetcode.com", "b@leetcode.com", "c@leetcode.com"};
  // printVectorString(emails);
  // int validEmails = uniqueEmailAddresses(emails);
  // std::cout << "Valid Emails " << validEmails << std::endl;

  // * Problem 6 - Isomorphic Strings
  // std::string s = "egg", t = "add";
  std::string s = "ab", t = "bb";
  std::cout << "s = " << s << " t = " << t << std::endl;
  bool ans = isIsomorphic(s, t);
  std::cout << "Isomorphic strings " << ans << std::endl;


  return 0;
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice