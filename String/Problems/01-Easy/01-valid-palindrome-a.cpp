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
  if (ch >= 'A' && ch <= 'Z') {
    return (ch - 'A') + 'a';
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
  std::string s = "";
  // * O(N)
  for(char ch: str) {
    if(isAlphanumeric(ch)) {
      char lowerChar = getLowerChar(ch);
      s += lowerChar;
      charStack.push(lowerChar);
    }
  }

  std::string t = "";
  // * O(N)
  while(!charStack.empty()) {
    t += (char)charStack.top(); 
    charStack.pop();
  }

  // std::cout << s << std::endl;
  // std::cout << t << std::endl;

  return s == t;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
bool findIsValidPalindrome(std::string str) {
  int l = 0, r = str.size() - 1;
  while(l < r) {
    while (!(isAlphanumeric(str[l])) && l < r) {
      l++;
      std::cout << "1" << std::endl;
    }

    while (!(isAlphanumeric(str[r])) && l < r){
      r--;
      std::cout << "2" << std::endl;
    }

    char l_ch = getLowerChar(str[l]);
    char r_ch = getLowerChar(str[r]);


    // * debug
    // std::cout << "-------------------------------" << std::endl;
    // std::cout << l << " & " << r << std::endl;
    // std::cout << str[l] << " " << str[r] << std::endl;
    // std::cout << l_ch << " " << r_ch << std::endl;
    // std::cout << isAlphanumeric(str[l]) << " " << isAlphanumeric(str[r]) << std::endl;

    if (l_ch != r_ch)
      return false;
    
    l++;
    r--;
  }
  return true;
}

int main() {
  // * testcase 1
  // std::string str = "A man, a plan, a canal: Panama";
  // * testcase 2
  // std::string str = "race a car";
  // * testcase 3
  // std::string str = "s.";
  // * testcase 4
  std::string str = ".,";

  std::cout << str << std::endl;
  // bool isValid = bruteForce(str);
  bool isValid = findIsValidPalindrome(str);
  std::cout << "Is Valid Palindrome " << isValid << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 01-valid-palindrome-a.cpp -o output && ./output