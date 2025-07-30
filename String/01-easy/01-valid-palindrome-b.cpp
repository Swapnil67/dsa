/**
 * * Valid Palindrome 2
 * * Given a string s, return true if the s can be palindrome after deleting atmost one character from it.

 * * Example 1
 * * Input : str = "aba"
 * * Output : true

 * * Example 2
 * * Input : str = "abca"
 * * Output : true
 * * Explanation: You could delete the character 'c'.

 * * https://leetcode.com/problems/valid-palindrome-ii/description/
*/

// * A-Z [65-90]
// * a-z [97-122]


#include<string>
#include<iostream>

// * ------------------------- Utility -------------------------`

bool validPalindromeUntil(std::string str, int l, int r) {
  while(l < r) {
    if (str[l++] != str[r--])
      return false;
  }
  return true;
}

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
bool findIsValidPalindrome(std::string str) {
  int l = 0, r = str.size()-1;
  // * O(N)
  while(l < r) {
    if (str[l++] != str[r--]) {
      return validPalindromeUntil(str, l - 1, r) || validPalindromeUntil(str, l, r + 1);
    }
  }
  return true;
}

int main() {
  // * testcase 1
  // std::string str = "abca";
  // * testcase 2
  std::string str = "abc";
  std::cout << str << std::endl;
  bool isValid = findIsValidPalindrome(str);
  std::cout << "Is Valid Palindrome " << isValid << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 01-valid-palindrome-b.cpp -o output && ./output