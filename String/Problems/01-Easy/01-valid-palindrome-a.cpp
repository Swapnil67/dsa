/**
 * * Valid Palindrome
 * * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all 
 * * non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include 
 * * letters and numbers. 
 * 
 * * Given a string s, return true if it is a palindrome, or false otherwise.

 * * Example 1
 * * Input : str = "A man, a plan, a canal: Panama"
 * * Output : true
 * * Explanation: "amanaplanacanalpanama" is a palindrome.

 * * Example 2
 * * Input : str = "race a car"
 * * Output : false
 * * Explanation:  "raceacar" is not a palindrome.

 * * https://leetcode.com/problems/valid-palindrome/description/
*/

// * A-Z [65-90]
// * a-z [97-122]

// * P = 80, p = 112
// * 80 - 65 = 15 + 97 = 112

// * S = 83, p = 112
// * 83 - 65 = 18 + 97 = 115


#include<stack>
#include<string>
#include<iostream>

// * ------------------------- Utility -------------------------`

// * Returns the lowercase character [A-Z]
char getLowerChar(char ch) {
  // return ((int)ch - 65) + 97; // * OR
  if((int)ch >= (int)'A' && (int)ch <= (int)'Z') {
    return ((int)ch - (int)'A') + (int)'a';
  } 
  return ch;
}

bool isAlphanumeric(char ch) {
  return (
    ((int)ch >= (int)'A' && (int)ch <= (int)'Z') || 
    ((int)ch >= (int)'a' && (int)ch <= (int)'z') || 
    ((int)ch >= 0 && (int)ch <= 9));
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
bool bruteForce(std::string str) {
  std::stack<int> charStack;
  std::string tempStrA = "";
  // * O(N)
  for(char ch: str) {
    if(isAlphanumeric(ch)) {
      char lowerChar = getLowerChar(ch);
      tempStrA += lowerChar;
      charStack.push(lowerChar);
    }
  }

  std::string tempStrB = "";
  // * O(N)
  while(!charStack.empty()) {
    tempStrB += (char)charStack.top(); 
    charStack.pop();
  }

  // std::cout << tempStrA << std::endl;
  // std::cout << tempStrB << std::endl;
  if(tempStrA == tempStrB) return true;
  return false;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
bool findIsValidPalindrome(std::string str) {
  int l = 0, r = str.size() - 1;
  while(l < r) {
    while (!(isAlphanumeric(str[l])) && l < r)
      l++;
    while (!(isAlphanumeric(str[r])) && r > 1)
      r--;

    char lowerL = getLowerChar(str[l]);
    char upperR = getLowerChar(str[r]);
    if(lowerL != upperR) {
      return false;
    }
    l++;
    r--;
  }
  return true;
}

int main() {
  // * testcase 1
  // std::string str = "A man, a plan, a canal: Panama";
  // * testcase 2
  std::string str = "race a car";
  std::cout << str << std::endl;
  // bool isValid = bruteForce(str);
  bool isValid = findIsValidPalindrome(str);
  std::cout << "Is Valid Palindrome " << isValid << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 01-valid-palindrome-a.cpp -o 01-valid-palindrome-a && ./01-valid-palindrome-a