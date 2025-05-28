/*
 * Leetcode - 1190
 * Reverse Substrings Between Each Pair of Parentheses
 * You are given a string s that consists of lower case English letters and brackets.

 * * Example 1
 * * Input  : s = "(abcd)"
 * * Output : "dcba"
 * 
 * * Example 2
 * * Input  : s = "(u(love)i)"
 * * Output : "iloveu"
 * 
 * * Example 2
 * * Input  : s = "(ed(et(oc))el)"
 * * Output : "leetcode"

 * https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/
*/

#include <stack>
#include <iostream>

std::string reverseParentheses(std::string s) {
  int n = s.size();
  std::stack<char> st;

  for (char &ch : s) {
    if (ch == ')') {
      std::string temp = "";
      // * get the string b/w '()' brackets
      while(!st.empty() && st.top() != '(') {
        temp += st.top();
        st.pop();
      }

      // * Remove the '(' paranthesis
      st.pop();

      // * Push the string again on top of stack
      for (char &c : temp) {
        st.push(c);
      }
      // std::cout << temp << std::endl;
    }
    else {
      st.push(ch);
    }
  }

  std::string ans = "";
  while (!st.empty()) {
    ans = st.top() + ans;
    st.pop();
  }
  return ans;
}

int main() {
  // std::string s = "(u(love)i)";
  std::string s = "(ed(et(oc))el)";
  std::cout << s << std::endl;

  std::string ans = reverseParentheses(s);
  std::cout << ans << std::endl;
  
  return 0;
}


// * Run the code
// * g++ --std=c++20 15-reverse-substr-bw-parenthesis.cpp -o output && ./output
