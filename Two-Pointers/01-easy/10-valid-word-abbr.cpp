/**
 * * Valid Word Abbreviation
 * * A string can be shortened by replacing any number of non-adjacent, non-empty substrings with their lengths
 * * (without leading zeros).

 * * Example 1
 * * Input  : word = "apple", abbr = "a3e";
 * * Output : 1

 * * Example 2
 * * Input  : word = "apple", abbr = "a4";
 * * Output : 1

 * * Example 3
 * * Input  : word = "internationalization", abbr = "i18n";
 * * Output : 1

 * * Example 4
 * * Input  : word = "substitution", abbr = "s55n";
 * * Output : 1

 * * http://leetcode.com/problems/valid-word-abbreviation/description/
 * * https://neetcode.io/problems/valid-word-abbreviation
*/

#include <iostream>

// * ------------------------- APPROACH 2B: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n + m)
// * SPACE COMPLEXITY O(1)
bool validWordAbbreviation(std::string word, std::string abbr) {
  int n = word.length(), m = abbr.length();
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (abbr[j] == '0')
      return false;

    if(isalpha(abbr[j])) {
      if (word[i] != abbr[j])
        return false;
      i++, j++;
    } else {  
      int numLen = 0;
      while (j < m && isdigit(abbr[j])) {
        numLen = numLen * 10 + (abbr[j] - '0');
        j++;
      }
      i += numLen;
    }
  }

  return i == n && j == m;
}

bool validWordAbbreviation2(std::string &word, std::string &abbr) {
  int n = word.size();
  int i = 0;

  for (char &c : abbr) {
    if (isdigit(c)) {
      i += c - '0';
    } else {
      std::cout << word[i] << " " << c << std::endl;
      if (word[i] != c) 
        return false;
      i++;
    }
  }
  return true;
}


int main(void) {
  // std::string word = "apple", abbr = "a3e";
  // std::string word = "apple", abbr = "a4";
  // std::string word = "international", abbr = "i9l";
  // std::string word = "abbreviation", abbr = "abbreviation";
  // std::string word = "internationalization", abbr = "i18n";
  std::string word = "substitution", abbr = "s55n";

  bool ans = validWordAbbreviation(word, abbr);
  std::cout << "Valid word abbreviation: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ -std=c++17 10-valid-word-abbr.cpp -o output && ./output