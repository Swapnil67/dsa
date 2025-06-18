/*
 * Leetcode - 1021
 * Remove Outermost Parentheses
 * A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, 
 * and + represents string concatenation.
 * For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
 * 
 * Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.
 * 
 * Example 1
 * input  : s = "(()())(())"
 * output : "()()()"
 * 
 * Example 2
 * input  : s = "(()())(())(()(()))"
 * output : "()()()()(())"
 * 
 * Example 3
 * input  : s = "()()"
 * output : ""
 * 
 * https://leetcode.com/problems/remove-outermost-parentheses/description/
*/

#include <iostream>

// * ------------------------- APPROACH 1: Optimal Approach -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::string removeOuterParentheses(std::string s) {
  int balance = 0;
  std::string result = "";
  for (char &ch : s) {
    if(ch == '(') {
      if (balance > 0) {
        result += ch;
      }
      balance++;
    }
    else {
      balance--;
      if (balance > 0) {
        result += ch;
      }
    }
  }

  return result;
}

int main() {
  // * testcase 1
  // std::string s = "(()())(())";

  // * testcase 2
  // std::string s = "(()())(())(()(()))";

  // * testcase 3
  std::string s = "()()";

  std::string ans = removeOuterParentheses(s);
  std::cout << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 18-remove-outermost-parentheses.cpp -o output && ./output