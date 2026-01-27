/**
 * * Leetcode - 290
 * * Word Pattern
 * * Given a pattern and a string s, find if s follows the same pattern.
 * * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 * * Example 1
 * * Input  : pattern = "abba", s = "dog cat cat dog"
 * * Output : true

 * * Example 2
 * * Input  : pattern = "abba", s = "dog cat cat fish"
 * * Output : false

 * * https://leetcode.com/problems/word-pattern/description/
*/

#include <string>
#include <iostream>
#include <unordered_map>

bool isAlphabet(char ch) {
  return (
    ((int)ch >= (int)'A' && (int)ch <= (int)'Z') || 
    ((int)ch >= (int)'a' && (int)ch <= (int)'z')
  );
}

bool wordPattern(std::string pattern, std::string s) {
  std::unordered_map<char, std::string> patternCharToWordMap;
  std::unordered_map<std::string, char> patternWordToCharMap;
  int patternCount = 0;
  int i = 0, n = s.size();
  for(char c : pattern) {
    std::string word = "";

    // * Check if we already have a char -> word entry
    bool exists = false;
    if(patternCharToWordMap.find(c) != patternCharToWordMap.end()) {
      // std::cout << "Pattern exists " << c << " -> " << patternCharToWordMap[c] << " | " << word << std::endl;
      exists = true;
    }

    // * Create a word for char 'c'
    for (; i < n; i++) {
      if(isAlphabet(s[i])) {
        word += s[i];
      }
      else {
        i++;
        break;
      }
    }

    // * char did not get any word [testcase 4]
    if(word == "") {
      return false;
    }

    // * If word is already mapped to some other character
    if(exists) {
      if(word != patternCharToWordMap[c]) {
        return false;
      } 
    }
    patternCharToWordMap[c] = word;

    // * Check if we already have a word -> char entry
    if(patternWordToCharMap.find(word) != patternWordToCharMap.end() && patternWordToCharMap[word] != c) {
      return false;
    } 
    patternWordToCharMap[word] = c;
  }

  // * More words than characters [testcase 3]
  if(i < s.size()) {
    return false;
  }

  return true;
}

int main() {
  // * testcase 1
  std::string pattern = "abba";
  std::string s = "dog cat cat dog";
  // std::string s = "dog dog dog dog";
  // std::string s = "dog cat cat fish";

  // * testcase 2
  // std::string pattern = "abba";
  // std::string s = "fish whoops helloworld fish";

  // * testcase 3
  // std::string pattern = "aaa";
  // std::string s = "aa aa aa aa";

  // * testcase 4
  // std::string pattern = "he";
  // std::string s = "cat";

  bool ans = wordPattern(pattern, s);
  std::cout << "Pattern: " << pattern << std::endl;
  std::cout << "Str: " << s << std::endl;
  std::cout << "Is Word Pattern: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 09-word-pattern.cpp -o 09-word-pattern && ./09-word-pattern